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
    {
        m_ui->setupUi(this);

        QLayout& layout{*(m_ui->scroll_area_content->layout())};
        m_single_page_view = std::make_unique<Single_page_view>(layout);
        m_multiple_page_view = std::make_unique<Multiple_page_view>(layout);
    }

    Pdf_reader::~Pdf_reader()
    {
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
                m_single_page_view->show_page(*m_document, Page_position::first);
                m_multiple_page_view->add_pages(*m_document);

                if(m_ui->action_single_page->isChecked())
                {
                    m_single_page_view->show();
                }
                else
                {
                    m_multiple_page_view->show();
                }
            }
        }
    }

    void Pdf_reader::on_action_single_page_triggered()
    {
        m_ui->action_single_page->setChecked(true);
        m_ui->action_multi_page->setChecked(false);
        m_ui->action_first_page->setEnabled(true);
        m_ui->action_previous_page->setEnabled(true);
        m_ui->action_next_page->setEnabled(true);
        m_ui->action_last_page->setEnabled(true);

        m_multiple_page_view->hide();
        m_single_page_view->show();
    }

    void Pdf_reader::on_action_multi_page_triggered()
    {
        m_ui->action_single_page->setChecked(false);
        m_ui->action_multi_page->setChecked(true);
        m_ui->action_first_page->setEnabled(false);
        m_ui->action_previous_page->setEnabled(false);
        m_ui->action_next_page->setEnabled(false);
        m_ui->action_last_page->setEnabled(false);

        m_single_page_view->hide();
        m_multiple_page_view->show();
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
