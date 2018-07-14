#ifndef MUPDF_WRAPPER_CONTEXT_H
#define MUPDF_WRAPPER_CONTEXT_H

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class Context
    {
        fz_context* m_mupdf_context;

    public:
        Context();
        ~Context();
        fz_context* get() const;
        void register_document_handlers() const;
    };
}

#endif
