#include "document.h"

#include "mupdf_wrapper/context.h"
#include "mupdf_wrapper/document.h"
#include "mupdf_wrapper/matrix.h"
#include "mupdf_wrapper/page.h"
#include "mupdf_wrapper/pixmap.h"

#include <QImage>

namespace pdf_reader
{
    Document::Document(const std::string& filename)
        : m_page_number(0)
        , m_total_pages(0)
    {
        m_context = std::make_shared<mupdf_wrapper::Context>();
        m_context->register_document_handlers();

        m_document = std::make_shared<mupdf_wrapper::Document>(m_context, filename);

        m_total_pages = m_document->get_total_pages();
    }

    std::shared_ptr<QImage> Document::get_page(Page page)
    {
        auto page_number = 0;

        switch(page)
        {
            case Page::first:
                page_number = 0;
                break;
            case Page::previous:
                page_number = m_page_number - 1;
                break;
            case Page::next:
                page_number = m_page_number + 1;
                break;
            case Page::last:
                page_number = m_total_pages - 1;
                break;
        }

        return get_page(page_number);
    }

    std::shared_ptr<QImage> Document::get_page(int page_number)
    {
        std::shared_ptr<QImage> page_image = nullptr;

        if((0 <= page_number) && (m_total_pages > page_number))
        {
            m_page_number = page_number;

            const unsigned int zoom = 100;
            const float rotation = 0;

            const auto page = std::make_shared<mupdf_wrapper::Page>(m_context, m_document, m_page_number);

            m_matrix = std::make_shared<mupdf_wrapper::Matrix>();
            m_matrix->set_zoom(zoom);
            m_matrix->set_rotation(rotation);

            m_pixmap = std::make_shared<mupdf_wrapper::Pixmap>(m_context, m_document, m_matrix, page);
            const auto samples = m_pixmap->get_samples();
            const auto width = m_pixmap->get_width();
            const auto height = m_pixmap->get_height();

            page_image = std::make_shared<QImage>(samples, width, height, QImage::Format_RGB888, nullptr, samples);
        }

        return page_image;
    }
}
