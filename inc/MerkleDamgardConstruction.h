#pragma once

#include <iostream>
#include "MessageSchedule.h"
#include "SHA1_Hash.h"

class MerkleDamgardConstruction{
public:
    explicit MerkleDamgardConstruction(const MessageBlock& messageBlock);
    MerkleDamgardConstruction & update(const MessageBlock& messageBlock);
    SHA1_Hash sha1_hash() const;
    void print() const {
        for(int i = 0; i < 80; i++){
            std::cout << i << ": " << mMessageSchedule[i] <<std::endl;
        }
    }

private:
    MerkleDamgardConstruction& nextRound();

    MessageSchedule mMessageSchedule;
    int mRoundCounter = 0;
    SHA1_Hash mLastHash = SHA1_Hash{0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    SHA1_Hash mCurrentHash;

};