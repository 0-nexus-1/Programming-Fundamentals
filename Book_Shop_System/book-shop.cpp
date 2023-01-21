#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class book
{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book()
    {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }
    int storedata();
    int editdata();
    int showdata();
    int search(char[], char[]);
    int buybook();
};

int book::storedata()
{
    cin.ignore();
    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);

    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);

    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;
}

int book::editdata()
{

    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);

    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);

    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;
}

int book::showdata()
{
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;

    cout << "\nPublisher Name: " << publisher;

    cout << "\nPrice: " << *price;
    cout << "\nStock Position: " << *stock;
}

int book::search(char tbuy[20], char abuy[20])
{
    if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0) // tbuy = title buy and abuy = author buy
        return 1;
    else
        return 0;
}

int book::buybook()
{
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;

    if (count <= *stock)
    {
        *stock = *stock - count;
        cout << "\nBooks Bought Sucessfully";
        cout << "\nAmount: Rs. " << (*price) * count;
    }
    else
        cout << "\nRequired Copies not in Stock";
}

int main()
{
    book *B[20];
    int i = 0, r, t, choice;
    char titlebuy[20], authorbuy[20];

    cout << "\t\tTIME              :           " << __TIME__ << endl;
    cout << "\t\tDATE              :           " << __DATE__ << endl;
    cout << "\t\t=========================================" << endl;

    while (1)
    {

        cout << "\n\n\t\tMENU" << endl;
        cout << "\t\t====" << endl;

        cout << "\n1. --> Entry of New Book"
             << "\n2. --> Buy Book"
             << "\n3. --> Search For Book"
             << "\n4. --> Edit Details Of Book"
             << "\n5. --> Exit"
             << "\n\n       Enter your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            B[i] = new book;
            B[i]->storedata();
            i++;
            break;

        case 2:
            cin.ignore();

            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);

            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    B[t]->buybook();
                    break;
                }
            }
            if (t == 1)
                cout << "\nThis Book is Not in Stock";
            break;

        case 3:
            cin.ignore();

            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);

            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    cout << "\n***Book Found Successfully***\n";
                    B[t]->showdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nSorry, This Book is Not in Stock ";
            break;

        case 4:
            cin.ignore();

            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);

            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    cout << "\n***Book Found Successfully***\n";
                    B[t]->editdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 5:
            exit(0);
        default:
            cout << "\nInvalid Choice Entered";
        }
    }

    return 0;
}
