#include <iostream>

#include "../include/command_line_interface.h"
#include "../include/rayscanner.h"
#include "../include/scene.h"

int main()
{
  Scene scene = Scene();
  RayScanner scanner = RayScanner(scene, 1280, 720, 75);

  CommandLineInterface program = CommandLineInterface(scene, scanner);
  program.run();

  return 0;
}
