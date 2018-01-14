#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

ll russianPeasant(ll a, ll b, int k){
    ll res = 0;
    while (b > 0){
         if (b & 1)
             res = (res + a) % mod[k];
 
         a = (a << 1) % mod[k];
         b = b >> 1;
     }
     return res;
}
