#include "pdf_reader.h"

#include "mupdf_wrapper/context.h"
#include "mupdf_wrapper/document.h"
#include "mupdf_wrapper/matrix.h"
#include "mupdf_wrapper/pixmap.h"
#include "ui_pdf_reader.h"

#include <exception>
#include <iostream>

#include <QLabel>
#include <QStackedLayout>

Pdf_reader::Pdf_reader(QWidget* parent)
    : QMainWindow(parent)
    , m_ui(new Ui::Pdf_reader)
{
    m_ui->setupUi(this);

    try{
        const std::string filename = "C:/Users/antonioborondo/Desktop/test.pdf";
        const unsigned int page_number = 0;
        const unsigned int zoom = 100;
        const float rotation = 0;

        mupdf_wrapper::Context context;
        context.register_document_handlers();

        mupdf_wrapper::Document document(&context, filename);

        mupdf_wrapper::Matrix matrix;
        matrix.set_zoom(zoom);
        matrix.set_rotation(rotation);

        const mupdf_wrapper::Pixmap pixmap(&context, &document, &matrix, page_number);
        const auto samples = pixmap.get_samples();
        const auto width = pixmap.get_width();
        const auto height = pixmap.get_height();

        const auto image = QImage(samples, width, height, QImage::Format_RGB888, nullptr, samples);

        // Add image to UI
        QLabel* label = new QLabel();
        label->setPixmap(QPixmap::fromImage(image));
        label->resize(label->sizeHint());
        QStackedLayout* stacked_layout = new QStackedLayout();
        m_ui->centralWidget->setLayout(stacked_layout);
        stacked_layout->addWidget(label);
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

Pdf_reader::~Pdf_reader()
{
    delete m_ui;
}
