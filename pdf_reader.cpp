#include "pdf_reader.h"
#include "ui_pdf_reader.h"

#include <QLabel>
#include <QStackedLayout>
#include <mupdf/fitz.h>

#include "document.h"

pdf_reader::pdf_reader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pdf_reader)
{
    ui->setupUi(this);

    const document my_document{"C:/Users/antonioborondo/Desktop/test.pdf"};

    unsigned int page_number{0};
    unsigned int zoom{100};
    unsigned int rotate{0};
    const QImage image = my_document.get_page_image(page_number, zoom, rotate);

    QLabel* label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image));
    label->resize(label->sizeHint());

    QStackedLayout* stacked_layout = new QStackedLayout();
    ui->centralWidget->setLayout(stacked_layout);

    stacked_layout->addWidget(label);
}

pdf_reader::~pdf_reader()
{
    delete ui;
}
