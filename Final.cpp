#include<iostream>
#include<string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

string palabra_oculta;
string palabra_pantalla;
string letras_escritas;
int intentos;

void bienvenida();
void texto_adivina();
void texto_ganaste();
void texto_perdiste();
void ahorcado_ascii(int vidas);
void mostrar_pantalla();
void ingresar_usuario(char x);
void iniciar();
void fuegos_artificiales(int animacion, int linea);
void delay(int number_of_seconds);

int main(){
	bool continua;
	do{
		bienvenida();
		iniciar();
		mostrar_pantalla();
		while(intentos>0 && palabra_pantalla!=palabra_oculta){
			char x;
			cout<<"Letra que deseas ingresar: ";
			cin>>x;
			system("CLS");
			ingresar_usuario(x);
			letras_escritas+=x;
			letras_escritas+=", ";
			mostrar_pantalla();
		}
		if(intentos>0){
			texto_ganaste();
		}else{
			texto_perdiste();
		}
		cout<<"\nLa palabra era: "<<palabra_oculta<<endl;
		continua = false;
		char opcion = 'a';
		while(opcion != 'n' && opcion != 'N' && opcion != 's' && opcion != 'S'){
			cout<<"Desea jugar otra vez? (S/N): ";
			fflush(stdin);
			opcion = getchar();
			if(opcion == 'n' || opcion == 'N' || opcion == 's' || opcion == 'S'){
				if(opcion == 's' || opcion == 'S')
					continua = true;
			}else {
				system("cls");
				cout<<("Respuesta invalida, escriba 'S' o 'N'\n");
			}
		}
	}while(continua);
	return 0;
}

void mostrar_pantalla(){
	texto_adivina();
	ahorcado_ascii(intentos);
	//cout<<"\nFallos restantes: "<<intentos<<endl;
	cout<<"Letras ingresadas: "<<letras_escritas<<endl;
}

void iniciar(){
	intentos = 5;
	//palabra_oculta="SAMSUNG";
	for(int i=0;i<palabra_oculta.length();i++){
		if(palabra_oculta[i]>='A' && palabra_oculta[i]<='Z'){
			palabra_oculta[i]+=32;
		}
	}
	for(int i=0;i<palabra_oculta.length();i++){
		if(palabra_oculta[i]>='a' && palabra_oculta[i]<='z'){
			palabra_pantalla+='*';
		}else{
			palabra_pantalla+=palabra_oculta[i];
		}
	}
}

void ingresar_usuario(char x){
	bool perder_intentos=true;
	for(int i=0;i<palabra_oculta.length();i++){
		if(x==palabra_oculta[i]){
			perder_intentos=false;
			palabra_pantalla[i]=x;
		}
	}
	if(perder_intentos==true){
		intentos--;
	}
}

void bienvenida(){
	system("cls");
	texto_adivina();
	cout<<"\nEscribe la palabra oculta para que alguien la intente adivinar: ";
	palabra_pantalla = "";
	letras_escritas = "";
	cin >> palabra_oculta;
	system("cls");
}

void texto_adivina(){
	cout<< "   __    ____  ____  _  _  ____  _  _    __      __      __      ____   __    __      __    ____  ____    __   \n";	
	cout<<"  /__\\  (  _ \\(_  _)( \\/ )(_  _)( \\( )  /__\\    (  )    /__\\    (  _ \\ /__\\  (  )    /__\\  (  _ \\(  _ \\  /__\\  \n";
	cout<<" /(__)\\  )(_) )_)(_  \\  /  _)(_ (    ) /(__)\\    )(__  /(__)\\    )___//(__)\\  )(__  /(__)\\  ) _ < )   / /(__)\\ \n";
	cout<<"(__)(__)(____/(____)  \\/  (____)(_)\\_)(__)(__)  (____)(__)(__)  (__) (__)(__)(____)(__)(__)(____/(_)\\_)(__)(__)\n";

}

