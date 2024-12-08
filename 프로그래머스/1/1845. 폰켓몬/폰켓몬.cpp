#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int candidate_max = nums.size()/2;
    
    sort(nums.begin(), nums.end());
    
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int candidate = nums.size();
    
    if(candidate)
    
    return candidate<=candidate_max?candidate:candidate_max;
}