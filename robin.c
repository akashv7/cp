#include <stdio.h>
#include <stdlib.h>

struct node {
    int id,at,bt,ct,tempbt,isComplete;
    struct node*next;
}

int front=-1 ,rear=-1;

struct node*create(int n){
    struct node*temp=NULL;
    struct node*head=NULL;
    for(int i=0;i<n;i++){
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->id=i+1;
        printf("ARRIVAL TIME:");
        scanf("%d",newnode->at);
        printf("BURST TIME:");
        scanf("%d",newnode->bt);
        newnode->tempbt=newnode->bt;
        newnode->isComplete=0;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        newnode->next=NULL;// MARANNU POOKUM
    }
    return sort(head);
}

struct node*sort(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        struct node*temp2=head->next;
        while(temp2!=NULL){
            if(temp->at<temp2->at){
                int id=temp->id;
                int at=temp->at;
                int bt=temp->bt;
                int tempbt=temp->tempbt;

                temp->id=temp->id;
                temp->at=temp->at;
                temp->bt=temp2->bt;
                temp->tempbt=temp2->tempbt;

                temp2->at=at;
                temp2->bt=bt;
                temp2->id=id;
                temp2->tempbt=tempbt;
            }
            temp2=temp2->next;
        }
    temp=temp->next;
    }
return head;//marakkkummmmmmmmmmmmmm
}


robin(struct node*head,int qt){
    struct node *queue[20];
    int currentct=0;
    enqueue(queue,head);
    while(isEmpty(queue)==0){
        struct node*current=dequeue(queue);
        if(current->tempbt<=qt){
            currentct +=current->tempbt;//MARAKUMMMMMMM
            current->ct=currentct;
            current->tempbt=0;// MARAKKUMMMMMMM
            current->isComplete=1;
        }
        else(){
            current->tempbt=(current->tempbt)-qt;//BRACKETS MARAKALLE
            currentct+=qt;
            struct node*temp=current->next;
            while(temp!=NULL && (temp->at)<=currentct && (temp->isComplete)!=1 ){
                if(isinqueue())
                enqueue(queue,temp);
                temp=temp->next;
            }
        }
    }

}

void enqueue(struct node*queue[],struct node*head){
        if(front==-1 && rear=-1){
            front=rear=0;
            queue[rear]=head;
        }
        else{
            rear++;
            queue[rear]=head;
        }
}

void isEmpty(struct node* queue[]){
    if (front == -1 && rear == -1) return 1;
    else return 0;
}

void main(){
    int n,qt;
    printf("ENTER TOTAL NO:");
    scanf("%d",&n);
    struct node*head=create(n);
    printf("ENTER QT: ");
    scanf("%d",&qt);
    robin();
}