#include "document.h"

#include "mupdf_wrapper/context.h"
#include "mupdf_wrapper/document.h"
#include "mupdf_wrapper/matrix.h"
#include "mupdf_wrapper/page.h"
#include "mupdf_wrapper/pixmap.h"

#include <QImage>

namespace pdf_reader
{
    Document::Document(const std::filesystem::path& filename)
        : m_total_pages{}
    {
        m_context = std::make_shared<mupdf_wrapper::Context>();
        m_context->register_document_handlers();

        m_document = std::make_shared<mupdf_wrapper::Document>(m_context, filename);

        m_total_pages = m_document->get_total_pages();
    }

    std::shared_ptr<QImage> Document::get_page(int page_number)
    {
        std::shared_ptr<QImage> page_image = nullptr;

        if((0 <= page_number) && (m_total_pages > page_number))
        {
            const unsigned int zoom = 100;
            const float rotation = 0;

            const auto page = std::make_shared<mupdf_wrapper::Page>(m_context, m_document, page_number);

            m_matrix = std::make_shared<mupdf_wrapper::Matrix>();
            m_matrix->set_zoom(zoom);
            m_matrix->set_rotation(rotation);

            m_pixmap = std::make_shared<mupdf_wrapper::Pixmap>(m_context, m_matrix, page);
            const auto samples = m_pixmap->get_samples();
            const auto width = m_pixmap->get_width();
            const auto height = m_pixmap->get_height();

            page_image = std::make_shared<QImage>(samples, width, height, QImage::Format_RGB888, nullptr, samples);
        }

        return page_image;
    }

    std::optional<QImage> Document::get_page_image(int page_number)
    {
        auto page_image = get_page(page_number);
        if(nullptr != page_image)
        {
            return *page_image;
        }
        return {};
    }

    int Document::get_total_pages() const
    {
        return m_total_pages;
    }
}
