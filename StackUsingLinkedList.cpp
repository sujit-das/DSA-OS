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

struct list
{
    int element;
    struct list* link;
};

class stack
{
    public:
        stack();
        int push(int);
        int pop(int&);
        int pop(void);
        static const int MAX = 4;

    private:
        int top;
        list* head;
};

stack::stack()
{
    top = -1;
    head = NULL;
}

int stack::push(int element)
{
    int result = -1;
    if(top < MAX -1)
    {
        list* node = new list;
        node->element = element;
        node->link = head;
        head = node;
        top++;
        result = 0;
        cout << endl << "Pushed " << head->element << endl;
    }
    else
    {
        cout << "Stack overflow!!" << endl;
    }
    return result;
}

int stack::pop(int& element)
{
    int result = -1;
    if(top >= 0)
    {
        element = head->element;
        list* temp = head->link;
        delete head;
        head = temp;
        top--;
        result = 0;
        cout << endl << "Poped " << element << endl;
    }
    else
    {
        cout << endl << "Stack underflow!!" << endl;
    }
    return result;
}

int stack::pop(void)
{
    int result = -1;
    if(top >= 0)
    {
        result = head->element;
        list* temp = head->link;
        delete head;
        head = temp;
        top--;
        cout << endl << "Poped " << result << endl;
    }
    else
    {
        cout << endl << "Stack underflow!!" << endl;
    }
    return result;
}

int main()
{
    cout<<"Hello World";
    stack s1;
    s1.pop();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    s1.push(3);
    s1.push(4);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    return 0;
}
