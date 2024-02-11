#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element){
        if(size-top >1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    void peek(){
        if(top>=0){
            cout<<"Peek Element: "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    
    Stack s(6);
    s.push(5);
    s.push(7);
    s.push(11);
    s.peek();
    cout<<"Stack is empty: "<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.peek();
    cout<<"Stack is empty: "<<s.isEmpty()<<endl;
    s.push(6);
    s.push(9);
    s.push(11);
    s.push(90);
    s.push(19);
    s.push(69);
    s.push(89);
    s.peek();
    return 0;
}