/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode *node, graphNode *copy, unordered_map<int,graphNode*> &vis){
    
    for(auto &adj : node->neighbours){
        if(vis[adj->data]==NULL){
            auto newNode = new graphNode(adj->data);
            vis[adj->data] = newNode;
            copy->neighbours.push_back(newNode);
            dfs(adj,newNode,vis);
        }
        else{
            copy->neighbours.push_back(vis[adj->data]);
        }
        
    }
}
graphNode *cloneGraph(graphNode *node)
{
    if(node==NULL)
        return NULL;
    unordered_map<int,graphNode*> visited;
    graphNode* copy = new graphNode(node->data);
    visited[node->data] = copy;
    dfs(node,copy,visited);
    return copy;
}

// Time: O( V + E ) , Space: for unordered_map
