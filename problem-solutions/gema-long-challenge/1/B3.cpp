#include <bits/stdc++.h>
// #define ap 278782 10001111 ^_^
#define ll long long int
using namespace std;

long long int t,n,k,m;
long long int curprim,ppow,ap[1000001];
vector < pair <long long int,long long int> > factors,modulo;
long long int d, x, y;
void gcdex(long long int a, long long int b) {

    if(b==0){
        x=1;y=0;d=a;return;
    }
    gcdex(b,a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;y=y1;
}

long long int ebsmod(long long int a,long long int b,long long int m)
{
    long long int res=1,i=1;
    while(i<=b)
    {
        if(i&b)
            res=(res*a)%m;
        a=(a*a)%m;
        i*=2;
    }
    return res;
}
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long int primepowerinfact(long long int n,long long int p)
{
    long long int i=p,ans=0;
    while(i<=n)
    {
        ans+=n/i;
        i*=p;
    }
    return ans;
}

long long int f(long long int n)
{
    return (ebsmod(ap[ppow],n/ppow,ppow)*ap[n%ppow])%ppow;
}

long long int F(long long int n)
{
    long long int i=1,res=1;
    while(i<=n)
    {
        res=(res*(f(n/i)))%ppow;
        i*=curprim;
    }
    return res;
}

void ncr(long long int n,long long int r)
{
    long long int e=primepowerinfact(n,curprim)-primepowerinfact(n-r,curprim)-primepowerinfact(r,curprim);
 //   cout << e << endl;
    long long int res=1;
    res=(res*ebsmod(curprim,e,ppow))%ppow;
    res=(res*F(n))%ppow;
  //  cout << F(n)%ppow << endl;
  //  cout << F(r)%ppow << endl;
    gcdex(F(r),ppow);
    if(x<0)
        x+=ppow;
    res=(res*x)%ppow;
    gcdex(F(n-r),ppow);
    if(x<0)
        x+=ppow;
    res=(res*x)%ppow;
    //cout << res << endl;
    modulo.push_back(make_pair(res,ppow));
}

long long int crt()
{
    long long int res=0;
    for(int i=0;i<modulo.size();i++)
    {
        long long int yi=m/modulo[i].second;
        long long int ai=modulo[i].first;
        gcdex(yi,modulo[i].second);
        if(x<0)
            x+=modulo[i].second;
        long long int zi=x;
        res=(res+ai*yi*zi)%m;
    }
    return res;
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> m;
        long long int s=m;
        long long int n1,n2;
        n2=(n+k-1)/k;
        n1=n2*k-n;
     //   cout << n1 << " " << n2 << endl;
        factors.clear();
        modulo.clear();
        for(int i=2;i<=s;i++)
        {
            int cnt=0;
            while(s%i==0)
            {
                s/=i;
                cnt++;
            }
            if(cnt)
                factors.push_back(make_pair(i,cnt));
        }
        for(int i=0;i<factors.size();i++)
        {
           // cout << factors[i].first << " " << factors[i].second << endl;
            curprim=factors[i].first;
            ppow=ebsmod(factors[i].first,factors[i].second,10000000);
            ap[0]=1;
            for(int i=1;i<=ppow;i++)
            {
                if(i%curprim==0)
                    ap[i]=ap[i-1];
                else
                    ap[i]=(ap[i-1]*i)%ppow;
            }
            ncr(n1+n2-1,n1);
        }
        for(int i=0;i<modulo.size();i++);
          //  cout << modulo[i].first << " " << modulo[i].second << endl;
        cout << n2 << " " << crt() << endl;
    }
    return 0;
}
