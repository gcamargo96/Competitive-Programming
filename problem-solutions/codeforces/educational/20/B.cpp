#include <bits/stdc++.h>
using namespace std;
#define INF 200005
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;	
int n;
int v[N];
int l[N], r[N];

int main(void){
	scanf("%d", &n);

	l[0] = INF;
	r[n+1] = INF;

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = 1; i <= n; i++){
		if(v[i] == 0){
			l[i] = 0;
		}
		else{
			l[i] = l[i-1] + 1;
		}
	}

	for(int i = n; i >= 1; i--){
		if(v[i] == 0){
			r[i] = 0;
		}
		else{
			r[i] = r[i+1] + 1;
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", min(l[i], r[i]));
	}
	printf("\n");

	return 0;
}