#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"
#include "Person.h"

#include <cstdio>

#include <cstdio>

#include <cstdio>

#include <cstdio>

#include <cstdio>


int main() {
    int x = 10; // x Memory(0x0001,10)
    int * y = &x; //y Memory(0x0002,0x0001)

    int &z = x;

    std::cout << &x << "\n"; //印出 0x0001
    std::cout << y << "\n"; //印出 0x0001
    std::cout << &y << "\n";//印出 0x0002
    std::cout << *y << "\n"; //印出 10
}



