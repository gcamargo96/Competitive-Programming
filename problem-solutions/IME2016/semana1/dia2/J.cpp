#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n;
int cnt1[10], cnt2[10];
set<int> vamp;

int main(void){
	ios_base::sync_with_stdio(false);
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; i*j <= 1001000; j++){
			memset(cnt1, 0, sizeof cnt1);
			memset(cnt2, 0, sizeof cnt2);

			int x = i*j;
			while(x != 0){
				int d = x%10;
				x /= 10;
				cnt1[d]++;
			}
			int i2 = i, j2 = j;
			while(i2 != 0){
				int d = i2%10;
				i2 /= 10;
				cnt2[d]++;
			}
			while(j2 != 0){
				int d = j2%10;
				j2 /= 10;
				cnt2[d]++;
			}

			bool flag = 1;
			for(int k = 0; k <= 9; k++){
				if(cnt1[k] != cnt2[k]){
					flag = 0;
					break;
				}
			}	

			if(flag){
				vamp.insert(i*j);
			}
			//cout << "loop " << i*j << endl;
		}
	}
	//cout << "terminou" << endl;

	while(cin >> n, n != 0){
		auto it = lower_bound(vamp.begin(), vamp.end(), n);
		cout << *it << endl;
	}

	return 0;
}
