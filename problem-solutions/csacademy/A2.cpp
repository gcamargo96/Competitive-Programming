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

int n, m;
int X1, Y1, X2, Y2;

int dist(int X1, int Y1, int X2, int Y2){
	return (int) abs(X1-X2) + abs(Y1-Y2);
}

int main(void){
	scanf("%d%d", &n, &m);
	scanf("%d%d", &X1, &Y1);
	scanf("%d%d", &X2, &Y2);

	int ans = 0;
	if(dist(X1, Y1, X2, Y2)%2 == 0){
		if(abs(X1-X2) == abs(Y1-Y2)){
			if(X1 > X2 and Y1 > Y2){
				ans += (m-X1+1)*(Y2);
				ans += (X2)*(n-Y1+1);
			}
			else if(X2 > X1 and Y2 > Y1){
				ans += (m-X2+1)*(Y1);
				ans += (X1)*(n-Y2+1);	
			}
			else if(X1 > X2 and Y1 < Y2){
				ans += (m-X1+1)*(n-Y2+1);
				ans += (X2*Y1);
			}
			else if(X1 < X2 and Y1 > Y2){
				ans += (m-X2+1)*(n-Y1+1);
				ans += (X1*Y2);
			}

		}
		else if(abs(X1-X2) > abs(Y1-Y2)){
			if(abs(Y1-Y2) > 0) ans += n - int(abs(Y1-Y2)) + 1;
			else ans = n; 
			// printf("aqui\n");
		}
		else if(abs(X1-X2) < abs(Y1-Y2)){
			if(abs(X1-X2) > 0) ans += m - int(abs(X1-X2)) + 1;
			else ans = m;
		}
	}

	printf("%d\n", ans);

	return 0;
}