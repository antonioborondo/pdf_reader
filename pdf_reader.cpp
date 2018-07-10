#include "pdf_reader.h"
#include "ui_pdf_reader.h"

#include <QLabel>
#include <QStackedLayout>
#include <mupdf/fitz.h>

#include "document.h"

#include <exception>
#include <iostream>

pdf_reader::pdf_reader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pdf_reader)
{
    ui->setupUi(this);

    try{
        const mupdf_wrapper::document document{"C:/Users/antonioborondo/Desktop/test.pdf"};

        unsigned int page_number{0};
        unsigned int zoom{100};
        unsigned int rotate{0};
        const QImage image = document.get_page_image(page_number, zoom, rotate);

        QLabel* label = new QLabel();
        label->setPixmap(QPixmap::fromImage(image));
        label->resize(label->sizeHint());

        QStackedLayout* stacked_layout = new QStackedLayout();
        ui->centralWidget->setLayout(stacked_layout);

        stacked_layout->addWidget(label);
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

pdf_reader::~pdf_reader()
{
    delete ui;
}
