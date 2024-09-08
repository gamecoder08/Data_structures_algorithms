#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (!head)
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
        for (int i = 1; i < position - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            std::cout << "Position out of range." << std::endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
        {
            std::cout << "List is empty.";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head)
        {
            std::cout << "List is empty.";
            return;
        }

        if (!head->next)
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
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp || !temp->next)
        {
            std::cout << "Position out of range." << std::endl;
            return;
        }

        Node *nodetodelete = temp->next;
        temp->next = temp->next->next;
        delete nodetodelete;
    }

    void display()
    {
        if (!head)
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

    Node *middle(Node *start, Node *last)
    {
        if (start == NULL)
        {
            return NULL;
        }

        if (start == last)
        {
            return start;
        }

        Node *slow = start;
        Node *fast = start->next;

        while (fast != last)
        {
            fast = fast->next;
            slow = slow->next;
            if (fast != last)
            {
                fast = fast->next;
            }
        }
        return slow;
    }

    bool binarySearch(int target)
    {
        Node *start = head;
        Node *last = NULL;

        while (true)
        {
            Node *mid = middle(start, last);

            if (mid == NULL)
            {
                return false;
            }
            if (mid->data == target)
            {
                return true;
            }
            else if (start == last)
            {
                break;
            }
            else if (mid->data < target)
            {
                start = mid->next;
            }
            else if (mid->data > target)
            {
                last = mid;
            }
        }
        return false;
    }
};

int main()
{
    LinkedList list1;

    list1.display();
    list1.insertAtBeginning(8);
    list1.display();
    list1.insertAtEnd(29);
    list1.display();
    list1.insertAtBeginning(7);
    list1.display();
    list1.insertAtPosition(21, 3);
    list1.display();

    int target;
    std::cout << "Enter your target num: " << std::endl;
    std::cin >> target;

    std::cout << list1.binarySearch(target) << std::endl;
    return 0;
}