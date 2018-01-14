#include <bits/stdc++.h>

using namespace std;

#define N 200
#define INF 500000000

vector<pair<int, int> > g[N + 1];
bool neg[N + 1];
int dist[N + 1];
int b[N + 1];
int n, m;

void bellman_ford(int u){
    int i, j, v, w;
    bool updated;

    for (i = 1; i <= n; i++){
        dist[i] = INF;
        neg[i] = false;
    }

    dist[u] = 0;

    for (i = 0; i < n - 1; i++){
        updated = false;

        for (u = 1; u <= n; u++){
            for (j = 0; j < (int)g[u].size(); j++){
                v = g[u][j].first;
                w = g[u][j].second;

                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
        }

        /*if (!updated){
            break;
        }*/
    }

    // if (updated){
    for (i = 0; i < n - 1; i++){
        for (u = 1; u <= n; u++){
            for (j = 0; j < (int)g[u].size(); j++){
                v = g[u][j].first;
                w = g[u][j].second;

                if (dist[u] + w < dist[v]){
                    neg[v] = true;
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    // }
}

int cost(int src, int dest){
    return (b[dest] - b[src]) * (b[dest] - b[src]) * (b[dest] - b[src]);
}

bool vis[N+1];

void dfs(int u){
    vis[u] = 1;

    for(pair<int,int> v : g[u]){
        if(!vis[v.first]) dfs(v.first);
    }
}

int main(){
    int t, q, u, v, i;

    t = 0;

    while (cin >> n){
        for (i = 1; i <= n; i++){
            scanf("%d", b + i);
        }

        // scanf("%d", &m);
        cin >> m;

        for (i = 1; i <= m; i++){
            // scanf("%d%d", &u, &v);
            cin >> u >> v;
            g[u].push_back(make_pair(v, cost(u, v)));
        }

        memset(vis, 0, sizeof vis);
        dfs(1);
        bellman_ford(1);

        scanf("%d", &q);

        t++;
        printf("Set #%d\n", t);

        for (i = 1; i <= q; i++){
            // scanf("%d", &u);
            cin >> u;

            if (!vis[u] or neg[u] or dist[u] < 3 /*or dist[u] >= INF*/){
                // printf("?\n");
                cout << "?" << endl;
            }
            else{
                // printf("%d\n", dist[u]);
                cout << dist[u] << endl;
            }
        }

        for (i = 1; i <= n; i++){
            g[i].clear();
        }
    }

    return 0;
}