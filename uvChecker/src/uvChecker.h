#ifndef __UVCHECKER_H__
#define __UVCHECKER_H__

#include <maya/MDagPath.h>
#include <maya/MPxCommand.h>
#include <maya/MSyntax.h>
#include <maya/MString.h>

class UvChecker : public MPxCommand {
public:
    UvChecker();
    virtual ~UvChecker();
    MStatus doIt(const MArgList& argList);
    MStatus undoIt();
    MStatus redoIt();
    bool isUndoable() const;
    static void* creater();
    static MSyntax newSyntax();

    MStatus findOverlaps();
    MStatus findUdimIntersections();
    MStatus findNoUvFaces();
    MStatus findZeroUvFaces();

    enum Check {
        OVERLAPS,
        UDIM,
        HAS_UVS,
        ZERO_AREA
    };

private:
    MDagPath mDagPath;
    bool verbose;
    double minUVArea;
    unsigned int checkNumber;
};

#endif /* defined(__UVCHECKER_H__) */
