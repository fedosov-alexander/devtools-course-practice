// Copyright 2014 Fedosov Alexander

#include <set>
#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
extern const int TYPE_METER;
extern const int TYPE_MILE;
extern const int TYPE_YARD;
extern const int TYPE_FOOT;
extern const int TYPE_INCH;
class Length {
 public:
Length();
~Length();
static Length* create(int type, double length);
Length* convert(int type);
void setType(int type);
int getType();
double getLength();
void setLength(double length);
 private:
    int type_;
    double length_;
    Length(int type, double length);
    void convert(int type, double* length);
    static double checkLength(double length);
};
#endif
