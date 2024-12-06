#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

std::string handle_input(int argc, char** argv, bool& decode) {
    std::string input;

    // Check for the -d flag for decoding
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-d") {
            decode = true;
            break;
        }
    }

    if (argc > 1 && argv[argc - 1][0] != '-') {
        input = argv[argc - 1];
    } else {
        if (!std::cin.eof() && std::cin.peek() != EOF) {
            std::getline(std::cin, input);
        } else {
            std::cerr << "No input received via pipe or stdin.\n";
            std::exit(1);
        }
    }

    std::cout << "Input received: [" << input << "]\n";

    // If input is enclosed in quotes, remove the quotes
    bool quotes_removed = false;
    if (!input.empty() && ((input.front() == '"' && input.back() == '"') || (input.front() == '\'' && input.back() == '\''))) {

        std::cout << "Detected and removing quotes from the input.\n";
        input = input.substr(1, input.size() - 2);
        quotes_removed = true;
    }

    // Print the modified input after removing quotes (if any)
    if (quotes_removed) {
        std::cout << "Modified Input (quotes removed): [" << input << "]\n";
    } else {
        std::cout << "No quotes to remove. Modified Input: [" << input << "]\n";
    }

    return input;
}