#ifndef UI_H
#define UI_H

#include "Service.h"
#include "ServiceBani.h"
class UI {
private:
	Service service;
	ServiceBani serviceBani;
	void displayMenu();
	void printProduse(vector<Produs*> produse);
	void printBani(vector<Bani*> banuti);
	void uiShowAll();
	void uiShowAllBani();
	void uiAddProdus();
	void uiAddBani();
	void uiModifyProdus();
	void uiDeleteProdus();
	void uiAchizitioneazaProdus();
	void uiAfiseazaBani();
public:
	UI();
	UI(Service& service, ServiceBani& serviceBani);
	~UI();

	void runMenu();
};

#endif
