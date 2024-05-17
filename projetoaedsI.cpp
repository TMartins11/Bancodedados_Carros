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
#include <math.h>

using namespace std;

const int TAM = 100;

typedef struct{
    bool valido = true;
    string modelo;
    string marca;
    string tipo;
    int ano;
    int quilometragem;
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
        cout << endl << "ERRO, arquivo inicial inexistente!";
        return 1;
    }
    
    // Gerando Base Inicial de Veículos
    int qtdcarros = 0 , i = 0;
    arquivo_inicial >> tabela[i].modelo;
    while(tabela[i].modelo != "FIM"){
        if(tabela[i].valido == true){
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
                int vec_duplicado = 0;
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
                
                // Algoritmo para impedir que o usuário adicione 2 veículos com a mesma placa
                cout << endl << "Insira a placa: ";
                cin >> tabela[j].placa;
                for(i = 0; i < qtdcarros; i++){
                    if(tabela[i].placa == tabela[j].placa){
                        vec_duplicado = 1;
                    }
                }
                while(vec_duplicado != 0){
                    cout << endl << "A placa que você inseriu já pertence a outro veículo! Insira novamente: ";
                    cin >> tabela[j].placa;
                    vec_duplicado = 0;
                    for(i = 0; i < qtdcarros; i++){
                        if(tabela[i].placa == tabela[j].placa){
                            vec_duplicado = 1;
                        }
                    } 
                }

                cout << endl << "Insira o valor do veículo: ";
                cin >> tabela[j].valor;
                
                cout << endl << "Veículo adicionado com sucesso!" << endl;
                qtdcarros++;
                j++;
                tabela[j].modelo = "FIM";
                break;
            }
            case 3:
            {
                // Buscar um Veículo
                int opbusca;
                int exc_vec;
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
                            int vec_enc = 0;
                            cout << endl << "Insira a placa do veículo que deseja encontrar: ";
                            cin >> enc_placa;

                            for(i = 0; i < qtdcarros; i++){
                                if(tabela[i].valido == true){
                                    if(tabela[i].placa == enc_placa){
                                        cout << endl << "O veículo encontrado foi:" << endl;
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
                                        vec_enc = i;
                                    }
                                }
                            }
                            
                           
                            if(vec_enc == 0){
                                cout << endl << "Nenhum veículo com essa placa foi encontrado!" << endl;
                                break;
                            }
                            
                            cout << endl << "Deseja excluir o veículo encontrado?:";
                            cout << endl << "1- Sim" << endl << "2- Não" << endl;
                            cout << endl << "Escolha a opção desejada: ";
                            cin >> exc_vec;
                            while(exc_vec < 1 || exc_vec > 2){
                                cout << endl << "Opção inválida! Insira novamente: ";
                                cin >> exc_vec;
                            }
                            
                            
                            if(exc_vec == 1){
                                tabela[vec_enc].valido = false;
                                cout << endl << "O veículo foi excluído com sucesso!" << endl;
                                qtdcarros--;
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
                                if(tabela[i].valido == true){
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
                            }
                            
                            if(tipo_enc < 0){
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
                                if(tabela[i].valido == true){
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
                                if(tabela[i].valido == true){
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
                            }
                            if(enc_p <= 0){
                                cout << endl << "Nenhum veículo foi encontrado dentro dessa faixa de preço!" << endl;
                            }
                            
                            break;
                        }
                    }
                }while(opbusca != 5);
                break;
            }
            case 4:
            {
                // Exibir Relatório do Banco de Dados
                // (% de veículos por tipo)
                float qtd_hatch = 0, qtd_suv = 0,qtd_pickup = 0,qtd_sedan = 0,qtd_van = 0;
                cout << endl << "Relatório Banco de Dados" << endl;
                cout << endl << "Dividindo os veículos por tipos, temos que:" << endl;
                for(i = 0; i < qtdcarros; i++){
                    if(tabela[i].valido == true){
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
                    if(tabela[i].valido == true){
                        if(tabela[i].combustivel == "Flex"){
                            qtd_flex++;
                        }else if(tabela[i].combustivel == "Diesel"){
                            qtd_diesel++;
                        }else if(tabela[i].combustivel == "Gasolina"){
                            qtd_gasolina++;
                        }
                    }
                }
                qtd_flex = (qtd_flex / qtdcarros) * 100;
                qtd_diesel = (qtd_diesel / qtdcarros) * 100;
                qtd_gasolina = (qtd_gasolina / qtdcarros) * 100;

                cout << endl << "Flex: " << qtd_flex << "%";
                cout << endl << "Diesel: " << qtd_diesel << "%";
                cout << endl << "Gasolina: " << qtd_gasolina << "%" << endl;
                
                // Veículo 1.0 mais barato + financiamento em 60 meses
                Carro carro1_0[TAM];
                int x = 0;

                for (int i = 0; i < qtdcarros; i++) {
                    if (tabela[i].potencia == 1.0 && tabela[i].valido) {
                        carro1_0[x] = tabela[i];
                        x++;
                    }
                }

                if (x == 0) {
                    cout << endl << "Nenhum veículo 1.0 encontrado!" << endl;
                    return 0;
                }

                int v = 0;
                for (int i = 1; i < x; i++) {
                    if (carro1_0[i].valor < carro1_0[v].valor) {
                        v = i;
                    }
                }
                
                cout << endl << "O veículo 1.0 mais barato é o:" << endl;
                cout << endl << carro1_0[v].modelo;
                cout << " " << carro1_0[v].marca;
                cout << " " << carro1_0[v].tipo;
                cout << " " << carro1_0[v].ano;
                cout << " " << carro1_0[v].quilometragem;
                cout << " " << carro1_0[v].potencia;
                cout << " " << carro1_0[v].combustivel;
                cout << " " << carro1_0[v].cambio;
                cout << " " << carro1_0[v].direcao;
                cout << " " << carro1_0[v].cor;
                cout << " " << carro1_0[v].portas;
                cout << " " << carro1_0[v].placa;
                cout << " " << carro1_0[v].valor << endl;
                
                // Foi considerado uma taxa de 1.63% ao mês em juros, conforme a média de instituições privadas em 2024
                float valor_mb = carro1_0[v].valor;
                float taxa_juros = 0.0163;
                int num_prestacoes = 60;
                float juros = pow((1 + taxa_juros), num_prestacoes) * taxa_juros;
                float parcelas = pow((1 + taxa_juros), num_prestacoes) - 1;
                float prestacao = valor_mb * (juros / parcelas); 
        
                // Veículo mais caro com direção hidraúlica, câmbio automático + valor do seguro estimado
                int l = -1;
                int valor_mc;
                for(int i = 0; i < qtdcarros; i++){
                    if(tabela[i].valido == true && tabela[i].direcao == "Hidráulica" && tabela[i].cambio == "Automático"){
                        if(l == -1 || tabela[i].valor > tabela[l].valor){ 
                            l = i;
                        }
                    }
                }

                // Verifica se um carro válido foi encontrado
                if(l != -1){
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

                // Calcula o valor do carro já com o seguro imbutido
                valor_mc = tabela[l].valor * 1.066;
                cout << endl << "Saindo, já com o seguro imbutido, por um preço de: R$" << valor_mc << endl;
                }else {
                    cout << endl << "Nenhum veículo com direção hidráulica e câmbio automático foi encontrado." << endl;
                }

                // Quantidade e Média de Quilometragem(veículos com 5 anos ou mais)
                int mais5_anos = 0;
                int km_5anos = 0;
                for(i = 0; i < qtdcarros; i++){
                    if(tabela[i].valido == true && tabela[i].ano >= 2019){
                        mais5_anos++;
                        km_5anos = km_5anos + tabela[i].quilometragem;
                    }
                }
                km_5anos /= mais5_anos;
                cout << endl << "O número de carros com 5 anos ou mais é: " << mais5_anos;
                cout << endl << "Com uma média de: " << km_5anos << "KM percorridos" << endl;
                break;
            }
        }
    }while(opcao != 5); 

    // Reabrindo o arquivo para inserir nele o estado final do banco de dados, após a finalização do programa
    ofstream arquivo_final("BD_veiculos.txt");
    if(!arquivo_final.is_open()){
        cout << endl << "Erro! Arquivo final inexistente";
        return 1;
    }

    // Inserindo o estado atual do banco de dados no programa
    for(i = 0; i < qtdcarros; i++){
        if(tabela[i].valido == true){
            arquivo_final << endl << tabela[i].modelo;
            arquivo_final << " " << tabela[i].marca;
            arquivo_final << " " << tabela[i].tipo;
            arquivo_final << " " << tabela[i].ano;
            arquivo_final << " " << tabela[i].quilometragem;
            arquivo_final << " " << tabela[i].potencia;
            arquivo_final << " " << tabela[i].combustivel;
            arquivo_final << " " << tabela[i].cambio;
            arquivo_final << " " << tabela[i].direcao;
            arquivo_final << " " << tabela[i].cor;
            arquivo_final << " " << tabela[i].portas;
            arquivo_final << " " << tabela[i].placa;
            arquivo_final << " " << tabela[i].valor;
        }
    }
    arquivo_final << endl << "FIM";

    arquivo_final.close();

    return 0;
 }
