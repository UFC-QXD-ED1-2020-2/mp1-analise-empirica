# MiniProjeto
## Descrição
Neste mini-projeto iremos implementar e analisar Algoritmos de Ordenação Básicos.

## Informações
Você deverá alterar os arquivos constantes na pasta `aluno`. *Os outros arquivos não devem ser alterados* para não afetar o funcionamento do programa.

Todas as funções que você irá implementar ou usar foram documentadas e devem ter suas informações apresentadas pelo VSCode quando repousar o mouse sobre elas. Além disso, você pode observar suas definições nos arquivos de cabeçalho importados.

### Linguagem
Você deverá usar a linguagem C para desenvolver sua implementação.

### Compilando e Executando
Para compilar o seu programa, você precisará ter o `cmake` e um compilador de C instalados.

#### Visual Studio Code
Você pode fazer uso do VSCode (usando a extensão *CMake Tools* [ms-vscode.cmake-tools]) clicando na opção "`⚙ Compilar`" (na barra inferior). Para executar, basta clicar no botão "`▷`" (um símbolo de reprodução), próximo ao botão para compilação.

#### Via terminal

Além disso, pelo terminal, você pode usar os comandos a seguir no *diretório raiz do projeto* (**verifique se ele contém o arquivo `CMakeLists.txt`**):

    $ cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -H. -B./build -G Ninja
    $ cmake --build ./build --config Release --target analise-empirica

> *Esses comandos foram extraídos da configuração feita pelo VSCode*.

Para executar o programa, use o seguinte comando (ainda na pasta raiz):

    ./build/analise-empirica

> Este programa inclui opções de alteração de parâmetros. Para ver todas as opções, execute:
>
>     ./build/analise-empirica --help

## Instruções
Observe as instruções contidas no arquivo `.pdf` incluído neste repositório. As informações necessárias para as instruções adicionais serão fornecidas como saída do programa.