// Copyright 2014 Fedosov Alexander

#include <float.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <set>
#include "Includes/lengthconverter.hpp"
const int TYPE_METER = 1;
const int TYPE_INCH = 2000;
const int TYPE_FOOT = 200;
const int TYPE_YARD = 20;
const int TYPE_MILE = 2;
Length::Length():type_(TYPE_METER), length_(0.0) {}
Length::Length(int type, double length):type_(type), length_(length) {
    length_ = checkLength(length);
    switch (type) {
        case TYPE_METER: {type_ = type;}
        case TYPE_MILE: {type_ = type;}
        case TYPE_YARD: {type_ = type;}
        case TYPE_FOOT: {type_ = type;}
        case TYPE_INCH: {type_ = type;}
    }
}
Length::~Length() {}
Length* Length::create(int type, double length) {
    length = checkLength(length);
switch (type) {
        case TYPE_METER: {return new Length(type, length);}
        case TYPE_MILE: {return new Length(type, length);}
        case TYPE_YARD: {return new Length(type, length);}
        case TYPE_FOOT: {return new Length(type, length);}
        case TYPE_INCH: {return new Length(type, length);}
        default: return NULL;
    }
}
int Length::getType() {return type_;}
double Length::getLength() {return length_;}
void Length::setLength(double length) {
    length_ = Length::checkLength(length);
}
void Length::setType(int type) {
    double length;
    length = this->getLength();
    double *lngth = &length;
switch(type) {
    case TYPE_METER: {this->convert(type, lngth); length_ = *lngth;
            type_ = type; return;}
    case TYPE_MILE: {this->convert(type, lngth); length_ = *lngth;
            type_ = type; return;}
    case TYPE_YARD: {this->convert(type, lngth); length_ = *lngth;
            type_ = type; return;}
    case TYPE_FOOT: {this->convert(type, lngth); length_ = *lngth;
            type_ = type; return;}
    case TYPE_INCH: {this->convert(type, lngth); length_ = *lngth;
            type_ = type; return;}
        default: {return;}
    }
}
double Length::checkLength(double length) {
if (length < 0.0000001) {
        length = 0.0;
    } else {
        if (DBL_MAX - length < 0.0000001) {
        length = DBL_MAX;
        } else {length = length;}
    }
return length;
}
Length* Length::convert(int type) {
    double length;
    length = this->getLength();
    double *lngth = &length;
    Length* converted;
    switch (type) {
        case TYPE_METER: {this->convert(type, lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case TYPE_MILE: {this->convert(type, lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case TYPE_YARD: {this->convert(type, lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case TYPE_FOOT: {this->convert(type, lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case TYPE_INCH: {this->convert(type, lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        default: {return NULL;}
    }
}
void Length::convert(int type, double* length) {
    int myType;
    double lngth = *length;
    myType = this->getType();
    if (type == TYPE_METER) {
        if (myType == TYPE_METER) {lngth = checkLength(lngth);
            *length = lngth; return;}
        if (myType == TYPE_MILE) {lngth*=1609.344;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_YARD) {lngth*=0.9144;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_FOOT) {lngth*=0.3048;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_INCH) {lngth*=0.0254;
            lngth = checkLength(lngth); *length = lngth; return;}
    }
if (type == TYPE_MILE) {
        if (myType == TYPE_METER) {lngth*=0.0006214;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_MILE) {lngth = checkLength(lngth);
            *length = lngth; return;}
        if (myType == TYPE_YARD) {lngth*=0.0005682;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_FOOT) {lngth*=0.0001894;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_INCH) {lngth*=0.000016;
            lngth = checkLength(lngth); *length = lngth; return;}
    }
if (type == TYPE_YARD) {
        if (myType == TYPE_METER) {lngth*=1.0936;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_MILE) {lngth*=1760.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_YARD) {lngth = checkLength(lngth);
            *length = lngth; return;}
        if (myType == TYPE_FOOT) {lngth*=0.3333333;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_INCH) {lngth*=0.0278;
            lngth = checkLength(lngth); *length = lngth; return;}
    }
if (type == TYPE_FOOT) {
        if (myType == TYPE_METER) {lngth*=3.2808;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_MILE) {lngth*=5280.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_YARD) {lngth*=3.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_FOOT) {lngth = checkLength(lngth);
            *length = lngth; return;}
        if (myType == TYPE_INCH) {lngth*=0.0833;
            lngth = checkLength(lngth); *length = lngth; return;}
    }
if (type == TYPE_INCH) {
        if (myType == TYPE_METER) {lngth*=39.3701;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_MILE) {lngth*=63360.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_YARD) {lngth*=36.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_FOOT) {lngth*=12.0;
            lngth = checkLength(lngth); *length = lngth; return;}
        if (myType == TYPE_INCH) {lngth = checkLength(lngth);
            *length = lngth; return;}
    }
}
