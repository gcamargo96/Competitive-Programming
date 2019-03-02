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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

int main(void){
	fastcin;
	cin >> s;
	ll n = s.size();

	ll cur = (1LL << n);
	cur /= 2;

	int x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){

		}
		if(s[i] == '1'){
			x += cur;
		}
		if(s[i] == '2'){
			y += cur;
		}
		if(s[i] == '3'){
			x += cur;
			y += cur;
		}
		
		cur /= 2;
	}

	cout << n << " " << x << " " << y << endl;

	return 0;
}