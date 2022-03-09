#pragma once

#include <string>

#include "lex.hpp"
#include "elf.hpp"
#include "symbol.hpp"

class Parser {
public:
    explicit Parser(std::string input, Elf64File *file, Symbols *symbols);
    void build();
private:
    // Private variables
    Scanner *scanner;
    Elf64File *file;
    Symbols *symbols;
    
    // Private functions
    void parseText();
    void buildMov();
    void writeRROperand(uint8_t prefix, TokenType src, TokenType dest);
    uint8_t getRegisterValue(TokenType reg);
};
