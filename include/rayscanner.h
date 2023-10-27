#ifndef H_RAYSCANNER
#define H_RAYSCANNER

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

#include "object.h"

typedef std::vector<Object *> VPO;

#include "ray.h"
#include "image.h"
#include "scene.h"

class RayScanner
{
public:
    Scene scene;
    int xResolution, yResolution;
    float fovScaler;

    RayScanner(Scene &scene, float xResolution, float yResolution, float fovValue);

    float normalizeXValue(int value);

    float normalizeYValue(int value);

    Image renderImage();
};
#endif
