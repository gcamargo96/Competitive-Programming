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

const int N = 1000005;
const ll MOD = 1000000007;
int t, n, k;
ll pot[N];
string s;

ll mul(ll a, ll b){
	return (a*b)%MOD;
}

ll add(ll a, ll b){
	return (a+b)%MOD;
}

void precalc(){
	pot[0] = 1;
	for(int i = 1; i < N; i++){
		pot[i] = mul(2LL, pot[i-1]);
	}
}

int main(void){
	fastcin;
	precalc();

	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n >> k;
		cin >> s;

		int cnt = 0;
		ll ans = 0;
		for(int i = n-1; i >= 0; i--){
			cnt = max(cnt, 0);

			if(s[i] == 'B'){
				cnt++;
			}
			else{
				cnt--;
			}

			if(cnt > k){
				ans = add(ans, pot[i+1]);
				cnt -= 2;
			}
		}

		cout << "Case #" << caso << ": " << ans << endl; 
	}

	return 0;
}