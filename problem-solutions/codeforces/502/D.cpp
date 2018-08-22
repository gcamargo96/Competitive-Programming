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

int n, m, q;
int w[15];
map<string, ll> cnt, acum[N];

string AND(string a, string b){
	string s;
	for(int i = 0; i < n; i++){
		if(a[i] == '1' or b[i] == '1'){
			s += '1';
		}
		else{
			s += '0';
		}
	}
	return s;
}

int val(string s){
	int val = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			val += w[i];
		}
	}
	return val;
}

int main(void){
	fastcin;
	cin >> n >> m >> q;

	for(int i = 0; i < n; i++){
		cin >> w[i];
	}

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		cnt[s]++;
	}

	for(auto it1 : cnt){
		map<string,int> aux;
		for(auto it2 : cnt){
			string t = AND(it1.fi, it2.fi);
			aux[t]++;
		}
		for(auto it : aux){
			adj[it1.fi].pb(val(it1.fi));
			acum[it1.fi].pb(it2.se); // quantas strings do multiset dão o AND com it1.fi
		}
	}

	return 0;
}