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

const int N = 60002;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < N; i++){
		v[i] = i+1;
	}

	if(n%4 == 0){
		printf("0\n");
		printf("%d ", n/2);
		for(int i = 0; i < n/4; i++){
			printf("%d %d ", v[i], v[n-1-i]);
		}
		printf("\n");
	}
	else if(n%4 == 1){
		printf("1\n");
		printf("%d ", (n-1)/2);
		for(int i = 0; i < (n-1)/4; i++){
			printf("%d %d ", v[i+1], v[n-1-i]);
		}
		printf("\n");
	}
	else if(n%4 == 2){
		printf("%d\n", 1);
		printf("%d ", (n-2)/2+1);
		for(int i = 0; i < (n-2)/4; i++){
			printf("%d %d ", v[i+2], v[n-1-i]);
		}
		printf("1\n");
	}
	else{
		printf("0\n");
		printf("%d ", (n-3)/2 + 2);
		for(int i = 0; i < (n-3)/4; i++){
			printf("%d %d ", v[i+3], v[n-1-i]);
		}
		printf("1 2\n");
	}

	return 0;
}