#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> counts;
    
    for(auto each : participant){
        counts[each]++;
    }
    
    for(auto each : completion){
        counts[each]--;
    }
    
    for(auto each : counts){
        if(each.second!=0){
            return each.first;
        }
    }
    
}