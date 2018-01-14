#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
#define fastcin ios_base::sync_with_stdio(false)

const int N = 100002;
int n;
int a[N], b[N], c[N];
ll up[N], acum[N];

int main(void){
	//fastcin;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}

	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);

	for(int i = 0; i < n; i++){
		int j = lower_bound(a, a+n, b[i]) - a;
		up[i] = j;
	}

	acum[0] = up[0];
	for(int i = 1; i < n; i++){
		acum[i] = acum[i-1] + up[i];
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		int j = lower_bound(b, b+n, c[i]) - b;;
		if(j > 0){
			ans += acum[j-1];
		}
	}

	printf("%lld\n", ans);

	return 0;
}