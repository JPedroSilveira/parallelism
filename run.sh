#!/bin/bash

# Nome dos executáveis
EXECUTAVEL_ORIGINAL="./shsup"
EXECUTAVEL_PARALLEL="./shsupparallel"

# Valores para os quais você deseja executar o teste
VALORES=(50 100 500 1000)

for VALOR in "${VALORES[@]}"; do
    # Arquivo de entrada correspondente ao valor
    ARQUIVO_INPUT="./inputs/input-${VALOR}.txt"

    # Verifica se o arquivo de entrada existe
    if [ -e "$ARQUIVO_INPUT" ]; then
        # Executa o programa original e salva a análise no arquivo correspondente
        rm gmon.out
        $EXECUTAVEL_ORIGINAL < $ARQUIVO_INPUT
        gprof $EXECUTAVEL_ORIGINAL gmon.out > "./gprof/analise-original${VALOR}.txt"

        # Executa o programa paralelo e salva a análise no arquivo correspondente
        rm gmon.out
        $EXECUTAVEL_PARALLEL < $ARQUIVO_INPUT
        gprof $EXECUTAVEL_PARALLEL gmon.out > "./gprof/analise-parallel${VALOR}.txt"
    else
        echo "Arquivo de entrada '$ARQUIVO_INPUT' não encontrado."
    fi
done
