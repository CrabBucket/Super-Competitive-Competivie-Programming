#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <bitset>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

typedef pair<int,int> pairII;

//Declare some memory ahead of time so it contiguous
const int MAXN = 1e5 + 3;
int n, dist[MAXN], parent[MAXN]; //essentially a DAT
vector<vector<pairII>> adjList; //Format: adjList[From][<To, Weight>]
bitset<MAXN> visited; //Bitset instead of bools

//dijkstra's with a source and target node
bool dijkstra(int s, int t){
	//Construct min heap <distance, Node>
	priority_queue<pairII, vector<pairII>, greater<pairII>> q;
	fill(dist, dist+n+1, INT_MAX);

	//Insert source node
	q.push(pairII(0, s));
	dist[s]   =  0;
	parent[s] = -1;

	//Dijkstra, quit once target t is being evaluated
	while(!q.empty()){
		int u = q.top().second;
		//target found?
		if(u == t)
			return true;
		q.pop();
		visited[u] = true;

		//Check all neighbors of u
		for(pairII &n : adjList[u]){
			int v = n.first, w = n.second; //unpack data
			if(!visited[v] and dist[u] + w < dist[v]){
				dist[v]   = dist[u] + w;
				parent[v] = u;
				q.push(pairII(dist[v], v)); //push better node to queue
			}
		}
	}
	return false; //no path found
}

int main(){
	int m;
	scanf("%d %d", &n, &m);
	adjList.resize(n+3); //DAT Vector

	int a, b, w;
	while(m--){
		scanf("%d %d %d", &a, &b, &w);
		adjList[a].push_back(pairII(b, w));
		adjList[b].push_back(pairII(a, w));
	}

	//trace path if it exists
	if(dijkstra(1, n)){
		stack<int> path;
		int temp = n;
		while(parent[temp] != -1){
			path.push(temp);
			temp = parent[temp];
		}
		
		printf("1");
		while(!path.empty()){
			printf(" %d", path.top());
			path.pop();
		}
	}
	else{
		printf("-1");
	}

	return 0;
}