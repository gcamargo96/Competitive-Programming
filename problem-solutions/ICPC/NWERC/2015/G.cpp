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

const int N = 200005;
int bit[N];
int a[N], b[N], c[N], pos[N];
int n;

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

ll inversions(int a[N], int b[N]){
	memset(bit, 0, sizeof bit);
	for(int i = 1; i <= n; i++){
		pos[a[i]] = i;
	}

	ll ret = 0;
	for(int i = n; i >= 1; i--){
		ret += query(pos[b[i]]-1);
		update(pos[b[i]], 1);
	}

	return ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}

	ll ans = 0;
	ans += inversions(a, b);
	ans += inversions(a, c);
	ans += inversions(b, c);

	printf("%lld\n", (ll(n)*ll(n-1))/2LL - ans/2LL);

	return 0;
}