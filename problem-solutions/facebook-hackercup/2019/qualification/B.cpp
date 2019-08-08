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

int t;
string s;

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> s;

		int n = s.size(), cnt = 0;

		for(int i = 1; i < s.size(); i++){
			if(s[i] == 'B') cnt++;
		}

		cout << "Case #" << caso << ": ";
		if(n == 3 and cnt == 1){
			cout << "Y" << endl;
		}
		else if(cnt > 1 and cnt < n-1){
			cout << "Y" << endl;
		}
		else{
			cout << "N" << endl;
		}
	}

	return 0;
}