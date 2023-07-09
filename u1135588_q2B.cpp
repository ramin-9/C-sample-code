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

    void print() const
    {
        cout << "Name of Book: " << name << endl;
    }

private:
    string name;
};

class CookBook : private Book
{
public:
    void setCookBookName(const string &n)
    {
        setName(n);
    }

    void setISBN(int n)
    {
        ISBN = n;
    }

    int getISBN() const
    {
        return ISBN;
    }

    void print() const
    {
        Book::print();
        cout << "ISBN: " << ISBN << endl;
    }

private:
    int ISBN;
};

int main()
{
    CookBook cbook;
    cbook.setCookBookName("Universities");
    cbook.setISBN(53545556);

    cbook.print();

    return 0;
}
