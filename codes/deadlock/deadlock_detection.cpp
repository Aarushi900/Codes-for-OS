#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> work{0, 0, 0};
	vector<int> available{0, 0, 0};
	vector<vector<int>> allocated{{0, 1, 0}, {2, 0, 0}, {3, 0, 3}, {2, 1, 1}, {0, 0, 2}};
	vector<vector<int>> request{{0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2}};
	vector<bool> finish(request.size(), false);
	int count = 0;

	for (int i = 0; i < allocated.size(); i++)
	{
		if (all_of(allocated[i].cbegin(), allocated[i].cend(), [](int j)
				   { return j == 0; }))
		{
			finish[i] = true;
			count++;
		}
	}

	int x = 0;
	while (x < finish.size())
	{
		for (int i = 0; i < finish.size(); i++)
		{
			if (finish[i] == false &&
				equal(request[i].begin(), request[i].end(), work.begin(), [](int a, int b) -> bool
					  { return a <= b; }))
			{
				finish[i] = true;
				count++;
				for (int k = 0; k < work.size(); k++)
				{
					work[k] += allocated[i][k];
				}
			}
		}
		x++;
	}

	if (count != finish.size())
	{
		cout << "Deadlock Stage\n";
		cout << "Deadlock states:\n";
		for (int i = 0; i < finish.size(); i++)
		{
			if (finish[i] == false)
				cout << "Process " << i + 1 << "\n";
		}
	}
	else
	{
		cout << "No deadlock state\n";
		for (int i = 0; i < finish.size(); i++)
		{
				cout << "Process " << i + 1 << "\n";
		}
	}
	return 0;
}
