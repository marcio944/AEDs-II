#include <bits/stdc++.h>


using namespace std;

vector<vector<int> > adjList;
int n;

bool bipartido(){
	
	vector<int> cor;
	
	cor.assign(n, -1);
	
	queue<int> q;
	q.push(0);
	cor[0] = 0;
	bool ehbipartido = true;
	
	while (!q.empty() && ehbipartido){
		
		int u = q.front();
		
		 q.pop();
		
		for (int j = 0 ; j < adjList[u].size(); j++){
			
			if (cor[adjList[u][j]] == -1){
				cor[adjList[u][j]] = cor[u] ^ 1;
				q.push(adjList[u][j]);
			}else if (cor[adjList[u][j]] != -1 && cor[adjList[u][j]] == cor[u]){
				ehbipartido = false;
				break;	
			}
		}
	}
	
	while (!q.empty()) q.pop();
	cor.clear();
	
	return ehbipartido;
	
}

int main()
{
	string x;
	
	stringstream str;
	
	int y;
	int m;
	
	while (cin >> n)
	{
		if (!n) return 0;
		adjList.assign(n, vector<int> ());
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> m;
			getchar();
			getline(cin, x);
			--m;
			str << x;
			
			while (str >> y)
				adjList[m].push_back(y - 1);
			
			str.clear();
		}
		
		if (bipartido()){
			printf("SIM\n");
		}else{
			printf("NAO\n");
		} 
		
		adjList.clear();
		
	}
		
}
