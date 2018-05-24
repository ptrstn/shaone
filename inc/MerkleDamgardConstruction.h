#pragma once

#include "MessageSchedule.h"
#include "SHA1_Hash.h"

class MerkleDamgardConstruction{
private:
    SHA1_Hash round(SHA1_Hash input, Word word); //4 stages á 20 rounds

    std::string mOriginalMessage;
    MessageSchedule mMessageSchedule;
    int mRoundCounter;
    SHA1_Hash mCurrentHash;

};