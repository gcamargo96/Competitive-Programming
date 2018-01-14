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

int x;

int main(void){
	printf("PERFECTION OUTPUT\n");
	
	while(scanf("%d", &x) and x != 0){
		vector<int> factors;
		int aux = x;
		// factors.pb(1);

		for(int i = 1; i < x; i++){
			if(x%i == 0){
				factors.pb(i);
			}
		}

		int sum = 0;
		for(int i = 0; i < factors.size(); i++){
			sum += factors[i];
		}


		// factors.resize(unique(factors.begin(), factors.end()) - factors.begin());
	
		/*for(int i = 0; i < factors.size(); i++){
			printf("%d ", factors[i]);
		}
		printf("\n");
		*/

		if(sum == x){
			printf("%5d  PERFECT\n", x);
		}
		else if(sum < x){
			printf("%5d  DEFICIENT\n", x);
		}
		else{
			printf("%5d  ABUNDANT\n", x);
		}
	}

	printf("END OF OUTPUT\n");

	return 0;
}