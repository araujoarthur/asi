#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define DOT 0x2e
#define COMMA 0x2c

typedef struct _arbitraryInt{
    size_t length;
    int signal;
    uint32_t data[]; 
} arbitraryInt;

//arbitraryInt* arbitraryInteger(char* string);
void arbitraryInteger(char string[]);

void main(void)
{
    char* foo = "23134";
    arbitraryInteger(foo);
}

void arbitraryInteger(char string[]){
    // Counts total digits (i) and separators
    int i = 0;
    int separators = 0;

    while(string[i] != 0x00)
    {
        if (string[i] == COMMA || string[i] == DOT)
        {
            separators++;
        }
        i++;
    }

    // Infer total numeric digits
    size_t totalDigits = &string[i] - string - separators;

    int digits[totalDigits];
    int reverseIterator = totalDigits - 1;

    // Fill digits array so the 0 element is element * 10^0, second is element * 10^1, third is element * 10^2 [...]
    for(int k = 0; k < i; k++)
    {
        if (!(string[k] == COMMA || string[k] == DOT))
        {
            digits[reverseIterator] = (int) (string[k] - 48);
            reverseIterator--;
        }
    }

    size_t szLong = sizeof(uint32_t);
    printf("%i\n", szLong);

    /* DEBUG
    int pwr = (int) (1 << 3) + (1 << 1);
    int base = pwr;
    int soma = 0;
    for (int o = 0; o < totalDigits; o++)
    {
        if (o == 0)
        {
            soma += digits[o] * base/base;
        }
        else
        {
            soma += digits[o] * base;
            base *= pwr;
        }
    } */


}


int checkConformity(char* string)
{

}