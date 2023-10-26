#include "../include/rayscanner.h"

RayScanner::RayScanner(VPO &objects, float xResolution, float yResolution, float fovValue)
{
  this->objects = objects;
  this->xResolution = xResolution;
  this->yResolution = yResolution;
  fovScaler = 3 / tan((180 - fovValue) / 2 * 3.14159265358979323846 / 180.0); //  calculates how much the screen has to be scaled in order to reach the desired FOV
}

float RayScanner::normalizeXValue(int value)
{ //  returns x coordinate on a scale from -1 to 1
  return ((value - xResolution / 2) / (float)xResolution) * 2;
}

float RayScanner::normalizeYValue(int value)
{ //  returns x coordinate on a scale relative to the width of the screen
  return -((value - yResolution / 2) / (float)xResolution) * 2;
}

void RayScanner::scan()
{ //  Prints the image in ascii characters in the console
  static const char ascii[8] = {' ', '.', ',', '\"', '/', 'O', '8', '@'};
  for (int y = 0; y < yResolution; y++)
  { //  these two loops loop trough all pixels
    for (int x = 0; x < xResolution; x++)
    {
      float brightness = Ray(normalizeXValue(x) * fovScaler, normalizeYValue(y) * fovScaler, 1.0, objects).trace();
      for (int charCount = 0; charCount < 2; charCount++)
      {
        std::cout << ascii[(int)(brightness * (sizeof ascii / sizeof ascii[0]))]; //  picks a character based on the brightness
      }
    }
    std::cout << std::endl; //  Adds a line ending on the end of all lines
  }
}

void RayScanner::renderImage(float rValue, float gValue, float bValue)
{
  /*
    This was not needed for the assignment, but I wanted to try it. This outputs the image as a bmp file named "Output.bmp". This function works almost the same way
    as the function above, but with some extra code to write it to a bmp file.
  */

  std::cout << "Generating image..." << std::endl;

  //  This is a standard header for a simple bmp file, with the resolution filled in
  unsigned char bmpHeader[54] = {66, 77, 70, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, (unsigned char)(xResolution % 256), (unsigned char)(xResolution / 255), 0, 0, (unsigned char)(yResolution % 256), (unsigned char)(yResolution / 255), 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  std::ofstream outputFile;
  outputFile.open("Output.bmp", std::ios::binary);

  for (int tc = 0; tc < 54; tc++)
  { //  writes the header to the file
    outputFile << bmpHeader[tc];
  }

  for (int y = 0; y < yResolution; y++)
  {
    for (int x = 0; x < xResolution; x++)
    {
      float brightness = Ray(normalizeXValue(x) * fovScaler, -normalizeYValue(y) * fovScaler, 1.0, objects).trace();
      for (int rgb = 0; rgb < 3; rgb++)
      { // Writes the value 3 times because there are 3 color chanels
        switch (rgb)
        {
        case 0:
          outputFile << (char)(rValue * brightness * 255);
          break;
        case 1:
          outputFile << (char)(gValue * brightness * 255);
          break;
        case 2:
          outputFile << (char)(bValue * brightness * 255);
          break;
        }
      }
    }
    //  BMP files have to start each row of a image on a byte which is a multiple of 4. this writes some extra 0's to make all lines start on a valid byte
    for (int blankCounter = 0; blankCounter < (4 - (xResolution * 3) % 4) % 4; blankCounter++)
    {
      outputFile << (char)0;
    }
  }
  std::cout << "Image generated, See Output.bmp for result" << std::endl;
}
