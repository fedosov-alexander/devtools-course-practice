// Copyright 2014 Fedosov Alexander
#include <gtest/gtest.h>

#include <float.h>
#include <limits.h>
#include <string>


#include "Includes/colorspaceconverter.hpp"

class ColorspaceconverterTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    Color color;
};

TEST_F(ColorspaceconverterTest, creation_test1) {
    Color* col1;
    col1 = new Color(TYPE_RGB, static_cast<float>(233.12),
        static_cast<float>(-FLT_MAX), static_cast<float>(FLT_MAX));
    EXPECT_EQ(col1->getValue(1), static_cast<float>(233.0));
    EXPECT_EQ(col1->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col1->getValue(3), static_cast<float>(255.0));
}

TEST_F(ColorspaceconverterTest, creation_test2) {
    Color* col;
    col = new Color(15, static_cast<float>(233.12),
        static_cast<float>(-100.0), static_cast<float>(4444444.0));
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_EQ(col->getValue(1), static_cast<float>(233.0));
    EXPECT_EQ(col->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col->getValue(3), static_cast<float>(255.0));
}
TEST_F(ColorspaceconverterTest, creation_test3) {
    Color* col;
    col = new Color();
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.0));
    EXPECT_EQ(col->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col->getValue(3), static_cast<float>(0.0));
}
TEST_F(ColorspaceconverterTest, creation_test4) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(0.233),
        static_cast<float>(-1.0), static_cast<float>(0.9999));
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.233));
    EXPECT_EQ(col->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col->getValue(3), static_cast<float>(0.9999));
}
TEST_F(ColorspaceconverterTest, creation_test5) {
    Color* col1;
    col1 = new Color(TYPE_HSV, static_cast<float>(0.33),
        static_cast<float>(-FLT_MAX), static_cast<float>(FLT_MAX));
    EXPECT_EQ(col1->getValue(1), static_cast<float>(0.33));
    EXPECT_EQ(col1->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col1->getValue(3), static_cast<float>(1.0));
}
TEST_F(ColorspaceconverterTest, creation_test6) {
    Color* col1;
    Color* col2;
    Color* col3;
    col1 = new Color(TYPE_XYZ, FLT_MAX,
        static_cast<float>(-FLT_MAX), static_cast<float>(FLT_MAX));
    EXPECT_EQ(col1->getValue(1), static_cast<float>(95.047));
    EXPECT_EQ(col1->getValue(2), static_cast<float>(0.0));
    EXPECT_EQ(col1->getValue(3), static_cast<float>(108.883));
     col2 = new Color(TYPE_XYZ, -FLT_MAX, FLT_MAX,
        static_cast<float>(33.0));
    EXPECT_EQ(col2->getValue(1), static_cast<float>(0.0));
    EXPECT_EQ(col2->getValue(2), static_cast<float>(100.0));
    EXPECT_EQ(col2->getValue(3), static_cast<float>(33.0));
    col3 = new Color(TYPE_XYZ, static_cast<float>(33.0),
        static_cast<float>(33.0), -FLT_MAX);
    EXPECT_EQ(col3->getValue(1), static_cast<float>(33.0));
    EXPECT_EQ(col3->getValue(2), static_cast<float>(33.0));
    EXPECT_EQ(col3->getValue(3), static_cast<float>(0.0));
}

TEST_F(ColorspaceconverterTest, creation_test7) {
    Color* col1;
    Color* col2;
    Color* col3;
    col1 = new Color(TYPE_CIE_LAB, FLT_MAX, -FLT_MAX,
        static_cast<float>(33.0));
    EXPECT_EQ(col1->getValue(1), static_cast<float>(100.0));
    EXPECT_EQ(col1->getValue(2), static_cast<float>(-86.185));
    EXPECT_EQ(col1->getValue(3), static_cast<float>(33.0));
    col2 = new Color(TYPE_CIE_LAB, -FLT_MAX, FLT_MAX, FLT_MAX);
    EXPECT_EQ(col2->getValue(1), static_cast<float>(0.0));
    EXPECT_EQ(col2->getValue(2), static_cast<float>(98.254));
    EXPECT_EQ(col2->getValue(3), static_cast<float>(94.482));
    col3 = new Color(TYPE_CIE_LAB, static_cast<float>(33.0),
        static_cast<float>(33.0), -FLT_MAX);
    EXPECT_EQ(col3->getValue(1), static_cast<float>(33.0));
    EXPECT_EQ(col3->getValue(2), static_cast<float>(33.0));
    EXPECT_EQ(col3->getValue(3), static_cast<float>(-107.863));
}

