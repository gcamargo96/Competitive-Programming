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

const int N = 102;
int n;
int vis[N], in[N];
vi adj[N];
set<int> s;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		adj[i].pb(x);
		in[x]++;
	}

	for(int i = 1; i <= n; i++){
		if(in[i] == 0){
			cout << -1 << endl;
			return 0;
		}
	}

	for(int i = 1; i <= n; i++){
		int t = 0, u = i;
		while(!vis[u]){
			vis[u] = 1;
			u = adj[u][0];
			t++;
		}
		if(t == 0) continue;
		if(t%2 == 0) s.insert(t/2);
		else s.insert(t);
	}


	int res = 1;
	for(int x : s){
		//cout << x << " ";
		res = lcm(res, x);
	}
	//cout << endl;

	cout << res << endl;

	return 0;
}

