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
