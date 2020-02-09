# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 16:04:57 by ybohusev          #+#    #+#              #
#    Updated: 2020/01/25 16:05:09 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = AVM

CC = clang++
FLAGS = -std=c++11  #-Wall -Werror -Wextra

DIR_S = src
DIR_C = $(DIR_S)/Commands
DIR_O = obj
DIR_H = headers

SOURCES =

SOURCES += main.cpp
SOURCES += Parser.cpp
SOURCES += OFactory.cpp
SOURCES += Lexer.cpp
SOURCES_C += Sub.cpp
SOURCES_C += Push.cpp
SOURCES_C += Print.cpp
SOURCES_C += Pop.cpp
SOURCES_C += Mul.cpp
SOURCES_C += Mod.cpp
SOURCES_C += Dump.cpp
SOURCES_C += Add.cpp
SOURCES_C += Assert.cpp
SOURCES_C += Commands.cpp
SOURCES_C += Div.cpp

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
SRCS_C = $(addprefix $(DIR_C)/,$(SOURCES_C))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))
OBJS_C = $(addprefix $(DIR_O)/,$(SOURCES_C:.cpp=.o))
 
all: $(NAME)

$(NAME): $(OBJS_C) $(OBJS)
	$(CC) $(OBJS_C) $(OBJS) -I $(DIR_H) $(FLAGS) -o $(NAME)

$(DIR_O)/%.o: $(DIR_C)/%.cpp
	@mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(DIR_H) -o $@ -c $<

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	@mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(DIR_H) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_C)
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
