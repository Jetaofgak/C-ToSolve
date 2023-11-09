#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur
{
private:
    string NomAuteur;
    bool prime;
public:
    Auteur(string n,bool p = false)
    {
        NomAuteur = n;
        prime = p;
    }

    string getNom()const {return NomAuteur;}
    bool getPrix() const {return prime;}



};

class Oeuvre
{
private:
    string titre;
    const Auteur &auteur;
    string langue;
public:
    Oeuvre(const string &t, const Auteur &a,const string &l):
        titre(t),
        auteur(a),
        langue(l)
    {

    }
    string getTitre()const {return titre;}
    const Auteur& getAuteur() const {return auteur;}
    string getLangue() const {return langue;}
};

class Exemplaire
{
private:
    const Oeuvre &refOeuvre;
public:
    Exemplaire(const Oeuvre &oe) : refOeuvre(oe)
    {

        cout << "Nouvelle exemplaire de : " << refOeuvre.getTitre() << ", " << refOeuvre.getAuteur().getNom() << ", en " << refOeuvre.getLangue() << endl;
    }

    Exemplaire(const Exemplaire &ex) : refOeuvre(ex.GetOeuvre())
    {
        cout << "Copie d'un exemplaire de : " << refOeuvre.getTitre() << ", " << refOeuvre.getAuteur().getNom() << ", en " << refOeuvre.getLangue() << endl;
    }
    ~Exemplaire()
    {
        cout<< "Un exemplaire de :"<<refOeuvre.getTitre()<<", "<<refOeuvre.getAuteur().getNom()<<", en " << refOeuvre.getLangue()<<" a été jeté !"<<endl;
    }
    const Oeuvre &GetOeuvre() const { return refOeuvre; }
};

class Bibliotheque
{
private:

    string name;
    vector<Exemplaire> Expl;
public:
    Bibliotheque(string n):name(n)
    {

        cout << "La bibliothèque "<<name<<" est ouverte"<<endl;

    }
    ~Bibliotheque()
    {
        int i=0;
        cout<<"La bibliothèque "<<name <<"ferme ses portes, et détruit ses exemplaires :"<<endl;
        while(!Expl.empty())
        {

            cout<<"Un exemplaire de \""<<Expl[i].GetOeuvre().getTitre()<<", "<<Expl[i].GetOeuvre().getAuteur().getNom()<<", en "<<Expl[i].GetOeuvre().getLangue()<<endl;
            Expl.erase(Expl.begin());
            i++;
        }

    }
    string getNom()const {return name;}
    void stocker(Oeuvre o,int nbr = 1)
    {
        for(int i = 0;i<nbr;i++)
        {
            Exemplaire ex(o);
            Expl.push_back(ex);
        }
    }


    void lister_exemplaires(string langue = "Def")
    {
        if(langue == "Def")
        {
            for(int i = 0;i<Expl.size();i++)
            {


                cout << "Exemplaire de : " << Expl[i].GetOeuvre().getTitre()<<", "<<Expl[i].GetOeuvre().getAuteur().getNom()<<", en "<<Expl[i].GetOeuvre().getLangue()<<endl;

            }

        }
        else
        {
            for(int i = 0;i<Expl.size();i++)
            {
                if(Expl[i].GetOeuvre().getLangue() == langue)
                {
                    cout << "Exemplaire de : " << Expl[i].GetOeuvre().getTitre()<<", "<<Expl[i].GetOeuvre().getAuteur().getNom()<<", en "<<Expl[i].GetOeuvre().getLangue()<<endl;
                }
            }
        }
    }

    void afficher_auteurs(bool prime = false)
    {
        if(prime)
        {

            for(int i=0;i<Expl.size();i++)
            {
                if(Expl[i].GetOeuvre().getAuteur().getPrix())
                {
                    cout << Expl[i].GetOeuvre().getAuteur().getNom() << endl;
                }
            }
        }
        else
        {
           for(int i=0;i<Expl.size();i++)
            {
                cout << Expl[i].GetOeuvre().getAuteur().getNom() << endl;
            }
        }
    }
    int compter_exemplaires(Oeuvre o)
    {
        int compte = 0;
        for(int i=0;i<Expl.size();i++)
        {
            if(Expl[i].GetOeuvre().getTitre() == o.getTitre())
            {
                compte++;
            }

        }
        return compte;
    }

};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les MisÃ©rables"           , a1, "franÃ§ais" ),
         o2("L'Homme qui rit"          , a1, "franÃ§ais" ),
         o3("Le Comte de Monte-Cristo" , a2, "franÃ§ais" ),
         o4("Zazie dans le mÃ©tro"      , a3, "franÃ§ais" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothÃ¨que " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs Ã  succÃ¨s sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
