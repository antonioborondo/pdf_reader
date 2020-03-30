#include "single_page_view.h"

namespace pdf_reader
{
    Single_page_view::Single_page_view(QLayout &layout)
        : m_layout(layout)
        , m_page_number{}
    {
        constexpr int margin{5};
        m_page.setMargin(margin);
        m_page.setAlignment(Qt::AlignHCenter);
    }

    void Single_page_view::show()
    {
        m_layout.addWidget(&m_page);
    }

    void Single_page_view::hide()
    {
        m_layout.removeWidget(&m_page);
    }

    void Single_page_view::show_page(Document& document, Page_position page_position)
    {
        int page_number{};

        switch(page_position)
        {
            case Page_position::first:
                page_number = 0;
                break;
            case Page_position::previous:
                page_number = m_page_number - 1;
                break;
            case Page_position::next:
                page_number = m_page_number + 1;
                break;
            case Page_position::last:
                page_number = document.get_total_pages() - 1;
                break;
        }

        const auto page_image = document.get_page_image(page_number);
        if(page_image)
        {
            m_page.setPixmap(QPixmap::fromImage(*page_image));

            m_page_number = page_number;
        }
    }
}
