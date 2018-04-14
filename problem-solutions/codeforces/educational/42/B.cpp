#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, a, p;
string s;

int main(void){
	fastcin;
	cin >> n >> p >> a;
	cin >> s;
	s = "#" + s;

	for(int i = 1; i <= n; i++){
		if(s[i] == '*')
			continue;

		if(s[i-1] == 'p'){
			if(a > 0){
				s[i] = 'a';
				a--;
			}
			continue;
		}
		if(s[i-1] == 'a'){
			if(p > 0){
				s[i] = 'p';
				p--;
			}
			continue;
		}

		if(p > a and p > 0){
			s[i] = 'p';
			p--;
		}
		else if(a > 0){
			s[i] = 'a';
			a--;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'a' or s[i] == 'p'){
			ans++;
		}
	}

	// cout << s << endl;
	cout << ans << endl;

	return 0;
}