/*************************************************************************
    > File Name: WordChanger.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月14日 星期五 09时14分19秒
 ************************************************************************/

/* ***********
 * 单词转换
 * file1为转换规则，file2为需要转换的文本，打印转换前后的文本
 * 根据file1建立map，读取并转换file2
 * *******/
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

// 读取map
map<string, string> ReadFileMap(const string &filename) {
    ifstream pf1(filename);
    if(!pf1) {
       throw invalid_argument("规则文件不存在");
    }
    map<string, string> ruleMap;
    string index;
    string value;
    while(pf1 >> index && getline(pf1, value)) {
        if(value.empty()) {
            cout << "警告：" << index << "转换规则为空" << endl;
        }
        ruleMap[index] = value.substr(1);
    }
    return ruleMap;
}

// 单词替换
string ReplaceWords(const map<string, string> &ruleMap, const string &lineString) {
    istringstream line(lineString);
    ostringstream newLine;
    string word;
    if(line >> word) {
        newLine << ruleMap.at(word);
    }
    while(line >> word) {
        newLine << " " << ruleMap.at(word);
    }
    return newLine.str();
}

// 文件处理
void WordChanger(const string &file1, const string &file2) {
    map<string, string> ruleMap = ReadFileMap(file1);
    // 打印原文本和替换后文本
    ifstream pf2(file2);
    if(pf2) {
        vector<string> text;
        string lineString;
        cout << "原始文本为：" << endl;
        while(getline(pf2, lineString)) {
            cout << lineString << endl;
            text.push_back(ReplaceWords(ruleMap, lineString));
        }
        cout << "\n替换后文本为：" << endl;
        for(auto line: text) {
            cout << line << endl;
        }
       
    }
    else {
       throw invalid_argument("文本文件不存在");
    }
}

int test(void) {
    try {
        WordChanger("./转换规则.txt", "./需转换文本.txt");
    }
    catch(invalid_argument err) {
        cout << "文件错误： " << err.what() << endl;
    }
    catch(out_of_range err) {
        cout << "关键字不存在： " << err.what() << endl;
    }
    return 0;
}
