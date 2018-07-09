#include "pdf_reader.h"
#include "ui_pdf_reader.h"

pdf_reader::pdf_reader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pdf_reader)
{
    ui->setupUi(this);
}

pdf_reader::~pdf_reader()
{
    delete ui;
}
