#include <bitset>
#include <iostream>
#include "MessageSchedule.h"
#include "MessageBlock.h"

MessageSchedule::MessageSchedule(MessageBlock message) : mMessage{message}{
    //split message into Words
    for(int i = 0; i < 16; i++) {
        std::bitset<8> b1 = message.str()[i*4 + 0];
        std::bitset<8> b2 = message.str()[i*4 + 1];
        std::bitset<8> b3 = message.str()[i*4 + 2];
        std::bitset<8> b4 = message.str()[i*4 + 3];
        std::bitset<32> word(b1.to_string()+b2.to_string()+b3.to_string()+b4.to_string());
        mWords.push_back(Word(static_cast<uint32_t>(word.to_ulong())));
    }

    for(int j = 16; j < 80; j++) {
        mWords.push_back((mWords[j-16] ^ mWords[j-14] ^ mWords[j-8] ^ mWords[j-3]).rotateLeft(1));
    }

    std::cout <<"\nMessage Scheduler:\n";
    for(int i = 0; i <80; i++){
        std::cout << "i=" << i << " :" << mWords[i] << std::endl;
    }
}

Word MessageSchedule::operator[](std::size_t idx) const {
    return mWords[idx];
}
