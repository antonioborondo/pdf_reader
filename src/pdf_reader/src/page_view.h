#ifndef PDF_READER_PAGE_VIEW_H
#define PDF_READER_PAGE_VIEW_H

#include <QLayout>

namespace pdf_reader
{
    class Page_view
    {
    public:
        //virtual ~Page_view();
        virtual void show() = 0;
        virtual void hide() = 0;
    };
}

#endif
