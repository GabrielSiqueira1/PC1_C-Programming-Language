#O matemático computacional - Um curso em C

### O que é uma linguagem de programação

Se trata de um método padronizado com regras sintáticas e semânticas.

### Como surgiu a linguagem C

Criada em 1972 na Bell Labs, sendo baseada em BCLP e B. Popular em ambientes UNIX. É uma linguagem imperativa pois o programador pode definir um conjunto de instruções que serão seguidas, também é procedural, pois é possível subdividir o código em funções e subrrotinas. É uma linguagem de alto nível, porque se aproxima da linguagem humana, no entanto, esta possuí recursos de baixo nível como visto neste repositório em outras pastas. Também é altamente portátil e de alta performance.

### Padronização da linguagem C

Padronização de C89 até C18, com o objetivo de modernizar a sintaxe, melhorar a representação de dados e uma biblioteca com novas funcionalidades. Existem diversos benefícios nisso, como a reusabilidade.

### Aplicações em C

Núcleo de sistemas operacionais, Computação gráfica, hardware e sistemas de tempo real, banco de dados e algumas linguagens de programação.

### Fases da criação de um programa em C

1. Criação do código-fonte de extensão .c e .h
2. Processamento cujo o propósito é tratar as diretivas antes da compilação, a inclusão arquivos e a substituição de constantes e macros.
3. Compilação realiza o procedimento de troca do código-fonte para código de máquina
4. Linka-se ao programa
5. CPU executa as instruções

### Flags

-g sinaliza ao compilador para criação de um programa que possa ser executado passo a passo
-o opção que define o nome do executável, por padrão será o nome do arquivo fonte sem a extensão

### Composição

Um código-fonte são compostas incialmente por diretivas de preprocessamento que são executadas antes da compilação, dentre elas tem o #include que inclui a biblioteca (por exemplo, a stdio.h carrega consigo o scanf e o printf) e #define que cria um macro (isso significa que uma determinada variável, imutável, pode receber esse valor em todo o código).

1. "{}" separa um conjunto de instruções
2. "return" separa funções
3. ";" finda uma instrução, seu esquecimento gera um erro de sintaxe.

### Variáveis e constantes

Uma variável está presente em uma região limitada na memória. Em C, é dito que uma variável é altamente tipada, ou seja, o tipo que uma variável armazena é definido previamente e de forma fixa. Cada variável é fixada por um inteiro hexadecimal.
Uma constante tem todas as características de uma variável, no entanto, não possuem a possibilidade de alterar seu valor.

Regras:

1. Declare antes do uso;
2. Sensibilidade ao caso;
3. Nomenclatura: Letra simples, underline, número (Porém não se inicia com um).

Convenções:

1. Inicie nome com letra;
2. Apenas maiúsculas para constantes;
3. Nomes significativos.

### Intervalos de tipos

Cada tipo de variável tem um intervalo definido e este depende da quantidade de bits que o mesmo representa. Por exemplo, um char armazena 8 bits, o que significa que o seu intervalo tem $2^8$ valores possíveis, desde -127 a 127 totalizando 256 termos. Já o int, são 32 bits e portanto são $2^{32}$ valores. As constantes que define o valor máximo que podem possuir estão na biblioteca "limits.h".

### Conversão de tipos

Trata-se do processo de transformação de um dado de um tipo em outro. O primeiro procedimento é uma conversão implícita que é interessante pois evita a perda de dados e atualiza de acordo com a maior capacidade, ou seja, uma variável double pode armazenar uma operação entre variáveis do tipo int e long por exemplo, por ter maior espaço de armazenamento. Um outro modo é o type casting que define para o que a variável irá converter, o problema é que pode-se perder informação, (int) z.
