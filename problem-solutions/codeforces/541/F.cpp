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

const int N = 200005;
int n;
int p[N];
vi v[N];

int find(int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    if (v[x].size() < v[y].size()){
        p[x] = y;
        for (int i = 0; i < v[x].size(); ++i)
            v[y].pb(v[x][i]);
    }
    else{
        p[y] = x;
        for (int i = 0; i < v[y].size(); ++i)
            v[x].pb(v[y][i]);
    }
}

int main(){
	scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        p[i] = i;
        v[i].pb(i);
    }
    for (int i = 0; i < n - 1; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        join(x, y);
    }

    int x = find(1);
    for (int i = 0; i < v[x].size(); ++i){
    	printf("%d ", v[x][i]);
    }
    printf("\n");

    return 0;
}