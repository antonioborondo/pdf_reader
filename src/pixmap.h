#ifndef MUPDF_WRAPPER_PIXMAP_H
#define MUPDF_WRAPPER_PIXMAP_H

#include "context.h"
#include "document.h"
#include "matrix.h"

namespace mupdf_wrapper
{
    class Pixmap
    {
        fz_pixmap* m_mupdf_pixmap;

        Context m_context;
        Document m_document;
        Matrix m_matrix;

    public:
        Pixmap(const Context& context, const Document& document, const Matrix& matrix, unsigned int page_number);
        ~Pixmap();
        fz_pixmap* get() const;
    };
}

#endif
