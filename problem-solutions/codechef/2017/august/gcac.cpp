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
int t, n, m;
int minSalary[N], offeredSalary[N], maxJobOffers[N], cntEmployees[N];
vector<int> offers[N];

bool cmp(int a, int b){
	return offeredSalary[a] > offeredSalary[b];
}

void init(){
	memset(cntEmployees, 0, sizeof cntEmployees);
	for(int i = 0; i < N; i++){
		offers[i].clear();
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d%d", &n, &m);

		for(int i = 1; i <= n; i++){
			scanf("%d", &minSalary[i]);
		}

		for(int i = 1; i <= m; i++){
			scanf("%d%d", &offeredSalary[i], &maxJobOffers[i]);
		}

		char c;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf(" %c", &c);
				if(c == '1'){
					offers[i].pb(j);
				}
			}
		}

		for(int i = 1; i <= n; i++){
			sort(offers[i].begin(), offers[i].end(), cmp);
		}

		int employed = 0;
		ll amount = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < offers[i].size(); j++){
				int comp = offers[i][j];
				if(offeredSalary[comp] >= minSalary[i] and cntEmployees[comp] < maxJobOffers[comp]){
					cntEmployees[comp]++;
					employed++;
					amount += offeredSalary[comp];
					break;
				}
			}
		}

		int hadntHired = 0;
		for(int i = 1; i <= m; i++){
			if(cntEmployees[i] == 0) hadntHired++;
		}

		printf("%d %lld %d\n", employed, amount, hadntHired);
	}

	return 0;
}