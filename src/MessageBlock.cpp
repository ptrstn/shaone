#include <cassert>
#include <iostream>
#include "MessageBlock.h"

MessageBlock::MessageBlock(const std::string& message) : mMessage(message) {
    assert(message.length()==64);
}

const std::string &MessageBlock::str() const {
    return mMessage;
}

