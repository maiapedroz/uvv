#!/bin/bash

# Verifica se foi passado um parâmetro
if [ "$#" -ne 1 ]; then
  echo "Erro: Você precisa fornecer um nome para a busca."
  echo "Uso: $0 <nome>"
  exit 1
fi

# Nome do arquivo de agenda
ARQUIVO_AGENDA="agenda"

# Verifica se o arquivo "agenda" existe
if [ ! -f "$ARQUIVO_AGENDA" ]; then
  echo "Erro: Arquivo '$ARQUIVO_AGENDA' não encontrado."
  exit 1
fi

# Busca o nome no arquivo
RESULTADO=$(grep -i "$1" "$ARQUIVO_AGENDA")

# Verifica se o nome foi encontrado
if [ -z "$RESULTADO" ]; then
  echo "Nenhuma entrada encontrada para o nome '$1'."
else
  echo "Resultados encontrados para '$1':"
  echo "$RESULTADO"
fi

