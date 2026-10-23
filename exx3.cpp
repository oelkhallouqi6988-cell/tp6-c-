

#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Produit {
protected:
    string nom;
    float prix;

public:
    // Constructeur
    Produit(string n, float p) {
        nom = n;
        prix = p;
    }

    // Methode virtuelle
    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }

    // Destructeur virtuel
    virtual ~Produit() {}
};

// Classe derivee : produit alimentaire
class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, float p, string date)
        : Produit(n, p) {
        dateExpiration = date;
    }

    // Redefinition de la methode
    void afficherInfos() override {
        cout << "--- Produit alimentaire ---" << endl;
        Produit::afficherInfos();
        cout << "Date d'expiration : "
             << dateExpiration << endl;
    }
};

// Classe derivee : produit electronique
class ProduitElectronique : public Produit {
private:
    int garantie;

public:
    ProduitElectronique(string n, float p, int g)
        : Produit(n, p) {
        garantie = g;
    }

    // Redefinition de la methode
    void afficherInfos() override {
        cout << "--- Produit electronique ---" << endl;
        Produit::afficherInfos();
        cout << "Garantie : " << garantie
             << " ans" << endl;
    }
};

int main() {
    ProduitAlimentaire p1("Lait", 12.5, "30/11/2026");
    ProduitElectronique p2("Ordinateur", 6500, 2);

    p1.afficherInfos();

    cout << endl;

    p2.afficherInfos();

    return 0;
}

