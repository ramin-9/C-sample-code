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
    void printBook() const
    {
        cout << "Name of book: " << getName() << endl;
        cout << "ISBN: " << getISBN() << endl;
    }

private:
    string name;
    string ISBN;
};

class CookBook : public Book
{
public:
    void print() const
    {
        cout << "Name of CookBook: " << getName() << endl;
        cout << "ISBN: " << getISBN() << endl;
    }
};

bool Bsame(const Book &book1, const Book &book2)
{
    return (book1.getName() == book2.getName()) && (book1.getISBN() == book2.getISBN());
}

bool Csame(const CookBook &cookbook1, const CookBook &cookbook2)
{
    return Bsame(cookbook1, cookbook2);
}

int main()
{
    Book book1, book2;
    book1.setName("Universities");
    book1.setISBN("1234-456-USQBK");
    book1.printBook();
    book2.setName("Universities");
    book2.setISBN("1234-457-USQBK");
    book2.printBook();
    if (Bsame(book1, book2))
    {
        cout << "The books are the same!" << endl;
    }
    else
    {
        cout << "The books are different!" << endl;
    }

    CookBook cookbook1, cookbook2;
    cookbook1.setName("Universities");
    cookbook1.setISBN("53545556");
    cookbook1.print();
    cookbook2.setName("Universities");
    cookbook2.setISBN("53545556");
    cookbook2.print();
    if (Csame(cookbook1, cookbook2))
    {
        cout << "The books are the same!" << endl;
    }
    else
    {
        cout << "The books are different!" << endl;
    }

    return 0;
}
