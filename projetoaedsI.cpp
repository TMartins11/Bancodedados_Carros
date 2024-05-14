/*
    Projeto AEDS I - Estatística em Base de Dados de Veículos

    Author: Thiago Martins - 2024.1.08.023

    Requisitos: 1- inclusão de um novo veículo na base de dados;
                2- Busca de um veículo pela placa, com opção de exclusão da base de dados;
                3- Busca de veículos pelo tipo;
                4- Busca de veículos pelo câmbio;
                5- Busca de veículos por umaa faixa de valores;
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
    int ano;
    float quilometragem;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valor;
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
    
    do{
        cout << endl << "Base de Dados de Veículos" << endl;
        cout << endl << "Opções disponíveis:";
        cout << endl << "1 - Exibir Base de Dados" << endl << "2 - Incluir um veículo" << endl << "3 - Buscar um Veículo";
        cout << endl << "4 - Exibir Relatório" << endl << "5 - Sair" << endl;
        cout << endl << "Escolha a opção desejada: ";
        cin >> opcao;
        while(opcao > 5 || opcao <=0){
            cout << endl << "Opção inválida! Insira novamente: ";
            cin >> opcao;
        }

        switch(opcao){
            case 1:
            {
                // Exibição da Base de Dados
                cout << endl << "Início da Base de Dados" << endl;
                for(int i = 0; i < qtdcarros; i++){
                    if(tabela[i].valido == true){
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
                }
                cout << endl << endl << "Fim da Base de Dados" << endl;
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
                break;
            }
            case 3:
            {
                // Buscar um Veículo
                int opbusca;
                string exc_vec;
                do{
                    cout << endl << "Opções de Busca:" << endl << "1 - Pela placa";
                    cout << endl << "2 - Pelo tipo" << endl << "3 - Pelo câmbio" << endl << "4 - Por faixas de preço";
                    cout << endl << "5 - Sair" << endl;
                    cout << endl << "Insira a opção desejada: ";
                    cin >> opbusca;
                    while(opbusca > 5 || opbusca <= 0){
                        cout << endl << "Opção inválida!Insira novamente: ";
                        cin >> opbusca;
                    }
                    switch(opbusca){
                        case 1:
                        {
                            // Buscar Veículo pela Placa
                            string enc_placa;
                            int placa_enc = -1;
                            int vec_enc = 0;
                            cout << endl << "Insira a placa do veículo que deseja encontrar: ";
                            cin >> enc_placa;
                            for(i = 0; i < qtdcarros; i++){
                                if(tabela[i].placa == enc_placa){
                                    vec_enc = i;
                                }
                            }
                            if(vec_enc >= 0){
                                cout << endl << "O veículo encontrado foi:" << endl;
                                cout << endl << tabela[vec_enc].modelo;
                                cout << " " << tabela[vec_enc].marca;
                                cout << " " << tabela[vec_enc].tipo;
                                cout << " " << tabela[vec_enc].ano;
                                cout << " " << tabela[vec_enc].quilometragem;
                                cout << " " << tabela[vec_enc].potencia;
                                cout << " " << tabela[vec_enc].combustivel;
                                cout << " " << tabela[vec_enc].cambio;
                                cout << " " << tabela[vec_enc].direcao;
                                cout << " " << tabela[vec_enc].cor;
                                cout << " " << tabela[vec_enc].portas;
                                cout << " " << tabela[vec_enc].placa;
                                cout << " " << tabela[vec_enc].valor << endl;
                            }else{
                                cout << endl << "Nenhum veículo com essa placa foi encontrado!";
                                break;
                            }
                            
                            cout << endl << "Deseja excluir o veículo encontrado?: ";
                            cin >> exc_vec;
                            
                            
                            if(exc_vec == "Sim" || exc_vec == "SIM" || exc_vec == "sim"){
                                tabela[vec_enc].valido = false;
                                qtdcarros--;
                                cout << endl << "O veículo foi excluído com sucesso!" << endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            // Buscar veículo pelo tipo
                            string enc_tipo;
                            int tipo_enc = -1;
                            cout << endl << "Insira o tipo do(s) veículo(s) que deseja encontrar: ";
                            cin >> enc_tipo;
                            cout << endl << endl << "O(s) veículo(s) encontrado(s) foi(foram):" << endl;
                            for(i = 0; i < qtdcarros; i++){
                                if(enc_tipo == tabela[i].tipo){
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
                                    cout << " " << tabela[i].valor << endl;
                                    tipo_enc++;
                                }
                            }
                            
                            if(tipo_enc <= 0){
                                cout << endl << "Nenhum veículo com o tipo selecionado foi encontrado!" << endl;
                            }
                        
                            break;
                        }
                        case 3:
                        {
                            // Buscar veículo pelo câmbio
                            string enc_cambio;
                            cout << endl << "Insira o tipo de câmbio do(s) veículo(s) que deseja encontrar: ";
                            cin >> enc_cambio;
                            cout << endl << endl << "O(s) veículo(s) encontrado(s) foi(foram):" << endl;
                            for(i = 0; i < qtdcarros; i++){
                                if(enc_cambio == tabela[i].cambio){
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
                                    cout << " " << tabela[i].valor << endl;
                                }
                            }
                        
                            break;
                        }
                        case 4:
                        {
                            // Buscar veículos por faixa de preço
                            int p_min = 0, p_max = 0, enc_p = 0;
                            cout << endl << "Insira o valor mínimo desejado: ";
                            cin >> p_min;
                            cout << endl << "Insira o valor máximo desejado: ";
                            cin >> p_max;
                            for(i = 0; i < qtdcarros; i++){
                                if(tabela[i].valor >= p_min && tabela[i].valor <= p_max){
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
                                    cout << " " << tabela[i].valor << endl;
                                    enc_p++;
                                }
                            }
                            if(enc_p <= 0){
                                cout << endl << "Nenhum veículo foi encontrado dentro dessa faixa de preço!" << endl;
                            }
                            
                            break;
                        }
                    }
                }while(opbusca != 5);    
            }
            case 4:
            {
                // Exibir Relatório do Banco de Dados
                // (% de veículos por tipo)
                float qtd_hatch = 0, qtd_suv = 0,qtd_pickup = 0,qtd_sedan = 0,qtd_van = 0;
                cout << endl << "Relatório Banco de Dados" << endl;
                cout << endl << "Dividindo os veículos por tipos, temos que:" << endl;
                for(i = 0; i < qtdcarros; i++){
                    if(tabela[i].tipo == "Hatch" || tabela[i].tipo == "HATCH" || tabela[i].tipo == "hatch"){
                        qtd_hatch++;
                    }else if(tabela[i].tipo == "Suv" || tabela[i].tipo == "SUV" || tabela[i].tipo == "suv"){
                        qtd_suv++;
                    }else if(tabela[i].tipo == "Pick-up" || tabela[i].tipo == "PICK-UP" || tabela[i].tipo == "pick-up"){
                        qtd_pickup++;
                    }else if(tabela[i].tipo == "Sedan" || tabela[i].tipo == "SEDAN" || tabela[i].tipo == "sedan"){
                        qtd_sedan++;
                    }else if(tabela[i].tipo == "Van" || tabela[i].tipo == "VAN" || tabela[i].tipo == "van"){
                        qtd_van++;
                    }
                }
                qtd_hatch = (qtd_hatch / qtdcarros) * 100;
                qtd_suv = (qtd_suv / qtdcarros) * 100;
                qtd_pickup = (qtd_pickup / qtdcarros) * 100;
                qtd_sedan = (qtd_sedan / qtdcarros) * 100;
                qtd_van = (qtd_van / qtdcarros) * 100;

                cout << endl << "Tipo Hatch: " << qtd_hatch << "%";
                cout << endl << "Tipo SUV: "  << qtd_suv << "%";
                cout << endl << "Tipo Pick-Up: " << qtd_pickup << "%";
                cout << endl << "Tipo Sedan: " << qtd_sedan << "%";
                cout << endl << "Tipo Van: " << qtd_van << "%" << endl;
                
                // Exibindo a % de veículos pelo tipo de combustível
                float qtd_flex = 0, qtd_diesel = 0, qtd_gasolina = 0;
                cout << endl << "Dividindo os veículos pelo tipo de combustível, temos:" << endl;
                for(i = 0; i < qtdcarros; i++){
                    if(tabela[i].combustivel == "Flex"){
                        qtd_flex++;
                    }else if(tabela[i].combustivel == "Diesel"){
                        qtd_diesel++;
                    }else if(tabela[i].combustivel == "Gasolina"){
                        qtd_gasolina++;
                    }
                }
                qtd_flex = (qtd_flex / qtdcarros) * 100;
                qtd_diesel = (qtd_diesel / qtdcarros) * 100;
                qtd_gasolina = (qtd_gasolina / qtdcarros) * 100;

                cout << endl << "Flex: " << qtd_flex << "%";
                cout << endl << "Diesel: " << qtd_diesel << "%";
                cout << endl << "Gasolina: " << qtd_gasolina << "%" << endl;
                
                // Veículo 1.0 mais barato + financiamento em 60 meses
                int k = qtdcarros - 1;
                int valor_mb;
                for( i = 0; i < qtdcarros; i++){
                    if(tabela[i].potencia == 1.0){
                        if(tabela[i].valor <= tabela[k].valor){
                            k = i;
                        }
                    }
                }

                cout << endl << "O veículo 1.0 mais barato é o:" << endl;
                cout << endl << tabela[k].modelo;
                cout << " " << tabela[k].marca;
                cout << " " << tabela[k].tipo;
                cout << " " << tabela[k].ano;
                cout << " " << tabela[k].quilometragem;
                cout << " " << tabela[k].combustivel;
                cout << " " << tabela[k].cambio;
                cout << " " << tabela[k].direcao;
                cout << " " << tabela[k].cor;
                cout << " " << tabela[k].portas;
                cout << " " << tabela[k].placa << endl;

                // Foi considerado uma taxa de 1.63% ao mês em juros, conforme a média de instituições privadas em 2024
                valor_mb = (tabela[k].valor * 1.63) / 60;
                cout << endl << "Saindo em um financiamento total por 60 prestações de: R$" << valor_mb << endl;

                // Veículo mais caro com direção hidraúlica, câmbio automático + valor do seguro estimado
                int l = qtdcarros - 1;
                int valor_mc;
                for( i = 0; i < qtdcarros; i++){
                    if(tabela[i].direcao == "Hidráulica" && tabela[i].cambio == "Automático"){
                        if(tabela[i].valor >= tabela[l].valor){
                            l = i;
                        }
                    }
                }
                cout << endl << "O veículo completo com direção hidráulica e câmbio automático mais caro é o:" << endl;
                cout << endl << tabela[l].modelo;
                cout << " " << tabela[l].marca;
                cout << " " << tabela[l].tipo;
                cout << " " << tabela[l].ano;
                cout << " " << tabela[l].quilometragem;
                cout << " " << tabela[l].potencia;
                cout << " " << tabela[l].combustivel;
                cout << " " << tabela[l].cambio;
                cout << " " << tabela[l].direcao;
                cout << " " << tabela[l].cor;
                cout << " " << tabela[l].portas;
                cout << " " << tabela[l].placa << endl;

                // Foi considerada uma taxa média de 6,6% sobre o valor total do carro como taxa do seguro
                valor_mc = (tabela[l].valor * 0.066) + tabela[l].valor;
                cout << endl << "Saindo, já com o seguro imbutido, por um preço de: R$" << valor_mc << endl;
                break;
            }
        }
    }while(opcao != 5); 

    return 0;
 }
