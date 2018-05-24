#pragma once

#include <string>
#include <vector>
#include "SHA1_Hash.h"
#include "MerkleDamgardConstruction.h"
#include "MessageBlock.h"

class SHA1{
public:
    SHA1(std::string message); //split message in Message Blocks and feed into Merkle
    SHA1_Hash hash() const;
private:
    MerkleDamgardConstruction mMerkle;
    std::vector<MessageBlock> messageBlocks;
    std::string message;
};