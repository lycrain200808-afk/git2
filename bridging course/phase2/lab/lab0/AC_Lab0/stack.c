// stack2.c - LIFO stack
// Implementation of Stack by linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct input {
   int num;
   struct input *below;   /* pointer to successor on stack */
} node;

node *top = NULL;    /* pointer to top node on stack */

void push(node tr );
void pop( char ch );
void free_stack(void);

int main() {
     FILE *indata = fopen("C:\\Users\\Rain\\Desktop\\AC_Lab0\\postfix.inf", "r");
     if (indata == NULL) {
          printf("Error opening file\n");
          return 1;
     }
     node t, *ptr;
     char ch;

   //  clrscr();

	// printf ("\n size = %d", sizeof(node));

     /* do stack operations until user signals halt */
     while ( (ch = fgetc(indata)) != EOF ){
          if (ch >= '0' && ch <= '9'){
               t.num = ch - '0';
               printf("%d", t.num);
               push(t);
          } else {
	       switch ( ch ) {
	       case '=': /* get a node and add it to stack */
		    printf(" = ");
              printf("%d\n", top->num);
		    break;
	       case '+': 
            case '-': 
            case '*':
            case '/':
            /* delete a node from stack and print it */
              pop(ch);
		    break;
	       case '\n':
             top = NULL;
             break;
	       }
	     }
     }
     free_stack();
     return 0;
}

/*   If the stack is full, push returns NULL. Otherwise, push
     allocates storage for a node, copies the data passed into the
     allocated storage, adds the node to the linked list, updates top
     and the current size of the stack, and returns the address of
     the node added. */

void push(node tr ){
     node *ptr;
     ptr = (node *) malloc( sizeof ( node ) ); /* new TRAY */
     *ptr = tr;   /* store data */
     ptr -> below = top; /* push it on stack */
     top = ptr;   /* update top */

     return;
}

/*   If the stack is empty, pop returns NULL. Otherwise, pop copies
     the top node to permanent storage, updates top, frees the stack
     storage, updates the current size of the stack, and returns the
     address of the popped node.   */

void pop( char ch ) {
     node *ptr;

     if ( top == NULL )   /* empty stack? */
	  return;
     
     ptr = top;       /* save address of 1st node for garbage collection */
     top = top -> below;    /* update top */
     
     switch ( ch ) {  
      case '+': 
      printf("+");
      top->num = top->num + ptr->num;
      break;
      case '-': 
      printf("-");
      top->num = top->num - ptr->num;
      break;
      case '*':
      printf("*");
      top->num = top->num * ptr->num;
      break;
      case '/':    
      printf("/");
      top->num = top->num / ptr->num;
      break;
      free( ptr );
     }         /* collect garbage */

     return;
}