TEST_F(ColorspaceconverterTest, setting_values_test1) {
    Color* col;
    col = new Color(TYPE_RGB, 0, 0, 0);
    col->setValue(1, FLT_MAX);
    EXPECT_EQ(col->getValue(1), static_cast<float>(255.0));
    col->setValue(1, FLT_MIN);
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.0));
    col->setValue(1, static_cast<float>(33.0));
    EXPECT_EQ(col->getValue(1), static_cast<float>(33.0));
}
TEST_F(ColorspaceconverterTest, setting_values_test2) {
    Color* col;
    col = new Color(TYPE_CIE_LAB, 0, 0, 0);
    col->setValue(1, FLT_MAX);
    EXPECT_EQ(col->getValue(1), static_cast<float>(100.0));
    col->setValue(1, -FLT_MAX);
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.0));
    col->setValue(1, static_cast<float>(33.0));
    EXPECT_EQ(col->getValue(1), static_cast<float>(33.0));
    col->setValue(2, FLT_MAX);
    EXPECT_EQ(col->getValue(2), static_cast<float>(98.254));
    col->setValue(2, -FLT_MAX);
    EXPECT_EQ(col->getValue(2), static_cast<float>(-86.185));
    col->setValue(2, static_cast<float>(33.0));
    EXPECT_EQ(col->getValue(2), static_cast<float>(33.0));
    col->setValue(3, FLT_MAX);
    EXPECT_EQ(col->getValue(3), static_cast<float>(94.482));
    col->setValue(3, -FLT_MAX);
    EXPECT_EQ(col->getValue(3), static_cast<float>(-107.863));
    col->setValue(3, static_cast<float>(33.0));
    EXPECT_EQ(col->getValue(3), static_cast<float>(33.0));
}
TEST_F(ColorspaceconverterTest, setting_values_test3) {
    Color* col;
    col = new Color(TYPE_HSV, 0, 0, 0);
    col->setValue(1, FLT_MAX);
    EXPECT_EQ(col->getValue(1), static_cast<float>(1.0));
    col->setValue(1, -FLT_MAX);
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.0));
    col->setValue(1, static_cast<float>(0.33));
    EXPECT_EQ(col->getValue(1), static_cast<float>(0.33));
}

TEST_F(ColorspaceconverterTest, conversion_test1) {
    Color* conv;
    Color* col;
    col = new Color(TYPE_RGB, 233, 100, 44);
    EXPECT_EQ(col->getValue(1), static_cast<float>(233.0));
    EXPECT_EQ(col->getValue(2), static_cast<float>(100.0));
    EXPECT_EQ(col->getValue(3), static_cast<float>(44.0));
    conv = col->convert(TYPE_HSV);
    EXPECT_EQ(conv->getType(), TYPE_HSV);
    EXPECT_NEAR(conv->getValue(1), static_cast<float>(0.05),
        static_cast<float>(0.01));
    EXPECT_NEAR(conv->getValue(2), static_cast<float>(0.811),
        static_cast<float>(0.01));
    EXPECT_NEAR(conv->getValue(3), static_cast<float>(0.7411),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, type_setting_test1) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(233.0),
        static_cast<float>(100.0), static_cast<float>(44.0));
    col->setType(TYPE_HSV);
    EXPECT_EQ(col->getType(), TYPE_HSV);
    EXPECT_NEAR(col->getValue(1), static_cast<float>(0.05),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(2), static_cast<float>(0.811),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(3), static_cast<float>(0.7411),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, conversion_test2) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0));
    col->convert(TYPE_HSV);
}

TEST_F(ColorspaceconverterTest, conversion_test3) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test4) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(0.0),
        static_cast<float>(255.0), static_cast<float>(0.0));
    col->convert(TYPE_HSV);
}

TEST_F(ColorspaceconverterTest, conversion_test5) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(255.0));
    col->convert(TYPE_HSV);
}

TEST_F(ColorspaceconverterTest, conversion_test6) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(255.0),
        static_cast<float>(255.0), static_cast<float>(255.0));
    col->convert(TYPE_HSV);
}

TEST_F(ColorspaceconverterTest, conversion_test7) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(255.0),
        static_cast<float>(0.0), static_cast<float>(250.0));
    col->convert(TYPE_HSV);
}


TEST_F(ColorspaceconverterTest, conversion_test8) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(250.0),
        static_cast<float>(0.0), static_cast<float>(255.0));
    col->convert(TYPE_HSV);
}

TEST_F(ColorspaceconverterTest, conversion_test9) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(1.0),
        static_cast<float>(0.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test10) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(1.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test11) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(1.0/6.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test12) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(2.0/6.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test13) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(3.0/6.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test14) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(4.0/6.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test15) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(5.0/6.0),
        static_cast<float>(1.0), static_cast<float>(1.0));
    col->convert(TYPE_RGB);
}

TEST_F(ColorspaceconverterTest, conversion_test16) {
    Color* col;
    col = new Color(TYPE_CIE_LAB, static_cast<float>(100.0),
        static_cast<float>(98.0), static_cast<float>(-107.0));
    col->setType(TYPE_RGB);
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_NEAR(col->getValue(1), static_cast<float>(255.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(2), static_cast<float>(181.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(3), static_cast<float>(255.0),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, conversion_test17) {
    Color* col;
    col = new Color(TYPE_CIE_LAB, static_cast<float>(0.0),
        static_cast<float>(-86.0), static_cast<float>(94.0));
    col->convert(TYPE_RGB);
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_NEAR(col->getValue(1), static_cast<float>(0.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(2), static_cast<float>(48.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(3), static_cast<float>(138.0),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, conversion_test18) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(255.0),
        static_cast<float>(181.0), static_cast<float>(255.0));
    col->convert(TYPE_CIE_LAB);
    EXPECT_EQ(col->getType(), TYPE_CIE_LAB);
    EXPECT_NEAR(col->getValue(1), static_cast<float>(100.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(2), static_cast<float>(98.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(3), static_cast<float>(-107.0),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, conversion_test19) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(0.0),
        static_cast<float>(48.0), static_cast<float>(138.0));
    col->convert(TYPE_CIE_LAB);
    EXPECT_EQ(col->getType(), TYPE_CIE_LAB);
    EXPECT_NEAR(col->getValue(1), static_cast<float>(0.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(2), static_cast<float>(-86.0),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->getValue(3), static_cast<float>(94.0),
        static_cast<float>(0.01));
}
