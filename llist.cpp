#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class linkedList{
    private:
        Node *head;
    public:
        linkedList(){
            head=NULL;
        }
        void insertAtBeg(int value){
            Node *temp=new Node;
            temp->data=value;
            temp->next=head;
            head=temp;
        }

        void insert(int value){
            Node *temp=new Node;
            temp->data=value;
            temp->next=NULL;

            if(head==NULL){
                temp->next=head;
                head=temp;
            }
            else{
                Node *cur=head;
                while(cur->next!= NULL){
                    cur=cur->next;
                }
                cur->next=temp; 
            }
        }
        void insertAtPos(int value,int loc){
            Node *temp=new Node;
            Node *prev=new Node;
            Node *cur=head;
            int i=1;
            while(i<loc){
                prev=cur;
                cur=cur->next;
                i++;
            }
            temp->data=value;
            prev->next=temp;
            temp->next=cur;
        }
        void deleteAtBeg(){
            Node *cur=head;
            head=head->next;
            delete cur;
        }
        void deleteAtPos(int pos){
            Node *cur=head;
            Node *prev= new Node;
            int i=1;
            while(i<pos-1){
                prev=cur;
                cur=cur->next;
                i++;
            }
            prev->next=cur->next;
            delete cur;

        }
        void deleteAtEnd(){
            Node *cur=head;
            Node *prev= new Node;
            while(cur->next != NULL){
                prev=cur;
                cur=cur->next;
            }
            prev->next=NULL;
            delete cur;
        }

        void reverse(){
            Node *prev=NULL;
            Node *next=NULL;
            Node *cur=head;
            while(cur!=NULL){
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            head=prev;
        }


        void print(){
            Node *cur=head;
            while(cur!=NULL){
                cout<<cur->data<<" ";
                cur=cur->next;
            }
        }
};
int main(){
    linkedList l;
    l.insert(5);
    l.insert(15);
    l.insert(25);
    l.insert(35);
    l.insertAtPos(11,2);
    l.insertAtBeg(69);
    l.deleteAtBeg();
    l.deleteAtEnd();
    l.deleteAtPos(3);
    l.print();
    l.reverse();
    cout<<endl;
    l.print();
    return 0;
}