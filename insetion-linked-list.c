#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
};
    
int main ()
{
    
    struct node *current, *tail, * head, *temp;
    current = NULL;
    head = NULL;
    tail = NULL;
    
    current = (struct node*)malloc(sizeof(struct node));
    current -> value = 'A';
    current -> next = NULL;
    head = current;
    tail = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current -> value = 'B';
    current -> next = NULL;
    head -> next = current;
    tail = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current -> value = 'C';
    current -> next = NULL;
    tail -> next = current;
    tail = current;
    
    //BEGINNING
    struct node  *newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert at the beginning: ");
    scanf("%c", &newnode -> value);
    newnode -> next = head;
    head = newnode;
    
    temp = head;
    while (temp != NULL)
    {
        printf ("%c ", temp -> value);
        temp = temp -> next;
    }
    
    // END
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at the end: ");
    scanf(" %c", &newnode->value);
    newnode->next = NULL;
    
    tail->next = newnode;
    tail = newnode;
    
    temp = head;
    while (temp != NULL) {
        printf("%c ", temp->value);
        temp = temp->next;
    }
    
    //any any boi
    int pos, i = 1, count = 0;
temp = head;
while (temp != NULL) {
    count++;
    temp = temp->next;
}

printf("\nEnter the position you want (1 to %d): ", count+1);
scanf("%d", &pos);

if (pos < 1 || pos > count+1) {
    printf("Position is invalid\n");
} else {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf(" %c", &newnode->value);

    if (pos == 1) {
        // beginning
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        for (i = 1; i < pos-1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        if (pos == count+1) {
            tail = newnode; 
        }
    }
}

if (head != NULL) {
    temp = head;
    head = head->next;   
    free(temp);          
}

// DELETE LAST NODE
if (head != NULL) {
    temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;  
        tail = prev;        
    } else {
   
        head = NULL;
        tail = NULL;
    }
    free(temp);             
}

// Print list after insertion
temp = head;
printf("\n Final Linked List after: ");
while (temp != NULL) {
    printf("%c ", temp->value);
    temp = temp->next;
}

  
    return 0;
}