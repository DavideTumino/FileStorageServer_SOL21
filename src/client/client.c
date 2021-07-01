
#include <unistd.h>
#include <stdio.h>

void helper();


int main(int argc, char const *argv[])
{
	if (argc == 1) {
		printf("Parametri assenti, digitare \"./client -h\" per visualizzare la lista dei comandi\n");
		return -1;
	}

	int opt;
	int h_flag = 0,
		f_flag = 0,
		p_flag = 0,
		D_flag = 0;


	while ((opt = getopt(argc, argv, ":hf:w:W:D:r:R:d:t:l:u:c:p")) != -1)
		
		switch (opt) {
			case 'h': {
				if (h_flag == 1) return -1;
				h_flag = 1;
				helper();
				break;
			}
			case 'f': {
				if (f_flag == 1) return -1;
				f_flag = 1;
				printf("f %s\n", optarg);
				break;
			}
			case 'w': {
				printf("-w %s\n", optarg);
				break;
			}
			case 'W': {
				if (D_flag == 0) return -1;
				printf("-W %s\n", optarg);
				break;
			}
			case 'D': {
				D_flag = 1;
				printf("-D %s\n", optarg);
				break;
			}
			case 'r': {
				printf("-r %s\n", optarg);
				break;
			}
			case 'R': {
				printf("-R %s\n", optarg);
				break;
			}
			case 'd': {
				printf("-d %s\n", optarg);
				break;
			}
			case 't': {
				printf("-t %s\n", optarg);
				break;
			}
			case 'l': {
				printf("-l %s\n", optarg);
				break;
			}
			case 'u': {
				printf("-u %s\n", optarg);
				break;
			}
			case 'c': {
				printf("-c %s\n", optarg);
				break;
			}
			case 'p': {
				if (p_flag == 1) return -1;
				p_flag = 1;
				printf("-p %s\n", optarg);
				break;
			}
			case ':': {
				printf("Invalid argument\n");
				break;	
			}
			case '?': {
				printf("nessun comando valido\n");
				break;
			} 

		}


	return 0;
}

void helper() {
	printf("\n -- HELPER --\n\n");
	printf("\t-h                  stampa la lista dei comandi ed il loro funzionamento\n");
	printf("\t-f <filename>       specifica il nome del socket a cui connettersi\n");
	printf("\t-w <dirname[,n=0]>  invia al server n file contenuti nella cartella ‘dirname’ (se n non è specificato allora invia tutto il contenuto della cartella. In caso di capacity misses necessita del comando -D)\n");
	printf("\t-W <file1[,file2]>  lista di nomi di file da scrivere nel server separati da ‘,’\n");
	printf("\t-D <dirname>        indica la cartella dove vengono scritti i file che il server rimuove a seguito di capacity misses (deve essere usata congintamente a '-w' o '-W')\n");
	printf("\t-r <file1[,file2]>  lista di nomi di file da leggere dal server separati da ‘,’ \n");
	printf("\t-R <[n=0]>          permette di leggere ‘n’ file qualsiasi attualmente memorizzati nel server (tutti se n non è specificato)\n");
	printf("\t-d <dirname>        cartella scrivere i file letti dal server con l’opzione ‘-r’ o ‘-R’ (deve essere usata congiuntamente a '-r' o '-R')\n");
	printf("\t-t <time>           tempo in millisecondi che intercorre tra l’invio di due richieste successive al server (time=0 -> nessun ritardo)\n");
	printf("\t-l <file1[,file2]>  lista di nomi di file su cui acquisire la mutua esclusione\n");
	printf("\t-u <file1[,file2]>  lista di nomi di file su cui rilasciare la mutua esclusione\n");
	printf("\t-c <file1[,file2]>  lista di file da rimuovere dal server se presenti\n");
	printf("\t-p                  abilita le stampe sullo standard output per ogni operazione\n\n");
}


































