#ifndef H_COMMAND_LINE_INTERFACE
#define H_COMMAND_LINE_INTERFACE

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "scene.h"
#include "rayscanner.h"
#include "floor.h"
#include "sphere.h"

class CommandLineInterface
{
public:
    std::map<std::string, void (CommandLineInterface::*)(const std::string &)> commandMap{
    };
    Scene &scene;
    RayScanner &rayScanner;

    CommandLineInterface(Scene &scene, RayScanner &rayScanner);
    void run();

private:
    void processInput(const std::string &input);
};

#endif
