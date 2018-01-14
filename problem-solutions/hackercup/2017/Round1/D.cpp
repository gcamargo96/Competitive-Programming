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

#define MOD 1000000007
const int N = 2002, M = 1000000002;
int t, n, m, r;
int v[N];
ll fat1[N], fat2[N];
int k;
map<int,int> raios;

void init(){
	raios.clear();
	k = 0;
}

int main(void){
	precalc();
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d", &n, &m);

		if(n == 1){
			printf("Case #%d: %d\n", caso, m);
			continue;
		}

		ll S = 0;	
		For(i,0,n){
			scanf("%d", &v[i]);
			S += 2*v[i];
			k = max(v[i], k);
		}

		fat1[0] fat2[0] = 1;
		for(int i = 1; i <= k; i++){
			fat1[i] = (fat1[i-1] * i);
			fat2[i] = (fat2[i-1] * (m-k+i));
		}

		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				raios[v[i]+v[j]]++;
			}
		}
		
		ll res = 0;
		for(auto it = raios.begin(); it != raios.end(); it++){
			ll L = m + it->fi;
			res += fat2[k-2] * fat1[L-S+n]
		}
	}

	return 0;
}

