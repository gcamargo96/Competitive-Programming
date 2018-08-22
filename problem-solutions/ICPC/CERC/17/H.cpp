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
	string s;
	ll size;

	node() {}

	node(string _s){
		s = _s;
		size = 0;
	}

	map<string, node*> children;

	bool operator<(const node& b) const{
		return s < b.s;
	}
};

int n;
node* root = new node("/");
string path;
ll t;

vector<string> split(string& s, char c){
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

void insert(vector<string>& path, int tam){
	node* cur = root;
	cur->size += tam;

	for(string s : path){
		if(!cur->children.count(s)){
			node* novo = new node(s);
			cur->children[s] = novo;
		}
		cur = cur->children[s];
		cur->size += tam;
	}
}

void dfs(node* cur){
	path += cur->s;
	if(cur->s != "/") path += "/";
	// cout << path << " " << cur->size << endl;

	bool flag = 0;
	for(auto it : cur->children){
		if(it.se->size >= t){
			flag = 1;
		}
	}

	if(flag){
		cout << "- " << path << " " << cur->size << endl;

		for(auto it : cur->children){
			dfs(it.se);
		}
	}
	else if(cur->children.size() > 0){
		cout << "+ " << path << " " << cur->size << endl;
	}
	else{
		cout << "  " << path << " " << cur->size << endl;
	}

	if(cur->s != "/") path.pop_back();
	for(int i = 0; i < cur->s.size(); i++){
		path.pop_back();
	}
}

int main(void){
	fastcin;
	cin >> n;

	string s;
	int tam;
	for(int i = 0; i < n; i++){
		cin >> s >> tam;

		vector<string> path = split(s, '/');
		path.pop_back();

		insert(path, tam);
	}
	cin >> t;

	dfs(root);

	return 0;
}