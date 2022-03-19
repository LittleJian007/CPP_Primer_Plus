#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    int qs;
    Item temp;
    int i = 0;
    int customers = 0;
    cout << "Enter maximum size of queue: ";
    cin >> qs;

    Queue line(qs);

    while (!line.isfull())
    {
        temp.set(i++);
        line.enqueue(temp);
        customers++;
    }
    cout << "Customers: " << customers << endl;

    while (!line.isempty())
    {
        line.dequeue(temp);
        customers--;
    }
    cout << "New customers: " << customers << endl;
    return 0;
    
}