#include "agenda.h"
#ifdef _WIN32
#include <windows.h>
#endif


int main(){
    // Forçando UTF-8
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
    struct prova *provas = NULL;
    int quant_provas = 0;
    int option = -1;
    FILE *arquivo;
    //Carga do arquivo .txt
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
                fscanf(arquivo, "%149[^\n]\n", provas[i].desc);
                fscanf(arquivo, "%49[^\n]\n", provas[i].local);
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
            ordena_agenda(provas,quant_provas);
        }
        else{ //quant_provas == 0
            fclose(arquivo);
            printf("\nAgenda de provas vazia.\nInicializando. . .\n");
            system("pause");
        }
    }
    //Menu seletor
    while(option != 0){
        system("cls");
        printf("┌──────────────────────────────────────────────┐\n");
        printf("│           Agenda de Provas by João           │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│  1. Cadastrar Nova Prova                     │\n");
        printf("│  2. Visualizar Provas Agendadas              │\n");
        printf("│  3. Remover Prova                            │\n");
        printf("│  4. Pesquisar por Data                       │\n");
        printf("│  5. Pesquisar por Descrição                  │\n");
        printf("│  0. Sair do Programa                         │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("\n-> ");
        if(scanf("%d",&option) != 1){
            printf("\nEntrada inválida, use números.\n");
            limpa_buffer();
            system("pause");
            continue;
        }
        //início do switch case
        switch (option)
        {
        case 1:
            printf("\nCadastro de Prova.\n");
            provas = cadastra_prova(provas,&quant_provas);
            ordena_agenda(provas,quant_provas);
            break;

        case 2:
            if(quant_provas == 1){
                printf("\n%d Prova Cadastradas:\n",quant_provas);
            }
            else{
                printf("\n%d Provas Cadastradas:\n",quant_provas);
            }
            mostra_provas(provas,quant_provas);
            printf("\n");
            system("pause");
            break;

        case 3:
            printf("\nRemoção de Prova.\n");
            provas = remover_prova(provas, &quant_provas);
            break;
        
        case 4:
            printf("\nPesquisa por Data.\n");
            pesquisa_data(provas,quant_provas);
            break;
        
        case 5:
            printf("\nPesquisa por Descrição.\n");
            pesquisa_desc(provas,quant_provas);
            break;

        case 0:
            printf("\nEncerrando o programa\n");
            arquivo = fopen("agenda.txt","wt");
            if(arquivo != NULL){
                salva_arquivo(arquivo, provas, quant_provas);
                fclose(arquivo);
            }
            else{
                printf("\nErro ao abrir arquivo para escrita!\n");
            }

            if(provas != NULL){
                free(provas);
            }
            break;
        
        default:
            printf("\nOpção inválida.\n");
            system("pause");
            continue;
            break;
        }
    }
    return 0;
}