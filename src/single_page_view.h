#ifndef PDF_READER_SINGLE_PAGE_VIEW_H
#define PDF_READER_SINGLE_PAGE_VIEW_H

#include <QLabel>

class QLayout;

namespace pdf_reader
{
    class Document;

    enum class Page_position
    {
        first,
        previous,
        next,
        last
    };

    class Single_page_view : public QLabel
    {
        int m_page_number;

    public:
        Single_page_view(QWidget* parent, QLayout* layout);
        void show_page(Document& document, Page_position page_position);
    };
}

#endif
