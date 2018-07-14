#ifndef MUPDF_WRAPPER_PIXMAP_H
#define MUPDF_WRAPPER_PIXMAP_H

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class Context;
    class Document;
    class Matrix;

    class Pixmap
    {
        fz_pixmap* m_mupdf_pixmap;
        Context* m_context;

    public:
        Pixmap(Context* context, Document* document, Matrix* matrix, unsigned int page_number);
        ~Pixmap();
        fz_pixmap* get() const;
        unsigned char* get_samples() const;
        int get_width() const;
        int get_height() const;
    };
}

#endif
