

#include "Digit.h"
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnGenericAttribute.h>
#include <maya/MFnTypedAttribute.h>




MTypeId Digit::id(0x00121BD3);
MObject Digit::double_digit;
MObject Digit::int_digit;

Digit::Digit() { }
Digit::~Digit() { }

void* Digit::creator() {
	return new Digit();
}


MStatus Digit::initialize() {
    // attributes are writable by default
    // attributes are storable by default
    // attributes are readable by default
    // attributes not keyable by default

    MStatus stat;
    MFnNumericAttribute fnNum;
    MFnGenericAttribute fnGen;
    MFnTypedAttribute fnTyped;

    // TODO: Maybe there is a more generic way to handle these attribute, but this works for now

    double_digit = fnNum.create("doubleDigit", "ddgt", MFnNumericData::kDouble, 0.0, &stat);
    CHECK_MSTATUS_AND_RETURN_IT(stat);
    fnNum.setKeyable(true);
    stat = Digit::addAttribute(double_digit);
    CHECK_MSTATUS_AND_RETURN_IT(stat);

    int_digit = fnNum.create("intDigit", "idgt", MFnNumericData::kInt, 0, &stat);
    CHECK_MSTATUS_AND_RETURN_IT(stat);
    fnNum.setKeyable(true);
    stat = Digit::addAttribute(int_digit);
    CHECK_MSTATUS_AND_RETURN_IT(stat);


    return MS::kSuccess;
}

