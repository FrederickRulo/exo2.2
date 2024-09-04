#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototype1.h"


void saisirCIDR(char cidr[]) {
    printf("Entrez l'adresse en notation CIDR (ex: 192.168.1.0/24) : ");
    scanf("%19s", cidr);
}


void extraireCIDR(char cidr[], char ip[], int *prefixe) {
    char *token = strtok(cidr, "/");
    strcpy(ip, token);
    token = strtok(NULL, "/");
    *prefixe = atoi(token);
}


void calculerMasqueEtBroadcast(int prefixe, char masque[], char broadcast[]) {
    unsigned int masqueBinaire = 0xFFFFFFFF;
    masqueBinaire = masqueBinaire << (32 - prefixe);

    
    sprintf(masque, "%d.%d.%d.%d",
            (masqueBinaire >> 24) & 0xFF,
            (masqueBinaire >> 16) & 0xFF,
            (masqueBinaire >> 8) & 0xFF,
            masqueBinaire & 0xFF);

    
    unsigned int adresseIP = 0;
    int octets[4];
    sscanf(masque, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    adresseIP = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    unsigned int adresseBroadcast = adresseIP | ~masqueBinaire;

   
            (adresseBroadcast >> 24) & 0xFF,
            (adresseBroadcast >> 16) & 0xFF,
            (adresseBroadcast >> 8) & 0xFF,
            adresseBroadcast & 0xFF);
}


int calculerNombreMachines(int prefixe) {
    return (1 << (32 - prefixe)) - 2;
}


void afficherResultat(char ip[], int prefixe, char masque[], char broadcast[], int nombreMachines) {
    printf("Adresse IP : %s\n", ip);
    printf("Nombre de bits réseau : %d\n", prefixe);
    printf("Masque de sous-réseau : %s\n", masque);
    printf("Adresse de broadcast : %s\n", broadcast);
    printf("Nombre de machines disponibles : %d\n", nombreMachines);
}
