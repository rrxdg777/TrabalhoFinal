#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
    char proprietario[50];
    char combustivel[10];
    char modelo[50];
    char cor[20];
    char chassi[20];
    char placa[8];
    struct Veiculo *prox;
} Veiculo;

void listar_proprietarios_carros_2010(Veiculo *carros);
void listar_placas_J(Veiculo *carros);
void listar_modelos_cores(Veiculo *carros);
void trocar_proprietario(Veiculo *carros, char *chassi, char *novo_proprietario);

int main() {

    listar_proprietarios_carros_2010(carros);
    listar_placas_J(carros);
    listar_modelos_cores(carros);
    trocar_proprietario(carros, "CHASSI_EXEMPLO", "NOVO_PROPRIETARIO");

    return 0;
}

void listar_proprietarios_carros_2010(Veiculo *carros) {
    Veiculo *aux = carros;
    while (aux != NULL) {
        int ano = atoi(aux->ano);
        if (ano >= 2010 && strcmp(aux->combustivel, "diesel") == 0) {
            printf("%s\n", aux->proprietario);
        }
        aux = aux->prox;
    }
}

void listar_placas_J(Veiculo *carros) {
    Veiculo *aux = carros;
    while (aux != NULL) {
        if (strncmp(aux->placa, "J", 1) == 0 && strchr("AEIOU", aux->placa[1]) != NULL) {
            int soma = 0;
            for (int i = 0; i < 7; i++) {
                if (isdigit(aux->placa[i])) {
                    soma += aux->placa[i] - '0';
                }
            }
            if (soma % 2 == 0 && (strcmp(aux->placa, "J000000") == 0 || strcmp(aux->placa, "J200000") == 0 ||
                                   strcmp(aux->placa, "J400000") == 0 || strcmp(aux->placa, "J700000") == 0)) {
                printf("%s - %s\n", aux->placa, aux->proprietario);
            }
        }
        aux = aux->prox;
    }
}

void listar_modelos_cores(Veiculo *carros) {
    Veiculo *aux = carros;
    while (aux != NULL) {
        if (strchr("AEIOU", aux->placa[1]) != NULL) {
            int soma = 0;
            for (int i = 0; i < 7; i++) {
                if (isdigit(aux->placa[i])) {
                    soma += aux->placa[i] - '0';
                }
            }
            if (soma % 2 == 0) {
                printf("%s - %s\n", aux->modelo, aux->cor);
            }
        }
        aux = aux->prox;
    }
}

void trocar_proprietario(Veiculo *carros, char *chassi, char *novo_proprietario) {
    Veiculo *aux = carros;
    while (aux != NULL) {
        if (strcmp(aux->chassi, chassi) == 0) {
            int possui_zero = 0;
            for (int i = 0; i < 7; i++) {
                if (aux->placa[i] == '0') {
                    possui_zero = 1;
                    break;
                }
            }
            if (!possui_zero) {
                strcpy(aux->proprietario, novo_proprietario);
            }
        }
        aux = aux->prox;
    }
}