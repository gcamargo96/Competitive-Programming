#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100002;
int n;
ll v[N];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lld", &v[i]);
	}

	ll g = 0;
	For(i,0,n){
		g = gcd(g, v[i]);
	}

	if(g > 1){
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	
	ll res = 0;
	For(i,0,n-1){
		res += v[i];
		v[i+1] += v[i];
		v[i] = 0;
	}

	printf("YES\n");
	printf("%lld\n", res);

	return 0;
}

