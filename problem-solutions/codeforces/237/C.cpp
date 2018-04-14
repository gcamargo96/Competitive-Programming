#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, k;
vi adj[N];
int dist[N];
vector<ii> v;

int main(void){
	scanf("%d%d", &n, &k);

	int v0 = 0, cnt0 = 0;
	// priority_queue<ii> pq;
	for(int i = 1; i <= n; i++){
		scanf("%d", &dist[i]);
		v.pb(ii(dist[i], i));
		// pq.push(ii(-d[i], i));

		if(dist[i] == 0){
			cnt0++;
			v0 = i;
		}
	}

	if(cnt0 != 1){
		printf("-1\n");
		return 0;
	}

	sort(v.begin(), v.end());

	int j = 0;
	vector<ii> ans;
	for(int i = 1; i < n; i++){
		while(dist[v[j].se] < dist[v[i].se]-1 or (dist[v[j].se] == dist[v[i].se]-1 and adj[v[j].se].size() == k)){
			j++;
		}
		if(dist[v[j].se] == dist[v[i].se]-1){
			adj[v[i].se].pb(v[j].se);
			adj[v[j].se].pb(v[i].se);
			ans.pb(ii(v[i].se, v[j].se));
		}
		else{
			// printf("deu ruim em %d %d\n", v[i].se, v[j].se);
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	// printf("\n");

	return 0;
}