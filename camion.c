#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	char numero[20];
	int  anne;
	char marque[20];
	char model[20];
	int prix;
}camion;

//Remplir les camion
void remplir(camion t[],int n) {
	int i;
	for(i=0;i<n;i++)
	{
		printf("Camion numero --> %d <--\n\n",i+1);
		printf("Veuillez saisir le numero d'immatriculation :");
		scanf("%s",t[i].numero);
		printf("Veuillez donner l'anne de sortie du  camion :");
		scanf("%d",&t[i].anne);
		printf("Veuillez donner la marque du camion :");
		scanf("%s",t[i].marque);
		printf("Veuillez donner le modele du camion :");
		scanf("%s",t[i].model);
		printf("Veuillez donner le prix du camion :");
		scanf("%d",&t[i].prix);
	}
		
}

//Trier
void trier(camion t[],int n) {
	int i,j,test;
	camion x;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			test=strcmp(t[i].marque,t[j].marque);
			if(test<0||test==0&&t[i].prix>t[j].prix)
			{
				x=t[i];
				t[i]=t[j];
				t[j]=x;
			}
		}			
	}	
		
}

//Afficher les camion
void affiche(camion t[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
    printf("Camion numero --> %d <--\n\n\n",i+1);
	printf(">--> le numero d immatriculation    >-->%s\n",t[i].numero);
	printf(">-->donner l anne du camion         >-->%d\n",t[i].anne);
	printf(">-->donner la marque du camion      >-->%s\n",t[i].marque);
	printf(">-->donner le modile du camion      >-->%s\n",t[i].model);
	printf(">-->donner le prix du camion        >-->%d\n",t[i].prix);
	printf("________________\n\n");
				
	}
}

//Les camion plus de 10 ans
void  compte_camion (camion t[],int n)
{
	int i,cp=0,aff;
	for(i=0;i<n;i++)
	{
		if(2021-t[i].anne>10)
			cp++;
	}	 
	if(cp==0)
	{
		printf("___________________\n");
		printf("   >>->>>aucun camion plus de 10 ans dans le garage<<<-<<");
		printf("___________________\n");	
	}
	else
	{
		printf("___________________\n");
		printf(">>--->les camion plus de 10 ans sont :\t||--< %d >--||\n",cp);
		printf("___________________\n");
	}
	printf("Si vous voulez Afficher/Quitter ces info press 1/0\n\nVotre choix --> ");
	scanf("%d",&aff);
	if (aff == 1)
	{
		for(i=0;i<n;i++)
		{
			if(2021-t[i].anne>10)
			{	printf("___________________\n");
				printf(">-->le numero d immatriculation    >-->%s\n",t[i].numero);
				printf(">-->L'anne du camion         >-->%d\n",t[i].anne);
				printf(">-->La marque du camion      >-->%s\n",t[i].marque);
				printf(">-->Le modile du camion      >-->%s\n",t[i].model);
				printf(">-->Le prix du camion        >-->%d\n",t[i].prix);
				printf("___________________\n");
			}
		}		
	}
	printf("Press any key to go back !\n");	
}

//Rechercher un camion par son numero d'immatriculation
void  rechercher (camion t[],int n,int pos)
{
	int i;
	int test,cp=0;
	char cami[20];
	printf("\n\n||--->>Veuillez donner le numero d immatriculation  du camion :\t")	;
	scanf("%s",cami);
	for(i=0;i<n;i++)
	{
	    test=strcmp(t[i].numero,cami);
		if(test==0)
		{
			printf("________________\n");
			printf(">--> le numero d immatriculation    >-->%s\n",t[i].numero);
			printf(">-->donner l anne du camion         >-->%d\n",t[i].anne);
			printf(">-->donner la marque du camion      >-->%s\n",t[i].marque);
			printf(">-->donner le modile du camion      >-->%s\n",t[i].model);
			printf(">-->donner le prix du camion        >-->%d\n",t[i].prix);
			printf("________________\n");
			cp++;	
			pos=i;	
		}			
	}
	if(cp==0)
	{
		pos=-1;
		printf("___________________\n");
		printf("  >>--->ce camion ne trouve pas dans le garage<---<<\n");
		printf("___________________\n");
			
	}
}

//Modifier un camion
void  mod_camion (camion t[],int n)
{
	int pos;
	rechercher(t,n,pos);
    camion ele;
	if(pos!=-1)
	{
        printf("---------- Modifier le camion ----------\n\n");
		printf(">--->>Veullez saisir le numero d immatriculation\n\t>-->");
		scanf("%s",ele.numero);
		printf(">-->>Veullez donner l anne du camion\n\t>-->");
		scanf("%d",&ele.anne);
		printf(">--->>Veullez donner la marque du camion\n\t>-->");
		scanf("%s",ele.marque);
		printf(">--->>Veullez donner le modile du camion\n\t>-->");
		scanf("%s",ele.model);
		printf(">--->>Veullez donner le prix du camion\n\t>-->");
		scanf("%d",&ele.prix);
		printf("_______________\n");
		t[pos]=ele;	
	}			
}

