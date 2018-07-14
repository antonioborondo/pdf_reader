#include "context.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    Context::Context()
        : m_mupdf_context(nullptr)
    {
        m_mupdf_context = fz_new_context(nullptr, nullptr, FZ_STORE_UNLIMITED);
        if(nullptr == m_mupdf_context)
        {
            throw std::runtime_error("Cannot create context");
        }
    }

    Context::~Context()
    {
        if(nullptr != m_mupdf_context)
        {
            fz_drop_context(m_mupdf_context);
            m_mupdf_context = nullptr;
        }
    }

    fz_context* Context::get() const
    {
        return m_mupdf_context;
    }

    bool Context::register_document_handlers() const
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
}
