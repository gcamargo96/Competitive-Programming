#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1000002;
int n;

int main(void){
	scanf("%d", &n);

	int a, b, menor = N;
	For(i,1,n+1){
		if(n%i == 0){
			int B = n/i;
			if(abs(B-i) < menor){
				menor = abs(B-i);
				a = i, b = B;
			}
		}
	}

	printf("%d %d\n", a, b);

	return 0;
}

