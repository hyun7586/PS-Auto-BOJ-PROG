#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr;
    vector<int> index_arr;

    // default setting

    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    for (int i = 0; i < M; i++)
        index_arr.push_back(0);
    for (int i = 0; i < N - M; i++)
        index_arr.push_back(1);

    // 반복 : index_arr[i]==0인 index의 숫자만 선택해서 출력함
    do
    {
        for (int i = 0; i < N; i++)
        {
            if (index_arr[i] == 0)
            {
                cout << arr[i] << " ";
            }
        }
        cout << '\n';

    } while (next_permutation(index_arr.begin(), index_arr.end()));

    return 0;
}