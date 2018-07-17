#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100005;
map<int,int> avaible;
int v[N];
int n;

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		v[i] = x;
		avaible[x]++;
	}

	sort(v, v+n);

	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		auto it = avaible.lower_bound(v[i]);
		if(it == avaible.begin()){ // menor de todos
			it = avaible.end();
			it--;

			it->se--;
			if(it->se == 0){
				avaible.erase(it);
			}
			continue;
		}

		it--;
		it->se--;
		if(it->se == 0){
			avaible.erase(it);
		}
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}