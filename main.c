#include "agenda.h"

int main(){
    struct prova *provas = NULL;
    int quant_provas = 0;
    FILE *arquivo;
    arquivo = fopen("agenda.txt","rt");
    if(arquivo == NULL){
        printf("\nErro ao ler agenda.\n");
        system("pause");
    }
    else{
        if(fscanf(arquivo, "%d\n", &quant_provas) != 1){ //deve ler somente um valor
            quant_provas = 0;
            printf("\nErro: Agenda de provas corrompida.\n");
            fclose(arquivo);
            system("pause");
        }
        else if(quant_provas > 0){
            provas = malloc(sizeof(struct prova) * quant_provas);
            if(provas == NULL){
                printf("\nErro: Falha na alocação de memória.\n");
                fclose(arquivo);
                system("pause");
                return 1;
            }
            for(int i = 0; i < quant_provas; i++){
                fscanf(arquivo, "%d %d %d\n", &provas[i].data.dia, &provas[i].data.mes, &provas[i].data.ano);
                fscanf(arquivo, "%d %d\n", &provas[i].horario_ini.hora, &provas[i].horario_ini.minuto);
                fscanf(arquivo, "%d %d\n", &provas[i].horario_fim.hora, &provas[i].horario_fim.minuto);
                fscanf(arquivo, "%50[^\n]\n", provas[i].desc);
                fscanf(arquivo, "%50[^\n]\n", provas[i].local);
            }
            fclose(arquivo);
            if(quant_provas == 1){
                printf("\n1 Prova encontrada.\n");
                system("pause");
            }
            else{
                printf("\n%d Provas encontradas.\n",quant_provas);
                system("pause");
            }
        }
        else{ //quant_provas == 0
            fclose(arquivo);
            printf("\nAgenda de provas vazia.\nInicializando. . .\n");
            system("pause");
        }
    }
    return 0;
}