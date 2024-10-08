// CHIP8project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "chip8.h"

chip8::chip8()
{
    std::array<uint8_t, 80> chip8_fontset =
    {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    PC = 0x200; //0x000 to 0x1FF (511 bits) is the interpreter so start at 512
    //reset on start
    I = 0;
    SP = 0;
    sound_timer = 0;
    delay_timer = 0;
    V_WIDTH = 64;

    //reset registers
    ViRe = {};
    stack = {};
    memory = {};
    display = {};
    keypad = {};
    draw_flag = false;

    //copy fontset into memory
    std::copy(std::begin(chip8_fontset), std::end(chip8_fontset), std::begin(memory));
} 

bool chip8::get_draw_flag()
{
    return draw_flag;
}

bool chip8::get_display_value(int display_location)
{
    return display[display_location];
}

void chip8::load_rom(const std::string* filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open())
    {
        const std::streampos size = file.tellg();
        char* buffer = new char[size];

        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        for (long i = 0; i < size; ++i)
        {
            memory[PC + i] = buffer[i]
        }

    }
}