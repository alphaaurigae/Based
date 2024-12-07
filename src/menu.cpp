#include "menu.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

void show_menu(const char* program_name) {
    std::cout << "Usage:\n"
              << "  " << program_name << " [options] <input>\n\n"
              << "Options:\n"
              << "  -h, --help      Show this help message and exit.\n"
              << "  -d              Decode Base58 input.\n"
              << "  --hex           Handle input as hex E.g 68656c6c6f == Cn8eVZg \n\n"
              << "  E.g \n"
              << "  $ bin/based_encode-decode 'Cn8eVZg'\n"
              << "  $ bin/based_encode-decode --hex '68656c6c6f'\n"
              << "  $ bin/based_encode-decode -d  'Cn8eVZg'\n"
              << "  Ensure your input for decoding is valid Base58-encoded data.\n\n";
    exit(0);
}

bool show_menu_condition(int argc, char** argv) {
    if (argc > 1 && (std::strcmp(argv[1], "-h") == 0 || std::strcmp(argv[1], "--help") == 0)) {
        show_menu(argv[0]);
        return true;
    }

    if (argc == 1 && isatty(STDIN_FILENO)) {
        show_menu(argv[0]);
        return true;
    }

    return false;
}