// Copyright 2014 Fedosov Alexander
#include "Includes/colorspaceconverter.hpp"
#include <math.h>
#include <cstdlib>
const int TYPE_RGB = 1;
const int TYPE_CIE_LAB = 2;
const int TYPE_HSV = 3;
const int TYPE_XYZ = 4;
Color::Color():type_(TYPE_RGB), val1_(static_cast<float>(0.0)),
val2_(static_cast<float>(0.0)), val3_(static_cast<float>(0.0)) {}
Color::~Color() {}
Color::Color(int type, float val1, float val2, float val3):type_(type),
val1_(val1), val2_(val2), val3_(val3) {
switch (type) {
case TYPE_RGB: {
    type_ = type;
    if (val1 > static_cast<float>(0.0)) {
        if (val1 > static_cast<float>(255.0)) {
            val1_ = static_cast<float>(255.0);
        } else {
        val1_ = static_cast<float>(floor(val1));}
    } else {val1_ = static_cast<float>(0.0);}

    if (val2 > static_cast<float>(0.0)) {
        if (val2 > static_cast<float>(255.0)) {
            val2_ = static_cast<float>(255.0);
        } else {
        val2_ = static_cast<float>(floor(val2));}
    } else {val2_ = static_cast<float>(0.0);}

    if (val3 > static_cast<float>(0.0)) {
        if (val3 > static_cast<float>(255.0)) {
            val3_ = static_cast<float>(255.0);
        } else {
        val3_ = static_cast<float>(floor(val3));}
    } else {val3_ = static_cast<float>(0.0);}
    break;}
case TYPE_HSV: {
    type_ = type;
    if (val1 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val1 > static_cast<float>(0.0000001))
            {val1_ = val1;} else {
            val1_ = static_cast<float>(1.0);
        }
    } else {val1_ = static_cast<float>(0.0);}
    if (val2 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val2 > static_cast<float>(0.0000001))
            {val2_ = val2;} else {
            val2_ = static_cast<float>(1.0);
        }
    } else {val2_ = static_cast<float>(0.0);}

     if (val3 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val3 > static_cast<float>(0.0000001))
            {val3_ = val3;} else {
            val3_ = static_cast<float>(1.0);
        }
    } else {val3_ = static_cast<float>(0.0);}
    break;}
case TYPE_CIE_LAB: {
    type_ = type;
    if (val1 > static_cast<float>(0.0)) {
        if (val1 > static_cast<float>(100.0))
            {val1_ = static_cast<float>(100.0);} else {
        val1_ = val1;}
    } else {val1_ = static_cast<float>(0.0);}
    if (val2 > static_cast<float>(-86.185)) {
        if (val2 > 98.254) {val2_ = static_cast<float>(98.254);} else {
        val2_ = val2;}
    } else {val2_ = static_cast<float>(-86.185);}
    if (val3 > static_cast<float>(-107.863)) {
        if (val3 > static_cast<float>(94.482)) {
            val3_ = static_cast<float>(94.482);} else {
        val3_ = val3;}
    } else {val3_ = static_cast<float>(-107.863);}
    break;}
    case TYPE_XYZ: {
    type_ = type;
    if (val1 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val1 > static_cast<float>(0.0000001))
            {val1_ = val1;} else {
            val1_ = static_cast<float>(1.0);
        }
    } else {val1_ = static_cast<float>(0.0);}
    if (val2 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val2 > static_cast<float>(0.0000001))
            {val2_ = val2;} else {
            val2_ = static_cast<float>(1.0);
        }
    } else {val2_ = static_cast<float>(0.0);}

     if (val3 > static_cast<float>(0.0)) {
        if (static_cast<float>(1.0)-val3 > static_cast<float>(0.0000001))
            {val3_ = val3;} else {
            val3_ = static_cast<float>(1.0);
        }
    } else {val3_ = static_cast<float>(0.0);}
        break;
    }
    default: {type_ = TYPE_RGB;
    if (val1 > static_cast<float>(0.0)) {
        if (val1 > static_cast<float>(255.0)) {
            val1_ = static_cast<float>(255.0);
        } else {
        val1_ = static_cast<float>(floor(val1));}
    } else {val1_ = static_cast<float>(0.0);}

    if (val2 > static_cast<float>(0.0)) {
        if (val2 > static_cast<float>(255.0)) {
            val2_ = static_cast<float>(255.0);
        } else {
        val2_ = static_cast<float>(floor(val2));}
    } else {val2_ = static_cast<float>(0.0);}

    if (val3 > static_cast<float>(0.0)) {
        if (val3 > static_cast<float>(255.0)) {
            val3_ = static_cast<float>(255.0);
        } else {
        val3_ = static_cast<float>(floor(val3));}
    } else {val3_ = static_cast<float>(0.0);}
    }
}
}

