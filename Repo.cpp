#include "Repo.h"
#include "RepoException.h"
#include "ValidationException.h"

/**
 * Constructor.
 * 
 */
Repo::Repo()
{
}

/**
 * Deconstructor.
 * 
 */
Repo::~Repo()
{
    this->empty();
}

/**
 * Returnare produse.
 * 
 * \return 
 */
vector<Produs*> Repo::getAll()
{
    vector<Produs*> produseCopie;
    for (int i = 0; i < this->produse.size(); i++)
    {
        produseCopie.push_back(this->produse[i]->clone());
    }
    return produseCopie;
}

/**
 * Marime repo.
 * 
 * \return 
 */
int Repo::getSize()
{
    return this->produse.size();
}

/**
 * Getter dupa index.
 * 
 * \param index
 * \return 
 */
Produs* Repo::get(int index) throw(RepoException)
{
    if (index < 0 || index >= this->produse.size())
    {
        throw RepoException("Index invalid!");
    }
    return this->produse[index]->clone();
}

/**
 * Gaseste produsul.
 * 
 * \param p
 * \return 
 */
int Repo::find(Produs* p)
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        if (*this->produse[i] == *p)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Adauga produs.
 * 
 * \param p
 * \return 
 */
void Repo::addProdus(Produs* p) throw(RepoException, ValidationException)
{
    
    if (this->find(p) != -1)
    {
        throw RepoException("Produsul nu poate fi adaugat pt. ca exista deja!");
    }
    this->produse.push_back(p->clone());
    
}

/**
 * Modifica produs.
 * 
 * \param pVechi
 * \param pNou
 * \return 
 */
void Repo::updateProdus(Produs* pVechi, Produs* pNou) throw(RepoException, ValidationException)
{

    for (int i = 0; i < this->produse.size(); i++)
    {
        if (this->produse[i]->getNume() == pVechi->getNume())
        {
            delete this->produse[i];
            this->produse[i] = pNou->clone();
            return;
        }
    }
    throw RepoException("Produsul nu poate fi updatat pt. ca nu exista!");
}

/**
 * Sterge produs.
 * 
 * \param p
 * \return 
 */
void Repo::deleteProdus(Produs* p) throw(RepoException)
{
    bool found = false;
    for (int i = 0; i < this->produse.size(); i++)
    {
        //if (*this->produse[i] == *p)
        if (**(this->produse.begin() + i) == *p)
        {
            delete this->produse[i];
            this->produse.erase(this->produse.begin() + i);
            i--;
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw RepoException("Produsul nu poate fi sters pt. ca nu exista!");
    }
}

/**
 * Goleste repo.
 * 
 */
void Repo::empty()
{
    for (int i = 0; i < this->produse.size(); i++)
    {
        if (this->produse[i] != NULL)
        {
            delete this->produse[i];
            this->produse[i] = NULL;
        }
    }
    this->produse.clear();
}
