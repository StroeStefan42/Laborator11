#include "RepoBani.h"
#include "RepoBaniException.h"
#include "ValidationBaniException.h"

/**
 * Constructor.
 *
 */
RepoBani::RepoBani()
{
}

/**
 * Deconstructor.
 *
 */
RepoBani::~RepoBani()
{
    this->empty();
}

/**
 * Returnare produse.
 *
 * \return
 */
vector<Bani*> RepoBani::getAllBani()
{
    vector<Bani*> banutiCopie;
    for (int i = 0; i < this->banuti.size(); i++)
    {
        banutiCopie.push_back(this->banuti[i]->clone());
    }
    return banutiCopie;
}

/**
 * Marime repo.
 *
 * \return
 */
int RepoBani::getSize()
{
    return this->banuti.size();
}

/**
 * Getter dupa index.
 *
 * \param index
 * \return
 */
Bani* RepoBani::get(int index) throw(RepoBaniException)
{
    //if (index < 0 || index >= this->produse.size())
    //{
        //throw RepoException("Index invalid!");
    //}
    return this->banuti[index]->clone();
}

/**
 * Gaseste produsul.
 *
 * \param p
 * \return
 */
int RepoBani::find(Bani* p)
{
    for (int i = 0; i < this->banuti.size(); i++)
    {
        if (*this->banuti[i] == *p)
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
void RepoBani::addBani(Bani* p) throw(RepoBaniException, ValidationBaniException)
{

    if (this->find(p) != -1)
    {
        throw RepoBaniException("Produsul nu poate fi adaugat pt. ca exista deja!");
    }
    this->banuti.push_back(p->clone());

}

/**
 * Modifica produs.
 *
 * \param pVechi
 * \param pNou
 * \return
 */
void RepoBani::updateBani(Bani* pVechi, Bani* pNou) throw(RepoBaniException, ValidationBaniException)
{

    for (int i = 0; i < this->banuti.size(); i++)
    {
        if (this->banuti[i]->getValoare() == pVechi->getValoare())
        {
            delete this->banuti[i];
            this->banuti[i] = pNou->clone();
            return;
        }
    }
    throw RepoBaniException("Produsul nu poate fi updatat pt. ca nu exista!");
}

/**
 * Sterge produs.
 *
 * \param p
 * \return
 */
void RepoBani::deleteBani(Bani* p) //throw(RepoException)
{
    bool found = false;
    for (int i = 0; i < this->banuti.size(); i++)
    {
        //if (*this->produse[i] == *p)
        if (**(this->banuti.begin() + i) == *p)
        {
            delete this->banuti[i];
            this->banuti.erase(this->banuti.begin() + i);
            i--;
            found = true;
            break;
        }
    }/*
    if (!found)
    {
        throw RepoException("Produsul nu poate fi sters pt. ca nu exista!");
    }
    */
}

/**
 * Goleste repo.
 *
 */
void RepoBani::empty()
{
    for (int i = 0; i < this->banuti.size(); i++)
    {
        if (this->banuti[i] != NULL)
        {
            delete this->banuti[i];
            this->banuti[i] = NULL;
        }
    }
    this->banuti.clear();
}