#include<iostream>
#include<vector>
#include"linkedlist.h"
using namespace std;

void insertAfter(vector<int>& x,int firstValue, int secondValue){
    for(int i=0;i<x.size();i++){
        if(x.at(i)==firstValue){
            x.insert(x.begin()+(i+1),secondValue);
        }
    }
}

int main(){
    vector<int> x;
    int n;
    cout<<"Please enter the number of values you want to enter: \n";
    cin>>n;
    x.resize(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the element number "<<i+1<<" in your vector:\n";
        cin>>x[i];
    }
    insertAfter(x,12,7);

    LinkedList LL;
    LL.vectorToLL(x);
    LL.printelements();
    LL.remove_node(3);
    cout<<"\n"<<"After Removal!"<<"\n"<<"\n";
    LL.printelements();

    return 0;
}