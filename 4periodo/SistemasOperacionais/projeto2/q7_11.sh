#!/bin/bash

while true; do
  # Exibe o menu
  echo "Menu de Opções:"
  echo "1. Exibir status da utilização das partições do sistema"
  echo "2. Exibir relação de usuários logados"
  echo "3. Exibir data/hora"
  echo "4. Sair"
  echo -n "Escolha uma opção (1-4): "
  
  # Lê a opção digitada pelo usuário
  read opcao
  
  # Processa a opção usando case
  case "$opcao" in
    1)
		clear
      echo "Status da utilização das partições:"
      df -h
      ;;
    2)
		clear
      echo "Relação de usuários logados:"
      who
      ;;
    3)
	    clear
      echo "Data e hora atuais:"
      date
      ;;
    4)
      echo "Saindo..."
      break
      ;;
    *)
      echo "Opção inválida! Por favor, escolha uma opção entre 1 e 4."
      ;;
  esac
  
  echo # Linha em branco para separar as saídas
done

