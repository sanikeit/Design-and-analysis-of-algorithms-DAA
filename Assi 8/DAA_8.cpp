#include <bits/stdc++.h>
using namespace std;

void primsMST(vector <vector<pair<int,int>>> adj, int v) //we are using prims algorithm for finding the minimum spanning tree
{
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;    //defining priority_queue
    pq.push(make_pair(0, 1));   //pushing the source vertex
    vector <int> MST(v+1);
    vector <int> parent(v+1);
    vector <int> min_weight(v+1, INT_MAX);  // minimum weight of edge from a vertex to its parent
    min_weight[1]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;    // minimum cost edge from the previously included vertices in the queue
        pq.pop();
        MST[u]=1;
        for(int i=0;i<adj[u].size();i++)    //traversing the adjacent nodes of u
        {
            int adjv=adj[u][i].first;
            int weight = adj[u][i].second;
            if(MST[adjv]==0 && min_weight[adjv]>weight)     //if we find a vertex with minimum cost than the previous, we push the node in queue
            {
                parent[adjv]=u;
                min_weight[adjv]=weight;
                pq.push(make_pair(weight,adjv));
            }
        }
    }
    for(int i=2;i<=v;i++)
    {
        cout<<i<<" "<<parent[i]<<" "<<min_weight[i]<<endl;
    }
}

int main()
{
    int v,e;    //number of vertices and the number of edges
    cin>>v>>e;
    vector <vector<pair<int, int>>> adj(v+1);
    for(int i=1;i<=e;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        adj[a].push_back(make_pair(b,weight));  //filling the adjacency list
        adj[b].push_back(make_pair(a,weight));
    }
    cout<< v<<" "<<e<<endl;
    primsMST(adj,v);
	return 0;
}