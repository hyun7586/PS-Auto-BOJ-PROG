#include <bits/stdc++.h>
using namespace std;

vector<int> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;

        if(temp)
            s.push_back(temp);
        else
            s.pop_back();

    }

    for(int i=0;i<s.size();i++)
        result+=s[i];
    
    cout<<result;
    
    return 0;
}