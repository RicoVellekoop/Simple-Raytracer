#ifndef H_RAYSCANNER
#define H_RAYSCANNER

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

#include "object.h"

typedef std::vector<Object*> VPO;

#include "ray.h"

class RayScanner{
public:
    VPO objects;
    int xResolution, yResolution;
    float fovScaler;

    RayScanner(VPO &objects, float xResolution, float yResolution, float fovValue);

    float normaliseXValue(int value);

    float normaliseYValue(int value);

    void scan();

    void renderImage(float rValue, float gValue, float bValue);
};
#endif
