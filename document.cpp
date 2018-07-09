#include "document.h"

#include <mupdf/fitz.h>

document::document(const std::string filename)
{

}

document::~document()
{

}

const QImage document::get_page_image(unsigned int page_number, unsigned int zoom, float rotate) const
{
    char *input;
    //float zoom, rotate;
    int page_count;
    fz_context *ctx;
    fz_document *doc;
    fz_pixmap *pix;
    fz_matrix ctm;
    int x, y;

    //input = const_cast<char*>(file_path.c_str());
    page_number = 0;
    zoom = 100;
    rotate = 0;

    /* Create a context to hold the exception stack and various caches. */
    ctx = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
    if (!ctx)
    {
        fprintf(stderr, "cannot create mupdf context\n");
        //return EXIT_FAILURE;
    }

    /* Register the default file types to handle. */
    fz_try(ctx)
        fz_register_document_handlers(ctx);
    fz_catch(ctx)
    {
        fprintf(stderr, "cannot register document handlers: %s\n", fz_caught_message(ctx));
        fz_drop_context(ctx);
        //return EXIT_FAILURE;
    }

    /* Open the document. */
    fz_try(ctx)
        doc = fz_open_document(ctx, "C:/Users/antonioborondo/Desktop/test.pdf");
    fz_catch(ctx)
    {
        fprintf(stderr, "cannot open document: %s\n", fz_caught_message(ctx));
        fz_drop_context(ctx);
        //return EXIT_FAILURE;
    }

    /* Count the number of pages. */
    fz_try(ctx)
        page_count = fz_count_pages(ctx, doc);
    fz_catch(ctx)
    {
        fprintf(stderr, "cannot count number of pages: %s\n", fz_caught_message(ctx));
        fz_drop_document(ctx, doc);
        fz_drop_context(ctx);
        //return EXIT_FAILURE;
    }

    if (page_number < 0 || page_number >= page_count)
    {
        fprintf(stderr, "page number out of range: %d (page count %d)\n", page_number + 1, page_count);
        fz_drop_document(ctx, doc);
        fz_drop_context(ctx);
        //return EXIT_FAILURE;
    }

    /* Compute a transformation matrix for the zoom and rotation desired. */
    /* The default resolution without scaling is 72 dpi. */
    fz_scale(&ctm, zoom / 100, zoom / 100);
    fz_pre_rotate(&ctm, rotate);

    /* Render page to an RGB pixmap. */
    fz_try(ctx)
        pix = fz_new_pixmap_from_page_number(ctx, doc, page_number, &ctm, fz_device_rgb(ctx), 0);
    fz_catch(ctx)
    {
        fprintf(stderr, "cannot render page: %s\n", fz_caught_message(ctx));
        fz_drop_document(ctx, doc);
        fz_drop_context(ctx);
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

    samples = fz_pixmap_samples(ctx, pix);
    width = fz_pixmap_width(ctx, pix);
    height = fz_pixmap_height(ctx, pix);

copyed_samples=samples;

    // with Qt 5.2, Format_RGB888 is correct for any architecture
            const auto image = QImage(copyed_samples,
                           width, height, QImage::Format_RGB888, NULL, copyed_samples);
return image;

    /* Clean up. */
    fz_drop_pixmap(ctx, pix);
    fz_drop_document(ctx, doc);
    fz_drop_context(ctx);
}
