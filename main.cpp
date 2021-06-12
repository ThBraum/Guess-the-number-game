#include <iostream>
#include <ctime>
#include <locale.h>
#include <conio.h>
#include <cstdio>

using namespace std;

int comecar(int nsecreto, int qtdtentativas, string modo);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    int numero_secreto, opc, jogar;
    int nivel = 2, ntentativas = 5;
    char sorn;
    string nome_modo;

    cout << "__________________________________________________________________________\n";
    cout << "    ____     _____    _   _      _    _     __   _     _   _____      __  \n";
    cout << "    /   )    /    '   /  /|      |   /      /    /|   /    /    )   /    )\n";
    cout << "---/__ /----/__------/| /-|------|--/------/----/-| -/----/----/---/----/-\n";
    cout << "  /    )   /        / |/  | ===  | /      /    /  | /    /    /   /    /  \n";
    cout << "_/____/___/____ ___/__/___|______|/____ _/_ __/___|/____/____/___(____/___\n";


    cout << "\nPressione ENTER para continuar.";
    cin.ignore();

    system("cls");

    srand(time(0));
    numero_secreto = rand() % 100 + 1;


    do{
        cout << "   _   _   _   _  \n";
        cout << "  / \\ / \\ / \\ / \\ \n";
        cout << " ( M | E | N | U )\n";
        cout << "  \\_/ \\_/ \\_/ \\_/ \n";

        cout << "\n\n[ 1 ] COMEÇAR\n\n";
        cout << "[ 2 ] SELECIONAR DIFICULDADE\n\n";
        cout << "[ 3 ] REGRAS\n\n";
        cout << "[ 4 ] SAIR\n\n";
        cout << "Digite o número referente a opção desejada: ";
        cin >> opc;

        if(nivel == 1){
                nome_modo = "FÁCIL";
                ntentativas = 10;
            }else if(nivel == 2){
                nome_modo = "MÉDIO";
                ntentativas = 5;
            }else{
                nome_modo = "DIFÍCIL";
                ntentativas = 3;
            }

        switch(opc){
        case 1:
            jogar = comecar(numero_secreto, ntentativas, nome_modo);
            break;
        case 2:
            system("cls");

            if(nivel == 1){
                nome_modo = "FÁCIL";
            }else if(nivel == 2){
                nome_modo = "MÉDIO";
            }else{
                nome_modo = "DIFÍCIL";
            }

            cout << "\tDIFICULDADE\n\n\n";
            cout << "Modo de jogo atual: " << nome_modo;
            cout << "\n\n[ 1 ] FÁCIL\n";
            cout << "\n[ 2 ] MÉDIO\n";
            cout << "\n[ 3 ] DIFÍCIL\n\n";

            cout << "Digite o número referente a dificuldade que deseja jogar: ";
            cin >> nivel;

            if(nivel == 1){
                nome_modo = "FÁCIL";
                ntentativas = 10;
            }else if(nivel == 2){
                nome_modo = "MÉDIO";
                ntentativas = 5;
            }else{
                nome_modo = "DIFÍCIL";
                ntentativas = 3;
            }

            cout << "\n\nModo de jogo alterado para: " << nome_modo;
            cout << "\nNesse modo de jogo você possui " << ntentativas << " tentativas!\n\n\tBOA SORTE!\t";

            cout << "\n\n\nPressione ENTER quando estiver pronto para retornar ao MENU.";
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "\tREGRAS\t\n\n";
            cout << "Nosso programa gerará um número aleatório entre 1 e 100, o objetivo do jogador é acertar esse número aleatório\ne secreto." << endl;
            cout << "\nO jogador terá um número limitado de tentativas que irá variar de acordo com o nível de dificuldade escolhido \npelo mesmo." << endl;
            cout << "\nPara facilitar a jogatina, após cada chute nosso jogo irá dizer se o seu chute está abaixo ou acima do número \nsecreto gerado aleatoriamente." << endl;

            cout << "\n\n\nPressione ENTER quando estiver pronto para retornar ao MENU.";
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "O jogo será encerrado!\n";
            cout << "Obrigado por jogar!\n";
            return 0;
        default:
            cout << "\nOpção inválida.\n\n";
            cout << "Deseja retornar ao MENU para tentar novamente? (S/N)";
            cin >> sorn;
            if(sorn == 's' or sorn == 'S'){
                system("cls");
                continue;
            }else if(sorn == 'n' or sorn == 'N'){
                cout << "\nO programa será encerrado!\n";
                return 0;
            }else{
                cout << "\nEntrada não reconhecida. O programa será encerrado!\n";
                return 0;
            }

    }

    }while(opc != 4);

    return 0;
}

