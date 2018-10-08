#include "pdf_reader.h"

#include "document.h"
#include "ui_pdf_reader.h"

#include <QFileDialog>
#include <QLabel>

#include <exception>
#include <iostream>
#include <memory>

using namespace std;

namespace pdf_reader
{
    Pdf_reader::Pdf_reader(QWidget* parent)
        : QMainWindow(parent)
        , m_ui(nullptr)
        , m_label(nullptr)
    {
        m_label = new QLabel();
        m_label->setAlignment(Qt::AlignHCenter);

        m_ui = new Ui::Pdf_reader();
        m_ui->setupUi(this);
        m_ui->scroll_area_content->layout()->addWidget(m_label);
    }

    Pdf_reader::~Pdf_reader()
    {
        delete m_ui;
        m_ui = nullptr;

        delete m_label;
        m_label = nullptr;
    }

    void Pdf_reader::open_file(const string& filename)
    {
        try
        {
            m_document = make_unique<pdf_reader::Document>(filename);
        }
        catch(const exception& e)
        {
            cout << "Exception: " << e.what() << endl;
        }
    }

    void Pdf_reader::show_page(shared_ptr<QImage> page)
    {
        if(nullptr != page)
        {
            m_label->setPixmap(QPixmap::fromImage(*page));
            m_label->resize(m_label->sizeHint());
        }
    }

    void Pdf_reader::on_action_open_file_triggered()
    {
        const auto filename = QFileDialog::getOpenFileName(this, tr("Open file"), nullptr, tr("*.pdf"));

        if(!filename.isEmpty())
        {
            open_file(filename.toStdString());
            if(nullptr != m_document)
            {
                show_page(m_document->get_page(Page::first));
            }
        }
    }

    void Pdf_reader::on_action_first_page_triggered()
    {
        if(nullptr != m_document)
        {
            show_page(m_document->get_page(Page::first));
        }
    }

    void Pdf_reader::on_action_previous_page_triggered()
    {
        if(nullptr != m_document)
        {
            show_page(m_document->get_page(Page::previous));
        }
    }

    void Pdf_reader::on_action_next_page_triggered()
    {
        if(nullptr != m_document)
        {
            show_page(m_document->get_page(Page::next));
        }
    }

    void Pdf_reader::on_action_last_page_triggered()
    {
        if(nullptr != m_document)
        {
            show_page(m_document->get_page(Page::last));
        }
    }
}
