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

const int N = 1002;

struct group{
	int c, p, id;

	bool operator<(const group& b) const{
		return p < b.p;
	}
};

int n, c, k, p, r;
map<int,vector<int>> t;
group g[N];
vector<ii> ans;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &g[i].c, &g[i].p);
		g[i].id = i+1;
	}

	scanf("%d", &k);

	int x;
	For(i,0,k){
		scanf("%d", &x);
		t[x].pb(i+1);
	}

	sort(g, g+n);

	int ac = 0, money = 0;
	for(int i = n-1; i >= 0; i--){
		auto it = t.lower_bound(g[i].c); // iterador do map de mesas
		if(it != t.end()){
			vector<int>& v = it->se;
			int table = v[v.size()-1];
			v.pop_back();

			ans.pb(mp(g[i].id, table));
			ac++;
			money += g[i].p;

			if(v.size() == 0){
				t.erase(it->fi);
			}
		}
	}

	printf("%d %d\n", ac, money);

	For(i,0,ans.size()){
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}

	return 0;
}

