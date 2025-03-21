#include <bits/stdc++.h>
using namespace std;

int N, M;

void func(int n, vector<int> sequence);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> ary;
    func(1, ary);

    return 0;
}

void func(int n, vector<int> sequence)
{
    if (n > M)
        return;

    if (n == 1)
    {
        for (int i = 1; i <= N; i++)
        {
            sequence.push_back(i);

            if (n == M)
            {
                for (int i = 0; i < sequence.size(); i++)
                    cout << sequence[i] << " ";
                cout << '\n';
            }
            else
            {
                func(n + 1, sequence);
            }

            sequence.pop_back();
        }
    }
    else
    {
        int i = sequence.back();
        for (i; i <= N; i++)
        {
            sequence.push_back(i);

            if (n == M)
            {
                for (int i = 0; i < sequence.size(); i++)
                    cout << sequence[i] << " ";
                cout << '\n';
            }
            else
            {
                func(n + 1, sequence);
            }

            sequence.pop_back();
        }
    }
}