#include "document.h"

#include "pixmap.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    Document::Document(const std::string& filename)
        : m_mupdf_document(nullptr)
        , m_context()
        , m_matrix()
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

    Document::~Document()
    {
        if(nullptr != m_mupdf_document)
        {
            fz_drop_document(m_context.get(), m_mupdf_document);
            m_mupdf_document = nullptr;
        }
    }

    fz_document* Document::get() const
    {
        return m_mupdf_document;
    }

    void Document::set_zoom(unsigned int zoom) const
    {
        m_matrix.set_zoom(zoom);
    }

    void Document::set_rotation(float rotation) const
    {
        m_matrix.set_rotation(rotation);
    }

    unsigned int Document::get_total_pages()
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

    const QImage Document::get_page_image(unsigned int page_number) const
    {
        /* Render page to an RGB pixmap. */
            fz_pixmap *pix;
        fz_try(m_context.get())
            pix = fz_new_pixmap_from_page_number(m_context.get(), m_mupdf_document, page_number, m_matrix.get(), fz_device_rgb(m_context.get()), 0);
        fz_catch(m_context.get())
        {
            //fprintf(stderr, "cannot render page: %s\n", fz_caught_message(m_mupdf_context));
            fz_drop_document(m_context.get(), m_mupdf_document);
            //fz_drop_context(m_context.get());
            //return EXIT_FAILURE;
        }

//        Pixmap pixmap(m_context, *this, m_matrix, page_number);
//        const auto pix = pixmap.get();

        const auto pixmap_samples = fz_pixmap_samples(m_context.get(), pix);
        const auto pixmap_width = fz_pixmap_width(m_context.get(), pix);
        const auto pixmap_height = fz_pixmap_height(m_context.get(), pix);
        const auto image = QImage(pixmap_samples, pixmap_width, pixmap_height, QImage::Format_RGB888, NULL, pixmap_samples);

        return image;
    }
}
