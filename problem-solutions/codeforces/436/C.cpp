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

int a, b, f, k;

bool test(int mi){
	int fuel = b - f, cnt = 0;

	// if(fuel < 0) return 0;

	for(int i = 0; i < k-1; i++){
		if(i%2 == 0){ // ida
			if(fuel < 2 * (a-f)){
				fuel = b;
				cnt++;
			}
			fuel -= 2 * (a-f);
			// if(fuel < 0){
			// 	return 0;
			// }
		}
		else{ // volta
			if(fuel < 2*f){
				fuel = b;
				cnt++;
			}
			fuel -= 2*f;
			// if(fuel < 0){
			// 	return 0;
			// }
		}
	}

	if((k-1)%2 == 0){ // ida
		if(fuel < (a-f)){
			fuel = b;
			cnt++;
		}
		fuel -= (a-f);
		// if(fuel < 0){
		// 	return 0;
		// }
	}
	else{ // volta
		if(fuel < f){
			fuel = b;
			cnt++;
		}
		fuel -= f;
		// if(fuel < 0){
		// 	return 0;
		// }
	}

	return cnt <= mi;
}

int main(void){
	scanf("%d%d%d%d", &a, &b, &f, &k);

	if(f > b or a-f > b){
		cout << -1 << endl;
		return 0;
	}
	if(k > 1 and 2*(a-f) > b){
		cout << -1 << endl;
		return 0;
	}
	if(k > 2 and 2*f > b){
		cout << -1 << endl;
		return 0;
	}

	int lo = 0, hi = k, ans = 0;
	while(lo <= hi){
		int mi = (lo+hi)/2;
		if(test(mi)){
			ans = mi;
			hi = mi-1;
		}
		else{
			lo = mi+1;
		}
	}

	printf("%d\n", ans);

	return 0;
}