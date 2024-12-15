#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> answer;
    
    for(auto each : commands){
        int i=each[0], j=each[1], k=each[2];
        
        for(int p=i-1;p<j;p++)
            temp.push_back(array[p]);
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k-1]);
        temp.clear();
    }
    
    return answer;
}