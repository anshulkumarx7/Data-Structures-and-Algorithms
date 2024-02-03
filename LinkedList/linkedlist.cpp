#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory free for node with data"<<value<<endl;
    }
};

void InsertAtHead(Node *&head, int data)
{

    // create new node
    Node *temp = new Node(data);
    temp->next = NULL;
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int data)
{
    // create new node
    Node *temp = new Node(data);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    Node *temp = head;
    int cnt = 1;
    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
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
    Node *NextToNode = new Node(data);
    NextToNode->next = temp->next;
    temp->next = NextToNode;
}
void deleteNode(int position, Node* & head,Node* & tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
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
bool isCircular(Node*head){
    Node* temp=head->next;
    if(head==NULL){
        return true;
    }

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;

}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);
    // InsertAtHead(head, 12);
    InsertAtTail(tail, 12);
    print(head);
    // InsertAtHead(head, 9);
    InsertAtTail(tail, 9);
    print(head);
    // InsertAtHead(head, 100);
    InsertAtTail(tail, 100);
    print(head);
    InsertAtPosition(head, tail, 1, 22);
    print(head);
    InsertAtPosition(head, tail, 6, 67);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    // deleteNode(3,head,tail);
    // print(head);
    // deleteNode(5,head,tail);
    // print(head);
    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;
    cout<<"Circular: "<<isCircular(head)<<endl;

    return 0;
}