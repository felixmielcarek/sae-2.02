#include "networkMod4.hpp"
#include "cityMod4.hpp"
#include <string>
using namespace std;

namespace aerial_network{
    //fel
    NetworkMod4::~NetworkMod4(){
        for ( vector<City*>::iterator i = cities.begin(); i != cities.end(); ++i ){
            delete *i;
        }
        cities.clear();
    }

    //fel
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

    //fel
    void NetworkMod4::defaultCityMod4(){
        cities.push_back(new CityMod4{"Lyon",0});
        cities.push_back(new CityMod4{"Clermont-Ferrand",1});
        cities.push_back(new CityMod4{"Castres",2});
        cities.push_back(new CityMod4{"Albi",3});
        cities.push_back(new CityMod4{"Perpignan",4});
        cities.push_back(new CityMod4{"Paris",5});

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
        matrix[1][0]=true;
        matrix[1][4]=true;
        matrix[1][5]=true;
        matrix[2][0]=true;
        matrix[2][5]=true;
        matrix[3][1]=true;
        matrix[3][4]=true;
        matrix[4][3]=true;
        matrix[4][5]=true;
        matrix[5][0]=true;
        matrix[5][1]=true;
        matrix[5][2]=true;
        matrix[5][4]=true;
        
        cout <<endl;
    }
    
    //fel
    void NetworkMod4::searchDest(){
        cout << "De quelle ville partez vous ?\n";
        int count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int start;
        cin >> start;

        cout << "Dans quelle ville allez vous ?\n";
        count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){

            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int end;
        cin >> end;

        vector<int> path;
        int steps = matrixPath(start-1,end-1,path);
    }

    //fel
    int NetworkMod4::matrixPath(int a , int b,vector<int> path){
        for(int i=0 ; i<static_cast<int>(matrix.size()) ; i++){
            if(i)
            if(matrix[a][b] == true){
                
                return 1;
            }
        }

    }

    //fel
    void NetworkMod4::displayCities(){
        string empty;
        empty.resize(10,' ');
        string tabEmptyDisplay;

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