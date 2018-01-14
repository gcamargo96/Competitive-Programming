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

const int N = 200002;
int p[N], z[N];
int n;
int s[N];

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] == 0){
			s[i] = cnt++;
		}
		else{
			s[i] = s[p[i]];
		}
	}

	for(int i = 0; i < n; i++){
		s[i] = s[i+1];
	}

	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i <= r)
			z[i] = min(z[i-l], r-i+1);
		while(z[i]+i < n and s[z[i]+i] == s[z[i]])
			z[i]++;
		if(r < i+z[i]-1)
			l = i, r = i+z[i]-1;
	}

	For(i,0,n){
		printf("%d ", z[i]);
	}
	printf("\n");

	return 0;
}

