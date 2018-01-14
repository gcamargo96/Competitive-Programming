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

int n;

int main(void){
	scanf("%d", &n);

	int x, id = -1, sum = 0;
	For(i,0,n){
		scanf("%d", &x);
		sum += x;

		if(x and id == -1) id = i;
	}
	if(id == -1){
		printf("NO\n");
		return 0;
	}

	if(sum){
		printf("YES\n");
		printf("1\n");
		printf("1 %d\n", n);
	}
	else{
		printf("YES\n");
		printf("2\n");
		printf("1 %d\n", id+1);
		printf("%d %d\n", id+2, n);
	}

	return 0;
}

