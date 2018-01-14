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


const int N = 26;
int k;

int main(void){
	scanf("%d", &k);

	int maior = 0, x;
	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		maior = max(maior, x);
	}

	if(maior <= 25){
		printf("0\n");
	}
	else{
		int ans = maior-25;
		printf("%d\n", ans);
	}

	return 0;
}