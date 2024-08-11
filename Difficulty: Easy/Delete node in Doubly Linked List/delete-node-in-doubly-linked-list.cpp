//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* delete_head(Node* head){
        Node* temp = head;
        head = head->next;
        head->prev->next = NULL;
        head->prev = NULL;
        
        delete temp;
        return head;
    }
    Node* delete_tail(Node* head){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
        return head;
    }
    Node* deleteNode(Node* head, int x) {
       int count = 0;
       Node* knode = head;
       
       while(knode!=NULL){
           count++;
           if(count == x) break;
           knode = knode->next;
       }
       
       Node* back = knode->prev;
       Node* front = knode->next;
       
       if(back == NULL){
           return delete_head(head);
       }
       else if(front == NULL){
           return delete_tail(head);
       }
       
       back->next = front;
       front->prev = back;
       
       knode->next = NULL;
       knode->prev = NULL;
       
       delete knode;
       return head;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends