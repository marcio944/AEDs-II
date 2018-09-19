#include <bits/stdc++.h>

using namespace std;

int dfscount;
int dfs_low[1000], dfs_parent[1000], dfs_num[1000];
int pontes;

vector<vector<int> > AdjList;

void dfs(int c) {
	
	dfs_low[c] = dfscount++;
	dfs_num[c] = dfscount++;
	
	for (int j = 0; j < (int)AdjList[c].size(); j++) {
		int v = AdjList[c][j];
		if (dfs_num[v] == -1) {	
			dfs_parent[v] = c;
			dfs(v);
			if (dfs_low[v] > dfs_num[c]){
				pontes++;
			}		
			dfs_low[c] = min(dfs_low[c], dfs_low[v]);
		}else if (v != dfs_parent[c]){
			dfs_low[c] = min(dfs_low[c], dfs_num[v]);
		} 
		
	} 
}

int main()
{
	int c, p;
	
	while (cin >> c >> p){
		
		memset(dfs_low, -1, sizeof dfs_low);
		memset(dfs_parent, -1, sizeof dfs_parent);
		memset(dfs_num, -1, sizeof dfs_num);
		
		dfscount =0;
		pontes = 0;
		
		AdjList.assign(c, vector<int> ());
		
		for (int i = 0 ; i < p; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		
		dfs(0);
		
		printf("%d\n", pontes);
		
		AdjList.clear();
		
	}
	
	return 0;
	
}
