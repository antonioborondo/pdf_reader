#include "document.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    document::document(const std::string& filename)
        : m_context()
        , m_mupdf_document(nullptr)
    {
        m_context.register_document_handlers();

        fz_try(m_context.get())
            m_mupdf_document = fz_open_document(m_context.get(), filename.c_str());
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Document cannot be opened");
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

    const QImage document::get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const
    {
    //    fz_try(m_context.get())
    //        m_total_pages = fz_count_pages(m_context.get(), m_mupdf_document);
    //    fz_catch(m_context.get())
    //    {
    //        throw std::runtime_error("Pages cannot be counted");
    //    }

    //    if (page_number < 0 || page_number >= m_page_count)
    //    {
    //        //fprintf(stderr, "page number out of range: %d (page count %d)\n", page_number + 1, m_page_count);
    //        //fz_drop_document(m_, doc);
    //        //fz_drop_context(ctx);
    //        //return EXIT_FAILURE;
    //    }

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

        auto pixmap_samples = fz_pixmap_samples(m_context.get(), pix);
        auto pixmap_width = fz_pixmap_width(m_context.get(), pix);
        auto pixmap_height = fz_pixmap_height(m_context.get(), pix);

        //fz_drop_pixmap(m_context.get(), pix);

        // with Qt 5.2, Format_RGB888 is correct for any architecture
        return QImage(pixmap_samples, pixmap_width, pixmap_height, QImage::Format_RGB888, NULL, pixmap_samples);
    }
}
