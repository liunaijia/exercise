#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

    struct product
    {
        int id_type;
        union
        {
            unsigned int id1;
            char id2[10];
        };
        double price;
    };
    product p;
    p.id_type = 1;
    p.id1 = 3344;
    
    if (p.id_type == 1)
        cout << p.id1;
    else
        cout << p.id2;
}