void Color::setType(int type) {
switch (type) {
case TYPE_RGB: {
    Color* tmp;
    Color* pseudo;
    pseudo = new Color(this->getType(), this->get1stValue(),
        this->get2ndValue(), this->get3rdValue());
    tmp = pseudo->convert(TYPE_RGB);
    this->type_ = type;
    this->set1stValue(tmp->get1stValue());
    this->set2ndValue(tmp->get2ndValue());
    this->set3rdValue(tmp->get3rdValue());
    return;
}
case TYPE_HSV: {
    Color* tmp;
    Color* pseudo;
    pseudo = new Color(this->getType(), this->get1stValue(),
        this->get2ndValue(), this->get3rdValue());
    tmp = pseudo->convert(TYPE_HSV);
    this->type_ = type;
    this->set1stValue(tmp->get1stValue());
    this->set2ndValue(tmp->get2ndValue());
    this->set3rdValue(tmp->get3rdValue());
    return;
}
case TYPE_CIE_LAB: {
    Color* tmp;
    Color* pseudo;
    pseudo = new Color(this->getType(), this->get1stValue(),
        this->get2ndValue(), this->get3rdValue());
    tmp = pseudo->convert(TYPE_CIE_LAB);
    this->type_ = type;
    this->set1stValue(tmp->get1stValue());
    this->set2ndValue(tmp->get2ndValue());
    this->set3rdValue(tmp->get3rdValue());
    return;
}
default: {return;}
}
}

int Color::getType() {return type_;}

void Color::set1stValue(float val1) {
int type;
type = this->getType();
switch (type) {
case TYPE_RGB: {
    if (val1 > static_cast<float>(0.0)) {
        if (255.0-val1 > 0.0) {
            val1_ = static_cast<float>(floor(val1));
        } else {val1_ = static_cast<float>(255.0);}
    } else { val1_ = static_cast<float>(0.0);}
    return;}
case TYPE_HSV: {
    if (val1 > static_cast<float>(0.0)) {
        if (1.0-val1 > 0.0000001) {val1_ = val1;} else {
            val1_ = static_cast<float>(1.0);
        }
    } else {val1_ = static_cast<float>(0.0);}
    return;}
case TYPE_CIE_LAB: {
if (val1 > static_cast<float>(0.0)) {
        if (val1 > 100.0) {val1_ = static_cast<float>(100.0);} else {
        val1_ = val1;}
    } else {val1_ = static_cast<float>(0.0);}
    return;}
default: return;
}
}

float Color::get1stValue() {return val1_;}

void Color::set2ndValue(float val2) {int type;
type = this->getType();
switch (type) {
case TYPE_RGB: {
    if (val2 > static_cast<float>(0.0)) {
        if (255.0-val2 > 0.0) {
            val2_ = static_cast<float>(floor(val2));
        } else {val2_ = static_cast<float>(255.0);}
    } else { val2_ = static_cast<float>(0.0);}
    return;}
case TYPE_HSV: {
if (val2 > static_cast<float>(0.0)) {
        if (1.0-val2 > 0.0000001) {val2_ = val2;} else {
            val2_ = static_cast<float>(1.0);
        }
    } else {val2_ = static_cast<float>(0.0);}
    return;}
case TYPE_CIE_LAB: {
    if (val2 > static_cast<float>(-86.185)) {
        if (val2 > 98.254) {val2_ = static_cast<float>(98.254);} else {
        val2_ = val2;}
    } else {val2_ = static_cast<float>(-86.185);}
    return;}
default: return;
}
}

float Color::get2ndValue() {return val2_;}

void Color::set3rdValue(float val3) {
int type;
type = this->getType();
switch (type) {
case TYPE_RGB: {
    if (val3 > static_cast<float>(0.0)) {
        if (255.0-val3 > 0.0) {
            val3_ = static_cast<float>(floor(val3));
        } else {val3_ = static_cast<float>(255.0);}
    } else { val3_ = static_cast<float>(0.0);}
    return;}
case TYPE_HSV: {
if (val3 > static_cast<float>(0.0)) {
        if (1.0-val3 > 0.0000001) {val3_ = val3;} else {
            val3_ = static_cast<float>(1.0);
        }
    } else {val3_ = static_cast<float>(0.0);}
    return;}
case TYPE_CIE_LAB: {
    if (val3 > static_cast<float>(-107.863)) {
        if (val3 > static_cast<float>(94.482)) {
            val3_ = static_cast<float>(94.482);} else {
        val3_ = val3;}
    } else {val3_ = static_cast<float>(-107.863);}
    return;}
default: return;}
}

