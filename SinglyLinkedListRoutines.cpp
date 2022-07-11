/*
 *
 * Copyright (C) 2022 Sujit Das
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, see <http://www.gnu.org/licenses/>.
 */
 
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};
typedef Node* NodePtr;

// This function prints contents of linked list
// starting from the given node
void printList(NodePtr n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// This function inserta in the front of the given node
void insertInBeggining(NodePtr &head, int element)
{
    NodePtr new_node = new Node;
    new_node->data = element;
    new_node->next = head;
    head = new_node;
}

// This function inserts at the end of the linked list
// starting from the given node
void insertAtEnd(NodePtr &head, int element)
{
    NodePtr new_node = new Node;
    new_node->data = element;
    new_node->next = nullptr;
    
    if(head == nullptr)
        head = new_node;
    else
    {
        NodePtr current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;        
    }
}

// This function deletes the current node of the linked list
void deleteCurrentNode(NodePtr &current)
{
    if(current != nullptr)
    {
        NodePtr copy_current = current;
        current = current->next;
        delete copy_current;
        copy_current = nullptr;
    }
}

// This function deletes the last node of the linked list
// starting from the given node
void deleteLastNode(NodePtr &head)
{
    if(head != nullptr)
    {
        NodePtr current = head;
        NodePtr previous = nullptr;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        if(previous != nullptr)
            previous->next = nullptr;

        delete current;

        if(previous == nullptr)
            head = nullptr;
    }
}

// This function deletes the next node of the argument node in the linked list
void deleteNextNode(NodePtr current)
{
    if((current != nullptr) && (current->next != nullptr))
    {
        NodePtr remove_node = current->next;
        current->next = current->next->next;
        delete (remove_node);
    }
}

// This function searches for element in the linked list starting from the given node
// If found, it provides address of the matching node and its previous node.
// If the matching node is the head-node, the previous node is expected to be nullptr
// If not found, nullptr is retuned in both loc and prev
void searchList(NodePtr head, int element, NodePtr &prev, NodePtr &loc)
{
    prev = nullptr;
    loc  = nullptr;

    if(head != nullptr)
    {
        NodePtr current  = head;
        NodePtr previous = nullptr;
        if(current->data == element)
        {
            prev = previous;
            loc  = current;
            cout << "Item " << element << " Found, previous = UNKNOWN, loc = " << current->data << endl;
        }
        else
        {
            while (current->next != nullptr)
            {
                if(current->next->data == element)
                {
                    prev = current;
                    loc  = current->next;
                    cout << "Item " << element << " Found, previous = " << prev->data << " loc = " << loc->data << endl;
                    break;
                }
                previous = current;
                current = current->next;
            }   
        }
        if(loc == nullptr)
            cout << "Item " << element << " Not found in list" << endl;
    }
    else
        cout << "Invalid list" << endl;
}

// This function deletes the node whose data matches with the argument.
// The list starting from the given node is considered as input list
void deleteItemInNode(NodePtr &current,  int element)
{
    NodePtr prev = nullptr, loc = nullptr;
    searchList(current, element, prev, loc);

    if(loc != nullptr)
    {
        if(prev != nullptr)
            prev->next = loc->next;
        else
            current = loc->next;
        delete (loc);
    }
}

// Test function
int main()
{
    cout<<"Hello Linked List" << endl;
    NodePtr head = nullptr;
    
    for (int i = 10; i >= 1; i--)
    {
        insertAtEnd(head, i);
    }

    printList(head);
    
    for (int i = 11; i <= 20; i++)
    {
        insertInBeggining(head, i);
    }

    printList(head);

    deleteCurrentNode(head);
    printList(head);

    deleteLastNode(head);
    printList(head);

    deleteNextNode(head); 
    printList(head);

    deleteNextNode(head->next->next->next);
    printList(head);

    deleteCurrentNode(head->next->next->next);
    printList(head);

    deleteLastNode(head->next->next->next);
    printList(head);

    NodePtr prev = nullptr, loc = nullptr;
    searchList(head, 19, prev, loc);
    searchList(head->next, 19, prev, loc);
    searchList(head, 3, prev, loc);
    searchList(head, 20, prev, loc);
    searchList(nullptr, 2, prev, loc);
    
    deleteItemInNode(head,13);
    printList(head);

    deleteItemInNode(head,3);
    printList(head);

    deleteItemInNode(head,19);
    printList(head);

    deleteItemInNode(head,-19);
    printList(head);

    cout << "Good Bye Linked List" << endl;
    return 0;
}
