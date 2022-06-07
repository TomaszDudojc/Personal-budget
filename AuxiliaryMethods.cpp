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

string AuxiliaryMethods::changeFirstLetterToCapitalAndOtherToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::loadLine()
{
    string enrtrance = "";
    getline(cin, enrtrance);
    return enrtrance;
}
