#include "multiple_page_view.h"

namespace pdf_reader
{
    Multiple_page_view::Multiple_page_view()
    {

    }

    void Multiple_page_view::bind_layout(QLayout &layout)
    {

    }

    void Multiple_page_view::unbind_layout(QLayout &layout)
    {

    }

    void Multiple_page_view::show_pages(Document& document)
    {
        for(int page_number{}; page_number < document.get_total_pages(); page_number++)
        {
            const auto page_image = document.get_page_image(page_number);
            if(page_image)
            {
                m_pages.emplace_back(nullptr).setPixmap(QPixmap::fromImage(*page_image));
            }
        }
    }
}
