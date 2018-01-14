#include <bits/stdc++.h>
using namespace std;

/* great strings:
 * g0 : ""
 * g1 : "a"
 * g2 : "aba"
 * g3 : "abacaba"
 and so on...
*/

const int N = 1002;
string s, t;
int A[N][32], F[N][32], K[N][32];
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
   
   	// MATRIZ A:
	// estados:
	// 		i : tamanho do maior matching do sufixo da nova string com um prefixo de s	
	// 		j : caractere a ser adicionado no final da nova string
	// A guarda o tamanho do maior sufixo comum a um prefixo de s apos i caracteres
	// coincidirem e adicionarmos a o caractere c+'a'
    for(int c = 0; c < 26; c++){
        A[0][c] = (s[0] == c+'a');
    }
    for(int i = 1; i < (int)s.size(); i++){
        for(int c = 0; c < 26; c++){
            if(s[i] == c+'a')
                A[i][c] = i+1;
            else
                A[i][c] = A[p[i]][c];
        }
    }

	// MATRIZ F:
	// estados:
	// 		i : tamanho do maior matching do sufixo da nova string com um prefixo de s
	// 		j : id da nova great string a ser adicionada ao final da nova string
	// F guarda o tamanho do maior sufixo comum a um prefixo de s apois i caracteres
	// coincidirem e adicionarmos a great string gj
	for(int j = 0; j <= k; j++){ 				
		for(int i = 0; i < (int)s.size(); i++){
			if(j == 0) F[j][i] = i;
			else{
				int x = A[F[j-1][i]][j-1];
				F[j][i] = F[j-1][x];
			}
		}
	}

	// MATRIZ K:
	// estados:
	// 		i : tamanho do maior matching do sufixo da nova string com um prefixo de s
	// 		j : id da nova great string a ser adicionada ao final da nova string
	// K guarda o numero de matchings completos da string s que se pode chegar a partir de
	// i letras coincidentes e adicionando a string gj
	for(int j = 0; j <= k; j++){
		for(int i = 0; i < (int)s.size(); i++){
			if(j == 0) K[j][i] = 0;
			else{
				int x = A[F[j-1][i]][j-1];
				K[j][i] = K[j-1][i] + (x == (int)s.size()-1) + K[j-1][x];
			}
		}
	}

	printf("%d\n", K[k][0]);
    
    return 0;
}
