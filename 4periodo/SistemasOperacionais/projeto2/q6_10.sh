#!/bin/bash

# Verifica se o número de parâmetros é igual a 2
if [ "$#" -ne 2 ]; then
  echo "Erro: Número de parâmetros incorreto."
  echo "Uso: $0 <diretório> <letra>"
  exit 1
fi

# Verifica se o primeiro parâmetro é um diretório
if [[ -d "$1" ]]; then
  echo "Listando arquivos no diretório $1 que começam com '$2':"
  # Lista os arquivos que começam com a letra fornecida no diretório especificado
  ls "$1"/"$2"* 2>/dev/null
  # Se não houver arquivos correspondentes, o comando acima não mostrará nada
else
  echo "$1 não é um diretório válido."
  exit 1
fi

