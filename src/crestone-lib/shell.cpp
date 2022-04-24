#include "shell.hpp"
#include "common.hpp"

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
            u8 index = emulator_state->key_to_index(event.key.code);
            if (index == -1)
                break;
            
            emulator_state->input[index] = true;
            // wait flag is only set true by Fx0A.
            if (emulator_state->wait_flag == true) {
                emulator_state->wait_flag = false;

                // so much for separation of repsonsiblities!
                // ugly code VVVV
                u16 current_opcode = (GET_MEMORY(emulator_state->program_counter) << 8) + GET_MEMORY(emulator_state->program_counter + 1);
                emulator_state->registers[GET_REGISTER(((current_opcode & 0x0F00) >> 8))] = index; 
            }

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