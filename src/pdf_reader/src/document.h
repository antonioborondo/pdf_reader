#ifndef PDF_READER_DOCUMENT_H
#define PDF_READER_DOCUMENT_H

#include <filesystem>
#include <memory>
#include <optional>

class QImage;

namespace mupdf_wrapper
{
    class Context;
    class Document;
    class Matrix;
}

namespace pdf_reader
{
    class Document
    {
        std::shared_ptr<mupdf_wrapper::Context> m_context;
        std::shared_ptr<mupdf_wrapper::Document> m_document;
        std::shared_ptr<mupdf_wrapper::Matrix> m_matrix;
        int m_total_pages;

    public:
        Document(const std::filesystem::path& filename);

        std::optional<QImage> get_page_image(int page_number);

        int get_total_pages() const;
    };
}

#endif
