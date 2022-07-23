class Solution1 // good approach for solving problems bcz easy to write
{
    void dfs(int node, vector<int> adjList[], vector<bool> &vis,vector<int> &storeDFS)
    {
        if(vis[node]) return;
        storeDFS.push_back(node);
        vis[node] = true;
        for(auto nn : adjList[node]) // nn : neighbour_node
            dfs(nn,adjList,vis,storeDFS);
    }
  public:
    vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
    {
        vector<int> adjList[V]; // Graph_representation
        for(int j=0; j<E; j++)
        {
            // edges[j][0] - node1, edges[j][1] - node2
            int node1 = edges[j][0], node2 = edges[j][1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        vector<vector<int>> components;
        vector<bool> vis(V+1,false);
        for(int i=0; i<V; i++)
        {
            vector<int> storeDFS;
            if(vis[i]==false)
            {
                dfs(i,adjList,vis,storeDFS);
                sort(storeDFS.begin(),storeDFS.end());
                components.push_back(storeDFS);
            }
        }
        return components; // lists of components
    }
};

class Solution2 // good but lengthy, not recommended to use in problems , unless there is no other choice
{
    private:
        class GraphNode
        {
            public:
            int data;
            bool visited;
            vector<GraphNode*> neighbours;
            GraphNode(int data)
            {
                visited = false;
                this->data = data;
            }
        };
        void dfs(GraphNode* node,vector<int> &v)
        {
            if(node->visited) return;
            v.push_back(node->data);
            node->visited = true;
            for(auto neighbour : node->neighbours)
                dfs(neighbour,v);
        }
    public:        
        vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
        {
            unordered_map<int,GraphNode*> um;
            for(int i=0; i<V; i++)
                um[i] = new GraphNode(i);
            for(int j=0; j<E; j++)
            {
                // edges[j][0] -> node1_val, edges[j][1] -> node2_val
                auto node1 = um[edges[j][0]], node2 = um[edges[j][1]];
                vector<GraphNode*> &n1n = node1->neighbours; // node1's neighbour[n1n]
                vector<GraphNode*> &n2n = node2->neighbours; // node2's neighbour[n2n]
                n1n.push_back(node2);
                n2n.push_back(node1);
            }
            vector<vector<int>> res;
            for(int i=0; i<V; i++)
            {
                vector<int> component;
                GraphNode *curr = um[i];
                if(!curr->visited)
                {
                    dfs(curr,component);
                    sort(component.begin(),component.end());
                    res.push_back(component);
                }
            }
            return res; // lists of components
        }  
};
