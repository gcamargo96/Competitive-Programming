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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 100005;
int n, k;
int v[N];
bool vis[N];

int main(void){
	scanf("%d%d", &n, &k);

	int g = -1;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i]%k != 0){
			g = v[i]%k;
		}
	}

	if(g == -1){
		printf("1\n0\n");
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(v[i]%k != 0) g = gcd(g, v[i]%k);
	}

	vi ans;
	int d = g;
	while(!vis[d]){
		vis[d] = 1;
		ans.pb(d);
		d += g;
		d %= k;
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}