#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define BEG 0
#define END 1
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 52;
int t, n;
vector<int> v;
set<vector<int> > s; 

int solve(int p, int last){
	for(int i = 0; i < N; i++){

	}
}

void solve(vector<int>& v){
	if(s.count(v)) return;
	s.insert(v);

	for(int i = 0; i < v.size()-1; i++){
		if(v[i] > 0 and v[i+1] > 0){
			v[i]--;
			v[i+1]--;
			if(i < v.size()-2){
				v[i+2]++;
				solve(v);
				v[i+2]--;
			}
			else{
				v.pb(1);
				solve(v);
				v.pop_back();
			}
			v[i]++;
			v[i+1]++;
		}
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		v.clear();
		s.clear();
		scanf("%d", &n);

		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			v.pb(x);
		}

		solve(v);

		printf("%d\n", (int)s.size());
	}

	return 0;
}