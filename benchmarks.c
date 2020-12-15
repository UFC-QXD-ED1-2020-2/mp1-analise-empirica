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

#include <stdio.h>
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

UBENCH_F(piores_casos_naodecr, selection_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        selection_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(piores_casos_naodecr, insertion_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        insertion_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(piores_casos_naodecr, bubble_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        bubble_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
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

UBENCH_F(piores_casos_naocresc, selection_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        selection_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONINCREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(piores_casos_naocresc, insertion_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        insertion_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONINCREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(piores_casos_naocresc, bubble_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        bubble_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONINCREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

//----- quase-ordenado nãodecrescente

struct quaseord_naodecr {
    int *array_selection;
    int *array_insertion;
    int *array_bubble;
    size_t size;
    size_t samples_count;
};

UBENCH_F_SETUP(quaseord_naodecr) {
    ubench_fixture->size = instance_size;
    ubench_fixture->samples_count = samples;

    ubench_fixture->array_selection = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_insertion = malloc(sizeof(int) * instance_size);
    ubench_fixture->array_bubble = malloc(sizeof(int) * instance_size);

    instancia_quase_ordenada(ubench_fixture->array_selection, instance_size, ORDER_NONDECREASING);
    instancia_quase_ordenada(ubench_fixture->array_insertion, instance_size, ORDER_NONDECREASING);
    instancia_quase_ordenada(ubench_fixture->array_bubble, instance_size, ORDER_NONDECREASING);
}

UBENCH_F_TEARDOWN(quaseord_naodecr) {
    free(ubench_fixture->array_bubble);
    free(ubench_fixture->array_insertion);
    free(ubench_fixture->array_selection);
}

UBENCH_F(quaseord_naodecr, selection_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        selection_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(quaseord_naodecr, insertion_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        insertion_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(quaseord_naodecr, bubble_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        bubble_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
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

UBENCH_F(aleatorio_naodecr, selection_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        selection_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(aleatorio_naodecr, insertion_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        insertion_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}

UBENCH_F(aleatorio_naodecr, bubble_sort) {
    static unsigned int execution = 0;
    sorting_telemetry telemetry =
        bubble_sort(ubench_fixture->array_insertion, ubench_fixture->size, ORDER_NONDECREASING);
    if (execution == 0) {
        printf("comparacoes = %zu, trocas = %zu\n", telemetry.comparisons_count, telemetry.swaps_count);
        ++execution;
    }
}