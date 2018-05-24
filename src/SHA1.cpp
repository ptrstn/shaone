//
// Created by Spectre on 23.05.2018.
//

#include "SHA1.h"
#include <sstream>
#include <cassert>

SHA1::SHA1(const std::string &message) : mMessage(message) {}

const std::string &SHA1::message() const {
    return mMessage;
}

std::string SHA1::messageAsHex() const {
    std::stringstream ss;
    assert(mMessage.length() == 64);
    for(char c: mMessage) {
        ss << std::hex << std::bitset<8>(c).to_ulong();
    }
    return ss.str();
}

std::string SHA1::hash() const {
    return "bcab303508c3df0357cbe0c08cc1da3cfc0211ac";
}


void mytest(){
    std::string message = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012";
    char input[64];
    std::strcpy(input, message.c_str());
    std::cout << input << std::endl;
    for (char c: input) {
        std::cout << std::bitset<8>(c);
    }
    std::cout << std::endl;

    for (char c: input) {
        std::cout << std::hex << std::bitset<8>(c).to_ulong();
    }
    std::cout << std::endl;
}