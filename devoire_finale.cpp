/*
chaymae mezouri
apg:19003213
P146000272 
*/

                        /// le code de devoir finale ///
#include <iostream>

using namespace std;

class Stack
{
private:
    int *stack;
    int taille;
    int index=-1;

public:
    Stack(int taille_par_defaut = 20) : taille(taille_par_defaut), index(-1)
    {
        stack = new int[taille];
    }

    ~Stack()
    {
        delete[] stack;
    }

    void operator<<(int n)
    {
        if (index < taille - 1)
        {
            stack[++index] = n;
        }
        else
        {
            throw "La pile est pleine impossible d ajouter";
        }
    }

    void operator>>(int &n)
    {
        if (index >= 0)
        {
            n = stack[index--];
        }
        else
        {
            throw "La pile est vide impossible de retirer";
        }
    }

    bool operator++()
    {
        return index == taille - 1;
    }

    bool operator--()
    {
        return index == -1;
    }
};

int main()
{
    Stack p;

    try
    {
        p << 10;
        p << 20;
        p << 30;

        int n1 = 0;
        int n2 = 0;
        int n3 = 0;

        p >> n1;
        p >> n2;
        p >> n3;

        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
        cout << "n3 = " << n3 << endl;

        if (++p)
        {
            cout << "La pile est pleine " << endl;
        }
        else
        {
            cout << "La pile n est pas pleine" << endl;
        }

        if (--p)
        {
            cout << "La pile est vid " << endl;
        }
        else
        {
            cout << "La pile n est pas vide" << endl;
        }
    }
    catch (char *e)
    {
        cerr << "Erreur: " << endl;
    }

    return 0;
}