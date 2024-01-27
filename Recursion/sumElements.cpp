#include<iostream>
using namespace std;
void print(int arr[],int size){
    cout<<size<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    // cout<<endl;
}
int getSum(int arr[],int size){
    print(arr,size);
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int sum=arr[0]+getSum(arr+1,size-1);
    // cout<<sum<<endl;

    return sum;
}
int main(){
    int arr[6]={5,1,2,3,1,4};
    int ans=getSum(arr,6);
    cout<<ans<<endl;
    
    return 0;
}