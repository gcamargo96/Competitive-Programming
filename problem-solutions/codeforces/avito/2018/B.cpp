#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
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
typedef complex<double> base;

const int N = 100005;
int n, m;
map<int,int> a, b;

int main(void){
	scanf("%d", &n);

	int ai, xi;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &ai, &xi);
		a[ai] = xi;
	}

	scanf("%d", &m);

	int bi, yi;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &bi, &yi);
		b[bi] = yi;
	}

	ll ans = 0;
	for(auto it = a.begin(); it != a.end(); ++it){
		if(b.count(it->fi)){
			ans += (ll)max(it->se, b[it->fi]);
		}
		else{
			ans += (ll) it->se;
		}
	}

	for(auto it = b.begin(); it != b.end(); it++){
		if(!a.count(it->fi)){
			ans += (ll)it->se;
		}
	}

	printf("%lld\n", ans);

	return 0;
}