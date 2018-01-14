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

const int N = 50002;
string s, t, cat;
int p[2*N];

void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	int n = s.size();

	cat = t + '#' + s;
	prefix_function(cat);

	int suf = p[cat.size()];

	bool ok = 1;
	for(int i = 0; i < n-suf; i++){
		if(s[i] != t[n-i-1]) ok = 0;
	}

	if(ok){
		cout << "Yes" << endl;
		cout << n-suf << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}

