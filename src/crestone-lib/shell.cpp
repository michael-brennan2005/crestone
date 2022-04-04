#include "shell.hpp"

#include <iostream>

Shell::Shell(EmulatorState* emulator_state) : emulator_state(emulator_state), window(sf::VideoMode(640, 320), "Hello World!") {}
Shell::~Shell() { window.close(); }

void Shell::execute() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            emulator_state->kill_flag = true;
            break;
        }
        
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "Cool." << std::endl;
            break;
        }
    }

    window.clear(sf::Color::Black);

    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 32; y++) {
            if (emulator_state->get_pixel(x, y)) {
                sf::RectangleShape pixel(sf::Vector2<float>(10.0,10.0));
                pixel.setPosition(x * (window.getSize().x / 64), y * (window.getSize().y / 32));
                pixel.setFillColor(sf::Color::White);
                window.draw(pixel);
            }
        }
    }

    window.display();
};