/*
Problem Description

Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.

You have to find an integer array D of size A such that:

D[i]: Shortest distance from the C node to node i.
If node i is not reachable from C then -1.
Note:

There are no self-loops in the graph.
There are no multiple edges between two pairs of vertices.
The graph may or may not be connected.
Nodes are numbered from 0 to A-1.
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints

1 <= A <= 1e5

0 <= B[i][0],B[i][1] < A

0 <= B[i][2] <= 1e3

0 <= C < A



Input Format

The first argument is an integer A, representing the number of nodes in the graph.
The second argument is a matrix B of size M x 3, where each row represents an edge in the graph. The three columns of each row denote the source node B[i][0], the destination node B[i][1], and the weight of the edge B[i][2].
The third argument is an integer C, representing the source node for which the shortest distance to all other nodes needs to be found.


Output Format

Return the integer array D.



Example Input

Input 1:

A = 6
B = [   [0, 4, 9]
        [3, 4, 6] 
        [1, 2, 1] 
        [2, 5, 1] 
        [2, 4, 5] 
        [0, 3, 7] 
        [0, 1, 1] 
        [4, 5, 7] 
        [0, 5, 1] ] 
C = 4
Input 2:

A = 5
B = [   [0, 3, 4]
        [2, 3, 3] 
        [0, 1, 9] 
        [3, 4, 10] 
        [1, 3, 8]  ] 
C = 4


Example Output

Output 1:

D = [7, 6, 5, 6, 0, 6]
Output 2:

D = [14, 18, 13, 10, 0]


Example Explanation

Explanation 1:

 All Paths can be considered from the node C to get shortest path
Explanation 2:

 All Paths can be considered from the node C to get shortest path
*/

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {

    vector<vector<pair<int, int>>> wt_node_vec(A, vector<pair<int, int>>());

    //Create adjacency list from edge list
    for(auto edge: B)
    {
        wt_node_vec[edge[0]].push_back(make_pair(edge[2], edge[1]));
        wt_node_vec[edge[1]].push_back(make_pair(edge[2], edge[0]));
    }
   
    //Min heap to store weighted path and destination node pair
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wt_node;
    wt_node.push(make_pair(0, C)); //Initialize min heap with source node and it's distance from itself (0)

    //Set to store visited nodes
    unordered_set<int> visited;

    //Array to store shortest distance of C from ith node
    vector<int> D(A, INT_MAX);

    while(visited.size() < A && !wt_node.empty())
    {
        //Get the top node with least amount of weight
        pair<int, int> currNode = wt_node.top();
        //Pop from priority_queue
        wt_node.pop();
        // cout<<currNode.first<<" "<<currNode.second<<endl;

        //Check if visted or not
        if(visited.find(currNode.second) != visited.end())
        {
            continue;
        }

        //Insert currNode in visited Set
        visited.insert(currNode.second);

        //Add distance to currNode.second index in the array as the minimum distance
        D[currNode.second] = min(currNode.first, D[currNode.second]);
        // cout<<currNode.second<<" "<<D[currNode.second]<<endl;
       

        //Loop through all the un-visited neighbors of currNode and insert them in the priority_queue
        for(auto adj : wt_node_vec[currNode.second])
        {
            if(visited.find(adj.second) == visited.end())
            {
                //Add distance of parent node as well while adding children
                wt_node.push(make_pair(currNode.first+adj.first, adj.second));
                // cout<<currNode.first+adj.first<<" "<<adj.second<<endl;
            }
        }
    }

    //There can be some unvisited nodes. If unvisted insert -1.
    for(auto &elem : D)
    {
        if(elem == INT_MAX)
        {
            elem = -1;
        }
    }

    return D;

}