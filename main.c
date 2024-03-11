#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


/* ***** Cálcula média ***** */
    float average (float n1, float n2, float Sub);

/* ***** Verifica Substutiva ***** */
    float verif_sub (float n1, float n2, float M);

/* ***** Imprimir média ***** */
    void imprime_media(float media)
    {
        system("cls");
        printf("\nSua média foi %.2f\n", media);
    }

/* ********* MAIN PRINCIPAL ********* */
    int main(void) {
        
        system("cls");
        setlocale(LC_ALL,"Portuguese");

        int cont,Tam_Vetor; //Contador e Máximo de iterações
        float notaN1[4]; //Armazar as notas de atividade N1
        float N1,N2,S=0,Media,APS; //Recebe notas 

    //Recebe a quantidade de atividades propostas para compor a N1
        do {

            printf("\nQuantas atividades foram aplicadas na N1? ");
            printf("\nNúmero máximo de atividades permitido é 4.");
            scanf("%i",&Tam_Vetor);
            printf("\n");

        } while(Tam_Vetor<0||Tam_Vetor>4);
        
    //Recebe as notas que compõe a N1
        for (cont=0;cont<Tam_Vetor;cont++)
        {
            do {
                
                printf("Qual foi sua nota na atividade A%i? De 0 a 10", cont+1);
                scanf("%f",&notaN1[cont]);
                system("cls");

                N1 += (notaN1[cont]/Tam_Vetor)*0.4;

            } while (notaN1[cont]<0||notaN1[cont]>10);
        }
    
    //Recebe a nota da N2 e APS
        do {
            
            printf("\nQual foi sua nota na N2? De 0 a 9");
            scanf("%f",&N2);
            N2 *= 0.6;
            system("cls");

        } while (N2<0||N2>9);
        
        do {

            printf("\nQual foi sua nota na APS? Entre 0 e 1");
            scanf("%f",&APS);
            N2+=APS;
            system("cls");

        } while (APS<0||APS>1);
        

    //Chamada de Funcão average
        Media = average(N1,N2,S);
    
    //Confere se a média atingida é supior ou inferior a necessária + Vericação de Substutiva
        if (Media>=6)
        {
            imprime_media(Media);
            printf("\nParabéns! Você atingiu a média exigida para aprovação!\n");
            printf("\n");   
        } else 
            {
                Media = verif_sub(N1,N2,Media);
                
                if (Media>=6)
                {
                    imprime_media(Media);
                    printf("\nParabéns! Você atingiu a média exigida para aprovação!");
                    printf("\n");     
                } else 
                    {
                        imprime_media(Media);
                        printf("\nInfelizmente, Você não atingiu a média exigida para aprovação.");
                        printf("\n");
                    }
            }

        return 0;
    }
/* ********* FIM DO MAIN PRINCIPAL ********* */    


    //Corpo de Funcão average
    float average (float n1, float n2, float Sub)
    {   
        float MediaF;
        if (Sub==0)
        {
            MediaF = n1 + n2;
            return(MediaF);
        } else  
            {
                n2=Sub;
                MediaF = n1 + n2; 
                return(MediaF);
            }  
    }

    //Corpo de Funcão verif_sub
    float verif_sub (float n1, float n2, float M)
    {        
        float A6=0;
        char check;
        imprime_media(M);
        printf("\nMédia final inferior a necessária. ");
        printf("Realizou a substutiva? (S/N): ");
        scanf(" %c",&check);

        switch (check)
        {
        case 's':
            printf("\nQuanto tirou? ");
            scanf("%f",&A6);
            break;
        
        case 'n':
            A6=0;
            break;
        }

        M = average(n1,n2,A6);
        
        return(M);
    }