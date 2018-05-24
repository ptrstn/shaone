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
    SHA1_Hash round(SHA1_Hash input, Word word); //4 stages á 20 rounds

    MessageSchedule mMessageSchedule;
    int mRoundCounter = 0;
    SHA1_Hash mCurrentHash;

};