#ifndef PDF_READER_H
#define PDF_READER_H

#include <QMainWindow>

namespace Ui
{
    class Pdf_reader;
}

class Pdf_reader : public QMainWindow
{
    Q_OBJECT

    Ui::Pdf_reader* m_ui;

public:
    explicit Pdf_reader(QWidget* parent = 0);
    ~Pdf_reader();
};

#endif
