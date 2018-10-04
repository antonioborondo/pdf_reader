#ifndef PDF_READER_H
#define PDF_READER_H

#include <QLabel>
#include <QMainWindow>
#include <QStackedLayout>

namespace Ui
{
    class Pdf_reader;
}

class Pdf_reader : public QMainWindow
{
    Q_OBJECT

    Ui::Pdf_reader* m_ui;
    QLabel* m_label;
    QStackedLayout* m_stacked_layout;

public:
    explicit Pdf_reader(QWidget* parent = nullptr);
    ~Pdf_reader();

private:
    void open_file(const std::string& filename);

private slots:
    void on_menu_open_file_triggered();
};

#endif
