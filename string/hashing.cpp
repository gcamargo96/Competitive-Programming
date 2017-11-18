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

#define B 33
string s;
int a, b, c, d, k, n;
ll mod[2] = {1000000007, 1000000009};
ll h[2][10000000], hr[2][10000000];
ll pot[2][10000000], potr[2][10000000];

void precalc(string& s){
    for(int k = 0; k < 2; k++){
        h[k][0] = s[0]/* - 'A' + 1*/;
        pot[k][0] = 1;

        for(int i = 1; i < s.size(); i++){
            h[k][i] = ((h[k][i-1]*B)%mod[k] + (s[i]/* - 'A' + 1*/))%mod[k];
            pot[k][i] = (pot[k][i-1]*B)%mod[k];
        }
    }
}

void precalcrev(string& s){
    int n = s.size();
    for(int k = 0; k < 2; k++){
        hr[k][n-1] = s[n-1]/* - 'A' + 1*/;
        potr[k][n-1] = 1;

        for(int i = n-2; i >= 0; i--){
            hr[k][i] = ((hr[k][i+1]*B)%mod[k] + (s[i]/* - 'A' + 1*/))%mod[k];
            potr[k][i] = (potr[k][i+1]*B)%mod[k];
        }
    }
}

ll calcHash(int i, int j, int k){
    if(i == 0) return h[k][j];
    return (h[k][j] - (h[k][i-1]*pot[k][j-i+1])%mod[k] + mod[k])%mod[k];
}

ll calcHashRev(int i, int j, int k){
    if(j == n-1) return hr[k][i];
    return (hr[k][i] - (hr[k][j+1]*potr[k][n-1-(j-i+1)])%mod[k] + mod[k])%mod[k];
}
