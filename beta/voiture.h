
typedef struct Voiture
        {
                int idVoiture;
                char marque[15];
                char nomVoiture[15];
                char couleur[7];
                int nbplaces;
                int prixJour;
                char EnLocation[5];

        } voiture;

typedef struct data_voiture
{
	voiture vtr;
	struct data_voiture *suivant;
} liste_vtr;



/*int ListeVide(liste_vtr *l)
{
	if(l==NULL)
		return 0;
	else
		return 1;
}*/

void Alert(char *msg)
{
	int i;


	for(i=0;i<2;i++)
	{

		system("cls");
		Sleep(450);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\a\a%s",msg);
		Sleep(450);
	}
}



///********************************************************************
///*     Fonction  : Recherche d'une voiture                         **
///*     Parametre : prend une liste et le ID                        **
///*	 Traitement: cherche une voiture en comparant l'identifiant  **
///*     Retourne  : retourne NULL si la voiture n'est pas trouvée   **
///*				 elle retourne un pointeur sur les element trouvé **
///*     Utilise   : strcpy->pour comparer						     **
///********************************************************************

liste_vtr* Recherche_Voiture(liste_vtr *l,int idVoiture)
{

	if(l == NULL)		///**** CONDITION D ARRET ****
		return NULL;

	if(l->vtr.idVoiture == idVoiture)
			{
			    return l;
			}
	else
		return Recherche_Voiture(l->suivant,idVoiture);

}



///***********************************************************
///*    Procedure : Afichage d'une voiture                  **
///*    Parametre : la structure voiture                    **
///*    Traitement: c'est une procedure qui affiche         **
///*                les champs d'une voiture            **
///***********************************************************

void Affiche_voiture(liste_vtr *aide_vtr)
{
	empty_ui();

	printf("\tIdentifiant               :  %d",aide_vtr->vtr.idVoiture);
	printf("\n\n\t\tMarque              :  %s",aide_vtr->vtr.marque);
	printf("\n\t\tNom                   :  %s",aide_vtr->vtr.nomVoiture);
	printf("\n\t\tCouleur               :  %s",aide_vtr->vtr.couleur);
	printf("\n\t\tNb place              :  %d",aide_vtr->vtr.nbplaces);
	printf("\n\t\tprix par jour         :  %s",aide_vtr->vtr.couleur);
	printf("\n\t\tLocation Statut       :  %s",aide_vtr->vtr.EnLocation);
	printf("\n\n");
	system("pause");

}


///*******************************************************
///*	Fonction  : Saisie d'une voiture				**
///*	Parametre : une liste                           **
///*	Traitement: Saisie des champs d'une voiture     **
///*	Retourne  : un element voiture                  **
///*******************************************************
liste_vtr* Saisie_info_Voiture()
{


	liste_vtr *vtr_fin=NULL;
	voiture vtr;

	empty_ui();

	vtr_fin=(liste_vtr*)malloc(sizeof(liste_vtr));

	printf("\n\n\tSaisie les info de voiture......\n");

	printf("\n\tMarque        :  ");
	scanf("%s",vtr.marque);

	printf("\tNom           :  ");
	scanf("%s",vtr.nomVoiture);

	printf("\n\tId de Voiture :  ");
	scanf("%d",&vtr.idVoiture);

	printf("\n\tCouleur       :  ");
	scanf("%s",vtr.couleur);

	printf("\n\tNb de place :  ");
	scanf("%d",&vtr.nbplaces);

	printf("\n\tPrix par jour :  ");
	scanf("%d",&vtr.prixJour);

    printf("\n\tlocation satut :  ");
    scanf("%s",vtr.EnLocation);

	vtr_fin->vtr=vtr;
	vtr_fin->suivant=NULL;


	return vtr_fin;

}


///*******************************************************
///*	Fonction  : Inserer voiture en fin          	**
///*	Parametre : liste de voiture   		            **
///*	Traitement: Inserer une voiture à la fin de la  **
///*                liste de voitures                   **
///*	Retourne  : Liste de voiture                    **
///*    Utilise   : ListeVide                           **
///*******************************************************

liste_vtr* inserer_en_fin(liste_vtr *l,liste_vtr *tmp)
{
	liste_vtr *p=NULL;

	if ( l == NULL )
		return tmp;

	p=l;
	while(p->suivant!=NULL)
	{
		p=p->suivant;
	}
	p->suivant=tmp;
	return l;
}


