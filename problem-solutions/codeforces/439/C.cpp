#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 998244353
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



const int N = 5002;
ll a, b, c;
ll fat[N];

void calcfat(){
	fat[0] = 1;
	for(int i = 1; i < N; i++){
		fat[i] = (fat[i-1]*i)%M;
	}
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return (x*x)%M;
	}
	else{
		return ((b*x)%M * x)%M;
	}
}

ll ncr(ll n, ll m){
	ll num = fat[n];
	ll den = (fat[m]*fat[n-m])%M;
	return (num * fastpow(den, M-2))%M;
}

int main(void){
	calcfat();
	cin >> a >> b >> c;

	ll ansAB = 0;
	for(int i = 0; i <= min(a,b); i++){
		ansAB += ((ncr(a,i) * ncr(b,i))%M * fat[i])%M;
		ansAB %= M;
	}

	ll ansBC = 0;
	for(int i = 0; i <= min(b,c); i++){
		ansBC += ((ncr(b,i) * ncr(c,i))%M * fat[i])%M;
		ansBC %= M;
	}

	ll ansAC = 0;
	for(int i = 0; i <= min(a,c); i++){
		ansAC += ((ncr(a,i) * ncr(c,i))%M * fat[i])%M;
		ansAC %= M;
	}

	ll ans = ((ansAB * ansBC)%M * ansAC)%M;

	cout << ans << endl;

	return 0;
}