#ifndef PDF_READER_SINGLE_PAGE_VIEW_H
#define PDF_READER_SINGLE_PAGE_VIEW_H

#include "document.h"
#include "page_view.h"

#include <QLabel>
#include <QLayout>

#include <memory>

namespace pdf_reader
{
    enum class Page_position
    {
        first,
        previous,
        next,
        last
    };

    class Single_page_view : Page_view
    {
        QLabel m_page;
        int m_page_number;

    public:
        Single_page_view();
        void bind_layout(QLayout &layout) override;
        void unbind_layout(QLayout &layout) override;
        void show_page(Document& document, Page_position page_position);
    };
}

#endif
