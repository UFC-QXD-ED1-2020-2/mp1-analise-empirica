/**
 **
 **  @file   benchmarks.c
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Definição dos benchmarks a serem executados.
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

#include "ordenacao/algoritmos.h"
#include "ordenacao/gera_instancias.h"

#include <stdlib.h>
#include <ubench.h>

size_t instance_size = 1000;
size_t samples = 30;

//----- piores casos NÃO-DECRESCENTE

struct piores_casos_naodecr {
    int *array_selection;
    int *array_insertion;
    int *array_bubble;
    size_t size;
};

UBENCH_F_SETUP(piores_casos_naodecr) {
    ubench_fixture->size = instance_size;
    ubench_fixture->array_selection = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_insertion = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_bubble = malloc(sizeof(int) * instance_size);

    pior_caso_selection(ubench_fixture->array_selection, instance_size, ORDER_NONDECREASING);
    pior_caso_insertion(ubench_fixture->array_insertion, instance_size, ORDER_NONDECREASING);
    pior_caso_bubble(ubench_fixture->array_bubble, instance_size, ORDER_NONDECREASING);
}

UBENCH_F_TEARDOWN(piores_casos_naodecr) {
    free(ubench_fixture->array_bubble);
    free(ubench_fixture->array_insertion);
    free(ubench_fixture->array_selection);
}

//----- piores casos NÃO-CRESCENTE

struct piores_casos_naocresc {
    int *array_selection;
    int *array_insertion;
    int *array_bubble;
    size_t size;
};

UBENCH_F_SETUP(piores_casos_naocresc) {
    ubench_fixture->size = instance_size;
    ubench_fixture->array_selection = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_insertion = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_bubble = malloc(sizeof(int) * instance_size);

    pior_caso_selection(ubench_fixture->array_selection, instance_size, ORDER_NONINCREASING);
    pior_caso_insertion(ubench_fixture->array_insertion, instance_size, ORDER_NONINCREASING);
    pior_caso_bubble(ubench_fixture->array_bubble, instance_size, ORDER_NONINCREASING);
}

UBENCH_F_TEARDOWN(piores_casos_naocresc) {
    free(ubench_fixture->array_bubble);
    free(ubench_fixture->array_insertion);
    free(ubench_fixture->array_selection);
}

//----- aleatorio nãodecrescente

struct aleatorio_naodecr {
    int *array_selection;
    int *array_insertion;
    int *array_bubble;
    size_t size;
    size_t samples_count;
};

UBENCH_F_SETUP(aleatorio_naodecr) {
    ubench_fixture->size = instance_size;
    ubench_fixture->samples_count = samples;

    ubench_fixture->array_selection = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_insertion = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_bubble = malloc(sizeof(int) * instance_size);

    instancia_aleatoria(ubench_fixture->array_selection, instance_size);
    instancia_aleatoria(ubench_fixture->array_insertion, instance_size);
    instancia_aleatoria(ubench_fixture->array_bubble, instance_size);
}

UBENCH_F_TEARDOWN(aleatorio_naodecr) {
    free(ubench_fixture->array_bubble);
    free(ubench_fixture->array_insertion);
    free(ubench_fixture->array_selection);
}