#include <bits/stdc++.h>
using namespace std;
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

int n, a, b;

int main(void){
	scanf("%d%d%d", &n, &a, &b);
	if(a > b)
		swap(a,b);

	vi v;
	for(int i = 1; i <= n; i++){
		v.pb(i);
	}

	int rd = 1;
	while(v.size() > 1){
		vi aux;
		// cout << "sz = " << v.size() << endl;
		for(int i = 0; i < v.size(); i += 2){
			// if(v.size() == 2){
			// 	printf("%d %d\n", v[i], v[i+1]);
			// }

			if(v[i] == a and v[i+1] == b){
				if(v.size() == 2){
					printf("Final!\n");
				}
				else{
					printf("%d\n", rd);
				}
				return 0;
			}
			else if(v[i] == a or v[i] == b){
				aux.pb(v[i]);
			}
			else{
				aux.pb(v[i+1]);
			}
		}
		v = aux;
		rd++;
	}


	return 0;
}