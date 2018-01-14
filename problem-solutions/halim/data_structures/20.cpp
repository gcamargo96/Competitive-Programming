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

map<string, double> m;
string s;
int T;

int main(void){
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(4);

	cin >> T;
	cin.get();
	cin.get();

	For(k,0,T){
		m.clear();
		double total = 0;
		while(getline(cin, s), s.size() != 0){
			m[s] += 1;
			total += 1;
		}

		for(auto it = m.begin(); it != m.end(); it++){
			double prc = 100*(it->se/total);
			cout << it->fi << " " << prc << endl;
		}

		if(k < T-1) cout << endl;
	}

	return 0;
}