///***********************************************************************
///*   Fonction  : modifier voiture                                     **
///*   Parametre : Prend une liste voiture                              **
///*   Traitement: modifier une voiture					     	        **
///*   Utilise   : Elle utilise Recherche_Voiture pour trouver          **
///*               et Saisie_info_Voiture pour modifier la voiture	  	**
///*   Retourne  : la liste apres modification ou pas	                **
///***********************************************************************

liste_vtr* Modifier_info_Voiture(liste_vtr *l)
{
	liste_vtr *modif=NULL;
	//liste_vtr *vtr_modif=NULL;
	int rech_id;

	printf("\n\tDonnee identifiant du Voiture   :  ");
	scanf("%d",&rech_id);

	modif=Recherche_Voiture(l,rech_id);

	if(modif != NULL)
	{
	   empty_ui();
		printf("\n\n\n\t\tRe-saisie des info de la voiture....");
		printf("\n\tMarque        :  ");
        scanf("%s",modif->vtr.marque);

        printf("\tNom           :  ");
        scanf("%s",modif->vtr.nomVoiture);

        printf("\n\tId de Voiture :  ");
        scanf("%d",&modif->vtr.idVoiture);

        printf("\n\tCouleur       :  ");
        scanf("%s",modif->vtr.couleur);

        printf("\n\tNb de place :  ");
        scanf("%d",&modif->vtr.nbplaces);

        printf("\n\tPrix par jour :  ");
        scanf("%d",&modif->vtr.prixJour);

        printf("\n\tlocation satut :  ");
        scanf("%s",modif->vtr.EnLocation);


	}
	else
	Alert("Voiture non trouvee");

	return l;
}


liste_vtr* SupprimerPosition(liste_vtr *l,liste_vtr *supp)
{
	liste_vtr *tmp=NULL;
	tmp=l;
	while((tmp->suivant!=supp)&&(tmp!=NULL))
		tmp=tmp->suivant;

	if(tmp->suivant==supp)
	{
		tmp->suivant=supp->suivant;
		free(supp);
	}

	return l;
}



///***********************************************************************
///*   Fonction  : supprimer une voiture                                **
///*   Parametre : Prend une liste                                      **
///*   Traitement: Supprime une de voiture						        **
///*   Utilise   : Elle utilise Recherche_Voiture pour trouver          **
///*               et Supprimer_Position  pour supprimer                **
///*   Retourne  : la liste apres suppression ou pas	                **
///***********************************************************************

liste_vtr* Supprimer_Voiture(liste_vtr *l)
{
	liste_vtr *voiture_supp=NULL;
	int rech_id;

	if( l == NULL)
		Alert("Suppression impossible\n\t\t\t\tPas de voiture en stock");
	else
	{
		printf("\n\t\t\tDonner identifiant de voiture :  ");
		scanf("%d",&rech_id);

		voiture_supp=Recherche_Voiture(l,rech_id);

		if(voiture_supp==NULL)
			Alert("Voiture non trouver");
		else
		{
		    if( strcmp(voiture_supp->vtr.EnLocation,"oui") == 0)
            {
                 Alert("Supprission impossible : voiture alloue");
                 return l;
            }

            else
            {

                 if(l==voiture_supp)
                 {
                     l=l->suivant;
                     free(voiture_supp);
                 }
                 else
                 {
                     l=SupprimerPosition(l,voiture_supp);
                     Alert("Voiture supprimer");
                 }
            }
	     }

	}

	return l;
}



///*******************************************************
///*	Fonction  : Rechercher une voiture          	**
///*	Parametre : liste des voitures  et une chaine   **
///*                de caractere                        **
///*	Traitement: Rechercher une voiture  dans la     **
///*                liste des voitures                  **
///*	Retourne  : La liste des voitures si ce dernier  **
///*                 est trouvé et NULL sinon           **
///*                                                    **
///*******************************************************

liste_vtr* Recherche_Voiture_Libre(liste_vtr *t,char *nom)
{

	if(t==NULL)
	return NULL;
	if(strcmp(t->vtr.nomVoiture,nom)==0   &&   strcmp(t->vtr.EnLocation,"non")==0)
		return t;
    if(strcmp(t->vtr.nomVoiture,nom)==0   &&   strcmp(t->vtr.EnLocation,"oui")==0)
        return NULL;
	return Recherche_Voiture_Libre(t->suivant,nom);


}


