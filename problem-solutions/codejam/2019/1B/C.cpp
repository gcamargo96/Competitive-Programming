#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int t, n, k;
int c[N], d[N];

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &k);

		for(int i = 0; i < n; i++){
			scanf("%d", &c[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &d[i]);
		}

	
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int mc = -1, md = -1;
			for(int j = i; j < n; j++){
				mc = max(mc, c[j]);
				md = max(md, d[j]);

				if(abs(mc-md) <= k){
					ans++;
				}
			}
		}

		printf("Case #%d: %lld\n", caso, ans);
	}


	return 0;
}