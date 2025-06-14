#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int n);
int cnt;


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		cnt = 0;
		DFS(n);
		printf("%d\n", cnt);
	}
	
	return 0;
}

void DFS(int n)
{
	//DFS
	//parameter는 앞으로 남은 계단 수
	if (n < 0)
		return;
	if (n == 0)
	{
		cnt += 1;
		return;
	}
	
	DFS(n - 1);
	DFS(n - 2);
	DFS(n - 3);
}