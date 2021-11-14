#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

/*
INSERTION
*/

// add a node to the front
void push(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node = new Node();

    //  put in the data
    new_node->data = new_data;

    // make next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// insert a new node after the given node
void insertAfter(Node *prev_node, int new_data)
{
    // check if the given prev_node is NULL
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    // allocate new node
    Node *new_node = new Node();

    // put in the data
    new_node->data = new_data;

    // make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // make the next of prev_node as new_node
    prev_node->next = new_node;

    // make prev_node as previous of new_node
    new_node->prev = prev_node;

    // change previous of new_node's next node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// add a node before a given node
void insertBefore(Node **head_ref, Node *next_node, int new_data)
{
    // check if a the given next_node is NULL
    if (next_node == NULL)
    {
        cout << "The next node cannot be NULL";
        return;
    }

    // allocate the new node
    Node *new_node = new Node();

    // put in the data
    new_node->data = new_data;

    // make prev of new_node as prev of next_node
    new_node->prev = next_node->prev;

    // make the next of new_node as next_node
    new_node->next = next_node;

    // make new_node as previous of next_node
    next_node->prev = new_node;

    // change the previous of next_node's next node
    if (new_node->prev != NULL)
        next_node->prev->next = new_node;

    // if the given node is the head, then the new node will be the new head.
    else
        *head_ref = new_node;
}

// append a new node at the end
void append(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node = new Node();

    Node *last = *head_ref; // used in step 5

    // put in the data
    new_node->data = new_data;

    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // if the Linked List is empty, then make the new node as head
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // else traverse till the last node
    while (last->next != NULL)
        last = last->next;

    // change the next of last node
    last->next = new_node;

    // make last node as previous of new node
    new_node->prev = last;

    return;
}

/*
DELETION
*/

// delete a node when pointer to the node is given
void deleteNode(Node **head_ref, Node *del)
{
    // bade case
    if (*head_ref == NULL || del == NULL)
        return;

    // if node to be deleted is the head node
    if (*head_ref == del)
        *head_ref = del->next;

    // change next only if node to be delted is NOT the last node
    if (del->next != NULL)
        del->next->prev = del->prev;

    // change prev only if node to be deleted is NOT the first node
    if(del->prev!=NULL)
        del->prev->next = del->next;
    
    // free the memory occupied by del
    free(del);
    return;
}

// delete a node at a given position
void deleteNodePos(Node** head_ref, int position)
{
    if(*head_ref==NULL|| position<=0)
        return;

    Node *current = *head_ref;

    // traverse up to the given node from the beginning 
    for (int i = 1; current != NULL && i < position; i++)
        current = current->next;
    
    // if position is more than the number of nodes
    if (current == NULL )
    {
        cout << "Position exceeded bounds of the list";
        return;
    }

    // delete the node pointed to by 'current' 
    deleteNode(head_ref, current);
}

/*
TRAVERSAL
*/

void printList(Node *node)
{
    Node *last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}
