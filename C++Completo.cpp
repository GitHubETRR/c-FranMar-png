#include <iostream>
#include <stdlib.h>

using namespace std;

class Pokemon{
    private:
        const char* nombre;
        int vida;
        int ataque;
        int etapas;
    public:
        void darNombre(const char* newNombre);
        const char* conseguirNombre();
        void darVida(int newVida);
        int conseguirVida();
        void darAtaque(int newAtaque);
        int conseguirAtaque();
        void darEtapas(int newEtapas);
        int conseguirEtapas();
        Pokemon(const char* newNombre, int newVida, int newAtaque, int newEtapas); //polimorfismos, puedo escribir de diferentes modos un pokemon
        Pokemon(); //constructor default
        ~Pokemon(); //destructor
};

Pokemon::Pokemon(){
    nombre = "No identificado";
    vida = 00;
    ataque = 00;
    etapas = 00;
}
Pokemon::~Pokemon(){
    printf("Tu pokemon %s esta muerto, que descanse en pueblo lavanda \n", conseguirNombre());
}
Pokemon::Pokemon(const char* newNombre, int newVida, int newAtaque, int newEtapas){
    nombre = newNombre;
    vida = newVida;
    ataque = newAtaque;
    etapas = newEtapas;
}
void Pokemon::darNombre(const char* newNombre){nombre = newNombre;}
void Pokemon::darVida(int newVida){vida = newVida;}
void Pokemon::darAtaque(int newAtaque){ataque = newAtaque;}
void Pokemon::darEtapas(int newEtapas){etapas = newEtapas;}

const char* Pokemon::conseguirNombre(){return nombre;}
int Pokemon::conseguirVida(){return vida;}
int Pokemon::conseguirAtaque(){return ataque;}
int Pokemon::conseguirEtapas(){return etapas;}

class Pseudo : public Pokemon{
    private:
        bool pseudoIV;
    public:
        void darPseudoIV(bool newPseudoIV);
        bool conseguirPseudoIV();
};

void Pseudo::darPseudoIV(bool newPseudoIV){pseudoIV = newPseudoIV;};
bool Pseudo::conseguirPseudoIV(){return pseudoIV;};

int main(void){
    Pokemon mi_pokemon = Pokemon();
    mi_pokemon.darNombre("Dunsparce");
    mi_pokemon.darVida(82);
    mi_pokemon.darAtaque(30);
    mi_pokemon.darEtapas(2);

    Pokemon mi_pokemon1 = Pokemon("Pikachu", 60, 37, 3);

    Pseudo mi_pseudo = Pseudo();
    mi_pseudo.darNombre("Larvitar");
    mi_pseudo.darVida(121);
    mi_pseudo.darAtaque(64);
    mi_pseudo.darEtapas(3);
    mi_pseudo.darPseudoIV(true);

    //Memoria dinamica      | Gracias al new se genera un pokemon en la memoria Heap, el cual despues se elimina con delete, si no se hace el pokemon queda almacenado.
    Pokemon* mi_pokemon2 = new Pokemon("Bidoof",20,10,2);
    delete (mi_pokemon2);

    //Crear pokemones nuevos
    printf("Por la decepcion de perder a tu Pokmeon favorito, tu apreciado Bidoof, vas a un laboratorio a crear uno nuevo...\n");

    int crearPokemon;
    char newNombre[20];
    int newVida;
    int newAtaque;
    int newEtapas;
    printf("Desea crear un pokemon? (1 para si)\n");
    scanf("%d", &crearPokemon);
    if (crearPokemon == 1){
        Pokemon* mi_pokemon3 = new Pokemon();
        printf("Ingrese el nombre del pokemon\n");
        scanf("%s", newNombre);
        mi_pokemon3->darNombre(newNombre);
        
        printf("Ingrese la vida del pokemon\n");
        scanf("%d", &newVida);
        mi_pokemon3->conseguirVida();

        printf("Ingrese el ataque del pokemon\n");
        scanf("%d", &newAtaque);
        mi_pokemon3->conseguirAtaque();

        printf("Ingrese las etapas del pokemon\n");
        scanf("%d", &newEtapas);
        mi_pokemon3->conseguirEtapas();
        printf("Tu pokemon %s ha sido creado, pero debe morir, es una deformidad de la naturaleza...\n", newNombre);
        delete (mi_pokemon3);
        printf("Todos tus pokemon pasaran por el mismo destino...\n");
    }else{
        printf("Bueno no crees nada, tus pokemon sufriran las consecuencias\n");
    }

}
