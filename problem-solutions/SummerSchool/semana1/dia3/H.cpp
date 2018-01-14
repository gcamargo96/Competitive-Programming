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

	if(n == 1){
		printf("YES\n");
		return 0;
	}
	if(n == 4){
		printf("NO\n");
		return 0;
	}

	int raiz = sqrt(n);
	bool prime = 1;
	for(int i = 2; i <= raiz; i++){
		if(n%i == 0) prime = 0;
	}

	if(prime){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}

	return 0;
}

