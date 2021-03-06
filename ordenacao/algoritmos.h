/**
 **
 **  @file   algoritmos.h
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Definição dos cabeçalhos para os algoritmos de ordenação que serão
 **  avaliados.
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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! IMPORTANTE
//!
//! - Não altere este arquivo.
//!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef QXD_QXCODE_ALGORITMOS_H
#define QXD_QXCODE_ALGORITMOS_H

#include <stdbool.h>
#include <stddef.h>

/**
 ** @brief Especifica as informações que devem ser reportadas ao final do processo de ordenação.
 **/
typedef struct {
    size_t input_size;        //< Tamanho da entrada ordenada.
    size_t comparisons_count; //< Número de comparações <em>entre elementos</em> realizadas.
    size_t swaps_count;       //< Número de trocas <em>entre elementos</em> realizadas.
} sorting_telemetry;

/**
 ** @brief Define a ordem usada nos algoritmos de ordenação.
 **/
enum ordering {
    ORDER_NONINCREASING, //< Ordem não-decrescente (menor para maior, com repetição)
    ORDER_NONDECREASING  //< Ordem não-crescente (maior para menor, com repetição)
};

/**
 ** @brief Ordena os primeiros @p size elementos do vetor @p array usando
 ** <em>ordenação por seleção</em> segundo a ordem especificada por @p order.
 ** 
 ** @param array    vetor a ser ordenado.
 ** @param size     quantidade de elementos a considerar em @p array.
 ** @param order    ordem em que os elementos de @p array devem ficar após ordenados.
 ** @return         informações sobre as operações realizadas durante a ordenação.
 **/
sorting_telemetry selection_sort(int array[], size_t size, enum ordering order);

/**
 ** @brief Ordena os primeiros @p size elementos do vetor @p array usando
 ** <em>ordenação por inserção</em> segundo a ordem especificada por @p order.
 ** 
 ** @param array    vetor a ser ordenado.
 ** @param size     quantidade de elementos a considerar em @p array.
 ** @param order    ordem em que os elementos de @p array devem ficar após ordenados.
 ** @return         informações sobre as operações realizadas durante a ordenação.
 **/
sorting_telemetry insertion_sort(int array[], size_t size, enum ordering order);

/**
 ** @brief Ordena os primeiros @p size elementos do vetor @p array usando
 ** <em>ordenação pelo borbulhamento</em> segundo a ordem especificada por @p order.
 ** 
 ** @param array    vetor a ser ordenado.
 ** @param size     quantidade de elementos a considerar em @p array.
 ** @param order    ordem em que os elementos de @p array devem ficar após ordenados.
 ** @return         informações sobre as operações realizadas durante a ordenação.
 **/
sorting_telemetry bubble_sort(int array[], size_t size, enum ordering order);

/**
 ** @brief Verifica se os primeiros @p size elementos do vetor @p array estão
 ** ordenados segundo a ordem @p order especificada.
 **
 ** @param array    vetor a verificar.
 ** @param size     quantidade de elementos a considerara em @p array.
 ** @param order    ordem a ser verificada.
 ** @return true    caso a ordem esteja estabelecida.
 ** @return false   caso exista algum elemento fora de ordem.
 **/
bool testa_ordenacao(int array[], size_t size, enum ordering order);

#endif