#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
const int M = 20;

struct node{
	node *nxt[2];
	node *p;
	int d;
	int leaves;

	node() : d(0), leaves(0), p(NULL) {
		memset(nxt, 0, sizeof nxt);
	}
};

typedef node* trie;
trie root = new node();

void add(int x, int pos, trie cur){
	if(pos < 0){
		cur->leaves = 1;
		return;
	}

	int d = (x>>pos)&1;

	if(!cur->nxt[d]){
		trie son = new node();
		son->p = cur;
		son->d = d;	
		cur->nxt[d] = son;
	}

	add(x, pos-1, cur->nxt[d]);

	cur->leaves = 0;
	if(cur->nxt[0]) cur->leaves += cur->nxt[0]->leaves;
	if(cur->nxt[1]) cur->leaves += cur->nxt[1]->leaves;
}

bool search(int x, int pos, trie cur){
	if(pos < 0) return 1;

	int d = (x>>pos)&1;

	if(!cur->nxt[d]) return 0;

	return search(x, pos-1, cur->nxt[d]);
}

int solve(int x, int pos, trie cur){
	if(pos < 0) return 0;

	int d = (x>>pos)&1;

	if(!cur->nxt[d]){
		return 0;
	}
	else if(cur->nxt[d]->leaves < (1<<pos)){
		return solve(x, pos-1, cur->nxt[d]);
	}
	else if(!cur->nxt[!d]){
		return (1<<pos);
	}
	else{
		return (1<<pos) | solve(x, pos-1, cur->nxt[!d]);
	}
}

int n, m;

int main(void){
	//ios_base::sync_with_stdio(false);
	/* testing the trie:
	add(90, M, root);
	add(120, M, root);
	if(search(90, M, root)) cout << "OK1" << endl;
	if(search(120, M, root)) cout << "OK2" << endl;
	if(!search(50, M, root)) cout << "OK3" << endl;
	*/
	cin >> n >> m;

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		add(x, M, root);
	}
	
	int ans, curxor = 0;
	while(m--){
		scanf("%d", &x);
		curxor ^= x;
		ans = solve(curxor, M, root);
		printf("%d\n", ans);
	}

	return 0;
}