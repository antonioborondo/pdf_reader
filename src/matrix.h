#ifndef MUPDF_WRAPPER_MATRIX_H
#define MUPDF_WRAPPER_MATRIX_H

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class matrix
    {
        fz_matrix* m_mupdf_matrix;

    public:
        matrix();
        ~matrix();
        void set_zoom(unsigned int zoom) const;
        void set_rotation(float rotation) const;
        const fz_matrix* get() const;
    };
}

#endif
