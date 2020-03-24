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

        const unsigned int zoom = 100;
        const float rotation = 0;

        m_matrix = std::make_shared<mupdf_wrapper::Matrix>();
        m_matrix->set_zoom(zoom);
        m_matrix->set_rotation(rotation);
    }

    std::optional<QImage> Document::get_page_image(int page_number)
    {
        if((page_number >= 0) && (page_number < m_total_pages))
        {
            const auto page = std::make_shared<mupdf_wrapper::Page>(m_context, m_document, page_number);

            const mupdf_wrapper::Pixmap pixmap{m_context, m_matrix, page};
            const auto data = pixmap.get_samples();
            const auto width = pixmap.get_width();
            const auto height = pixmap.get_height();

            return QImage{data, width, height, QImage::Format_RGB888}.copy(); // copy() is needed to perform a deep copy of data
        }
        return {};
    }

    int Document::get_total_pages() const
    {
        return m_total_pages;
    }
}
