#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 105;
int n;
char v[N];
bool has[N], has1[N], has2[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			v[i] = 'B';
		}
		else{
			v[i] = 'W';
		}
	}

	int pos;
	for(int i = 0; i < n/2; i++){
		scanf("%d", &pos);	
		has[pos-1] = 1;
		has1[pos-1] = 1;
		has2[pos-1] = 1;
	}

	int ans1 = 0; // all in black
	for(int i = 0; i < n; i++){
		if(v[i] == 'B' and has1[i] == 0){
			bool found = 0;
			for(int j = i-1; j >= 0; j -= 2){
				if(has1[j]){
					ans1 += i-j;
					has1[i] = 1;
					has1[j] = 0;
					found = 1;
					break;
				}
			}

			if(!found){
				for(int j = i+1; j < n; j += 2){
					if(has1[j]){
						ans1 += j-i;
						has1[i] = 1;
						has1[j] = 0;
						break;
					}					
				}
			}
		}
	}

	int ans2 = 0; // all in white
	for(int i = 0; i < n; i++){
		if(v[i] == 'W' and has2[i] == 0){
			bool found = 0;
			for(int j = i-1; j >= 0; j -= 2){
				if(has2[j]){
					ans2 += i-j;
					has2[i] = 1;
					has2[j] = 0;
					found = 1;
					break;
				}
			}

			if(!found){
				for(int j = i+1; j < n; j += 2){
					if(has2[j]){
						ans2 += j-i;
						has2[i] = 1;
						has2[j] = 0;
						break;
					}					
				}
			}
		}
	}

	printf("%d\n", min(ans1, ans2));

	return 0;
}