
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Compte {
protected:
    string numero;
    float solde;

public:
    // Constructeur
    Compte(string num, float s) {
        numero = num;
        solde = s;
    }

    // Deposer de l'argent
    void deposer(float montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot effectue avec succes." << endl;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    // Retirer de l'argent
    void retirer(float montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        } else {
            cout << "Retrait impossible." << endl;
        }
    }

    void afficher() {
        cout << "Numero du compte : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

// Classe derivee
class CompteEpargne : public Compte {
private:
    float tauxInteret;

public:
    // Constructeur de la classe derivee
    CompteEpargne(string num, float s, float taux)
        : Compte(num, s) {
        tauxInteret = taux;
    }

    // Calculer les interets
    void calculerInteret() {
        float interet = solde * tauxInteret / 100;
        solde += interet;

        cout << "Interet ajoute : " << interet << " DH" << endl;
        cout << "Nouveau solde : " << solde << " DH" << endl;
    }
};

int main() {
    CompteEpargne c1("C123", 1000, 5);

    cout << "=== Solde initial ===" << endl;
    c1.afficher();

    cout << "\n=== Depot ===" << endl;
    c1.deposer(500);
    c1.afficher();

    cout << "\n=== Retrait ===" << endl;
    c1.retirer(200);
    c1.afficher();

    cout << "\n=== Calcul des interets ===" << endl;
    c1.calculerInteret();

    return 0;
}
