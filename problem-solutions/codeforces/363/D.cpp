#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 200002;
int n, root = -1, res = 0;
int pai[N], vis[N];

void dfs(int x){
	vis[x] = 1;
	
	if(pai[x] == x and x != root){
		pai[x] = root;
		res++;
	}	
	else if(vis[pai[x]] == 0){
		dfs(pai[x]);
	}
	else if(vis[pai[x]] == 1 and pai[x] != x){
		if(root == -1){
			pai[x] = x;
			root = x;
		}
		else{
			pai[x] = root;
		}
		res++;
	}
	vis[x] = 2;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i, 1, n+1){
		cin >> pai[i];
		if(pai[i] == i) root = i;
	}

	For(i, 1, n+1){
		if(!vis[i]){
			dfs(i);
		}
	}

	cout << res << endl;
	For(i, 1, n+1){
		cout << pai[i] << " ";
	}
	cout << endl;

	return 0;
}
