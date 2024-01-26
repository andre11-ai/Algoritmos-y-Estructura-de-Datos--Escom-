/*
     Implementa el TDA Lista ligada
*/

#include <stdio.h>
#include <malloc.h>

struct nodo
{
   char elem;
   struct nodo * sig;
};

typedef struct nodo * LIST;

LIST newlist(void);           /*  constructora  */
int isemptylist(LIST);        /*  observadora  */
char head(LIST);              /*  observadora  */
LIST tail(LIST);              /*  función con linaje  */
LIST inserthead(LIST, char);  /*  constructora  */
void printlist(LIST);         /*  observadora  */
void auxprintlist(LIST);      /*  observadora  */
LIST append(LIST, LIST);      /*  función con linaje  */
LIST appendaux(LIST, LIST);

void main()
{
   LIST l1, l2, l3, l4;
   l1 = inserthead(inserthead(newlist(),'b'), 'a');
   puts("Lista l1:  ");
   printlist(l1);
   l2 = inserthead(inserthead(newlist(),'d'), 'c');
   puts("\n Lista l2:  ");
   printlist(l2);
   l3 = newlist();
   puts("\n append l1, l3: ");
   l1 = append(l1, l3);
   printlist(l1);
   puts("\n append l3, l2: ");
   l2 = append(l3, l2);
   printlist(l2);
   l4 = newlist();
   l4 = append(l2,l1);
   puts("\n Resultado (l4 = app(l2,l1): ");
   printlist(l4);
   puts("\n\n ojo: efecto lateral (l2): ");
   printlist(l2);
   putchar('\n');
}

LIST newlist()
{
   LIST ancla;
   ancla = malloc(sizeof(struct nodo));
   if(ancla == NULL)
      puts("Problema grave en newlist. Memoria agotada.");
   else
   {
      ancla -> elem = '\0';
      ancla -> sig = NULL;
   }
   return(ancla);
}

int isemptylist(LIST mili)
{
   return(mili -> sig == NULL);
}

char head(LIST mili)
{
   if(isemptylist(mili))
   {
      puts("ERROR. Función: head. Lista vacía.");
      return('\0');
   }
   else
      return(mili -> sig -> elem);
}

LIST tail(LIST mili)
{
   LIST ancla;
   if(isemptylist(mili))  /* isemptylist prueba a: mili -> sig  */
   {
      puts("Error. Función: tail. Lista vacía");
      return(mili);
   }
   if(isemptylist(mili -> sig))
   {
      return(newlist());
   }
   else
   {
      ancla = newlist();
      ancla -> sig = mili -> sig -> sig;
      return(ancla);
   }
}

LIST inserthead(LIST mili, char c)
{
   LIST ancla;
   ancla = newlist();
   ancla -> elem = c;
   ancla -> sig = mili -> sig;
   mili -> sig = ancla;
   return(mili);
}

void printlist(LIST mili)
{
   if(isemptylist(mili))
      ;
   else
      auxprintlist(mili -> sig);
}

void auxprintlist(LIST mili)
{
   if(mili == NULL)    /* ojo: está fuera de la defición de lista */
      ;
   else
   {
      putchar(mili -> elem);
      auxprintlist(mili -> sig);
   }
}

/*     append(primera, segunda)
       agrega segunda al final de primera     */
LIST append(LIST mili, LIST apli)
{
   if(isemptylist(apli))
      return(mili);
   else
   if(isemptylist(mili))
   {
      mili = apli;
      return(mili);
   }
   else
   {
      mili = appendaux(mili, apli);
      return(mili);
   }
}

/* appendaux recibe ambas listas completas, con su anclaje */
LIST appendaux(LIST mili, LIST apli)
{

   puts("\n   Rastreo de appendaux: ");
   printlist(mili); putchar('\n'); printlist(apli); putchar('\n');

   if(mili -> sig == NULL)
   {
      mili -> sig = apli -> sig;
      return(mili);
   }
   else
   {
      mili -> sig = appendaux(mili -> sig, apli);
      return(mili);
   }
}
