#ifndef CONTEXT_H
#define CONTEXT_H

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class context
    {
        fz_context* m_mupdf_context;

    public:
        context();
        ~context();
        bool register_document_handlers() const;
        fz_context* get() const;
    };
}

#endif
