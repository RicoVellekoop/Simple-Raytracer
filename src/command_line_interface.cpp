#include "../include/command_line_interface.h"

CommandLineInterface::CommandLineInterface(Scene &scene, RayScanner &rayScanner)
    : scene(scene), rayScanner(rayScanner)
{
}

void CommandLineInterface::run()
{
    std::string input;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit")
            break;
        processInput(input);
    }
}

void CommandLineInterface::processInput(const std::string &input)
{
    std::string command = input.substr(0, input.find(" "));
    std::string arguments = input.substr(input.find(" ") + 1);
    if (commandMap.count(command) == 0)
    {
        std::cout << "Error: Unknown command '" << command << "'" << std::endl;
        return;
    }
    (this->*commandMap[command])(arguments);
}
