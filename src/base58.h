#ifndef BASE58_H
#define BASE58_H

#include <vector>
#include <string>


std::string encode_base58(const std::vector<unsigned char>& data);


std::vector<unsigned char> decode_base58(const std::string& encoded);

#endif