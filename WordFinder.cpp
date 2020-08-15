/*************************************************************************
    > File Name: WordFinder.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月15日 星期六 11时44分47秒
 ************************************************************************/

/* ***********
 * 文本查询程序
 * 读入文本文件，给定一个查找的单词
 * 找到则列出行号和该行的内容，查找word输入格式如下：
 * * *****
 * * word出现112次：
 * *    （第1行）   ... ...
 * *    （第12行）  ... ...
 * *    ... ...
 * * *****
 * 如果在一行中出现多次，则统计数量但该行只输出一次
 * ***********/
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// 使用一个vector<string>存储输入的文本
// 使用set存储行号
// 这个版本先忽略标点符号的影响

// 打印结果
void SearchResultPrint(const vector<string> &text, const string &word, const set<int> &linesNum, int count) {
    cout << "元素 " << word << " 出现 " << count << "次：" << endl;
    for(auto i: linesNum) {
        cout << "\t(line " << i+1 << " )\t" << text[i] << endl;
    }
}

// 查找程序
// 输入文本和单词，使用stringIO操作每一行，使用set存储行号
// 使用计数器计数出现次数
// 查找完成后打印
void SearchVector(const vector<string> &text, const string &word) {
    size_t count = 0;
    int lineNum = 0;
    set<int> lineSet;
    for(auto line: text) {
        auto beg = line.begin();
        while(1) {
            beg = search(beg, line.end(), word.begin(), word.end());
            if(beg == line.end()) { // 未查找到
                break;
            }
            beg += word.size();     // 跳过查找到的部分
            ++count;                // 计数
            lineSet.insert(lineNum);
        }
        ++lineNum;
    }
    SearchResultPrint(text, word, lineSet, count);
}

// 读入IO对象到容器中
void ReadToVector(istream &ip, vector<string> &text) {
    string line;
    while(getline(ip, line)) {
        text.push_back(line);
    }
}


// 输入文件名查找，或直接输入字符串
// 将文件或字符串读入到字符串容器中，并调用查找程序
void WordFinder(const string &str, const string &word) {
    vector<string> text;
    if(string(str) == "STD_IN") {     // 从标准输入读入
        ReadToVector(cin, text);
    }
    else if(string(str) == "STRING") {     // 从标准输入读入
        istringstream textStringIO(str);
        ReadToVector(textStringIO, text);
    }
    else {      // 从文件读入
        ifstream fp(str);
        if(!fp) {
            throw invalid_argument("文件不存在");
        }
        ReadToVector(fp, text);
    }
    SearchVector(text, word);
}

// 主程序
int main(int argc, char **argv) {
    string filename("./单词查找.txt");
    string word("vim");
    int fromFile = 1;
    for(auto i = 0; i < (argc - 1)/2; i++) {
        auto option = string(argv[i*2 + 1]);
        if(option == "-f") {
            filename = argv[2*i + 2];
        }
        else if(option == "-w") {
            word = argv[2*i + 2];
        }
        else {
            cout << "WARRING: option \"" << option << "\"未定义" << endl;
        }
    }
    try {
        WordFinder(filename, word);
    }
    catch (invalid_argument err){
        cout << "ERROR: " << err.what() << endl;
    }
    return 0;
}

