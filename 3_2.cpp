/*Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду.*/
#include<bits/stdc++.h>
using std::vector;
int main()
{
	int n;
	std::cin >> n;
	int t = sqrt(2 * n);//легко доказать что к-во слагаемых меньше чем t ,где слагаемые к-во кубиков в каждом слое
	vector< vector<long long> >S(n + 1, vector<long long>(t + 1, 0));

	S[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int l = sqrt(2 * i);
		for (int j = 1; j <= l; ++j)
		{
			S[i][j] = S[i - j][j] + S[i - j][j - 1];
		}
	}
	long long s = 0;
	for (int i = 1; i <=t; i++)
	{
		s += S[n][i];
	}
	std::cout << s << std::endl;
	system("pause");
	return 0;
}
