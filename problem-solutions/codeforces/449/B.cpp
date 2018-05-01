#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

int k;
ll p;

int main(void){
	scanf("%d%lld", &k, &p);

	ll sum = 0;
	for(int i = 1; i <= k; i++){
		string s(to_string(i));
		string r(s);
		reverse(r.begin(), r.end());
		ll x = stoll(s+r);
		sum += x;
		sum %= p;
	}

	printf("%lld\n", sum);

	return 0;
}