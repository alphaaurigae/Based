#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void print_unicode(const std::vector<unsigned char>& decoded) {
    try {
        // Convert the decoded bytes into a string, assuming UTF-8 encoding
        std::string decoded_str(decoded.begin(), decoded.end());
        
        // print the decoded string
        std::cout << "Decoded Output (Unicode Symbols): " << decoded_str << '\n';
    } catch (const std::exception& e) {
        std::cout << "Decoded Output (Unicode Symbols): Invalid UTF-8 sequence\n";
    }
}