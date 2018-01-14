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

const int N = 1000002;
int pai[N], Rank[N];
int n, T, a, b;
char c;

void init(){
	For(i,0,N){
		pai[i] = i;
		Rank[i] = 1;
	}
}

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(Rank[a] < Rank[b]) swap(a,b);
	if(a != b){
		if(Rank[a] == Rank[b]) Rank[a]++;
		pai[b] = a;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	while(T--){
		init();
		cin >> n;
		cin.get();
		string s;

		int ok = 0, wrong = 0;
		while(getline(cin, s) and s.size() > 0){
			stringstream ss;
			ss << s;
			ss >> c >> a >> b;

			if(c == 'c'){
				join(a, b);
			}
			else{
				if(find(a) == find(b)) ok++;
				else wrong++;
			}
		}

		cout << ok << "," << wrong << endl;
		if(T >= 1) cout << endl;
	}

	return 0;
}
