# Atividade 6.4 – Usando testes dentro dos scripts
# Crie um script que mostra qual é o usuário atual, qual o diretório atual e o Shell que está usando.
# Uma dica é lembrar que no arquivo /etc/passwd encontram-se listados os usuários e seus shells.
# Use o comando cut com a sintaxe:
# cut -d DELIMITADOR -f NUMERO_DO_CAMPO
# O comando cut corta somente o(s) campo(s) de número NUMERO_DO_CAMPO e utiliza o sepa-
# rador DELIMITADOR para delimitar cada campo. No caso do arquivo passwd, o delimitador é “:”.

#!/bin/bash

# Mostra o usuário atual
USUARIO=$(whoami)

# Mostra o diretório atual
DIRETORIO_ATUAL=$(pwd)

# Mostra o Shell atual
SHELL_ATUAL=$(grep "^$USUARIO:" /etc/passwd | cut -d ':' -f 7)

# Exibe as informações
echo "Usuário atual: $USUARIO"
echo "Diretório atual: $DIRETORIO_ATUAL"
echo "Shell atual: $SHELL_ATUAL"

