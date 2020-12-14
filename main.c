/**
 **
 **  @file   main.c
 **  @date   2020-12-10
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **  Arquivo principal, cujas únicas responsabilidades consistem de ler
 **  alterações dos parâmetros padrão e iniciar a biblioteca que realiza os
 **  benchmarks.
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

#include <argtable3.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ubench.h>

UBENCH_STATE();

// FIXME Mover para localização onde alunos podem alterar esses valores.
extern size_t instance_size;
extern size_t samples;

int main(int argc, char *argv[]) {
    int exitcode = EXIT_SUCCESS;
    
    // -- Leitura de parâmetros --
    const char *progname = QXD_QXCODE_PROGNAME;

    // Estruturas para parametros
    struct arg_lit *help_opt;
    struct arg_int *size_opt, *samples_opt;
    struct arg_end *end_opt;

    // Sequencia de parametros
    void *argtable[] = {
        help_opt    = arg_litn("?h", "help", 0, 1, "mostrar este texto de ajuda e encerrar"),
        size_opt    = arg_intn("n", "size", "<n>", 0, 1, "tamanho de cada instancia a gerar"),
        samples_opt = arg_intn("r", "samples", "<n>", 0, 1, "quantidade de instancias aleatorias a gerar"),
        end_opt     = arg_end(5),
    };

    if (arg_nullcheck(argtable) != 0) {
        fputs("[ERRO]: nao ha memoria suficiente disponivel.\n", stderr);
        exitcode = EXIT_FAILURE;
    } else {
        int nerrors = arg_parse(argc, argv, argtable);

        if(help_opt->count > 0 || nerrors != 0) {
            FILE *stream = stdout;
            if(nerrors != 0) {
                stream = stderr;
                exitcode = EXIT_FAILURE;
                fputs("[ERRO]: Parametros ou valores incorretos foram encontrados.\n", stream);
                arg_print_errors(stdout, end_opt, progname);
                fputc('\n', stream);
            }

            fputs("UFCQXD - QXD0010 - [MiniProjeto = Analise empirica].\n\n", stream);
            fprintf(stream, "Uso: %s", progname);
            arg_print_syntax(stream, argtable, "\n");
            arg_print_glossary(stream, argtable, "  %-25s %s\n");
            fputs("\nQXD0010 - 2020.2 - Estrutura de Dados\n", stream);
            fputs("Universidade Federal do Ceara. Campus de Quixada.\n", stream);
        } else {
            if (size_opt->count > 0) {
                if(size_opt->ival[0] > 0) {
                    instance_size = (size_t) size_opt->ival[0];
                } else {
                    fprintf(stderr, "[ERRO]: Tamanho das entradas deve ser positivo. Valor fornecido foi %d.\n",
                            size_opt->ival[0]);
                    exitcode = EXIT_FAILURE;
                    goto exit_point;
                }
            } else {
                fprintf(stderr, "[NOTA]: Usando o tamanho padrão de instancia de %d.\n", instance_size);
            }

            if (samples_opt->count > 0) {
                if(samples_opt->ival[0] > 0) {
                    samples = (size_t) samples_opt->ival[0];
                } else {
                    fprintf(stderr,
                            "[ERRO]: Quantidade de instancias aleatorias deve ser positiva. Valor fornecido foi %d.\n",
                            samples_opt->ival[0]);
                    exitcode = EXIT_FAILURE;
                    goto exit_point;
                }
            } else {
                fprintf(stderr, "[NOTA]: Usando a quantidade padrão de instancias aleatorias de %d.\n", samples);
            }

            // Inicializando geração de números aleatórios.
            srand(time(NULL));

            exitcode = ubench_main(argc, (const char * const*)argv);
        }
    }

    exit_point:
    arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
    
    return exitcode;
}