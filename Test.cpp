#include <gtest/gtest.h>
#include <sstream>
#include "../CatenaryLib/CatenaryLib.h"

using namespace std;


// ÁŔÇÎÂŰÉ ĘÎÍŃŇĐÓĘŇÎĐ
TEST(CatenaryTest, DefaultConstructorTest1) {
Catenary::Catenary cat;
EXPECT_EQ(cat.get_parameter(), 1);
}

TEST(CatenaryTest, DefaultConstructorTest2) {
Catenary::Catenary cat;
EXPECT_EQ(cat.get_x1(), -1);
}

TEST(CatenaryTest, DefaultConstructorTest3) {
Catenary::Catenary cat;
EXPECT_EQ(cat.get_x2(), 1);
}


// ĘÎÍŃŇĐÓĘŇÎĐ
TEST(CatenaryTest, ConstructorTest1) {
ASSERT_NO_THROW(Catenary::Catenary a(-1, 1, 1));
}

TEST(CatenaryTest, ConstructorTest2) {
ASSERT_ANY_THROW(Catenary::Catenary a(-1, 1, 0));
}


// ŃĹŇŇĹĐŰ
TEST(CatenaryTest, SetterTest1) {
Catenary::Catenary cat;
cat.set_x1(-2);
EXPECT_EQ(cat.get_x1(), -2);
}

TEST(CatenaryTest, SetterTest2) {
Catenary::Catenary cat;
cat.set_x2(4);
EXPECT_EQ(cat.get_x2(), 4);
}

TEST(CatenaryTest, SetterTest3) {
Catenary::Catenary cat;
cat.set_x1(2);
EXPECT_EQ(cat.get_x1(), 1);
EXPECT_EQ(cat.get_x2(), 2);
}

TEST(CatenaryTest, SetterTest4) {
Catenary::Catenary cat;
cat.set_parameter(2);
EXPECT_EQ(cat.get_parameter(), 2);
}

TEST(CatenaryTest, SetterTest5) {
Catenary::Catenary cat;
ASSERT_ANY_THROW(cat.set_parameter(0));
}


// ÇÍŔ×ĹÍČĹ ÔÓÍĘÖČČ
TEST(CatenaryTest, ValueTest1) {
Catenary::Catenary cat;
EXPECT_NEAR(cat.f(1), 1.54308, 0.00001);
}

TEST(CatenaryTest, ValueTest2) {
Catenary::Catenary cat(-1, 1, 2);
EXPECT_NEAR(cat.f(-2), 3.08616, 0.00001);
}


// ČÍŇĹĂĐŔË
TEST(CatenaryTest, IntegralTest1) {
Catenary::Catenary a(-1, 1, 1);
double res = a.arc_length();
EXPECT_NEAR(res, 2.35048, 0.00001);
}

TEST(CatenaryTest, IntegralTest2) {
Catenary::Catenary a(-2, 2, 1);
double res = a.arc_length();
EXPECT_NEAR(res, 7.25372, 0.00001);
}

TEST(CatenaryTest, IntegralTest3) {
Catenary::Catenary a(-3, 3, 0.5);
double res = a.arc_length();
EXPECT_NEAR(res, 201.723, 0.001);
}


// ĎËÎŮŔÄÜ
TEST(CatenaryTest, AreaTest1) {
Catenary::Catenary cat;
EXPECT_NEAR(cat.trapezoid_area(), 2.3504, 0.00001);
}

TEST(CatenaryTest, AreaTest2) {
Catenary::Catenary cat(-2, 1, 2);
EXPECT_NEAR(cat.trapezoid_area(), 6.78519, 0.00001);
}


// ŇĹŃŇ ÎŃŇĐČĚ
TEST(CatenaryTest, OstreamTest1) {
Catenary::Catenary cat(-1, 1, 1);
std::ostringstream o;
cat.print(o);
ASSERT_STREQ(o.str().c_str(), "a = 1  x1 = -1  x2 = 1\n");
}

TEST(CatenaryTest, OstreamTest2) {
Catenary::Catenary cat(-3.5, 2, 0.5);
std::ostringstream o;
cat.print(o);
ASSERT_STREQ(o.str().c_str(), "a = 0.5  x1 = -3.5  x2 = 2\n");
}

TEST(CatenaryTest, OstreamTest3) {
Catenary::Catenary cat(3, 1, -2);
std::ostringstream o;
cat.print(o);
ASSERT_STREQ(o.str().c_str(), "a = -2  x1 = 1  x2 = 3\n");
}
