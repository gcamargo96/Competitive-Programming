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
int v[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = 1; i <= n/2; i++){
		if(i%2 == 1){
			swap(v[i], v[n-i+1]);
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}

