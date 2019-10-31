//
// Created by dobrowol on 30.10.2019.
//
#include "gtest/gtest.h"
#include "../parser/ASTParser.h"
#include "../data_model/Operation.h"
#include "../evaluator/ASTEvaluator.h"
#include "../exceptions/LiteralTooBig.h"
#include "../exceptions/NegativeLiteralOrUnaryMinus.h"

namespace {
    class ASTParserTest : public ::testing::Test {
    protected:
        ASTParser astParser;
        ASTEvaluator astEvaluator;
    };

    TEST_F(ASTParserTest, shouldParseBraces) {
        std::shared_ptr<ASTTree> tree;
        ASSERT_NO_THROW(tree = astParser.parse("(4 + 5 * (7 - 3)) - 2"));
        Operation *op = dynamic_cast<Operation *>(tree.get());
        EXPECT_EQ(op->operation, '-');
        EXPECT_EQ(astEvaluator.evaluate(tree), 22);
    }

    TEST_F(ASTParserTest, shouldAlsoParseWithoutBraces) {
        std::shared_ptr<ASTTree> tree;
        ASSERT_NO_THROW(tree = astParser.parse("4+5+7/2"));
        Operation *op = dynamic_cast<Operation *>(tree.get());
        EXPECT_EQ(op->operation, '+');
        EXPECT_EQ(astEvaluator.evaluate(tree), 12);
    }

    TEST_F(ASTParserTest, literalTooBig) {
        std::shared_ptr<ASTTree> tree;
        EXPECT_THROW(astParser.parse("10 + 2"), LiteralTooBig);
    }

    TEST_F(ASTParserTest, negativeLiteralOrUnaryMinus) {
        std::shared_ptr<ASTTree> tree;
        EXPECT_THROW(astParser.parse("-10"), NegativeLiteralOrUnaryMinus);
    }

    TEST_F(ASTParserTest, negativeLiteralOrUnaryMinusWithBrackets) {
        std::shared_ptr<ASTTree> tree;
        EXPECT_THROW(astParser.parse("(-10)"), NegativeLiteralOrUnaryMinus);
    }
}
