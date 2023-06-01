#include <iostream>
using namespace std;
int main()
{
	int n, m, i, j, k;
	cin >> n; // no. of processes
	cin >> m; // no. of resources
	int alloc[n][m] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 3}, {2, 1, 1}, {0, 0, 2}};
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cin>>alloc[i][j];
	// 	};
	// };
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<alloc[i][j];
	// 	};
	// 	cout<<"\n";
	// };
	int request[n][m] = {{0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2}};

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cin>>request[i][j];
	// 	};
	// };

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<request[i][j];
	// 	};
	// 	cout<<"\n";
	// };
	int avail[m] = {0, 0, 0};
	int f[n], ans[n], ind = 0;
	int x = 0;
	for (k = 0; k < n; k++)
	{
		for (int j = 0; j < m; j++)
		{
			if (alloc[i][j] == 0)
			{
				x = 0;
			}
			else
				x = 1;
		}
		if (x == 1)
		{
			f[k] = 0;
		}
		else
		{
			f[k] = 1;
		}

		cout << k << f[k] << "\n";
	}
	//	int need[n][m];
	//	for (i = 0; i < n; i++) {
	//		for (j = 0; j < m; j++)
	//			need[i][j] = max[i][j] - alloc[i][j];
	//	}
	int y = 0;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (request[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	// To check if sequence is safe or not
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
		for (i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[n - 1] << endl;
	}
	return (0);
}
