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

class Lexer
{
    static std::string errLine;
    std::vector<std::string> commands;
    std::ifstream fin;

    std::vector<std::string> splitString(std::string com, char delim);
public:
    Lexer();
    Lexer(Lexer const &obj);
    ~Lexer();
    Lexer &operator=(Lexer const &obj);
    std::vector<std::string> readFromFile(std::string const &filename);
    std::vector<std::string> readUserInput();

    void checkLex(std::string line);

    class FileOpenException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class NoExitException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class WrongCommandException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };
};

#endif //AVM_LEXER_HPP
