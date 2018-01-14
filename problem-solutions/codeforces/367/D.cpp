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

int n;

struct Trie{
	int cnt;
	map<int,Trie> adj;

	Trie(){
		cnt = 0;
		adj.clear();
	}

	void insert(vector<int>& v, int i){
		cnt++;
		if(i == v.size()) return;
		adj[v[i]].insert(v, i+1);
	}

	void erase(vector<int>& v, int i){
		cnt--;
		if(i == v.size()+1) return;
		adj[v[i]].erase(v, i+1);
	}

	int query(vector<int>& v, int i){
		if(i == v.size()+1) return 0;
		if(v[i] == 0){
			if(adj.count(1) and adj[1].cnt > 0) return adj[1].query(v, i+1) + (1 << (31-i));
			else return adj[0].query(v, i+1);
		}
		else{
			if(adj.count(0) and adj[0].cnt > 0) return adj[0].query(v, i+1) + (1 << (31-i));
			else return adj[1].query(v, i+1);
		}
	}
};

Trie tr;

void init(){
	vector<int> v;
	For(i,0,32){
		v.pb(0);
	}
	tr.insert(v, 0);
}

int main(void){
	ios_base::sync_with_stdio(false);
	init();
	cin >> n;
	
	char c;
	int x;
	For(i,0,n){
		cin >> c >> x;
		vector<int> v;
		For(j,0,32){
			v.pb(x%2);
			x /= 2;
		}
		reverse(v.begin(), v.end());

		if(c == '+'){
			tr.insert(v, 0);
		}
		if(c == '-'){
			tr.erase(v, 0);
		}
		if(c == '?'){
			int res = tr.query(v, 0);
			cout << res << endl;
		}
	}

	return 0;
}
