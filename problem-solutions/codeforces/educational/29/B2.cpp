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

#define HEAL 0
#define STRIKE 1

int h1, a1, c1;
int h2, a2;

int main(void){
	scanf("%d%d%d", &h1, &a1, &c1);
	scanf("%d%d", &h2, &a2);

	vi ans;
	while(h2 > 0){
		if(a1 >= h2){
			ans.pb(STRIKE);
			break;	
		}
		else if(h1 > a2){
			ans.pb(STRIKE);
			h2 -= a1;
			
			h1 -= a2;
		}
		else{
			ans.pb(HEAL);
			h1 += c1 - a2;
		}
	}

	printf("%d\n", (int) ans.size());

	for(int i = 0; i < ans.size(); i++){
		if(ans[i] == STRIKE)
			printf("STRIKE\n");
		else
			printf("HEAL\n");
	}

	return 0;
}