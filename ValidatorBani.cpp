#include "ValidatorBani.h"
#include "ValidationBaniException.h"

ValidatorBani::ValidatorBani()
{
}

ValidatorBani::~ValidatorBani()
{
}

void ValidatorBani::validate(Bani* p) throw(ValidationBaniException)
{
    string errorMessage = "";

    if (p->getValoare() <= 0)
    {
        errorMessage += "Valoarea monezii trebuie sa fie strct pozitiva! \n";
    }

    if (p->getNrBani() <= 0)
    {
        errorMessage += "Numarul de monede trebuie sa fie strict pozitiv \n";
    }

    if (errorMessage.length() > 0)
    {
        throw ValidationBaniException(errorMessage);
    }
}
