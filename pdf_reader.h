#ifndef PDF_READER_H
#define PDF_READER_H

#include <QMainWindow>

namespace Ui {
class pdf_reader;
}

class pdf_reader : public QMainWindow
{
    Q_OBJECT

public:
    explicit pdf_reader(QWidget *parent = 0);
    ~pdf_reader();

private:
    Ui::pdf_reader *ui;
};

#endif // PDF_READER_H
