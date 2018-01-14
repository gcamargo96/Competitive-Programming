#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
int n;
ll v[N];

int main(void){
	scanf("%d", &n);

	int zeros = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		if(v[i] == 0)
			zeros++;
	}

	vector<ll> dists, squares;
	for(int i = 0; i < n; i++){
		ll sqr = floor(sqrt(v[i]));
		
		if(sqr*sqr == v[i])
			squares.pb(v[i]);
		else{
			dists.pb(min(abs(v[i]-sqr*sqr), abs(v[i]-(sqr+1)*(sqr+1))));
		}
	}

	sort(dists.begin(), dists.end());
	sort(squares.begin(), squares.end(), greater<ll>());

	ll ans = 0;
	if(squares.size() < n/2){
		for(int i = 0; i < n/2-squares.size(); i++){
			ans += dists[i];
		}
	}
	else if(squares.size() > n/2){
		for(int i = 0; i < squares.size() - n/2; i++){
			if(squares[i] == 0){
				ans += 2;
			}
			else{
				ans++;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}