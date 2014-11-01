// Copyright 2014 Fedosov Alexander
#include <gtest/gtest.h>
#include <float.h>
#include <cstdlib>
#include "Includes/lengthconverter.hpp"

class lengthconverterTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}
};

TEST_F(lengthconverterTest, creatinon_test1) {
    Length* len = Length::create(15, 100000);
    EXPECT_EQ(NULL, len);
}

TEST_F(lengthconverterTest, creatinon_test2) {
    Length* len = Length::create(TYPE_METER, 100000);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(100000.0, len->getLength(), 0.000001);
}
TEST_F(lengthconverterTest, creatinon_test3) {
    Length* len = Length::create(TYPE_MILE, DBL_MAX+100);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(DBL_MAX, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, creatinon_test4) {
    Length* len = Length::create(TYPE_INCH, -DBL_MAX+100);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(0.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, creatinon_test5) {
    Length* len = Length::create(TYPE_YARD, -DBL_MAX+100);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(0.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, creatinon_test6) {
    Length* len = Length::create(TYPE_FOOT, -DBL_MAX+100);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(0.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test1) {
    Length* len = Length::create(TYPE_FOOT, -DBL_MAX+100);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(0.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test2) {
    Length* len = Length::create(TYPE_FOOT, 100.0);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(30.48, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test3) {
    Length* len = Length::create(TYPE_FOOT, 100.0);
    len->setType(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(100.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test4) {
    Length* len = Length::create(TYPE_FOOT, 100.0);
    len->setType(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(1200.0, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test5) {
    Length* len = Length::create(TYPE_FOOT, 100.0);
    len->setType(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(0.019, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test6) {
    Length* len = Length::create(TYPE_FOOT, 100.0);
    len->setType(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(33.3333333, len->getLength(), 0.01);
}

TEST_F(lengthconverterTest, conversion_test7) {
    Length* len = Length::create(TYPE_METER, 100.0);
    len->setType(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(328.08, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test8) {
    Length* len = Length::create(TYPE_METER, 100.0);
    len->setType(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(0.062, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test9) {
    Length* len = Length::create(TYPE_METER, 100.0);
    len->setType(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(3937.01, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test10) {
    Length* len = Length::create(TYPE_METER, 100.0);
    len->setType(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(109.36, len->getLength(), 0.000001);
}
TEST_F(lengthconverterTest, conversion_test11) {
    Length* len = Length::create(TYPE_METER, 100.0);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(100.0, len->getLength(), 0.000001);
}
TEST_F(lengthconverterTest, conversion_test12) {
    Length* len = Length::create(TYPE_MILE, 100.0);
    len->setType(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(528000.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test13) {
    Length* len = Length::create(TYPE_MILE, 100.0);
    len->setType(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(100.0, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test14) {
    Length* len = Length::create(TYPE_MILE, 100.0);
    len->setType(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(6336000.0, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test15) {
    Length* len = Length::create(TYPE_MILE, 100.0);
    len->setType(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(176000.0, len->getLength(), 0.000001);
}
TEST_F(lengthconverterTest, conversion_test16) {
    Length* len = Length::create(TYPE_MILE, 100.0);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(160934.4, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test17) {
    Length* len = Length::create(TYPE_YARD, 100.0);
    len->setType(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(300.0, len->getLength(), 0.000001);
}

TEST_F(lengthconverterTest, conversion_test18) {
    Length* len = Length::create(TYPE_YARD, 100.0);
    len->setType(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(0.057, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test19) {
    Length* len = Length::create(TYPE_YARD, 100.0);
    len->setType(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(3600.0, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test20) {
    Length* len = Length::create(TYPE_YARD, 100.0);
    len->setType(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(100.0, len->getLength(), 0.000001);
}
TEST_F(lengthconverterTest, conversion_test21) {
    Length* len = Length::create(TYPE_YARD, 100.0);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(91.44, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test22) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    len->setType(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len->getType());
    EXPECT_NEAR(8.33, len->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test23) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    len->setType(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len->getType());
    EXPECT_NEAR(0.0016, len->getLength(), 0.00001);
}

TEST_F(lengthconverterTest, conversion_test24) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    len->setType(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len->getType());
    EXPECT_NEAR(100.0, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test25) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    len->setType(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len->getType());
    EXPECT_NEAR(2.78, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test26) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    len->setType(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len->getType());
    EXPECT_NEAR(2.54, len->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test27) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    Length* len1;
    len1 = len->convert(TYPE_FOOT);
    EXPECT_EQ(TYPE_FOOT, len1->getType());
    EXPECT_NEAR(8.33, len1->getLength(), 0.001);
}

TEST_F(lengthconverterTest, conversion_test28) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    Length* len1;
    len1 = len->convert(TYPE_MILE);
    EXPECT_EQ(TYPE_MILE, len1->getType());
    EXPECT_NEAR(0.0016, len1->getLength(), 0.00001);
}

TEST_F(lengthconverterTest, conversion_test29) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    Length* len1;
    len1 = len->convert(TYPE_INCH);
    EXPECT_EQ(TYPE_INCH, len1->getType());
    EXPECT_NEAR(100.0, len1->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test30) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    Length* len1;
    len1 = len->convert(TYPE_YARD);
    EXPECT_EQ(TYPE_YARD, len1->getType());
    EXPECT_NEAR(2.78, len1->getLength(), 0.001);
}
TEST_F(lengthconverterTest, conversion_test31) {
    Length* len = Length::create(TYPE_INCH, 100.0);
    Length* len1;
    len1 = len->convert(TYPE_METER);
    EXPECT_EQ(TYPE_METER, len1->getType());
    EXPECT_NEAR(2.54, len1->getLength(), 0.001);
}

TEST_F(lengthconverterTest, defaultconsttruction_test) {
    Length len = Length();
    EXPECT_EQ(TYPE_METER, len.getType());
    EXPECT_NEAR(0.0, len.getLength(), 0.001);
}

TEST_F(lengthconverterTest, destruction_test) {
    Length len = Length();
    EXPECT_EQ(TYPE_METER, len.getType());
    EXPECT_NEAR(0.0, len.getLength(), 0.001);
    len.~Length();
}
TEST_F(lengthconverterTest, setlength_test) {
    Length len = Length();
    EXPECT_EQ(TYPE_METER, len.getType());
    EXPECT_NEAR(0.0, len.getLength(), 0.001);
    len.setLength(1000.0);
     EXPECT_NEAR(1000.0, len.getLength(), 0.001);
}


