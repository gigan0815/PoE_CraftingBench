#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

//
// TODO:
// -----------------------------------------------------------------------
// Clean up code, check for functions
// -----------------------------------------------------------------------
// Add logic to use the stored coordinates
// -----------------------------------------------------------------------
// Saving coordinates by pressing 'a' feels unresponsive most of the time.
// -----------------------------------------------------------------------
//

POINT StoreMouseCoordinates(string s)
{
    POINT cursorPos;

    cout << "Press 'a' while hovering over the center of: " + s << endl;

    while (true)
    {
        // Check if the 'A' key is pressed
        if (GetAsyncKeyState('A') & 0x8000)
        {
            if (GetCursorPos(&cursorPos))
            {
                cout << "Cursor Position: (" << cursorPos.x << ", " << cursorPos.y << ")" << endl;
                Sleep(100); // Sleep to avoid multiple captures on a single key press

                return cursorPos;
            }
            else
            {
                cerr << "Error: Could not get cursor position." << endl;
                exit(1);
            }
            break;
        }
        Sleep(100);
    }
}

int main()
{
    // Set window title as constant
    // This is the title of the Path of Exile window we want to bring to the foreground
    // Ensure that the title matches exactly with the game's window title, else it cant be found
    const char *windowTitle = "Path of Exile";

    // Find the window by its title
    HWND hwnd = FindWindowA(NULL, windowTitle);

    // Check if the window was found
    if (hwnd == NULL)
    {
        cerr << "Error: Could not find window." << endl;
        exit(1);
    }

    // Bring the window to the foreground
    SetForegroundWindow(hwnd);

    POINT orbOfAlterationPos = StoreMouseCoordinates("Orb of Alteration");
    POINT orbOfAugmentationPos = StoreMouseCoordinates("Orb of Augmentation");
    POINT itemPos = StoreMouseCoordinates("Item");

    return 0;
}