#ifndef PDF_READER_H
#define PDF_READER_H

#include "mupdf_wrapper/context.h"
#include "mupdf_wrapper/document.h"

#include <memory>

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

    std::shared_ptr<mupdf_wrapper::Context> m_context;
    std::shared_ptr<mupdf_wrapper::Document> m_document;
    int m_page_number;

public:
    explicit Pdf_reader(QWidget* parent = nullptr);
    ~Pdf_reader();

private:
    void open_file(const std::string& filename);
    void show_page(int page_number);

private slots:
    void on_action_open_file_triggered();
    void on_action_first_page_triggered();
    void on_action_previous_page_triggered();
    void on_action_next_page_triggered();
    void on_action_last_page_triggered();
};

#endif
