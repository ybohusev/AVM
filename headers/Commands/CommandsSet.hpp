/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandsList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:26:33 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/26 18:26:35 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_COMMANDSSET_HPP
#define AVM_COMMANDSSET_HPP

#include <map>

enum class eCommandType
{
    UNKNOWN = 0,
    PUSH,
    ADD,
    ASSERT,
    DIV,
    DUMP,
    MOD,
    MUL,
    POP,
    PRINT,
    SUB,
    EXIT
};

const std::map<std::string, eCommandType> gCommandSet = { { "push",    eCommandType::PUSH   },
                                                          { "add",     eCommandType::ADD    },
                                                          { "assert",  eCommandType::ASSERT },
                                                          { "div",     eCommandType::DIV    },
                                                          { "dump",    eCommandType::DUMP   },
                                                          { "mod",     eCommandType::MOD    },
                                                          { "mul",     eCommandType::MUL    },
                                                          { "pop",     eCommandType::POP    },
                                                          { "print",   eCommandType::PRINT  },
                                                          { "sub",     eCommandType::SUB    },
                                                          { "exit",    eCommandType::EXIT   }
};

#endif //AVM_COMMANDSSET_HPP
