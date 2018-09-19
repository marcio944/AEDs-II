#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10005];
int visitado[10005];
int achou;

void dfs(int v) {
	
	visitado[v] = 1;

	for(int i=0; i<adjList[v].size() && !achou; i++){
		if( visitado[adjList[v][i]] == 0 ){
			dfs(adjList[v][i]);
		}else if( visitado[adjList[v][i]] == 1){
			achou = true;	
		}
	}
	
	visitado[v] = 2;
			
}

int main() {
	
	int t, n, m, a, b;

	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d%d", &n, &m);
		
		for(int i=1; i<=n; i++){
			adjList[i].clear();
		}
		
		for( int i=0; i<m; i++ ){
			scanf("%d %d", &a, &b);
			adjList[a].push_back(b);
		}
		
		achou = false;
		
		memset(visitado, 0, sizeof visitado);
		
		for( int i=1; i<=n && !achou; i++){
			if( visitado[i] != 1 ){
				dfs(i);		
			}
		}

        if(achou){
            printf("%s\n", "SIM");
        }else{
            printf("%s\n", "NAO");
        }
                		
	}

	return 0;
        
}
