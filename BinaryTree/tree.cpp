#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data in left of" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data in right of" << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void buildTreeFromLevelOrder(Node *&root){
    queue<Node*>q;
    int data;
    cout<<"Enter data:"<<endl;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data for right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node *root = NULL;
    // root = buildTree(root);
    buildTreeFromLevelOrder(root);

    cout << "Printing in level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << endl<<"Printing in InOrder Traversal" << endl;
    inOrder(root);
    cout << endl<< "Printing in PreOrder Traversal" << endl;
    preOrder(root);
    cout << endl<< "Printing in PostOrder Traversal" << endl;
    postOrder(root);
    return 0;
}