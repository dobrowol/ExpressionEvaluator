//
// Created by dobrowol on 28.10.2019.
//
#include "gtest/gtest.h"

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
        try {
            expressionEvaluator.evaluate("10 + 25000000000000");
        }
        catch( const LiteralTooBig& err ) {
            ASSERT_EQ("Literal too big", err.msg());
        }
    }

    TEST_F(ExpressionEvaluatorTest, negativeLiteralOrUnaryMinus){
        try {
            expressionEvaluator.evaluate("-10");
        }
        catch( const NgativeLiteralOrUnaryMinus& err ) {
            ASSERT_EQ("Literal too big", err.msg());
        }
    }
}