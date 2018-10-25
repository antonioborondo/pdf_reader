#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/page.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("Create a page", "[page]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page.pdf");

    REQUIRE_NOTHROW(mupdf_wrapper::Page(context, document, 0));
}
