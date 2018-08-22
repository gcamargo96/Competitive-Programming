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

#define INF 1000000000000000000LL

const int N = 3005;
ll ans = 0;
int cnt[N];
int n, m;
ii v[N];
int pos = 0;

bool win(){
	int mx = 0;
	for(int i = pos; i < n; i++){
		if(v[i].se != 1){
			mx = max(mx, cnt[v[i].fi]);
		}
	}
	return cnt[1] > mx;
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].se, &v[i].fi);
		cnt[v[i].se]++;
		if(v[i].se != 1) mx = max(mx, v[i].se);
	}

	sort(v, v+n);

	for(i = 0; i < n and !win(); i++){
		pos = i;
		if(v[i].se != 1){
			ans += v[i].fi;
			cnt[v[i].se]--;
		}
	}

	ll aux = ans;

	if(v[pos].se != 1){
		cnt[v[i].se]++;
		aux -= v[i].fi;
	}

	int pos2 = pos+1;
	pos--;
	while(pos >= 0){
		int mn = 1000000009;
		for(int i = pos; i < n; i++){
			if()
		}

		pos--;
	}

	return 0;
}