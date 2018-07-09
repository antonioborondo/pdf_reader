#include "pdf_reader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pdf_reader w;
    w.show();

    return a.exec();
}
