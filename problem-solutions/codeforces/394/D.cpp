#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, l, r;
int a[N], b[N], c[N];
ii p[N];

int main(void){
	scanf("%d%d%d", &n, &l, &r);

	For(i,0,n){
		scanf("%d", &a[i]);
	}

	For(i,0,n){
		scanf("%d", &p[i].fi);
		p[i].se = i;
	}

	sort(p, p+n);

	int last = r, cc = r - a[p[n-1].se];
	b[p[n-1].se] = cc + a[p[n-1].se];
	for(int i = n-2; i >= 0; i--){
		cc--;
		b = cc + a[p[i].se]
	}

	return 0;
}

