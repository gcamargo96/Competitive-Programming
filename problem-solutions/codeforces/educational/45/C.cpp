#include <bits/stdc++.h>
using namespace std;
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

const int N = 300002;
string s[N];
int n;
map<int, ll> m;

ii check(string& s){
	stack<char> p;

	int esq = 0, dir = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			p.push('(');
		}
		else if(!p.empty()){
			p.pop();
		}
		else{
			esq++;
		}
	}
	dir = p.size();

	return ii(esq, dir);
}

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	for(int i = 0; i < n; i++){
		ii bal = check(s[i]);

		if(bal.fi == 0 and bal.se == 0){ // balanced
			m[0]++;
		}
		else if(bal.fi > 0 and bal.se == 0){ // left
			m[-bal.fi]++;
		}
		else if(bal.fi == 0 and bal.se > 0){ // right
			m[bal.se]++;
		}
	}

	ll ans = m[0]*m[0];

	for(auto it : m){
		if(it.fi > 0 and m.count(-it.fi)){
			ans += it.se * m[-it.fi];
		}
	}

	cout << ans << endl;

	return 0;
}