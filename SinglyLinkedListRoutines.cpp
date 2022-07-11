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
    cout << "Linked List: ";
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

// This function returns address of middle node of the linked List
// starting from the node passed as an argument
NodePtr findMidOfList(NodePtr head)
{
    NodePtr moveBy1 = head, moveBy2 = head;
    while(moveBy1 != nullptr && moveBy2 != nullptr && moveBy2 ->next !=nullptr && moveBy2 ->next->next !=nullptr)
    {
        moveBy1 = moveBy1->next;
        moveBy2 = moveBy2->next->next;
    }
    return moveBy1;
}

// This function swap node1 with node2 keeping the linklist as intended.
void swapNode(NodePtr &node1, NodePtr &node1_prev, NodePtr &node2, NodePtr &node2_prev)
{
    cout << "ENTRY :: node1 = " << node1->data << " node2_prev = " << node2_prev->data << " node2 = " << node2->data << endl;
    if(node1_prev == nullptr)
    {
        cout << "node1_prev is nullptr" << endl;
        NodePtr backup_node2_next = node2->next;

        node2->next = node1->next;

        node2_prev->next = node1;
        node1->next = backup_node2_next;
    }
    else
    {
        cout << "node1_prev is NOT nullptr" << endl;
        cout << "node1_prev = " << node1_prev->data << endl;
        NodePtr backup_node2_next = node2->next;

        node1_prev->next = node2;
        node2->next = node1->next;

        node2_prev->next = node1;
        node1->next = backup_node2_next;
    }

    NodePtr tmp = node1;
    node1 = node2;
    node2 = tmp;
    cout << "EXIT :: node1 = " << node1->data << " node2_prev = " << node2_prev->data << " node2 = " << node2->data << endl;
}

// This function sorts(in ascending order) the given linked list
// starting from the node passed as an argument, based on data field of the node
void sortList(NodePtr &head)
{
    NodePtr current1      = head;
    NodePtr current1_prev = nullptr;
    while(current1 != nullptr && current1->next != nullptr)
    {
        NodePtr current2 = current1->next;
        NodePtr current2_prev = current1;
        while(current2 != nullptr)
        {
            if(current1->data > current2->data)
            {
                // Node Swap
                //swapNode(current1, current1_prev, current2, current2_prev);
                
                // Data Swap
                int temp = current1->data;
                current1->data = current2->data;
                current2->data = temp;
            }
            current2_prev = current2;
            current2 = current2->next;
        }
        
        //printList(head);
        current1_prev = current1;
        current1 = current1->next;
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

    sortList(head);
    printList(head);

    NodePtr mid = findMidOfList(head);
    cout << "Middle of the list: " << mid->data << endl;
    
    for (int i = 11; i <= 20; i++)
    {
        insertInBeggining(head, i);
    }
    printList(head);

    sortList(head);
    printList(head);

    mid = findMidOfList(head);
    cout << "Middle of the list: " << mid->data << endl;

    deleteCurrentNode(head);
    printList(head);

    mid = findMidOfList(head);
    cout << "Middle of the list: " << mid->data << endl;

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

