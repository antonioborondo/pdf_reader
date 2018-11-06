#include <mupdf_wrapper/context.h>

#include <catch2/catch.hpp>

#include <memory>

SCENARIO("Create Context", "[Context]")
{
    WHEN("Create Context")
    {
        std::unique_ptr<mupdf_wrapper::Context> context;

        THEN("No exception is thrown")
        {
            REQUIRE_NOTHROW(context = std::make_unique<mupdf_wrapper::Context>());

            AND_THEN("Context is created")
            {
                const auto mupdf_context = context->get();
                REQUIRE(nullptr != mupdf_context);
            }
        }
    }
}

SCENARIO("Register document handlers", "[Context]")
{
    GIVEN("Context")
    {
        const mupdf_wrapper::Context context;
        const auto mupdf_context = context.get();
        REQUIRE(nullptr != mupdf_context);

        WHEN("Register document handlers")
        {
            THEN("No exception is thrown")
            {
                REQUIRE_NOTHROW(context.register_document_handlers());
            }
        }
    }
}
