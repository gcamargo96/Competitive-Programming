#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

const int N = 300002;
int n, m;
map<int,int> adj[N];
int cnt[N], res[N];

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("intouch.in", "r", stdin);
	freopen("intouch.out", "w", stdout);
	cin >> n >> m;

	char c;
	int a, b;
	while(m--){
		cin >> c;
		if(c == '!'){
			cin >> a;
			cnt[a]++;
		}
		if(c == '+'){
			cin >> a >> b;
			adj[a][b] = cnt[b];
			adj[b][a] = cnt[a];
		}
		if(c == '-'){
			cin >> a >> b;
			res[a] += cnt[b]-adj[a][b];
			adj[a].erase(b);
			res[b] += cnt[a]-adj[b][a];
			adj[b].erase(a);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(auto it = adj[i].begin(); it != adj[i].end(); it++){
			res[i] += cnt[it->first] - it->second;
			//cout << i << " -> " << it->first << " : " << it->second << endl;
			//cout << "res[" << i << "] += " << cnt[it->first]-it->second << endl;
		}
	}

	for(int i = 1; i <= n; i++){
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
