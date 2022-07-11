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

// Insert in the beginning of the linked list
void insertBeg(NodePtr &head, int element)
{
    NodePtr new_node = new Node;
    new_node->data = element;
    new_node->next = head;
    head = new_node;
}

// Insert at the end of the linked list
void insertEnd(NodePtr &head, int element)
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

// Delete from the beginning of the linked list
void deleteBeg(NodePtr &head)
{
    if(head != nullptr)
    {
        NodePtr old_head = head;
        head = head->next;
        delete old_head;
        old_head = nullptr;
    }
}

// Delete from the end of the linked list
void deleteEnd(NodePtr &head)
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

// Delete next of the node passed as argument
void deleteNext(NodePtr current)
{
    if((current != nullptr) && (current->next != nullptr))
    {
        NodePtr remove_node = current->next;
        current->next = current->next->next;
        delete (remove_node);
    }
}

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

int main()
{
    cout<<"Hello Linked List" << endl;
    NodePtr head = nullptr;
    
    for (int i = 10; i >= 1; i--)
    {
        insertEnd(head, i);
    }

    printList(head);
    
    for (int i = 11; i <= 20; i++)
    {
        insertBeg(head, i);
    }

    printList(head);

    deleteBeg(head);
    printList(head);

    deleteEnd(head);
    printList(head);

    deleteNext(head); 
    printList(head);

    deleteNext(head->next->next->next);
    printList(head);

    deleteBeg(head->next->next->next);
    printList(head);

    deleteEnd(head->next->next->next);
    printList(head);

    NodePtr prev = nullptr, loc = nullptr;
    searchList(head, 19, prev, loc);
    searchList(head->next, 19, prev, loc);
    searchList(head, 3, prev, loc);
    searchList(head, 20, prev, loc);
    searchList(nullptr, 2, prev, loc);
    cout << "Good Bye Linked List" << endl;
    return 0;
}


