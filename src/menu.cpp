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
              << "  -d              Decode Base58 input.\n\n"
              << "Description:\n"
              << "  By default, the program encodes the input to Base58.\n"
              << "  Use the -d option to decode Base58 back to raw bytes.\n"
              << "  Input can be provided as an argument or through a pipe.\n\n"
              << "Examples:\n"
              << "  Encoding from stdin (pipe):\n"
              << "    echo 'hello' | " << program_name << "\n"
              << "  Encoding from argument:\n"
              << "    " << program_name << " 'hello'\n\n"
              << "  Decoding from stdin (pipe):\n"
              << "    echo 'Cn8eVZg' | " << program_name << " -d\n"
              << "  Decoding from argument:\n"
              << "    " << program_name << " -d 'Cn8eVZg'\n\n"
              << "Behavior:\n"
              << "  - Decoding output includes hex (default and compact) and Unicode representations.\n\n"
              << "Note:\n"
              << "  Ensure your input for decoding is valid Base58-encoded data.\n";
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