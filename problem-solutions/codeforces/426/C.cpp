#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
int n;
ll a, b;

ll bin_search(ll x){
	ll l = 1, r = N;
	ll last = N;
	while(l <= r){
		ll m = (l+r)/2;
		if(m*m*m > x){
			r = m-1;
			// last = m;
		}
		else{
			l = m+1;
			last = m;
		}
	}
	return last;
}

int main(void){
	// ios_base::sync_with_stdio(false);
	// cin >> n;
	scanf("%d", &n);

	while(n--){
		// cin >> a >> b;
		scanf("%lld%lld", &a, &b);

		ll x = bin_search(a*b);
		
		if(x*x*x != a*b){
			// cout << "No" << endl;
			printf("No\n");
		}
		else if(a%x == 0 and b%x == 0){
			// cout << "Yes" << endl;
			printf("Yes\n");
		}
		else{
			// cout << "No" << endl;
			printf("No\n");
		}
	}

	return 0;
}