#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    void setName(const string &n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }

    void setISBN(const string &n)
    {
        ISBN = n;
    }

    string getISBN() const
    {
        return ISBN;
    }

    void print() const
    {
        cout << "Name of book: " << name << endl;
        cout << "ISBN: " << ISBN << endl;
    }

private:
    string name;
    string ISBN;
};

int main()
{
    Book book;
    book.setName("C++ in 12 hours");
    book.setISBN("1234-456-USQBK");

    book.print();

    return 0;
}
