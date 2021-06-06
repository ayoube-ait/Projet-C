typedef struct {char dt[12];} date;


typedef struct{

            float numContrat;
            int idVoiture;
            int idClient;
            date debut;
            date fin;
            int coute;

              } contrat;

typedef struct data_Contrat{
	contrat contra;
	struct data_Contrat *suivant;
} liste_Contrat;







///***********************************************************
///*    Fonction  : Recherche d'un contrat          		**
///*    Parametre : liste de contrat                     	**
///*    Traitement: elle cherche un contrat celon le        **
///*            id de voiture,le nom et le prénom du client **
///*                    							        **
///*    Retourne  :	l element contrat si elle est trouvée  **
///*                et NULL sinon                           **
///*	                                                    **
///*                                                        **
///***********************************************************

liste_Contrat* Recherche_Contrat(liste_Contrat *l)
{
	liste_Contrat *aide=NULL;
	int Id;
	float num;

	printf("\n\tId de voiture louee   :  ");
	scanf("%d",&Id);
	printf("\n\tNum du contrat        :  ");
	scanf("%f",&num);
	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
			if(aide->contra.numContrat == num)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}





///***********************************************************
///*    Procedure : Afichage d'un contrat                   **
///*    Parametre : la liste contrat                    **
///*    Traitement: c'est une procedure qui affiche         **
///*                un contrat                              **
///***********************************************************


void Affiche_Contrat(liste_Contrat *crt)
{
	empty_ui();

	printf("\n\tN\xf8 du contrat   :  %.0f\n------------------------------\n",crt->contra.numContrat);

	printf("\n\n\tId Voiture         :  %d",crt->contra.idVoiture);
	printf("\n\n\tId Client            :  %d",crt->contra.idClient);

	printf("\n\n\tDebut              :  %s",crt->contra.debut.dt);
	printf("\n\n\tFin                :  %s",crt->contra.fin.dt);

	printf("\n\n\tCout location      :   %d TTC",crt->contra.coute);

	printf("\n\n");

   getch();
}

///**********************************************************
///*	Fonction  : Saisie d'un contrat  				   **
///*	Parametre : liste de client,liste de voitures      **
///*	Traitement: Saisie des champs du contrat           **
///*	Retourne  : la liste   contrat sinon retourne NULL **
///**********************************************************


liste_Contrat* saisie_Contrat(liste_vtr *l,liste_client *t)
{
    liste_Contrat *aide=NULL;

	empty_ui();
	aide=(liste_Contrat*)malloc(sizeof (liste_Contrat) );
    printf("\n\tsaisir un code contrat :");
    scanf("%f",&aide->contra.numContrat);

	aide->contra.idVoiture=l->vtr.idVoiture;
	aide->contra.idClient=t->individu.idClient;

	printf("\n\tNumero contrat : %.0f",aide->contra.numContrat);

    printf("\n\tDate du debut    :  ");
    scanf("%s",aide->contra.debut.dt);

    printf("\n\tDate retour      :  ");
    scanf("%s",aide->contra.fin.dt);

	printf("\n\tnombre jour      : ");
	scanf("%d",&aide->contra.coute);

	aide->contra.coute=(aide->contra.coute)*(l->vtr.prixJour);
	strcpy(l->vtr.EnLocation,"oui");

	return aide;

}




///***********************************************************
///*    Fonction  : Supprimer un Contrat					**
///*    Parametre : Liste de contrat et element de contrat	**
///*    Traitement: elle supprime un contrat            	**
///*    Retourne  :	La liste contrat apres suppression      **
///*                si effectuer                            **
///*	Utilise   : rien               						**
///***********************************************************


liste_Contrat* Supprimer_Contrat(liste_Contrat *l,liste_Contrat *supp,liste_vtr *t)
{
	liste_Contrat *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		l=l->suivant;
	    free(supp);
	    return l;
	}


	parc=l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		parc->suivant=supp->suivant;
		free(supp);
	}

	return l;

}





///***********************************************************
///*    fonction  : Retour d'une voiture            		**
///*    Parametre : liste de contrat, liste de voiture  ,   **
///*                et liste de client                     	**
///*    Traitement: permet de completer les champs d'un     **
///*                contrat lors du retour de la véhicule   **
///*                louée(calcul du prix total de location) **
///*                     							        **
///*    Utilise   : les fonctions de recherche:             **
///*                Recherche_Contrat,Supprimer_Voiture     **
///*                                                        **
///***********************************************************


liste_Contrat* Retour_Contrat(liste_Contrat *l,liste_vtr *t)
{
	liste_Contrat *contr=NULL;

	empty_ui();

	contr=Recherche_Contrat(l);

	if(contr==NULL)
		{Alert("Contrat non-trouve");return l;}

	else
	{

		printf("\n\tContrat numero   :  %.0f",contr->contra.numContrat);
		printf("\n\tCout    :  %d\n\n",contr->contra.coute);
		l=Supprimer_Contrat(l,contr,t);
        Alert("Contrat supprimer");
	}
	Alert("statut de la voiture est change.");
    return l;

	//getch();
}



///*******************************************************
///*    Fonction  : Modifier un contrat                 **
///*    Parametre : Liste contrat                       **
///*    Traitement: Modifie un contrat s'il existe      **
///*    Retourne  : Liste de contrat                    **
///*    Utilise   : RechercheContrat                    **
///*                                                    **
///*******************************************************

liste_Contrat* Modifier_Contrat(liste_Contrat *l)
{
	liste_Contrat *rech=NULL;

	if(l==NULL)
            {
                Alert("Pas de contrat disponible");
                return l;
            }

	rech=Recherche_Contrat(l);

	if(rech==NULL)
            {
                Alert("Contrat non-trouve");
                return l;
            }

///**************RE-SAISIE DU CONTRAT*****************

     Alert("Contrat trouvee.");
     printf("\n\tDate du debut    :  ");
     scanf("%s",rech->contra.debut.dt);
     printf("\n\tDate retour      :  ");
     scanf("%s",rech->contra.fin.dt);
     Alert("Contrat modifie");
	 return l;

}





///------------------------------------------------------------------------------------------------------------


///************************************************************
///*    Procedure : trouver une contrat a partir d Id client **
///*    Parametre : la liste contrat  et Id client           **
///*    Traitement: c'est une fonction qui renvoit un contrat**
///*                                                         **
///************************************************************






liste_Contrat* Rech_Contrat_Id(liste_Contrat *l,int Id)
{
	liste_Contrat *aide=NULL;

	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}








void Supprimer_Contrat_client(liste_Contrat **l,liste_Contrat *supp,liste_vtr *t)
{
	liste_Contrat *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==*l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		*l=(*l)->suivant;
	    free(supp);
	    return;
	}


	parc=*l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		parc->suivant=supp->suivant;
		free(supp);
	}

	return;

}

