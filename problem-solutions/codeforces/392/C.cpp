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

ll n, m, k, x, y;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> x >> y;

	ll base = k/(n*m);
	ll resto = k%(n*m);

	ll minimo = base, maximo = base, sergei = base;
	if(resto > 0) maximo++;
	
	if(base%2 == 1){
		base--;
		sergei--;
		resto += n*m;
	}

	ll cnt;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == x and j == y){
				sergei++;
			}
			cnt++;
			if(cnt == resto) break;
		}
		if(cnt == resto) break;
	}
	if(cnt < resto){
		for(int i = n; i >= 1; i--){
			for(int j = 1; j <= m; j++){
				if(i == x and j == y){
					sergei++;
				}
				cnt++;
				if(cnt == resto) break;
			}
			if(cnt == resto) break;
		}
	}

	cout << maximo << " " << minimo << " " << sergei << endl;

	return 0;
}

