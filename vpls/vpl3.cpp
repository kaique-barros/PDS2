/*
O objetivo desse exercício é praticar a manipulação de dados em memória, especialmente considerando o uso de ponteiros.

Para isso, você deve escrever as instruções necessárias para cada um dos itens listados nos comentários do código inicial fornecido (main.cpp). Baixe o código fornecido, escreva as instruções nos locais adequados, e submeta o seu código para avaliação.

Todas as impressões específicas de uma instrução devem ser feitas na mesma linha, utilizando um espaço em branco (" ") caso mais de um elemento seja impresso. Ao final de cada instrução que realiza alguma impressão você deve fazer uma quebra de linha (endl).

ATENÇÃO: quando vários elementos são impressos na mesma linha, o último elemento não deve ser seguido de espaço, apenas da quebra de linha!

Referências:
https://www.cplusplus.com/doc/tutorial/pointers/
https://www.cplusplus.com/doc/tutorial/dynamic/
*/

#include <iostream>

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por referência 
//    - A segunda deve ser passada "por referência" usando apontadores (passgem "por referência" disponível em C)
//    - A terceira deve ser passada por valor
//   A função deverá incrementar em 1 o valor das 3 variáveis e retornar.

void incrementa(int &a, int* b, int c) {
    a++;
    *b += 1;
    c++;
}


int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int a;
    std::cin >> a;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* b = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho;
    std::cin >> tamanho;
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        std::cin >> vetor[i]; 
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    std::cout << &a << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    std::cout << a << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    std::cout << &b << std::endl;

    // 7) Imprima o VALOR da variável declarada em (2)
    std::cout << b << std::endl;


    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    std::cout << &vetor << std::endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    std::cout << &vetor[0] << std::endl;    

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    std::cout << vetor[0] << std::endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)    
    b = &a;

    // 12) Imprima o VALOR da variável declarada em (2)
    std::cout << b << std::endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *b << std::endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *b = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    std::cout << a << std::endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    b = vetor;

    // 17) Imprima o VALOR da variável declarada em (2)
    std::cout << b << std::endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *b << std::endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    b = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(b == vetor){
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl; 
    }

    // 21) Imprima o VALOR da variável declarada em (2)
    std::cout << b << std::endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *b << std::endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i = 0; i < tamanho; i++){
        b[i] *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i = 0; i < tamanho; i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for(int i = 0; i < tamanho; i++){
        std::cout << *(vetor + i) << " ";
    }
    std::cout << std::endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for(int i = 0; i < tamanho; i++){
        std::cout << *(b + i) << " ";
    }
    std::cout << std::endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    b = vetor + tamanho - 1;

    // 28) Imprima o VALOR da variável declarada em (2)
    std::cout << b << std::endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *b << std::endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** c = &b;

    // 31) Imprima o VALOR da variável declarada em (30)
    std::cout << c << std::endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    std::cout << &c << std::endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    std::cout << *c << std::endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    std::cout << **c << std::endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int d, e, f;
    std::cin >> d >> e >> f;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    incrementa(d, &e, f);
    
    // 37) Imprima o valor das 3 variáveis criadas em 35, uma por linha
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;

    return 0;
}