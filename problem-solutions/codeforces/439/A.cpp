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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 4002;
int n;
int x[N], y[N];
set<int> s;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
		s.insert(x[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &y[i]);
		s.insert(y[i]);
	}


	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int aux = x[i] ^ y[j];
			if(s.count(aux)) ans++;
		}
	}

	if(ans%2 == 0){
		printf("Karen\n");
	}
	else{
		printf("Koyomi\n");
	}

	return 0;
}