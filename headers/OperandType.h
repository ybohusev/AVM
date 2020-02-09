//
// Created by ybohusev on 27.01.2020.
//

#ifndef AVM_OPERANDTYPE_H
#define AVM_OPERANDTYPE_H

#include <map>

enum eOperandType
{
    UNKNOWN = -1,
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

const std::map<std::string, eOperandType> gOperandTypeSet = { { "int8",  Int8   },
                                                          { "int16", Int16  },
                                                          { "int32", Int32  },
                                                          { "float", Float  },
                                                          { "double",Double },
};

#endif //AVM_OPERANDTYPE_H
