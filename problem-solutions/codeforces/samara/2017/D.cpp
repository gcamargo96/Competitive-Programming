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

const int N = 200002;
int n, x;
int a[N];

int main(void){
	scanf("%d%d", &n, &x);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int g = a[0];
	for(int i = 1; i < n; i++){
		g = __gcd(g, a[i]);
	}

	if(x%g == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}