#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define emp emplace
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k, m;

vector<ll> euler(2000003, -1), primes;

//Generate primes and also calculate the euler number
void genprime(){
 	for(ll i = 2;i<=1100002;i++){
 		if(euler[i]==-1){
 			primes.push_back(i);
 			euler[i] = i-1;
 			for(ll j = 2*i; j<=1100002; j+=i){
 				if(euler[j]==-1)euler[j] = j;
 				euler[j] = (euler[j]/i)*(i-1);
 			}
 		}
 	}
}

//Calculates x raised to the power of p % m
ll powll(ll x, ll p, ll m = 1ll<<62){
 	if(p==0)return 1;
 	if(p==1)return x%m;
 	ll ans = powll(x, p/2, m);
 	ans = ((ans%m)*(ans%m))%m;
 	if(p&1)ans=(ans*x%m)%m;
 	return ans%m;
}

ll inverse(ll x, ll m){
 	if(x==1)return 1;
 	return powll(x, euler[m]-1, m)%m;
}

//finds (n!)_p
ll ff(ll n, ll p, ll q){
 	ll x = 1, y = powll(p, q);
 	for(ll i = 2; i<=n;i++)
 		if(i%p)
 			x = (x*i)%y;
 	return x%y;
}

//Generalized Lucas Theorem calculates nCm mod p^q
ll f(ll n, ll m, ll p, ll q){
 	ll r = n-m, x = powll(p, q);
 	ll e0 = 0, eq = 0;
 	ll mul = (p==2&&q>=3)? 1: -1;
 	ll cr = r, cm = m, carry = 0, cnt = 0;
 	while(cr||cm||carry){
 		cnt++;
 		ll rr = cr%p, rm = cm%p;
 		if(rr + rm + carry >= p){
 			e0++;
 			if(cnt>=q)eq++;
 		}
 		carry = (carry+rr+rm)/p;
 		cr/=p;
 		cm/=p;
 	}
 	mul = powll(p, e0)*powll(mul, eq);
 	ll ret = (mul % x + x) % x;
 	ll temp = 1;
 	for(ll i = 0;;i++)//This is THE line that calculates the formula
 	{
 		ret = ((ret*ff((n/temp)%x, p, q)%x)%x*(inverse(ff((m/temp)%x, p, q), x)%x*inverse(ff((r/temp)%x, p, q), x)%x)%x)%x;

 		if(temp>n/p && temp>m/p && temp>r/p)
			break;
 		temp = temp*p;
 	}
 	return (ret%x+x)%x;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);

	genprime();

	int t; cin >> t;

	while (t--) {
		cin >> n >> k >> m;

		ll temp = m;

		ll a = (n+k-1)/k-1, b = (k-n%k)%k;
		ll val = a+b;

 		ll aux = m;
		vector<ll> num, rem;
 		for(ll i = 0; primes[i]<=m; i++){
 			if(m%primes[i]==0){
 				ll p = primes[i], q = 0;
 				
 				while(aux%p==0){
 					q++, aux/=p;
 				}
 				
 				num.push_back(powll(p, q));
 				rem.push_back(f(val, b, p, q));
 			}
 		}
 		// m = temp;
 		ll ans = 0;

 		//Chinese Remainder Theorem
 		temp = 0;
 		for(ll i = 0;i<num.size(); i++)
 			ans = (ans+rem[i]*(temp = m/num[i])*inverse(temp, num[i]))%m;

		cout << (n+k-1)/k << " " << ans << endl;
	}

	return 0;
}