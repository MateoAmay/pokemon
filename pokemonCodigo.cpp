#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string historial[100];
int totalPartidas = 0;
int Victorias = 0;
char verHistorial;
int vidaPokemon = 100;
int vidaPokemonRival = 100;
string nombreEntrenador;
int pokemonSeleccionado;
string pokemonSeleccionadoTexto;
string tipo;
int opcionAtaque;
int opcionAtaqueRival;
int placaje = 10;
int habilidadEspecial = 20;
int curacion = 15;
int volverAJugar;

int main () {

    do {

    //reiniciamos las stats
    vidaPokemon = 100;
    vidaPokemonRival = 100;

    pokemonSeleccionado = 0;
    opcionAtaque = 0;
    opcionAtaqueRival = 0;
    pokemonSeleccionadoTexto = "";
    tipo = "";

    //fin de reiniciamos las stats

    cout << "========================================" << endl;
    cout << "    Bienvenido a los duelos Pokemon!    " << endl;
    cout << "========================================" << endl;

    cout<<"ingrese tu nombre de entrenador!!:";
    getline(cin, nombreEntrenador);
    cout<<"Bienvenido "<<nombreEntrenador<<" ,selecciona el pokemon con el que estaras peleando";

    do {
        cout<<endl;
        cout << "--- Seleccione su Pokemon ---" << endl;
        cout << "1. Charmander" << endl;
        cout << "2. Pikachu"    << endl;
        cout << "3. Mewtwo"     << endl;
        cout << "4. Charizard"  << endl;
        cout << "5. Blastoise"  << endl;
        cout << "6. Eevee"      << endl;
        cout << "Opcion (1-6): ";
        cin  >> pokemonSeleccionado;

        if (pokemonSeleccionado > 0 && pokemonSeleccionado < 7){
            cout << "pokemon valido, cargando..."<<endl;
        }
        else {
            cout<<"el pokemon que haz elegido no esta en nuestro catalogo, porfavor vuelve a intentarlo"<<endl;
        }

    } while (pokemonSeleccionado <= 0 || pokemonSeleccionado >= 7);

     switch (pokemonSeleccionado) {
        case 1: pokemonSeleccionadoTexto = "Charmander"; tipo = "Fuego"; break;
        case 2: pokemonSeleccionadoTexto = "Pikachu";    tipo = "Electrico"; break;
        case 3: pokemonSeleccionadoTexto = "Mewtwo";     tipo = "Psiquico"; break;
        case 4: pokemonSeleccionadoTexto = "Charizard";  tipo = "Fuego"; break;
        case 5: pokemonSeleccionadoTexto = "Blastoise";  tipo = "Agua"; break;
        case 6: pokemonSeleccionadoTexto = "Eevee";      tipo = "Normal"; break;
    }

    cout << endl;
    cout << "Pokemon    : " << pokemonSeleccionadoTexto << endl;
    cout << "Tipo       : " << tipo << endl;
    cout << "Salud      : " << vidaPokemon << endl;
    cout<<endl;

    cout<<"estas listo para la batalla? tu contrincante te esta esperando!!!"<<endl;
    cout<<"los ataques/habilidades de tu pokemon y el pokemon rival son: "<<endl;
    cout<<"placaje"<<endl;
    cout<<"ataque especial"<<endl;
    cout<<"curacion"<<endl;
    cout<<endl;

    do {
        do {
            cout<<"es tu turno para atacar o usar la habilidad"<<endl;
            cout<<"1. Placaje              (Daño: 10)"<<endl;
            cout<<"2. Habilidad especial   (Daño: 20)"<<endl;
            cout<<"3. Curación             (Vida: +15)"<<endl;
            cout<<"Opcion (1-3): ";
            cin>>opcionAtaque;

            if (opcionAtaque >= 1 && opcionAtaque < 4){
                cout<<"movimiento valido"<<endl;
            }
            else {
                cout<<"movimiento no valido, vuelve a intentarlo"<<endl;
            }
        } while (opcionAtaque <= 0 || opcionAtaque >= 4);

    
        switch (opcionAtaque) {
            case 1:
                vidaPokemonRival = vidaPokemonRival - placaje;
                if (vidaPokemonRival < 0){
                     vidaPokemonRival = 0;
                }
                cout<<"¡Has usado Placaje! Infliges "<<placaje <<" de daño y dejaste a tu rival con "<<vidaPokemonRival<<" de vida"<<endl;
                break;
            case 2:
                vidaPokemonRival = vidaPokemonRival - habilidadEspecial;
                if (vidaPokemonRival < 0){
                     vidaPokemonRival = 0;
                }
                cout<<"¡Has usado tu ataque especial! Infliges "<<habilidadEspecial<<" de daño y dejaste a tu rival con "<<vidaPokemonRival<<" de vida"<<endl;
                break;
            case 3:
                vidaPokemon = vidaPokemon + curacion;
                if (vidaPokemon > 100){
                vidaPokemon = 100;
                }
                cout<<"¡Has usado Curación! Recuperas " << curacion << " de puntos de vida y te quedas con: "<<vidaPokemon<<" de vida"<<endl;
                break;
            default:
                cout << "Como haz llegado aqui?!"<<endl;
                break;
        }

        cout<<"turno del rival!!"<<endl;

        do {
            cout<<"controla los movimiento de tu rival para seguir jugando, estos son sus ataques/movimientos"<<endl;
            cout<<"1. Placaje              (Daño: 10)"<<endl;
            cout<<"2. Habilidad especial   (Daño: 20)"<<endl;
            cout<<"3. Curación             (Vida: +15)"<<endl;
            cout<<"Opcion (1-3): ";
            cin>>opcionAtaqueRival;

            if (opcionAtaqueRival >= 1 && opcionAtaqueRival < 4){
                cout<<"movimiento valido"<<endl;
            }
            else {
                cout<<"movimiento no valido, vuelve a intentarlo"<<endl;
            }
        } while (opcionAtaqueRival <= 0 || opcionAtaqueRival >= 4);

        switch (opcionAtaqueRival) {
            case 1:
                vidaPokemon = vidaPokemon - placaje;
                if (vidaPokemon < 0){
                     vidaPokemon = 0;
                }
                cout<<"¡Has usado Placaje! Infliges "<<placaje <<" de daño y dejaste a tu rival con "<<vidaPokemon<<" de vida"<<endl;
                break;
            case 2:
                vidaPokemon = vidaPokemon - habilidadEspecial;
                if (vidaPokemon < 0){
                     vidaPokemon = 0;
                }
                cout<<"¡Has usado tu ataque especial! Infliges "<<habilidadEspecial<<" de daño y dejaste a tu rival con "<<vidaPokemon<<" de vida"<<endl;
                break;
            case 3:
                vidaPokemonRival = vidaPokemonRival + curacion;
                if (vidaPokemonRival > 100){
                vidaPokemonRival = 100;
                }
                cout<<"¡Has usado Curación! Recuperas " << curacion << " de puntos de vida y te quedas con: "<<vidaPokemonRival<<" de vida"<<endl;
                break;
            default:
                cout << "Como haz llegado aqui?!"<<endl;
                break;
        }

        cout<<endl;
            cout<<"===== Estado de la batalla ====="<<endl;
            cout<<pokemonSeleccionadoTexto<<" tiene "<<vidaPokemon<<" HP"<<endl;
            cout<<"Pokemon rival tiene "<<vidaPokemonRival<<" HP"<<endl;
            cout<<"==============================="<<endl;
            cout<<endl;
        

    } while (vidaPokemon > 0 && vidaPokemonRival > 0);

    cout << endl;

    if (vidaPokemon <= 0){
        cout << "Has perdido la batalla." << endl;
    }
    else{
        cout << "Felicidades, has ganado la batalla." << endl;
    }

ofstream archivo("historial.txt", ios::app);

string resultado;

if (vidaPokemon > 0){
    resultado = "Gano";
    Victorias++;
}
else{
    resultado = "Perdio";
}


archivo  << "Entrenador: " << nombreEntrenador
        << " | Pokemon: " << pokemonSeleccionadoTexto
        << " | Resultado: " << resultado << endl;

archivo.close();

cout << endl;
cout << "Desea ver el historial? (S/N): ";
cin >> verHistorial;

if(verHistorial == 'S' || verHistorial == 's'){

    ifstream leerArchivo("historial.txt");

    totalPartidas = 0;

    while(getline(leerArchivo, historial[totalPartidas])){
        totalPartidas++;
    }

    leerArchivo.close();

    cout << endl;
    cout << "========= HISTORIAL =========" << endl;

    for(int i=0;i<totalPartidas;i++){
        cout << historial[i] << endl;
    }

    cout << "=============================" << endl;
    
}

cout << endl;
cout << "Victorias obtenidas: "<< Victorias << endl;
    
do{

    cout<<"Desea volver a jugar?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;

    cin>>volverAJugar;

    if(volverAJugar != 1 && volverAJugar != 2){
        cout<<"Opcion invalida"<<endl;
    }

    }while(volverAJugar != 1 && volverAJugar != 2);

    } while(volverAJugar == 1);  

    return 0;
}