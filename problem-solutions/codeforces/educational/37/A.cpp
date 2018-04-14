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

const int N = 202;
int t, n, k;
bool vis[N], v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &n, &k);

		int x, ans = 0;
		queue<ii> q;
		for(int i = 0; i < k; i++){
			scanf("%d", &x);
			vis[x] = 1;
			q.push(ii(x, 1));
		}

		while(!q.empty()){
			int x = q.front().fi;
			int temp = q.front().se;
			q.pop();

			ans = max(ans, temp);
			if(x-1 > 0 and !vis[x-1]){
				vis[x-1] = 1;
				q.push(ii(x-1, temp+1));
			}
			if(x+1 <= n and !vis[x+1]){
				vis[x+1] = 1;
				q.push(ii(x+1, temp+1));
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}