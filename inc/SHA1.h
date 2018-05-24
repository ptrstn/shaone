#pragma once

class SHA1{
public:
    SHA1(std::string message); //split message in Message Blocks and feed into Merkle
    SHA1_Hash hash() const;
private:
    MerkleDamgardConstruction mMerkle;
    std::string message;
};