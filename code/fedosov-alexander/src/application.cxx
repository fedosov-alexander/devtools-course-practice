
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
    double value = 0.0;
    int i;
    char* valEnd;
    if (argc != 6) {
        help(argv[0]);
        return;
    }
    convTo = LengthConverter::TYPE_WRONG;
    convFrom = LengthConverter::TYPE_WRONG;
    for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-from")) {
        ++i;
        convFrom = checkType(argv[i]);
        ++i;
        value = strtod(argv[i], &valEnd);
        if (valEnd[0]) {
        message_ = "";
        message_ += "Wrong input!\n";
        return;
        }
    } else if (!strcmp(argv[i], "-to")) {
        ++i;
         convTo = checkType(argv[i]);
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

LengthConverter::Type Application::checkType(const char* type) {
    LengthConverter::Type typeToReturn;
    if (!strcmp(type, "meters")) {
            typeToReturn = LengthConverter::TYPE_METER;
        } else if (!strcmp(type, "inches")) {
            typeToReturn = LengthConverter::TYPE_INCH;
        } else if (!strcmp(type, "feet")) {
            typeToReturn = LengthConverter::TYPE_FOOT;

        } else if (!strcmp(type, "yards")) {
            typeToReturn = LengthConverter::TYPE_YARD;
        } else if (!strcmp(type, "miles")) {
            typeToReturn = LengthConverter::TYPE_MILE;
        } else {
            typeToReturn =  LengthConverter::TYPE_WRONG;
        }
    return typeToReturn;
}
