#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>ary(n + 1);
	ary[1] = 0;		 ary[2] = 1;	ary[3] = 1;
	int x, y, z;
	if ( n == 1 || n == 2 || n == 3)
		printf("%d\n", ary[n]);
	else
	{
		for (int i = 4; i <= n; i++)
		{
			x = 2147483647;
			y = 2147483647;
			z = 1 + ary[i - 1];
			if (i % 3 == 0)
				x = ary[3] + ary[i / 3];
			if (i % 2 == 0)
				y = ary[2] + ary[i / 2];

			ary[i] = min(x, min(y, z));
		}
		printf("%d\n", ary[n]);
	}
}