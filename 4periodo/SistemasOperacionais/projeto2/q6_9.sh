#!/bin/bash

# Verifica se o número de parâmetros é igual a 1
if [ "$#" -ne 1 ]; then
  echo "Não possui exclusivamente 1 paramêtro."
  exit 1
fi

# Verifica se o parâmetro é um diretório
if [[ -d "$1" ]]; then
  echo "$1 é um diretório válido."
else
  echo "$1 não é um diretório válido."
fi

# Exibe o parâmetro recebido
echo "Parâmetro recebido: $1"

echo "Pedro Maia, Bruno Secchin"
