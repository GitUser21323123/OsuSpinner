#include <input.h>
#include <windows.h>
#include <random>


// Simple diamond-shaped spinner. Creates a uniform integer rng value for delay and movement range.
void driver(std::mt19937 &gen)
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


// WIP
#include <shape.h>
#include <vector>
#include <iostream>
void driver_fancy(std::vector<shape::Data> const &coords)
{
    for (auto i : coords)
    {
        //input::moveMouse(i[0], i[1]); // Very slow...

        std::cout << i.dx << " " << i.dy << "\n";

        Sleep(1);
    }
}

void driver_fancyArray(shape::Data *coords)
{
    for (int i = 0; i < 21; ++i)
    {
        input::moveMouse(coords[i].dx, coords[i].dy);

        Sleep(5);
    }
}

int main(int, char**)
{
    bool start = false;
    bool toggle = false;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Heart coordinates
    std::vector<shape::Data> coords = shape::genHeart();
    shape::Data coordinates[45];
    shape::genHeartArray(coordinates);

    for (int i = 0; i < 22; ++i)
    {
        std::cout << coordinates[i].dx << " " << coordinates[i].dy << "\n";
    }

    while (start)
    {
        // spin 2 win
        if (toggle && (GetAsyncKeyState(VK_SHIFT) & 0x8000))
        {
            //driver(gen);
            //driver_fancy(coords);
            driver_fancyArray(coordinates);
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
