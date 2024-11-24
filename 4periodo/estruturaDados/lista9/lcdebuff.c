#include "buffer.h"
#include "genlib.h"
#include <stdio.h>
#include <stdlib.h>

// Definição dos tipos de dados
typedef struct celulaTCD {
    char letra;
    struct celulaTCD *proximo;
    struct celulaTCD *anterior;
} celulaTCD;

typedef struct bufferTCD {
    celulaTCD *inicio; // Ponteiro para a célula dummy
    celulaTCD *cursor; // Ponteiro para a posição do cursor
} bufferTCD;

// Função auxiliar para criar uma célula
static celulaTCD *criar_celula(void) {
    celulaTCD *nova_celula = calloc(1, sizeof(celulaTCD));
    if (nova_celula == NULL) {
        fprintf(stderr, "Erro: impossível criar célula.\n");
        exit(1);
    }
    return nova_celula;
}

// Função auxiliar para remover uma célula
static void remover_celula(celulaTCD *celula) {
    if (celula != NULL) {
        free(celula);
    }
}

// Função: criar_buffer
bufferTAD criar_buffer(void) {
    bufferTCD *buffer = calloc(1, sizeof(bufferTCD));
    if (buffer == NULL) {
        fprintf(stderr, "Erro: impossível alocar buffer.\n");
        exit(1);
    }

    // Criar célula dummy
    celulaTCD *dummy = criar_celula();
    dummy->proximo = dummy->anterior = dummy;

    buffer->inicio = dummy;
    buffer->cursor = dummy;

    return buffer;
}

// Procedimento: liberar_buffer
void liberar_buffer(bufferTAD *buffer) {
    if (buffer == NULL || *buffer == NULL) return;

    celulaTCD *atual = (*buffer)->inicio->proximo;
    while (atual != (*buffer)->inicio) {
        celulaTCD *proxima = atual->proximo;
        remover_celula(atual);
        atual = proxima;
    }

    remover_celula((*buffer)->inicio);
    free(*buffer);
    *buffer = NULL;
}

// Procedimento: mover_cursor_para_frente
void mover_cursor_para_frente(bufferTAD buffer) {
    if (buffer->cursor->proximo != buffer->inicio) {
        buffer->cursor = buffer->cursor->proximo;
    }
}

// Procedimento: mover_cursor_para_tras
void mover_cursor_para_tras(bufferTAD buffer) {
    if (buffer->cursor != buffer->inicio) {
        buffer->cursor = buffer->cursor->anterior;
    }
}

// Procedimento: mover_cursor_para_inicio
void mover_cursor_para_inicio(bufferTAD buffer) {
    buffer->cursor = buffer->inicio->proximo;
}

// Procedimento: mover_cursor_para_final
void mover_cursor_para_final(bufferTAD buffer) {
    buffer->cursor = buffer->inicio->anterior;
}

// Procedimento: inserir_caractere
void inserir_caractere(bufferTAD buffer, char c) {
    celulaTCD *nova_celula = criar_celula();
    nova_celula->letra = c;

    nova_celula->proximo = buffer->cursor->proximo;
    nova_celula->anterior = buffer->cursor;

    buffer->cursor->proximo->anterior = nova_celula;
    buffer->cursor->proximo = nova_celula;

    buffer->cursor = nova_celula;
}

// Procedimento: apagar_caractere
void apagar_caractere(bufferTAD buffer) {
    if (buffer->cursor->proximo == buffer->inicio) return;

    celulaTCD *remover = buffer->cursor->proximo;

    buffer->cursor->proximo = remover->proximo;
    remover->proximo->anterior = buffer->cursor;

    remover_celula(remover);
}

// Procedimento: exibir_buffer
void exibir_buffer(bufferTAD buffer) {
    celulaTCD *atual = buffer->inicio->proximo;
    while (atual != buffer->inicio) {
        putchar(atual->letra);
        atual = atual->proximo;
    }
    putchar('\n');

    atual = buffer->inicio->proximo;
    while (atual != buffer->cursor->proximo) {
        putchar(' ');
        atual = atual->proximo;
    }
    putchar('^');
    putchar('\n');
}

