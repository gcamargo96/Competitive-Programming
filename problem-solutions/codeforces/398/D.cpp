#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1000002;
int f[N];
int n, m, k;
ii s[N];

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	For(i,0,n){
		scanf("%d", &f[i]);
	}

	int x;
	For(i,0,m){
		scanf("%d", &x);
		s[i].fi = x;
		s[i].se = i+1;
	}

	sort(f, f+n);
	sort(s, s+m);

	s[m].fi = INF;

	int dia = 0;
	bool ok = 1;
	For(i,0,n){
		if(i%k == 0) dia++;
		if(f[i] < dia) ok = 0;
	}

	if(!ok){
		printf("-1\n");
		return 0;
	}

	dia = 0;
	int j = 0;
	for(int i = 0; i < n; i++){
		while(j < m and s[j].fi < dia){
			j++;
		}

		if(dia == s[j].fi)
	}	

	return 0;
}

