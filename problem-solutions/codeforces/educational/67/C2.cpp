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

const int N = 1005;
int n,m;
vector<ii> a;
vector<ii> b;
int ans[N];


int main(){
    scanf("%d%d", &n, &m);
    
    int x,y,z;
    for(int i=1; i<=m; i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x == 1){
            a.eb(y,z);
        }
        else b.eb(y,z);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int l = 0, r = 0;
    
    for(auto x : a){
        l = x.fi;
        r = x.se;
        for(int i = l+1; i<=r; i++)
            ans[i] = 1;
    }
    
    for(auto x : b){
        l = x.fi;
        r = x.se;
        int flag = 0;
        for(int i = l+1; i <= r; i++){
            if(ans[i] == 0){
                flag = 1;
            }
        }
        if(flag == 0){
            printf("NO\n");
            return 0;
        }
    }

    ans[1] = 2*N;
    for(int i = 2; i <= n; i++){
        if(ans[i] == 1)
            ans[i] = ans[i-1] + 1;
        else 
            ans[i] = ans[i-1] - 1;
    }

    printf("YES\n");
    for(int i = 1; i <= n; i++){
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}