void texto_ganaste(){
	system("cls");
	for(int i = 0; i<15; i++){
		system("cls");
		cout<< " /$$$$$$$$        /$$ /$$           /$$   /$$                         /$$                                        \n";
		cout<< "| $$_____/       | $$|__/          |__/  | $$                        |__/                                        \n";
		cout<< "| $$     /$$$$$$ | $$ /$$  /$$$$$$$ /$$ /$$$$$$    /$$$$$$   /$$$$$$$ /$$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$$\n";
		cout<< "| $$$$$ /$$__  $$| $$| $$ /$$_____/| $$|_  $$_/   |____  $$ /$$_____/| $$ /$$__  $$| $$__  $$ /$$__  $$ /$$_____/\n";
		cout<< "| $$__/| $$$$$$$$| $$| $$| $$      | $$  | $$      /$$$$$$$| $$      | $$| $$  \\ $$| $$  \\ $$| $$$$$$$$|  $$$$$$ \n";
		cout<< "| $$   | $$_____/| $$| $$| $$      | $$  | $$ /$$ /$$__  $$| $$      | $$| $$  | $$| $$  | $$| $$_____/ \\____  $$\n";
		cout<< "| $$   |  $$$$$$$| $$| $$|  $$$$$$$| $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$|  $$$$$$/| $$  | $$|  $$$$$$$ /$$$$$$$/\n";
		cout<< "|__/    \\_______/|__/|__/ \\_______/|__/   \\___/   \\_______/ \\_______/|__/ \\______/ |__/  |__/ \\_______/|_______/ \n";
		cout<<"\n  /$$$$$$                                            /$$               /$$\n";
		cout<<" /$$__  $$                                          | $$              | $$\n";
		cout<<"| $$  \\__/  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$ | $$\n";
		cout<<"| $$ /$$$$ |____  $$| $$__  $$ |____  $$ /$$_____/|_  $$_/   /$$__  $$| $$\n";
		cout<<"| $$|_  $$  /$$$$$$$| $$  \\ $$  /$$$$$$$|  $$$$$$   | $$    | $$$$$$$$|__/\n";
		cout<<"| $$  \\ $$ /$$__  $$| $$  | $$ /$$__  $$ \\____  $$  | $$ /$$| $$_____/    \n";
		cout<<"|  $$$$$$/|  $$$$$$$| $$  | $$|  $$$$$$$ /$$$$$$$/  |  $$$$/|  $$$$$$$ /$$\n";
		cout<<" \\______/  \\_______/|__/  |__/ \\_______/|_______/    \\___/   \\_______/|__/\n";
	                                                                          
		cout<<"      .--..--..--..--..--..--.\n";
		cout<<"    .' \\  (`._   (_)     _   \\";
		fuegos_artificiales(i+1,0);
		cout<<"  .'    |  '._)         (_)  |";
		fuegos_artificiales(i+1,1);
		cout<<"  \\ _.')\\      .----..---.   /";
		fuegos_artificiales(i+1,2);
		cout<<"  |(_.'  |    /    .-\\-.  \\  |";
		fuegos_artificiales(i+1,3);
		cout<<"  \\     0|    |   ( O| O) | o|";
		fuegos_artificiales(i+1,4);
		cout<<"   |  _  |  .--.____.'._.-.  |";
		fuegos_artificiales(i+1,5);
		cout<<"   \\ (_) | o         -` .-`  |";
		fuegos_artificiales(i+1,6);
		cout<<"    |    \\   |`-._ _ _ _ _\\ /";
		fuegos_artificiales(i+1,7);
		cout<<"    \\    |   |  `. |_||_|   |\n";
		cout<<"    | o  |    \\_      \\     |     -.   .-.\n";
		cout<<"    |.-.  \\     `--..-'   O |     `.`-' .'\n";
		cout<<"  _.'  .' |     `-.-'      /-.__   ' .-'\n";
		cout<<".' `-.` '.|='=.='=.='=.='=|._/_ `-'.'\n";
		cout<<"`-._  `.  |________/\\_____|    `-.'\n";
		cout<<"   .'   ).| '=' '='\\/ '=' |\n";
		cout<<"   `._.`  '---------------'\n";
		cout<<"           //___\\   //___\\\n";
		cout<<"             ||       ||\n";
		cout<<"             ||_.-.   ||_.-.\n";
		cout<<"            (_.--__) (_.--__)\n";        
		delay(70);
	}
}

