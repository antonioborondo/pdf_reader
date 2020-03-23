#include "single_page_view.h"

namespace pdf_reader
{
    Single_page_view::Single_page_view(QLayout* layout)
    {
        m_page.setAlignment(Qt::AlignHCenter);
        m_page.resize(m_page.sizeHint());

        layout->addWidget(&m_page);
    }

    void Single_page_view::show_page(std::shared_ptr<QImage> page_image)
    {
        if(nullptr != page_image)
        {
            m_page.setPixmap(QPixmap::fromImage(*page_image));
        }
    }
}
