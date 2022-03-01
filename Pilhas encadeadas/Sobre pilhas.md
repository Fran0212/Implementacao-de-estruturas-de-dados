## Pilha encadeada

> Defini??o
> 
> - A pilha encadeada ? uma estrutura de dados, na qual, voc? consegue acessar apenas o ?ltimo elemento ? *LIFO* (*Last In Fist Out*).

### Estrutura

- Uma estrutura chamada *node* foi criada.
- Essa, que, por sua vez, possui os dados do topo (*top)* e os pr?ximos (*next).*

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

- Inicializa??o
    - A pilha deve ser inicializada com null pois sua base sempre aponta para o vazio.
    - Por mais estranho que isso pare?a, pense: uma pilha ? na vida real ? tem uma base que fica sempre no ch?o, logo, ela sempre aponta para onde n?o tem nada.
    - Visto isso, entenda o ?*NULL?* como o ch?o da pilha virtual.
    
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
    

> Aten??o
> 
> 
> Antes de entrarmos nas opera??es b?sicas de manipula??o, ? necess?rio entender o b?sico do funcionamento do encadeamento de dados.
> 
> - Cada posi??o tem um dado e, ao mesmo tempo, aponta para a pr?xima posi??o.
> - Ou seja, [dado] ? [pr?ximo dado].
> - Por isso, todo cuidado deve ser tomado, para que o encadeamento n?o seja perdido.

- Push (stackUp)
    - J? que os dados s?o adicionados no topo, ? necess?rio que:
        1. O dado novo fique em cima.
        2. Ele aponte para o pr?ximo item.
        3. Esse pr?ximo item tenha o encademamento anterior guardado.
    - Logo, a seguinte linha de racioc?nio pode ser formada:
        1. Um novo espa?o de mem?ria deve ser alocado ? vamos cham?-lo de *new*.
        2. *new* ? do tipo *node*, portanto, possui o espa?o para o topo e para o pr?ximo item.
        3. Por fim, entendi que [dado de *new*] recebe dado do usu?rio. [pr?ximo item em rela??o a *new*] ? [pilha].
        4. Essa ?ltima parte ocorre, pois, na minha concep??o, a realoca??o da referencia de memoria da pilha ? necess?ria para que a cadeia de informa??o n?o seja perdida.
    
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
    - Por padr?o, remove apenas o topo da pilha.
    - Nesse momento voc? me pergunta:
        
        > ?*AAA assim ta f?cil, ? so tirar o topo n???*
        > 
    - Sim, no entanto, lembre-se sempre dos cuidados especiais que o encadeamento necessita.
    - Logo, ? preciso que, algo armazene o topo antes que o topo seja reescrito pelas proximas informa??es da pilha.
    - Assim voc? evita que, os dados se percam no processo.
    
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
    

> ### Conclus?o
> 
> - Nesse readme, voc? leu apenas sobre o b?sico da pilha, ou seja, como voc? inicia, insere e tira dados dela.
> - Agora, ? necess?rio que voc? leia as outras fun??es implementadas para que essa estrutura fique fixa na sua mente.
> - Desde j?, obrigado por ler, bons estudos, e fique a vontade para abrir issues e tirar d?vidas.