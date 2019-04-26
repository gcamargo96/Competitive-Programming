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

const int N = 300005;
int n;
ll a[N];

int main(void){
	scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
    }

    ll sum=0, r=0;
    for(int i = 0; i < n ;i++){
        sum += min(r, a[i]/2);
        ll o = min(r, a[i]/2);
        r -= o;
        a[i] -= o*2;
        sum += a[i]/3;
        a[i] %= 3;
        r += a[i];
    }

    printf("%lld\n", sum);

	return 0;
}