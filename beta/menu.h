






///***********************************************************
///*	Procedure : EnTete					                **
///*	Parametre : pas de parametre					    **
///*	Traitement: elle dessine l'entete de notre interface**
///*	Utilise   : _strtime et _strdate                    **
///***********************************************************

void empty_ui()
{
	system("cls");
	system("color 70");
	char temp[128],date[128];

    _strtime( temp );

    _strdate( date );

	printf("\xc9");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

	printf("\xbb");

	printf("\n\xba %s \xba		      \xba Location voiture \xba 		   \xba %s \xba\n",temp,date);

	printf("\xc8");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xbc");

	printf("\n\n");

}



///*******************************************************
///*	Fonction  : MenuPrincipale   					**
///*	Parametre : pas de parametre					**
///*	Traitement: creation du menu principale  		**
///*	Retourne  : un entier qui est le choix          **
///*******************************************************
int MenuPrincipal()
{
	int choix;

	empty_ui();
	system("cls");
	system("color 70");

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principale \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Location..............................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Gestion clients.......................3   \xba");
	printf("\n               \xba    A propos..............................4   \xba");
	printf("\n               \xba    Quitter...............................9   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

	scanf("%d",&choix);

	return choix;
}



///*******************************************************
///*	Fonction  : MenuLocation     					**
///*	Parametre : pas de parametre					**
///*	Traitement: creation du menu location   		**
///*	Retourne  : un entier qui est le choix          **
///*******************************************************
int MenuLocation()
{
	int choix;

	empty_ui();

	printf("\n                          \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                          \xb3 Location d une voiture\xb3");
	printf("\n                          \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser contrat....................1   \xba");
	printf("\n               \xba    Louer voiture.........................2   \xba");
	printf("\n               \xba    Retourner voiture.....................3   \xba");
	printf("\n               \xba    Modifier contrat......................4   \xba");
	printf("\n               \xba    Supprimer contrat.....................5   \xba");
	printf("\n               \xba    Retour................................9   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}





///*******************************************************
///*	Fonction  : MenuGestionVoiture 					**
///*	Parametre : pas de parametre					**
///*	Traitement: creation du menu GestionVoiture		**
///*	Retourne  : un entier qui est le choix          **
///*******************************************************
int MenuGestionVoiture()
{
	int choix;

	empty_ui();

	printf("\n                          \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                          \xb3 Gestion Des Voitures  \xb3");
	printf("\n                          \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");


	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser voiture....................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n               \xba    Modifier voiture......................3   \xba");
	printf("\n               \xba    Supprimer voiture.....................4   \xba");
	printf("\n               \xba    Retour................................9   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}



///*******************************************************
///**	Fonction  : MenuGestionClient 					**
///**	Parametre : pas de parametre					**
///**	Traitement: creation du menu GestionClient		**
///**	Retourne  : un entier qui est le choix          **
///*******************************************************
int MenuGestionClient()
{
	int choix;

	empty_ui();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion client  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser client.....................1   \xba");
	printf("\n               \xba    Ajouter client........................2   \xba");
	printf("\n               \xba    Modifier client.......................3   \xba");
	printf("\n               \xba    Supprimer client......................4   \xba");
	printf("\n               \xba    Retour................................9   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}


void A_Propos()
{


	empty_ui();


	printf("\n\tFACULTE DES SCIENCES AGADIR-IBNO ZOHR");

	printf("\n\n\n\t\ttMini projet  : Gestion location de voiture");

	printf("\n\n\n\t\t\tRealiser par :\tAIT ABDELLAH Ayoub ");
	printf("\n\n\t\t\t                 \tOUMANOU Mohamed");

	printf("\n\n\n\t\t\t\tEncadrer par :\tMr. EL OUAFDI *****");

	printf("\n\n\n\n\t\t\t\t\tAnnee universitaire   2020/2021");

	printf("\n\n");
	system("pause");


}
