#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n, t, q;
map<char,double> m;
string s;

int main(void){
	cin >> t;

	while(t--){
		m.clear();
		cin >> n;

		char c;
		double val;
		For(i,0,n){
			cin >> c >> val;
			m[c] = val/100;
		}

		cin >> q;

		double res = 0;
		For(i,0,q+1){
		getline(cin, s);
			For(j,0,s.size()){
				if(m.count(s[j])) res += m[s[j]];
			}
		}

		printf("%.2lf$\n", res);
	}

	return 0;
}
