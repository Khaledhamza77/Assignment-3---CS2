#include<iostream>
#include<vector>
using namespace std;

struct Node{int data; int occur=1; Node *next;};

class LinkedList{
private:
    Node * head, *next, *previous;
public:
    LinkedList(){head=NULL;next=NULL;previous=NULL;}
    void add_node(int n){
        Node*new1=new Node;
        new1->data=n;
        numofoccurences(new1);
        if(head==NULL){head=new1;head->next=NULL;}
        else{
            Node*p=head;
            while(p->next!=NULL){p=p->next;}
            new1->next=NULL;
            p->next=new1;
        }
    }
    void remove_node(int index){
        Node*p; p=head; int listlength=0;
        while(p!=NULL){
            listlength++;
            p=p->next;
        }
        if(index>listlength)cout<<"Out of Reach!\n";
        else if(index==1){p=head;head=head->next;delete p;}
        else{
            int position=0;p=head;
            while(position!=index){
                previous=p;
                p=p->next;
                next=p->next;
                position++;
            }
            previous->next=next;
            p->next=NULL;
            delete p;
        }
    }
    void printelements(){
        Node*p; p=head; int i=0; int sum;
        while(p!=NULL){
            cout<<"Element number "<<i+1<<" is: "<<p->data<<" and it has occured "<<p->occur<<" times\n";
            p=p->next;
            i++;
        }
        sum=this->sumOfnodes();
        cout<<"Sum of elements is: "<<sum<<"\n";
    }
    int sumOfnodes(){
        Node*p=p=head;
        int sum=0;
        while(p!=NULL){
            sum=sum+p->data;
            p=p->next;
        }
        return sum;
    }
    void numofoccurences(Node *h){
        Node*p;p=head;
        while(p!=NULL){
            if(h->data==p->data){
                h->occur++;
                p->occur++;
            }
            p=p->next;
        }
    }
    void vectorToLL(vector<int> v){
        for(int i=0;i<v.size();i++){
            this->add_node(v[i]);
        }
    }
};