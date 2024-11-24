# ******************************************************************************
# Arquivo: Makefile
# Versão : 2.1
# Data   : 2024-10-20 16:17
# -------------------------
# Esta Makefile é um modelo para a compilação de programas C que utilizem uma
# das seguintes bibliotecas especialmente criadas para estudantes:
#
#     1) CSLIB: biblioteca criada por Eric S. Roberts, especialmente para o
#               estudo dos livros publicados por ele:
#               - The Art and Science of C: An Introduction to Computer Science
#               - Programming Abstractions in C
#
#     2) CS50 : biblioteca criada pelo staff da disciplina Harvard CS50, para
#               os alunos que estão cursando a disciplina homônima.
#
#     3) CSABRANTES : biblioteca criada pelo professor Abrantes Araújo Silva
#                     Filho, com alguns utilitários utilizados nas disciplinas
#                     que ministra de forma online ou presencial.
#
# Por: Abrantes Araújo Silva Filho (Computação Raiz):
#          www.computacaoraiz.com.br
#          www.youtube.com.br/computacaoraiz
#          github.com/computacaoraiz
#          twitter.com/ComputacaoRaiz
#          www.linkedin.com/company/computacaoraiz
#          www.abrantes.pro.br
#          github.com/abrantesasf
# 
# PRÉ-REQUISITOS:
# ---------------
# Obviamente, como esta Makefile depende das bibliotecas CSLIB e CS50, você
# precisa ter essas bibliotecas instaladas e acessíveis em seu sistema.
# Além disso é necessário ter o compilador GCC e a biblioteca GLIBC.
#
# Para informações sobre a instalação da CSLIB, consulte:
#     https://github.com/abrantesasf/the_art_and_science_of_c
#
# Para informações sobre a instalação da CS50, consulte:
#     https://github.com/cs50/libcs50
#
# CONFIGURAÇÃO:
# -------------
# Informe o diretório de instalação da CSLIB em seu sistema, através da variável
# "DIRETORIO", abaixo. Por padrão esta variável aponta para /opt/cslib, mas você
# deve indicar o local exato em seu sistema.
#
# MODO DE USO:
# ------------
#     1) Acrescente o nome do target na variável PROGRAMAS. Idealmente o nome
#        do target deve ser o nome do arquivo que será criado pelo target (você
#        pode apagar os targets "ola" e "ola2" de exemplo), pois isso fará com
#        que os targets de limpeza apagem esses arquivos.
#
#     2) Crie a regra do target na seção de regras individuais de compilação.
#
#     3) Para executar a compilação, apenas digite "make <target>". Por padrão
#        a compilação é feita em "MODO=debug", ou seja, sem nenhuma otimização
#        habilitada e com a inclusão de símbolos para o GDB. Se você quiser
#        compilar para produção (sem os símbolos de debug) e com otimização
#        habilitada, faça: "make MODO=producao <target>".
#
#     4) Para limpar arquivos temporário faça "make limpar", e para limpar os
#        arquivos temporários e também os binários (os targets), faça
#        "make apagar".
# ******************************************************************************


# ******************************************************************************
# Configuração inicial da Makefile:

# Ajuste a variável DIRETORIO para o diretório de instalação da CSLIB.
# Acrescente outros diretórios para header files e arquivos conforme necessidade.
DIRETORIO = /home/cslib
DIRUTIL = /usr/lib

# As variáveis abaixo estão OK (NÃO ALTERE!):
CC = gcc

CSLIB = -lcslib
CS50 = -lcs50
#ABRANTES = -labrantes

CFLAGS = -L$(DIRETORIO) -L$(DIRUTIL) -I$(DIRETORIO) -I$(DIRUTIL) -std=c17 -Wall -Wextra -Werror -Wpedantic
MODO = debug
ifeq ($(MODO), debug)
    CFLAGS += -ggdb -O0 -Ddebug
else ifeq ($(MODO), producao)
    CFLAGS += -O2
endif

LFLAGS = $(CSLIB) $(CS50) -lm -lX11 -lcrypt -ledit
BIBS = dinamicas
ifeq ($(BIBS), estaticas)
    LFLAGS += -static
endif


# ******************************************************************************
# Programas a serem compilados (pode ser tudo em uma única linha, mas colocar um
# nome por linha facilita a exclusão e a visualização):
PROGRAMAS = \
	    lcdebuff.o \
	    meu_editor_lcdebuff

# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
lcdebuff.o: buffer.h lcdebuff.c
	$(CC) $(CFLAGS) -c -o lcdebuff.o lcdebuff.c $(LFLAGS)

meu_editor_lcdebuff: meu_editor.c buffer.h lcdebuff.o
	$(CC) $(CFLAGS) -o meu_editor_lsebuff meu_editor.c lcdebuff.o $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)

