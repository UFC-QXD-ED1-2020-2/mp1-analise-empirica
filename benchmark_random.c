/**
 **
 **  @file   benchmark_random.c
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Definição dos benchmarks a serem executados para instãncias aleatórias.
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

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ubench.h>

extern size_t instance_size;
extern size_t samples;

enum qx_qxcode_sorting_algos { SELECTION = 0, INSERTION = 1, BUBBLE = 2 };
const char *const sorting_algos_names[3] = {"SelectionSort", "InsertionSort", "BubbleSort"};

void benchmark_random_instances() {
    int *array = malloc(sizeof(int) * instance_size);
    //* NOTE Necessário para podermos passar o mesmo vetor aleatório para cada
    //*      um dos algoritmos
    int *array_clone = malloc(sizeof(int) * instance_size);

    //* NOTE Valores serão agragados para cada um dos três algorimos
    size_t *swaps_array[3] = {malloc(sizeof(size_t) * samples), malloc(sizeof(size_t) * samples),
                              malloc(sizeof(size_t) * samples)};
    size_t *comparisons_array[3] = {malloc(sizeof(size_t) * samples), malloc(sizeof(size_t) * samples),
                                    malloc(sizeof(size_t) * samples)};
    ubench_int64_t *timings[3] = {malloc(sizeof(ubench_int64_t) * samples), malloc(sizeof(ubench_int64_t) * samples),
                                  malloc(sizeof(ubench_int64_t) * samples)};

    size_t current_sample;
    sorting_telemetry telemetry;

    double time_avg, time_stde, time_moe;
    double swaps_avg, swaps_stde, swaps_moe;
    double comps_avg, comps_stde, comps_moe;

    bool selection_failed = false, insertion_failed = false, bubble_failed = false;

    puts("\n[[RELATORIO SOBRE INSTANCIAS ALEATORIAS]]");
    puts("=== Os valores a seguir consideram um intervalo de confianca de 95\%. ===");

    for (current_sample = 0; current_sample < samples; ++current_sample) {
        instancia_aleatoria(array, instance_size);

        // Selection
        memcpy(array_clone, array, sizeof(int) * instance_size);

        timings[SELECTION][current_sample] = ubench_ns();
        telemetry = selection_sort(array_clone, instance_size, ORDER_NONDECREASING);
        timings[SELECTION][current_sample] = ubench_ns() - timings[SELECTION][current_sample];

        if (!selection_failed)
            if ((selection_failed = !testa_ordenacao(array_clone, instance_size, ORDER_NONDECREASING)))
                fprintf(stderr, "[ERRO (aleatorias)]: O algoritmo %s falhou em ordenar o vetor.\n",
                        sorting_algos_names[SELECTION]);

        comparisons_array[SELECTION][current_sample] = telemetry.comparisons_count;
        swaps_array[SELECTION][current_sample] = telemetry.swaps_count;

        // Insertion
        memcpy(array_clone, array, sizeof(int) * instance_size);

        timings[INSERTION][current_sample] = ubench_ns();
        telemetry = insertion_sort(array_clone, instance_size, ORDER_NONDECREASING);
        timings[INSERTION][current_sample] = ubench_ns() - timings[INSERTION][current_sample];

        if (!insertion_failed)
            if ((insertion_failed = !testa_ordenacao(array_clone, instance_size, ORDER_NONDECREASING)))
                fprintf(stderr, "[ERRO (aleatorias)]: O algoritmo %s falhou em ordenar o vetor.\n",
                        sorting_algos_names[INSERTION]);

        comparisons_array[INSERTION][current_sample] = telemetry.comparisons_count;
        swaps_array[INSERTION][current_sample] = telemetry.swaps_count;

        // Bubble
        memcpy(array_clone, array, sizeof(int) * instance_size);

        timings[BUBBLE][current_sample] = ubench_ns();
        telemetry = bubble_sort(array_clone, instance_size, ORDER_NONDECREASING);
        timings[BUBBLE][current_sample] = ubench_ns() - timings[BUBBLE][current_sample];

        if (!bubble_failed)
            if ((bubble_failed = !testa_ordenacao(array_clone, instance_size, ORDER_NONDECREASING)))
                fprintf(stderr, "[ERRO (aleatorias)]: O algoritmo %s falhou em ordenar o vetor.\n",
                        sorting_algos_names[BUBBLE]);

        comparisons_array[BUBBLE][current_sample] = telemetry.comparisons_count;
        swaps_array[BUBBLE][current_sample] = telemetry.swaps_count;
    }

    int algorithm;
    for (algorithm = SELECTION; algorithm <= BUBBLE; ++algorithm) {
        // Averages
        time_avg = swaps_avg = comps_avg = 0.0;

        for (current_sample = 0; current_sample < samples; ++current_sample) {
            //* NOTE Dividindo logo, para evitar overflow de cálculo durante a soma
            time_avg += timings[algorithm][current_sample] / samples;
            swaps_avg += swaps_array[algorithm][current_sample] / samples;
            comps_avg += comparisons_array[algorithm][current_sample] / samples;
        }

        // Standard Errors
        time_stde = swaps_stde = comps_stde = 0.0;
        for (current_sample = 0; current_sample < samples; ++current_sample) {
            //* NOTE Dividindo logo, para evitar overflow de cálculo durante a soma
            time_stde += pow(timings[algorithm][current_sample] - time_avg, 2.0) / (samples - 1);
            swaps_stde += pow(swaps_array[algorithm][current_sample] - swaps_avg, 2.0) / (samples - 1);
            comps_stde += pow(comparisons_array[algorithm][current_sample] - comps_avg, 2.0) / (samples - 1);
        }

        time_stde = sqrt(time_stde);
        swaps_stde = sqrt(swaps_stde);
        comps_stde = sqrt(comps_stde);

        // Margins of Error (120 degrees of freedom for 95% confidence interval from student's t)
        time_moe = 1.98 * time_stde / sqrt(samples);
        swaps_moe = 1.98 * swaps_stde / sqrt(samples);
        comps_moe = 1.98 * comps_stde / sqrt(samples);

        printf("\n[ %s: media [margem] ]:\n", sorting_algos_names[algorithm]);
        printf("  - %-25s %.3lf %-3s [+- %.3lf]\n", "Tempo de execucao:", "us", time_avg, time_moe);
        printf("  - %-25s %.3lf     [+- %.3lf]\n", "Trocas:", swaps_avg, swaps_moe);
        printf("  - %-25s %.3lf     [+- %.3lf]\n", "Comparacoes:", comps_avg, comps_moe);
    }

    for (current_sample = 0; current_sample < 3; ++current_sample) {
        free(timings[current_sample]);
        free(comparisons_array[current_sample]);
        free(swaps_array[current_sample]);
    }

    free(array_clone);
    free(array);
}