#include "worker.h"

void Worker::Get()
{
    cout << "Please enter worker's fullname: ";
    cin >> fullname;
    cout << "please enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        ;
}

void Worker::Data() const
{
    cout << "Fullname:" << fullname << endl;
    cout << "ID:" << id << endl;
}

void Waiter::Get()
{
    cout << "Please enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        ;
}

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Set()
{
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    Worker::Data();
    Data();
}

const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Get()
{
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

void Singer::Data() const
{
    cout << "Vioce:" << pv[vioce] << endl;
}

void Singer::Set()
{
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    Worker::Data();
    Data();
}

void SingingWaiter::Set()
{
    Worker::Get();
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Show() const
{
    Worker::Data();
    Singer::Data();
    Waiter::Data();
}