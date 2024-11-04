#include<stdio.h>
#include<iostream>

void clearScreen() {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}

typedef struct node{
    int data;
    node* next;
}node;

node* create_node(int data){
    node* new_node= (node*)malloc(sizeof(node));
    new_node->data=data;

    new_node->next=nullptr;

    return new_node;
}

//function declarations
void print_list(node* head);

//insert at beginning
node* insert_at_beg(node* head,int data){
    node* new_node= (node*)malloc(sizeof(node));

    new_node->next=head;
    new_node->data=data;
    head=new_node;
    return head;
}

//insert after specified location
void insert_after(node* head,int loc,int data){
    node* ptr=head;
    for(int i=1;i<loc;++i){
        ptr=ptr->next;
        if(head==NULL)
            printf("INVALID OPERATION");
    }

    node* new_node= (node*)malloc(sizeof(node));
    
    new_node->data=data;
    new_node->next=ptr->next;
    ptr->next=new_node;
}

//insert at end
void insert_at_end(node* head,int data){
    node*ptr= head;
    while(ptr->next)
        ptr=ptr->next;

    node* new_node= (node*)malloc(sizeof(node));

    new_node->data=data;
    new_node->next=NULL;
    ptr->next=new_node;
}

//delete specific value from list
node* deleteNode(struct node* head, int key) 
{ 
    struct node *temp = head; 

    if(temp->next==nullptr)
        return nullptr;
    
    if(temp->data==key){
        head=temp->next;
    }
    
    while(temp->next->data!=key){
        temp=temp->next;
        if(temp->next==nullptr){
            printf("Value not found.");
            return head;
        }
    }

    temp->next=temp->next->next;

   return head;
} 

//delete from beginning
node* delete_beg(node* head){
    struct node *temp = head; 

    if(temp->next==nullptr)
        return nullptr;
    
    
    head=temp->next;
    return head;
    
}

//delete from end
node* delete_end(node* head){
    struct node *temp = head; 

    if(temp->next==nullptr)
        return nullptr;
    
    
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    temp->next=nullptr;
    return head;
    
}

int main(){
     int a;
    printf("\n...............................................................\n");
    printf("\t INITIALIZING LINKED LIST");
    printf("\n...............................................................\n");
    //taking size of linked list to be initialized
    int nt;
    printf("Enter no of terms: ");
    scanf("%d",&nt);

    clearScreen();

   //taking values of each node 
    printf("\n \nEnter element 1:  ");
    scanf("%d",&a);
    node* node1= create_node(a);
    node* head= node1;
    node* temp= head;
    for(int i=0;i<nt-1;++i){
        printf("\nEnter element %d:  ",i+2);
        scanf("%d",&a);
        temp->next= create_node(a);
        temp=temp->next;
    }

    //main menu of the program
    edit:
        clearScreen();
    print_list(head);
    
     renter:
    printf("ENTER CHOICE: \n");
    printf("\t 1. Insert data at beginning. \n");
    printf("\t 2. Insert data at end. \n");
    printf("\t 3. Insert data after a postion. \n");
    printf("\t 4. Delete an element. \n");
    printf("\t 5. Delete an element from beginning. \n");
    printf("\t 6. Delete an element from end. \n");
    printf("\t 99. EXIT \n");
   
    int choice;
    scanf("%d",&choice);

    clearScreen();
    
    switch (choice){
        case 1: 
                print_list(head);
                int newval;
                printf("Enter value to insert at beginning:");
                scanf(" %d",&newval);
                clearScreen();
                head=insert_at_beg(head,newval);
                print_list(head);
                break;
        case 2:
                print_list(head);
                printf("Enter value to insert at end:");
                scanf(" %d",&newval);
                clearScreen();
                insert_at_end(head,newval);
                print_list(head);
                break;
        case 3:
                print_list(head);
                int location;
                printf("Enter location:");
                scanf("%d",&location);
                printf("Enter value to insert:");
                scanf("%d",&newval);
                clearScreen();
                insert_after(head,location,newval);
                print_list(head);
                break;
        case 4:
                print_list(head);
                int val;
                printf("Enter Value to be deleted:");
                scanf("%d",&val);
                clearScreen();
                head=deleteNode(head,val);
                print_list(head);
                break;
        case 5:
                print_list(head);
                clearScreen();
                head=delete_beg(head);
                print_list(head);
                break;
        case 6:
                print_list(head);
                clearScreen();
                head=delete_end(head);
                print_list(head);
                break;
        case 99:
                exit(0);
                break;
        default:
                print_list(head);
                printf("\tINVALID INPUT\n\tRE-ENTER valid value ");
                choice=-1;
    printf("\n...............................................................\n");
                goto renter;
                break;
    }
    
    
        goto edit;

}

//function to print the list
void print_list(node* head){
   
    
    printf("\n...............................................................\n");
     if(head==nullptr){
        printf("EMPTY LIST");
        
    }
    else{
        printf("Printing linked list:\n\n");
    // printf("%d\t",head);
   node* temp= head;
    int i=0;
    printf("%d ",temp->data);
    temp=temp->next;
    while (temp)
    {
        printf("------>%d ",temp->data);
        temp=temp->next;
    }
    }
    
    printf("\n...............................................................\n\n");
}



