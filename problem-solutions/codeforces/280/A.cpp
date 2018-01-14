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

	int alt = 0, need = 1, tem = n;

	int res = 0;
	for(int i = 2; tem >= need; i++){
		tem -= need;
		need += i;
		res++;
	}

	printf("%d\n", res);
	return 0;
}

