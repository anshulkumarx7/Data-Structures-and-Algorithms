#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout << "Memory free for node with data" << value << endl;
    }
};

void InsertNode(Node* &tail,int data,int element){
    if(tail==NULL){
        Node* newNode=new Node(data);
        newNode->next=newNode;
        tail=newNode;
        return;
    }
    else{
        //when not empty
        //assuming element is present in the list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        Node*temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }

}
void print(Node* &tail){
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    Node *forward=tail;
    do{
        cout<<forward->data<<" ";
        forward=forward->next;

    }while(forward!=tail);
    cout<<endl;

}
void deleteNode(Node*&tail,int element){

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
int main(){
    Node*tail=NULL;
    InsertNode(tail,10,1);
    cout<<"tail "<<tail->data<<endl;
    print(tail);
    InsertNode(tail,20,10);
    print(tail);
    cout<<"tail "<<tail->data<<endl;
    cout<<"Circular: "<<isCircular(tail)<<endl;

    return 0;
}