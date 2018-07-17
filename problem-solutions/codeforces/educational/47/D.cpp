#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100005;
int n, m;
vector<ii> ans;
set<int> vis[N];

int main(void){
	scanf("%d%d", &n, &m);

	if(m < n-1){
		printf("Impossible\n");
		return 0;
	}

	for(int i = 2; i <= n and ans.size() < m; i++){
		ans.pb(ii(1, i));
	}

	for(int i = 2; i < n; i++){
		if(vis[i].size() == 0){
			for(int j = i; j <= n; j += i){
				vis[j].insert(i);
			}
		}
	}

	for(int i = 2; i < n; i++){
		for(int j = i+1; j <= n; j++){
			bool ok = 1;
			for(int x : vis[i]){
				if(vis[j].count(x)){
					ok = 0;
					break;
				}
			}

			if(ok and ans.size() < m){
				// printf("%d %d\n", i, j);
				ans.pb(ii(i,j));
			}
		}

		if(ans.size() == m) break;
	}

	if(ans.size() == m){
		printf("Possible\n");
		for(int i = 0; i < ans.size(); i++){
			printf("%d %d\n", ans[i].fi, ans[i].se);
		}
	}
	else{
		printf("Impossible\n");
	}

	return 0;
}