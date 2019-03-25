#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10005;
int n, m;
int c[N];
vector<ii> adj[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main(void){
	// freopen("dwarf.in", "r", stdin);
	// freopen("dwarf.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		pq.push(ii(c[i], i+1));
	}

	int a, x, y;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &x, &y);
		adj[x].eb(y,a);
		adj[y].eb(x,a);
	}

	while(!pq.empty()){
		int item = pq.top().se;
		int cost = pq.top().fi;
		pq.pop();

		if(c[item] < cost) continue;

		for(int i = 0; i < adj[item].size(); i++){
			int other = adj[item][i].fi;
			int crafted = adj[item][i].se;

			if(c[item] + c[other] < c[crafted]){
				c[crafted] = c[item] + c[other];
				pq.push(ii(c[crafted], crafted));
			}
		}
	}

	printf("%d\n", c[1]);

	return 0;
}