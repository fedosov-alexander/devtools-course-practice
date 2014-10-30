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
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(233.12),
        static_cast<float>(-100.0), static_cast<float>(4444444.0));
    EXPECT_EQ(col->get1stValue(), static_cast<float>(233.0));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(255.0));
}

TEST_F(ColorspaceconverterTest, creation_test2) {
    Color* col;
    col = new Color(15, static_cast<float>(233.12),
        static_cast<float>(-100.0), static_cast<float>(4444444.0));
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_EQ(col->get1stValue(), static_cast<float>(233.0));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(255.0));
}
TEST_F(ColorspaceconverterTest, creation_test3) {
    Color* col;
    col = new Color();
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_EQ(col->get1stValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(0.0));
}
TEST_F(ColorspaceconverterTest, creation_test4) {
    Color* col;
    col = new Color(TYPE_HSV, static_cast<float>(0.233),
        static_cast<float>(-1.0), static_cast<float>(0.9999));
    EXPECT_EQ(col->get1stValue(), static_cast<float>(0.233));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(0.9999));
}

TEST_F(ColorspaceconverterTest, setting_values_test1) {
    Color* col;
    col = new Color(TYPE_RGB, 0, 0, 0);
    col->set1stValue(FLT_MAX);
    EXPECT_EQ(col->getType(), TYPE_RGB);
    EXPECT_EQ(col->get1stValue(), static_cast<float>(255.0));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(0.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(0.0));
}

TEST_F(ColorspaceconverterTest, conversion_test1) {
    Color* conv;
    Color* col;
    col = new Color(TYPE_RGB, 233, 100, 44);
    EXPECT_EQ(col->get1stValue(), static_cast<float>(233.0));
    EXPECT_EQ(col->get2ndValue(), static_cast<float>(100.0));
    EXPECT_EQ(col->get3rdValue(), static_cast<float>(44.0));
    conv = col->convert(TYPE_HSV);
    EXPECT_EQ(conv->getType(), TYPE_HSV);
    EXPECT_NEAR(conv->get1stValue(), static_cast<float>(0.05),
        static_cast<float>(0.01));
    EXPECT_NEAR(conv->get2ndValue(), static_cast<float>(0.811),
        static_cast<float>(0.01));
    EXPECT_NEAR(conv->get3rdValue(), static_cast<float>(0.7411),
        static_cast<float>(0.01));
}

TEST_F(ColorspaceconverterTest, type_setting_test1) {
    Color* col;
    col = new Color(TYPE_RGB, static_cast<float>(233.0),
        static_cast<float>(100.0), static_cast<float>(44.0));
    col->setType(TYPE_HSV);
    EXPECT_EQ(col->getType(), TYPE_HSV);
    EXPECT_NEAR(col->get1stValue(), static_cast<float>(0.05),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->get2ndValue(), static_cast<float>(0.811),
        static_cast<float>(0.01));
    EXPECT_NEAR(col->get3rdValue(), static_cast<float>(0.7411),
        static_cast<float>(0.01));
}

