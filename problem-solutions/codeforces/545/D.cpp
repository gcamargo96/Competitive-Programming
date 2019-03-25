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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500005;
string s, t, ans;
int cnt[100];
int p[2*N];

void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];

		// if(cnt[s[p[i]]] > 0){
		// 	p[i]++;
		// 	ans += s[p[i]];
		// 	cnt[s[p[i]]--];
		// 	continue;
		// }
		// while(p[i] > 0 and cnt[s[p[i]]] == 0)
		// 	p[i] = p[p[i]];

		// ans += s[p[i]];
		// p[i]++;
		// cnt[s[p[i]]--];

		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

char NOT(char c){
	if(c == '0') return '1';
	return '0';
}

void solve(string& s){
	// cout << s << endl;
	// cout << "aqui " << cnt['0'] << " " << cnt['1'] << endl;

	int n = s.size();
	for(int i = t.size()+2; i <= n; i++){
		p[i] = p[i-1];

		// cout << p[i] << endl;
		// cout << s[p[i]] << " ";

		if(s[p[i]] != '#' and cnt[s[p[i]]] > 0){
			ans += s[p[i]];
			cnt[s[p[i]]]--;
			p[i]++;
			// cout << "p1 " << s[p[i]] << endl;
			continue;
		}
		while(s[p[i]] == '#' or (p[i] > 0 and cnt[s[p[i]]] == 0))
			p[i] = p[p[i]];

		if(cnt[s[p[i]]] > 0){
			ans += s[p[i]];
			cnt[s[p[i]]]--;
			p[i]++;
			// cout << "p2 " << s[p[i]] << endl;

		}
		else{
			char c = NOT(s[p[i]]);
			ans += c;
			p[i] = 0;
			cnt[c]--;
			// cout << "p3 " << c << endl;
		}
	}

	// cout << cnt['0'] << " " << cnt['1'] << endl;
	// cout << endl;
}


int main(void){
	cin >> s >> t;

	if(s.size() < t.size()){
		// cout << -1 << endl;
		cout << s << endl;
		return 0;
	}


	for(int i = 0; i < s.size(); i++){
		cnt[s[i]]++;
	}
	// for(int i = 0; i < t.size(); i++){
	// 	cnt[t[i]]++;
	// }
	// cnt['#']++;

	string r;
	r = t + "#" + s;

	string aux = t + "#";
	prefix_function(aux);
	solve(r);

	// for(int i = 1; i <= r.size(); i++){
	// 	cout << p[i] << " ";
	// }
	// cout << endl;

	cout << ans << endl;

	return 0;
}