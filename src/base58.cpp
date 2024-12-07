#include "base58.h"

#include <flint/fmpz.h>

#include <array>
#include <stdexcept>
#include <ranges>
#include <string_view>
#include <algorithm>

constexpr std::string_view BASE58_ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
constexpr int BASE58_ALPHABET_SIZE = BASE58_ALPHABET.size();

constexpr auto CREATE_BASE58_LOOKUP_TABLE() {
    std::array<int, 256> lookup_table{};
    lookup_table.fill(-1);
    for (int i = 0; i < BASE58_ALPHABET_SIZE; ++i) {
        lookup_table[static_cast<unsigned char>(BASE58_ALPHABET[i])] = i;
    }
    return lookup_table;
}

constexpr auto BASE58_LOOKUP_TABLE = CREATE_BASE58_LOOKUP_TABLE();


std::string encode_base58(const std::vector<unsigned char>& data) {
    fmpz_t value;
    fmpz_init(value);
    fmpz_set_ui(value, 0);

    for (unsigned char byte : data) {
        fmpz_mul_ui(value, value, 256);
        fmpz_add_ui(value, value, byte);
    }

    std::string result;
    while (fmpz_cmp_ui(value, 0) > 0) {
        fmpz_t remainder;
        fmpz_init(remainder);
        fmpz_mod_ui(remainder, value, BASE58_ALPHABET_SIZE);
        int remainder_int = fmpz_get_ui(remainder);
        result.push_back(BASE58_ALPHABET[remainder_int]);
        fmpz_fdiv_q_ui(value, value, BASE58_ALPHABET_SIZE);
        fmpz_clear(remainder);
    }

    for (unsigned char byte : data) {
        if (byte != 0) break;
        result.push_back(BASE58_ALPHABET[0]);
    }

    std::ranges::reverse(result);
    fmpz_clear(value);

    return result;
}

std::vector<unsigned char> decode_base58(const std::string& encoded) {
    fmpz_t value;
    fmpz_init(value);
    fmpz_set_ui(value, 0);

    for (char c : encoded) {
        int index = BASE58_LOOKUP_TABLE[static_cast<unsigned char>(c)];
        if (index == -1) {
            throw std::invalid_argument("Invalid character in Base58 string.");
        }
        fmpz_mul_ui(value, value, BASE58_ALPHABET_SIZE);
        fmpz_add_ui(value, value, index);
    }

    int num_leading_zeros = std::ranges::count(encoded | std::views::take_while([](char c) { return c == BASE58_ALPHABET[0]; }), BASE58_ALPHABET[0]);

    std::vector<unsigned char> result;
    while (fmpz_cmp_ui(value, 0) > 0) {
        fmpz_t remainder;
        fmpz_init(remainder);
        fmpz_mod_ui(remainder, value, 256);
        unsigned char byte = fmpz_get_ui(remainder);
        result.insert(result.begin(), byte);
        fmpz_fdiv_q_ui(value, value, 256);
        fmpz_clear(remainder);
    }

    result.insert(result.begin(), num_leading_zeros, 0);

    fmpz_clear(value);
    return result;
}

