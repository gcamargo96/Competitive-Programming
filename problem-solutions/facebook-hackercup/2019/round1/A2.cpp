#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 55, oo = 0x3f3f3f3f;
int dist[N][N];

int main()
{
	int t, tc = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		memset(dist, 0x3f, sizeof(dist));
		for (int i = 1; i <= n; i++)
			dist[i][i] = 0;
		vector<tuple<int, int, int>> e;
		for (int i = 0; i < m; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			dist[a][b] = dist[b][a] = w;
			e.eb(a, b, w);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}
		printf("Case #%d: ", tc++);
		bool ok = true;
		for (auto edg : e)
		{
			int a, b, w;
			tie(a, b, w) = edg;
			if (dist[a][b] != w)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
			printf("Impossible\n");
		else
		{
			printf("%d\n", (int)e.size());
			for (auto edg : e)
				printf("%d %d %d\n", get<0>(edg), get<1>(edg), get<2>(edg));
		}
	}
	return 0;
}

