// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_COLORSPACECONVERTER_H_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_COLORSPACECONVERTER_H_
extern const int TYPE_RGB;
extern const int TYPE_CIE_LAB;
extern const int TYPE_HSV;
extern const int TYPE_XYZ;
class Color {
 public:
Color();
Color(int type, float val1, float val2 , float val3);
~Color();
Color* convert(int type);
void setType(int type);
int getType();
void setValue(int position, float value);
float getValue(int position);
Color* convertToRGB();
Color* convertToHSV();
Color* convertToXYZ();
Color* convertToCIELAB();
static float checkValue(int type, int position, float val);
 private:
int type_;
float val1_;
float val2_;
float val3_;
};
#endif  // CODE_FEDOSOV_ALEXANDER_INCLUDES_COLORSPACECONVERTER_H_S
