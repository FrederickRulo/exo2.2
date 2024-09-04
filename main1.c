#include "prototype1.h"

int main() {
    char cidr[20];  
    char ip[16];    
    int prefixe;    
    char masque[16]; 
    char broadcast[16]; 
    int nombreMachines; 

   
    saisirCIDR(cidr);
    extraireCIDR(cidr, ip, &prefixe);
    calculerMasqueEtBroadcast(prefixe, masque, broadcast);
    nombreMachines = calculerNombreMachines(prefixe);
    afficherResultat(ip, prefixe, masque, broadcast, nombreMachines);

    return 0;
}
