#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int multiplica_karatsuba(int x, int y, int n) {
    if(n == 1) {
        return x * y;
    }

    int metadeN = n/2;
    int dezAMetadeN = (pow(10, metadeN));

    int a = x / (pow(10, metadeN));
    int b = x % dezAMetadeN;
    int c = y / (pow(10, metadeN));
    int d = y % dezAMetadeN;

    int ac = multiplica_karatsuba(a, c, metadeN);
    int ad = multiplica_karatsuba(a, d, metadeN);
    int bc = multiplica_karatsuba(b, c, metadeN);
    int bd = multiplica_karatsuba(b, d, metadeN);

    return ac*(pow(10, n)) + (ad + bc)*(pow(10, (n/2)) + bd);
}

int main() {
    int num1 = 10000;
    int num2 = 10000;
    int digitos = 4;

    int resultado = multiplica_karatsuba(num1, num2, digitos);

    printf("A multiplicação dos inteiros %d e %d é %d\n", num1, num2, resultado);
    return 0;
}