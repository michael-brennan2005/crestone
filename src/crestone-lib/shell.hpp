#ifndef CRESTONE_SHELL_H
#define CRESTONE_SHELL_H

#include <SFML/Graphics.hpp>
#include "emulatorstate.hpp"

class Shell {
public: 
    Shell(EmulatorState* emulator_state);
    ~Shell();
    EmulatorState* emulator_state;
    sf::RenderWindow window; 

    void execute();
};

#endif // CRESTONE_SHELL_H
