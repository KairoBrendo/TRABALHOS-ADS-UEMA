#include <stdio.h>
#include <stdlib.h>

#define TAMCli 10
#define TAMProd 20
#define TAMvenda 20


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
    printf("\nNAO HA CLIENTES CADASTRADOS!\n");
    system("pause");
    return;
    }

    for(int i=0; i < qtd_clientes; i++) {

        printf("\nId do Cliente: %d",  c[i].id);

        printf("\nPrimeiro Nome: %s\n",  c[i].nome);

    }

    printf("\n");
    system("pause");

}

void consultarProduto (Produto p[], int qtd_produtos) {

    if (qtd_produtos == 0){
    printf("\nNAO HA PRODUTOS CADASTRADOS!\n");
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

    printf("\n");
    system("pause");

}
//FUNÇÃO DE VENDAS:
void realizarVenda (Cliente clientes[], int qtd_clientes, Produto produtos[], int qtd_produtos, Venda vendas[], int *qtd_vendas){
    int idCliente, idProduto, qtd_desejada;
    int clienteExistente = 0, produtoExistente = 0;
    int indiceCliente = -1, indiceProduto = -1; //inicia em -1 para indicar indice de array nao encontrado que inicia em (0)

    if (*qtd_vendas >= TAMvenda){
        printf("\nLIMITE DE VENDAS ATINGIDO!\n");
    return;
    }

    if (qtd_clientes == 0 || qtd_produtos == 0){
        printf("\nNAO HA CLIENTES OU PRODUTOS CADASTRADOS PARA REALIZAR A VENDA!\n");
    return;
    }

        printf("Informe o ID do cliente: ");
        scanf("%d", &idCliente);

    for (int i=0; i < qtd_clientes; i++){
        if (clientes[i].id == idCliente){
            clienteExistente = 1;
            indiceCliente = i;
            break;
        }  
    }
    if (clienteExistente == 0){
        printf("\nCLIENTE NAO ENCONTRADO!\n");
        return;
    }

        printf("Informe o ID do produto: ");
        scanf("%d", &idProduto);

    for (int i=0; i < qtd_produtos; i++){
        if (produtos[i].id == idProduto){
            produtoExistente = 1;
            indiceProduto = i;
            break;
        }  
    }
    if (produtoExistente == 0){
        printf("\nPRODUTO NAO ENCONTRADO!\n");
        return;
    }

        printf("Informe a quantidade desejada: ");
        scanf("%d", &qtd_desejada);

    if (qtd_desejada > produtos[indiceProduto].quantidade){
        printf("\nESTOQUE INDISPONIVEL!");
        printf("\n DISPONIVEL SOMENTE %d UNIDADES DESSE PRODUTO", produtos[indiceProduto].quantidade);
        return;
    }

    produtos[indiceProduto].quantidade = produtos[indiceProduto].quantidade - qtd_desejada;

    vendas[*qtd_vendas].idCliente = idCliente;
    vendas[*qtd_vendas].idProduto = idProduto;
    vendas[*qtd_vendas].quantProduto = qtd_desejada;
    vendas[*qtd_vendas].valorTotal = qtd_desejada * produtos[indiceProduto].valor;
    
    printf("\nVENDA EFETUADA COM SUCESSO!");
    printf("\nCliente: %s", clientes[indiceCliente].nome);
    printf("\nProduto: %s", produtos[indiceProduto].nome);
    printf("\nQuantidade: %d", qtd_desejada);
    printf("\nValor total: R$ %.2f\n", vendas[*qtd_vendas].valorTotal);

    *qtd_vendas = *qtd_vendas + 1;
}
    
    
    
    
    
//INICIO DO CODIGO PRINCIPAL
int main() {

    int opcao, sair=0; // sair inicialmente falso

    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda vendas [TAMvenda];

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

        printf("\n\t6 - Sair\n\t>>>>>> ");

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
                realizarVenda(clientes, qtd_clientes, produtos, qtd_produtos, vendas, &qtd_vendas);
                break;

            case 6:
                sair = 1;
                break;

            default:
                printf("\n\nOPCAO INVALIDA!");
        }

    } while ( sair != 1 );

    return 0;
}
