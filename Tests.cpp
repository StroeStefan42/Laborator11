#include "Tests.h"
#include "TestRepo.h"
#include "TestRepoFile.h"
#include "TestProdus.h"
#include "TestValidatorProdus.h"
#include "TestService.h"
using namespace std;
void testAll()
{
    TestProdus testProdus;
    testProdus.testAll();

    TestValidatorProdus testValidatorProdus;
    testValidatorProdus.testAll();

    //TestRepo testRepo;
    //testRepo.testAll();

    //TestRepoFile testRepoFile;
    //testRepoFile.testAll();

    TestService testService;
    testService.testAll();
}
