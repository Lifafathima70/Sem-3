#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

int main()
{
    node *start = NULL, *head, *temp;
    int n, i, pos, value;

    // Create list
    cout << "Enter number of nodes: ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        temp = new node;

        cout << "Enter data: ";
        cin >> temp->data;

        temp->prev = NULL;
        temp->next = NULL;

        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            head = start;

            while(head->next != NULL)
                head = head->next;

            head->next = temp;
            temp->prev = head;
        }
    }

    // INSERT AT BEGINNING
    temp = new node;

    cout << "Enter value to insert at beginning: ";
    cin >> value;

    temp->data = value;
    temp->prev = NULL;
    temp->next = start;

    if(start != NULL)
        start->prev = temp;

    start = temp;


    // INSERT AT END
    temp = new node;

    cout << "Enter value to insert at end: ";
    cin >> value;

    temp->data = value;
    temp->next = NULL;

    head = start;

    while(head->next != NULL)
        head = head->next;

    head->next = temp;
    temp->prev = head;


    // INSERT AT SPECIFIC POSITION
    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter value: ";
    cin >> value;

    temp = new node;
    temp->data = value;

    head = start;

    for(i = 1; i < pos - 1; i++)
        head = head->next;

    temp->next = head->next;
    temp->prev = head;

    if(head->next != NULL)
        head->next->prev = temp;

    head->next = temp;


    // DISPLAY
    cout << "\nDoubly Linked List: ";

    head = start;

    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}