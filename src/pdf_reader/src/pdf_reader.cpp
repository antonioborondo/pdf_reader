#include "pdf_reader.h"

#include "document.h"
#include "multiple_page_view.h"
#include "single_page_view.h"
#include "ui_pdf_reader.h"

#include <QFileDialog>
#include <QLabel>

#include <exception>
#include <iostream>

namespace pdf_reader
{
    Pdf_reader::Pdf_reader(QWidget* parent)
        : QMainWindow(parent)
        , m_ui(std::make_unique<Ui::Pdf_reader>())
        , m_multiple_page_view{std::make_unique<Multiple_page_view>()}
        , m_single_page_view{std::make_unique<Single_page_view>()}
    {
        m_ui->setupUi(this);
        //m_single_page_view->bind_layout(*(m_ui->scroll_area_content->layout()));
        m_multiple_page_view->bind_layout(*(m_ui->scroll_area_content->layout()));
    }

    Pdf_reader::~Pdf_reader()
    {
        //m_single_page_view->unbind_layout(*(m_ui->scroll_area_content->layout()));
        m_multiple_page_view->unbind_layout(*(m_ui->scroll_area_content->layout()));
    }

    void Pdf_reader::open_file(const std::filesystem::path& filename)
    {
        try
        {
            m_document = std::make_unique<Document>(filename);
        }
        catch(const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    void Pdf_reader::on_action_open_file_triggered()
    {
        const auto filename = QFileDialog::getOpenFileName(this, tr("Open file"), nullptr, tr("*.pdf"));

        if(!filename.isEmpty())
        {
            open_file(std::filesystem::path{filename.toStdString()});
            if(nullptr != m_document)
            {
                //m_single_page_view->show_page(*m_document, Page_position::first);
                m_multiple_page_view->show_pages(*m_document);
            }
        }
    }

    void Pdf_reader::on_action_first_page_triggered()
    {
        if(nullptr != m_document)
        {
            m_single_page_view->show_page(*m_document, Page_position::first);
        }
    }

    void Pdf_reader::on_action_previous_page_triggered()
    {
        if(nullptr != m_document)
        {
            m_single_page_view->show_page(*m_document, Page_position::previous);
        }
    }

    void Pdf_reader::on_action_next_page_triggered()
    {
        if(nullptr != m_document)
        {
            m_single_page_view->show_page(*m_document, Page_position::next);
        }
    }

    void Pdf_reader::on_action_last_page_triggered()
    {
        if(nullptr != m_document)
        {
            m_single_page_view->show_page(*m_document, Page_position::last);
        }
    }
}
