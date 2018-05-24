#pragma once

#include <string>
#include <Word.h>
#include <vector>
#include "MessageBlock.h"

class MessageSchedule {
public:
    MessageSchedule(MessageBlock message); // 512 Bits x_i
    Word operator[](std::size_t idx) const;
private:
    MessageBlock mMessage;
    std::vector<Word> mWords;
};
