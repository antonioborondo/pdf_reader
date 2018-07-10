#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "context.h"

#include <QImage>

#include <mupdf/fitz.h>

class document
{
    context m_context;
    fz_document* m_mupdf_document;

public:
    document(const std::string& filename);
    ~document();
    const QImage get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const;
};

#endif
