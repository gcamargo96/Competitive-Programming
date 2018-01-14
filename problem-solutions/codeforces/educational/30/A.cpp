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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, k, x;
int v[N];

int main(void){
	scanf("%d%d%d", &n, &k, &x);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = n-k; i < n; i++){
		v[i] = x;
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];
	}

	printf("%d\n", sum);

	return 0;
}