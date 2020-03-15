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

    class Pdf_reader : public QMainWindow
    {
        Q_OBJECT

        std::unique_ptr<Ui::Pdf_reader> m_ui;
        std::unique_ptr<QLabel> m_document_area;

        std::unique_ptr<pdf_reader::Document> m_document;

    public:
        explicit Pdf_reader(QWidget* parent = nullptr);
        ~Pdf_reader();

    private:
        void open_file(const std::filesystem::path& filename);
        void show_page(std::shared_ptr<QImage> page);

    private slots:
        void on_action_open_file_triggered();
        void on_action_first_page_triggered();
        void on_action_previous_page_triggered();
        void on_action_next_page_triggered();
        void on_action_last_page_triggered();
    };
}

#endif
