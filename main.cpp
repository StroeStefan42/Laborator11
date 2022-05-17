#include <iostream>
#include "Service.h"
#include "ServiceBani.h"
#include "RepoFile.h"
#include "RepoBaniFile.h"
#include "UI.h"
#include "Tests.h"

int main()
{   
    RepoFile* repo = new RepoFile("produse.txt");
    RepoBaniFile* repoBani = new RepoBaniFile("bani.txt");
    Service service(repo);
    ServiceBani serviceBani(repoBani);
    UI ui(service, serviceBani);
    testAll();
    cout << "Au rulat testele\n";

    ui.runMenu();
}