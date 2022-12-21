#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <functional>
#include <memory>

class IProcessor {
public:
    virtual ~IProcessor() = default;
    virtual void process(std::string p_userInput) = 0;
};

class AbstractProcessor : public IProcessor
{
public:
    explicit AbstractProcessor(std::unordered_map<std::string, std::string>& p_variables)
        : m_variables(p_variables) {}
protected:
    std::unordered_map<std::string, std::string>& m_variables;
};

class VariableProcessor : public AbstractProcessor {
public:
    using AbstractProcessor::AbstractProcessor;

    void process(std::string p_userInput) override {
        size_t equals = p_userInput.find('=');
        std::string name = p_userInput.substr(0, equals);
        std::string value = p_userInput.substr(equals + 1);
        m_variables.insert({name, value});
    }
};

class AddCommandProcessor;
class PrintCommandProcessor;

class CommandProcessor : public AbstractProcessor {
private:
    using CommandType = std::string;
    std::unordered_map<CommandType, std::unique_ptr<IProcessor>> m_commandProcessors;
public:
    explicit CommandProcessor(std::unordered_map<std::string, std::string>& p_variables) : AbstractProcessor(p_variables)
    {
        m_commandProcessors.emplace("!add", std::make_unique<AddCommandProcessor>(m_variables));
        m_commandProcessors.emplace("!print", std::make_unique<PrintCommandProcessor>(m_variables));
    }
    void process(std::string p_userInput) override
    {
        auto commandToken = p_userInput.substr(0, p_userInput.find_first_of(' '));
        m_commandProcessors.at(commandToken)->process(p_userInput);
    }
};

class AddCommandProcessor : public CommandProcessor {
public:
    using CommandProcessor::CommandProcessor;

    void process(std::string p_userInput) override {
        // Process the add command: add another variable or value to a specified variable.
        std::istringstream iss(p_userInput);
        std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
        if (tokens.size() == 3 && tokens[1][0] == '$') {
            std::string variableName = tokens[1];
            std::string arg = (tokens[2][0] == '$') ? m_variables[tokens[2]] : tokens[2];
            m_variables[variableName] += arg;
        }
    }
};

class PrintCommandProcessor : public CommandProcessor {
public:
    using CommandProcessor::CommandProcessor;

    void process(std::string p_userInput) override {
        // Process the print command.
        std::istringstream iss(p_userInput);
        std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
        auto it = tokens.begin();
        it++;
        while (it != tokens.end()) {
            std::string token = *it++;
            if (token[0] == '$') {
                std::cout << m_variables[token];
            } else {
                std::cout << token;
            }
        }
        std::cout << std::endl;
    }

};
class Parser
{
public:
    explicit Parser()
    {
        m_processors.emplace('$', std::make_unique<VariableProcessor>(variables));
        m_processors.emplace('!', std::make_unique<CommandProcessor>(variables));
    }
    void readInput() {
        std::string line;
        while (std::getline(std::cin, line)) {
            m_processors.at(line[0])->process(line);
        }
    }
private:
    std::unordered_map<std::string, std::string> variables;
    using CommandChar = char;
    std::unordered_map<CommandChar, std::unique_ptr<IProcessor>> m_processors;
};

// A simple parser.
int main() {
    Parser{}.readInput();
    return 0;
}
