#include "pdf_reader.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

    pdf_reader::Pdf_reader pdf_reader;
    pdf_reader.show();

    return application.exec();
}
