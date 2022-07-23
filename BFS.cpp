#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adjList[vertex]; // Graph_representation
    for(int j=0; j<edges.size(); j++)
    {
        // edges[j][0] - node1, edges[j][1] - node2
        int node1 = edges[j].first, node2 = edges[j].second;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    vector<int> res;
    vector<bool> vis(vertex,false);
    vector<int> visit_order;
    for(int i=0; i<vertex; i++)
    {
        if(vis[i]==true)
            continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            visit_order.push_back(curr);
            vector<int> tmp;
            for(int neighb : adjList[curr])
                tmp.push_back(neighb);
            sort(tmp.begin(),tmp.end()); // level wise sorted
            for(int node:tmp)
                if(vis[node]==false)
                {
                    q.push(node);
                    vis[node]=true;
                }
        }
        res.insert(res.end(),visit_order.begin(),visit_order.end());
        visit_order.clear();
    }
    return res;
}
