#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

string s;
set<int> dif;
set<vi> vis;
ll fat[20];

void precalc(){
	fat[0] = 1;
	for(ll i = 1; i <= 18; i++){
		fat[i] = fat[i-1] * i;
	}
}

int POW(int b, int e){
	int ret = 1;
	for(int i = 0; i < e; i++){
		ret *= b;
	}

	return ret;
}

bool has_all(vi& v){
	set<int> aux;
	for(int i = 0; i < v.size(); i++){
		aux.insert(v[i]);
	}

	return (aux.size() == dif.size());
}

ll calc(vi& v){
	ll ret = 0;
	for(int i = 0; i < v.size(); i++){
		map<int,int> cnt;
		if(v[i] != 0 and (i == 0 or v[i] != v[i-1])){ // fixa v[i] na primeira posição
			for(int j = 0; j < v.size(); j++){ // calcula as frequencias
				if(j != i){
					cnt[v[j]]++;
				}
			}

			ll num = fat[int(v.size())-1];
			ll den = 1;
			for(auto it : cnt){
				den *= fat[it.se];
			}

			ret += num/den;
		}
	}

	return ret;
}

void print(vi& v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
}

int main(void){
	fastcin;
	precalc();
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		dif.insert(s[i]-'0');
	}

	int k = POW(2, s.size());

	ll ans = 0;
	for(int mask = 0; mask < k; mask++){
		vi v;
		for(int i = 0; i < s.size(); i++){
			if(((mask>>i) & 1) == 1){
				v.pb(s[i]-'0');
			}
		}

		sort(v.begin(), v.end());
		if(has_all(v) and !vis.count(v)){
			// print(v);
			ans += calc(v);
			vis.insert(v);
		}
	}

	cout << ans << endl;

	return 0;
}