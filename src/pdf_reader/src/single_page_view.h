#ifndef PDF_READER_SINGLE_PAGE_VIEW_H
#define PDF_READER_SINGLE_PAGE_VIEW_H

#include "document.h"

#include <QLabel>
#include <QLayout>

#include <memory>

namespace pdf_reader
{
    class Single_page_view
    {
        std::unique_ptr<QLabel> m_page;

    public:
        Single_page_view(QLayout* layout);

        void show_page(std::shared_ptr<QImage> page_image);
    };
}

#endif
