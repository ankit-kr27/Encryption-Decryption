// #include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main()
{
    cout << "\n\n***EncDec***\n\nSelect the operation you want to perform :- \n1. Encryption\n2. Decryption\n\nInput : ";
    int n = 0;int i = 0;
    
    do{
        if(i!=0)cout << "\nInvalid input, Please enter again \n\nInput : ";
        cin >> n;
        i=1;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }while(n != 1 && n != 2);

    switch (n)
    {
    case 1:
    {
        system("cls");
        cout << "You've chose to perform encryption \n";

        string data;
        cout << "\nEnter your data (to be encrypted) below :-\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        getline(cin, data);

        srand(time(0)); // seeding rand() to increase the randomity

        int key[5];
        for (int i = 0; i < 5; i++)
        {
            key[i] = rand() % 127;
        }

        int ln = data.length();
        int cng = 0, branch = (ln / 5) + (ln % 5 != 0);
        for (int i = 0; i < branch; i++)
        {
            if (i == branch - 1 && ln%5 != 0)
            {
                cng = 5 - ln % 5;
                // if(cng==5)     //commited by avinav
                // cng=0;
            }
            for (int j = 5 * i, k = 0; j < 5 * (i + 1) - cng; j++, k++)
            {
                data[j] += key[k];
            }
        }
        cng = 0;
        cout << "Encrypted Data :-\n\n|"
             << data<<"|";

        cout << "\n\nYour security is : ";
        for (int i = 0; i < 5; i++)
            cout << key[i] << " ";
        
        cout <<"\n\n";
        break;
    }
    case 2:
    {
        string _data;
        cout << "\nYou've chose to decrypt your data \n\n";
        cout << "Put/Paste your encrypted data below :- \n\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        getline(cin, _data);

        int _key[5];

        cout << "\nEnter the respective key : ";
        for (int i = 0; i < 5; i++)
            cin >> _key[i];

        int _ln = _data.length();
        int _cng = 0, _branch = (_ln / 5) + (_ln % 5 != 0);

        for (int i = 0; i < _branch; i++)
        {
            if (i == _branch - 1 && _ln%5 != 0)
                _cng = 5 - _ln % 5;
            for (int j = 5 * i, k = 0; j < 5 * (i + 1) - _cng; j++, k++)
            {
                _data[j] -= _key[k];
            }
        }

        cout << "The decrypted data is :- \n"
             << _data;
        break;
    }
    default:
        cout << "\nOops !, Something went wrong ";
        break;
    }
    return 0;
}
