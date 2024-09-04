#ifndef PROTOTYPE_H
#define PROTOTYPE_H

// Fonction pour saisir l'adresse CIDR
void saisirCIDR(char cidr[]);

// Fonction pour extraire l'adresse IP et le nombre de bits réseau à partir d'une adresse CIDR
void extraireCIDR(char cidr[], char ip[], int *prefixe);

// Fonction pour calculer le masque de sous-réseau et l'adresse de broadcast
void calculerMasqueEtBroadcast(int prefixe, char masque[], char broadcast[]);

// Fonction pour calculer le nombre de machines disponibles
int calculerNombreMachines(int prefixe);

// Fonction pour afficher les résultats
void afficherResultat(char ip[], int prefixe, char masque[], char broadcast[], int nombreMachines);

#endif
