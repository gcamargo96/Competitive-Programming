#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n;

ll mod_mul(ll a, ll b, ll mod){
    ll r = 0;
    while(b > 0){
        if(b & 1){
            r = (r + a)%mod;
        }
        a = (a + a)%mod;
        b >>= 1;
    }

    return r;
}

ll mod_pow(ll a, ll b, ll mod){
    ll r = 1;
    while(b > 0){
        if(b & 1){
            r = mod_mul(r, a, mod);
        }
        a = mod_mul(a, a, mod);
        b >>= 1;
    }

    return r;
}


bool isPrime(ll p, ll k){
    if(p<2 || (p!=2 && p % 2 == 0))
        return false;

    ll s = p-1;
    while(s % 2 == 0)
        s /= 2;

    for(ll i = 0; i < k; i++){
        ll a = rand() % (p-1)+1, temp=s;
        ll mod = mod_pow(a, temp, p);
        while(temp!=p-1 && mod != 1 && mod!= p-1){
            mod = mod_mul(mod, mod, p);
            temp *= 2;
        }
        if(mod != p-1 && temp % 2 == 0)
            return false;
    }
    return true;
}

ll pollar(ll n){
    if(n == 1)
        return n;
    if(n%2 == 0)
        return 2;
    ll  x = (rand() % (n-2))+2;
    ll y = x;
    ll c = (rand() % (n-1))+1;
    ll d = 1;
    while(d == 1){
        x = ( ( mod_mul(x%n, x%n, n) )%n+c+n)%n;
        y = ( ( mod_mul(y%n, y%n, n) )%n+c+n)%n;
        y = ( ( mod_mul(y%n, y%n, n) )%n+c+n)%n;
        d = __gcd(abs(x-y),n);
        if(d == n)
            return pollar(n);
    }
    return d;
}

int main() {
    srand(time(NULL));
    scanf("%lld", &n);

    if(n < 4 or isPrime(n, 50))
        cout << "Nao" << endl;
    else{
        ll p = pollar(n);
        cout << "Sim" << endl << p << " " << n / p << endl;
    }

    return 0;
}