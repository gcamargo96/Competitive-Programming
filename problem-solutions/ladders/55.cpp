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

struct node{
	int deg, s;
};

const int N = 66000;
int n;
node nodes[N];
queue<int> q;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &nodes[i].deg, &nodes[i].s);
		if(nodes[i].deg == 1) q.push(i);
	}

	vector<ii> res;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		int v = nodes[u].s;	
		if(nodes[u].deg > 0 and nodes[v].deg > 0){
			res.pb(mp(u,v));
			nodes[v].s ^= u;
			nodes[v].deg--;
			if(nodes[v].deg == 1) q.push(v);
		}
	}

	printf("%d\n", res.size());
	For(i,0,res.size()){
		printf("%d %d\n", res[i].fi, res[i].se);
	}

	return 0;
}

