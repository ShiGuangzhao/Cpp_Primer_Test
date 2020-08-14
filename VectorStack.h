/*************************************************************************
    > File Name: VectorStack.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月28日 星期二 14时30分12秒
 ************************************************************************/

#ifndef _VECTORSTACK_H_C
#define _VECTORSTACK_H_C
#include <vector>
using std::vector;

class VectorStack {
private:
    vector<int> stack;
    static const int count1 = 1;
    static int count;

public:
    VectorStack() = default;
    VectorStack(int data): stack(vector<int>{data}) {++count; }
    VectorStack(vector<int> v): stack(v) {++count; }
    VectorStack &push(int data) {
        stack.push_back(data);
        return *this;
    }
    inline int pop(void);
    void print() const;
    void print(int n) const;
    static int getCount() {
        return count;
    }
    static int initCount();
};

int VectorStack::pop(void) {
    int ret = *(--stack.end());
    stack.pop_back();
    return ret;
}
#endif /* VECTORSTACK_H_C */
