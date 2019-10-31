//
// Created by dobrowol on 28.10.2019.
//
#include <memory>
#include "gtest/gtest.h"
#include "../ExpressionEvaluator.cpp"
#include "../exceptions/LiteralTooBig.h"
#include "../exceptions/NegativeLiteralOrUnaryMinus.h"
#include "mocks/EvaluatorMock.h"
#include "mocks/ParserMock.h"
#include "../data_model/Integer.h"

using ::testing::_;
using ::testing::Return;

namespace {
    class ExpressionEvaluatorTest : public ::testing::Test {
    protected:
        std::shared_ptr<ParserMock> parserMock;
        std::shared_ptr<EvaluatorMock> evaluatorMock;
        ExpressionEvaluator expressionEvaluator;

    public:
        ExpressionEvaluatorTest():parserMock(std::make_shared<ParserMock>()),
        evaluatorMock(std::make_shared<EvaluatorMock>())
        ,expressionEvaluator(parserMock, evaluatorMock)
        {}
    };


    TEST_F(ExpressionEvaluatorTest, shouldParse) {
        std::shared_ptr<ASTTree> tree = std::make_shared<Integer>('2');
        EXPECT_CALL(*evaluatorMock, evaluate(_)).WillOnce(Return(12));
        EXPECT_CALL(*parserMock, parse("(4 + 5 * (7 - 3)) - 2")).WillOnce(Return(tree));

    //    auto ret = expressionEvaluator.evaluate("(4 + 5 * (7 - 3)) - 2");
    //    EXPECT_EQ(ret, 12);
    }
}