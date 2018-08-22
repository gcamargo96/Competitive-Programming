#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, x, c25, c50;
bool ok = 1;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &x);
		if(x == 25) c25++;
		else if(x == 50){
			c50++;
			if(c25 >= 1) c25--;
			else{
				ok = 0;
				break;
			}
		}
		else if(x == 100){
			if(c50 >= 1 and c25 >= 1){
				c50--;
				c25--;
			}
			else if(c25 >= 3) c25 -= 3;
			else{
				ok = 0;
				break;
			}
		}
	}

	if(ok) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}

