#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cifrar(char *mensagem, int chave) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] = ((mensagem[i] - 'A' + chave) % 26) + 'A';
        }
    }
}

void decifrar(char *mensagem, int chave) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] = ((mensagem[i] - 'A' - chave + 26) % 26) + 'A';
        }
    }
}

int main() {
    int chave, opcao;
    char mensagem[100];

    printf("DIGITE O TEXTO PARA SER CIFRADO (APENAS LETRAS MAIÚSCULAS)\n");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';

    printf("DIGITE UM NÚMERO DESEJADO DE 1 A 25 PARA SER A CHAVE\n");
    scanf("%d", &chave);

    if (chave < 1 || chave > 25) {
        printf("CHAVE INVÁLIDA. DEVE SER ENTRE 1 E 25.\n");
        return 1;
    }

    cifrar(mensagem, chave);
    printf("TEXTO CIFRADO: %s\n", mensagem);

    decifrar(mensagem, chave);
    printf("TEXTO DECIFRADO: %s\n", mensagem);


    return 0;
}
