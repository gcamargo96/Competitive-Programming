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

map<int, int> m;
vector<int> v;
int T, n;

int main(void){
	scanf("%d", &T);

	For(k,0,T){
		v.clear();
		m.clear();
		scanf("%d", &n);

		int x;
		For(i,0,n){
			scanf("%d", &x);
			v.pb(x);
		}
		
		int res = 0;

		int j = 0;
		For(i,0,n){
			while(j < n and !m.count(v[j])){
				m[v[j]] = 1;
				j++;
			}
			if(m.size() > res) res = m.size();
			m.erase(v[i]);
		}

		printf("%d\n", res);
	}

	return 0;
}
