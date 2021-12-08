#include <iostream>
// doubly linked list is just a linked list with an extra pointer to traverse back
class doubly_linked_list
{
  int val;                      // value of node
  doubly_linked_list *next;     //  pointer to next node
  doubly_linked_list *previous; // pointer to prevous node

public:
  doubly_linked_list(int value) : val(value), next(NULL), previous(NULL)
  {
  } // initializing constructor and the node using initialiser list

  void insertion(int value);
  doubly_linked_list *deletion(int value);
  void display();
};
// Display function to display the linked list
void doubly_linked_list::display()
{
  doubly_linked_list *curr = this;
  std::cout << "NULL <-> ";
  while (curr != NULL) // traversing the linked list
  {
    std::cout << curr->val << " <-> ";
    curr = curr->next;
  }
  std::cout << "NULL" << std::endl;
}

// insert function to insert a node at end
void doubly_linked_list::insertion(int value)
{
  std::cout << "Inserting " << value << std::endl;
  doubly_linked_list *curr = this; // initialising a pointer pointing to the root
  while (curr->next != NULL)       // traversing to the last node
  {
    curr = curr->next;
  }
  curr->next = new doubly_linked_list(value); // creating a new node
  curr->next->previous = curr;                // setting up th pointers to point to the previous node
}

doubly_linked_list *doubly_linked_list::deletion(int value)
{
  std::cout << "Deleting " << value << std::endl;
  doubly_linked_list *curr = this; // initialising a pointer pointing to the root
  if (curr->val == value)          // if the value matches the root node return the node next to the root
  {
    curr->next->previous = NULL;
    return curr->next;
  }
  while (curr->next != NULL && curr->next->val != value) // traverse the linked list to find the node which is the previous node of node to be deleted
  {
    curr = curr->next;
  }
  if (curr->next == NULL)
  {
    std::cout << value << " was not found" << std::endl;
  }
  if (curr->next != NULL)
  {
    curr->next = curr->next->next; // deleting the node
    if (curr->next != NULL)
      curr->next->previous = curr; // setting up the previous pointer if its not the last node whch is getting deleted
  }
  return this;
}

int main()
{
  doubly_linked_list *root = new doubly_linked_list(10); // initialising root node
  root->insertion(20);                                   // inserting
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