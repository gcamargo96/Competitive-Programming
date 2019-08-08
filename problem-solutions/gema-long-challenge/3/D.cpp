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

#define INF 0x3f3f3f3f

const int N = 22;
vi adj[N];
vi path;
ll rnd[N];
ii edges[N];
unordered_set<ll> subtrees;
map<vector<ll>, int> hashToId;
int dist[N];
int n;

void init(){
	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
}

void dfsDist(int v, int p, int d) {
    dist[v] = d;
    for (int to : adj[v]) {
        if (to != p) {
            dfsDist(to, v, d + 1);
        }
    }
}

int getMax() {
    int id, mx = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx) {
            id = i;
            mx = dist[i];
        }
    }
    return id;
}

bool getPath(int u, int to, int pai) {
    if (u == to) {
        path.pb(u);
        return 1;
    }
    path.pb(u);
    for (int v : adj[u]) {
        if (v != pai and getPath(v, to, u)) {
            return 1;
        }
    }
    path.pop_back();
    return 0;
}

ii getCenters(int u) {
    memset(dist, -1, sizeof dist);
    dfsDist(u, -1, 0);
    u = getMax();

    memset(dist, -1, sizeof dist);
    dfsDist(u, -1, 0);
    int to = getMax();
    
    path.clear();
    getPath(u, to, -1);

    if (path.size() % 2 == 0) {
        return ii(path[path.size() / 2 - 1], path[path.size() / 2]);
    } else {
        return ii(path[path.size() / 2], -1);
    }
}

ll dfsHash(int u, int pai) {
    int count = 0;
    for (int v : adj[u]) {
        if (v != pai) {
            count++;
        }
    }

    if(count == 0){
    	vector<ll> vec;
    	hashToId[vec] = 1;
    	return 1;
    }

    vector<ll> child;
    for (int v : adj[u]) {
        if (v != pai) {
            child.pb(dfsHash(v, u));
        }
    }
    sort(child.begin(), child.end());

    if(!hashToId.count(child)){
    	hashToId[child] = hashToId.size()+1;
    }
    ll ans = hashToId[child];

    return ans;
}

int dfsSize(int u, int pai){
	int sz = 1;

	for(int v : adj[u]){
		if(v != pai){
			sz += dfsSize(v, u);
		}
	}

	return sz;
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		u--, v--;
		edges[i] = ii(u,v);
	}

	int up = (1<<n);
	for(int mask = 1; mask < up; mask++){

		// if(mask%1000 == 0) printf("mask = %d\n", mask);
		init();

		vi comp;
		for(int i = 0; i < n; i++){
			if((1<<i) & mask){
				comp.pb(i);
			}
		}

		// printf("size = %d\n", dfsSize(comp[0], -1));

		// if(dfsSize(comp[0], -1) != comp.size()){
		// 	continue;
		// }

		for(int i = 0; i < n-1; i++){
			int u = edges[i].fi, v = edges[i].se;
			if(((1<<u) & mask) and ((1<<v)&mask)){
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}

		ii centers = getCenters(comp[0]);

		ll hash = dfsHash(centers.fi, -1);
		if(centers.se != -1){
			hash = min(hash, dfsHash(centers.se, -1));
		}

		subtrees.insert(hash);
	}

	printf("%d\n", (int) subtrees.size());

	return 0;
}