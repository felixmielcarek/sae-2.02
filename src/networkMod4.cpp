/**
 *\file netwotkMod4.cpp
 *\brief code de la classe NetworkMod4 ainsi que de ses méthodes. 
 */

#include "networkMod4.hpp"
#include "cityMod4.hpp"
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

namespace aerial_network{
    /**
     *\brief constructeur de NetworkMod4
     *\author MIELCAREK Félix
     */
    NetworkMod4::~NetworkMod4(){
        for ( vector<City*>::iterator i = cities.begin(); i != cities.end(); ++i ){
            delete *i;
        }
        cities.clear();
    }

    /**
     *\brief fonciton interactive permmettant des créer dynamiquement des CityMod4 et de les ajouter au 
     *\brief conteneur 'cities' de NetworkMod4
     *\author MIELCAREK Félix
     */
    void NetworkMod4::addCities(){
        string tmpName;
        City* c;
        
        cout << "Entrez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
        cin >> tmpName;

        while(tmpName != "-1"){
            c = new CityMod4{tmpName,static_cast<int>(cities.size())};
            cities.push_back(c);
            cout << "Entrez '-1' si vous ne souhaitez pas rajouter de ville," << endl;
            cout << "ou tapez le nom de la ville numéro "<< (cities.size()+1) << " : ";
            cin >> tmpName;
        }

        int cs = static_cast<int>(cities.size());
        for(int i=0; i<cs;i++){
            vector<bool> tmpV;
            tmpV.resize(cs);
            for(int y=0 ; y<cs ; y++){
                tmpV[y]=false;
            }
            matrix.push_back(tmpV);
        }

        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            CityMod4* tmpPtr=dynamic_cast<CityMod4*>(*it);
            tmpPtr->initDest(this);
        }
    }

    /**
     *\brief fonciton permmettant des créer dynamiquement des CityMod1 par défaut et de les ajouter au 
     *\brief conteneur 'cities' de NetworkMod4
     *\author MIELCAREK Félix
     */
    void NetworkMod4::defaultCityMod4(){
        cities.push_back(new CityMod4{"Lyon",0});
        cities.push_back(new CityMod4{"Clermont-Ferrand",1});
        cities.push_back(new CityMod4{"Castres",2});
        cities.push_back(new CityMod4{"Albi",3});
        cities.push_back(new CityMod4{"Perpignan",4});
        cities.push_back(new CityMod4{"Paris",5});
        cities.push_back(new CityMod4{"Toulouse",6});
        cities.push_back(new CityMod4{"Nantes",7});
        cities.push_back(new CityMod4{"Strasbourg",8});
        cities.push_back(new CityMod4{"Marseille",9});
        cities.push_back(new CityMod4{"Bordeaux",10});
        cities.push_back(new CityMod4{"Grenoble",11});
        cities.push_back(new CityMod4{"Bayonne",12});
        cities.push_back(new CityMod4{"Lille",13});
        cities.push_back(new CityMod4{"Rouen",14});
        cities.push_back(new CityMod4{"Orléans",15});

        int cs = static_cast<int>(cities.size());

        for(int i=0; i<cs;i++){
            vector<bool> tmpV;
            tmpV.resize(cs);
            for(int y=0 ; y<cs ; y++){
                tmpV[y]=false;
            }
            matrix.push_back(tmpV);
        }
        
        matrix[0][4]=true;
        matrix[0][5]=true;
        matrix[0][10]=true;
        matrix[0][11]=true;
        matrix[0][15]=true;

        matrix[1][0]=true;
        matrix[1][4]=true;
        matrix[1][5]=true;
        matrix[1][8]=true;
        matrix[1][12]=true;
        matrix[1][15]=true;

        matrix[2][0]=true;
        matrix[2][5]=true;
        matrix[2][9]=true;
        matrix[2][13]=true;

        matrix[3][1]=true;
        matrix[3][4]=true;
        matrix[4][3]=true;
        matrix[4][5]=true;
        matrix[3][9]=true;
        matrix[3][10]=true;
        matrix[4][11]=true;
        matrix[4][14]=true;

        matrix[5][0]=true;
        matrix[5][1]=true;
        matrix[5][2]=true;
        matrix[5][4]=true;
        matrix[5][6]=true;
        matrix[5][7]=true;
        matrix[5][10]=true;
        matrix[5][13]=true;
    
        matrix[6][0]=true;
        matrix[6][3]=true;
        matrix[6][7]=true;
        matrix[6][13]=true;
        
        matrix[7][1]=true;
        matrix[7][4]=true;
        matrix[7][8]=true;
        matrix[7][14]=true;

        matrix[8][2]=true;
        matrix[8][5]=true;
        matrix[8][9]=true;
        matrix[8][15]=true;

        matrix[9][6]=true;
        matrix[9][9]=true;
        matrix[9][13]=true;
        matrix[9][14]=true;

        matrix[10][1]=true;
        matrix[10][3]=true;
        matrix[10][6]=true;
        matrix[10][12]=true;

        matrix[11][2]=true;
        matrix[11][4]=true;
        matrix[11][7]=true;
        matrix[11][13]=true;

        matrix[12][3]=true;
        matrix[12][5]=true;
        matrix[12][8]=true;
        matrix[12][14]=true;

        matrix[13][4]=true;
        matrix[13][6]=true;
        matrix[13][9]=true;
        matrix[13][15]=true;

        matrix[14][0]=true;
        matrix[14][1]=true;
        matrix[14][7]=true;
        matrix[14][10]=true;

        matrix[15][2]=true;
        matrix[15][5]=true;
        matrix[15][8]=true;
        matrix[15][11]=true;
        
        cout <<endl;
    }
    
   /**
     *\brief fonction interactive demandant où l'utilisateur souhaite se rendre, et lui renvoie le nombre
     *\brief de vol nécessaire, ou bien lui dit si ce n'est pas possible.
     *\author MIELCAREK Félix 
     */
    void NetworkMod4::searchDest(){
        cout << "De quelle ville partez vous ?\n";
        int count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int start;
        cin >> start;

        if(start<0 || start>static_cast<int>(cities.size())) { throw NonExistentCityException{}; }

        cout << "Dans quelle ville allez vous ?\n";
        count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int end;
        cin >> end;

        if(end<0 || end>static_cast<int>(cities.size())) { throw NonExistentCityException{}; }

        if(start==end){ throw SamePlaceException{}; }

        vector<int> path;

        int res = matrixPath(start-1,end-1,path);

        if(res==0){ throw NonExistentPathException{cities[start-1]->getName(),cities[end-1]->getName()}; }
        if(res == 1){
            cout << "La ville " << cities[end-1]->getName() << " est accessible par les étapes suivantes : " << cities[path[0]]->getName();
            for(int i=1 ; i<static_cast<int>(path.size()) ; i++){
                cout << " - " << cities[path[i]]->getName();
            }
        }        
    }
     /**
     *\brief fonction de recherche à travers la matrice 'dest' d'un réseau NetworkMod4, le chemin le plus court, si il en existe un.
     *\param a indice de la ville dont on parcours les destinations (selon le contexte)
     *\param b indice de la ville destination
     *\param path conteneur des indices des villes 
     *\author MIELCAREK Félix
     */
    int NetworkMod4::matrixPath(int a ,const int b,vector<int>& path){
        path.push_back(a);

        // si la ville recherchée est accessible directement
        if(matrix[a][b] == true){
            return 1;
        }

        // si la ville du contexte n'a aucun départ
        vector<bool>::iterator it;
        it = find(matrix[a].begin() , matrix[a].end() , true);
        if(it == matrix[a].end()){
            return 0;
        }

        // va stocker les différents chemin pour ne garder que le plus court
        vector<vector<int>> allPaths;

        // on mémorise les valeurs initiales pour que les comparaisons de chemins se fasse avec la même base
        vector<int> path_old=path;

        // pour chaque ville (accessible ou non)
        for(int i=0 ; i<static_cast<int>(matrix.size()) ; i++){
            
            // si le chemin a déjà été parcouru on le saute
            bool skip=false;
            for(int y=0 ; y<static_cast<int>(path.size()) ; y++){
                if( i == path[y]) {
                    skip=true;
                    break;    
                }
            }
            if(skip) { continue; }

            // pour chaque chemins trouvés on appelle la fonction
            if(matrix[a][i] == true){
                int res = matrixPath(i,b,path);

                // si le chemin mène à une réussite on le mémorise pour le comparer plus tard
                if(res == 1) { 
                    allPaths.push_back(path);

                    // une fois qu'il est mémorisé on remet le chemin dans son état initiale
                    path=path_old;
                }
            }
        }

        // si il n'existe aucun chemin qui n'a pas déjà été traversé
        if(allPaths.size()==0){ return 0; }

        // on recherche le nombre d'étapes minimum
        vector<int> min=allPaths.front();        
        for(vector<vector<int>>::iterator it=allPaths.begin() ; it != allPaths.end() ; it++){
            if((*it).size() < min.size()){
                min=*it;
            }
        }
        
        path=min;

        return 1;
    }

    /**
     *\brief fonction d'affichage de la CityMod4 appellé avec toutes ses destinations possible sous formes de matrice
     *\author MIELCAREK Félix
     */
    void NetworkMod4::displayCities(){
        string empty;
        empty.resize(10,' ');
        string tabEmptyDisplay;

        if(cities.empty()){ throw NoCityException{}; }

        for(int i=0 ; i<static_cast<int>(cities.size()) ; i++){
            tabEmptyDisplay+="|\t"+empty+"\t";
        }
        tabEmptyDisplay+="\n";

        cout << "\\__________     Arrivé  " ;
        cout << tabEmptyDisplay;

        cout << "           \\___________ ";
        for(int i = 0 ; i < static_cast<int>(matrix.size()) ; i++){
            string tmpStr=cities[i]->getName();
            tmpStr.resize(10,' ');
            cout << "|\t" << tmpStr << "\t";
        }

        cout << endl << "   Départ              \\";
        cout << tabEmptyDisplay;

        for(int i=0;i<static_cast<int>(matrix.size());i++){
            string tmpStr=cities[i]->getName();
            tmpStr.resize(10,' ');

            for (int ii = 0; ii < static_cast<int>(matrix.size())+1; ii++){
                cout << "-------------------------" ;
            }            
            cout << endl << "\t" << empty << "\t";

            cout << tabEmptyDisplay;

            cout << "\t" << tmpStr << "\t";
                
            for(int y=0 ; y < static_cast<int>(matrix.size()) ; y++){
                string res;
                if(matrix[i][y]){
                    res="Accessible";
                }
                else{
                    res=" ";
                }
                res.resize(10,' ');
                
                cout << "|\t" << res << "\t";
            }
            cout << endl << "\t" << empty << "\t";
            cout << tabEmptyDisplay;
        }
    }
}
