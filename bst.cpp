#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

Node* buildBST(Node* root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->val)
    {
        root->left = buildBST(root->left, val);
    }
    else
    {
        root->right = buildBST(root->right, val);
    }

    return root;
}

Node *createTree()
{
    cout << "enter the value of node:- " << endl;
    int val;
    cin >> val;

    Node *root = NULL;

    while (val != -1)
    {
        root = buildBST(root, val);
        cout << "enter the value of node:- " << endl;
        cin >> val;
    }

    return root;
}

void leveltraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* frontnode = q.front();
        q.pop();

        if (frontnode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontnode->val << " ";

            if (frontnode->left)
            {
                q.push(frontnode->left);
            }

            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
    }
}

int main()
{
    Node* root = createTree();
    leveltraversal(root);
}