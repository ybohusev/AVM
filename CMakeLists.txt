cmake_minimum_required(VERSION 3.14)
project(AVM)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(headers/Commands)

add_executable(AVM
        headers/Commands/Add.hpp
        headers/Commands/Assert.hpp
        headers/Commands/Commands.hpp
        headers/Commands/Div.hpp
        headers/Commands/Dump.hpp
        headers/Commands/Mod.hpp
        headers/Commands/Mul.hpp
        headers/Commands/Pop.hpp
        headers/Commands/Print.hpp
        headers/Commands/Push.hpp
        headers/Commands/Sub.hpp
        headers/IOperand.hpp
        headers/OFactory.hpp
        #headers/Parser.hpp
        headers/TOperands.hpp
        src/Commands/Add.cpp
        src/Commands/Assert.cpp
        src/Commands/Commands.cpp
        src/Commands/Div.cpp
        src/Commands/Dump.cpp
        src/Commands/Mod.cpp
        src/Commands/Mul.cpp
        src/Commands/Pop.cpp
        src/Commands/Print.cpp
        src/Commands/Push.cpp
        src/Commands/Sub.cpp
        src/main.cpp
        src/OFactory.cpp
        #src/Parser.cpp
        headers/Lexer.hpp
        src/Lexer.cpp
        headers/Commands/CommandsSet.hpp)
