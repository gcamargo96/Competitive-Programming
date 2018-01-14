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

const int N = 100002;
int T, n;
map<string,int> m;
int pai[N], rank[N], tam[N];
int cnt;

void init(){
	cnt = 0;
	m.clear();

	For(i,0,N){
		pai[i] = i;
		rank[i] = 1;
		tam[i] = 1;
	}
}

int find(int x){
	if(pai[x] == x) return pai[x];
	return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(rank[a] < rank[b]) swap(a,b);
	if(a != b){
		if(rank[a] == rank[b]) rank[a]++;
		pai[b] = a;
		tam[a] += tam[b];
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	while(T--){
		init();
		cin >> n;

		string a, b;
		For(i,0,n){
			cin >> a >> b;
			if(!m.count(a)) m[a] = cnt++;
			if(!m.count(b)) m[b] = cnt++;

			join(m[a],m[b]);
			int x = find(m[a]);
			cout << tam[x] << endl;
		}
	}

	return 0;
}
