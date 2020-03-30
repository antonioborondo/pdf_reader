#include "multiple_page_view.h"

namespace pdf_reader
{
    Multiple_page_view::Multiple_page_view(QLayout &layout)
        : m_layout(layout)
    {
    }

    Multiple_page_view::~Multiple_page_view()
    {
        remove_pages();
    }

    void Multiple_page_view::add_pages(Document& document)
    {
        remove_pages();

        for(int page_number{}; page_number < document.get_total_pages(); page_number++)
        {
            const auto page_image = document.get_page_image(page_number);
            if(page_image)
            {
                QLabel* page{new QLabel{}};
                constexpr int margin{5};
                page->setMargin(margin);
                page->setAlignment(Qt::AlignHCenter);
                page->setPixmap(QPixmap::fromImage(*page_image));

                m_pages.push_back(page);
            }
        }

        for(auto& page : m_pages)
        {
            m_layout.addWidget(&page);
        }
    }

    void Multiple_page_view::remove_pages()
    {
        for(auto& page : m_pages)
        {
            m_layout.removeWidget(&page);
        }

        m_pages.clear();
    }
}
