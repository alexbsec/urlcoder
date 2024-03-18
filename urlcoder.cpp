#include <iostream>
#include <string>
#include <algorithm>

// Function prototypes
std::string urlencode(const std::string &value);
std::string urldecode(const std::string &value);
bool hasDecodeFlag(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	std::string input;
	bool decode = hasDecodeFlag(argc, argv);

	if (argc == 1 || (argc == 2 && decode)) {
		// Read from stdin
		std::getline(std::cin, input);
	} else {
		// Use the first non-flag argument as input
		for (int i =1; i < argc; i++) {
			std::string arg = argv[i];
			if (arg != "-d" && arg != "--decode") {
				input = arg;
				break;
			}
		}
	}

	if (decode) {
		std::cout << urldecode(input) << std::endl;
	} else {
		std::cout << urlencode(input) << std::endl;
	}

	return EXIT_SUCCESS;
}

bool hasDecodeFlag(int argc, char *argv[]) {
	return std::find(argv, argv + argc, std::string("-d")) != argv + argc ||
		std::find(argv, argv + argc, std::string("--decode")) != argv + argc;
}

std::string urlencode(const std::string &value) {
	std::string encoded;
	for (char c : value) {
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
			encoded += c;
		} else {
			char encodedChar[4];
			sprintf(encodedChar, "%%%02X", c);
			encoded.append(encodedChar);
		}
	}
	return encoded;
}

std::string urldecode(const std::string &value) {
	std::string decoded;
	for (size_t i = 0; i < value.length(); i++) {
		if (value[i] == '%' && i + 2 < value.length()) {
			std::string hex = value.substr(i + 1, 2);
			char decodedChar = static_cast<char>(std::stoi(hex, nullptr, 16));
			decoded += decodedChar;
			i += 2;
		} else if (value[i] == '+') {
			decoded += ' ';
		} else {
			decoded += value[i];
		}
	}
	return decoded;
}
