#include <iostream>
#include <fstream>
#include <optional>
#include <vector>
#include <fmt/color.h>
#include <CLI/CLI.hpp>

enum class TokenType {
    _return,
    int_lit,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

std::string readFile(char *fileName);
std::vector<Token> lex(const std::string& fileContent);


int main(int argc, char **argv)
{
    CLI::App app{"Stupid Compiler"};

    std::string filename, fileContent;
    app.add_option("-f,--file", filename, "Input file name")->required();

    CLI11_PARSE(app, argc, argv);

    if(filename != "")
    {
        filename = argv[2];
        fileContent = readFile((char *)filename.c_str());
    }

    // std::cout << fileContent << std::endl;
    lex(fileContent);

    return EXIT_SUCCESS;
}

/**
 * @brief Show input file content 
 * 
 * @param inputFile Input file name 
 */
std::string readFile(char *inputFile)
{
    std::string fileContent;
    std::fstream file(inputFile, std::ios::in);

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            // Skip over empty or whitespace-only lines
            if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            {
                continue;
            }
            fileContent += line + "\n";
            // std::cout << line << std::endl;
        }
        file.close();
    }
    else
        fmt::print(fg(fmt::color::red), "Error: File not found (Func)\n");
    return fileContent;
}

std::vector<Token> lex(const std::string &fileContent)
{
    for (auto &c : fileContent)
    {
        std::cout << c << std::endl;
        std::isalpha(c);
    }
    return std::vector<Token>();
}
