/**
 **
 **  @file   gera_instancias.h
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Definição dos cabeçalhos para as funções que serão chamadas em busca de
 **  instâncias para os algoritmos de ordenação declarados no arquivo
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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! IMPORTANTE
//!
//! - Não altere este arquivo.
//!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef QXD_QXCODE_GERA_INSTANCIAS_H
#define QXD_QXCODE_GERA_INSTANCIAS_H

#include "algoritmos.h"

/**
 ** @brief Preenche as primeiras @p size posições do vetor @p array com elementos
 ** arbitrários, porém compondo um @b pior caso para o algoritmo <em>SelectionSort</em>
 ** quando ordenando-os segundo a ordem especificada por @p order.
 **
 ** A memória correspondente ao vetor @p array será alocada pela função que chamar esta.
 **
 ** @param array    vetor a preencher.
 ** @param size     quantidade de elementos a preencher.
 ** @param order    ordem em que os elementos serão ordenados.
 **/
void pior_caso_selection(int array[], size_t size, enum ordering order);

/**
 ** @brief Preenche as primeiras @p size posições do vetor @p array com elementos
 ** arbitrários, porém compondo um @b pior caso para o algoritmo <em>InsertionSort</em>
 ** quando ordenando-os segundo a ordem especificada por @p order.
 **
 ** A memória correspondente ao vetor @p array será alocada pela função que chamar esta.
 **
 ** @param array    vetor a preencher.
 ** @param size     quantidade de elementos a preencher.
 ** @param order    ordem em que os elementos serão ordenados.
 **/
void pior_caso_insertion(int array[], size_t size, enum ordering order);

/**
 ** @brief Preenche as primeiras @p size posições do vetor @p array com elementos
 ** arbitrários, porém compondo um @b pior caso para o algoritmo <em>BubbleSort</em>
 ** quando ordenando-os segundo a ordem especificada por @p order.
 **
 ** A memória correspondente ao vetor @p array será alocada pela função que chamar esta.
 **
 ** @param array    vetor a preencher.
 ** @param size     quantidade de elementos a preencher.
 ** @param order    ordem em que os elementos serão ordenados.
 **/
void pior_caso_bubble(int array[], size_t size, enum ordering order);

/**
 ** @brief Preenche as primeiras @p size posições do vetor @p array com elementos
 ** arbitrários, porém constituindo uma instância com muito poucos elementos ainda
 ** por ordenar, considerando a ordem especificada por @p order.
 **
 ** A memória correspondente ao vetor @p array será alocada pela função que chamar esta.
 **
 ** @param array    vetor a preencher.
 ** @param size     quantidade de elementos a preencher.
 ** @param order    ordem em que os elementos serão ordenados.
 **/
void instancia_quase_ordenada(int array[], size_t size, enum ordering order);

/**
 ** @brief Preenche as primeiras @p size posições do vetor @p array com elementos
 ** arbitrários, dispostos em uma ordem aleatória.
 **
 ** A memória correspondente ao vetor @p array será alocada pela função que chamar esta.
 **
 ** @param array    vetor a preencher.
 ** @param size     quantidade de elementos a preencher.
 ** @param order    ordem em que os elementos serão ordenados.
 **/
void instancia_aleatoria(int array[], size_t size);

#endif