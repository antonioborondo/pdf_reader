#ifndef MUPDF_WRAPPER_DOCUMENT_H
#define MUPDF_WRAPPER_DOCUMENT_H

#include "context.h"
#include "matrix.h"

#include <QImage>

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class Document
    {
        fz_document* m_mupdf_document;

        Context m_context;
        Matrix m_matrix;

    public:
        Document(const std::string& filename);
        ~Document();
        fz_document* get() const;
        void set_zoom(unsigned int zoom) const;
        void set_rotation(float rotation) const;
        unsigned int get_total_pages();
        const QImage get_page_image(unsigned int page_number) const;
    };
}

#endif
