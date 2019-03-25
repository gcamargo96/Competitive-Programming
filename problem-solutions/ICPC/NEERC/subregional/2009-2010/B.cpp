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

int cnta[11], cntb[11];
string s, t;

int main(void){
	freopen("bulls.in", "r", stdin);
	freopen("bulls.out", "w", stdout);

	fastcin;
	cin >> s >> t;

	int bulls = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t[i]){
			bulls++;
		}
		else{
			cnta[s[i]-'0']++;
			cntb[t[i]-'0']++;
		}
	}

	int cows = 0;
	for(int i = 0; i <= 9; i++){
		cows += min(cnta[i], cntb[i]);
	}

	// printf("%d %d\n", bulls, cows);
	cout << bulls << " " << cows << endl;

	return 0;
}