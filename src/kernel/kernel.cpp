/*
Kernel Main File
Contains entry point
*/
#include "kernel.hpp"

void KeyboardHandler( char scanCode )
{
    KeyInput input = translateScanCode(scanCode);
    
    if (input.action == KeyDown) {
        if (input.key == Backspace)
        {
            term->moveCursor(term->getCursorPos() - 1);
            term->printChr(' ');
            term->moveCursor(term->getCursorPos() - 1);
            return;
        }

        char keyCode = translateKeyCode(input.key);
        if (!keyCode) return;

        term->printChr(keyCode);
    }
}

extern "C" void _start( void )
{
    InitializeHeap(0xC000);
    setup_idt();
    
    term = (VBETerminal*) calloc(sizeof(VBETerminal));
    term->clear_screen();
    term->info("Kernel Loaded!");
}