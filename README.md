[![Build Status](https://travis-ci.com/ptrstn/shaone.svg?branch=master)](https://travis-ci.com/ptrstn/shaone)
# ShaOne

A very simple implementation of the (broken) SHA-1 Hashing Algorithm in C++.

This repository does not claim to be particularly efficient. It is used for educational purposes only.

Do NOT use this in production as SHA-1 was broken by Google in 2017. See https://shattered.io/ for details.

## Example

```C++
#include <iostream>
#include "SHA1.h"

int main() {
    SHA1 s{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    std::cout << s.hash() << std::endl;
    return 0;
}
```

Output:
```bash
faa62a12e3969824a7daf66b62c939dc0324b6b8
```