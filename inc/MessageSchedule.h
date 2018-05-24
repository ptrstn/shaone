#pragma once

#include <string>
#include <Word.h>
#include "MessageBlock.h"

class MessageSchedule {
    MessageSchedule(MessageBlock message); // 512 Bits x_i
    Word getWord(unsigned int n ); // 0 ... 79
    //Word getWordsForStage(unsigned int n /*1 ... 4*/);
private:
    MessageBlock message;
};
