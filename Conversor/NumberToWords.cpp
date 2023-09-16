#include <stdio.h>

void escreverNumero(int numero) {
    const char* unidades[] = { "", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove" };
    const char* dezenas[] = { "", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa" };

    if (numero < 10) {
        printf("%s", unidades[numero]);
    }
    else if (numero < 20) {
        const char* especiais[] = { "Dez", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove" };
        printf("%s", especiais[numero - 10]);
    }
    else {
        int unidade = numero % 10;
        int dezena = numero / 10;
        if (unidade == 0) {
            printf("%s", dezenas[dezena]);
        }
        else {
            printf("%s e %s", dezenas[dezena], unidades[unidade]);
        }
    }
}

int main() {
    long long int numero;
    printf("Digite um numero de ate seis digitos: ");
    scanf_s("%lld", &numero);

    if (numero < 0 || numero > 999999) {
        printf("Número fora do intervalo válido.\n");
        return 1;
    }

    int milhar = numero / 1000;
    int centena = (numero % 1000) / 100;
    int dezena = (numero % 100) / 10;
    int unidade = numero % 10;

    if (milhar > 0) {
        escreverNumero(milhar);
        printf("Mil");
        if (centena > 0 || dezena > 0 || unidade > 0) {
            printf(", ");
        }
    }

    if (centena > 0) {
        escreverNumero(centena);
        printf("centos");
        if (dezena > 0 || unidade > 0) {
            printf(" e ");
        }
    }

    if (dezena > 0 || unidade > 0) {
        escreverNumero(dezena * 10 + unidade);
    }

    printf(" Reais\n");

    return 0;
}
