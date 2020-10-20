#include <iostream>
#include<locale.h>
using namespace std;
//VÁRIAVEIS GLOBAIS
    int hora1,min1, dia1, mes1, horaf, minf, diaf, mesf;
    int tp_operacao;
    int carro=0,camionete=0,carrosport=0;
    int carros[45], camionetes[60],carros_sport[15];
    double faturamento=0;
    int crratend=0, veinatend=0, camioatend=0;
    double totapag;
    double horas;
    int ret;
//---------------------------------------------------

//ESTRUTURA PARA OS DADOS DOS VEICULOS
struct veiculos{
    string tipo;
    int hora;
    int minuto;
    int dia;
    int mes;
    }vei[120];



//CALCULAR AS HORAS ESTACIONADAS
double calc_horas(int h1, int hf, int m1, int mf, int d1, int df, int ms1, int msf){
       if(ms1 == msf){
            if(hf>h1 && d1==df){
                horas = hf - h1;
            }
            if(hf<h1 && d1==df){
                horas = h1 - hf;
            }
            if(hf<h1 && d1!=df){
                horas = ((df-d1) * 24) + (h1 - hf);
            }
            if(h1<hf && d1!=df){
                horas = ((df-d1)* 24) + (hf - h1);
            }
        }
        if(ms1 != msf){
                if(h1<hf && d1==df){
                    horas = ((msf-ms1) * 30) * 24;
                    horas = horas + (hf - h1);
                }
                if(h1>hf && d1 == df){
                    horas = ((msf-ms1) * 30) *24;
                    horas = horas + (h1-hf);
                }
                if(hf<h1 && d1!=df){
                    horas = ((msf-ms1) * 30) *24;
                    horas = horas + ((df-d1) * 24) + (h1 - hf);
                }
                if(hf>h1 && d1!=df){
                    horas = ((msf-ms1) * 30) *24;
                    horas = horas + ((df-d1) * 24) + (hf - h1);
                }

        }
        return horas;
}

//ENTRADA DE VEICULOS
    void  entrada (){
        for(int i =0; i<=120;i++){
        cout << "Digite o tipo de veículo(carro, carro super esportivo ou camionete): \n";
        cin >> vei[i].tipo;

        cout << "Digite o horario de entrada(hora e minuto): \n";
        cin >> vei[i].hora >> vei[i].minuto;

        cout << "Digite a data de entrada(dia e mes): \n";
        cin >> vei[i].dia >> vei[i].mes;
                                break;
        }
            cout << "**********************************************" << endl;
    }
//COLETA DE DADOS PARA RETIRADA
    void dados_para_retirada(){
            int hora1, min1,dia1,mes1;
            int horaf,minf,diaf,mesf;
            double hpg; //horas a pagar

                cout << "Digite o horário que o veículo foi deixado(hora e minuto): \n";
                cin >> hora1 >> min1;
                cout << "Digite a data que o veículo foi deixado(dia e mês): \n";
                cin >> dia1 >> mes1;

                cout << "Digite o horário da retirada(hora e minuto): \n";
                cin >> horaf >> minf;
                cout << "Digite a data da retirada(dia e mês): \n";
                cin >> diaf >> mesf;

                

                        for(int i = 0;i<=120;i++){
                          hpg = calc_horas(hora1, horaf, min1, minf, dia1, diaf, mes1, mesf);
                            if(hora1 == vei[i].hora && min1 == vei[i].minuto && dia1 == vei[i].dia && mes1 == vei[i].mes){
                                    if(vei[i].tipo == "carro"){
                                        carros[i]=0;
                                        totapag = hpg*5;
                                        cout << "Total a pagar: R$" << totapag << endl;
                                    }
                                    if(vei[i].tipo == "carro super esportivo"){
                                        carros_sport[i]--;
                                        totapag = hpg*5;
                                        cout << "Total a pagar: R$" << totapag << endl;
                                    }
                                    if(vei[i].tipo == "camionete"){
                                        camionetes[i]--;
                                        totapag = hpg*7;
                                        cout << "Total a pagar: R$" << totapag << endl;
                                    }
                                }
                            }

                        }

//-------------------------------------------------------
int main(){
    
   setlocale(LC_ALL, "Portuguese");

//LOOP PARA COLETAR OS DADOS ENQUANTO OPÇÃO DIFERENTE DE 4
while(tp_operacao !=4){
        cout << "|-------------||||AUTO PARKING||||---------------| \n";
        cout << " 1 - entrada \n 2 - retirada \n 3 - relatório \n 4 - sair \n";
        cout << "Qual o tipo de operação? \n";
        cin >> tp_operacao;

        switch (tp_operacao){
                case 1: entrada();
                      for(int i = 0;i<=120;i++){
                        //CARROS
                        if(vei[i].tipo == "carro" || vei[i].tipo == "Carro" || vei[i].tipo == "CARRO"){
                                    crratend++;
                                for(int i = 0;i<=45;i++){
                                    carros[i] = 1;
                                    carro++;
                                }
                                cout << "\n\t\t Veículo Estacionado!\n" << endl;
                                cout << "**********************************************" << endl;

                        if(i == 45){
                                    veinatend++;
                                cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                                cout << "SEM VAGAS!" << endl;
                                cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                            }
                        }
                        //CAMIONETES
                        if(vei[i].tipo == "camionete"){
                                camioatend++;
                            for(int i = 0; i<=60;i++){
                                camionetes[i] = 1;
                                camionete++;
                            }
                                cout << "\n\t\t Veículo Estacionado!\n" << endl;
                                cout << "**********************************************" << endl;
                            if(i == 60){
                                  veinatend++;
                                cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                                cout << "SEM VAGAS!" << endl;
                                cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                            }
                        }
                        //CARROS SUPER ESPORTIVOS
                        if(vei[i].tipo == "carro super esportivo"){
                                            crratend++;
                                        for(int i = 0;i<=15;i++){
                                            carros_sport[i] = 1;
                                            carrosport++;
                                        }
                                                cout << "\n\t\t Veículo Estacionado!\n" << endl;
                                                cout << "**********************************************" << endl;
                                        if(i == 15){
                                                veinatend++;
                                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                                            cout << "SEM VAGAS!" << endl;
                                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                                        }
                                    }
                                }

                        break;
                case 2: dados_para_retirada();
                        horas = calc_horas(hora1,min1, dia1, mes1, horaf, minf, diaf, mesf);
                        
                        break;
                case 3: {
                                faturamento += totapag;
                                cout << "----------------------------------------------------------" << endl;
                                cout << "******************RELATÓRIO******************** \n";
                                cout << "Faturamento total: R$" << faturamento << endl;
                                cout << "Veículos não atendidos por lotação: " << veinatend << endl;
                                cout << "Total de carros atendidos: " << crratend << endl;
                                cout << "Total de camionetes atendidas: " << camioatend << endl;
                                cout << "Faturamento médio por hora: R$" << faturamento/60 <<endl;
                                cout << "----------------------------------------------------------" << endl;
                                break;
                            }
                        
                         }


                      }  
      return 0;
}
