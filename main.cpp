#include <input.h>
#include <windows.h>
#include <random>

// Simple diamond-shaped spinner. Creates a uniform integer rng value for delay and movement range.
void spinSimpleDiamond(std::mt19937 &gen)
{
    input::pressKey(0x53, true);
    std::uniform_int_distribution<> distribMove(8, 12); // Range of movement: [lower, upper]
    std::uniform_int_distribution<> distribDel(5, 15); // Range of delay: [lower, upper]

    while (GetAsyncKeyState(VK_SHIFT) & 0x8000)
    {
        int val = distribMove(gen);
        int delay = distribDel(gen);

        for (int i = 0; i < 10; ++i)
        {
            input::moveMouse(val, -val);
        }
        Sleep(delay);

        for (int i = 0; i < 10; ++i)
        {
            input::moveMouse(-val, -val);
        }
        Sleep(delay);

        for (int i = 0; i < 10; ++i)
        {
            input::moveMouse(-val, val);
        }
        Sleep(delay);

        for (int i = 0; i < 10; ++i)
        {
            input::moveMouse(val, val);
        }
        Sleep(delay);
    }

    input::pressKey(0x53, false);
}

// WIP: It is working but doesn't max out spin rate (~370 rpm)
#include <shape.h>
#include <vector>
#include <iostream>
void spinHeart(std::vector<shape::Data> const &coords)
{
    for (auto i : coords)
    {
        input::moveMouse(i.dx, i.dy);

        Sleep(1);
    }
}

void spinHeartArray(shape::Data *coords)
{
    for (int i = 0; i < 12; ++i)
    {
        input::moveMouse(coords[i].dx, coords[i].dy);

        Sleep(1);
    }
}

void spinCircle(std::vector<shape::Data> const &coords)
{
    for (auto i : coords)
    {
        input::moveMouse(i.dx, i.dy);

        Sleep(1);
    }
}

int main(int, char**)
{
    bool start = true;
    bool toggle = false;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Heart coordinates
    std::vector<shape::Data> coords = shape::genHeart();
    shape::Data coordinates[45];
    shape::genHeartArray(coordinates);

    // Circle coordinates
    coords = shape::genEllipse(1, 1, 25);

    while (start)
    {
        // spin 2 win
        if (toggle && (GetAsyncKeyState(VK_SHIFT) & 0x8000))
        {
            //driver(gen);
            //driver_fancy(coords);
            //driver_fancyArray(coordinates);
            spinCircle(coords);
        }

        // Kill switch
        if (GetKeyState(VK_END) & 0x8000)
        {
            return 0;
        }

        // Toggle
        if (GetKeyState(VK_HOME) & 0x8000)
        {
            system("cls");
            if (toggle)
            {
                toggle = !toggle;
                std::cout << "Off\n";
            }
            else
            {
                toggle = !toggle;
                std::cout << "On\n";
            }
            Sleep(250);
        }
    }

    return 0;
}