//Supprimer un camion
int  supprimer (camion t[],int n,char supp[])
{
	int i,j;
	int test,c=0;
	for(i=0;i<n;i++)
	{
	   	test=strcmp(t[i].numero,supp);
		if(test==0)
		{
			for(j=i;j<n;j++)
			{
				t[j]=t[j+1];	
			}
			n--;	
		}		
	}
	return n;	
}

//Ajouter un camion
int ajouter(camion t[],int n)
{
 	n++;
 	int i,j;
 	camion eleme;
	printf("_______________\n");
	printf(">--->>Veuillez saisir le numero d immatriculation\n\t>-->");
	scanf("%s",eleme.numero);
    printf(">-->>Veuillez donner l anne du camion\n\t>-->");
	scanf("%d",&eleme.anne);
	printf(">--->>Veuillez donner la marque du camion\n\t>-->");
	scanf("%s",eleme.marque);
	printf(">--->>Veuillez donner le modile du camion\n\t>-->");
	scanf("%s",eleme.model);
	printf(">--->>Veuillez donner le prix du camion\n\t>-->");
	scanf("%d",&eleme.prix);
	printf("_______________\n");
				
	int cp=0;
	for(i=0;i<n;i++)
	{		
		int test=strcmp(t[i].marque,eleme.marque);
		if(test>0||test==0&&t[i].prix>eleme.prix)
		{
			for(j=n-1;j>=i+1;j--)
			{
				t[j]=t[j-1];
			}											
		}
									
		}
		if(cp==0)
		{
			t[n-1]=eleme;
		}
		return n;	
}

// Les camion disponible sur son budjet
void  prix (camion t[],int n ,int min,int max)
{
	int i,cp=0;
	 
	for(i=0;i<n;i++)		
	{
		if(min<=t[i].prix&&t[i].prix<=max) 
		{
	 		printf("________________\n");
			printf(">--> le numero d immatriculation    >-->%s\n",t[i].numero);
			printf(">-->donner l anne du camion         >-->%d\n",t[i].anne);
			printf(">-->donner la marque du camion      >-->%s\n",t[i].marque);
			printf(">-->donner le modile du camion      >-->%s\n",t[i].model);
			printf(">-->donner le prix du camion        >-->%d\n",t[i].prix);
			printf("________________\n");	
			cp++;	
		}
				
	}
	if(cp==0)
	{
		printf("___________________\n");
		printf("\n>>--->aucun camion avec ce prix dans le garage<----<<\n");
		printf("___________________\n");
	}					
}
int	main(){
	int choix,n=100;
	camion t[n];
	
	printf("\n--------------- Donner le nombre des Camions dans le garage -----------\n\n\t\t\t\t    ");
	scanf("%d",&n);
	system("cls");
	do{
		system("cls");
		printf("\n\t\t\t\t   MENU\n\t\t\t\t --------\n\n\n1-Ajouter   un camion\t\t\t\t\t2-Les camions disponibles\n\n3-Modifier  un camion\t\t\t\t\t4-Rechercher un camion par son numero d'immatriculation\n\n5-Supprimer un camion\t\t\t\t\t6-Le nombre de camions > 10 ans\n\n7-Remplir\n\n\n\t\t\t\t 8-Quitter\n\nVotre choix --> ");
		scanf("%d",&choix);
		system("cls");
		switch(choix) {
			case 1:
				n = ajouter(t,n);
				break;
			case 2:{
				affiche(t,n);
				getch();
				break;
			}
			case 3:{
				mod_camion(t,n);
				getch();
				break;
			}
				
			case 4:{
				int pos;
				rechercher(t,n,pos);	
				getch();
				break;
			}
				
			case 5:{
				char val[20];
				printf("||--->>donner le numero d immatriculation  du camion pour supprimer\t:");
				scanf("%s",val);
				n = supprimer(t,n,val);
				break;
			}
			case 6:{
				compte_camion(t,n);
				getch();
				break;
			}
			case 7:{
				remplir(t,n);
				trier(t,n);
				break;
			}
			case 8:{
				int min,max;
				printf("\n\n||--->>donner le prix min\t:");
				scanf("%d",&min);
				printf("||--->>donner le prix max\t:");
				scanf("%d",&max);				
				rechercherprix(t,n,min,max);
				getch();
				break;
			}
			default:
				break;
		}
	}while(choix!= 9);
	return 0;
}
