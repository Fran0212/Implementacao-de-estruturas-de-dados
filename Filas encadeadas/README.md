# Fila encadeada

> Definição
> 
> - Filas encadeadas são, ao meu ver, listas encadeadas que você consegue “mexer” apenas no último elemento
>     - FIFO (*First In First Out*)

## Estrutura

- A estrutura possui um dado e um ponteiro para o próximo item.
    - Data → Inteiro representando o dado a ser inserido.
    - Next → Ponteiro para a fila.

```c
typedef struct queue
{
    // dado a ser inserido
    /*-----------------*/
    // data to be inserted
    int data;

    // ponteiro para o proximo
    /*---------------------*/
    // pointer to the next
    struct queue* next;
}node;
```

## Inicialização

- A fila recebe NULL, indicando seu fim.

```c
void startQueue(node** queue)
{
    // espaco de memoria é esvaziado
    /*---------------------------*/
    // memory space is emptied
    *queue = NULL;
}
```

## Enfileiramento

- O enfileiramento ocorre entre o NULL e o ultimo dado inserido.
    - Pois, ao meu ver, o fim da fila é marcado por NULL.

```c
int enqueue(node** queue, int data)
{
    // declaracao do novo item
    /*-----------------------*/
    // Declaration of the new item
    node* new = (node*)malloc(sizeof(node));

    // declaracao do auxiliar de enfileiramento
    /*---------------------------------------*/
    // Declaration of enqueue assistant
    node* aux = *queue;

    // atribuicao de valores
    /*--------------------*/
    // value attribution
    new->data = data;
    new->next = NULL;

    // se a fila estiver vazia...
    /*-------------------------*/
    // If the queue is empty ...
    if (emptyQueue(aux))
    {
        // a fila original recebe a nova celula
        /*-----------------------------------*/
        // The original queue receives the new cell
        *queue = new;
    }
    // caso contrario...
    /*----------------*/
    // otherwise...
    else
    {       
        // enquanto o proximo não for nulo...
        /*------------------------------*/
        // while the next is not null...
        while (aux->next != NULL)
        {
            // o atual recebe o proximo valor
            /*-----------------------------*/
            // The current one receives the next value
            aux = aux->next;
        }
        // o proximo item recebe o novo valor
        /*---------------------------------*/
        // The next item receives the new value
        aux->next = new;
    }
}
```

## Desenfileiramento

- Como a cada enfileiramento, os primeiros dados inserido “caminham para frente”
- É só fazer o seguinte jogo:
    1. Auxiliar recebe a fila;
    2. Fila recebe o próximo item;
    3. Auxiliar é esvaziado.

```c
int dequeue(node** queue)
{
    // se a fila estiver vazia retorna 0
    /*--------------------------------*/
    // If the queue is empty returns 0
    if (emptyQueue(*queue)) return 0;

    // declaracao do auxiliar de desenfileiramento
    /*---------------------------------------*/
    // Declaration of dequeue assistant
    node* aux;

    // auxiliar recebe a celula atual da fila
    /*-------------------------------------*/
    // auxiliary receives the current cell of the queue
    aux = *queue;

    // celula atual recebe a proxima
    /*----------------------------*/
    // Current cell receives the next
    *queue = (*queue)->next;

    // limpa o espaco de memoria do auxiliar
    /*------------------------------------*/
    // Clears the auxiliary memory space
    free(aux);
}
```

> Conclusão
> 
> - Nesse readme, você leu apenas sobre o básico da fila, ou seja, como você inicializa, insere e tira dados dela.
> - Agora, é necessário que você leia as outras funções implementadas para que essa estrutura fique fixa na sua mente.
> - Desde já, obrigado por ler, bons estudos, e fique à vontade para abrir issues.
