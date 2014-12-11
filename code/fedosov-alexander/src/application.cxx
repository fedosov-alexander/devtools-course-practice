
// Copyright 2014 Fedosov Alexander

#include <float.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "include/lengthconverter.hpp"
#include "include/application.hpp"

Application::Application() : message_("") {}

Application::~Application() {}

void Application::help(const char* appname) {
    message_ += std::string("This is a simple length converter app.\n\n")
        + "Please provide arguments in the following format:\n\n"
        + "  $ " + appname + "-from <measure> <value> -to <measure>\n\n"
        + "Where <measure> can be one of the following: "
        + "meters, inches, feet, yards, miles,"
        + "and <value> is floating-point number in format 0.0\n"
        + "Usage example: $ " + appname + "-from meters 10.0 -to yards\n";
}

std::string Application::operator()(int argc, const char** argv) {
    parseArgsAndConvert(argc, argv);
    return message_;
}

void Application::parseArgsAndConvert(int argc, const char** argv) {
    LengthConverter::Type convTo, convFrom;
    double value;
    int i;
    if (argc != 6) {
        help(argv[0]);
        return;
    }
    convTo = LengthConverter::TYPE_WRONG;
    convFrom = LengthConverter::TYPE_WRONG;
    for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-from")) {
        ++i;
        if (!strcmp(argv[i], "meters")) {
            convFrom = LengthConverter::TYPE_METER;
        } else if (!strcmp(argv[i], "inches")) {
            convFrom = LengthConverter::TYPE_INCH;
        } else if (!strcmp(argv[i], "feet")) {
            convFrom = LengthConverter::TYPE_FOOT;

        } else if (!strcmp(argv[i], "yards")) {
            convFrom = LengthConverter::TYPE_YARD;
        } else if (!strcmp(argv[i], "miles")) {
            convFrom = LengthConverter::TYPE_MILE;
        }
        ++i;
        value = atof(argv[i]);
        if ((value < 0.0000001)&&(argv[i][0] != '0')) {
        message_ = "";
        message_ += "Wrong input!\n";
        return;
        }
    } else if (!strcmp(argv[i], "-to")) {
        ++i;
        if (!strcmp(argv[i], "meters")) {
            convTo = LengthConverter::TYPE_METER;
        } else if (!strcmp(argv[i], "inches")) {
            convTo = LengthConverter::TYPE_INCH;
        } else if (!strcmp(argv[i], "feet")) {
            convTo = LengthConverter::TYPE_FOOT;

        } else if (!strcmp(argv[i], "yards")) {
            convTo = LengthConverter::TYPE_YARD;
        } else if (!strcmp(argv[i], "miles")) {
            convTo = LengthConverter::TYPE_MILE;
        }
    }
    }
    if (convTo == LengthConverter::TYPE_WRONG ||
        convFrom == LengthConverter::TYPE_WRONG) {
        message_ = "";
        message_ += "Wrong input!\n";
        return;
    }
    std::ostringstream stream;
    stream << "Conversion result is ";
    LengthConverter lengthConverter;
    stream << lengthConverter.convert(convFrom, value, convTo);
    message_ = stream.str();
}
