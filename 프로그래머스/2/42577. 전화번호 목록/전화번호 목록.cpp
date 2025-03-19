#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrefix(string prefix, string base){
    for(int i=0;i<prefix.length();i++){
        if(prefix[i]!=base[i])
            return false;
    }
    
    return true;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size()-1;i++){
        // phone_book[i]이 phone_book[i+1]의 접두사인지 판단
        if(isPrefix(phone_book[i], phone_book[i+1])==true){
            return false;
        }
    }
    
    return true;
}