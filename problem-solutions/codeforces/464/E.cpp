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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500002;
int n, cnt = 0;
double sum = 0, mean = 0, mx = 0;
multiset<double> ms, sb;

int main(void){
	scanf("%d", &n);

	int op, x;
	for(int i = 0; i < n; i++){
		scanf("%d", &op);

		if(op == 1){
			scanf("%d", &x);
			ms.insert(x);
			mx = x;
			mean = (sum + mx)/double(sb.size()+1);

			for(auto it = ms.begin(); it != ms.end();){
				if(*it > mean)
					break;

				sum += *it;
				sb.insert(*it);
				mean = (sum+mx)/double(sb.size()+1);
				it = ms.erase(it);
			}
		}
		else{
			double ans = mx - mean;
			printf("%.10lf\n", ans);
		}
	}

	return 0;
}