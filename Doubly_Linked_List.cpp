#include <bits/stdc++.h>
using namespace std;

#define     ll          long long
#define     pb          push_back
#define     tc()        ll test_case; cin>>test_case; while(test_case--)
#define     ed          '\n'
#define     readme      ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);

struct Node
{
    int data;
    Node* prev = NULL, *next = NULL;
};

Node* cNode(int data){
    Node* node = new Node();
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void printreverse(Node* tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* ToDelete(Node* head, int ITEM){
    Node* temp = head;
    while((temp->data != ITEM) && (temp!=NULL)){
        temp = temp->next;
    }
    if(temp->data == head->data){
        Node* TEMP = temp;
        temp = temp->next;
        temp->prev = NULL;
        delete(TEMP);
        head = temp;
    }
    else{
        Node* TEMP = temp, *pretemp = temp->prev;
        pretemp->next = temp->next;
        temp->next->prev = pretemp;
        delete(TEMP);
    }
    return head;
}

Node* ToInsert(Node* head, int ITEM, int position){
    Node* temp = head;
    int index = 0;
    while((index!=position) && temp!=NULL){
        index++;
        temp = temp->next;
    }
    if(index == 0){
        Node* node = cNode(ITEM);
        node->next = temp;
        temp->prev = node;
        head = node;
    }
    else{
        Node* node = cNode(ITEM), *TEMP = temp, *pretemp = temp->prev;
        node->next = temp;
        node->prev = temp->prev;
        temp->prev = node;
        pretemp->next = node;
    }
    return head;
}

void deleting(Node* head, Node* tail){
    cout<<"Before Delete: ";
    print(head);
    cout<<ed;
    cout<<"Before delete in reverse: ";
    printreverse(tail);
    cout<<ed<<"Enter a element to delete: ";
    int todelete;
    cin>>todelete;
    if(todelete != tail->data) head = ToDelete(head, todelete);
    else{
        Node*  TEMP = tail;
        tail = tail->prev;
        delete(TEMP);
        tail->next = NULL;
    }
    cout<<ed<<"After delete: ";
    print(head);
    cout<<ed<<"After delete in reverse: ";
    printreverse(tail);
    cout<<ed;
}

void inserting(Node* head, Node* tail, int elements){
    cout<<"Before insert: ";
    print(head);
    cout<<ed<<"Before insert in reverse: ";
    printreverse(tail);
    int toinsert, position;
    cout<<ed<<"Enter a number to insert: ";
    cin>>toinsert;
    cout<<"Enter positon number: ";
    cin>>position;
    if(position<elements) head = ToInsert(head, toinsert, position);
    else{
        Node* node = cNode(toinsert);
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    cout<<ed;
    cout<<"After inserting: ";
    print(head);
    cout<<ed<<"After inserting in reverse: ";
    printreverse(tail);
}

int main() {
    // readme;
    // OJ;
    Node* head, *tail;
     cout<< "Enter the number of elements: ";
    int ITEM, elements;
    cin>>elements;
    cout<<"Enter elements: ";
    for(int i=0; i<elements; i++){
        cin>>ITEM;
        if(i==0){
            head = cNode(ITEM);
            tail = head;
        }
        else{
            tail->next = cNode(ITEM);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }
    
    cout<<"1. Delete\n2. Insert\nChoose you option: ";
    int option;
    do{
        cin>>option;
        if(option>2 || option<1) cout<<"Try Again!"<<ed;
    }while(option>2 || option<1);
    switch (option)
    {
    case 1:
        deleting(head, tail);
        break;
    case 2:
        inserting(head, tail, elements);
        break;
    default:
        print(head);
        break;
    }
    return 0;
}
