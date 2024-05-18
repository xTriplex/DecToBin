#include <stdio.h>
#include <stdlib.h>

#define BINARY_SIZE 8

void decimalToBinary(int n, int binaryNum[], int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        binaryNum[i] = n % 2;
        n = n / 2;
    }
}

void findTwosComplement(int binaryNum[], int size) 
{
    int i;
    int carry = 1;
    for (i = 0; i < size; i++) 
    {
        binaryNum[i] = binaryNum[i] == 1 ? 0 : 1;
    }
    for (i = 0; i < size; i++) 
    {
        binaryNum[i] += carry;
        if (binaryNum[i] == 2) 
        {
            binaryNum[i] = 0;
            carry = 1;
        } 
        else 
        {
            carry = 0;
        }
    }
}

void printBinary(int binaryNum[], int size) 
{
    int i;
    for (i = size - 1; i >= 0; i--) 
    {
        printf("%d", binaryNum[i]);
    }
}

int main() 
{
    int n;
    int binaryNum[BINARY_SIZE] = {0};

    do 
    {
        printf("Enter a decimal number: ");
        if (scanf("%d", &n) != 1) 
        {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer.\n");
        } 
        else 
        {
            break;
        }
    } while (1);

    if (n < 0) 
    {
        n = abs(n);
        decimalToBinary(n, binaryNum, BINARY_SIZE);
        findTwosComplement(binaryNum, BINARY_SIZE);
    } 
    else if (n == 0) 
    {
        printf("Binary equivalent     : 00000000\n");
        printf("2's complement        : 00000000\n");
        return 0;
    }
    else 
    {
        decimalToBinary(n, binaryNum, BINARY_SIZE);
    }

    printf("Binary equivalent     : ");
    printBinary(binaryNum, BINARY_SIZE);
    printf("\n");

    if (n > 0) 
    {
        findTwosComplement(binaryNum, BINARY_SIZE);
    }

    printf("2's complement        : ");
    printBinary(binaryNum, BINARY_SIZE);
    printf("\n");

    return 0;
}
