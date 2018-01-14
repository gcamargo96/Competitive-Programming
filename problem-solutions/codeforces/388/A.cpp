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

	vector<int> res;
	int sum = 0;
	
	if(n%2 == 1){
		res.pb(3);
		sum += 3;
	}

	while(sum < n){
		sum += 2;
		res.pb(2);
	}

	printf("%d\n", res.size());

	For(i,0,res.size()){
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}

