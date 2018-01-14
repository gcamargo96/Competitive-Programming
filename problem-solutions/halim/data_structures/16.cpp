// uva 1062 - Containers

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

string s;

int add(vector<stack<char> >& v, char c){
	For(i,0,v.size()){
		if(c <= v[i].top()){
			v[i].push(c);
			return 0;
		}
	}

	stack<char> s;
	s.push(c);
	v.pb(s);
	return 1;
}

int main(void){
	ios_base::sync_with_stdio(false);

	int caso = 1;
	while(cin >> s, s != "end"){
		vector<stack<char> > v;

		int res = 0;
		For(i,0,s.size()){
			res += add(v, s[i]);
		}

		cout << "Case " << caso << ": " << res << endl;
		caso++;
	}

	return 0;
}
