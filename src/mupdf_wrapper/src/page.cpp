#include "page.h"

#include "context.h"
#include "document.h"

namespace mupdf_wrapper
{
    Page::Page(std::shared_ptr<Context> context, std::shared_ptr<Document> document, int page_number)
        : m_context(context)
    {
        m_raw_page = fz_load_page(context->get(), document->get(), page_number);
        if(nullptr == m_raw_page)
        {
            throw std::runtime_error("Cannot load page");
        }
    }

    Page::~Page()
    {
        if(nullptr != m_raw_page)
        {
            fz_drop_page(m_context->get(), m_raw_page);
            m_raw_page = nullptr;
        }
    }
}
