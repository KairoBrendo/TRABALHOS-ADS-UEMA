// DISCENTES: Kairo Brendo, Paulo Ricardo, Nilton Cesar, Regys Chaves 
// DOCENTE: Yonara Costa Magalhães
// DISCIPLINA: Estrutura de Dados
// ATIVIDADE: Nota 3 - Implementação de código e apresentação - CENÁRIO 2 FARMÁCIA
// DESCRIÇÃO: O programa ordena os preços de 500 medicamentos de uma farmácia em ordem decrescente, utilizando o algoritmo Quick Sort...


#include <stdio.h>
#include <stdlib.h>
#define TAM 500 // constante para o numero de medicamentos


void TrocaFloat (float *a, float *b ) { // funcao para trocar os preços (valor float)
    float aux = *a;
    *a = *b;
    *b = aux;
}
    
void TrocaInt (int *a, int *b ) { // funcao para trocar a numeração dos medicamentos (valor int)
    int aux = *a;
    *a = *b;
    *b = aux;
}

int Particionamento (float precos[], int medicamentos[], int inicio, int fim) {
    float pivo = precos[fim]; // escolha do ultimo elemento como pivo
    int i = inicio - 1; // marcação do ultimo elemento do bloco dos maiores

    for (int j = inicio; j < fim; j++) {
        if (precos[j] > pivo) { // condição para definir ordem decrescente (com sinal ">")
            i++;

            TrocaFloat (&precos[i], &precos[j]); // troca de preços

            TrocaInt (&medicamentos[i], &medicamentos[j]); // troca de numeração dos medicamentos
        }
    }
    
    TrocaFloat (&precos[i + 1], &precos[fim]);
    TrocaInt (&medicamentos[i + 1], &medicamentos[fim]);

    return i + 1;  // devolve a posição final do pivô
}

void QuickSort (float precos[], int medicamentos[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = Particionamento (precos, medicamentos, inicio, fim);
        
        QuickSort (precos, medicamentos, inicio, pivo - 1);// ordena a parte à esquerda do pivô com recursão

        QuickSort (precos, medicamentos, pivo + 1, fim); // ordena a parte à direita do pivô com recursão
        
    }     
}


// FUNÇÃO PRINCIPAL
int main() {

    float precos[TAM];
    int medicamentos[TAM];
    

    printf(">>>> BEM VINDO AO SISTEMA ORDENACAO DE PRECOS DE MEDICAMENTOS - FARMACIA <<<<\n");
    printf("\n---> Insira os precos (> 0.0) dos %d medicamentos abaixo:\n", TAM);

    for (int i = 0; i < TAM; i++) {
        medicamentos[i] = i + 1;
        do {
            printf("\nPreco do Medicamento %d: R$ ", medicamentos[i]);
            scanf("%f", &precos[i]);
            
            if (precos[i] <= 0) { //validação dos preços (não aceita valor menor ou igual a 0)
                printf("Valor invalido! Tente novamente.\n");
            }
        } while (precos[i] <= 0); // garante que ao digitar um valor invalido, retorne solicitando o preço do medicamento novamente
    }

    //EXIBIÇÃO DOS PREÇOS SEM ORDENAÇÃO
    printf("\n----------------------------------------");
    printf("\nPrecos dos medicamentos sem ordenacao:");
    for (int i = 0; i < TAM; i++) {
        printf("\nMedicamento %d = R$ %.2f", medicamentos[i], precos[i]);
    }
    printf("\n----------------------------------------");
    
    // CHAMADA DA FUNÇÃO DE ORDENAÇÃO
    QuickSort (precos, medicamentos, 0, TAM - 1);
    
    
    //EXIBIÇÃO DOS PREÇOS ORDENADOS (DECRESCENTE)
    printf("\n\n___________________________________________________________");
    printf("\n>>>> PRECOS ORDENADOS (MAIOR PARA MENOR) <<<<\n");
    for (int i = 0; i < TAM; i++) {
        printf("Medicamento %d -> R$ %.2f\n", medicamentos[i], precos[i]);
    }
    printf("___________________________________________________________");


    return 0;
} 
