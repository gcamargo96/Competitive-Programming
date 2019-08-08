#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000005;
int v[2*N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		v[i] = i;
	}

	int end = n+1;
	for(int k = 2; k <= n; k++){
		v[end] = v[end-(n%k)];
		for(int j = end-(n%k); j > end-n; j -= k){
			v[j] = v[j-k];
		}
		end++;
	}

	for(int i = end-n; i < end; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}