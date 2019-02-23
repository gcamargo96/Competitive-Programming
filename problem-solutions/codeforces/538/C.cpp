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

ll prime[1000005],len,num[1000005];
void init(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            prime[++len]=i;
            while(x%i==0)
                x/=i,num[len]++;
        }
    }
    if(x>1) prime[++len]=x,num[len]=1;
}
int main()
{
    ll n,b,ans=2e18;scanf("%lld%lld",&n,&b);
    init(b);
    for(int i=1;i<=len;i++)
    {
        ll N=n,cnt=0;
        while(N)
        {
            cnt+=N/prime[i];
            N/=prime[i];
        }
        ans=min(ans,cnt/num[i]);
    }
    printf("%lld\n",ans);
    return 0;
}