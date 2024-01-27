#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data" << value << endl;
    }
};
void InsertAtHead(Node *&head, int data)
{

    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(Node* &head, Node* &tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        cout<<head->data<<endl;
        return;
    }
    Node *temp = NULL;
    Node *curr = head;
    int cnt = 1;
    while (cnt < position)
    {
        temp = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL)
    {
        temp->next = NULL;
        curr->prev = NULL;
        tail = temp;
        delete curr;
        return;
    }
    curr->next->prev = temp;
    temp->next = curr->next;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 20);
    print(head);
    InsertAtHead(head, 40);
    print(head);
    InsertAtHead(head, 50);
    print(head);
    InsertAtTail(tail, 70);
    print(head);
    InsertAtTail(tail, 90);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    cout << getLength(head) << endl;
    InsertAtPosition(head, tail, 7, 70);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    deleteNode(head, tail, 7);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
}