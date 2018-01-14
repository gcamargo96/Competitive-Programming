#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define BEG 0
#define END 1
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1002;
int t, n;
int v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		int last = 0;
		bool ans = 1;
		for(int i = 0, j = n-1; i <= j; i++, j--){
			if(v[i] != v[j]){
				ans = 0;
				break;
			}
			else if(v[i] != last and v[i] != last+1){
				ans = 0;
				break;
			}
			last = v[i];
		}

		if(ans and last == 7){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}