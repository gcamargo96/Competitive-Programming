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

const int N = 300005;
int a[N];
int n, m;

int main(void){
	scanf("%d", &n);

	ll sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += ll(a[i]);
	}

	sort(a, a+n);

	scanf("%d", &m);

	int q;
	for(int i = 0; i < m; i++){
		scanf("%d", &q);
		printf("%lld\n", sum - ll(a[n-q]));
	}

	return 0;
}