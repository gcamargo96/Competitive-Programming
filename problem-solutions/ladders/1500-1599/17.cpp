#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int v[N];
int n, sum;

int main(void){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		sum += v[i];
	}

	sort(v, v+n);

	int sum2 = 0, res = 0;
	for(int i = n-1; i >= 0; i--){
		sum2 += v[i];
		res++;
		if(sum2 > sum/2) break;
	}

	printf("%d\n", res);

	return 0;
}

