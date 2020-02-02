/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:35:57 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/26 16:36:00 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_LEXER_HPP
#define AVM_LEXER_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "Commands/CommandsSet.hpp"
#include "OperandType.h"

class LexicalError : public std::exception
{
public:
    virtual const char *what() const noexcept = 0;
};

class SyntaxError : public std::exception
{
public:
    virtual const char *what() const noexcept = 0;
};

class Lexer
{
    static std::string errLine;
    std::vector<std::string> commands;
    std::ifstream fin;
    bool isExit;

    void checkLex(std::string line);
    eCommandType checkComLex(std::string& com);
    static void checkOpTypeLex(std::string& OpType, eCommandType comType);
    static std::vector<std::string> splitString(std::string& com, char delim);
    static bool isNumber(std::string& st);
public:
    Lexer();
    Lexer(Lexer const &obj);
    ~Lexer();
    Lexer &operator=(Lexer const &obj);
    std::vector<std::string> readFromFile(std::string const &filename);
    std::vector<std::string> readUserInput();

    class FileOpenException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };
    class NoExitException : public SyntaxError
    {
    public:
        const char *what() const noexcept override;
    };
    class WrongCommandException : public LexicalError
    {
    public:
        const char *what() const noexcept override;
    };
    class WrongOperandTypeException : public LexicalError
    {
    public:
        const char *what() const noexcept override;
    };
    class commandSignException : public SyntaxError
    {
    public:
        const char *what() const noexcept override;
    };
    class unexpectedSybmbolException : public SyntaxError
    {
    public:
        const char *what() const noexcept override;
    };
    class missedBracketsException : public SyntaxError
    {
    public:
        const char *what() const noexcept override;
    };
    class invalidArgumentException : public SyntaxError
    {
    public:
        const char *what() const noexcept override;
    };
};

#endif //AVM_LEXER_HPP
