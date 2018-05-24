#pragma once

#include <string>
#include <vector>
#include "SHA1_Hash.h"
#include "MerkleDamgardConstruction.h"
#include "MessageBlock.h"

class SHA1{
public:
    explicit SHA1(const std::string& message); //split message in Message Blocks and feed into Merkle
    //SHA1_Hash hash() const;
private:
    std::vector<MessageBlock> mMessageBlocks;
    std::string mOriginalMessage;
};