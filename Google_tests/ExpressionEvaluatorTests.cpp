//
// Created by dobrowol on 28.10.2019.
//
#include "gtest/gtest.h"
#include "../ExpressionEvaluator.cpp"
#include "../exceptions/LiteralTooBig.cpp"
#include "../exceptions/NegativeLiteralOrUnaryMinus.h"

namespace {
    class ExpressionEvaluatorTest : public ::testing::Test {
    protected:
        ExpressionEvaluator expressionEvaluator;
    };


    TEST_F(ExpressionEvaluatorTest, shouldParse){
        auto ret = expressionEvaluator.evaluate("(4 + 5 * (7 - 3)) - 2");
        EXPECT_EQ(ret, 12);
    }

    TEST_F(ExpressionEvaluatorTest, literalTooBig){
            EXPECT_THROW(expressionEvaluator.evaluate("10 + 25000000000000"), LiteralTooBig);
    }

    TEST_F(ExpressionEvaluatorTest, negativeLiteralOrUnaryMinus){
        EXPECT_THROW(expressionEvaluator.evaluate("-10"), NegativeLiteralOrUnaryMinus);
    }
}