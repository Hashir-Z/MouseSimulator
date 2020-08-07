#include <iostream>
#include <windows.h>
#include <conio.h>

void MiddleClick()
{
	INPUT    Input = { 0 };
	// Middle Mouse Down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// Middle Mouse Up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
	::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
	if (RegisterHotKey(NULL, 1, MOD_CONTROL, 0))	// MOD Control tells you want CRTL to be register
	{
		std::cout << "Hotkey 'Left Control' Registered! \n";
	}
	else
	{
		std::cout << "Error code " << GetLastError();
	}

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		std::cout << "\nMessage:" << msg.message;	// Tells us the code ran successfully
		if (msg.message == WM_HOTKEY)
		{
			MiddleClick();							// Call Function to press Middle Mouse Button
		}
	}

	return 0;
}