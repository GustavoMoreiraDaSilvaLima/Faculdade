#include<stdio.h>
#include<string.h>
#define TF 9
main()
{
	float Vsaldo[TF];
	char Vnome[TF][40],nome[40];
	int COD,TL=0,i,excluir,exibir;
	
	printf("\nInsira a opcao desejada:");
	printf("\n1 - Insira um novo usuario e seu saldo");
	printf("\n2 - Exclua um usuario e seu saldo");
	printf("\n3 - consulte um usuario e seu saldo");
	printf("\n4 - Termine o programa\n");
	scanf("%d",&COD);
	while(COD!=4)
	{
		switch(COD)
		{
			case 1:
				printf("\nInsira o nome de usuario: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);
				for(i=0;i<TL;i++)
				{
					if(strcmp(nome,Vnome[i])==0)
					{
						printf("\n este usuario ja esta cadastrado\n");
						COD=0;
					}
				}
				if(COD!=0)
				{
					strcpy(Vnome[TL],nome);
					printf("\nInsira o saldo de pontos: ");
					scanf("%f",&Vsaldo[TL]);
					printf("\nCliente inserido\n");
					TL++;
				}
				break;
				
			case 2:
				printf("\nInsira o nome de usuario para ser excluido: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);
				for(i=0;i<TL;i++)
				if(strcmp(Vnome[i],nome)==0)
				{
					COD=0;
					excluir=i;
				}
				for(i=excluir;i<TL;i++)
				{
					strcpy(Vnome[i],Vnome[i+1]);
					Vsaldo[i]=Vsaldo[i+1];
				}
				TL--;
				if(COD==0)
					printf("\nUsuario Excluido\n");
				else
					printf("\nO Usuario Nao Existe\n");
				break;
				
			case 3:
				printf("\nInsira o usuario que deseja pesquisar: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);
				for(i=0;i<TL;i++)
				if(strcmp(Vnome[i],nome)==0)
					exibir=i;
				if(strcmp(Vnome[exibir],nome)!=0)
					printf("\nUsuario nao encontrado\n");
					
				if(strcmp(Vnome[exibir],nome)==0)
					printf("\no usuario %s tem %.2f no saldo de pontos\n",Vnome[exibir],Vsaldo[exibir]);
				break;
				
			default:
				printf("\nOpcao invalida");
				break;	
					
		}
		printf("\nInsira a opcao desejada:");
		printf("\n1 - Insira um novo usuario e seu saldo");
		printf("\n2 - Exclua um usuario e seu saldo");
		printf("\n3 - consulte um usuario e seu saldo");
		printf("\n4 - Termine o programa\n");
		scanf("%d",&COD);
	}
	printf("\nPrograma encerrado");
}
