#include <cstdio>

char a[2050][2050];
int nxt_left[2050], nxt_right[2050];
int nxt_up[2050], nxt_down[2050];

void update_left(int i, int j)
{
	while (a[i][nxt_left[i]] == '.' && nxt_left[i] <= nxt_right[i])
	{
		nxt_left[i]++;
	}
}

void update_right(int i, int j)
{
	while (a[i][nxt_right[i]] == '.' && nxt_left[i] <= nxt_right[i])
	{
		nxt_right[i]--;
	}
}

void update_up(int i, int j)
{
	while (a[nxt_up[j]][j] == '.' && nxt_up[j] <= nxt_down[j])
	{
		nxt_up[j]++;
	}
}

void update_down(int i, int j)
{
	while (a[nxt_down[j]][j] == '.' && nxt_up[j] <= nxt_down[j])
	{
		nxt_down[j]--;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	
	for (int i = 0; i < n; ++i)
	{
		nxt_left[i] = 0;
		nxt_right[i] = m - 1;
		update_left(i, 0);
		update_right(i, m - 1);
	}
	for (int i = 0; i < m; ++i)
	{
		nxt_up[i] = 0;
		nxt_down[i] = n - 1;
		update_up(0, i);
		update_down(0, i);
	}
	
	int oldans = -1;
	int ans = 0;
	while (oldans != ans)
	{
		oldans = ans;
		
		for (int i = 0; i < n; ++i)	
			for (int j = 0; j < m; ++j)
			{
				char dir = a[i][j];
				if (dir == 'W' && nxt_left[i] == j)
				{
					++ans;
					a[i][j] = '.';
					update_left(i, j);
				}
				if (dir == 'E' && nxt_right[i] == j)
				{
					++ans;
					a[i][j] = '.';
					update_right(i, j);
				}
				if (dir == 'N' && nxt_up[j] == i)
				{
					++ans;
					a[i][j] = '.';
					update_up(i, j);
				}
				if (dir == 'S' && nxt_down[j] == i)
				{
					++ans;
					a[i][j] = '.';
					update_down(i, j);
				}
				if (nxt_left[i] == j)
				{
					update_left(i, j);
				}
				if (nxt_right[i] == j)
				{
					update_right(i, j);
				}
				if (nxt_up[j] == i)
				{
					update_up(i, j);
				}
				if (nxt_down[j] == i)
				{
					update_down(i, j);
				}
			}
	}
	printf("%d\n", ans);
	return 0;
}
