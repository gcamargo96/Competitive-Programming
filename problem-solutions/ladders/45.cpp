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

int cnt[10];
string num;
vector<int> divs;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> num;

	For(i,0,num.size()){
		cnt[num[i]-'0']++;
	}

	int x = 8;
   	while(x < 1000){
		divs.pb(x);
		x += 8;
	}

	if(cnt[0] > 0){
		printf("YES\n0\n");
		return 0;
	}

	For(i,0,divs.size()){
		x = divs[i];
		int c = x%10;
		x /= 10;
		int b = x%10;
		x /= 10;
		int a = x;
		
		if(a == 0 and b == 0 and cnt[c] > 0){
			printf("YES\n");
			printf("%d\n", c);
			return 0;
		}
		else if(a == 0 and cnt[b] > 0 and cnt[c] > 0){
			if(b == c and cnt[b] < 2) continue;
			
			bool ok = 0, viub = 0, viuc = 0;
			For(i,0,num.size()){
				if(num[i] == c+'0' and viub) viuc = 1;
				if(num[i] == b+'0') viub = 1;
			}
		
			if(viub and viuc){	
				printf("YES\n");
				printf("%d%d\n", b, c);
				return 0;
			}
		}
		else if(cnt[a] and cnt[b] and cnt[c]){
			if(a == b and a == c and cnt[a] < 3) continue;
			if(a == b and cnt[a] < 2) continue;
			if(b == c and cnt[b] < 2) continue;
			if(a == c and cnt[a] < 2) continue;
			
			bool viua = 0, viub = 0, viuc = 0;
			For(i,0,num.size()){
				if(num[i] == c+'0' and viub and viua) viuc = 1;
				if(num[i] == b+'0' and viua) viub = 1;
				if(num[i] == a+'0') viua = 1;
			}
			
			if(viua and viub and viuc){
				printf("YES\n");
				printf("%d%d%d\n", a, b, c);
				return 0;
			}
		}
	}

	printf("NO\n");

	return 0;
}

