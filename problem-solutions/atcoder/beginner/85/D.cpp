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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n;
ll H;
ll a[N], b[N];

int main(void){
	scanf("%d%lld", &n, &H);

	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &a[i], &b[i]);
	}

	sort(a, a+n);
	sort(b, b+n);

	ll sum = 0;
	ll ans = 0;
	for(int i = n-1; i >= 0 and b[i] > a[n-1] and sum < H; i--){
		sum += b[i];
		ans++;
	}

	if(sum < H){
		ll falta = H - sum;
		ans += falta/a[n-1];
		falta -= (falta/a[n-1]) * a[n-1];
		if(falta > 0)
			ans++;
	}

	printf("%lld\n", ans);

	return 0;
}