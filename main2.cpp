#include <iostream>
#include <string>

//definição das variáveis. Cada produto terá como base a string de um código, esse código será usado para ser digitado na máquina para selecionar produto.
struct Produto {
    std::string codigo;
    int quantidade;
    double valor;
};

int main() {
    Produto produtos[5]; // Array para armazenar os produtos
    int contador = 0; // Variável para controlar o número de produtos cadastrados

    // Loop para cadastrar os produtos
    while (contador < 5) {
        std::cout << "Cadastrar Produto " << contador + 1 << std::endl;
    // Ler código do produto
        std::cout << "Codigo do Produto: ";
        std::getline(std::cin, produtos[contador].codigo);

    // Ler quantidade do produto
        std::cout << "Quantidade: ";
        std::cin >> produtos[contador].quantidade;

    // Ler valor do produto
        std::cout << "Valor: R$";
        std::cin >> produtos[contador].valor;

    // Limpar
        std::cin.ignore();

        contador++; // Incrementar o contador de produtos cadastrados
        std::cout << "Produto cadastrado com sucesso!" << std::endl << std::endl;
    }

    // Exibir os produtos cadastrados
    std::cout << "Produtos cadastrados:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Produto " << i + 1 << ": " << std::endl;
        std::cout << "Codigo: " << produtos[i].codigo << std::endl;
        std::cout << "Quantidade: " << produtos[i].quantidade << std::endl;
        std::cout << "Valor: R$" << produtos[i].valor << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

