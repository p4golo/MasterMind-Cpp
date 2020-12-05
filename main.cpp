#include <iostream>
#include "mmind_basic.h"
#include "modulo1.h"
using namespace std;

int main()
{
    print_if();
    const int difficulty = level();
    const int length = lenghtCode(difficulty);
    const int possibleValues = values(difficulty);
    const int tries = opportunities(difficulty);
    bool repeat = repeats();
    unsigned int code[length];
    unsigned int tryNumber[length];
    random_code(code,repeat,length,possibleValues);
    game(code,tryNumber,length,tries);

    return 0;
}

