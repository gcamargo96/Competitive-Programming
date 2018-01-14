#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 5002;
struct query{
	int u, v;
	ll w;

	bool operator<(const query& b) const{
		if(u == b.u) return v < b.v;
		return u < b.u;
	}
};

int n, m, t, maxtam = 0;
int cnt[N], pai[N];
ll temp[N];
query q[N];


int main(void){
	scanf("%d%d%d", &n, &m, &t);

	For(i,0,m){
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].w);
	}

	sort(q, q+m);

	int u, v, w;
	For(i,0,m){
		u = q[i].u, v = q[i].v, w = q[i].w;
		if(cnt[u]+1 > cnt[v]){
			
		}
	}

	return 0;
}

