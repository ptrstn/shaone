#include <bitset>
#include <cassert>
#include "SHA1.h"
/*
SHA1::SHA1(const std::string &message) : mOriginalMessage(message){
    for(int i = 0; i < message.length()/64; i++){
        mMessageBlocks.push_back(MessageBlock{message.substr(i*512, 512)});
    }
    if(message.length() % 64 != 0){
        //TODO: do padding
    }
}
*/
SHA1::SHA1(const std::string &message) {
    std::string paddedMessage = message;
    paddedMessage += (char)(0B10000000); //add binary 1
    while(paddedMessage.length() % 64 != 56){ //add binary 0 until length is 56
        paddedMessage += (char)(0B00000000);
    }

    uint64_t number=message.length() << 3; //length in bit

    for(size_t i = 0; i < 8; i++) { //append length of original message to paddedMessage char wise
        paddedMessage += (char) (number >> (7-i) * 8);
    }

    assert(paddedMessage.length() % 64 == 0);

    for(size_t i = 0; i < paddedMessage.length()/64; i++){ //create MessageBlocks
        std::string tmp = "";
        for(size_t j = 64*i; j < 64*i + 64; j ++){
            tmp += paddedMessage[j];
        }

        mMessageBlocks.push_back(MessageBlock{tmp});
    }

    MerkleDamgardConstruction merkle {mMessageBlocks[0]};
    for(size_t i = 1; i < mMessageBlocks.size(); i++){
        merkle.update(mMessageBlocks[i]);
    }
    std::cout << "SHA-1 Hash: " << merkle.sha1_hash() << std::endl;

    mHash = merkle.sha1_hash();
    //merkle.print();
    //std::cout << "SHA-1 Hash:" << merkle.sha1_hash() << std::endl;
}

SHA1_Hash SHA1::hash() const {
    return mHash;
}
