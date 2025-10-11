#include <gtest/gtest.h>
#include "./src/seven.h"

// === ТЕСТЫ КОНСТРУКТОРОВ ===

TEST(SevenConstructorTest, DefaultConstructor) {
    Seven a;
    std::ostringstream oss;
    a.print(oss);
    EXPECT_EQ(oss.str(), "0");
}

TEST(SevenConstructorTest, FromStringValid) {
    Seven a("123");
    std::ostringstream oss;
    a.print(oss);
    EXPECT_EQ(oss.str(), "123");
}

TEST(SevenConstructorTest, FromStringInvalidThrows) {
    EXPECT_THROW(Seven("789"), std::invalid_argument);
}

TEST(SevenConstructorTest, FromInitializerList) {
    Seven a({1, 2, 3});
    std::ostringstream oss;
    a.print(oss);
    EXPECT_EQ(oss.str(), "321");
}

TEST(SevenConstructorTest, CopyConstructor) {
    Seven a("123");
    Seven b(a);
    std::ostringstream oss;
    b.print(oss);
    EXPECT_EQ(oss.str(), "123");
}

TEST(SevenConstructorTest, MoveConstructor) {
    Seven a("456");
    Seven b(std::move(a));
    std::ostringstream oss;
    b.print(oss);
    EXPECT_EQ(oss.str(), "456");
}

// === ТЕСТЫ ПРИСВАИВАНИЯ ===

TEST(SevenAssignmentTest, CopyAssignment) {
    Seven a("12");
    Seven b;
    b = a;
    std::ostringstream oss;
    b.print(oss);
    EXPECT_EQ(oss.str(), "12");
}

TEST(SevenAssignmentTest, MoveAssignment) {
    Seven a("123");
    Seven b;
    b = std::move(a);
    std::ostringstream oss;
    b.print(oss);
    EXPECT_EQ(oss.str(), "123");
}

// === ТЕСТЫ АРИФМЕТИКИ ===

TEST(SevenArithmeticTest, AddSimple) {
    Seven a("3");
    Seven b("4");
    Seven c = a.add(b);
    std::ostringstream oss;
    c.print(oss);
    EXPECT_EQ(oss.str(), "10"); // 3 + 4 = 7 (в 7-ричной: 10)
}

TEST(SevenArithmeticTest, AddWithCarry) {
    Seven a("66");
    Seven b("1");
    Seven c = a.add(b);
    std::ostringstream oss;
    c.print(oss);
    EXPECT_EQ(oss.str(), "100");
}

TEST(SevenArithmeticTest, SubtractSimple) {
    Seven a("10"); // 7
    Seven b("1");  // 1
    Seven c = a.subtract(b);
    std::ostringstream oss;
    c.print(oss);
    EXPECT_EQ(oss.str(), "6"); // 7 - 1 = 6
}

TEST(SevenArithmeticTest, SubtractThrowsIfNegative) {
    Seven a("1");
    Seven b("2");
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
}

// === ТЕСТЫ СРАВНЕНИЙ ===

TEST(SevenComparisonTest, EqualsTrue) {
    Seven a("123");
    Seven b("123");
    EXPECT_TRUE(a.equals(b));
}

TEST(SevenComparisonTest, EqualsFalse) {
    Seven a("123");
    Seven b("124");
    EXPECT_FALSE(a.equals(b));
}

TEST(SevenComparisonTest, Greater) {
    Seven a("126");
    Seven b("125");
    EXPECT_TRUE(a.greater(b));
}

TEST(SevenComparisonTest, Less) {
    Seven a("5");
    Seven b("6");
    EXPECT_TRUE(a.less(b));
}

// === ТЕСТЫ НОРМАЛИЗАЦИИ ===

TEST(SevenNormalizationTest, RemovesLeadingZeros) {
    Seven a({3, 0, 0});
    std::ostringstream oss;
    a.print(oss);
    EXPECT_EQ(oss.str(), "3");
}

// === ТЕСТ НА СЛОЖНОЕ СЛОЖЕНИЕ ===

TEST(SevenArithmeticTest, AddMultipleDigits) {
    Seven a("666");
    Seven b("1");
    Seven c = a.add(b);
    std::ostringstream oss;
    c.print(oss);
    EXPECT_EQ(oss.str(), "1000");
}

// === ТЕСТ НА ВЫВОД ===

TEST(SevenOutputTest, PrintCorrectlyFormats) {
    Seven a("123");
    std::ostringstream oss;
    a.print(oss);
    EXPECT_EQ(oss.str(), "123");
}
