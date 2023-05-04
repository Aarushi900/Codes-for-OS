#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int alloc[n][m] = {{1, 1, 1}, {0, 1, 1}, {1, 0, 0}};
	int max[n][m] = {{1, 2, 2}, {0, 1, 1}, {2, 1, 0}};
	int available[m] = {0, 0, 0};
	int need[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int ind = 0, f[n], flag = 0;
	for (int k = 0; k < n; k++)
	{
		f[k] = 0;
	}

	int ans[n];
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				flag = 0;
				for (int j = 0; j < m; j++)
				{
					if (need[i][j] > available[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					ans[ind++] = i;
					for (int j = 0; j < m; j++)
					{
						available[j] += alloc[i][j];
					}
					f[i] = 1;
				}
			}
		}
	}
	flag = 1;
	for (int i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
			flag = 0;
			cout << "The given sequence is not safe";
			break;
		}
	}
	if (flag == 1)
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (int i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[n - 1] << endl;
	}
	return (0);
}
