#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, m, x, last = 0, w, h;
int mx[N];

main(void){
	scanf("%I64d", &n);

	scanf("%I64d", &mx[0]);
	For(i,1,n){
		scanf("%I64d", &x);
		mx[i] = max(mx[i-1], x);
	}

	scanf("%I64d", &m);

	For(i,0,m){
		scanf("%I64d%I64d", &w, &h);
		int res = max(mx[w-1], last);
		printf("%I64d\n", res);
		last = res + h;
	}

	return 0;
}

