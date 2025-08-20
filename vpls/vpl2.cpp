/*
O objetivo desse VPL é avançar na prática dos comandos de entrada e saída específicos de C++ (inserção/cout e extração/cin) e também a utilização do tipo String.

Você deve escrever um programa para validar comentários enviados para um fórum. Como entrada para o programa será informada uma lista de palavras proibidas e o próprio comentário.

O comentário é uma frase que possui um número não conhecido anteriormente de palavras. Caso o comentário possua palavras proibidas, as letras dessas palavras devem ser substituídas por '*' (asteriscos). Ao final, o programa deve imprimir a frase com as devidas alterações e o número de vezes que cada palavra foi ocultada.

Para facilitar, você pode assumir que todo o comentário possui apenas letras minúsculas e que no máximo 10 palavras proibidas serão informadas para substituição (também todas minúsculas). Além disso, o primeiro caractere da entrada informa o número de palavras proibidas a serem informadas em seguida.

Formato entrada e saída:
input = 
[NUM PALAVRAS PROIBIDAS] [Palavra1, Palavra2, ...]
[Mensagem]
output =
[Mensagem com palavras omitidas]
[Informações das palavras omitidas]



Exemplos de entrada e saída:

input = 
1 droga
o ibis eh uma droga de time 
output =
o ibis eh uma ***** de time
Palavra droga substituida 1 vez(es).


input = 
2 feio bobo
quem gosta de pds2 eh feio feio e bobo bobo
output =
quem gosta de pds2 eh **** **** e **** **** 
Palavra feio substituida 2 vez(es).
Palavra bobo substituida 2 vez(es).



Dica1:
Não complique além do necessário! O exercício pode (e deve!) ser resolvido usando apenas as estruturas básicas aprendidas em C e os novos comandos de C++ introduzidos.

Dica2:
Lembre-se que para testar localmente, você pode usar o seguinte comando: ./executavel < entrada.txt, onde o arquivo entrada.txt possui os dados que serão utilizados como entrada (a lista de palavras e o comentário, no caso desse exercício).

Referências:
https://www.cplusplus.com/doc/tutorial/basic_io/
https://www.cplusplus.com/reference/string/string/
*/

#include <iostream>
#include <string>

int main() {
    int num_palavras_proibidas = 0;
    std::cin >> num_palavras_proibidas;

    std::string palavras_proibidas[num_palavras_proibidas];
    for (int i = 0; i < num_palavras_proibidas; i++) {
        std::cin >> palavras_proibidas[i];
    }
    getchar(); // Para ignorar o \n depois da primeira linha

    std::string mensagem;
    std::getline(std::cin, mensagem);

    int contador_de_censura[num_palavras_proibidas] = {0};
    int contador_posicao_palavra = 0; 
    // Para contar a posição da palavra censurada
    // Sem isso tem que incluir 2 bibliotecas e achei over
    
    for (std::string palavra : palavras_proibidas){
        int tamanho_palavra = palavra.length();
        std::string palavra_censurada(tamanho_palavra, '*');
        
        int posicao_comecar_busca = 0;

        while (mensagem.find(palavra, posicao_comecar_busca) != std::string::npos) {
            // Para garantir que a palavra encontrada não é parte de outra palavra
            if (mensagem[mensagem.find(palavra, posicao_comecar_busca) + tamanho_palavra] == ' ' || mensagem[mensagem.find(palavra, posicao_comecar_busca) + tamanho_palavra] == '\0') {
                mensagem.replace(mensagem.find(palavra), tamanho_palavra, palavra_censurada);
                contador_de_censura[contador_posicao_palavra]++;
            } 
            // se for parte de outra palavra, apenas atualiza a posição de busca
            else {
                posicao_comecar_busca = mensagem.find(palavra, posicao_comecar_busca) + tamanho_palavra;
            }
        }
        contador_posicao_palavra++;
    }

    contador_posicao_palavra = 0;
    std::cout << mensagem << std::endl;
    for (std::string palavra : palavras_proibidas) {
        std::cout << "Palavra " << palavra << " substituída: " << contador_de_censura[contador_posicao_palavra] << " vez(es)." << std::endl;
        contador_posicao_palavra++;
    }

    return 0;
}