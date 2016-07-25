#pragma once

#include <maya/MPxNode.h>
#include <maya/MTypeId.h>


class Digit : public MPxNode {
public:
    Digit();
    ~Digit();
	virtual MPxNode::SchedulingType schedulingType() const override { return MPxNode::kParallel; }
	static void* creator();
	static MStatus initialize();
public:
	static MTypeId id;
    static MObject double_digit;
    static MObject int_digit;
};