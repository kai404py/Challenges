#pragma once
#include "structures.h"

PlayerInput BitfieldToPlayerInput(uint16_t input);
uint16_t PlayerInputToBitfield(const PlayerInput& input);

void PrintInputData(const uint16_t input)
{
    PlayerInput pi = BitfieldToPlayerInput(input);

    std::cout << "Player: " << pi.playerIndex << "\n";

    std::cout << "DPad: L=" << pi.dpad.leftPressed
        << " U=" << pi.dpad.upPressed
        << " R=" << pi.dpad.rightPressed
        << " D=" << pi.dpad.downPressed << "\n";

    std::cout << "Buttons: A=" << pi.buttons.APressed
        << " B=" << pi.buttons.BPressed
        << " X=" << pi.buttons.XPressed
        << " Y=" << pi.buttons.YPressed << "\n";

    std::cout << "Shoulders: L1=" << pi.shoulderButtons.L1Pressed
        << " L2=" << pi.shoulderButtons.L2Pressed
        << " R1=" << pi.shoulderButtons.R1Pressed
        << " R2=" << pi.shoulderButtons.R2Pressed << "\n";
}

void PrintBitfield(const uint16_t input)
{
    for (int i = 15; i >= 0; --i)
    {
        uint16_t mask = 1 << i;
        std::cout << ((input & mask) ? '1' : '0');
    }
    std::cout << "\n";
}

uint16_t SetBitAtPosition(const uint16_t input, int index, bool value)
{
    uint16_t mask = 1 << index;

    if (value)
        return input | mask;
    else
        return input & ~mask;
}

uint16_t SetData(const uint16_t input, const uint16_t data)
{
    uint16_t cleared = input & 0xF000;
    return cleared | (data & 0x0FFF);
}

uint16_t SetPlayers(const uint16_t input, const uint16_t players)
{
    uint16_t cleared = input & 0x0FFF;
    return cleared | (players << 12);
}

uint16_t GetPlayers(const uint16_t input)
{
    return (input >> 12) & 0x000F;
}

uint16_t GetData(const uint16_t input)
{
    return input & 0x0FFF;
}

uint16_t PlayerInputToBitfield(const PlayerInput& in)
{
    uint16_t result = 0;

    result |= (1 << (in.playerIndex - 1 + 12));

    result = SetBitAtPosition(result, 0, in.dpad.leftPressed);
    result = SetBitAtPosition(result, 1, in.dpad.upPressed);
    result = SetBitAtPosition(result, 2, in.dpad.rightPressed);
    result = SetBitAtPosition(result, 3, in.dpad.downPressed);

    result = SetBitAtPosition(result, 4, in.buttons.APressed);
    result = SetBitAtPosition(result, 5, in.buttons.BPressed);
    result = SetBitAtPosition(result, 6, in.buttons.XPressed);
    result = SetBitAtPosition(result, 7, in.buttons.YPressed);

    result = SetBitAtPosition(result, 8, in.shoulderButtons.L1Pressed);
    result = SetBitAtPosition(result, 9, in.shoulderButtons.L2Pressed);
    result = SetBitAtPosition(result, 10, in.shoulderButtons.R1Pressed);
    result = SetBitAtPosition(result, 11, in.shoulderButtons.R2Pressed);

    return result;
}

PlayerInput BitfieldToPlayerInput(const uint16_t input)
{
    PlayerInput out{};

    uint16_t p = GetPlayers(input);
    if (p == 1) out.playerIndex = 1;
    if (p == 2) out.playerIndex = 2;
    if (p == 4) out.playerIndex = 3;
    if (p == 8) out.playerIndex = 4;

    out.dpad.leftPressed = (input & (1 << 0)) != 0;
    out.dpad.upPressed = (input & (1 << 1)) != 0;
    out.dpad.rightPressed = (input & (1 << 2)) != 0;
    out.dpad.downPressed = (input & (1 << 3)) != 0;

    out.buttons.APressed = (input & (1 << 4)) != 0;
    out.buttons.BPressed = (input & (1 << 5)) != 0;
    out.buttons.XPressed = (input & (1 << 6)) != 0;
    out.buttons.YPressed = (input & (1 << 7)) != 0;

    out.shoulderButtons.L1Pressed = (input & (1 << 8)) != 0;
    out.shoulderButtons.L2Pressed = (input & (1 << 9)) != 0;
    out.shoulderButtons.R1Pressed = (input & (1 << 10)) != 0;
    out.shoulderButtons.R2Pressed = (input & (1 << 11)) != 0;

    return out;
}
