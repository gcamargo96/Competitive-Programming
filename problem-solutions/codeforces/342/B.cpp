#include <bits/stdc++.h>
using namespace std;

char s1[100005], s2[32];
int res = 0;
int check[100005];

int main(void){
	scanf("%s", s1);
	scanf("%s", s2);
	int t1 = strlen(s1);
	int t2 = strlen(s2);

	for(int i = 0; i <= t1-t2; i++){
		int flag = 1;
		for(int j = 0, k = i; j < t2 and k < t1; j++, k++){
			if(s1[k] != s2[j]){
				flag = 0;
			}
			//cout << s1[k] << " " << s2[j] << endl;
		}		
		//cout << endl;
		if(flag){
			res++;
			i += t2-1;
		}
	}

	printf("%d\n", res);

	return 0;
}
