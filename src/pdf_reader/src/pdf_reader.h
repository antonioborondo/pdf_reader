#ifndef PDF_READER_PDF_READER_H
#define PDF_READER_PDF_READER_H

#include <QMainWindow>

#include <filesystem>
#include <memory>

class QLabel;

namespace Ui
{
    class Pdf_reader;
}

namespace pdf_reader
{
    class Document;
    class Multiple_page_view;
    class Single_page_view;

    class Pdf_reader : public QMainWindow
    {
        Q_OBJECT

        std::unique_ptr<Ui::Pdf_reader> m_ui;
        std::unique_ptr<Document> m_document;
        std::unique_ptr<Multiple_page_view> m_multiple_page_view;
        std::unique_ptr<Single_page_view> m_single_page_view;

    public:
        explicit Pdf_reader(QWidget* parent = nullptr);
        ~Pdf_reader();

    private:
        void open_file(const std::filesystem::path& filename);

    private slots:
        void on_action_open_file_triggered();
        void on_action_first_page_triggered();
        void on_action_previous_page_triggered();
        void on_action_next_page_triggered();
        void on_action_last_page_triggered();
    };
}

#endif
