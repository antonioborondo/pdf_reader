#ifndef PDF_READER_MULTIPLE_PAGE_VIEW_H
#define PDF_READER_MULTIPLE_PAGE_VIEW_H

#include "document.h"
#include "page_view.h"

#include <boost/ptr_container/ptr_vector.hpp>
#include <QLabel>
#include <QLayout>

namespace pdf_reader
{
    class Multiple_page_view : Page_view
    {
        QLayout& m_layout;
        boost::ptr_vector<QLabel> m_pages;

    public:
        Multiple_page_view(QLayout& layout);
        ~Multiple_page_view();

        void show() override;
        void hide() override;

        void add_pages(Document& document);
        void remove_pages();

        void show_pages(Document& document);



        void add_pages_to_layout();
        void remove_pages_from_layout();
    };
}

#endif
