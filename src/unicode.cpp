#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void print_unicode(const std::vector<unsigned char>& decoded) {
    try {
        std::string decoded_str(decoded.begin(), decoded.end());

        std::cout << "Decoded Output (Unicode Symbols): " << decoded_str << '\n';
    } catch (const std::exception& e) {
        std::cout << "Decoded Output (Unicode Symbols): Invalid UTF-8 sequence\n";
    }
}