float Color::get3rdValue() {return val3_;}

Color* Color::convert(int type) {
Color* converted;
switch (type) {
case TYPE_RGB: {converted = convertToRGB(); return converted;}
case TYPE_HSV: {converted = convertToHSV(); return converted;}
case TYPE_CIE_LAB: {converted = convertToCIELAB(); return converted;}
default: return NULL;
}
}

Color* Color::convertToRGB() {
Color* converted;
int type;
type = this->getType();
switch (type) {
case TYPE_RGB: {
converted = new Color(TYPE_RGB, this->get1stValue(),
this->get1stValue(), this->get1stValue());
return converted;
}
case TYPE_HSV: {
float R, G, B;
float H, S, V, I;
float var1, var2, var3;
H = this->get1stValue();
S = this->get2ndValue();
V = this->get3rdValue();
if (fabs(S) < 0.0000001) {R = G = B = V * 255;
converted = new Color(TYPE_RGB, R, G, B);
return converted;} else {
H*=6;
if (fabs(H-static_cast<float>(6.0)) < 0.0000001) {
H = static_cast<float>(0.0);}
I = static_cast<float>(floor(H));
var1 = V*(1-S);
var2 = V*(1-S*(H-I));
var3 = V*(1-S*(1-(H-I)));
if (I < 0.0000001 ) {R = V; G = var3; B = var1;}
if (fabs(I-1.0) < 0.0000001) { R = var2; G = V; B = var1;}
if (fabs(I-2.0) < 0.0000001) { R = var1; G = V; B = var3;}
if (fabs(I-3.0) < 0.0000001) { R = var1; G = var2; B = V;}
if (fabs(I-4.0) < 0.0000001) { R = var3; G = var1; B = V;} else {
    R = V; G = var1 ; B = var2;}
    R*=255;
    G*=255;
    B*=255;
    converted = new Color(TYPE_RGB, R, G, B);
    return converted;
}
}
case TYPE_CIE_LAB: {
    Color* tmp;
    tmp = this->convertToXYZ();
    converted = tmp->convertToRGB();
    return converted;
}
default: return NULL;
}
return NULL;
}

Color* Color::convertToHSV() {
    Color* converted;
    int type;
    type = this->getType();
    switch (type) {
        case TYPE_RGB: {
            float red, green, blue, maxValue, minValue, delta;
            float H, S, V;
            red = this->get1stValue()/255;
            green = this->get2ndValue()/255;
            blue = this->get3rdValue()/255;
            minValue = fminf(red, fminf(green, blue));
            maxValue = fmaxf(red, fmaxf(green, blue));
            delta = maxValue-minValue;
            V = delta;
            if (delta < static_cast<float>(0.0000001)) {
                S = static_cast<float>(0.0);
                H = static_cast<float>(0.0);
               converted = new Color(TYPE_HSV, H, S, V);
               return converted;
            } else {
                S = delta/maxValue;
                float deltaR, deltaG, deltaB;
                deltaR = (static_cast<float>((maxValue-red)/6.0)+
                    static_cast<float>(maxValue/2.0))/delta;
                deltaG = (static_cast<float>((maxValue-green)/6.0)+
                    static_cast<float>(maxValue/2.0))/delta;
                deltaB = (static_cast<float>((maxValue-blue)/6.0)+
static_cast<float>(maxValue/2.0))/delta;
if (fabs(maxValue-red) < 0.0000001) {
H = deltaB-deltaG;
}
if (fabs(maxValue-green) < 0.0000001) {
H = static_cast<float>(1/3.0)+deltaR-deltaB;}
if (fabs(maxValue-blue) < 0.0000001) {
H = static_cast<float>(2/3.0)+deltaG-deltaR;}
if (H < static_cast<float>(0.0)) {
H+=static_cast<float>(1.0);}
if (H > static_cast<float>(1.0)) {
H-=static_cast<float>(1.0);
}
converted = new Color(TYPE_HSV, H, S, V);
}
return converted;
}
case TYPE_HSV: {
converted = new Color(TYPE_HSV, Color::get1stValue(),
Color::get1stValue(), Color::get1stValue());
return converted;
}
case TYPE_CIE_LAB: {
Color* xyz;
Color* rgb;
xyz = this->convertToXYZ();
rgb = xyz->convertToRGB();
converted = rgb->convertToHSV();
return converted;
}
default: return NULL;
}
return NULL;
}