void texto_perdiste(){
	system("cls");
	cout<< "        .--'''''''''--.         __   __  _______  _______     _______  _______  ______    ______   ___   ______   _______       \n";
	cout<< "     .'      .---.      '.     |  | |  ||   _   ||       |   |       ||       ||    _ |  |      | |   | |      | |       |      \n";
	cout<< "    /    .-----------.    \\    |  |_|  ||  |_|  ||  _____|   |    _  ||    ___||   | ||  |  _    ||   | |  _    ||   _   |      \n";
	cout<< "   /        .-----.        \\   |       ||       || |_____    |   |_| ||   |___ |   |_||_ | | |   ||   | | | |   ||  | |  |      \n";
	cout<< "   |       .-.   .-.       |   |       ||       ||_____  |   |    ___||    ___||    __  || |_|   ||   | | |_|   ||  |_|  | ___  \n";
	cout<< "   |      /   \\ /   \\      |   |   _   ||   _   | _____| |   |   |    |   |___ |   |  | ||       ||   | |       ||       ||   | \n";
	cout<< "    \\    | .-. | .-. |    /    |__| |__||__| |__||_______|   |___|    |_______||___|  |_||______| |___| |______| |_______||___| \n";
	cout<< "     '-._| | | | | | |_.-'\n";
	cout<< "         | '-' | '-' |\n";
	cout<< "          \\___/ \\___/\n";
	cout<< "       _.-'  /   \\  `-._\n";
	cout<< "     .' _.--|     |--._ '.\n";
	cout<< "     ' _...-|     |-..._ '\n";
	cout<< "            |     |\n";
	cout<< "            '.___.'\n";
	cout<< "              | |\n";
	cout<< "             _| |_\n";
	cout<< "            /\\( )/\\\n";
	cout<< "           /  ` '  \\\n";
	cout<< "          | |     | |\n";
	cout<< "          '-'     '-'\n";
	cout<< "          | |     | |\n";
	cout<< "          | |     | |\n";
	cout<< "          | |-----| |\n";
	cout<< "       .`/  |     | |/`.\n";
	cout<< "       |    |     |    |\n";
	cout<< "       '._.'| .-. |'._.'\n";
	cout<< "             \\ | /\n";
	cout<< "             | | |\n";
	cout<< "             | | |\n";
	cout<< "             | | |\n";
	cout<< "            /| | |\\\n";
	cout<< "          .'_| | |_`.\n";
	cout<< "          `. | | | .'\n";
	cout<< "       .    /  |  \\    .\n";
	cout<< "      /o`.-'  / \\  `-.`o\\\n";
	cout<< "     /o  o\\ .'   `. /o  o\\\n";
	cout<< "     `.___.'       `.___.'\n";
}
void ahorcado_ascii(int vidas){
	switch(vidas){
		case 5: 
			cout<<"  +---+\n";
			cout<<"      |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"      |\n";
			cout<<"      |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<"      |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
		case 4:
			cout<<"  +---+\n";
			cout<<"  |   |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"      |\n";
			cout<<"      |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<"      |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
		case 3:
			cout<<"  +---+\n";
			cout<<"  |   |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"  O   |\n";
			cout<<"      |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<"      |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
		case 2:
			cout<<"  +---+\n";
			cout<<"  |   |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"  O   |\n";
			cout<<"  |   |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<"      |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
		case 1:
			cout<<"  +---+\n";
			cout<<"  |   |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"  O   |\n";
			cout<<" /|\\  |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<"      |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
		case 0:
			cout<<"  +---+\n";
			cout<<"  |   |        ";
			cout<<"Intentos restantes: "<<intentos<<endl;
			cout<<"  O   |\n";
			cout<<" /|\\  |        ";
			cout<<"Palabra oculta: "<<palabra_pantalla<<endl;
			cout<<" / \\  |\n";
			cout<<"      |\n";
			cout<<"=========\n";
			break;
	}
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
}

