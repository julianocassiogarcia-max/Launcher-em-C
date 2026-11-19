#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
void limparTela (void) {
#ifdef _WIN32 //#IFDEF É PARA CASO O SISTEMA OPERACIONAL SEJA UM WINDOWNS
	system("cls");  //ESSE CLS É UM COMANDO PARA O WINDOWNS(_WIN32), QUE SIGNIFICA CLEAN SCREEN
#else
	system("clear"); //ESSE AQUI É BASICAMENTE A MESMA COISA DO CLS SÓ QUE PARA OS SISTEMAS LINUX E MAC
#endif
}

int d21(int danoBase) { //FUNÇÃO DO DADO D20, USADO PARA A ALEATORIEDADE PARA O DANO
	int d20 = rand() % 21;
	int danoFinal;

	if (d20 < 10) {
		danoFinal = danoBase / 2;
	} else if (d20 <= 16) {
		danoFinal = danoBase;
	} else {
		danoFinal = danoBase * 2;
	}

	printf("\nResultado do D20: %d\n", d20);
	printf("Dano causado: %d\n", danoFinal);

	return danoFinal;
}
void rpg (void) {
	int d20 = rand() % 21; //números percorrem de 0 a 20

	int jogarNovamente = 1;

	char nomePersonagem[125];
	int armaPersonagem;
	char armas[3][20] = {"Espada", "Machado", "Arco e flecha"};
	int escolhaJogador[10];
	int dinheiroJogador = 10;

	int danoArmas[3] = {15, 15, 15};
	int vidaJogador = 50;
	int vidaBandido[3] = {30, 60, 80};
	int danoBandido[3] = {10, 12, 15};

	do {
		limparTela();
		printf("===CAMINHO DO HERÓI ⚔️ ===\n");
		printf("\033[1;31mIMPORTANTE!\nSEU PERSONAGEM TEM COMO VIDA 50 HP\nTOTAS AS ARMAS POSSUEM O MESMO DANO, ESCOLHA A QUE MAIS COMBINE COM VOCÊ\n\033[0m\033[33mREGRAS:\nSe o D20 (Dado) for menor que 10, seu hit perderá força em 50%;\nSe o D20 cair entre 10 a 16 seu hit será com o dano normal;\nCaso o D20 cair entre 17 e 20, seu hit causará mais dano.\033[0m\n\033[1;32mMAIS PARA FRENTE DO JOGO VOCÊ PODERÁ AUMENTAR SEUS STATUS\033[0m ⚡ \033[0m\n");
		printf("\033[1;36mPARA POR NOME COMPOSTO UTILIZE ENTRE OS ESPAÇOS: (-, _ OU .)\n\033[0m");
		printf("BEM VINDO AO CAMINHO DO HERÓI, JOVEM GUERREIRO(A), ANTES DE TUDO, QUAL É O SEU NOME DE HERÓI?: ");
		scanf("%s", nomePersonagem);
		limparBuffer();
		printf("\nOlá \033[1;36m%s\033[0m, sua vila foi atacada por um terrível bando de bandidos, sua missão é ir até o covil deles, derrotar o líder e trazer os pertences da vila de volta!\n", nomePersonagem);
		printf("Ao chegar no centro de sua vila, o ferreiro diz o seguinte:\n\033[1;35mFERREIRO KLAUS:\033[0m NAQUELA SALA TEM ALGUMAS ARMAS, ESCOLHA UMA PARA A SUA JORNADA!!!\n\n");
		for (int i = 0; i < 3; i++) {
			printf("\033[33m%d \033[0m\033[37m- %s = 15 ATAQUE\033[0m\n", i + 1, armas[i]);
		}
		printf("\nQual delas você gostaria de usar: ");
		do {
			scanf("%d", &armaPersonagem);
			if (armaPersonagem != 1 && armaPersonagem != 2 && armaPersonagem != 3) {
				limparBuffer();
				printf("Escolha apenas uma das opções válidas: ");
			}
		} while(armaPersonagem != 1 && armaPersonagem != 2 && armaPersonagem != 3);

		printf("Incrível! Você agora possui %s!\n", armas[armaPersonagem - 1]);
		printf("Antes de se despedir, o prefeito da sua cidade vem ao seu encontro e diz :\n\033[1;35mPREFEITO AFONSO: \033[0mJovem %s, pegue essas moedas de ouro para te ajudar em sua jornada, você é nossa última esperança!\n\n\033[1;33mVOCÊ RECEBEU 10 MOEDAS DE OURO!\033[0m\n\n", nomePersonagem);
		printf("\033[1;36m%s!\033[0m Você irá participar de uma grande aventura, nessa sua jornada, lute pelo caminho da fé para ganhar a sua grande recompensa.\n", nomePersonagem);
		printf("\n\033[33m----------Você se despede da sua vila e vai ao caminho da fé.----------\033[0m\nPelo caminho, você encontra um dos bandidos que roubou sua vila, ele parou para reabastecer suprimentos para o bando (que tinham deixado ele sozinho), em uma vila que ficava a aproximadamente 30 km da sua vila.\nEle logo reconheçe o brazão que representa o selo dos que aceitaram a Cristo em seu peito, e vem atacar você, o que você faz?\n");

		printf("\n\033[1;34m===== PRIMEIRO COMBATE =====\033[0m\n");
		while (vidaBandido[0] > 0 && vidaJogador > 0) {

			printf("Você: %d HP | Bandido: %d HP\n", vidaJogador, vidaBandido[0]);
			printf("1) ATACAR\n2) DEFENDER-SE\nO que você escolhe?: ");

			do {
				scanf("%d", &escolhaJogador[0]);
				if (escolhaJogador[0] != 1 && escolhaJogador[0] != 2) {
					limparBuffer();
					printf("Opção inválida, digite novamente (1 ou 2): ");
				}
			} while (escolhaJogador[0] != 1 && escolhaJogador[0] != 2);


			switch (escolhaJogador[0]) {
			case 1:
				int dano;

				printf("\nVocê ataca com %s!\n", armas[armaPersonagem - 1]);

				dano = d21(danoArmas[armaPersonagem - 1]);
				vidaBandido[0] -= dano;

				if (vidaBandido[0] < 0) {
					vidaBandido[0] = 0;
				}

				printf("Vida do bandido: %d HP\n", vidaBandido[0]);
				if (vidaBandido[0] == 0) {
					printf("Você derrotou o bandido! Parabéns!\n");
					break;
				}
				printf("\nO bandido ainda está de pé!\n");
				printf("O bandido irá te atacar!\n");

				dano = d21(danoBandido[0]);
				vidaJogador -= dano;

				if (vidaJogador < 0) {
					vidaJogador = 0;
				}

				printf("Sua vida atual: %d HP\n", vidaJogador);
				if (vidaJogador == 0) {
					printf("\033[1;31m~~~~~~GAME OVER~~~~~~\033[0m\n");
					return;
				}
				break;
			case 2:
				printf("Você se defende do ataque, mas ele enfurecido vem te atacar novamente\n");
			}
		}
		printf("Após essa longa batalha, sua vida foi para %d.\nUm pouco a frente você encontra uma taberna, o preço para uma cama de descanso é de 2 moeda de ouro, você deseja decansar, ou continuar a viagem?\n", vidaJogador);
		printf("---------------\n1 - Descansar\n2 - Continuar viagem\n---------------\nEscolha: ");

		do {
			scanf("%d", &escolhaJogador[1]);

			if (escolhaJogador[1] != 1 && escolhaJogador[1] != 2) {
				limparBuffer();
				printf("Opção inválida, digite novamente (1 ou 2): ");
			}
		} while (escolhaJogador[1] != 1 && escolhaJogador[1] != 2);

		if(escolhaJogador[1] == 1) {
			dinheiroJogador -= 2;
			printf("Dormindo a noite toda...\n");
			printf("Após seu descanso, sua vida foi recuperada!\n\033[1;33mDINHEIRO: %d\033[0m", dinheiroJogador);
			vidaJogador = 50;
		} else if(escolhaJogador[1] == 2) {
			printf("A jornada continua...\n");
		}
		printf("\nAo amanhecer, você se depará com com um velho senhor que estava vendendo seus cavalos.\nAo conversar com ele, ele fala:\n");
		printf("\033[1;35mVELHO TOMAS:\033[0m Meu jovem, você não estaria interessado em ajudar um pobre senhor? Muitos bandidos estão aparecendo ultimamente e atacando as vilas, precisamos de dinheiro para comprar comida!\n");
		printf("Se você tiver interesse, meu cavalo está saindo por 3 moedas de ouro.\n");
		printf("\n===============\n1 - COMPRAR UM CAVALO\n2 - NÃO, MUITO OBRIGADO...\n===============\n\nESCOLHA: ");

		do {
			scanf("%d", &escolhaJogador[2]);
			if (escolhaJogador[2] != 1 && escolhaJogador[2] != 2) {
				limparBuffer();
				printf("Opção inválida, digite novamente (1 ou 2): ");
			}
		} while (escolhaJogador[2] != 1 && escolhaJogador[2] != 2);
		if(escolhaJogador[2] == 1) {
			printf("\n\033[1;35mVELHO TOMAS:\033[0m Oh meu jovem, muito obrigado pela sua compaixão, tome, aqui está o seu cavalo!\n(Cuide bem dele), diz o senhor indo embora feliz para a sua casa.\n");
			dinheiroJogador -= 3;
			printf("Com esse seu cavalo você chegará ao seu destino ainda hoje!\n");
		} else if(escolhaJogador[2] == 2) {
			printf("\033[1;35mVELHO TOMAS:\033[0mAh, ok, tudo bem...Diz o senhorzinho indo embora triste, tentando vender seu cavalo para conseguir ajudar a sua família.\n");
		}
		printf("\n\033[1;36m%s\033[0m ainda não se esqueceu da sua missão.Ao chegar perto do covil dos bandidos, um medo subiu ao seu coração, (Em que eu me meti?) pensou.\nMas a sede de justiça e a fé que ele tinha, deu o forças para continuar.\n\033[0m", nomePersonagem);
		printf("Pelo caminho, ele se depará com um goblin \033[33m(quem diria que em um RPG teria um goblin não é mesmo).\033[0m");
		printf("\nAo se aproximar, ele reconhe esse goblin, ele é um ancião muito famoso pela vila do amor e pela vila dos servos\n");
		printf("O goblin percebendo a presença do herói, diz: \n");
		printf("\033[1;35mGoblin\033[0m: Ora, o que um humano como você está fazendo andando pelo caminho da fé? Por algum acaso você quer fazer justiça?\n");
		printf("~~~~O herói responde~~~~\nOra, eu bem sei que a justiça não está nas minhas mãos, mas eu preciso recuperar os pertences do meu povo!\n");
		printf("\033[1;35mGoblin\033[0m: Muito bem então, vejo que seus olhos estão fixos no seu objetivo, se tiver interesse, eu posso te ajudar por algumas moedas de ouro\033[1;33m(5 MOEDAS)\033[0m");
		printf("\nVocê deseja a ajuda do goblin ancião?\n");
		printf("Digite 1 para aceitar a ajuda e 0 para continuar a viagem: ");
		do {
			scanf("%d", &escolhaJogador[3]);
			if (escolhaJogador[3] != 1 && escolhaJogador[3] != 0) {
				limparBuffer();
				printf("Opção inválida, escolha entre 1 - Sim, 0 - Não: ");
			}
		} while (escolhaJogador[3] != 1 && escolhaJogador[3] != 0);
		if(escolhaJogador[3] == 1) {
			printf("Muito bem, pequeno gafanhoto, eu irei te dar uma parte da escritura sagrada para você. Dizem que com ela você pode derrotar até as mais fortes tribulações.\n");
			dinheiroJogador -= 5;
			printf("Você começa a sentir uma força como nunca tinha sentido, e aquele medo que estava no seu coração se vai.\n");
			printf("\n=====STATUS ATUALIZADOS=====\n");
			printf("HP = 80\nDANO: 25\n");
			vidaJogador = 80;
			danoArmas[0,1,2] = 25;
		} else if(escolhaJogador[3] == 0) {
			printf("Como quiser, tenha uma boa sorte! Que Deus o proteja.\n");
		}
		printf("\n~~~~~~ A JORNADA ESTÁ CHEGANDO AO FIM~~~~~~\n");
		printf("Após uma longa jornada, %s chegou enfim ao seu destino\nPara entrar no covil, nosso jovem guerreiro teve que se manter em modo furtivo, até porque ele sabia das suas próprias forças.\nAdiante, ele encontrá os pertences roubados do povo do vilarejo!\n%s: Graças á Deus, eu achei os pertences!!!\nPorém, ali estava um dos bandidos mais brutais de todo aquele reino\n", nomePersonagem, nomePersonagem);
		printf("O bandido percebe a sua presença, e vem te atacar!");


		printf("\n\033[1;34m===== SEGUNDO COMBATE =====\033[0m\n");
		while (vidaBandido[1] > 0 && vidaJogador > 0) {

			printf("Você: %d HP | Bandido: %d HP\n", vidaJogador, vidaBandido[1]);
			printf("1) ATACAR\n2) DEFENDER-SE\nO que você escolhe?: ");

			do {
				scanf("%d", &escolhaJogador[4]);
				if (escolhaJogador[4] != 1 && escolhaJogador[4] != 2) {
					printf("Opção inválida, digite novamente (1 ou 2): ");
				}
			} while (escolhaJogador[4] != 1 && escolhaJogador[4] != 2);

			switch (escolhaJogador[4]) {
			case 1:
				int dano;

				printf("\nVocê ataca com %s!\n", armas[armaPersonagem - 1]);

				dano = d21(danoArmas[armaPersonagem - 1]);
				vidaBandido[1] -= dano;

				if (vidaBandido[1] < 0) {
					vidaBandido[1] = 0;
				}

				printf("Vida do bandido: %d HP\n", vidaBandido[1]);
				if (vidaBandido[1] == 0) {
					printf("Você derrotou o bandido! Parabéns!\n");
					break;
				}
				printf("\nO bandido ainda está de pé!\n");
				printf("O bandido irá te atacar!\n");

				dano = d21(danoBandido[1]);
				vidaJogador -= dano;

				if (vidaJogador < 0) {
					vidaJogador = 0;
				}

				printf("Sua vida atual: %d HP\n", vidaJogador);
				if (vidaJogador == 0) {
					printf("\033[1;31m~~~~~~GAME OVER~~~~~~\033[0m\n");
					return;
				}
				break;
			case 2:
				printf("Você se defende do ataque, porém esse bandido é muito mais forte do que aqule na estrada, você fica exausto!\n");
				break;
			}
		}
		printf("~~~~~~~~\nApós essa longa batalha, sua vida foi para %d.\n~~~~~~~~\nPorém a luta intensa atraiu a atenção do tão temível líder dos bandidos. Ao te ver, ele abre um sorriso cênico e pergunta:\nLíder: Vejamos bem, se não está em minha presença um resultado de esforço inútil hahaha. Antes que eu te mate, diga me, qual é o seu nome?\n");
		printf("%s: Meu nome é \033[36%s\033[0m! Contudo, não serei eu que irá perecer após essa batalha!\n", nomePersonagem, nomePersonagem);
		printf("Ora, vejo que você derrotou um dos meus aliados mais fortes, então por respeito a você, te falarei meu nome antes que eu te enterre, meu nome é: Shaatan, o abestado que caiu do céu.\n");
		printf("\033[31mShaatan\033[0m 👹 : Já chega de falatório, chegou a hora da sua morte!\n");

		printf("\n\033[1;34m===== O ÚLTIMO COMBATE =====\033[0m\n");
		while (vidaBandido[2] > 0 && vidaJogador > 0) {

			printf("Você: %d HP | Bandido: %d HP\n", vidaJogador, vidaBandido[2]);
			printf("1) ATACAR\n2) DEFENDER-SE\nO que você escolhe?: ");

			do {
				scanf("%d", &escolhaJogador[5]);
				if (escolhaJogador[4] != 1 && escolhaJogador[5] != 2) {
					limparBuffer();
					printf("Opção inválida, digite novamente (1 ou 2): ");
				}
			} while (escolhaJogador[5] != 1 && escolhaJogador[5] != 2);

			switch (escolhaJogador[5]) {
				int dano;
			case 1:

				printf("\nVocê ataca com %s!\n", armas[armaPersonagem - 1]);

				dano = d21(danoArmas[armaPersonagem - 1]);
				vidaBandido[2] -= dano;

				if (vidaBandido[2] < 0) {
					vidaBandido[2] = 0;
				}

				printf("Vida do bandido: %d HP\n", vidaBandido[2]);
				if (vidaBandido[2] == 0) {
					printf("Você derrotou o bandido! Parabéns!\n");
					break;
				}
				printf("\nO bandido ainda está de pé!\n");
				printf("O bandido irá te atacar!\n");

				dano = d21(danoBandido[2]);
				vidaJogador -= dano;

				if (vidaJogador < 0) {
					vidaJogador = 0;
				}

				printf("Sua vida atual: %d HP\n", vidaJogador);
				if (vidaJogador == 0) {
					printf("\033[1;31m~~~~~~GAME OVER~~~~~~\033[0m\n");
					return;
				}
				break;
			case 2:
				printf("Você consegue se defender graças a experiência que vocẽ conseguiu ao longo da sua jornada\n");
				break;
			}
		}
		if (vidaBandido[2] == 0) {
			printf("\n\033[31mShaatan\033[0m 👹 : Co..como você conseguiu?\n");
			printf("\033[1;36m%s:\033[0m Não é por força e nem por inteligência, mas é pelo Espirito de Deus que a dentro de mim que me deu forças para vencer!\n", nomePersonagem);
			printf("\n");
			printf("A jornada acabou...\nTodos os inimigos foram derrotados.\nDepois dessa luta, %s pegou os pertences da sua querida vila, e voltou para casa!\n", nomePersonagem);
			printf("\n");
		}
		if (vidaJogador == 0) {
			printf("Infelizmente, \033[1;36m%s\033[0m pereceu em sua jornada...", nomePersonagem);
		}
		printf("\n\033[33mCONTINUAÇÃO EM BREVE...\033[0m\n");
		printf("=====DESEJA FAZER UMA NOVA JORNADA?=====\n");
		printf("Digite 1 para se aventurar novamente e 0 para sair: ");
		do {
			scanf("%d", &jogarNovamente);
			if(jogarNovamente != 1 && jogarNovamente != 0) {
				limparBuffer();
				printf("\nOpção inválida,digite (1 ou 0): ");
			}
		} while(jogarNovamente != 1 && jogarNovamente != 0);
	} while(jogarNovamente != 0);
}
int main()
{
	rpg();

	return 0;
}