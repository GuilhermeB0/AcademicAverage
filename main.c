#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


    float CalculaMedia (float n1, float n2, float aps, int tam_vetor) {
        
        float media;
        n1=(n1/tam_vetor)*0.4;
        n2=(n2+aps)*0.6;

        media=n1+n2;

        system("cls");
        printf("Sua m�dia foi %.2f\n", media);

        return(media);
    }

    /*MAIN PRINCIPAL*/
    int main(void) {
        
        system("cls");
        setlocale(LC_ALL,"Portuguese");

        int cont,Tam_Vetor; //Contador e M�ximo de itera��es
        float notaN1[4]; //Armazar as notas de atividade N1
        float N1,N2,APS;
        float Media;
        char sub;

        //Recebe a quantidade de atividades propostas para compor a N1
        do {
            
            printf("N�mero m�ximo de atividades permitido � 4.");
            printf("\nQuantas atividades foram aplicadas na N1? ");
            scanf("%i",&Tam_Vetor);
            printf("\n");
            system("cls");
            
        } while(Tam_Vetor<0||Tam_Vetor>4);
        
        //Recebe as notas que comp�e a N1
        for (cont=0;cont<Tam_Vetor;cont++) {
            do {
                
                printf("De 0 a 10. Qual foi sua nota na atividade A%i? ", cont+1);
                scanf("%f",&notaN1[cont]);
                system("cls");
                
            } while (notaN1[cont]<0||notaN1[cont]>10);
        }

        //Soma as notas da N1
        for (cont=0;cont<Tam_Vetor;cont++) {
            N1+=notaN1[cont];
        }
    
        //Recebe a nota da N2
        do {
            
            printf("De 0 a 9. Qual foi sua nota na N2? ");
            scanf("%f",&N2);
            system("cls");

        } while (N2<0||N2>9);

        //Recebe a nota da APS
        do {

            printf("Entre 0 e 1. Qual foi sua nota na APS? ");
            scanf("%f",&APS);
            system("cls");

        } while (APS<0||APS>1);
        
        Media = CalculaMedia(N1,N2,APS,Tam_Vetor);

        if (Media>=6) {
            printf("\nParab�ns! Voc� atingiu a m�dia exigida para aprova��o!\n\n");  
        } else {
            // Se a m�dia for inferior a 6, verifica se o aluno realizou a substitutiva
            printf("\nM�dia final inferior a necess�ria. "); 
            printf("Realizou a substitutiva? (S/N): ");
            scanf(" %c",&sub);

            // Se realizou a substitutiva, o valor de N2 passa a ser a nota da substitutiva
            if (sub=='S'||sub=='s') {
                printf("\nDe 0 a 10. Qual foi sua nota na substitutiva? ");
                scanf("%f",&N2);
                
                //Valor de APS zerado, pois a substitutiva sobrescreve a N2 e APS
                APS=0;
                Media = CalculaMedia(N1,N2,APS,Tam_Vetor);

                if (Media>=6) {
                    printf("\nParab�ns! Voc� atingiu a m�dia exigida com a substitutiva!\n\n"); 
                }
            } else {
                printf("\nInfelizmente, voc� n�o atingiu a m�dia exigida para aprova��o.\n\n");
            }
        }

        return 0;
    }
    /*FIM DO MAIN*/