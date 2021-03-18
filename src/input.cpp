#include <input.h>
#include <windows.h>

namespace input
{
    // Sends a virtual keyboard input on WINDOWS
    // The key is signified by the hex virtual key code
    // Using a bool to determine if we are pressing or releasing
    void pressKey(int keyCode, bool down)
    {
        // Setup
        INPUT input[1];
        ZeroMemory(input, sizeof(input));

        // Keyboard input parameters (type, wVirtualKey, flag)
        input[0].type = INPUT_KEYBOARD;
        input[0].ki.wVk = keyCode;

        if (down) // Pressing
        {
            input[0].ki.dwFlags = 0;    
        }
        else // Releasing
        {
            input[0].ki.dwFlags = KEYEVENTF_KEYUP;
        }

        SendInput(1, input, sizeof(INPUT));
    }

    // Sends a mouse move command on WINDOWS
    // The values provided are the relative movement from current mouse location
    void moveMouse(int dx, int dy)
    {
        // Set up
        INPUT input[1];
        ZeroMemory(input, sizeof(input));

        // Mouse input arameters (type, flag, dx, dy)
        input[0].type = INPUT_MOUSE;
        input[0].mi.dwFlags = MOUSEEVENTF_MOVE;
        input[0].mi.dx = dx;
        input[0].mi.dy = dy;

        SendInput(ARRAYSIZE(input), input, sizeof(INPUT));
    }
}

