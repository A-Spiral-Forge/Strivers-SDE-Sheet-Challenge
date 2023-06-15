#include <bits/stdc++.h> 
using namespace std;

template <typename T = int>
class TreeNode
{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

// Function to check if a path exists between root node and destination node
bool getPath(TreeNode<int> *root, vector<int> &path, int x) {
    // If root is NULL there is no path
	if(!root) {
		return false;
	}

    // Push the root's data into the path vector
	path.push_back(root->data);
    // If root's data is equal to the destination node's data, return true
	if(root->data == x) {
		return true;
	}

    // If there is a path from root's left or right child to the destination node, return true
	if(getPath(root->left, path, x)) {
		return true;
	}
	if(getPath(root->right, path, x)) {
		return true;
	}

    // If there is no path from root's left or right child to the destination node, 
    // pop the root's data from the path vector and return false
	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Stores the path from root to destination node
    vector<int> res;
    // Check if a path exists between root node and destination node
	getPath(root, res, x);
    // Return the path
	return res;
}
