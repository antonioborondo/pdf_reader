#include "document.h"

#include <stdexcept>

document::document(const std::string& filename)
    : m_context()
    , m_mupdf_document(nullptr)
{
    m_context.register_document_handlers();

    fz_try(m_context.get())
        m_mupdf_document = fz_open_document(m_context.get(), filename.c_str());
    fz_catch(m_context.get())
    {
        throw std::runtime_error("Document cannot be opened");
    }
}

document::~document()
{
    if(nullptr != m_mupdf_document)
    {
        fz_drop_document(m_context.get(), m_mupdf_document);
        m_mupdf_document = nullptr;
    }
}

const QImage document::get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const
{
    fz_pixmap *pix;
    fz_matrix ctm;
    int x, y;

//    fz_try(m_context.get())
//        m_total_pages = fz_count_pages(m_context.get(), m_mupdf_document);
//    fz_catch(m_context.get())
//    {
//        throw std::runtime_error("Pages cannot be counted");
//    }

    //input = const_cast<char*>(file_path.c_str());
    page_number = 0;
    zoom = 100;
    rotate = 0;

//    if (page_number < 0 || page_number >= m_page_count)
//    {
//        //fprintf(stderr, "page number out of range: %d (page count %d)\n", page_number + 1, m_page_count);
//        //fz_drop_document(m_, doc);
//        //fz_drop_context(ctx);
//        //return EXIT_FAILURE;
//    }

    /* Compute a transformation matrix for the zoom and rotation desired. */
    /* The default resolution without scaling is 72 dpi. */
    fz_scale(&ctm, zoom / 100, zoom / 100);
    fz_pre_rotate(&ctm, rotate);

    /* Render page to an RGB pixmap. */
    fz_try(m_context.get())
        pix = fz_new_pixmap_from_page_number(m_context.get(), m_mupdf_document, page_number, &ctm, fz_device_rgb(m_context.get()), 0);
    fz_catch(m_context.get())
    {
        //fprintf(stderr, "cannot render page: %s\n", fz_caught_message(m_mupdf_context));
        fz_drop_document(m_context.get(), m_mupdf_document);
        //fz_drop_context(m_context.get());
        //return EXIT_FAILURE;
    }

    /* Print image data in ascii PPM format. */
    printf("P3\n");
    printf("%d %d\n", pix->w, pix->h);
    printf("255\n");
    for (y = 0; y < pix->h; ++y)
    {
        unsigned char *p = &pix->samples[y * pix->stride];
        for (x = 0; x < pix->w; ++x)
        {
            if (x > 0)
                printf("  ");
            printf("%3d %3d %3d", p[0], p[1], p[2]);
            p += pix->n;
        }
        printf("\n");
    }

    unsigned char *samples = NULL;
    unsigned char *copyed_samples = NULL;
    int width = 0;
    int height = 0;

    samples = fz_pixmap_samples(m_context.get(), pix);
    width = fz_pixmap_width(m_context.get(), pix);
    height = fz_pixmap_height(m_context.get(), pix);

copyed_samples=samples;

    // with Qt 5.2, Format_RGB888 is correct for any architecture
            const auto image = QImage(copyed_samples,
                           width, height, QImage::Format_RGB888, NULL, copyed_samples);
return image;

    /* Clean up. */
    fz_drop_pixmap(m_context.get(), pix);

}