int comecar(int nsecreto, int qtdtentativas, string modo){
    system("cls");
    int acertou = 0;
    int chute;
    char soun;

    cout << "  ******** **********     **     *******   **********\n";
    cout << " **////// /////**///     ****   /**////** /////**/// \n";
    cout << "/**           /**       **//**  /**   /**     /**    \n";
    cout << "/*********    /**      **  //** /*******      /**    \n";
    cout << "////////**    /**     **********/**///**      /**    \n";
    cout << "       /**    /**    /**//////**/**  //**     /**    \n";
    cout << " ********     /**    /**     /**/**   //**    /**    \n";
    cout << "////////      //     //      // //     //     //     \n";

    cout << "\nPressione ENTER para começar!";
    getch();
    system("cls");

    do{
        cout << "Nível de jogo: " << modo << "                                                                      VIDAS RESTANTES: " << qtdtentativas;
        cout << "\n\nHora de testar sua sorte! Chute um número de 1 a 100.\n";
        cout << "Seu chute: ";
        cin >> chute;

        if(qtdtentativas <= 1){
            cout << "\n\n\tOps. Parece que suas vidas acabaram!\t\n\n";
            cout << "@@@@@                                        @@@@@\n";
            cout << "@@@@@@@                                      @@@@@@@\n";
            cout << "@@@@@@@           @@@@@@@@@@@@@@@            @@@@@@@\n";
            cout << " @@@@@@@@       @@@@@@@@@@@@@@@@@@@        @@@@@@@@\n";
            cout << "     @@@@@     @@@@@@@@@@@@@@@@@@@@@     @@@@@\n";
            cout << "       @@@@@  @@@@@@@@@@@@@@@@@@@@@@@  @@@@@\n";
            cout << "         @@  @@@@@@@@@@@@@@@@@@@@@@@@@  @@\n";
            cout << "            @@@@@@@    @@@@@@    @@@@@@\n";
            cout << "            @@@@@@      @@@@      @@@@@\n";
            cout << "            @@@@@@      @@@@      @@@@@\n";
            cout << "             @@@@@@    @@@@@@    @@@@@\n";
            cout << "              @@@@@@@@@@@  @@@@@@@@@@\n";
            cout << "               @@@@@@@@@@  @@@@@@@@@\n";
            cout << "           @@   @@@@@@@@@@@@@@@@@   @@\n";
            cout << "           @@@@  @@@@ @ @ @ @ @@@@  @@@@\n";
            cout << "          @@@@@   @@@ @ @ @ @ @@@   @@@@@\n";
            cout << "        @@@@@      @@@@@@@@@@@@@      @@@@@\n";
            cout << "      @@@@          @@@@@@@@@@@          @@@@\n";
            cout << "   @@@@@              @@@@@@@              @@@@@\n";
            cout << "  @@@@@@@                                 @@@@@@@\n";
            cout << "   @@@@@                                   @@@@@\n\n\n";
            cout << "                   VOCÊ PERDEU!!                         ";

            cout << "\n\nO número secreto era " << nsecreto;
            cout << "\n\nDeseja retornar ao MENU para jogar novamente?(S/N)";
            cin >> soun;

            if(soun == 'S' or soun == 's'){
                acertou = 1;
                system("cls");
            }else{
                system("cls");
                cout << "O jogo será encerrado. Obrigado por jogar\n\nPressione ENTER para continuar";
                getch();
                exit(0);
            }
        }

        if(chute < nsecreto){
            cout << "\nSeu chute não confere com o número secreto. Tente um número maior!\n\n";
            qtdtentativas--;
        }else if(chute > nsecreto){
            cout << "\nSeu chute não confere com o número secreto. Tente um número menor!\n\n";
            qtdtentativas--;
        }else{
            cout << "\n    .-=========-.\n";
            cout << "    \'-=======-'/\n";
            cout << "    _|   .=.   |_\n";
            cout << "   ((|  {{1}}  |))\n";
            cout << "    \\|   /|\\   |/\n";
            cout << "     \\__ '`' __/\n";
            cout << "       _`) (`_\n";
            cout << "     _/_______\\_\n";
            cout << "    /___________\\\n";
            cout << " \n\nPARABÉNS. VOCÊ GANHOU!!\n";

            cout << "\n\nDeseja retornar ao MENU para jogar novamente?(S/N)";
            cin >> soun;

            if(soun == 'S' or soun == 's'){
                acertou = 1;
                system("cls");
            }else{
                system("cls");
                cout << "O jogo será encerrado. Obrigado por jogar\n\nPressione ENTER para continuar";
                getch();
                exit(0);
            }
        }

    }while(acertou != 1);
}
