#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp(const int& a, const int& b) {
  string sa = to_string(a);
  string sb = to_string(b);

  return stoi(sa + sb) > stoi(sb + sa);
}

string solution(vector<int> numbers) {
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    string answer="";
    
    for(auto each : numbers){
        if(answer=="" && each ==0)
            continue;
        answer+=to_string(each);
    }
    
    if(answer=="")
        return "0";
    
    return answer;
}