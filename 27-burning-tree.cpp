
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node* bfs(Node* root, unordered_map<Node*, Node*>& parent, int target)
    {
        queue<Node*> q;
        q.push(root);
        Node* start;
        
        while(!q.empty())
        {
            Node* curr = q.front();
            if(curr->data == target)
            {
                start = curr;
            }
            if(curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
            q.pop();
        }
        return start;
    }
    
    int findMaxDist(unordered_map<Node*, Node*>& parent, Node* start)
    {
        queue<Node*> q;
        q.push(start);
        unordered_map<Node*, bool> visited;
        visited[start] = true;
        int ans = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            int flag = 0;
            while(count--)
            {
                Node* curr = q.front();
                if(parent[curr] != 0 && visited[parent[curr]] == false)
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                    flag = 1;
                }
                if(curr->left && visited[curr->left] == false)
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    flag = 1;
                }
                if(curr->right && visited[curr->right] == false)
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    flag = 1;
                }
                q.pop();
            }
            if(flag)
                ans++;
        }
        return ans;
        
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        Node* start = bfs(root, parent, target);
        int ans = findMaxDist(parent, start);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends