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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, x;

int main(void){
	scanf("%d%d", &n, &x);

	if(x == 0 and n == 2){
		printf("NO\n");
	}

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		ans ^= i;
	}

	int extra = 0;
	for(int i = 0; i <= 20; i++){
		if(((ans>>i)&1) != ((x>>i)&1)){
			extra |= (1<<i);
		}
	}

	// printf("%d\n", (1<<6));

	printf("YES\n");

	int first = 0;
	if(extra >= n-1){
		for(int i = 0; i < n-1; i++){
			printf("%d ", i);
		}
		printf("%d\n", extra);
	}
	else{
		extra |= (1<<19);
		first = (1<<19);
		printf("%d ", first);
		for(int i = 1; i < n-1; i++){
			printf("%d ", i);
		}
		printf("%d\n", extra);
	}


	return 0;
}