#!/bin/bash

# Verifica se dois parâmetros foram passados
if [ "$#" -ne 2 ]; then
  echo "Erro: Você precisa fornecer duas palavras."
  echo "Uso: $0 <palavra1> <palavra2>"
  exit 1
fi

# Verifica se a primeira palavra está contida na segunda
if [[ "$2" == *"$1"* ]]; then
  echo "A palavra '$1' está contida em '$2'."
else
  echo "A palavra '$1' não está contida em '$2'."
fi

