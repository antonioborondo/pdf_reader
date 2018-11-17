#include <catch2/catch.hpp>

#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/matrix.h>
#include <mupdf_wrapper/pixmap.h>

#include <memory>

SCENARIO("Create Pixmap from page number", "[Pixmap]")
{
    GIVEN("One page empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from negative page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Pixmap(context, document, matrix, -1), std::runtime_error);
            }
        }
        WHEN("Create Pixmap from unexisting page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Pixmap(context, document, matrix, 1), std::runtime_error);
            }
        }
        WHEN("Create Pixmap from existing page number")
        {
            THEN("No exception is thrown")
            {
                std::shared_ptr<mupdf_wrapper::Pixmap> pixmap;
                REQUIRE_NOTHROW(pixmap = std::make_shared<mupdf_wrapper::Pixmap>(context, document, matrix, 0));

                AND_THEN("Pixmap is created")
                {
                    const auto mupdf_pixmap = pixmap->get();
                    REQUIRE(nullptr != mupdf_pixmap);
                }
            }
        }     
    }
}

SCENARIO("Create Pixmap from empty page", "[Pixmap]")
{
    GIVEN("One page empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from empty page")
        {
            const mupdf_wrapper::Pixmap pixmap(context, document, matrix, 0);

            THEN("Pixmap is empty")
            {
                const auto height = pixmap.get_height();
                const auto width = pixmap.get_width();

                const auto mupdf_pixmap = pixmap.get();

                for(auto y = 0; y < height; y++)
                {
                    auto pixel_color = &mupdf_pixmap->samples[y * mupdf_pixmap->stride];
                    for(auto x = 0; x < width; x++)
                    {
                        REQUIRE(255 == pixel_color[0]);
                        REQUIRE(255 == pixel_color[1]);
                        REQUIRE(255 == pixel_color[2]);

                        pixel_color += mupdf_pixmap->n;
                    }
                }
            }
        }
    }
}

SCENARIO("Create Pixmap from not empty page", "[Pixmap]")
{
    GIVEN("One page empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_not_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from empty page")
        {
            const mupdf_wrapper::Pixmap pixmap(context, document, matrix, 0);

            THEN("Pixmap is not empty")
            {
                bool pixmap_empty = true;

                const auto height = pixmap.get_height();
                const auto width = pixmap.get_width();

                const auto mupdf_pixmap = pixmap.get();

                for(auto y = 0; y < height; y++)
                {
                    auto pixel_color = &mupdf_pixmap->samples[y * mupdf_pixmap->stride];
                    for(auto x = 0; x < width; x++)
                    {
                        if((255 == pixel_color[0]) || (255 == pixel_color[1]) || (255 == pixel_color[2]))
                        {
                            pixmap_empty = false;
                        }
                        pixel_color += mupdf_pixmap->n;
                    }
                }

                REQUIRE_FALSE(pixmap_empty);
            }
        }
    }
}
