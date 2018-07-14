#include "matrix.h"

namespace mupdf_wrapper
{
    matrix::matrix()
    {
        m_mupdf_matrix = new fz_matrix;
        set_zoom(100);
        set_rotation(0);
    }

    matrix::~matrix()
    {
        delete m_mupdf_matrix;
        m_mupdf_matrix = nullptr;
    }

    void matrix::set_zoom(unsigned int zoom) const
    {
        fz_scale(m_mupdf_matrix, zoom/100, zoom/100);
    }

    void matrix::set_rotation(float rotation) const
    {
        fz_pre_rotate(m_mupdf_matrix, rotation);
    }

    const fz_matrix* matrix::get() const
    {
        return m_mupdf_matrix;
    }
}
