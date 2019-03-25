#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define mt make_tuple

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
	// freopen("figure.in", "r", stdin);
	// freopen("figure.out", "w+", stdout);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		if (h < 2 or w < 2)
		{
			printf("Impossible\n");
			if (t) printf("\n");
			continue;
		}

		int maxspots = ((h-2) * (w-2) + 1)/2;
		if (n > maxspots)
		{
			printf("Impossible\n");
			if (t) printf("\n");
			continue;
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 or i == h-1 or j == 0 or j == w-1)
					printf(".");
				else
				{
					if ((i+j)%2 == 0 and n)
					{
						printf("#");
						n--;
					}
					else
						printf(".");
				}
			}
			printf("\n");
		}

		if (t) printf("\n");
	}
	return 0;
}