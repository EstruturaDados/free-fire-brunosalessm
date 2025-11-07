
// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.


// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.


#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_NOME 50
#define TAM_TIPO 30

// Estrutura que representa um item
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS]; // vetor estático
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=== MENU DA MOCHILA ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // consome '\n'

        switch (opcao) {
            case 1: { // Adicionar item
                if (totalItens >= MAX_ITENS) {
                    printf("⚠️  Mochila cheia! Não é possível adicionar mais itens.\n");
                    break;
                }

                printf("\n--- Adicionar Item ---\n");
                printf("Nome: ");
                fgets(mochila[totalItens].nome, TAM_NOME, stdin);
                mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

                printf("Tipo: ");
                fgets(mochila[totalItens].tipo, TAM_TIPO, stdin);
                mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &mochila[totalItens].quantidade);
                getchar();

                totalItens++;
                printf("✅ Item adicionado com sucesso!\n");
                break;
            }

            case 2: { // Remover item
                if (totalItens == 0) {
                    printf("⚠️  Mochila vazia! Nada para remover.\n");
                    break;
                }

                char nomeRemover[TAM_NOME];
                printf("\n--- Remover Item ---\n");
                printf("Digite o nome do item que deseja remover: ");
                fgets(nomeRemover, TAM_NOME, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                int encontrado = 0;
                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        encontrado = 1;
                        // Move os itens seguintes uma posição para trás
                        for (int j = i; j < totalItens - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        totalItens--;
                        printf("🗑️  Item removido com sucesso!\n");
                        break;
                    }
                }
                if (!encontrado) {
                    printf("❌ Item não encontrado na mochila.\n");
                }
                break;
            }

            case 3: { // Listar itens
                if (totalItens == 0) {
                    printf("📦 Mochila vazia!\n");
                } else {
                    printf("\n--- Itens na Mochila ---\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("---------------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;
            }

            case 0:
                printf("👋 Encerrando o programa.\n");
                break;

            default:
                printf("⚠️  Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

