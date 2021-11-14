#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next = NULL;
};

/*
INSERTION
*/

// Adding a node on the front of the list
void push(Node **head_ref, int new_data)
{
    // allocate Node
    Node *new_node = new Node(); // allocation

    // put in data
    new_node->data = new_data;

    // make next of new node as head
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Adding a node after a given node
void insertAfter(Node *prev_node, int new_data)
{
    // check if the given prev_node is NULL
    if (prev_node == NULL)
    {
        cout << "The given node cannot be NULL";
        return;
    }

    // allocate the new node
    Node *new_node = new Node();

    // put in the data
    new_node->data = new_data;

    // make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // move the next of prev_node as new_node
    prev_node->next = new_node;
}

// Ading a node at the end of the list
void append(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node = new Node();

    // used in step 5
    Node *last = *head_ref;

    // put in the data
    new_node->data = new_data;

    // new_node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // if the list is empty make new_node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // else traverse to the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // change the next of the last node
    last->next = new_node;
    return;
}

/*
DELETION
*/

// Deletion if a key is provided

// iterative implemetation
void deleteNodeIter(Node **head_ref, int key)
{
    // store the head node
    Node *temp = *head_ref;
    Node *prev = NULL;

    // if the head itself holds the key to br deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // changed head
        delete temp;            // free old head
        return;
    }

    // else search for the key to be deleted, keeping track of previous node
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        // if the key was not present in linked list
        if (temp == NULL)
            return;

        // unlink the node from linked list
        prev->next = temp->next;

        // free memory
        delete temp;
    }
}

// recursive implementation
void deleteNodeRec(Node *&head, int val)
{
    // Check if list is empty or we reach at the end of the list.
    if (head == NULL)
    {
        cout << "Element not present in the list\n";
        return;
    }
    // If current node is the node to be deleted
    if (head->data == val)
    {
        Node *t = head;
        head = head->next; // If it's start of the node head
                           // node points to second node
        delete (t);        // Else changes previous node's link to
                           // current node's link
        return;
    }
    deleteNodeRec(head->next, val);
}

// Deletion when a position is given
void deleteNodePos(Node **head_ref, int position)
{
    // if linked list is empty
    if (*head_ref == NULL)
        return;

    // store the head node
    Node *temp = *head_ref;

    // if head needs to be removed
    if (position == 0)
    {
        // change head
        *head_ref = temp->next;

        // free old head
        free(temp);
        return;
    }

    // else find the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // if position is more than the number of nodes
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position exceeded bounds of the list";
        return;
    }

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}

// deletion of the complete list
void deleteList(Node **head_ref)
{

    // deref head_ref to get the real head
    Node *current = *head_ref;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    // deref head_ref to affect the real head back in the caller.
    *head_ref = NULL;
}

/*
SEARCHING
*/

bool search(Node *head, int x)
{
    Node *current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

bool searchRec(struct Node *head, int x)
{
    // Base case
    if (head == NULL)
        return false;

    // If key is present in current node, return true
    if (head->data == x)
        return true;

    // Recur for remaining list
    return search(head->next, x);
}

/*
TRAVERSAL
*/

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// counting the  number of nodes in a linked list
int getCount(Node *head)
{
    int count = 0;        // Initialize count
    Node *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}