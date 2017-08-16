/***************************************************
* Universidade Federal da Paraiba                  *
* Aluna: Mário Júnior de Sales Pimentel          *
* Matricula: 11218796                              *
*                                                  *
***************************************************/

#include <stdio.h>
#include <time.h>
#define  max 1000 //variavel que define a quantidade maxima de itens na lista

struct aluno{
   int matricula;
  char nome[100];
};
struct aluno vetor[max];

 /* Definição da função insertion_sort */
void insertion_sort (struct aluno vet[]) {  
  FILE *p;
  char str[30] = "insertion-lista_ordenada.txt"; // nome para o arquivo a ser aberto

  if (!(p = fopen(str,"w"))){                         /* Caso ocorra algum erro na abertura do arquivo..*/    
      printf("Erro! Impossivel abrir o arquivo!\n");  /* o programa aborta automaticamente */
      exit(1);
    }

  int i = 0, j = 0, cont = 0 ;
  struct aluno aux; 
  int x = 0;  
    
  clock_t c2, c1; /* variáveis que contam ciclos do processador */
  double tempo;

  c1 = clock();
  for (j = 1; j < max ; ++j){
    aux = vet[j];
  for (i = j-1; i >= 0 && vet[i].matricula > aux.matricula; --i){
      vet[i+1] = vet[i];
      if(!x){
      	x = 1;
      }
    }

    vet[i+1] = aux;
    if(x){
       x = 1;
       cont++;
    } 
  }
  c2 = clock();
    
  tempo = ((double)(c2 - c1))*1000/CLOCKS_PER_SEC;

  /* Imprime o vetor ordenado em ordem crescente no arquivo criado 'lista ordenada.txt' */
  for (i = 0; i < max; i++) {
    fprintf(p, " %d %s\n", vet[i].matricula, vet[i].nome);
  }

  printf("\n>>INSERTION SORT<<\n");
  printf("\nTEMPO DE EXECUCAO: %f\n", tempo);
  printf("NUMERO DE TROCAS: %d\n", cont);
  fclose(p);
}

  /* Definição da função selection_sort */
void selection_sort (struct aluno vet[]) {
  FILE *p;
  char str[30] = "selection-lista_ordenada.txt"; // nome para o arquivo a ser aberto

  if (!(p = fopen(str,"w"))){                         /* Caso ocorra algum erro na abertura do arquivo..*/    
      printf("Erro! Impossivel abrir o arquivo!\n");  /* o programa aborta automaticamente */
      exit(1);
    }

  int i, j, min, cont = 0;
  struct aluno aux;   
    
  clock_t c2, c1; /* variáveis que contam ciclos do processador */
  double tempo;

  c1 = clock();
  
  for (i = 0; i < (max - 1); i++){
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < max; j++){
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vet[j].matricula < vet[min].matricula){
        min = j;
      }
      cont++;
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
  c2 = clock();
    
  tempo = ((double)(c2 - c1))*1000/CLOCKS_PER_SEC;

    /* Imprime o vetor ordenado em ordem crescente no arquivo criado 'lista ordenada.txt' */
  for (i = 0; i < max; i++) {
    fprintf(p, " %d %s\n", vet[i].matricula, vet[i].nome);
  }

  printf("\n>>SELECTION SORT<<\n");
  printf("\nTEMPO DE EXECUCAO: %f\n", tempo);
  printf("NUMERO DE TROCAS: %d\n", cont);
  fclose(p);
}

int main(void){
  char url[]="Arquivo.txt";
  int i;

  FILE *arq;
  
  arq = fopen(url, "r");
  if(arq == NULL)
      printf("Erro, nao foi possivel abrir o arquivo\n");
  else
    /** le o arquivo ate o final e vai preenchendo o vetor 
    * com os dados encontrados no arquivo, seguindo o padrao 'numero', 'espaco' e 'string'*/
    for(i = 0; i < max; i++){
      if((fscanf(arq,"%d %s \n", &vetor[i].matricula, vetor[i].nome))!= EOF);
    }
  
  insertion_sort (vetor);
  rewind(arq);
  for(i = 0; i < max; i++){
      if((fscanf(arq,"%d %s \n", &vetor[i].matricula, vetor[i].nome))!= EOF);
    }
  selection_sort (vetor);
  rewind(arq);
  for(i = 0; i < max; i++){
      if((fscanf(arq,"%d %s \n", &vetor[i].matricula, vetor[i].nome))!= EOF);
    }

  fclose(arq);
  
  return 0;
}
