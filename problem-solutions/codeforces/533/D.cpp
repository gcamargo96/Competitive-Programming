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

struct node{
	int x, y, step;

	node() {}

	node(int _x, int _y, int _step){
		x = _x;
		y = _y;
		step = _step;
	}
};

const int N = 1005;
char g[N][N];
int n, m, p;
int s[12], cur[12], cnt[12];
queue<node> q[12];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

int main(void){
	scanf("%d%d%d", &n, &m, &p);

	for(int i = 1; i <= p; i++){
		scanf("%d", &s[i]);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);

			if(g[i][j] >= '1' and g[i][j] <= '9'){
				q[g[i][j]-'0'].push(node(i, j, 0));
				cnt[g[i][j]-'0']++;
			}
		}
	}

	while(1){
		// printf("aqui\n");

		bool stop = 1;
		for(int i = 1; i <= p; i++){
			if(!q[i].empty()) stop = 0;

			while(!q[i].empty() and q[i].front().step < cur[i] + s[i]){
				int x = q[i].front().x;
				int y = q[i].front().y;
				int st = q[i].front().step;
				q[i].pop();

				for(int j = 0; j < 4; j++){
					int nx = x + dir[j][0];
					int ny = y + dir[j][1];

					if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and g[nx][ny] == '.'){
						q[i].push(node(nx, ny, st+1));
						g[nx][ny] = i+'0';
						cnt[i]++;
					}
				}
			}

			cur[i] += s[i];
		}

		if(stop) break;
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		printf("%c", g[i][j]);
	// 	}
	// 	printf("\n");
	// }


	for(int i = 1; i <= p; i++){
		printf("%d ", cnt[i]);
	}
	printf("\n");

	return 0;
}