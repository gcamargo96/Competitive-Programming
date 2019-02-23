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


const ll M = 1000000007;
const int N = 100005;
ll fat[N], ifat[N], dp[N], cnt[55];
string s;
ll W;
int n, q;

int get(int i){
	if(s[i] >= 'a' and s[i] <= 'z'){
		return s[i]-'a';
	}
	else{
		return s[i]-'A'+26;
	}
}

ll add(ll a, ll b){
	return (a+b)%M;
}

ll sub(ll a, ll b){
	return (a-b+M)%M;
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return mul(x, x);
	}
	else{
		return mul(b, mul(x,x));
	}
}

ll Div(ll a, ll b){
	return mul(a, fastpow(b, M-2));
}

void calc_fat(){
	fat[0] = 1;
	for(int i = 1; i < N; i++){
		fat[i] = mul(fat[i-1], i);
	}

	for(int i = 0; i < N; i++){
        ifat[i] = fastpow(fat[i], M-2);
	}
}

void calc_freq(){
	for(int i = 0; i < n; i++){
		if(s[i] >= 'a' and s[i] <= 'z'){
			cnt[s[i]-'a']++;
		}
		else{
			cnt[s[i]-'A'+26]++;
		}
	}
}

ll mul_freqs(){
	ll ret = 1;
	for(int i = 0; i < 52; i++){
		if(cnt[i] > 0) ret = mul(ret, fat[cnt[i]]);
	}
	return ret;
}

void put(int x){
	if(x == 0) return;
	for(int j = n/2-x; j >= 0; j--){
		dp[j+x] = add(dp[j+x], dp[j]);
	}
}

void rem(int x){
	if(x == 0) return;
	for(int j = x; j <= n/2; j++){
		dp[j] = sub(dp[j], dp[j-x]);
	}
}

ll memo[52][52];

ll solve(int x, int y){
    if(x > y) swap(x, y);
    if(~memo[x][y]) return memo[x][y];
    ll ans = 0;
    if(x == y){
        if(cnt[x] > n / 2) return memo[x][y] = 0;
        rem(cnt[x]);
        ans = W * dp[n / 2] * 2 % M;
        put(cnt[x]);
        return memo[x][y] = ans;
    }
    if(cnt[x] + cnt[y] > n / 2) return memo[x][y] = 0;

    rem(cnt[x]);
    rem(cnt[y]);
    ans = W * dp[n / 2] * 2 % M;
    put(cnt[x]);
    put(cnt[y]);

    return memo[x][y] = ans;
}

int main(void){
	fastcin;
	calc_fat();

	cin >> s;
	n = s.size();
	calc_freq();

	W = Div(mul(fat[n/2], fat[n/2]), mul_freqs());
	// W = fat[n / 2] * fat[n / 2] % M;

 //    for(int i = 0; i < 52; i++)
 //        W = W * ifat[ cnt[i] ] % M;

	// cout << "W = " << W << endl;

	dp[0] = 1;
	for(int i = 0; i < 52; i++){
		put(cnt[i]);
	}

	cin >> q;

	memset(memo, -1, sizeof memo);

	int x, y;
	while(q--){
		cin >> x >> y;
		x--, y--;

		cout << solve(get(x), get(y)) << endl;

		// rem(cnt[get(x)]);
		// if(get(x) != get(y)) rem(cnt[get(y)]);

		// cout << mul(mul(W, dp[n/2]), 2) << endl;

		// put(cnt[get(x)]);
		// if(get(x) != get(y)) put(cnt[get(y)]);
	}

	return 0;
}