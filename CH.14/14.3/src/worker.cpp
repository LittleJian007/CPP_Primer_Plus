#include "worker.h"

void Worker::Set()
{
    cout << "Please enter worker's fullname: ";
    cin >> fullname;
    cout << "please enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        ;
}

void Worker::Show() const
{
    cout << "Fullname:" << fullname << endl;
    cout << "ID:" << id << endl;
}

void Waiter::Set()
{
    Worker::Set();
    cout << "Please enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        ;
}

void Waiter::Show() const
{
    Worker::Show();
    cout << "Panache rating: " << panache << endl;
}

const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    Worker::Set();
    cout << "Please enter number for singer's vocal range: " << endl;
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ":" << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> vioce && (vioce < 0 || vioce > Vtypes))
        cout << "Please enter a value (from 0 to " << Vtypes << ")" << endl;

    while (cin.get() != '\n')
        ;
}

void Singer::Show() const
{
    Worker::Show();
    cout << "Vioce:" << pv[vioce] << endl;
}