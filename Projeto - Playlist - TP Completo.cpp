#include <stdio.h>     // Biblioteca padrão para entrada/saída
#include <stdlib.h>    // Para funções auxiliares
#include <string.h>    // Para manipulação de strings

#define MAX_GENEROS 6
#define MAX_MUSICAS 100

// Define a estrutura para representar uma música
typedef struct {
    char nome[100];
    char genero[50];
    int duracao; // Em segundos
} Musica;

// Função que troca duas músicas de lugar (usada na ordenação)
void swap(Musica *a, Musica *b) {
    Musica temp = *a;
    *a = *b;
    *b = temp;
}

// Ordena a playlist por nome (Bubble Sort)
void sort_playlist(Musica musicas[], int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (strcmp(musicas[j].nome, musicas[j + 1].nome) > 0) {
                swap(&musicas[j], &musicas[j + 1]);
            }
        }
    }
}

// Salva as músicas no arquivo "playlist.txt"
void salvar_musicas(Musica musicas[], int quantidade) {
    FILE *arquivo = fopen("playlist.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s;%s;%d\n", musicas[i].nome, musicas[i].genero, musicas[i].duracao);
    }

    fclose(arquivo);
}

// Carrega músicas do arquivo "playlist.txt"
int carregar_musicas(Musica musicas[]) {
    FILE *arquivo = fopen("playlist.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de playlist não encontrado. Usando músicas padrão.\n");
        return 10; // Se não encontrar, retorna 10 para manter padrão
    }

    int i = 0;
    while (fscanf(arquivo, " %99[^;];%49[^;];%d\n", musicas[i].nome, musicas[i].genero, &musicas[i].duracao) == 3) {
        i++;
    }

    fclose(arquivo);
    return i; // Retorna número de músicas lidas
}

