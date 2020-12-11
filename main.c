#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonction pour ecrire le binaire traduit
void ecriture_fichier_binaire (int tab[8]){
    FILE *ptrFic = fopen("SortieAlice.txt","a"); // Fichier ou on écrit le resultat
    if(ptrFic==NULL)
    {
        printf("Erreur de mémoire");
        //exit(1);
    }
    int i=0;
    for (i=0;i<8;i++){
        fprintf(ptrFic,"%d",tab[i]); // Affichage du binaire dans le bon ordre
    }
    fclose(ptrFic);
}
// Fonction pour convertir lettre en binaire
void conversion_char_binaire(int lettre){
    int tab[8];
    int i;
    for(i=7;i>-1;i--){ // Calcul de l'exposant / nombre pour savoir si c'est 0 ou 1
        if (lettre >= pow(2,i)){
            lettre = lettre - pow(2,i);
            tab[7-i] = 1;
        }
        else {
            tab[7-i] = 0;
        }
    }
    ecriture_fichier_binaire(tab);
}
// Fonction pour lire le fichier
void lire_texte_lettre(void){
    FILE *ptrFic = fopen("Alice.txt","r"); // Fichier a lire le texte a traduire
    int lettre = 0;
    while ((lettre = fgetc(ptrFic)) != EOF ){ // EOF = tant qu'on arrive pas a la fin
        conversion_char_binaire(lettre);
    }
    if (ptrFic==NULL) {
        printf("Erreur de mémoire");
        //exit(1);
    }
    fclose(ptrFic);
}
void taille_fichier() {

 int compteur = 0;
 FILE *ptrFic = fopen("SortieAlice.txt","r");

   while(fgetc(ptrFic) != EOF)
   {
       compteur ++; /* incrémentation du compteur */
   }

 printf("Le nombre de caracteres du fichier est de : %d\n", compteur);
 fclose(ptrFic);

 return 0;
}

int main(){
    lire_texte_lettre();
    taille_fichier();
}
