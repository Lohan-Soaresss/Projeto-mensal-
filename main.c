#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"portuguese"); // Colocando o texto com acentos

int opcao = 0, caixa_aberto = 0, produto_escolhido = 0, quantidade_item = 0, qtd_venda_atual = 0, qtd_total_geral = 0;
float p1 = 5.00, p2 = 3.50, p3 = 25.00, p4 = 3.50, p5 = 7.00, p6 = 12.00;
float total_venda_atual = 0, valor_abertura = 0, saldo_caixa = 0, valor_total_geral = 0;
// p1 = Arroz - p2 = Feij�o - p3 = Carne - p4 = Leite (professor disse que gosta de leite) - p5 = P�o de Leite - p6 = Refrigerante

// Inicio do programa
    do{
        printf("\n>>> SISTEMA CAIXA <<<\n");
        printf("1 - ABRIR CAIXA\n");
        printf("2 - COMECAR NOVA VENDA\n");
        printf("3 - FECHAR SISTEMA\n");
        printf("ESCOLHA: ");
        scanf("%d", &opcao);
// mostrando o sistema novamente para quando o caixa tentar ser aberto 2 vezes
        if(opcao == 2 && caixa_aberto==0){
            do{
                printf("\nCAIXA FECHADO.\nTENTE NOVAMENTE\n");
                printf("\n>>> SISTEMA CAIXA <<<\n");
                printf("1 - ABRIR CAIXA\n");
                printf("2 - COMECAR NOVA VENDA\n");
                printf("3 - FECHAR SISTEMA\n");
                printf("ESCOLHA: ");
                scanf("%d", &opcao);
            }while(opcao == 2 && caixa_aberto==0);
        }
        // Sistema da loja - soma de cadas itens e valores
        do{
        switch(opcao){
            case 1:
                if(caixa_aberto == 1){
                    printf("\nCAIXA JA ABERTO\nVALOR EM CAIXA: R$%.2f\n\n",valor_total_geral+valor_abertura);
                }else{
                    printf("\nDIGITE VALOR EM CAIXA: R$");
                    scanf("%f", &valor_abertura);
                    printf("VALOR EM CAIXA: R$%.2f\nCAIXA ABERTO COM SUCESSO\n",valor_abertura);
                    caixa_aberto = 1;
                    saldo_caixa = valor_abertura;
                }

            break;
            case 2:
                if(caixa_aberto == 1){
                    printf("\n--- PRODUTOS DISPONIVEIS ---\n\n");
                    printf("1 - ARROZ: R$%.2f\n", p1);
                    printf("2 - FEIJAO: R$%.2f\n", p2);
                    printf("3 - CARNE: R$%.2f\n", p3);
                    printf("4 - LEITE: R$%.2f\n", p4);
                    printf("5 - PAO: R$%.2f\n", p5);
                    printf("6 - REFRIGERANTE: R$%.2f\n", p6);
                    printf("0 - FINALIZAR ITENS DA VENDA\n");
                    printf("\nDIGITE O CODIGO DO PRODUTO: ");
                    scanf("%d", &produto_escolhido);

                    switch(produto_escolhido){
                        case 1:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p1;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 2:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p2;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 3:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p3;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 4:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p4;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 5:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p5;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 6:
                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &quantidade_item);
                            total_venda_atual = quantidade_item*p6;
                            printf("\nVALOR DA VENDA: R$%.2f\n",total_venda_atual);
                            valor_total_geral = valor_total_geral+total_venda_atual;
                            qtd_total_geral = qtd_total_geral+quantidade_item;
                        break;
                        case 0:
                            opcao = 0;
                            printf("\nFINALIZANDO A VENDA...\n");
                            printf("TOTAL DE ITENS: %d\n",qtd_total_geral);
                            printf("TOTAL DA VENDA: R$%.2f\n",valor_total_geral);
                        break;

                            default:
                                printf("VALOR INVALIDO.");
                    }
                }
            break;
        }

        }while(opcao == 2);

    }while(opcao != 3);
// Fechamento do sistema com todos os Itens e etc
    if(qtd_total_geral!=0){
        printf("\n\nTOTAL DE ITENS VENDIDO: %d\n", qtd_total_geral);
        printf("VALOR FATURADO: R$%.2f\n", valor_total_geral);
        printf("VALOR TOTAL EM CAIXA: R$%.2f\n",valor_total_geral+valor_abertura);
        printf("\n\n>>> FECHANDO SISTEMA <<<\n");
    }
// Fechamento do sistema caso nao tenha tido nenhuma venda
    else{
        printf("\n\nNENHUMA VENDA FEITA ");
        printf("\n\n>>> FECHANDO SISTEMA <<<\n");
        }

    return 0;
}
