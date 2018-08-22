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

const int N = 100005;
int n, m;
int c[N];
set<int> s[N];
set<int> cores;

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		cores.insert(c[i]);
	}

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		if(c[u] != c[v]){
			s[c[u]].insert(c[v]);
			s[c[v]].insert(c[u]);
		}
	}

	int mx = -1, id = 1;
	for(int i : cores){
		// printf("i = %d, size = %d, mx = %d\n", i, (int)s[i].size(), mx);
		if(mx < int(s[i].size())){
			// printf("aqui %d\n", i);
			mx = s[i].size();
			id = i;
		}
	}

	printf("%d\n", id);

	return 0;
}