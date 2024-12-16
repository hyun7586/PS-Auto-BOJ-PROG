#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_value =0, max_j=0;
    
    for(int i=0;i<sizes.size();i++){
        for(int j=0;j<2;j++){
            if(max_value<sizes[i][j])
            {
                max_value=sizes[i][j];
                max_j=j;
            }
        }
    }
    
    for(auto & each : sizes){
        if(max_j==0 && each[0]<each[1] || max_j==1 && each[0]>each[1])
        {
            int temp = each[0];
            each[0]=each[1];
            each[1]=temp;
            
        } 
    }
    
    int other_max_value=0;
    for(int i=0;i<sizes.size();i++){
        if(other_max_value<sizes[i][1-max_j])
            other_max_value=sizes[i][1-max_j];
    }
    
    int answer = max_value * other_max_value;
    
    return answer;
}