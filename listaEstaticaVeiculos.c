#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

typedef struct valores{
    char nome[15]; 
    int ano;
    float consumo;
} tValor;

typedef struct carros{
    int contador;
    tValor valores[TAM];    
} tCarro;

void cabecalho(){
    for (int i = 0; i < 60; i++) printf("-");
    printf("\n\n\tGerenciamento de veiculos - Lista Estatica\n\n");
    for (int i = 0; i < 60; i++) printf("-");
}

void criaLista(tCarro *carro){
    carro->contador = -1;
}

int inserirVeiculo(tCarro *p){
    int aux;
    do
    {
        if (p->contador < TAM -1) {
            (p->contador)++;
            system("clear");
            printf("\t######### Inserindo veiculos ##########\n\n");
            printf("Informe o nome do carro: ");
            scanf(" %[^\n]", p->valores[p->contador].nome);
            printf("Informe o ano do carro: ");
            scanf("%d", &p->valores[p->contador].ano);
            printf("Informe o consumo do veiculo (km/lt): ");
            scanf("%f", &p->valores[p->contador].consumo);
            printf("\n--> Veiculo adicionado com sucesso na posição [%d]\n\n", p->contador + 1);
            printf("Deseja continuar inserindo outro veiculo? (1-sim / 0-não): ");
            scanf("%d", &aux);
            printf("\n");
        } else {
            return -1;
        }
    } while (aux == 1);
return 0;
}

int mostrarVeiculos(tCarro p){
    if (p.contador == -1) {
        return -1;
    } else {
        system("clear");
        printf("\nOs veiculos adicionados sao: \n");
        for (int i = 0; i <= p.contador; i++){
            printf("\nPosição [%d]\n\tNome: %s\n\tAno: %d\n\tConsumo (em litros): %.2f\n", i + 1, p.valores[i].nome, p.valores[i].ano, p.valores[i].consumo);
        }
    }
return 0;
}

int removeVeiculo(tCarro *p, int aux){
    if ((p->contador == -1) || (aux <= 0) || (aux > p->contador + 1)){
        return -1;
    } else {
        for (int i = aux - 1; i < p->contador; i++) {
            strcpy(p->valores[i].nome, p->valores[i+1].nome);
            p->valores[i].ano = p->valores[i+1].ano;
            p->valores[i].consumo = p->valores[i+1].consumo;
        }
        (p->contador)--;
    }
return 0;
}

int inserePosicao(tCarro *p, int aux){
    if ((p->contador == -1) || (aux <= 0) || (aux > p->contador + 1)){
        return -1;
    } else {
        for (int i = p->contador; i >= aux - 1; i--){
            strcpy(p->valores[i+1].nome, p->valores[i].nome);
            p->valores[i+1].ano = p->valores[i].ano;
            p->valores[i+1].consumo = p->valores[i].consumo;
        }
        printf("\nDigite as informações do veiculo para colocar na posição %d\n", aux);
        printf("\tDigite o nome do veiculo: ");
        scanf(" %[^\n]", p->valores[aux - 1].nome);
        printf("\tDigite o ano: ");
        scanf("%d", &p->valores[aux - 1].ano);
        printf("\tDigite o consumo: ");
        scanf("%f", &p->valores[aux - 1].consumo);
    }
    (p->contador++);
    printf("\nDeseja ver a lista de veiculos? (1-sim / 0-nao): ");
    scanf("%d", &aux);
    if (aux == 1) {
        mostrarVeiculos(*p);
    } else {
        printf("\nVeiculo adicionado com sucesso!\n");
        return 0;
    }
    
return 0;
}

void posicoesLivre(tCarro p){
    int aux = (TAM - p.contador) - 1;
    printf("\n--> Voce possui %d posiçoes para guardar as informaçoes dos veiculos\n\n", aux);
}

int insereInicio(tCarro *p){
    if (p->contador == TAM - 1) {
        return -1;
    } else {
        for (int i = p->contador; i >= 0; i--) {
            strcpy(p->valores[i+1].nome, p->valores[i].nome);
            p->valores[i+1].ano = p->valores[i].ano;
            p->valores[i+1].consumo = p->valores[i].consumo;
        }
        printf("Informa os dados do veiculos para colocar na 1ª posição: \n");
        printf("\tDigite o nome do veiculo: ");
        scanf(" %[^\n]", p->valores[0].nome);
        printf("\tDigite o ano: ");
        scanf("%d", &p->valores[0].ano);
        printf("\tDigite o consumo: ");
        scanf("%f", &p->valores[0].consumo);
        (p->contador)++;
        return 0;
    }
}

