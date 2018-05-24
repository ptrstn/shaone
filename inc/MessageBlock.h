#pragma once
#include <string>

// 512 Bit, if bigger then it needs to be split, if less then needs to be padded
class MessageBlock {
public:
    explicit MessageBlock(const std::string &message);

private:
    std::string mMessage;
};
