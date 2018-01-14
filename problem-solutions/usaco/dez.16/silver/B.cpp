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

//		 CITY  / STATE
map<pair<string, string>, ll> inv;
int n;

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	cin >> n;

	string c, s;
	For(i,0,n){
		cin >> c >> s;
		string aux;
	   	aux += c[0];
		aux += c[1];
		if(aux != s){
			inv[mp(aux,s)]++;
		}
	}

	ll res = 0;
	for(auto it = inv.begin(); it != inv.end(); it++){
		pair<string, string> opo = mp(it->fi.se, it->fi.fi);
		if(inv.count(opo)){
			res += it->se * inv[opo];
		}
	}

	cout << res/2 << endl;
	
	return 0;
}

