#include <stdio.h>
#include <stdlib.h>

#define TAMCli 10

#define TAMProd 20

#define TAMVenda 20

typedef struct {

    int id;

    char nome[30];

    int quantidade;

    float valor;

}Produto;



typedef struct {

    int id;

    char nome[20];

}Cliente;



typedef struct {

    int idCliente;

    int idProduto;

    int quantProduto;

    float valorTotal;

}Venda;





void cadastrarCliente (Cliente c[], int *qtd_clientes) {
    char continuar;

    while (*qtd_clientes < TAMCli) {
        printf("\nCliente %d, Primeiro Nome: ", *qtd_clientes + 1);
        scanf("%s", c[*qtd_clientes].nome);
        c[*qtd_clientes].id = *qtd_clientes + 1;
        (*qtd_clientes)++;

        if (*qtd_clientes == TAMCli) {
            printf("\n|LIMITE DE CLIENTES ATINGIDO|\n");
            break;
        }

    printf("\nDESEJA CADASTRAR OUTRO CLIENTE? (S ou N): ");
    scanf(" %c", &continuar);
        if(continuar == 'n' || continuar == 'N'){
            break;
        }
    }

}

void cadastrarProduto (Produto p[], int *qtd_produtos) {
    char continuar;

    while(*qtd_produtos < TAMProd) {

        printf("\nNome do Produto %d: ", *qtd_produtos + 1);

        scanf(" %[^\n]", p[*qtd_produtos].nome); // " %[^\n]" - Permite espaços no nome do produto - LER TUDO ANTES DE CLICAR ENTER

        printf("Quantidade: ");

        scanf("%d", &p[*qtd_produtos].quantidade);

        printf("Valor: ");

        scanf("%f", &p[*qtd_produtos].valor);

        p[*qtd_produtos].id = *qtd_produtos + 1;
        (*qtd_produtos)++;

        if (*qtd_produtos == TAMProd){
            printf("Limite de produtos atingido!\n");
            break;
        }

    printf("\nDESEJA CADASTRAR OUTRO PRODUTO? (S ou N): ");
    scanf(" %c", &continuar);
        if(continuar == 'n' || continuar == 'N'){
            break;
        }
    }

}

void consultarCliente (Cliente c[], int qtd_clientes) {

    if (qtd_clientes == 0){
    printf("\nNAO HA CLIENTES CADASTRADOS!\n\n");
    system("pause");
    return;
    }

    printf("\nLista de clientes cadastrados:\n");

    for(int i=0; i < qtd_clientes; i++) { 
        printf("\nCliente %d - %s", c[i].id, c[i].nome);
    }

    printf("\n\n");
    system("pause");

}

void consultarProduto (Produto p[], int qtd_produtos) {

    if (qtd_produtos == 0){
        printf("\nNAO HA PRODUTOS CADASTRADOS!\n\n");
        system("pause");
        return;
    }

    printf("\n----------------------------------");
    for(int i=0; i < qtd_produtos; i++) {

        printf("\nId do Produto: %d",  p[i].id);

        printf("\nNome Produto: %s", p[i].nome);

        printf("\nQuantidade: %d", p[i].quantidade);

        printf("\nValor: %.2f", p[i].valor);

        printf("\n----------------------------------");

    }

    printf("\n\n");
    system("pause");

}

void consultarVenda (Venda v[], int qtd_vendas) {
    if (qtd_vendas == 0) {
        printf("\nNAO HA VENDAS REALIZADAS!\n\n");
        system("pause");
        return;
    }

    for (int i=0; i<qtd_vendas; i++) {

        printf("\nID do comprador: %d", v[i].idCliente);

        printf("\nID do produto vendido: %d", v[i].idProduto);
        
        printf("\nQuantidade do produto vendido: %d", v[i].quantProduto);

        printf("\nValor arrecadado com a venda: %.2f", v[i].valorTotal);
    }

}

int main() {

    int opcao, sair=0; // sair inicialmente falso

    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda vendas[TAMVenda];

    int qtd_clientes = 0;
    int qtd_produtos = 0;
    int qtd_vendas = 0;

    

    do {

        system("cls");

        printf("<<<SEJA BEM VINDO!>>>");
        printf("\n\n>>>> Sistema de Vendas <<<< ");
        printf("\n|Escolha uma opcao:|");

        printf("\n\t1 - Cadastrar Clientes");

        printf("\n\t2 - Cadastrar Produtos");

        printf("\n\t3 - Consultar Clientes");

        printf("\n\t4 - Consultar Produtos");

        printf("\n\t5 - Realizar Venda");

        printf("\n\t6 - Consultar Vendas");

        printf("\n\t7 - Sair\n\t>>>>>> ");

        scanf("%d", &opcao);

        printf("\n");

        switch (opcao){

            case 1:
                cadastrarCliente(clientes, &qtd_clientes);
                break;
            
            case 2:
                cadastrarProduto(produtos, &qtd_produtos);
                break;

            case 3:
                consultarCliente(clientes, qtd_clientes);
                break;

            case 4:
                consultarProduto(produtos, qtd_produtos);
                break;
            case 5:
                break;
            case 6:
                consultarVenda(vendas, qtd_vendas);
                break;
            case 7:
                sair = 1;
                break;

            default:
                printf("\n\nOPCAO INVALIDA!");
        }

    } while ( sair != 1 );
//fim do codigo
    return 0;
}
