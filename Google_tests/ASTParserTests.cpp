//
// Created by dobrowol on 30.10.2019.
//
#include "gtest/gtest.h"
#include "../parser/ASTParser.h"
#include "../data_model/Operation.h"
#include "../evaluator/ASTEvaluator.h"

namespace {
    class ASTParserTest : public ::testing::Test {
    protected:
        ASTParser astParser;
        ASTEvaluator astEvaluator;
    };

    TEST_F(ASTParserTest, shouldParse){
        std::shared_ptr<ASTTree> tree;
        ASSERT_NO_THROW(tree = astParser.parse("(4 + 5 * (7 - 3)) - 2"));
        Operation* op = dynamic_cast<Operation*>(tree.get());
        EXPECT_EQ(op->operation, '-');
        EXPECT_EQ(astEvaluator.evaluate(tree), 22);
    }
}
