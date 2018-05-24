#include <iostream>
#include "SHA1.h"

int main() {
    SHA1 s{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    std::cout << s.hash() << std::endl;
    return 0;
}