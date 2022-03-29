#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tc()          \
    ll test_case;     \
    cin >> test_case; \
    while (test_case--)
#define ed '\n'
#define readme                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)
#define OJ                         \
    freopen("in.txt", "r", stdin); \
    freopen("out.txt", "w", stdout);

struct Node
{
    int data;
    Node *next;
};

Node *cNode(int ITEM)
{
    Node *new_node = new Node();
    new_node->data = ITEM;
    new_node->next = NULL;
    return new_node;
}

Node* ToDelete(Node *head, int ITEM)
{
    if (head->data == ITEM)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;
        while ((temp->data != ITEM) && (temp != NULL))
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->next == NULL){
            prev->next = NULL;
        }
        else if (temp != NULL)
        {
            // cout<< "Found"<<endl;
            prev->next = temp->next;
            delete (temp);
        }
        else
            cout << "Not Found" << endl;
    }
    return head;
}

Node* ToInsert(Node* head, int position, int ITEM){
    int index = 0;
    Node* temp = head, *prev = NULL;
    while((index != position) && (temp->next != NULL)){
        prev = temp;
        temp = temp->next;
        index++;
    }
    if(index == 0){
        head = cNode(ITEM);
        head->next = temp;
    }
    else if(temp->next == NULL){
        temp->next = cNode(ITEM);
    }
    else{
        prev->next = cNode(ITEM);
        prev->next->next = temp;
    }
    return head;
}

void print(Node *head)
{
    // cout<< "Displaying elements data: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void DeleteFunction(Node* head){
    cout<<"Enter a ITEM to delete: ";
    int operand;
    cin >> operand;
     head = ToDelete(head, operand);
     print(head);
}

void InsertFunction(Node* head){
    cout<<"Enter ITEM to insert: ";
    int position, operand;
    cin>>operand;
    cout<<"Enter 0 base index position: ";
    cin>>position;
    head = ToInsert(head, position, operand);
    print(head);
}

int main()
{
//    readme;
    // OJ;
    Node *head, *start;
    cout<< "Enter number of elements: ";
    int element_number;
    cin >> element_number;
    cout<< "Enter elements: \n";
    for (int i = 0; i < element_number; i++)
    {
        int ITEM;
        cin >> ITEM;
        if (i == 0)
        {
            Node *temp = cNode(ITEM);
            start = temp;
            head = start;
        }
        else
        {
            Node *temp = cNode(ITEM);
            start->next = temp;
            start = temp;
        }
    }
    cout<<"Choose your option: \n";
    cout<<"1. Want to delete?\n2. Want to insert?\n";
    int option, chance = 7;
    do{
        chance--;
        cin>>option;
        if(option<1 || option>2) cout<< "Try Again!"<<endl;
    }while((option<1 || option>2) && chance);
    switch (option)
    {
        case 1:
        DeleteFunction(head);
        break;
        case 2:
        InsertFunction(head);
        break;
        defaul:
        print(head);
    }
}
