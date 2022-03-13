# Lista encadeada

> Definição
> 
> - A lista encadeada (linked list) é um estrutura de dados de tamanho variado.
> - Nessa ED, todos os itens podem ser consultados, manipulados e removidos.
> - Além disso, a inserção também ocorre em toda sua extensão.

## Estrutura

```c
// struct responsável pela lista encadeada
typedef struct linkedList
{
    // dado a ser inserido
    int data;

    // ponteiro para a estrutura
    // responsavel por guardar as proximas posicoes
    struct linkedList* next;
}node;
```

- A estrutura “linkedList” possui as informações do dado (data) a ser inserido, e dos próximos itens (next)

## Funcionamento

### Double Pointer

- Nas listas encadeadas, eu optei por usar ponteiros duplos por dois motivos
    1. Somente com eles eu consigo manipular a lista sem ficar fazendo atribuições como: listaNova = listaVelha.
        1. Isso ocorre, pois com ponteiros duplos, o endereço de memória trabalhado não é o do valor, mas sim o da variável.
        2. Ou seja, quando eu tenho *list = 0, o ponteiro aponta para 0, mas quando eu **list = 0, o ponteiro mais externo aponta para *list.
        3. Portanto, ao invés de manipular os valores da lista, eu manipulo, diretamente, a própria lista.
    2. Sem ponteiros de ponteiros a lista não funciona, por conta da iteração.
        1. Já que, com ponteiros simples eu manipulo os valores, ao fazer: lista = lista→proximaPosição, acabava sobrescrevendo o valor alocado no espaço de memória.
        2. No entanto, ao usar **list, quando faço *list *=* (*list)→proximaPosição, o programa não reescreve os valores, apenas “viaja” entre os endereços de memória.

### Inicialização

- Assim como as pilhas, listas encadeadas começam em NULL.
- Indicando que o último item sempre aponta para NULL

```c
void startList(node** list)
{
    // lista eh inicializada
    *list = NULL;
}
```

### Inserção

```c
int insertInIndex(node** list, int data, int index)
{
    // alocacao do novo no
    node* new = (node*)malloc(sizeof(node*));
    // dado eh atribuido
    new->data = data;
    // auxiliar 
    node* aux = *list;
    // posicao
    int indexCount = 0;

    // verifica se a lista esta vazia e se o indice eh zero
    // pois se ela estiver vazia o unico jeito de inserir eh no incio
    if (emptyList(*list) && index != 0) return 0;

    // verifica se o indice eh possivel
    if (index > lenLinkedList(*list)) return 0;
    
    // switch para certos atalhos
    switch (index)
    {
        // se o indice for 0 
        case 0:
            // o proximo do novo recebe a lista
            new->next = *list;
            // lista recebe o novo
            *list = new;
            break;
        case -1:
            // itera ateh o ultimo item
            while (aux->next != NULL)
            {
                // auxiliar eh atualizado
                aux = aux->next;
            }

            // o proximo em relacao ao novo recebe NULL
            new->next = aux->next;
            // proximo recebe o novo
            aux->next = new;
            break;
        default:
            // procura o item ateh achar o index
            while (indexCount != index-1)
            {
                // a posicao do elemento eh incrementada
                indexCount++;
                // aux eh atualizado
                aux = aux->next;
            }

            // mesmo raciocinio de troca do case anterior
            new->next = aux->next;
            aux->next = new;
            break;
        }
}
```

- Coloquei casos para índice em -1 e 0 pois, torna, na minha opinião, o código, respectivamente, mais prático e eficiente.

### Remoção

- A operação de remoção ocorre parecida com a de inserção.
- No entanto, eu analiso sempre o item imediatamente antes do que eu quero remover
    - Ou seja, se eu quero remover o índice 5, eu paro a iteração no índice 4.
- A remoção ocorre, segundo minha implementação, de dois jeitos:
    1. Pelo índice
        
        ```c
        int removeInIndex(node** list, int index)
        {
            // auxiliar eh instanciado
            node* aux = *list;
            // contador para verificar o indice
            int countIndex = 0;
        
            // se a lista estiver vazia e o indice nao for 0
            // retorna 0
            if (emptyList(*list) && index != 0) return 0;
        
            // se o indice for maior que o possivel
            // retorna 0
            if (index > lenLinkedList(*list)) return 0;
        
            switch (index)
            {
                // primeiro indice
                case 0:
                    // posicao atual recebe a proxima
                    *list = (*list)->next;
                    return 1;
                // ultima posicao
                case -1:
                    // enquanto o item analizado nao for o prnultimo
                    while (aux->next->next != NULL)
                    {
                        // auxiliar anda uma casa
                        aux = aux->next;
                    }
        
                    // o proximo item recebe o ultimo
                    aux->next = aux->next->next;
                    return 1;
                // qualquer outra posicao
                default:
                    // enquanto o contador nao estiver antes do indice
                    while (countIndex != index-1)
                        {
                            // contador eh incrementado
                            countIndex++;
                            // auxiliar eh incrementado
                            aux = aux->next;
                        }
        
                    // o proximo item recebe o seu proximo
                    aux->next = aux->next->next;
                    return 1;
            }
        }
        ```
        
    2. pelo valor
        
        ```c
        int removeItem(node** list, int data)
        {
            // se o elemento nao for encontrado ele retorna 0
            if (elementIndex(*list, data) < 0) return 0;
        
            // auxiiliar eh instanciado
            node* aux = *list;
        
            // se o dado atual for igual ao dado inserido
            // sigfica que o item eh o primeiro
            if (aux->data == data)
            {
                // entao eh so fazer o atual recber o valor do proximo
                *list = (*list)->next;
                return 1;
            }
        
            // enquanto o dado for diferente
            while (aux->next->data != data)
            {
                // auxiliar eh atualizado
                aux = aux->next;
            }
        
            // dado eh removido
            aux->next = aux->next->next;
        
            return 1;
        }
        ```
        

> Conclusão
> 
> - Nesse readme, você leu apenas sobre o básico da lista, ou seja, como você inicia, insere e tira dados dela.
> - Agora, é necessário que você leia as outras funções implementadas para que essa estrutura fique fixa na sua mente.
> - Desde já, obrigado por ler, bons estudos, e fique à vontade para abrir issues.
