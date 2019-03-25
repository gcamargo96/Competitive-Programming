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

const int N = 105;
int t, n;
string s;

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		cin >> n;
		cin >> s;

		int a = 0, b = 0;

		for(int i = 0; i < n and s[i] == '<'; i++){
			a++;
		}
		for(int i = n-1; i >= 0 and s[i] == '>'; i--){
			b++;
		}

		int ans = min(a, b);

		// if(ans == 1) ans = 0;

		printf("%d\n", ans);
	}

	return 0;
}