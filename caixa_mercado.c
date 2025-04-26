#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX1 10
#define MAX2 100
#define USER "admin"
#define PASS "1234"

void ENTER() {
    printf("Pressione ENTER para continuar...");
    getchar();
}

void sucesso() {
    system("clear");
    printf("Produto cadastrado com sucesso!\n\n");
    ENTER();
}

int autenticar() {
    char usuario[50], senha[50];
    int tentativas = 3;

    while (tentativas > 0) {
        system("clear");
        printf("=============================\n");
        printf("            LOGIN            \n");
        printf("=============================\n");
        printf("Usuario: ");
        fgets(usuario, sizeof(usuario), stdin);
        usuario[strcspn(usuario, "\n")] = '\0';

        printf("Senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = '\0';

        if (strcmp(usuario, USER) == 0 && strcmp(senha, PASS) == 0) {
            return 1; // Login bem-sucedido
        } else {
            system("clear");
            printf("\nLogin ou senha incorretos. Tentativas restantes: %d\n\n", tentativas - 1);
            ENTER();
            tentativas--;
        }
    }

    return 0; // Falha no login
}

int main() {
    int quantidade, codigo, enter, i = 0, k = 0;
    char escolha = 'S', produto[MAX1][MAX2];
    float mult, pago, soma = 0, valor[MAX1][MAX2];

    if (!autenticar()) {
        system("clear");
        printf("Numero de tentativas esgotado. Saindo do programa...\n");
        sleep(2);
        return 0;
    }
    
    system("clear");
    printf("=============================\n");
    printf("   BEM-VINDO(A) AO SISTEMA   \n");
    printf("=============================\n\n");
    ENTER();

    while (1) {
        system("clear");
        printf("[1] Passar compras\n");
        printf("[2] Cadastrar produto\n");
        printf("[3] Lista de produtos cadastrados\n");
        printf("[4] Remover produto\n");
        printf("[5] Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &enter); 
        getchar();
    switch (enter) {
        case 1:
            if (i != 0) {
                while ((escolha != 'N') && (escolha != 'n')) {
                    system("clear");
                    if ((escolha == 'S') || (escolha == 's')) {
                        printf("Digite o codigo do produto: ");
                        scanf("%d", &codigo);
                        printf("Quantidade: ");
                        scanf("%d", &quantidade);
                        getchar();
                        system("clear");
                        
                        if ((codigo <= i) && (codigo > 0)) {
                            mult = valor[codigo - 1][codigo - 1] * quantidade;
                            soma += mult;
                            printf("%dx %s adicionado com sucesso!\n\n", quantidade, produto[codigo - 1]);
                            printf("Gostaria de passar outro produto? [S/N]: ");
                            scanf(" %c", &escolha);
                            getchar();
                        } else {
                            system("clear");
                            printf("Produto invalido\n\n");
                            ENTER();
                        }
                    } else {
                        system("clear");
                        printf("Digite um valor valido\n\n");
                        ENTER();
                        escolha = 'S';
                    }
                }
        } else {
            system("clear");
            printf("Nenhum produto cadastrado!\n\n");
            ENTER();
        }
        while (soma > 0) {
            system("clear");
            printf("Total a pagar: RS%.2f\n", soma);
            printf("Valor pago: RS");
            scanf("%f", &pago);
            getchar();
            if (soma > pago) {
                soma -= pago;
            } else {
                float troco = pago - soma;
                soma = 0;
                system("clear");
                printf("Troco: RS%.2f\n\n", troco);
                ENTER();
            }
        }

        escolha = 'S';
        soma = 0.0;
        break;

        case 2:
            system("clear");
            printf("Digite o nome do produto: ");
            fgets(produto[i], sizeof(produto[i]), stdin);
            produto[i][strcspn(produto[i], "\n")] = '\0';

            printf("Digite o valor do produto: RS");
            scanf("%f", &valor[i][k]);
            ++i, ++k;
            getchar();
            sucesso();
            break;

        case 3:
            system("clear");
            if (i == 0) {
                printf("Nenhum produto cadastrado\n\n");
                ENTER();
            } else {
                for (int j = 1; j < i + 1; ++j) {
                    printf("Nome: %s\n", produto[j - 1]);
                    printf("Valor: RS%.2f\n", valor[j - 1][j - 1]);
                    printf("Codigo: [%d]\n\n", j);
                }
                ENTER();
            }
            break;

        case 4:
            if (i != 0) {
                while(1) {
                    system("clear");
                    printf("Digite o codigo do produto (999 para cancelar): ");
                    scanf("%d", &codigo);
                    getchar();

                    if (codigo == 999){
                        break;
                    } else if ((codigo < i) && (codigo > 0)) {
                        for (int j = codigo; j < i; ++j) {
                            strcpy(produto[j - 1], produto[j]);
                            valor[j - 1][j - 1] = valor[j][j];
                            system("clear");
                            printf("Produto removido com sucesso!\n\n");
                            ENTER();
                        }
                        --i;
                        break;
                    } else if (codigo == i) {
                        memset(produto[i - 1], 0, sizeof(produto[i - 1]));
                        memset(valor[i - 1], 0, sizeof(valor[i - 1][i - 1]));
                        --i;
                        ENTER();
                        break;
                    } else {
                        system("clear");
                        printf("Produto invalido\n\n");
                        ENTER();
                    }
                }
            } else {
                system("clear");
                printf("Nenhum produto cadastrado!\n\n");
                ENTER();
            }

            break;

        case 5:
            system("clear");
            printf("Obrigado por usar o sistema!\n\n");
            ENTER();
            return 0;
            break;

        default:
            system("clear");
            printf("Digite um valor valido\n\n");
            ENTER();
    }

    }

    return 0;
}   