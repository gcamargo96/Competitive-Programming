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

const int N = 300002;
int n, a, b, c, d, start, len;
ii v[N];

ll solve(int i, int flag){
	if(i == n){
		
	}
}

int main(void){
	// fastcin;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d, &start, &len);

	int t, type;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].fi, &v[i].se);
	}

	ll ans = solve(0, 0);

	return 0;
}