/*************************************************************************
    > File Name: VectorStack.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月28日 星期二 14时47分54秒
 ************************************************************************/

#include <iostream>
#include "VectorStack.h"

int VectorStack::count = 0;

void VectorStack::print() const{
    std::cout << std::string(20, '-') << std::endl;
    for(auto i: stack) {
        std::cout << i << std::endl;
    }
    std::cout << std::string(20, '-') << std::endl;
}

void VectorStack::print(int n) const{
    auto beg = stack.begin();
    auto end = beg + n;
    std::cout << std::string(20, '-') << std::endl;
    for(; beg < end; ++beg) {
        std::cout << *beg << std::endl;
    }
    std::cout << std::string(20, '-') << std::endl;
}


