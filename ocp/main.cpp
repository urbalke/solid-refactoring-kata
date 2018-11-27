#include <iostream>
#include <unordered_map>
#include <vector>

// A simple parser.
int main() {
    std::unordered_map<std::string, std::string> variables;
    std::string line;
    while (std::getline(std::cin, line)) {
        switch (line[0]) {
            case '$': {
                // Process the entire line as a variable.
                size_t equals = line.find('=');
                std::string name = line.substr(0, equals);
                std::string value = line.substr(equals+1);
                variables.insert({name, value});
                break;
            }
            case '!': {
                // Process the command in this line.
                if (line.find('!print') == 0) {
                    // print command
                } else if (line.find('!add') == 0) {
                    // add command
                }
                break;
            }
            default: {
                // Do nothing.
            }
        }
    }
    return 0;
}
