// Nima Mahanloo
// Recursion - CISP 430
#include <iostream>

using namespace std;
// Recursive module to add comma between input number digits as necessary
void numberPoint (char* input, char* (&temp), char* (&output), int (&numSize), int (&index))
{
    int counter = 0, n = 0;
    while (temp[counter] != '\0')
    {
        n++;
        counter++;
    }
    counter = 0;
    while ((counter < 3) && ((index-1-counter) >= 0))
    {
        temp[n] = input[index-1-counter];
        n++;
        counter++;
    }
    index -= counter;
    if ((counter >= 3) && (n < numSize))
    {
        temp[n] = ',';
        numSize++;
        temp[n+1] = '\0';
    }
    else
    {
        temp[n] = '\0';
    }
    if (n < numSize)
    {
        numberPoint(input, temp, output, numSize, index);
    }
    else
    {
        counter = 0;
        while (n > 0)
        {
            output[counter] = temp[n-1];
            counter++;
            n--;
        }
        output[counter] = '\0';
    }
}


int main()
{
    int counter = 0, sign = 1, index = 0, numSize = 0;
    bool isNumber = false;;
    char* inputChar = (char*)malloc(sizeof(char));
    char* tempChar = (char*)malloc(sizeof(char));
    char* outputChar = (char*)malloc(sizeof(char));
    tempChar[0] = '\0';
    // A conditional loop to get, check and prove user input
    while ((counter < 1) || (counter > 10) || (isNumber == false))
    {
        cout << "Please enter a number maximum in 10 digit > ";
        cin >> inputChar;
        index = 0;
        isNumber = true;
        counter = 0;
        while (inputChar[counter] != '\0')
        {
            if (!(isdigit(inputChar[counter])))
            {
                if((counter == 0) && (inputChar[counter] == '-')){}
                else
                {
                    isNumber = false;
                }
            }
            counter++;
            index++;
        }
    }
    // A condition to explain input number sign as positive or negative and remove the minus sign from the character array
    if (inputChar[0] == '-')
    {
        sign = -1;
        counter = 1;
        while (inputChar[counter] != '\0')
        {
            tempChar[counter-1] = inputChar[counter];
            counter++;
        }
        tempChar[counter-1] = '\0';
        inputChar = tempChar;
        tempChar = (char*)malloc(sizeof(char));
        tempChar[0] = '\0';
        index--;
    }
    // A conditional loop to delete first digit as zero from the input number
    while (inputChar[0] == '0')
    {
        counter = 1;
        while (inputChar[counter] != '\0')
        {
            tempChar[counter-1] = inputChar[counter];
            counter++;
        }
        tempChar[counter-1] = '\0';
        inputChar = tempChar;
        tempChar = (char*)malloc(sizeof(char));
        tempChar[0] = '\0';
        index--;
    }
    // Character array size
    numSize = index;
    // Call recursive module to add commas at input number
    numberPoint(inputChar, tempChar, outputChar, numSize, index);
    cout << "Result is : ";
    // Add minus sign to first digit of negative input number
    if (sign == -1)
    {
        tempChar = (char*)malloc(sizeof(char));
        tempChar[0] = '-';
        counter = 1;
        while (outputChar[counter-1] != '\0')
        {
            tempChar[counter] = outputChar[counter-1];
            counter++;
        }
        tempChar[counter] = '\0';
        // Show output to user
        cout << tempChar << endl;
    }
    else
    {
        // Show output to user
        cout << outputChar << endl;
    }
    return 0;
}