Color* Color::convertToXYZ() {
Color* converted;
int type;
type = this->getType();
switch (type) {
case TYPE_RGB: {
float R, G, B;
float X, Y, Z;
R = this->get1stValue();
G = this->get2ndValue();
B = this->get3rdValue();
R/=255; G/=255; B/=255;
if ((R-0.04045) > 0) { R = static_cast<float>
(pow((R+0.055)/1.055, 2.4));} else {
R/=static_cast<float>(12.92);
}
if ((G-0.04045) > 0) { G = static_cast<float>
(pow((R+0.055)/1.055, 2.4));} else {
G/=static_cast<float>(12.92);
}
if ((B-0.04045) > 0) { B =static_cast<float>
(pow((R+0.055)/1.055, 2.4));} else {
B/=static_cast<float>(12.92);
}
R*=100; G*=100; B*=100;
X = static_cast<float>(R*0.4124+G*0.3576+B*0.1805);
Y = static_cast<float>(R*0.2126+G*0.7152+B*0.0722);
Z = static_cast<float>(R*0.0193+G*0.1192+B*0.9505);
converted = new Color(TYPE_XYZ, X, Y, Z);
return converted;
}
case TYPE_CIE_LAB: {
float L, A, B;
L = this->get1stValue();
A = this->get2ndValue();
B = this->get3rdValue();
float X, Y, Z;
Y = (L+16)/116;
X = A/500+Y;
Z = Y-B/200;
if (pow(Y, 3.0)-0.008856 > 0.0000001) {Y = static_cast<float>(pow(Y, 3.0));
} else {
Y = static_cast<float>((Y-16.0/116.0)/7.787);}
if (pow(X, 3.0)-0.008856 > 0.0000001)
    {X = static_cast<float>(pow(X, 3.0));
    } else {
        X = static_cast<float>((X-16.0/116.0)/7.787);}
        if (pow(Z, 3.0)-0.008856 > 0.0000001) {
            Z = static_cast<float>(pow(Z, 3.0));
        } else {
            Z = static_cast<float>((Z-16.0/116.0)/7.787);
        }

        X*=static_cast<float>(95.047);
        Y*=static_cast<float>(100.0);
        Z*= static_cast<float>(108.883);
        converted = new Color(TYPE_XYZ, X, Y, Z);
        return converted;
    }
    default: return NULL;
}
return converted;
}

Color* Color::convertToCIELAB() {
Color* converted;
int type;
type = this->getType();
switch (type) {
    case TYPE_RGB: {
        Color* tmp;
        tmp = this->convertToXYZ();
        converted = tmp->convertToCIELAB();
        return converted;
    }
    case TYPE_HSV: {
        Color* tmp;
        Color* tmprgb;
        tmprgb = this->convertToRGB();
        tmp = tmprgb->convertToXYZ();
        converted = tmp->convertToCIELAB();
        return converted;
    }
    case TYPE_CIE_LAB: {
        converted = new Color(TYPE_CIE_LAB, this->get1stValue(),
            this->get2ndValue(), this->get3rdValue());
        return converted;
    }
    case TYPE_XYZ: {
        float X, Y, Z;
        float L, A, B;
        X = this->get1stValue();
        Y = this->get2ndValue();
        Z = this->get3rdValue();
        X = static_cast<float>(X/95.047);
        Y = static_cast<float>(Y/100.0);
        Z = static_cast<float>(Z/108.883);
if (X > static_cast<float>(0.008856)) {
    X = static_cast<float>(pow(X, 1.0/3.0));} else {
    X = static_cast<float>((7.787*X)+(16.0/116.0));}
if (Y > static_cast<float>(0.008856)) {
    Y = static_cast<float>(pow(Y, 1.0/3.0));} else {
    Y = static_cast<float>((7.787*Y)+(16.0/116.0));}
if (Z > static_cast<float>(0.008856)) {
    Z = static_cast<float>(pow(Z, 1.0/3.0));} else {
    Z = static_cast<float>((7.787*Z)+(16.0/116.0));}
    L = (116*Y)-16;
    A = 500*(X-Y);
    B =200*(Y-Z);
converted = new Color(TYPE_CIE_LAB, L, A, B);
        return converted;
    }
    default: return NULL;
}
}
