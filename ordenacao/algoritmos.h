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
 ** @brief Ordena o vetor @p array usando <em>ordenação por seleção</em>, segundo a ordem especificada por @p order.
 **
 ** @param array    Vetor a ser ordenado.
 ** @param size     Número de elementos no vetor.
 ** @param order    Ordem a ser considerada na ordenação.
 ** @return         Informações sobre as operações realizadas na ordenação.
 **/
sorting_telemetry selection_sort(int array[], size_t size, enum ordering order);

/**
 ** @brief Ordena o vetor @p array usando <em>ordenação por inserção</em>, segundo a ordem especificada por @p order.
 **
 ** @param array    Vetor a ser ordenado.
 ** @param size     Número de elementos no vetor.
 ** @param order    Ordem a ser considerada na ordenação.
 ** @return         Informações sobre as operações realizadas na ordenação.
 **/
sorting_telemetry insertion_sort(int array[], size_t size, enum ordering order);

/**
 ** @brief Ordena o vetor @p array usando <em>ordenação pelo borbulhamento</em>, segundo a ordem especificada por @p
 ** order.
 **
 ** @param array    Vetor a ser ordenado.
 ** @param size     Número de elementos no vetor.
 ** @param order    Ordem a ser considerada na ordenação.
 ** @return         Informações sobre as operações realizadas na ordenação.
 **/
sorting_telemetry bubble_sort(int array[], size_t size, enum ordering order);