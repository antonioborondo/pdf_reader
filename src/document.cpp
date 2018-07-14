#include "document.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    document::document(const std::string& filename)
        : m_context()
        , m_mupdf_document(nullptr)
    {
        if(!m_context.register_document_handlers())
        {
            throw std::runtime_error("Cannot register document handlers");
        }

        fz_try(m_context.get())
            m_mupdf_document = fz_open_document(m_context.get(), filename.c_str());
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot open document");
        }
    }

    document::~document()
    {
        if(nullptr != m_mupdf_document)
        {
            fz_drop_document(m_context.get(), m_mupdf_document);
            m_mupdf_document = nullptr;
        }
    }

    unsigned int document::get_total_pages()
    {
        unsigned int total_pages = 0;

        fz_try(m_context.get())
            total_pages = fz_count_pages(m_context.get(), m_mupdf_document);
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot get total number of pages");
        }

        return total_pages;
    }

    const QImage document::get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const
    {
        /* Compute a transformation matrix for the zoom and rotation desired. */
        /* The default resolution without scaling is 72 dpi. */
        fz_matrix ctm;
        fz_scale(&ctm, zoom / 100, zoom / 100);
        fz_pre_rotate(&ctm, rotate);

        /* Render page to an RGB pixmap. */
            fz_pixmap *pix;
        fz_try(m_context.get())
            pix = fz_new_pixmap_from_page_number(m_context.get(), m_mupdf_document, page_number, &ctm, fz_device_rgb(m_context.get()), 0);
        fz_catch(m_context.get())
        {
            //fprintf(stderr, "cannot render page: %s\n", fz_caught_message(m_mupdf_context));
            fz_drop_document(m_context.get(), m_mupdf_document);
            //fz_drop_context(m_context.get());
            //return EXIT_FAILURE;
        }

        const auto pixmap_samples = fz_pixmap_samples(m_context.get(), pix);
        const auto pixmap_width = fz_pixmap_width(m_context.get(), pix);
        const auto pixmap_height = fz_pixmap_height(m_context.get(), pix);
        const auto image = QImage(pixmap_samples, pixmap_width, pixmap_height, QImage::Format_RGB888, NULL, pixmap_samples);

        //fz_drop_pixmap(m_context.get(), pix);

        return image;
    }
}
