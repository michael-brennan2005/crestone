#include "shell.hpp"

#include <iostream>

Shell::Shell(EmulatorState* emulator_state) : emulator_state(emulator_state), window(sf::VideoMode(640, 320), "Hello World!") {}
Shell::~Shell() { window.close(); }

void Shell::execute() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            emulator_state->kill_flag = true;
        }
        
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "Cool." << std::endl;
        }
    }

    window.clear(sf::Color::Black);

    window.display();
};