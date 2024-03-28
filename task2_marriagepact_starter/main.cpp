/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>

std::vector<std::string> split(std::string s);

std::set<std::string> get_applicants(std::string filename) {
    std::set<std::string> applicants;
    std::string line;
    std::ifstream ifs(filename);
    if(ifs.is_open()) {
        while(std::getline(ifs, line)) {
            applicants.insert(line);
            std::cout << line << std::endl;
        }
    }
    return applicants;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    //std::string name;
    std::queue<std::string*> match;
    std::vector<std::string> initials;
    for(auto iter = students.begin(); iter != students.end(); ++iter) {
        initials = split(*iter);
        if(initials[0][0] == 'A' && initials[1][0] == 'C') {
            //push(iter)报错原因：不是将迭代器本身推入队列，而是它指向的字符串的地址
            //我测...网上查看了别人的题解
            //在C++中，std::set 内部存储的元素默认为const
            //会得到一个指向 const 数据的指针（即 const std::string*）
            //但是我们队列的参数类型是<std::string *>，并不是const
            //所以我们要么把指针的const去掉，要么改变函数的返回值参数
            //所以改变指针的const属性
            //const_cast<new_type>(expression)
            match.push(const_cast<std::string*>(&(*iter)));
        }
    }
    return match;
}

std::vector<std::string> split(std::string s) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, ' ')) {
    return_vec.push_back(token);
  }
  return return_vec;
}

int main() {
    std::set<std::string> applicants = get_applicants("/root/CS106L_2024w/task2_marriagepact_starter/students.txt");
    //std::cout << applicants.size() <<std::endl; test
    std::queue<std::string*> matches = find_matches(applicants);
    /*
    //test
    std::cout << "------------------\n";
    while(matches.size() != 0) {
        std::cout << *matches.front() << std::endl;
        matches.pop();
    }
    */

    //任意选里面的人
    if(matches.size() == 0) {
        std::cout << "NO STUDENTFOUND.\n";
    } else {
        int num = random() % matches.size();
        std::string* name;
        while(num != 0) {
            matches.pop();
            --num;
        }
        std::cout << "your best choice is: " << *matches.front() << std::endl;
    }
  
    
    return 0;
}
