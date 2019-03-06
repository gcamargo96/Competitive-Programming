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

int n;
int c1, c2, w1, w2, t1, t2;
unordered_map<string, int> m1, m2;

int main(void){
	fastcin;
	cin >> n;

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		m1[s]++;
	}

	for(int i = 0; i < n; i++){
		cin >> s;
		m2[s]++;
	}

	int ans = 0;
	for(auto it : m1){
		ans += min(it.se, m2[it.fi]);
	}

	cout << ans << endl;

	return 0;
}