#include "shell.hpp"
#include "common.hpp"

#include <iostream>

Shell::Shell(EmulatorState* emulator_state) : emulator_state(emulator_state), window(sf::VideoMode(640, 320), "Hello World!") {}
Shell::~Shell() { window.close(); }

void Shell::press_key(int index) {
    emulator_state->input[index] = true;
    // wait flag is only set true by Fx0A.
    if (emulator_state->wait_flag == true) {
        emulator_state->wait_flag = false;
        // so much for separation of repsonsiblities!
        // ugly code VVVV
        u16 current_opcode = (GET_MEMORY(emulator_state->program_counter) << 8) + GET_MEMORY(emulator_state->program_counter + 1);
        emulator_state->registers[GET_REGISTER(((current_opcode & 0x0F00) >> 8))] = index; 
    }
}

void Shell::execute() {
    sf::Event event;
    
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            emulator_state->kill_flag = true;
            break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
        press_key(0x1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
        press_key(0x2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
        press_key(0x3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
        press_key(0xC);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        press_key(0x4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        press_key(0x5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
        press_key(0x6);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        press_key(0xD);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        press_key(0x7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        press_key(0x8);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        press_key(0x9);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        press_key(0xE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
        press_key(0xA);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
        press_key(0x0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
        press_key(0xB);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V))
        press_key(0xF);
        
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