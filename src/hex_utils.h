#ifndef HEX_UTILS_H
#define HEX_UTILS_H

#include <vector>
#include <string>
#include <stdexcept>

std::vector<unsigned char> hex_to_bytes(
const std::string& hex
);

std::string bytes_to_hex(
const std::vector<unsigned char>& bytes
);

#endif