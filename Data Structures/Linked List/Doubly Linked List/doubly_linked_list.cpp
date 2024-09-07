#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class Dlinkedlist
{
    Node *head;

public:
    Dlinkedlist()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            std::cout << "Position should be atleast 1." << std::endl;
            return;
        }
        else if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node();
        newNode->data = value;

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Position out of range." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            std::cout << "List is empty.";
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == NULL)
        {
            std::cout << "List is empty";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteFromPosition(int position)
    {
        if (head == NULL)
        {
            std::cout << "The list is already empty." << std::endl;
            return;
        }

        if (position < 1)
        {
            std::cout << "Position should be atleast 1." << std::endl;
            return;
        }

        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position && temp; ++i)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Position out of range." << std::endl;
            return;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "Null" << std::endl;
    }
};

int main()
{
    Dlinkedlist list1;

    list1.display();
    list1.insertAtBeginning(7);
    list1.display();
    list1.insertAtEnd(29);
    list1.display();
    list1.insertAtBeginning(8);
    list1.display();
    list1.insertAtPosition(21, 3);
    list1.display();

    list1.deleteFromBeginning();
    list1.display();
    list1.deleteFromEnd();
    list1.display();

    return 0;
}