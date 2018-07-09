#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QImage>

class document
{
public:
    document(const std::string filename);
    ~document();
    const QImage get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const;
};

#endif
