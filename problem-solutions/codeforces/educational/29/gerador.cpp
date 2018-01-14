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

int main(void){
	printf("200000\n");

	srand(time(NULL));
	for(int i = 0; i < 200000; i++){
		int x = rand()%1000000000 + 1;
		printf("%d ", x);
	}

	printf("\n");

	return 0;
}