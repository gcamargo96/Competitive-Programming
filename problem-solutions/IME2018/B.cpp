#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
#define INF 0x3f3f3f3f

int n, m;
string s[1002];
int item[1002];
int w0, wsi;
int dp[1002][1002];
bool choice[1002][1002]; 
vector<int> ans;
char saux[1002][12];

int solve(int i, int cap){
	// cout << cap << endl;
	if(cap <= 0) return 0;
	if(i == m) return INF;
	if(dp[i][cap] != -1) return dp[i][cap];

	int ret = INF;
	ret = min(ret, solve(i+1, cap));
	choice[i][cap] = 0;

	int aux = solve(i+1, cap-item[i]) + item[i];
	if(aux < ret){
		ret = aux;
		choice[i][cap] = 1;
	}

	return dp[i][cap] = ret;
}

void build(int i, int cap){
	if(cap <= 0 or i == m) return;

	if(choice[i][cap] == 0){
		build(i+1, cap);
	}
	else{
		ans.pb(i);
		build(i, cap-item[i]);
	}
}

int main(void){
	// cin >> w0 >> m;
	scanf("%d%d", &w0, &m);

	for(int i = 0; i < m; i++){
		// cin >> s[i] >> item[i];
		scanf("%s", saux[i]);
		scanf("%d", &item[i]);
	}

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> wsi;
		int cap = (wsi+1)/2 - w0; 
		// cout << "cap = " << cap << endl;

		if(cap > 0){
			memset(choice, 0, sizeof choice);
			memset(dp, -1, sizeof dp);
			int peso = solve(0, cap);

			// cout << "peso = " << peso << endl;

			if(peso < INF and peso >= cap){
				ans.clear();
				build(0, cap);
				
				// cout << ans.size() << " ";
				printf("%d ", int(ans.size()));
				for(int j = 0; j < ans.size(); j++){
					// cout << ans[j] << " ";
					printf("%s ", saux[ans[j]]);
				}
				// cout << endl;
				printf("\n");
			}
			else{
				// cout << -1 << endl;
				printf("-1\n");
			}
		}
		else{
			// cout << 0 << endl;
			printf("0\n");
			continue;			
		}
	}

	return 0;
}