#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n, tem, m;
vector<int> res;
bool vis[52];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> tem;

	For(i,0,n){
		cin >> m;
		int x;
		For(j,0,m){
			cin >> x;
			if(tem > x and !vis[i]){
				res.pb(i+1);
				vis[i] = 1;
			}
		}
	}

	cout << res.size() << endl;
	For(i,0,res.size()){
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
