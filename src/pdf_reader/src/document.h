#ifndef PDF_READER_DOCUMENT_H
#define PDF_READER_DOCUMENT_H

#include <filesystem>
#include <memory>

class QImage;

namespace mupdf_wrapper
{
    class Context;
    class Document;
    class Matrix;
    class Pixmap;
}

namespace pdf_reader
{
    enum class Page
    {
        first,
        previous,
        next,
        last
    };

    class Document
    {
        std::shared_ptr<mupdf_wrapper::Context> m_context;
        std::shared_ptr<mupdf_wrapper::Document> m_document;
        std::shared_ptr<mupdf_wrapper::Matrix> m_matrix;
        std::shared_ptr<mupdf_wrapper::Pixmap> m_pixmap;

        int m_page_number;
        int m_total_pages;

    public:
        Document(const std::filesystem::path& filename);
        std::shared_ptr<QImage> get_page(Page page);

    private:
        std::shared_ptr<QImage> get_page(int page_number);
    };
}

#endif
