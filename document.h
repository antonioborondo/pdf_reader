#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "context.h"

#include <QImage>

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class document
    {
        mupdf_wrapper::context m_context;
        fz_document* m_mupdf_document;

    public:
        document(const std::string& filename);
        ~document();
        unsigned int get_total_pages();
        const QImage get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const;
    };
}

#endif
