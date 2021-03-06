/**
 **
 **  @file   gera_instancias.c
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Implementações, fornecidas pelos alunos, das funções de geração de
 **  instâncias para os algoritmos de ordenação definidos no arquivo
 **  algoritmos.h.
 **
 **  @copyright
 **  Copyright (C) 2020 Universidade Federal do Ceará.
 **
 **  This source code is part of an educational project, associated with
 **  an undergraduate course or extension project, that is hosted at
 **  Universidade Federal do Ceará, Campus Quixadá.
 **
 **  This project is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This project is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with the source code of this project. If not, see
 **  <http://www.gnu.org/licenses/>.
 **
 **/

#include "../ordenacao/gera_instancias.h"

#include <stdlib.h>

void pior_caso_selection(int array[], size_t size, enum ordering order) {
    // TODO Implementação.
}

void pior_caso_insertion(int array[], size_t size, enum ordering order) {
    // TODO Implementação.
}

void pior_caso_bubble(int array[], size_t size, enum ordering order) {
    // TODO Implementação.
}

void instancia_quase_ordenada(int array[], size_t size, enum ordering order) {
    // NOTE Para construir instancias quase-ordenadas, siga o procedimento:
    //      1. Inicie de um vetor ordenado (segundo a ordem indicada) e calcule
    //         o valor de `repeticoes` como sendo 15% do tamanho do vetor.
    //      2. Repita o procedimento a seguir a quantidade de vezes calculada:
    //          2.1. Escolha dois índices `i` e `j` aleatoriamente.
    //          2.2. Troque os elementos `array[i]` e `array[j]`.

    // NOTE A inicialização do gerador de numeros aleatórios está feita na função
    //      main e não deve ser feita novamente.

    // TODO Implementação
}

void instancia_aleatoria(int array[], size_t size) {
    // NOTE Consulte esta página
    //          https://www.ime.usp.br/~pf/algoritmos/aulas/random.html
    //      para entender como gerar números aleatórios em C.

    // NOTE A inicialização do gerador está feita na função main e não deve ser feita
    //      novamente.

    // TODO Implementação
}