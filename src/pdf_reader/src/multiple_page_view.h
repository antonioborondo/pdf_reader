#ifndef PDF_READER_MULTIPLE_PAGE_VIEW_H
#define PDF_READER_MULTIPLE_PAGE_VIEW_H

#include "document.h"
#include "page_view.h"

#include <QLabel>
#include <QLayout>

#include <boost/ptr_container/ptr_vector.hpp>

namespace pdf_reader
{
    class Multiple_page_view : Page_view
    {
        std::vector<QLabel> m_pages;

    public:
        Multiple_page_view();
        void bind_layout(QLayout &layout) override;
        void unbind_layout(QLayout &layout) override;
        void show_pages(Document& document);
    };
}

#endif
