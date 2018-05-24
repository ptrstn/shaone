#pragma once
#include <string>

// 512 Bit, if bigger then it needs to be split, if less then needs to be padded
// will be passed to MessageSchedule and split there into 80 Words (16 directly, rest shuffled)
class MessageBlock {
public:
    explicit MessageBlock(const std::string& message);
    const std::string& str() const;

private:
    std::string mMessage;
};
