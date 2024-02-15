#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letter;
    struct node *next;
} node;

// Returns number of nodes in the linkedList.

int length(node *head)
// In order to read the length, we have to measure its length by reading thru it => a new variable
{
    int count = 0;
    // The linked list is traversed from head to the last node, and length is increased at each iteration.
    while (head != NULL)
    {
        count++;
        head = head->next; // keep traversing
    }
    return count; // return the length of that linkedlist
}
// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char *toCString(node *head)
{
    int sizeOfString = length(head);
    int i = 0;
    char *string = (char *) malloc(sizeOfString + 1);
	if (head == NULL){
		printf(" The string is empty");
	}
    // traversing and add head->letter to the string above
    while (head != NULL)
    {
        string[i] = head->letter;
        head = head->next;
        i++; // increase counter variable
    }
    string[sizeOfString] = '\0'; // set the last char = NUL
    return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
    // initialize a new Node to store char c
    node *newNode = (node *) malloc(sizeof(node));
    //check the condition
    if(newNode == NULL)
    {
        printf("Memory Allocation failure");
    }
    newNode->letter = c;
    newNode->next = NULL;
    // a temp pointer 4 traversing purpose
    node *temp = *pHead;
    // check the condition if pHead = NULL -> add char c to head
    if (*pHead == NULL)
    {
        *pHead = newNode;
        return;
    }
    else
    {
        // Add newNode to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
    // initialize a temp pointer for traversing purpose
    node *temp = *pHead;
    while (temp != NULL)
    {
        temp = temp->next;
        free(*pHead);
        *pHead = temp;
    }
}

int main(void)
{
    int i, strLen, numInputs;
    node *head = NULL;
    char *str;
    char c;
    FILE *inFile = fopen("input.txt", "r"); // open file for reading

    fscanf(inFile, " %d\n", &numInputs); // reads the numbers of inputs from the file, consuming any leading whitespace characters

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}
