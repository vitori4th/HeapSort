#include<stdio.h>
#include<stdlib.h>

typedef struct ponto{
  int x;
  int y;
}Ponto;

void troca(Ponto * a, Ponto *b){
  Ponto aux = *a;
  *a = *b;
  *b = aux;
}

int compara(Ponto* a, Ponto* b){
     if(a->x > b->x){
        return -1;
     }
     if(a->x == b->x ){
        if(a->y > b->y)
            return -1;
        if(b->y > a->y)
            return 1;
     }
     return 1;
}

void desce_heap(Ponto * heap, int n, int pos){
  int esq = 2*pos + 1;
  int dir = 2*pos + 2;
  
  //tenho filhos?
  if(esq >= n) return;
  
  int maior_filho = esq;
  
  int result = compara(&(heap[dir]), &(heap[maior_filho]));
  //verifica se tem filho direito
  // e se ele é maior que o esquerdo
  if(dir < n && result == -1){
    maior_filho = dir;
  }
  
  //VERIFICAR SE heap[pos] é maior que O MAIOR  FILHO
  //se for troca
  int result2=compara(&(heap[maior_filho]), &(heap[pos]));
  if(result2==-1){
    troca(&(heap[pos]), &(heap[maior_filho]));
    desce_heap(heap, n, maior_filho);
  }else{
    //se não tem troca, heap[pos] já tá no lugar certo.
  }
  
}

//recebe um vetor qualquer, e transforma em um heap
void constroi_heap(Ponto *v, int tamanho){
    for(int i = tamanho/2 ; i >= 0; i--){
      desce_heap(v, tamanho, i);
    }
}

void HeapSort(Ponto *v, int tamanho){
	constroi_heap(v, tamanho);
    for (int i = tamanho - 1; i >= 0; i--) {
    	//move pro final
        troca(&(v[0]), &(v[i])); 
        desce_heap(v, i, 0); 
    }
}

//************* NAO MODIFIQUE A MAIN ****************/
int main(int argc, char * argv[]){
  int tamanho;  
  scanf("%d", &tamanho);
  Ponto * v = (Ponto *) malloc(sizeof(Ponto)*tamanho);
  
  srand(tamanho);
  for(int i = 0; i < tamanho; i++){
    v[i].x = rand()%tamanho;
    v[i].y = rand()%tamanho;
  }
  
  HeapSort(v, tamanho);
  
  //imprimido a cada 1% (mais ou menos)
  for(int i = 0; i < tamanho; i += (tamanho/100) + 1){
    printf("(%d, %d) ", v[i].x, v[i].y);
  }
  printf("\n");
}

