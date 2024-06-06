#include <stdio.h>
#include <stdlib.h>

int processes, pointer = -1;

struct node{
    int id, at, bt, ct, tat, wt, isCompleted, priority;
    struct node* next;
};

struct node* head = NULL;

//For Printing
void SortByID(){
    struct node* temp = head;
    while(temp != NULL){
        struct node* smallNode = temp;
        struct node* temp2 = temp -> next;
        while(temp2 != NULL){
            if((temp2 -> id) < (smallNode -> id)){
                smallNode = temp2;
            }
            temp2 = temp2 -> next;
        }
        if(temp != smallNode){
            int id = temp -> id;
            int at = temp -> at;
            int bt = temp -> bt;
            int ct = temp -> ct;
            int tat = temp -> tat;
            int wt = temp -> wt;
            int pr = temp -> priority;

            temp -> id = smallNode -> id;
            temp -> at = smallNode -> at;
            temp -> bt = smallNode -> bt;
            temp -> ct = smallNode -> ct;
            temp -> tat = smallNode -> tat;
            temp -> wt = smallNode -> wt;
            temp -> priority = smallNode -> priority;

            smallNode -> id = id;
            smallNode -> at = at;
            smallNode -> bt = bt;
            smallNode -> ct = ct;
            smallNode -> tat = tat;
            smallNode -> wt = wt;
            smallNode -> priority = pr;
        }
        temp = temp -> next;
    }
}

void ReadProcesses(){
    struct node* temp = head;
    for(int i = 0; i < processes; i++){
        printf("\nPROCESS %d\n", i+1);
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> id = i+1;
        newNode -> isCompleted = 0;
        printf("\nArrival Time: ");
        scanf("%d", &newNode -> at);
        printf("Burst Time: ");
        scanf("%d", &newNode -> bt);
        printf("Priority (lower the value, higher the priority) : ");
        scanf("%d", &newNode -> priority);

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp -> next = newNode;
            temp = newNode;
        }

        newNode -> next = NULL;
    }
}

int AllCompleted(){
    struct node* temp = head;
    while(temp != NULL){
        if(temp -> isCompleted == 0)
            return 0;
        temp = temp -> next;
    }
    return 1;
}

void CheckArrival(struct node* array[], int currentTime){
    struct node* temp = head;
    while(temp != NULL){
        if((temp -> at <= currentTime) && (temp -> isCompleted == 0)){
            pointer++;
            array[pointer] = temp;
        }
        temp = temp -> next;
    }
}

struct node* ReturnExecutable(struct node* array[]){
    struct node* maxPriority = array[0];
    for(int i = 1; i <= pointer; i++){
        if(array[i] -> priority < maxPriority -> priority){
            maxPriority = array[i];
        }
    }
    pointer = -1;
    return maxPriority;
}

void Display(){
    SortByID();
    struct node* temp = head;
    printf("ID\tPR\tAT\tBT\tCT\tTAT\tWT\n\n");
    while(temp != NULL){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", temp -> id, temp -> priority, temp -> at, temp -> bt,
               temp -> ct, temp -> tat, temp -> wt);
        temp = temp -> next;
    }
}

void Sort(){
    struct node* temp = head;
    while(temp != NULL){
        struct node* smallNode = temp;
        struct node* temp2 = temp -> next;
        while(temp2 != NULL){
            if((temp2 -> at) < (smallNode -> at)){
                smallNode = temp2;
            }
            temp2 = temp2 -> next;
        }
        if(temp != smallNode){
            int id = temp -> id;
            int at = temp -> at;
            int bt = temp -> bt;
            int pr = temp -> priority;
            temp -> id = smallNode -> id;
            temp -> at = smallNode -> at;
            temp -> bt = smallNode -> bt;
            temp -> priority = smallNode -> priority;
            smallNode -> id = id;
            smallNode -> at = at;
            smallNode -> bt = bt;
            smallNode -> priority = pr;
        }
        temp = temp -> next;
    }
}

void Execute(){
    int currentTime = head -> at;
    while(AllCompleted() == 0){
        struct node* array[processes];
        CheckArrival(array, currentTime);
        struct node* process = ReturnExecutable(array);

        currentTime += process -> bt;
        process -> ct = currentTime;
        process -> tat = (process -> ct) - (process -> at);
        process -> wt = (process -> tat) - (process -> bt);
        process -> isCompleted = 1;
    }
    Display();
}

void main(){
    printf("Priority Scheduling\n");
    printf("-------------------\n\n");
    printf("Enter total number of processes: ");
    scanf("%d", &processes);
    ReadProcesses();
    Sort();
    Execute();
}