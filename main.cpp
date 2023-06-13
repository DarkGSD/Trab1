#include <iostream>
#include <string>
#include <map>

struct Produto {
    std::string cod;
    double preco;
};

int main() {
    std::map<int, Produto> produtos;

    // Adicionar produtos à máquina
    produtos[1] = {"01", 2.50};
    produtos[2] = {"02", 4.00};
    produtos[3] = {"03", 3.00};
    produtos[4] = {"04", 2.00};
    produtos[5] = {"05", 1.50};

    double saldo = 0.0;
    double valorPago = 0.0;
    int codigo;

    while (true) {
        // Exibir menu de produtos
        std::cout << "Produto\t\tPreço" << std::endl;
        for (const auto& it : produtos) {
            std::cout << it.first << "\t" << it.second.cod << "\t\tR$" << it.second.preco << std::endl;
        }
        std::cout << "Digite o código do produto (0 para sair): ";
        std::cin >> codigo;

        if (codigo == 0) {
            break;
        }

        // Verificar se o produto está disponível
        auto it = produtos.find(codigo);
        if (it == produtos.end()) {
            std::cout << "Produto não disponível." << std::endl;
            continue;
        }

        // Efetuar a venda
        std::cout << "Venda realizada. Produto: " << it->second.cod << ". Preço: R$" << it->second.preco << std::endl;
        saldo += it->second.preco;

        // Perguntar pelo valor pago
        std::cout << "Valor pago: R$";
        std::cin >> valorPago;

        // Calcular o troco
        double troco = valorPago - saldo;
        if (troco >= 0) {
            std::cout << "Troco: R$" << troco << std::endl;
        } else {
            std::cout << "Valor insuficiente. Faltam: R$" << -troco << std::endl;
        }
    }

    std::cout << "Saindo do programa." << std::endl;

    return 0;
}
