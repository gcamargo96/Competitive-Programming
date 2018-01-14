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

const int N = 102;
int n, k, g, t;
char s[N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
		if(s[i] == 'G') g = i;
		if(s[i] == 'T') t = i;
	}

	while(g > t){
		g -= k;

		if(s[g] == '#'){
			cout << "NO" << endl;
			return 0;
		}
		if(g == t){
			printf("YES\n");
			return 0;
		}
		if(g < t){
			printf("NO\n");
			return 0;
		}
	}

	while(g < t){
		g += k;
		
		if(s[g] == '#'){
			cout << "NO" << endl;
			return 0;
		}
		if(g == t){
			printf("YES\n");
			return 0;
		}
		if(g > t){
			printf("NO\n");
			return 0;
		}
	}

	return 0;
}

