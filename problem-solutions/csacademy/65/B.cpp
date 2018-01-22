#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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
typedef complex<double> base;

const int N = 100002;
int n;
set<ii> s, s2;

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		if(u > v)
			swap(u,v);

		s.insert(ii(u,v));
	}

	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		if(u > v)
			swap(u,v);
		s2.insert(ii(u,v));
	}

	int sub = 0;
	for(ii x : s){
		if(!s2.count(x))
			sub++;
	}

	int ans = int(s.size()) - sub;
	printf("%d\n", ans);

	return 0;
}