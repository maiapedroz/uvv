#!/bin/bash

# Verifica se foi passado o nome de um arquivo
if [ "$#" -ne 1 ]; then
  echo "Erro: Você precisa fornecer o nome de um arquivo."
  echo "Uso: $0 <arquivo>"
  exit 1
fi

# Verifica se o arquivo existe
if [ ! -f "$1" ]; then
  echo "Erro: Arquivo '$1' não encontrado."
  exit 1
fi

# Verifica se o usuário tem permissão de leitura
if [ ! -r "$1" ]; then
  echo "Erro: Você não tem permissão de leitura no arquivo '$1'."
  exit 1
fi

# Exibe as informações do arquivo
echo "Informações sobre o arquivo '$1':"
echo "Número de caracteres: $(wc -c < "$1")"
echo "Número de palavras: $(wc -w < "$1")"
echo "Número de linhas: $(wc -l < "$1")"

