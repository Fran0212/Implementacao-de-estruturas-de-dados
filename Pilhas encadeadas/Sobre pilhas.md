## Pilha encadeada

> Definição
> 
> - A pilha encadeada é uma estrutura de dados, na qual, você consegue acessar apenas o último elemento — *LIFO* (*Last in Fist out*).

### Estrutura

- Uma estrutura chamada *node* foi criada.
- Essa, que, por sua vez, possui os dados do topo (*top)* e os próximos (*next).*

```c
typedef struct stack
{
    // top indica o topo da pilha
    int top;

    // next indica o proximo item da pilha
    struct stack* next;
}node;
```

### Funcionamento

- Inicialização
    - A pilha deve ser inicializada com null pois sua base sempre aponta para o vazio.
    - Por mais estranho que isso pareça pense: uma pilha — na vida real — tem uma base que fica sempre no chão, logo, ela sempre aponta para onde não tem nada.
    - Visto isso, entenda o “*NULL”* como o chão da pilha virtual.
    
    ```c
    node* initStack()
    {
        // aloca um espaco na memoria para a pilha
        node *init = (node*) malloc(sizeof(node));
    
        // coloca um dado vazio 
        // pois pilhas devem ser inicializadas com NULL
        // ja que sua base sempre apontara para NULL
        init = NULL;
    
        // retorna um ponteiro para a pilha
        return init;
    }
    ```
    

> Atenção
> 
> 
> Antes de entrarmos nas operações básicas de manipulação, é necessário entender o básico do funcionamento do encadeamento de dados.
> 
> - Cada posição tem um dado e, ao mesmo tempo, aponta para a próxima posição.
> - Ou seja, [dado] → [próximo dado].
> - Por isso, todo cuidado deve ser tomado, para que o encadeamento não seja perdido.

- Push (stackUp)
    - Já que os dados são adicionados no topo, é necessário que:
        1. O dado novo fique em cima.
        2. Ele aponte para o próximo item.
        3. Esse próximo item tenha o encademamento anterior guardado.
    - Logo, a seguinte linha de raciocínio pode ser formada:
        1. Um novo espaço de memória deve ser alocado — vamos chamá-lo de *new*.
        2. *new* é do tipo *node*, portanto, possui o espaço para o topo e para o próximo item.
        3. Por fim, entendi que [dado de *new*] = recebe dado do usuário. [próximo item em relação a *new*] → [pilha].
        4. Essa última parte ocorre, pois, na minha concepção, a realocação da referencia de memoria da pilha é necessária para que a cadeia de informação não seja perdida.
    
    ```c
    node* stackUp(node* stack, int data)
    {
        // um espaco novo eh alocado para receber o dado
        node* new = (node*) malloc(sizeof(node));
    
        // o topo recebe o dado do usuario
        new->top = data;
    
        // o proximo item recebe a pilha 
        new->next = stack;
    
        // pilha eh atualizada
        stack = new;
    
        return stack;
    }
    ```
    
- Pop
    - Por padrão, remove apenas o topo da pilha.
    - Nesse momento você me pergunta:
        
        > “*AAA assim ta fácil, é so tirar o topo né?”*
        > 
    - Sim, no entanto, lembre-se sempre dos cuidados especiais que o encadeamento necessita.
    - Logo, é preciso que, algo armazene o topo antes que o topo seja reescrito pelas proximas informações da pilha.
    
    ```c
    node* pop(node* stack)
    {
        // auxRemove eh usado para que, ao remover,
        // o encadeamento nao seja perdido
        int auxRemove;
    
        // auxiliar recebe o topo
        auxRemove = stack->top;
    
        // pilha recebe o proximo
        stack = stack->next;
    
        return stack;
    }
    ```
    

> Conclusão
> 
> - Nesse readme, você leu apenas sobre o básico da pilha, ou seja, como você inicia, insere e tira dados dela.
> - Agora, é necessário que você leia as outras funções implementadas para que essa estrutura fique fixa na sua mente.
> - Desde já, obrigado por ler, bons estudos, e fique a vontade para abrir issues.
