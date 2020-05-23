#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
}
node;

int main(void)
{
     if (root)
    {
        if (root->val == val)
        {
            return root;
        }
        else if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return searchBST(root->left, val);
        }

    return 0;
}