void fuegos_artificiales(int animacion, int linea){
	char texto_fuegos1[][50] = {
	" \n",
	" \n",
	" \n",
	"                     _\\/_\n",
	"                      /\\ \n",
	"                     ' \n",
	"                    . \n",
	"                    . \n"};
	
	char texto_fuegos2[][50] = {
		" \n",
		" \n",
		"                     *  *\n",
		"                    *_\\/_*\n",
		"                    * /\\ *\n",
		"                     *  *\n",
		"  \n",
		"      \n"
	};
	char texto_fuegos3[][50] = {
		" \n",
		" \n",
		"                     *  *\n",
		"                    *    * \n",
		"                    *    * _\\/_\n",
		"   _\\/_              *  *   /\\ \n",
		"    /\\ \n",
		"     \n"
	};
	
	char texto_fuegos4[][50] = {
		" \n",
		" \n",
		"                     *  *\n",
		"        _\\/_        *    * .::.\n",
		"   .''.  /\\         *     :_\\/_:\n",
		"  :_\\/_:             *  * : /\\ : \n",
		"  : /\\ :              o    '::' \n",
		"   '...' \n"
	};
	char texto_fuegos5[][50] = {
		" \n",
		" \n",
		"        .''.          *\n",
		"       :_\\/_:              .::.\n",
		"   .''.: /\\ :             :    :\n",
		"  :    :'..'         \\'/  :    :\n",
		"  :    :            = o =  '::' \n",
		"   '...'             /.\\. \n"
	};
	
	char texto_fuegos6[][50] = {
		" \n",
		"                    _\\)/_\n",
		"        .''.         /(\\ \n",
		"       :    :              _\\/_\n",
		"   .''.:    :         :     /\\ \n",
		"  :    :'..'       '.\\'/.'\n",
		"  :    :           -= o =-\n",
		"   '...            .'/.\\:\n"
	};
	
	char texto_fuegos7[][50] = {
		"                      .\n",
		"                    _\\)/_\n",
		"        .''.         /(\\   .''.\n",
		"       :    :         '   :_\\/_:\n",
		"       :    :         :   : /\\ :\n",
		"        '..'       '. ' .' '..'\n",
		"                   -=   =-\n",
		"                   .' . :\n"
	};
	char texto_fuegos8[][50] = {
		" \n",                           
		" \n",
		"         _\\/_              .''.\n",
		"          /\\              :    :\n",
		"                          :    :\n",
		"                           '..'\n",
		" \n",
		"    \n"
	};
	char texto_fuegos9[][50] = {
		"                       \\'/\n",
		"         *  *         = o =\n",
		"        *_\\/_*         /.\\ .''.\n",
		"        * /\\ *            :    :\n",
		"         *  *             :    :\n",
		"                           '..'\n",
		" \n",
		"     \n"
	};
	char texto_fuegos10[][50] = {
		"                     '.\\'/.'\n",
		"         *  *        -= o =-\n",
		"        *    *       .'/.\\'.\n",
		"        *    *          :\n",
		"         *  * \n",
		" \n",
		" \n",
		"     \n"
	};
	char texto_fuegos11[][50] = {
		"                     '.\\'/.'\n",
		"                     -=   =-\n",
		"            o        .'/.\\'.\n",
		"     o                  :\n",
		"                           .:.\n",
		"                           ':' \n",
		" \n",
		"     \n"
	};
	char texto_fuegos12[][50] = {
		"                     '. ' .'\n",
		"           \\'/       -     -\n",
		"    \\'/   = o =      .' . '.\n",
		"   = o =   /.\\          :  .:::.\n",
		"    /.\\                   :::::::\n",
		"                           ':::' \n",
		" \n",
		"     \n"
	};
	char texto_fuegos13[][50] = {
		"            :\n",
		"     :   '.\\'/.'\n",
		"  '.\\'/.'-= o =-           .:::.\n",
		"  -= o =-.'/.\\'.          :::::::\n",
		"  .'/.\\'.   :             :::::::\n",
		"     :                     ':::' \n",
		" \n",
		"     \n"
	};
	char texto_fuegos14[][50] = {
		"            :\n",
		"     :   '.\\'/.'\n",
		"  '.\\'/.'-=   =-       *   .:::.\n",
		"  -=   =-.'/.\\'.          ::' '::\n",
		"  .'/.\\'.   :             ::. .::\n",
		"     :                     ':::' \n",
		" \n",
		"     \n"
	};
	char texto_fuegos15[][50] = {
		"            :          .\n",
		"     :   '. ' .'     _\\)/_\n",
		"  '. ' .'-     -      /(\\  .'''.\n",
		"  -     -.' . '.       '  :     :\n",
		"  .' . '.   :             :     :\n",
		"     :                     '...' \n",
		" \n",
		"     \n"
	};
	switch(animacion){
		case 1:
			cout<<texto_fuegos1[linea];
			break;
		case 2:
			cout<<texto_fuegos2[linea];
			break;
		case 3:
			cout<<texto_fuegos3[linea];
			break;
		case 4:
			cout<<texto_fuegos4[linea];
			break;
		case 5:
			cout<<texto_fuegos5[linea];
			break;
		case 6:
			cout<<texto_fuegos6[linea];
			break;
		case 7:
			cout<<texto_fuegos7[linea];
			break;
		case 8:
			cout<<texto_fuegos8[linea];
			break;
		case 9:
			cout<<texto_fuegos9[linea];
			break;
		case 10:
			cout<<texto_fuegos10[linea];
			break;
		case 11:
			cout<<texto_fuegos11[linea];
			break;
		case 12:
			cout<<texto_fuegos12[linea];
			break;
		case 13:
			cout<<texto_fuegos13[linea];
			break;
		case 14:
			cout<<texto_fuegos14[linea];
			break;
		case 15:
			cout<<texto_fuegos15[linea];
			break;
		
	}
}
