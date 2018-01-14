#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100005;
set<ii> ld, lu, rd, ru;
int n;
ii p[N];
int dist[N];

void prim(int u){
	memset(dist, INF, sizeof dist);
	dist[u] = 0;
	priority_queue<ii> pq;
	pq.push(mp(0, u));

	while(!pq.empty()){
		int u = pq.top().se;
		int d = pq.top().fi;
		pq.pop();

		
	}
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &p[i].fi, &p[i].se);
		ld.insert(mp(p[i]fi + ))
	}	

	return 0;
}

