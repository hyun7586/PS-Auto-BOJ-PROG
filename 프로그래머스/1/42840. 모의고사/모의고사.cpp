#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    int n=answers.size();
    vector<int> answer={0, 0, 0};
    
    vector<int> s1;
    vector<int> s2;
    vector<int> s3;
    
    for(int i=0;i<n;i++){
        // s1
        s1.push_back(i%5+1);
        
        // s2
        switch(i%8){
            case 0:
                s2.push_back(2);
                break;
            case 1:
                s2.push_back(1);
                break;
            case 2:
                s2.push_back(2);
                break;
            case 3:
                s2.push_back(3);
                break;
            case 4:
                s2.push_back(2);
                break;
            case 5:
                s2.push_back(4);
                break;
            case 6:
                s2.push_back(2);
                break;
            case 7:
                s2.push_back(5);
                break;
        }
        
        // s3
        switch(i%10){
            case 0:
                s3.push_back(3);
                break;
            case 1:
                s3.push_back(3);
                break;
            case 2:
                s3.push_back(1);
                break;
            case 3:
                s3.push_back(1);
                break;
            case 4:
                s3.push_back(2);
                break;
            case 5:
                s3.push_back(2);
                break;
            case 6:
                s3.push_back(4);
                break;
            case 7:
                s3.push_back(4);
                break;
            case 8:
                s3.push_back(5);
                break;
            case 9:
                s3.push_back(5);
                break;
        }
    }
    
    for(int i=0;i<n;i++){
        if(s1[i]==answers[i])
            answer[0]+=1;
        if(s2[i]==answers[i])
            answer[1]+=1;
        if(s3[i]==answers[i])
            answer[2]+=1;
    }
    
    int max_value = *max_element(answer.begin(), answer.end());
    vector<int> result;
    
    for(int i=0;i<3;i++)
        if(max_value==answer[i])
            result.push_back(i+1);
    
    return result;
}