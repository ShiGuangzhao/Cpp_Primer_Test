/*************************************************************************
    > File Name: main.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月23日 星期四 10时03分59秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
 

#define NDEBUG
#include <cassert>
void testAssert(void) {
    for(auto c: {1, 2, 3, 4, 5}) {
        assert(c < 4);
        cout << c << endl;
    }
}

const int fun(int a) {
    if(a == 0) {
        throw invalid_argument("除数不可为0");
    }
    else {
        return 10/a;
    }
}

void testArray(int (&a)[5]) {
    for(auto i: a) {
        cout << i << endl;
    }
}

void testFun1(int *a) {
    cout << "1\n";
}

void testFun1(const int *a) {
    cout << "const 1\n";
}

#include <initializer_list>
void testVariable(string head, initializer_list<string> list) {
    for(auto i: list) {
        cout << head << ":\t" << i << endl;
    }
}

using uInt = unsigned int;
struct TestClass {
    uInt c;
    uInt a = 11;
    uInt getA() {
        return a;
    }
    void Print() {
        cout << a << endl;
        cout << c << endl;
    }
};

#include "VectorStack.h"
void testClass2() {
    VectorStack stack(vector<int>{1, 2, 4, 5});
    stack.print();
    stack.push(8);
    stack.push(20);
    stack.print();
    cout << VectorStack::getCount() << endl;
    stack.pop();
    stack.print();
    stack.print(1);
    cout << VectorStack::getCount() << endl;
}

void testCin(void) {
    int a;
    cout << cin.goodbit << cin.badbit << cin.eofbit << cin.failbit << cin.rdstate() << endl;
    while(cin >> a) {
        cout << "hhh: " << a << endl;
        // cout << (cin.good()? "true": "false") << endl;
        // cout << (cin.bad()? "true": "false") << endl;
        // cout << (cin.fail()? "true": "false") << endl;
        // cout << (cin.eof()? "true": "false") << endl;
    }
    cout << (cin.good()? "true": "false") << endl;
    cout << (cin.bad()? "true": "false") << endl;
    cout << (cin.fail()? "true": "false") << endl;
    cout << (cin.eof()? "true": "false") << endl;
    // cin.clear();
    // cout << string(20, '-') << endl;
    // cout << (cin.good()? "true": "false") << endl;
    // cout << (cin.bad()? "true": "false") << endl;
    // cout << (cin.fail()? "true": "false") << endl;
    // cout << (cin.eof()? "true": "false") << endl;

    cout << string(20, '-') << endl;
    string b;
    if(cin >> b) {
        cout << "hhh: " << b << endl;
    }
    cout << (cin.good()? "true": "false") << endl;
    cout << (cin.bad()? "true": "false") << endl;
    cout << (cin.fail()? "true": "false") << endl;
    cout << (cin.eof()? "true": "false") << endl;
    cout << cin.goodbit << cin.badbit << cin.eofbit << cin.failbit << cin.rdstate() << endl;
}

#include <fstream>
void testFile(const string &name) {
    ofstream pf(name);
    string word;
    pf.open("a.txt");
    while(cin >> word) {
        pf << word << endl;
    }

}

#include <algorithm>
#include <sstream>
void testStringStream(const string &name) {
    string line;
    int word;
    ofstream pf(name);
    // 对每一行排序后存到文件中
    while(getline(cin, line)) {
        vector<int> temp;
        istringstream Line(line);       // 初始化对象
        while(Line >> word) {
            temp.push_back(word);
        }
        sort(temp.begin(), temp.end());     // 排序，定义在algorithm头文件中
        for(auto i: temp) {
            pf << i << "\t";
        }
        pf << endl;
    }
}

#include <iterator>
void testItreator(void) {
    string str{"hello!!"};
    auto it = std::inserter(str, str.end() - 3);
    // auto it = std::back_inserter(str);
    cout << str << endl;
    it = '?';
    cout << str << endl;
    *it = '$';
    cout << str << endl;
    ++it;
    *it = '@';
    cout << str << endl;
}

// 从文件读入数字，并输出
void testIO_Iterator(void) {
    ifstream fp("a.txt");
    istream_iterator<int> in(fp), eof;
    ostream_iterator<int> out(cout, " ");
    // vector<int> vec(in, eof);
    copy(in, eof, out);
    cout << endl;
}

void testBind(char c, int i) {
    cout << i++ << ": " << c << endl;
}

#include <functional>
void testLambda(void) {
    string s{"hello"};
    int i = 1;
    for_each(s.begin(), s.end(), bind(testBind, std::placeholders::_1, i));
    // for_each(s.begin(), s.end(), \
            // [=](char c) mutable {cout << i++ << ": " << c << endl;});
}


int main(int argc, char *argv[]) {
    testLambda();
    

    // testItreator();
    // testStringStream("test.txt");
    return 0;
}
