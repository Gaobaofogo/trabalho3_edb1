# Projeto da última unidade da disciplina Estrutura de Dados 1

## Objetivo

Construir um programa capaz de ler um arquivo de texto, procurar por palavras incorretas e sugerir correções a essas palavras. O programa deve ser escrito em C++ 11, utilizar o CMAKE e manter as boas práticas de programação.

## Estruturação das pastas

Segui o recomendado pelo professor da disciplina. Src contém o código fonte da aplicação, include contm os cabeçalhos e criei uma outra chamada support-files que abriga os dicionários e os textos com erros ortográficos a serem corrigidos.

## Escolha das estruturas de dados

Utilizei o vector e o set da stl do C++ no projeto.

Sobre o vector, fiquei em dúvida entre ele e a linked list já que havia uma inserção de dados muito alta. Porém, durante o desenvolvimento do trabalho, percebi que o gargalo de performace fica na leitura massiva das palavras e a linked list e suas variações tem pior performace nesse quesito em relação ao vector.

Depois, eu quis uma estrutura para pesquisar palavras do dicionário o mais rápido possível e com o menor custo de memória. Para isso, existe o set. É possível pesquisar dados nele com O(1). Os dados inseridos foram só a string das palavras e nada mais, economizando espaço de ter de guardar toda a estrutura das structs criadas no projeto. Se eu utilizasse o map, que também serviria para esse propósito de pesquisar em O(1), eu teria que ter um par de chave e valor e tudo o que eu precisava era apenas pesquisar se a chave já existia dentro da estrutura, não importando o valor.

## Compilando e executando

Para rodar, necessário ter o g++, make e cmake instalados na sua máquina.

Crie uma pasta chamada 'build' na raiz do projeto, entre nela:

```
$ mkdir build
$ cd build
```

E rode os comandos de compilação:

```
$ cmake ..
$ make
```

O executável estará dentro de build e se chama 'prog'. O programa recebe obrigatoriamente duas entradas via linha de comando:

1. Caminho do arquivo de dicionário
2. Caminho do arquivo alvo a ser corrigido

Um exemplo de execução seria(rodando o comando dentro da pasta build):

```
./prog ../support-files/dicionario-UTF-8.txt ../support-files/imd.txt
```

O fim da saída será algo parecido com isso:

```
(... outras palavras recomendadas que estão acima do prompt ...)

dossentes:
 - abesentar

técnico-administrativos:
 - jurídico-administrativo

diferentes:
 - abcedente

conhecimento:
 - acontecimental

há:
 - a

inclui:
 - abluir

pessoas:
 - abestos

esternas:
 - aberas

seus:
 - abases

campos:
 - abafos
```
