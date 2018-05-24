#pragma once

#include <string>
#include <Word.h>
#include "MessageBlock.h"

class MessageSchedule {
public:
   MessageSchedule(MessageBlock message); // 512 Bits x_i
    // 0 ... 79
    //Word getWordsForStage(unsigned int n /*1 ... 4*/);
    Word getWord(unsigned int n );
    Word operator[](std::size_t idx) const;
private:
    MessageBlock mMessage;
};
