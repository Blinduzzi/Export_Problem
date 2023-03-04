#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class resursa_tara{
    public:
    string nume;
    int pret_baza, cantitate_detinuta = 0, cantitate_c = 0, cantitate_v = 0;
    int productie = 0, consum = 0;
    int pret_c(){
        return pret_baza- 3 - cantitate_detinuta / 5;
    }
    int pret_v(){
        return pret_baza - cantitate_detinuta / 5;
    }
};
bool comparator(resursa_tara a, resursa_tara b){
    if(a.nume < b.nume)
        return true;
    return false;
}
class resursa_prelucrata{
    public:
    string consumat, produs;
    int cant_produs, cant_consumat;
};
class Tara{
    public:
    vector<resursa_tara> resursele_tarii; 
    vector<resursa_prelucrata> prelucrari;
    string nume, comportament_c, comportament_v;
    int taxe, bani;
    int fericire;
    Tara(){
        taxe = bani = 0;
        fericire = 100;
    }
    Tara(vector<resursa_tara> res){
        resursele_tarii = res;
        fericire = 100;
        bani = 0;
        sort(resursele_tarii.begin(), resursele_tarii.end(), comparator);
    }
    friend istream& operator >> (istream& left, Tara& right)
    {   
        left >> right.nume >> right.taxe >> right.comportament_c >> right.comportament_v;
        int n;
        left >> n;
        for( int i = 0 ; i < n ; i++){
            string s;
            left >> s;
            int x;
            left >> x;
            for( int j = 0 ; j < right.resursele_tarii.size() ; j++)
                if(right.resursele_tarii[j].nume == s)
                    right.resursele_tarii[j].productie = x;
        }
        left >> n;
        for( int i = 0 ; i < n ; i++){
            string s, p;
            left >> s;
            int x, y;
            left >> x >> p >> y;
            resursa_prelucrata rp;
            rp.consumat = s;
            rp.produs = p;
            rp.cant_consumat = x;
            rp.cant_produs = y;
            right.prelucrari.push_back(rp);
        }
        left >> n;
        for( int i = 0 ; i < n ; i++){
            string s;
            left >> s;
            int x;
            left >> x;
            for( int j = 0 ; j < right.resursele_tarii.size() ; j++)
                if(right.resursele_tarii[j].nume == s)
                    right.resursele_tarii[j].consum = x;
        }
        return left;
    }
};
class Productie : public Tara{
    public:
    Productie(){
        produs = 0;
        cantitate_produsa = 0;
    }
    int produs, cantitate_produsa;
    void calc_productie(){
        cantitate_produsa = fericire * produs / 100;
    }
};
class Prelucrare : public Tara{
    public:
    string nume_produs, nume_consumat;
    int produs, consumat, cantitate_produsa, cantitate_consumata;
    void calc_prelucrare(){
        cantitate_produsa = fericire * produs / 100;
        cantitate_consumata = consumat;
        //cout << nume_consumat << endl << cantitate_consumata << endl;
    }
};
class Consum : public Tara{
    public:
    int consumat, detinut, diferenta = 0, cantitate_consumata;
    void calc_consum(){
        cantitate_consumata = consumat;
        if(consumat > detinut){
            diferenta = consumat - detinut;
            cantitate_consumata = detinut;
        }
    }
};
int main(){
    int N;
    cin >> N;
    vector <resursa_tara> resurse;
    for( int i = 0 ; i < N ; i++){
        resursa_tara x;
        cin >> x.nume;
        resurse.push_back(x);
    }
    for( int i = 0 ; i < N ; i++){
        cin >> resurse[i].pret_baza;
    }
    int bani_firma;
    cin >> bani_firma;
    int K;
    cin >> K;
    vector <Tara> tari;
    for( int i = 0 ; i < K ; i++){
        Tara x(resurse);
        cin >> x;
        tari.push_back(x);
    }
    int zile;
    cin >> zile;
    for( int i = 0 ; i < zile ; i++){
        string tara_cu_firma;
        cin >> tara_cu_firma;
        int nr_oferte_c, nr_oferte_v;
        cin >> nr_oferte_c;
        vector<resursa_tara> oferte_c;
        for( int j = 0 ; j < nr_oferte_c ;j++){
            resursa_tara x;
            cin >> x.nume >> x.cantitate_c;
            oferte_c.push_back(x);
        }
        cin >> nr_oferte_v;
        vector<resursa_tara> oferte_v;
        for( int j = 0 ; j < nr_oferte_v ;j++){
            resursa_tara x;
            cin >> x.nume >> x.cantitate_v;
            oferte_v.push_back(x);
        }
    
        for( int j = 0 ; j < K ; j++){
            tari[j].bani += tari[j].fericire * tari[j].taxe / 100;
            for( int k = 0 ; k < N ; k++){
                Productie P;
                P.produs = tari[j].resursele_tarii[k].productie;
                P.fericire = tari[j].fericire;
                P.calc_productie();
                tari[j].resursele_tarii[k].cantitate_detinuta += P.cantitate_produsa;
            }
            for( int k = 0 ; k < tari[j].prelucrari.size() ; k++){
                Prelucrare P;
                P.consumat = tari[j].prelucrari[k].cant_consumat;
                P.produs = tari[j].prelucrari[k].cant_produs;
                P.nume_consumat = tari[j].prelucrari[k].consumat;
                P.nume_produs = tari[j].prelucrari[k].produs;
                P.fericire = tari[j].fericire;
                P.calc_prelucrare();
                for( int l = 0 ; l < N ; l++){
                    if(tari[j].resursele_tarii[l].nume == P.nume_consumat){
                        if(tari[j].resursele_tarii[l].cantitate_detinuta >= P.consumat){
                            tari[j].resursele_tarii[l].cantitate_detinuta -= P.cantitate_consumata;
                            for( int m = 0 ; m < K ; m++){
                                if(tari[j].resursele_tarii[m].nume == P.nume_produs)
                                    tari[j].resursele_tarii[m].cantitate_detinuta += P.cantitate_produsa;
                            }
                        }
                    }
                }
            }
            for( int k = 0 ; k < N ; k++){
                Consum P;
                P.consumat = tari[j].resursele_tarii[k].consum;
                P.fericire = tari[j].fericire;
                P.detinut = tari[j].resursele_tarii[k].cantitate_detinuta;
                P.calc_consum();
                tari[j].resursele_tarii[k].cantitate_detinuta -= P.cantitate_consumata;
                tari[j].fericire -= P.diferenta;
            }
            tari[j].fericire += 5;
            if( tari[j].fericire > 100)
                tari[j].fericire = 100;
            if(tari[j].fericire < 50)
                tari[j].fericire = 50;
            cout << tari[j].nume << " " << tari[j].fericire << " " << tari[j].bani << endl;
            for( int k = 0 ; k < N ; k++){
                if( tari[j].resursele_tarii[k].cantitate_detinuta != 0)
                    cout << tari[j].resursele_tarii[k].nume << " " << tari[j].resursele_tarii[k].cantitate_detinuta << endl;
            }
            cout << endl;
        }
    }
    return 0;
}

/*

1. Țara primește bani din taxe.

2. Dacă firma se află în țară, se rezolvă ofertele de cumpărare.

3. Se realizează toate producțiile.

4. Se realizează toate prelucrările.

5. Se realizează tot consumul.

6. Dacă firma se află în țară, se rezolvă ofertele de vânzare.

5

LEMN PIATRA ARGILA FIER MANCARE

10 10 10 10 10

100

2

ROMANIA 30 CONSUM FARA_CONSUM

2

MANCARE 11

PIATRA 3

1

PIATRA 5 FIER 2

2

MANCARE 10

LEMN 9

BULGARIA 10 PRODUCTIE ORICE

2

LEMN 10

ARGILA 10

1

PIATRA 5 FIER 2

1

MANCARE 9

5

ROMANIA 

0 

0

ROMANIA 

0 

0

ROMANIA 

0 

0

ROMANIA 

0 

0

ROMANIA 

0 

0



Output:

NUME_ȚARA FERICIRE_ȚARA BANI_ȚARA

RESURSA_DETINUTA_1 CANTITATE_RESURSA_1
*/