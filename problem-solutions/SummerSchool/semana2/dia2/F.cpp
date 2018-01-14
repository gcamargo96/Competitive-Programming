#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009;
#define ll long long

const int N = 1002, M = 10002;
string s, t;
ll A[N][2];
ll F[M][N], K[M][N];
int p[N];
int k;

void prefix_function(string& s){
    int n = s.size();
    for(int i = 2; i <= n; i++){
        p[i] = p[i-1];
        while(p[i] > 0 and s[p[i]] != s[i-1])
            p[i] = p[p[i]];
        if(s[p[i]] == s[i-1])
            p[i]++;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin >> s >> k;
	s += '#';

    prefix_function(s);
   
    for(int c = 0; c < 2; c++){
        A[0][c] = (s[0] == c+'a');
    }
    for(int i = 1; i < (int)s.size(); i++){
        for(int c = 0; c < 2; c++){
            if(s[i] == c+'a')
                A[i][c] = i+1;
            else
                A[i][c] = A[p[i]][c];
        }
    }

	for(int j = 0; j <= k; j++){ 				
		for(int i = 0; i < (int)s.size(); i++){
			if(j == 0){
				F[j][i] = i;
			}
			else if(j == 1){
				F[j][i] = A[i][0];
			}
			else if(j == 2){
				F[j][i] = A[i][1];
			}
			else{
				int x = F[j-2][i];
				F[j][i] = F[j-1][x];
			}
		}
	}

	for(int j = 0; j <= k; j++){
		for(int i = 0; i < (int)s.size(); i++){
			if(j == 0){
				K[j][i] = 0;
			}
			else if(j == 1){
				K[j][i] = (F[j][i] == (int)s.size()-1);
			}
			else if(j == 2){
				K[j][i] = (F[j][i] == (int)s.size()-1);
			}
			else{
				int x = F[j-2][i];
				K[j][i] = (K[j-2][i] + K[j-1][x])%MOD;
			}
		}
	}

   	cout << K[k][0] << endl;


    return 0;
}
