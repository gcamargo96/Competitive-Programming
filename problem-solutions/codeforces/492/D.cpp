#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 202;
int n;
vi v;

void print(){
	for(int i = 0; i < 2*n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < 2*n; i++){
		scanf("%d", &x);
		v.pb(x);
	}

	int ans = 0;
	for(int i = 0; i < 2*n-1; i++){
		for(int j = i+1; j < 2*n; j++){
			if(v[i] == v[j]){
				ans += j-i-1;
				v.erase(v.begin() + j);
				v.insert(v.begin()+i+1, v[i]);

				// print();
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}