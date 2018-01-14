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

const int N = 200002;
int n, k;
ii v[N]; 
int v2[N];

bool cmp(ii a, ii b){
	return abs(a.fi-a.se) < abs(b.fi-b.se);
}

int main(void){
	scanf("%d%d", &n, &k);

	For(i,0,n){
		scanf("%d", &v[i].fi);
	}
	
	For(i,0,n){
		scanf("%d", &v[i].se);
	}

	sort(v, v+n, cmp);

	int ca = 0, cb = 0;
	ll res = 0;
	For(i,0,n){
		if(v[i].fi <= v[i].se){
			ca++;
			v2[i] = 1;
			res += v[i].fi;
		}
		else{
			cb++;
			v2[i] = 2;
			res += v[i].se;
		}
	}

	int i = 0;
	while(ca < k and i < n){
		if(v2[i] == 2){
			res -= v[i].se;
			res += v[i].fi;
			ca++;
		}
		i++;
	}
	
	printf("%lld\n", res);

	return 0;
}

