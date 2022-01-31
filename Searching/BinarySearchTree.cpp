#include <iostream>
#include <stdlib.h>

using namespace std;

class node
{
public:
    int val;
    node *right, *left;
};

void insert(node **tree, node *item)
{
    if (!(*tree))
    {
        *tree = item;
        return;
    }
    if (item->val <= (*tree)->val)
    {
        insert(&(*tree)->left, item);
    }

    else
    {
        insert(&(*tree)->right, item);
    }
}

int isPresent(node *root, int val)
{
    /*
       The structure of the node is as follows:
          class node {
             public:
                 node * left, *right;
                 int val;
          };
    */
    if (root == NULL)
    {
        return 0;
    }
    if (root->val == val)
    {
        return 1;
    }
    else if (root->val < val)
    {
        return isPresent(root->right, val);
    }
    else
    {
        return isPresent(root->left, val);
    }
}

int main()
{
    node *_root, *root_curr;
    int root_i = 0, root_cnt = 0, root_num = 0;
    _root = NULL;
    cin >> root_cnt;
    for (root_i = 0; root_i < root_cnt; root_i++)
    {
        scanf("%d", &root_num);
        root_curr = (node *)malloc(sizeof(node));

        root_curr->left = root_curr->right = NULL;
        root_curr->val = root_num;

        insert(&_root, root_curr);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int _x;
        cin >> _x;
        cout << isPresent(_root, _x) << endl;
    }

    return 0;
}
