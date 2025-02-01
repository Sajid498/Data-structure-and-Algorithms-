//Calculate depth of a full Binary tree from Preorder
#include <iostream>
using namespace std;

// Recursive helper function to compute the depth of the tree
int calculateDepthHelper(const string &preorder, int &index)
{
    // If index goes out of bounds, return -1 (invalid case, should not happen in valid input)
    if (index >= preorder.length())
    {
        return -1;
    }

    // If current node is a leaf, return depth 0
    if (preorder[index] == 'l')
    {
        index++; // move to the next character
        return 0;
    }

    // If current node is an internal node ('n'), process both left and right subtrees
    if (preorder[index] == 'n')
    {
        index++; // move to the left child
        int leftDepth = calculateDepthHelper(preorder, index);
        int rightDepth = calculateDepthHelper(preorder, index);

        // Depth of current node is 1 + max depth of left and right subtrees
        return 1 + max(leftDepth, rightDepth);
    }

    return -1; // return an invalid depth for unexpected characters (shouldn't happen)
}

// Function to calculate the depth of the binary tree from the given preorder string
int calculateDepth(const string &preorder)
{
    int index = 0; // to keep track of current position in the preorder string
    return calculateDepthHelper(preorder, index);
}

int main()
{
    string preorder = "nlnnlll";
    cout << "Depth of the binary tree: " << calculateDepth(preorder) << endl;
    return 0;
}

