/*
    Projeto AEDS I - Estatística em Base de Dados de Veículos

    Author: Thiago Martins - 2024.1.08.023

    Requisitos: 1- inclusão de um novo veículo na base de dados;
                2- Busca de um veículo pela placa, com opção de exclusão da base de dados;
                3- Busca de veículos pelo tipo;
                4- Busca de veículos pelo câmbio;
                5- Busca de veículos por um faixa de valores;
                6- Relatório do banco de dados.

    modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, portas, placa e valor do veículo. 

*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int TAM = 100;

typedef struct{
    bool valido = true;
    string modelo;
    string marca;
    string tipo;
    string ano;
    string quilometragem;
    string potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    string valor;
} Carro;

int main(){
    Carro tabela[TAM];
    ifstream arquivo_inicial("BD_veiculos.txt");
    if(!arquivo_inicial.is_open()){
        cout << endl << "ERRO, arquivo_inicial inexistente!";
        return 1;
    }
    
    // Gerando Base Inicial de Veículos
    int qtdcarros = 0 , i = 0;
    arquivo_inicial >> tabela[i].modelo;
    while(tabela[i].modelo != "FIM"){
        arquivo_inicial >> tabela[i].marca;
        arquivo_inicial >> tabela[i].tipo;
        arquivo_inicial >> tabela[i].ano;
        arquivo_inicial >> tabela[i].quilometragem;
        arquivo_inicial >> tabela[i].potencia;
        arquivo_inicial >> tabela[i].combustivel;
        arquivo_inicial >> tabela[i].cambio;
        arquivo_inicial >> tabela[i].direcao;
        arquivo_inicial >> tabela[i].cor;
        arquivo_inicial >> tabela[i].portas;
        arquivo_inicial >> tabela[i].placa;
        arquivo_inicial >> tabela[i].valor;
        i++;
        qtdcarros++;
        arquivo_inicial >> tabela[i].modelo;
    }

    arquivo_inicial.close();

    // Guardando a posição final da tabela inicial
    int j = i;

    // Menu para direcionar os usuários
    int opcao = 0;
    cout << "Base de Dados de Veículos" << endl;
    cout << endl << "Opções disponíveis:";
    cout << endl << "1 - Exibir Base de Dados" << endl << "2 - Incluir um veículo" << endl << "3 - Buscar um Veículo";
    cout << endl << "4 - Exibir Relatório" << endl << "5 - Sair" << endl;
    cout << endl << "Escolha a opção desejada: ";
    cin >> opcao;
    while(opcao > 5 || opcao <=0){
        cout << endl << "Opção inválida! Insira novamente: ";
        cin >> opcao;
    }

    while(opcao != 5){
        switch(opcao){
            case 1:
            {
                // Exibição da Base de Dados
                cout << endl << "Início da Base de Dados" << endl;
                for(int i = 0; i < qtdcarros; i++){
                    cout << endl << tabela[i].modelo;
                    cout << " " << tabela[i].marca;
                    cout << " " << tabela[i].tipo;
                    cout << " " << tabela[i].ano;
                    cout << " " << tabela[i].quilometragem;
                    cout << " " << tabela[i].potencia;
                    cout << " " << tabela[i].combustivel;
                    cout << " " << tabela[i].cambio;
                    cout << " " << tabela[i].direcao;
                    cout << " " << tabela[i].cor;
                    cout << " " << tabela[i].portas;
                    cout << " " << tabela[i].placa;
                    cout << " " << tabela[i].valor;
                }
                cout << endl << endl << "Fim da Base de Dados" << endl;

                cout << endl << "Opções disponíveis:";
                cout << endl << "1 - Exibir Base de Dados" << endl << "2 - Incluir um veículo" << endl << "3 - Buscar um Veículo";
                cout << endl << "4 - Exibir Relatório" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <=0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;
            }
            case 2:
            {
                // Incluir um Veículo
                cout << endl << "Incluir um veículo" << endl;
                cout << endl << "Insira o modelo: ";
                cin >> tabela[j].modelo;
                cout << endl << "Insira a marca: ";
                cin >> tabela[j].marca;
                cout << endl << "Insira o tipo: ";
                cin >> tabela[j].tipo;
                cout << endl << "Insira o ano: ";
                cin >> tabela[j].ano;
                cout << endl << "Insira a quilometragem do veículo: ";
                cin >> tabela[j].quilometragem;
                cout << endl << "Insira a potência: ";
                cin >> tabela[j].potencia;
                cout << endl << "Insira o combustível: ";
                cin >> tabela[j].combustivel;
                cout << endl << "Insira o tipo de câmbio: ";
                cin >> tabela[j].cambio;
                cout << endl << "Insira o tipo de direção: ";
                cin >> tabela[j].direcao;
                cout << endl << "Insira a cor do veículo: ";
                cin >> tabela[j].cor;
                cout << endl << "Insira o Nº de portas: ";
                cin >> tabela[j].portas;
                cout << endl << "Insira a placa: ";
                cin >> tabela[j].placa;
                cout << endl << "Insira o valor do veículo: ";
                cin >> tabela[j].valor;
                
                cout << endl << "Veículo adicionado com sucesso!" << endl;
                qtdcarros++;
                j += 1;
                
                cout << endl << "Opções disponíveis:";
                cout << endl << "1 - Exibir Base de Dados" << endl << "2 - Incluir um veículo" << endl << "3 - Buscar um Veículo";
                cout << endl << "4 - Exibir Relatório" << endl << "5 - Sair" << endl;
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 5 || opcao <=0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;
            }
        }
    }

    return 0;
 }