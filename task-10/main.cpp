#include <iostream>
#include <string>
#include "structures.h"
#include "methods.h"

uint16_t TransformInput(uint16_t input)
{
    uint16_t data = GetData(input);
    uint16_t playerBits = GetPlayers(input);

    int player = 0;
    if (playerBits == 0b0001) player = 1;
    if (playerBits == 0b0010) player = 2;
    if (playerBits == 0b0100) player = 3;
    if (playerBits == 0b1000) player = 4;

    uint16_t dpad = data & 0x000F;
    uint16_t buttons = (data >> 4) & 0xF;
    uint16_t shoulder = (data >> 8) & 0xF;

    uint16_t ndpad = dpad;
    uint16_t nbuttons = buttons;
    uint16_t nshoulder = shoulder;

    switch (player)
    {
    case 1:
        break;

    case 2:
        ndpad = 0;
        ndpad |= ((dpad & 0b0010) ? 0b0001 : 0);
        ndpad |= ((dpad & 0b0100) ? 0b0010 : 0);
        ndpad |= ((dpad & 0b1000) ? 0b0100 : 0);
        ndpad |= ((dpad & 0b0001) ? 0b1000 : 0);
        break;

    case 3:
        ndpad = 0;
        ndpad |= ((dpad & 0b0100) ? 0b0001 : 0);
        ndpad |= ((dpad & 0b1000) ? 0b0010 : 0);
        ndpad |= ((dpad & 0b0001) ? 0b0100 : 0);
        ndpad |= ((dpad & 0b0010) ? 0b1000 : 0);

        nshoulder = (~shoulder) & 0xF;
        break;

    case 4:
        ndpad = 0;
        ndpad |= ((dpad & 0b0001) ? 0b0100 : 0);
        ndpad |= ((dpad & 0b0100) ? 0b0001 : 0);
        ndpad |= ((dpad & 0b0010) ? 0b1000 : 0);
        ndpad |= ((dpad & 0b1000) ? 0b0010 : 0);

        nbuttons = 0;
        nbuttons |= ((buttons & 0b0001) ? 0b0010 : 0);
        nbuttons |= ((buttons & 0b0010) ? 0b0001 : 0);
        nbuttons |= ((buttons & 0b0100) ? 0b1000 : 0);
        nbuttons |= ((buttons & 0b1000) ? 0b0100 : 0);

        nshoulder = (~shoulder) & 0xF;

        {
            uint16_t low6 = data & 0x003F;
            uint16_t high6 = (data >> 6) & 0x003F;
            data = (low6 << 6) | high6;
            return SetPlayers(0, playerBits) | data;
        }

        break;
    }

    uint16_t newData =
        (ndpad) |
        (nbuttons << 4) |
        (nshoulder << 8);

    return SetPlayers(0, playerBits) | newData;
}

int main()
{
    std::string inputStr;
    std::cout << "Enter a 16-bit binary number: ";
    std::cin >> inputStr;

    if (inputStr.length() != 16) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    uint16_t value = 0;
    for (char c : inputStr)
    {
        value <<= 1;
        if (c == '1') value |= 1;
    }

    std::cout << "Original input:\n";
    PrintBitfield(value);
    PrintInputData(value);

    uint16_t transformed = TransformInput(value);

    std::cout << "\nTransformed:\n";
    PrintBitfield(transformed);
    PrintInputData(transformed);

    return 0;
}