int main() {
    Musica musicas[MAX_MUSICAS]; // Vetor de músicas
    int quantidade;              // Quantidade atual de músicas
    int opcao, i, j;

    // Gêneros disponíveis
    char generos_preestabelecidos[MAX_GENEROS][50] = {
        "Eletronica", "Funk", "Rock", "Jazz", "Pop", "Hip-Hop"
    };

    // Preenche músicas padrão (serão usadas se não houver arquivo)
    strcpy(musicas[0].nome, "Bohemian Rhapsody"); strcpy(musicas[0].genero, "Rock"); musicas[0].duracao = 355;
    strcpy(musicas[1].nome, "Billie Jean"); strcpy(musicas[1].genero, "Pop"); musicas[1].duracao = 294;
    strcpy(musicas[2].nome, "Smells Like Teen Spirit"); strcpy(musicas[2].genero, "Rock"); musicas[2].duracao = 301;
    strcpy(musicas[3].nome, "Midnight City"); strcpy(musicas[3].genero, "Eletronica"); musicas[3].duracao = 241;
    strcpy(musicas[4].nome, "Lose Yourself"); strcpy(musicas[4].genero, "Hip-Hop"); musicas[4].duracao = 326;
    strcpy(musicas[5].nome, "So What"); strcpy(musicas[5].genero, "Jazz"); musicas[5].duracao = 563;
    strcpy(musicas[6].nome, "Uptown Funk"); strcpy(musicas[6].genero, "Funk"); musicas[6].duracao = 270;
    strcpy(musicas[7].nome, "Blinding Lights"); strcpy(musicas[7].genero, "Pop"); musicas[7].duracao = 200;
    strcpy(musicas[8].nome, "Get Lucky"); strcpy(musicas[8].genero, "Funk"); musicas[8].duracao = 369;
    strcpy(musicas[9].nome, "Rapper's Delight"); strcpy(musicas[9].genero, "Hip-Hop"); musicas[9].duracao = 430;

    // Tenta carregar do arquivo
    quantidade = carregar_musicas(musicas);

    do {
        printf("\n----- Menu -----\n");
        printf("1. Adicionar musica\n");
        printf("2. Listar musicas\n");
        printf("3. Montar playlist por tempo maximo\n");
        printf("4. Montar playlist por genero\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (quantidade >= MAX_MUSICAS) {
                printf("Playlist cheia!\n");
            } else {
                char nome_temp[100];
                printf("Digite o nome da musica: ");
                scanf(" %[^\n]s", nome_temp);

                // Verifica se a música já existe (case-insensitive)
                int repetida = 0;
                for (i = 0; i < quantidade; i++) {
                    if (strcasecmp(musicas[i].nome, nome_temp) == 0) {
                        repetida = 1;
                        break;
                    }
                }

                if (repetida) {
                    printf("Musica ja adicionada!\n");
                } else {
                    strcpy(musicas[quantidade].nome, nome_temp);

                    printf("Escolha o genero:\n");
                    for (i = 0; i < MAX_GENEROS; i++) {
                        printf("%d. %s\n", i + 1, generos_preestabelecidos[i]);
                    }
                    int genero_opcao;
                    printf("Opcao de genero (1-%d): ", MAX_GENEROS);
                    scanf("%d", &genero_opcao);

                    if (genero_opcao >= 1 && genero_opcao <= MAX_GENEROS) {
                        strcpy(musicas[quantidade].genero, generos_preestabelecidos[genero_opcao - 1]);
                    } else {
                        strcpy(musicas[quantidade].genero, "Indefinido");
                    }

                    printf("Digite a duracao (em minutos): ");
                    int duracao_minutos;
                    scanf("%d", &duracao_minutos);
                    musicas[quantidade].duracao = duracao_minutos * 60;

                    quantidade++;
                    salvar_musicas(musicas, quantidade);
                    printf("Musica adicionada com sucesso!\n");
                }
            }

        } else if (opcao == 2) {
            if (quantidade == 0) {
                printf("Playlist vazia.\n");
            } else {
                sort_playlist(musicas, quantidade);
                printf("\n--- Playlist ---\n");
                for (i = 0; i < quantidade; i++) {
                    printf("Musica %d:\n", i + 1);
                    printf("Nome: %s\n", musicas[i].nome);
                    printf("Genero: %s\n", musicas[i].genero);
                    printf("Duracao: %d minutos\n\n", musicas[i].duracao / 60);
                }
            }

        } else if (opcao == 3) {
            int tempo_maximo;
            printf("Tempo maximo (em minutos): ");
            scanf("%d", &tempo_maximo);
            tempo_maximo *= 60;

            sort_playlist(musicas, quantidade);

            int tempo_total = 0;
            printf("\n--- Playlist por Tempo ---\n");
            for (i = 0; i < quantidade; i++) {
                if (tempo_total + musicas[i].duracao <= tempo_maximo) {
                    printf("Nome: %s\nGenero: %s\nDuracao: %d minutos\n\n",
                           musicas[i].nome, musicas[i].genero, musicas[i].duracao / 60);
                    tempo_total += musicas[i].duracao;
                }
            }
            printf("Tempo total: %d minutos\n", tempo_total / 60);

        } else if (opcao == 4) {
            int generos_escolhidos[MAX_GENEROS] = {0};
            int genero_opcao;

            printf("Escolha os generos (0 para terminar):\n");
            for (i = 0; i < MAX_GENEROS; i++) {
                printf("%d. %s\n", i + 1, generos_preestabelecidos[i]);
            }

            while (1) {
                printf("Genero (1-%d ou 0): ", MAX_GENEROS);
                scanf("%d", &genero_opcao);
                if (genero_opcao == 0) break;
                if (genero_opcao >= 1 && genero_opcao <= MAX_GENEROS) {
                    generos_escolhidos[genero_opcao - 1] = 1;
                }
            }

            sort_playlist(musicas, quantidade);

            int tempo_total = 0;
            printf("\n--- Playlist por Genero ---\n");
            for (i = 0; i < quantidade; i++) {
                for (j = 0; j < MAX_GENEROS; j++) {
                    if (generos_escolhidos[j] == 1 &&
                        strcmp(musicas[i].genero, generos_preestabelecidos[j]) == 0) {
                        printf("Nome: %s\nGenero: %s\nDuracao: %d minutos\n\n",
                               musicas[i].nome, musicas[i].genero, musicas[i].duracao / 60);
                        tempo_total += musicas[i].duracao;
                        break;
                    }
                }
            }
            printf("Tempo total: %d minutos\n", tempo_total / 60);

        } else if (opcao == 5) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
