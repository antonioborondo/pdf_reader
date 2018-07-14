#ifndef MUPDF_WRAPPER_DOCUMENT_H
#define MUPDF_WRAPPER_DOCUMENT_H

#include "context.h"
#include "matrix.h"

#include <QImage>

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class document
    {
        mupdf_wrapper::context m_context;
        mupdf_wrapper::matrix m_matrix;
        fz_document* m_mupdf_document;

    public:
        document(const std::string& filename);
        ~document();
        void set_zoom(unsigned int zoom) const;
        void set_rotation(float rotation) const;
        unsigned int get_total_pages();
        const QImage get_page_image(unsigned int page_number) const;
    };
}

#endif
