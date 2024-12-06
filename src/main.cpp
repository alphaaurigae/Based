#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <array>
#include <iomanip>

#include "unicode.h"
#include "base58.h"
#include "input_handler.h"
#include "menu.h"
#include "hex_utils.h"

int main(int argc, char** argv) {
    if (show_menu_condition(argc, argv)) {
        return 0;
    }

    bool decode = false;
    bool is_hex = false;
    std::string input = handle_input(argc, argv, decode);

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--hex") {
            is_hex = true;
            break;
        }
    }

    // If both --hex and -d are provided ...
    if (is_hex && decode) {
        std::cerr << "Error: It is not possible to decode a hex string to base!.\n";
        std::cerr << "Remove the --hex or -d (decode) argument.\n";
        return 1;
    }

    try {
        if (is_hex) {
            if (decode) {
                // Hex decode logic
                std::vector<unsigned char> decoded = hex_to_bytes(input);
                std::cout << "Decoded Output (base58): " << encode_base58(decoded) << '\n';
                // Print decoded as hex (normal)
                std::cout << "Decoded Output (hex) default: ";
                for (unsigned char byte : decoded) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(byte) << " ";
                }
                std::cout << '\n';
            } else {
                // Hex encode logic
                std::vector<unsigned char> data = hex_to_bytes(input);
                std::cout << "Encoded Output (Base58): " << encode_base58(data) << '\n';
            }
        } else {
            // Base58 decoding or encoding
            if (decode) {
                std::vector<unsigned char> decoded = decode_base58(input);

                std::cout << "Decoded Output (hex) default: ";
                for (unsigned char byte : decoded) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(byte) << " ";
                }
                std::cout << '\n';

                std::cout << "Decoded Output (hex) compact: ";
                for (unsigned char byte : decoded) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(byte);
                }
                std::cout << '\n';

                print_unicode(decoded);
            } else {
                std::vector<unsigned char> data(input.begin(), input.end());
                std::cout << "Encoding Input: " << input << "\n";
                std::cout << "Encoded Output: " << encode_base58(data) << '\n';
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}