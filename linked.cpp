#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node * next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertathead(Node * &head, int ele){
    Node * newNode = new Node(ele); 
    newNode->next=head;
    head=newNode;
}

void insertattail(Node * head, int ele){
    Node * newNode = new Node(ele);
    Node * temp =head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void insertatk(Node * head, int ele, int pos){
    if (pos == 0){
        insertathead(head, ele);
        return;
    }
    Node * newNode= new Node(ele);
    Node * temp= head;
    for(int i =0; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next= newNode;
}

void display(Node * head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void updateatk(Node * head, int ele, int pos){
    Node * newNode= new Node(ele);
    Node * temp= head;
    for(int i =0; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    temp->val=ele;
}

void deleteatk(Node * head, int pos){
    int i=0;
    Node * temp= head;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }
    Node * del=temp->next;
    temp->next=temp->next->next;
    free(temp);
}

void deleteathead(Node * head){
    if(head=NULL){
        cout<<"Cannot be deleted from empty list"<<endl;
        return;
    }
    Node * temp = head;
    head = head->next;
    free(temp);
}

void deleteattail(Node * head){
    Node * sec_last=head;
    while (sec_last->next->next!=NULL){
        sec_last=sec_last->next;
    }
    Node * temp= sec_last->next;
    sec_last->next=NULL;
    free(temp);
}

int main(){
    
    Node * head= NULL;
    insertathead(head, 2);
    display(head);
    insertathead(head, 1);
    display(head);
    //deleteathead(head);
    //display(head);
    insertatk(head, 3, 2);
    display(head);
    deleteatk(head, 2);
    display(head);
    insertattail(head, 4);
    display(head);
    updateatk(head, 5, 3);
    display(head);
    deleteattail(head);
    display(head);
    return 0;
}