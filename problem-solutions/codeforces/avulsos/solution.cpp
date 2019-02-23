#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100005;
const ll mod = 1e9 + 7;

ll fat[N], ifat[N];

ll fexp(ll b, ll e){
    ll ans = 1; b %= mod;
    while(e){
        if(e & 1) ans = ans * b % mod;
        b = b * b % mod;
        e /= 2;
    }
    return ans;
}

ll C(int n, int k){
    return fat[n] * ifat[n - k] % mod * ifat[k] % mod;
}

int n;
char s[N];
int cnt[52];

int get(char c){
    if(c >= 'a' && c <= 'z') return int(c - 'a');
    return int(c - 'A') + 26;
}

ll base;

ll dp[N];

void add(int x){
    if(!x) return;
    for(int i = n / 2 - x; i >= 0; i--){
        dp[i + x] += dp[i];
        if(dp[i + x] >= mod) dp[i + x] -= mod;
    }
}

void rem(int x){
    if(!x) return;
    for(int i = 0; i + x <= n / 2; i++){
        dp[i + x] -= dp[i];
        if(dp[i + x] < 0) dp[i + x] += mod;
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
        ans = base * dp[n / 2] * 2 % mod;
        add(cnt[x]);
        return memo[x][y] = ans;
    }
    if(cnt[x] + cnt[y] > n / 2) return memo[x][y] = 0;

    rem(cnt[x]);
    rem(cnt[y]);
    ans = base * dp[n / 2] * 2 % mod;
    add(cnt[x]);
    add(cnt[y]);

    return memo[x][y] = ans;
}

int main(){
    memset(memo, -1, sizeof memo);

    fat[0] = 1;

    for(int i = 1; i < N; i++) fat[i] = i * fat[i - 1] % mod;

    for(int i = 0; i < N; i++)
        ifat[i] = fexp(fat[i], mod - 2);

    scanf("%s", s);

    n = (int)strlen(s);

    for(int i = 0; i < n; i++) cnt[get(s[i])]++;

    base = fat[n / 2] * fat[n / 2] % mod;

    for(int i = 0; i < 52; i++)
        base = base * ifat[ cnt[i] ] % mod;

    printf("base = %lld\n", base);

    dp[0] = 1;

    for(int i = 0; i < 52; i++)
        add(cnt[i]);

    int q, x, y;

    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &x, &y);
        printf("%lld\n", solve(get(s[x-1]), get(s[y-1])));
    }
}