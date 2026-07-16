#include "agenda.h"

int main(){
    struct prova *provas;
    int quant_provas = 0;
    FILE *arquivo;
    arquivo = fopen("agenda.txt","rt");
    if(arquivo == NULL){
        printf("\nErro ao ler agenda.");
        system("pause");
    }
    else{
        fscanf(arquivo, "%d \n", &quant_provas);
        if(quant_provas > 0){
            struct prova *temp = malloc(sizeof(struct prova) * quant_provas);
            for(int i = 0; i < quant_provas; i++){
                fscanf(arquivo, "%d %d %d \n", temp[i].data.dia, temp[i].data.mes, temp[i].data.ano);
                fscanf(arquivo, "%d %d \n", temp[i].horario_ini.hora, temp[i].horario_ini.minuto);
                fscanf(arquivo, "%d %d \n", temp[i].horario_fim.hora, temp[i].horario_fim.minuto);
                fscanf(arquivo, " %50[^\n]", temp[i].desc);
                fscanf(arquivo, " %50[^\n]", temp[i].local);
            }
        }
        else{
            printf("\nAgenda de provas vazia.\nInicializando. . .");
            system("pause");
        }
    }


    return 1;
}