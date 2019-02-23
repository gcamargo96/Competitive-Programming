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

const int N = 100005;
int n, k, A, B;
int v[N];

int POW(int b, int e){
	int x = 1;

	for(int i = 0; i < n; i++){
		x *= b;
	}

	return x;
}

ll solve(int l, int r){
	int na = upper_bound(v, v+k, r) - lower_bound(v, v+k, l);
	if(na == 0) return A;
	if(l == r) return B;

	ll ret = ll(B)*ll(na)*ll(r-l+1);

	printf("l+r = %d\n", (l+r));
	
	int mid = (l+r)/2;
	printf("mid = %d\n", mid);
	ret = min(ret, solve(l, mid) + solve(mid+1, r));

	return ret; 
}

int main(void){
	scanf("%d%d%d%d", &n, &k, &A, &B);
	n = POW(2, n);

	// printf("%d\n", n+n);

	for(int i = 0; i < k; i++){
		scanf("%d", &v[i]);
		v[i]--;
	}

	sort(v, v+k);

	ll ans = solve(0, n-1);

	printf("%lld\n", ans);

	return 0;
}