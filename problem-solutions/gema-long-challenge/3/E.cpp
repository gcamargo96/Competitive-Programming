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

const int N = 25;
double a[405][405], b[405];
char g[N][N];
bool vis[N][N];
int idx[N][N];
ii tunnel[N][N];
int xa, ya;
int cntIdx = 0;
int n, m, k;

int getId(int x, int y){
    if(idx[x][y] != -1)
        return idx[x][y];
    return idx[x][y] = cntIdx++;
}

double gauss (vector < vector<double> > mat) {
    int n = mat.size();
    int i, j, k, l;
    double t;
    for (j = 0; j < n; j++) {
        l = j;
        for (i = j+1; i < n; i++)
            if (fabs(mat[i][j]) > fabs(mat[l][j]))
                l = i;
        swap (mat[j], mat[l]);
        for (i = j+1; i < n; i++)
            for (k = n; k >=j; k--)
                mat[i][k] = mat[i][k] - (mat[j][k] * mat[i][j] / mat[j][j]);
    }
    vector <double> ans;
    ans.resize(n, 0.0);
    for (j = n-1; j >= 0; j--) {
        double at = 0.0;
        for (k = j+1; k < n; k++) at = at + mat[j][k] * ans[k];
        ans[j] = (mat[j][n] - at) / mat[j][j];
    }

    return ans[getId(xa,ya)];
}

bool canGo(int x, int y){
    return (x >= 1 and y >= 1 and x <= n and y <= m and g[x][y] != '#');
}

bool isExit(int x, int y){
    return (x >= 1 and y >= 1 and x <= n and y <= m and g[x][y] == '%');
}

void dfs(int x, int y){
    if(x < 1 or y < 1 or x > n or y > m or !(g[x][y] == 'O' or g[x][y] == 'A') or vis[x][y]) return;
    vis[x][y] = 1;

    int id = getId(x, y);

    if(tunnel[x][y] != ii(-1,-1)){
        int xx = tunnel[x][y].fi;
        int yy = tunnel[x][y].se;
        x = xx;
        y = yy;
    }

    int cntCanGo = 0, cntExits = 0;
    
    if(canGo(x-1,y)) cntCanGo++;
    if(canGo(x+1,y)) cntCanGo++;
    if(canGo(x,y-1)) cntCanGo++;
    if(canGo(x,y+1)) cntCanGo++;

    if(cntCanGo == 0){
        a[id][id] = 1;
        return;
    }

    if(isExit(x-1,y)) cntExits++;
    if(isExit(x+1,y)) cntExits++;
    if(isExit(x,y-1)) cntExits++;
    if(isExit(x,y+1)) cntExits++;


    a[id][id] = cntCanGo;
    b[id] = cntExits;

    if(canGo(x-1,y) and (g[x-1][y] == 'O' or g[x-1][y] == 'A')) a[id][getId(x-1,y)] = -1;
    if(canGo(x+1,y) and (g[x+1][y] == 'O' or g[x+1][y] == 'A')) a[id][getId(x+1,y)] = -1;
    if(canGo(x,y-1) and (g[x][y-1] == 'O' or g[x][y-1] == 'A')) a[id][getId(x,y-1)] = -1;
    if(canGo(x,y+1) and (g[x][y+1] == 'O' or g[x][y+1] == 'A')) a[id][getId(x,y+1)] = -1;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(void){
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c", &g[i][j]);
            if(g[i][j] == 'A'){
                xa = i;
                ya = j;
            }
            tunnel[i][j] = ii(-1,-1);
        }
    }

    int xi, yi, xj, yj;
    for(int i = 0; i < k; i++){
        scanf("%d%d%d%d", &xi, &yi, &xj, &yj);
        tunnel[xi][yi] = ii(xj,yj);
        tunnel[xj][yj] = ii(xi,yi);
    }

    memset(idx, -1, sizeof idx);
    dfs(xa, ya);

    vector<vector<double> > mat;
    mat.resize(cntIdx);

    for(int i = 0; i < cntIdx; i++){
        mat[i].resize(cntIdx+1);
        for(int j = 0; j < cntIdx; j++){
            mat[i][j] = a[i][j];
        }
        mat[i][cntIdx] = b[i];
    }

    // for(int i = 0; i < cntIdx; i++){
    //     for(int j = 0; j < cntIdx+1; j++){
    //         printf("%.1lf ", mat[i][j]);
    //     }
    //     printf("\n");
    // }

    double ans = gauss(mat);

    printf("%.10lf\n", ans);

    return 0;
}