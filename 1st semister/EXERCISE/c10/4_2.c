#include <stdio.h>
#include <Windows.h>

int main()
{
    HANDLE serial_port = CreateFile(
        "COM1",        // Change this to the appropriate COM port (COM1, COM2, etc.)
        GENERIC_READ,  // Access mode: read-only
        0,             // Share mode: none
        NULL,          // Security attributes
        OPEN_EXISTING, // Opens a device if it exists
        0,             // Flags and attributes
        NULL           // Template file (not used for COM ports)
    );

    if (serial_port == INVALID_HANDLE_VALUE)
    {
        printf("Error opening serial port\n");
        return 1;
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(serial_port, &dcbSerialParams))
    {
        printf("Error getting serial port state\n");
        CloseHandle(serial_port);
        return 1;
    }

    // The status of the serial port is stored in dcbSerialParams structure
    printf("Serial port status: %d\n", dcbSerialParams.fDtrControl);

    CloseHandle(serial_port);
    return 0;
}
