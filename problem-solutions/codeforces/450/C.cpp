#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 100002;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		v[i-1] = i;
	}

	do{
		for(int i = 0; i < n; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
	}while(next_permutation(v, v+n));

	return 0;
}