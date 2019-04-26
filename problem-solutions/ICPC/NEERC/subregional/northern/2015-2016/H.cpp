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

int n, x = 0, cnt = 0;
string a = "edHs", b = "fEHs";
string s;

void solve(int i){
	if(cnt == n) return;
	if(i == x){
		cout << s << endl;
		cnt++;
		return;
	}

	s += a;
	solve(i+1);
	s.pop_back();s.pop_back();s.pop_back();s.pop_back();
	s += b;
	solve(i+1);
	s.pop_back();s.pop_back();s.pop_back();s.pop_back();
}

int main(void){
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
	
	fastcin;
	cin >> n;

	int base = 1;
	while(base < n){
		base *= 2;
		x++;
	}

	solve(0);

	return 0;
}