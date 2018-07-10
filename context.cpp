#include "context.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    context::context()
        : m_mupdf_context(nullptr)
    {
        m_mupdf_context = fz_new_context(nullptr, nullptr, FZ_STORE_UNLIMITED);
        if(nullptr == m_mupdf_context)
        {
            throw std::runtime_error("Context cannot be created");
        }
    }

    context::~context()
    {
        if(nullptr != m_mupdf_context)
        {
            fz_drop_context(m_mupdf_context);
            m_mupdf_context = nullptr;
        }
    }

    bool context::register_document_handlers() const
    {
        auto document_handlers_registered = true;

        fz_try(m_mupdf_context)
            fz_register_document_handlers(m_mupdf_context);
        fz_catch(m_mupdf_context)
        {
            document_handlers_registered = false;
        }

        return document_handlers_registered;
    }

    fz_context* context::get() const
    {
        return m_mupdf_context;
    }
}