int gravarVeiculos(tCarro *p){
    int aux;
    char nomeArq[10];
    if (p->contador == -1) {
        return -1;
    } else {
        printf("\nDeseja informar o nome do arquivo? (1-sim / 0-não): ");
        scanf("%d", &aux);
        if (aux == 1) {
            printf("\nDigite o nome do arquivo que deseja salvar: "); scanf(" %[^\n]", nomeArq);
            FILE *arq = fopen(nomeArq,"w");
            fprintf(arq, "--> Relação de veiculos salvos: \n");
            for (int i = 0; i < p->contador + 1; i++) {
                fprintf(arq, "\nPosição[%d]: \n", i+1);
                fprintf(arq, "\tNome: %s\n", p->valores[i].nome);
                fprintf(arq, "\tAno: %d\n", p->valores[i].ano);
                fprintf(arq, "\tConsumo: %.2f\n", p->valores[i].consumo);
            }
            fclose(arq);
        } else {
            FILE *arq = fopen("Veiculos.txt","w");
            fprintf(arq, "--> Relação de veiculos salvos: \n");
            for (int i = 0; i < p->contador + 1; i++) {
                fprintf(arq, "\nPosição[%d]: \n", i+1);
                fprintf(arq, "\tNome: %s\n", p->valores[i].nome);
                fprintf(arq, "\tAno: %d\n", p->valores[i].ano);
                fprintf(arq, "\tConsumo: %.2f\n", p->valores[i].consumo);
            }
            fclose(arq);
        }
    }
    return 0;
}

int main(){
    int aux, valida;
    tCarro carro;

    system("clear");
    criaLista(&carro);
    do
    {   
        //system("clear");
        cabecalho();
        printf("\nOpções: \n\n\t1 - Incluir veiculo.\n\t2 - Mostrar relação de veiculos\n\t3 - Remover veiculos\n\t4 - Adicionar veiculo numa posição especifica\n\t5 - Incluir veiculo no inicio da lista\n\t6 - Gravar as informações num arquivo de texto\n\t7 - Desenvolvimento...\n\t8 - Consultar posições disponiveis\n\t9 - Sair\n\nDigite a opção desejada: ");
        scanf("%d", &aux);
        printf("\n");
        switch (aux) {
        case 1:
            system("clear");
            valida = inserirVeiculo(&carro);
            if (valida == -1)
                printf("\t--> A fila esta cheia. Nao pode inserir carro no momento!\n\n");     
            break;
        case 2:
            system("clear");
            valida = mostrarVeiculos(carro);
            if(valida == -1){
                printf("\n--> A lista esta vazia!\n\n");
                
            }
            break;
        case 3:
            system("clear");
            printf("Para remover um veiculo, informe sua posição (Opção 2): "); scanf("%d", &aux);
            valida = removeVeiculo(&carro, aux);
            if (valida == -1) {
                printf("\n--> Posição invalida, informa uma posição correta\n\n");
            } else {
                printf("\n--> Veiculo removido com sucesso!\n\n");
            }
            break;
        case 4:
            system("clear");
            printf("Escolha a posição que deseja incluir um novo veiculo. Deseja ver a relação de veiculos? (1-sim / 0-nao): "); scanf("%d", &aux);
            system("clear");
            if (aux == 1) {
                valida = mostrarVeiculos(carro);
                if (valida == -1) {
                    printf("\n--> A lista esta vazia.\n\n"); break;
                }
            } else {
                printf("\nDigite o numero da posição para incluir outro veiculo: "); scanf("%d", &aux);
                valida = inserePosicao(&carro, aux);
                if (valida == -1)
                {
                    printf("\n--> Posição invalida\n\n");
                }
            }
            break;
        case 5:
            system("clear");
            valida = insereInicio(&carro);
            if (valida == -1) {
                printf("\n--> A lista esta cheia, impossivel incluir um novo veiculo, caso necessario retire algum utilizando a opção 3\n");
            } else {
                printf("\n--> Veiculo adicionado com sucesso na 1ª posição\n\n");
            }
            
            break;
        case 6:
            system("clear");
            valida = gravarVeiculos(&carro);
            if (valida == -1)
            {
                printf("\n--> A lista esta vazia!\n");
            } else {
                printf("\n--> Lista gerada com sucesso!\n");
            }
            
            break;
        case 8:
            system("clear");
            posicoesLivre(carro);
            break;
        case 9: exit (-1); break;
        default: printf("Opção invalida\n"); exit (0); break;
        }
    } while (aux != 0);
    return 0;
}