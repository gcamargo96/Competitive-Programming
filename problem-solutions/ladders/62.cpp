#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, m;
int color[N];
set<int> s[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i,1,n+1){
		scanf("%d", &color[i]);
	}

	int u, v;
	For(i,0,m){
		scanf("%d%d", &u, &v);
		if(color[u] != color[v]){
			s[color[u]].insert(color[v]);
			s[color[v]].insert(color[u]);
		}
	}

	/*for(int i = 1; i <= 8; i++){
		printf("%d ", s[i].size());
	}
	printf("\n");
	*/

	int res = 0, maior = -1;
	for(int i = 1; i < N; i++){
		if((int)s[i].size() > maior){
			//cout << "entrou" << endl;
			maior = s[i].size();
			res = i;
		}
	}

	printf("%d\n", res);

	return 0;
}

