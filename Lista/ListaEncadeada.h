
typedef struct noduloLista *LISTA;// Ponteiro lista

//Prototipos
void menu();
LISTA* cria_Lista();
int listaDeletar(LISTA lista);
int listInserInicio(LISTA *inicio, int valor);
int listInseriFinal(LISTA *inicio, int valor);
int listaRemov(LISTA *inicio, int valor);
int listaIniRemov(LISTA *inicio);
int listaPrintInverso(LISTA lista);
int listaPrintComeco(LISTA lista);
int listaVazia(LISTA *inicio);
