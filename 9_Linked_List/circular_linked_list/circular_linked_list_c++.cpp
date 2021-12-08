#include <iostream>
// a circular linked list has no ends the last node of list points to the root
class circular_linked_list
{
 int value;                  // value of the node
 circular_linked_list *next; //  pointer to the next node

public:
 circular_linked_list(int value) : value(value), next(this)
 {
 }

 void insertion(int value);
 void display();
 circular_linked_list *deletion(int value);
};

// display function to display linked list
void circular_linked_list::display()
{
 circular_linked_list *curr = this;
 while (curr->next != this) // traversing the linked list
 {
  std::cout << curr->value << " <-> ";
  curr = curr->next;
 }
 std::cout << curr->value << " <-> " << this->value << std::endl;
}

// insert function to insert a node
void circular_linked_list::insertion(int value)
{
 std::cout << "Inserting " << value << std::endl;
 circular_linked_list *curr = this;
 while (curr->next != this)
 {
  curr = curr->next;
 }
 curr->next = new circular_linked_list(value);
 curr->next->next = this;
}

// delete function to delete node

circular_linked_list *circular_linked_list::deletion(int value)
{
 std::cout << "Deleting " << value << std::endl;
 circular_linked_list *curr = this;
 if (curr->value == value) // if the value matches the root node return the node next to the root
 {
  // as the root is changing we will have to make the last node point to the new root
  while (curr->next != this) // traversing to the last node
  {
   curr = curr->next;
  }
  curr->next = curr->next->next; // deleting the root node and last node pointing to the new root
  return curr->next;             // return new root
 }
 while (curr->next != this && curr->next->value != value) // traverse the linked list to find the node which is the previous node of node to be deleted
 {
  curr = curr->next;
 }
 if (curr->next == this)
 {
  std::cout << value << " was not found" << std::endl;
 }
 if (curr->next != this)
 {
  curr->next = curr->next->next; // deleting the node
 }
 return this;
}

int main()
{
 circular_linked_list *root = new circular_linked_list(10); // initialising root node
 root->insertion(20);                                       // inserting
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