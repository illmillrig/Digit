

#include "Digit.h"
#include <maya/MFnPlugin.h>


MStatus initializePlugin( MObject obj ) {
	MStatus   status;
	MFnPlugin plugin( obj, "Travis Miller", "2016", "Any");

	status = plugin.registerNode( "Digit", Digit::id, Digit::creator,
								  Digit::initialize, MPxNode::kDependNode );
	if (!status) {
		status.perror("registerNode");
		return status;
	}

	return status;
}

MStatus uninitializePlugin( MObject obj) {
	MStatus   status;
	MFnPlugin plugin( obj );

	status = plugin.deregisterNode( Digit::id );
	if (!status) {
		status.perror("deregisterNode");
		return status;
	}

	return status;
}