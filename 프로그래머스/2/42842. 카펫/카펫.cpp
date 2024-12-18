#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> candidates;
    vector<int> answer;
    
    int n=brown+yellow;
    
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            candidates.push_back(make_pair(n/i, i));
    
    for(auto each : candidates){
        int width = each.first;
        int height = each.second;
        
        int outers = 2*(width+height)-4;
        int inners = (width-2)*(height-2);
        
        if(outers==brown && inners==yellow){
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}