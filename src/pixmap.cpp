#include "pixmap.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    Pixmap::Pixmap(const Context& context, const Document& document, const Matrix& matrix, unsigned int page_number)
        : m_mupdf_pixmap(nullptr)
        , m_context(context)
        , m_document(document)
        , m_matrix(matrix)
    {
        fz_try(context.get())
            m_mupdf_pixmap = fz_new_pixmap_from_page_number(m_context.get(), m_document.get(), page_number, m_matrix.get(), fz_device_rgb(m_context.get()), 0);
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot create pixmap");
        }
    }

    Pixmap::~Pixmap()
    {
        if(nullptr != m_mupdf_pixmap)
        {
            fz_drop_pixmap(m_context.get(), m_mupdf_pixmap);
            m_mupdf_pixmap = nullptr;
        }
    }

    fz_pixmap* Pixmap::get() const
    {
        return m_mupdf_pixmap;
    }
}
