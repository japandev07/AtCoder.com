#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int , int>
#define PLI pair<LL  , int>
#define PLL pair<LL , LL>
#define bit(x) (1<<x)
#define bitl(x) (1LL<<x)
#define cnti(x) (__builtin_ctz(x))
#define cntl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzll(x) (__builtin_clzll(x))

#define Error(x) cerr<<#x<<" = "<<x<<endl;

#define NIL 0
#define INF INT_MAX

#define mx 2010

int n , m;
int dist[mx];
vector< int > con[mx];
int s[mx];

 
// A class to represent Bipartite graph for Hopcroft
// Karp implementation
class BipGraph
{
   
    
 
public:
	 // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    int m, n;
 
    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    list<int> adj[mx];
 
    // These are basically pointers to arrays needed
    // for hopcroftKarp()
	int pairU[mx], pairV[mx], dist[mx];
    BipGraph(int m, int n); // Constructor
    void addEdge(int u, int v); // To add edge
 
    // Returns true if there is an augmenting path
    bool bfs();
 
    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(int u);
 
    // Returns size of maximum matching
    int hopcroftKarp();
};
 
// Returns size of maximum matching
int BipGraph::hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
//    pairU = new int[m+1];
 
    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
//    pairV = new int[n+1];
 
    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
//    dist = new int[m+1];
 
    // Initialize NIL as pair of all vertices
    for (int u=0; u<=m; u++)
        pairU[u] = NIL;
    for (int v=0; v<=n; v++)
        pairV[v] = NIL;
 
    // Initialize result
    int result = 0;
 
    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (int u=1; u<=m; u++)
 
            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}
 
// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs()
{
    queue<int> Q; //an integer queue
 
    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }
 
        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }
 
    // Initialize distance to NIL as infinite
    dist[NIL] = INF;
 
    // Q is going to contain vertices of left side only.
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();
 
        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;
 
                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
 
    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}
 
// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            // Adjacent to u
            int v = *i;
 
            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
 
        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}
 
// Constructor
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
//    adj = new list<int>[m+1];
}
 
// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
}
 
// Driver Program


void dijkstra(int st){
	priority_queue< int , vector< int > , greater< int > > que;
	while(!que.empty()) que.pop();
	for(int i= 0 ; i < mx ; i++ ) dist[i] = 1e9;
	dist[st] = 0;
	que.push(st);
	while(!que.empty()){
		int u = que.top();que.pop();
		for(int i= 0 ; i < con[u].size() ; i++ ){
			int v = con[u][i];
			if(dist[v] >= dist[u] + 1){
				dist[v] = dist[u] + 1;
				que.push(v);
			}
		}
	}
	return;
}

int p[mx] , d[mx] , vis[mx];

int main()
{
	freopen("sam.txt" , "r" , stdin);
    
 	cin>>n>>m;
 	for(int i = 0 ; i < m ; i++ ){
 		int u , v;
 		cin>>u>>v;
 		con[u].push_back(v);
 		con[v].push_back(u);
	}
	BipGraph g(5, 5);
	g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
//    g.addEdge(4, 2);
    g.addEdge(4, 3);
	
	int val = g.hopcroftKarp();cout<<val<<endl;
	for(int i = 1 ; i <= 5 ; i++ ) {
		s[g.pairU[i]] = 1;
		cout<<i<<" "<<g.pairU[i] <<endl;
	}
	for(int i = 1 ; i <= n ; i++ ) cout<<s[i];
	cout<<"\n";
//    cout << "Size of maximum matching is " << g.hopcroftKarp();
 
    return 0;
}

