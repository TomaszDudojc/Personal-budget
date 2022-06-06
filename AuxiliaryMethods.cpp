#include "AuxiliaryMethods.h"


char AuxiliaryMethods :: loadCharacter()
{
    string enrtrance = "";
    char character  = {0};

    while (true)
    {
        getline(cin, enrtrance);

        if (enrtrance.length() == 1)
        {
            character = enrtrance[0];
            break;
        }
        cout << "This is not a single character. Please retype." << endl;
    }
    return character;
}
