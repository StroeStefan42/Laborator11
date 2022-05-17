#include "UI.h"
#include "RepoException.h"
#include "RepoBaniException.h"
#include "ValidationException.h"
#include "ValidationBaniException.h";
#include <iostream>

using namespace std;

/**
 * Afiseaza meniul.
 * 
 */
void UI::displayMenu()
{
	map<double, double> m;
	m.insert(pair<double, double>(1, 10));
	m.insert(pair<double, double>(5, 5));
	m.insert(pair<double, double>(10, 10));
	m.insert(pair<double, double>(50, 2));
	m.insert(pair<double, double>(100, 1));
	this->service.setCoins(m);
	cout << "1. Adaugare produs\n";
	cout << "2. Modificare produs\n";
	cout << "3. Stergere produs\n";
	cout << "4. Achizitie produs\n";
	cout << "5. Adaugare bani\n";
	cout << "a. Afisare toate produsele\n";
	cout << "b. Afiseaza banii disponibili\n";
	cout << "x. Iesire\n";
}

/**
 * Afiseaza produse.
 * 
 * \param produse
 */
void UI::printProduse(vector<Produs*> produse)
{
	for (int i = 0; i < produse.size(); i++)
	{
		cout << produse[i]->toString() << endl;
	}
}

/**
 * .
 * 
 */
void UI::uiShowAll()
{
	this->printProduse(this->service.getAll());
}

/**
 * Adaugare produs.
 * 
 */
void UI::uiAddProdus()
{
	cout << "Dati codul: ";
	double cod;
	cin >> cod;
	cin.ignore();

	cout << "Dati numele: ";
	string nume;
	getline(cin, nume);

	cout << "Dati pretul: ";
	double pret;
	cin >> pret;
	cin.ignore();

	try
	{
		this->service.addProdusService(cod, nume, pret);
	}
	catch (RepoException& e)
	{
		cout << e.what() << endl;
	}
	catch (ValidationException& e)
	{
		cout << e.toString() << endl;
	}
}

void UI::uiAddBani()
{
	cout << "Dati valoarea: ";
	double valoare;
	cin >> valoare;
	cin.ignore();

	cout << "Dati numarul de monede: ";
	double nrBani;
	cin >> nrBani;
	cin.ignore();

	try
	{
		this->serviceBani.addBaniService(valoare, nrBani);
    }
	catch (RepoBaniException& e)
	{
		cout << e.what() << endl;
	}
	catch (ValidationBaniException& e)
	{
		cout << e.toString() << endl;
	}
}

/**
 * Modifica produsul.
 * 
 */
void UI::uiModifyProdus()
{
	double codNou;
	cout << "Dati codul nou: ";
	cin >> codNou;
	cin.ignore();
	cout << "Dati numele vechiului produs: ";
	string numeVechi;
	getline(cin, numeVechi);
	cout << "Dati numele nou: ";
	string numeNou;
	getline(cin, numeNou);
	double pretNou;
	cout << "Dati pretul nou: ";
	cin >> pretNou;
	cin.ignore();
		try {
			this->service.updateProdusService(codNou, numeVechi, numeNou, pretNou);
		}
		catch (ValidationException& e) {
			cout << e.toString() << endl;
		}
		catch (RepoException& e) {
			cout << e.what() << endl;
		}
	
}

/**
 * Sterge produsul.
 * 
 */
void UI::uiDeleteProdus()
{
	cout << "Dati codul produsului pe care doriti sa il stergeti: ";
	double cod;
	cin >> cod;
	try {
		this->service.deleteProdusService(cod);
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

/**
 * Achizitionare produs.
 * 
 */
void UI::uiAchizitioneazaProdus()
{
	cout << "Dati codul produsului pe care vreti sa il achizitionati: ";
	double cod;
	cin >> cod;
		double pret_produs = this->service.getByCode(cod)->getPret();
		cout << "Introduceti bancnota: ";
		double valoare_bancnota_introdusa;
		cin >> valoare_bancnota_introdusa;
		if (valoare_bancnota_introdusa < pret_produs)
			cout << "Nu ati introdus suficienti bani!\n";
		else
		{
			double rest = valoare_bancnota_introdusa - pret_produs;
			map<double, double>M;
			if (this->service.enoughMoneyToGive(rest, M) == false)
				cout << "Ne pare rau, dar nu va putem da rest!\n";
			else
			{
				this->service.deleteProdusService(cod);
				this->service.addCoins(valoare_bancnota_introdusa, 1);
				map<double, double>::iterator it;
				for (it = M.begin(); it != M.end(); it++)
				{
					this->service.removeCoins(it->first, it->second);
					cout << it->first << " " << it->second << std::endl;
				}

				cout << "Multumim pentru achizitie!\n";
			}
		}
	
}

/**
 * Afisare bani.
 * 
 */
void UI::uiAfiseazaBani()
{
	map<double, double>::iterator it;
	map<double, double> all = this->service.getCoins();
	if (all.size() == 0)
		cout << "Nu sunt bani in tonomat!\n";
	for (it = all.begin(); it != all.end(); ++it)
		cout << it->first << ": " << it->second << endl;
}

void UI::printBani(vector<Bani*> banuti)
{
	for (int i = 0; i < banuti.size(); i++)
	{
		cout << banuti[i]->toString() << endl;
	}
}

void UI::uiShowAllBani()
{
	this->printBani(this->serviceBani.getAllBani());
}

/**
 * Constructor.
 * 
 */
UI::UI()
{
}

UI::UI(Service& service, ServiceBani& serviceBani)
{
	this->service = service;
}

UI::~UI()
{
}

void UI::runMenu()
{
	char option;
	int ok = 1;
	while (ok==1)
	{
		this->displayMenu();
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case '1':
		{
			this->uiAddProdus();
			break;
		}
		case '2':
		{
			this->uiModifyProdus();
			break;
		}
		case '3':
		{
			this->uiDeleteProdus();
			break;
		}
		case'4':
		{
			this->uiAchizitioneazaProdus();
			break;
		}
		case'5':
		{
			this->uiAddBani();
			break;
		}
		case 'a':
		{
			this->uiShowAll();
			break;
		}
		case 'b':
		{
			this->uiAfiseazaBani();
			break;
		}
		case 'x':
		{
			ok = 0;
			break;
		}
		default:
		{
			cout << "Optiune gresita! Reincercati: ";
			break;
		}
		}
	}
}
