#include <iostream>
using namespace std;
// Every node of linked list has some structure we wil provide that structure using user defined data type
class linked_list
{
 int value;         // value of the node
 linked_list *next; // pointer to the next node

public:
 linked_list(int value) : value(value), next(NULL) // declaring coonstructor
 {
 }

 void insertion(int value);        // function for inserting a node in linked list
 linked_list *deletion(int value); // function for deleting a node in linked list
 void display();                   // function for displaying the linked list
};

void linked_list::insertion(int value)
{
 linked_list *curr = this;  // initialising a pointer pointing to the root
 while (curr->next != NULL) // traversing to the last node with hwlp of pointer
 {
  curr = curr->next;
 }
 curr->next = new linked_list(value); // inserting new node at the last
}

linked_list *linked_list::deletion(int value)
{
 linked_list *curr = this; // initialising a pointer pointing to the root
 if (curr->value == value) // if the value matches the root node retuirn the node next to the root
 {
  return curr->next;
 }
 while (curr->next != NULL && curr->next->value != value) // traverse the linked list to find the node which is the previous node of node to be deleted
 {
  curr = curr->next;
 }
 if (curr->next == NULL)
 {
  cout << value << " was not found" << endl;
 }
 if (curr->next != NULL)
 {
  curr->next = curr->next->next; // deleting the node
 }
 return this;
}

void linked_list::display()
{
 linked_list *curr = this; // initialising a pointer pointing to the root
 while (curr != NULL)      // traversing the linked list and printing every node to the console
 {
  cout << curr->value << "->";
  curr = curr->next;
 }
 cout << "NULL" << endl;
}

int main()
{
 linked_list *root = new linked_list(10); // initialising root node
 root->insertion(20);                     // inserting
 root->insertion(30);
 root->insertion(40);
 root->insertion(50);
 root->insertion(60);
 root->display();
 root = root->deletion(60); // deleting
 root->display();
 root = root->deletion(70); // deleting
 root->display();
 root = root->deletion(10); // deleting
 root->display();
 root = root->deletion(40); // deleting
 root->display();
}