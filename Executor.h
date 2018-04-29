#ifndef WIND_EXECUTOR_H
#define WIND_EXECUTOR_H

#include <stdio.h>
#include "WindObject.h"
#include "Instruction.h"

#define WindExecutor_INS_SIZE 4000

#define WindExecutor_INS_SPACE(exec) (exec->insEnd - exec->insMark)

#define WindExecutor_HAS_SPACE(exec, space) (exec->insEnd - exec->insMark) > space

#define WindExecutor_OBJ_TYPE(exec) exec->object->type

#define WindExecutor_DEREF_INS(exec, type) *((type*)(exec->insMark))

#define WindExecutor_INC_IEND(exec, amount) exec->insMark += amount

#define WindExecutor_RESET_INS(wExec) wExec->insMark = wExec->instructions

#define WindExecutor_INIT(name) \
        WindExecutor name; \
        name.insMark = name.instructions; \
        name.insEnd = name.insMark + WindExecutor_INS_SIZE; \
        name.object.type = WindType_None; \
        name.state = ExecutorState_Translate; \
        name.lastIns = WindInstruc_Nil; \
        name.errMode = ExecutorError_dead;


enum ExecutorState
{
        ExecutorState_Translate,
        ExecutorState_Transition,
        ExecutorState_Execution,
        ExecutorState_Done // for end of current source code reached
};

typedef enum ExecutorState ExecutorState;


typedef enum
{
        ExecutorError_dead,
        ExecutorError_active
} ExecutorError;

// top level translation struct
// keeps track of the state of Wind execution, objects, and states
struct WindExecutor
{
        unsigned char instructions[WindExecutor_INS_SIZE];
        char err[256];
        unsigned char* insMark;
        unsigned char* insEnd;
        WindObject object;
        ExecutorState state;
        ExecutorError errMode;
        WindInstruc lastIns;
};

typedef struct WindExecutor WindExecutor;




#endif
