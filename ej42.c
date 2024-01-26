/*
      Implementa tabla hash en modalidad open hash (separate chaining)
      Corrida de prueba:
      C:\> ej42 < inputej42.txt
*/

#include <stdio.h>
#include <malloc.h>

const int h_size = 12007;   /*  12007  es primo  */
const int nom_size = 64;    /*  suficiente para un nombre cient�fico  */

struct node
{
   int key;
   char item[nom_size];
   char deleted;          /*  0: presente, 1: eliminado  */
   struct node * clash;
};

typedef struct node celda;   /* ojo: celda no es apuntador */

void iniciaarreglo(celda *);
int hash(char *);
int index(int);
void ingresavec(celda *, int);
void preinsercion(celda *, char *);
void insertitemintable(celda *, char *);
celda * insertinlist(celda *, int, char *);
void setitem(celda *, int, char *);
void printtable(celda *, int, int);
int ismemberitem(celda *, char *);
int deleteitem(celda *, char *);
celda * getaddress(celda *, char *);
celda * tracklist(celda *, char *);
int comparapalab(char *, char *);

void main()
{
    int tam;
    /* esperamos alrededor de 12 mil entradas*/
    celda tabla[h_size];   /* 12007, 12011, 12037 son primos */
    iniciaarreglo(tabla);
    puts("Cu�ntos elementos quieres agregar?");
    scanf("%d\n", &tam);  /* se requiere sacar el Return del buffer */
    ingresavec(tabla, tam);
    puts("\n\n Imprimir la tabla completa:\n");
    printtable(tabla, 0, 0);
    puts("\nCu�ntos elementos quieres eliminar?");
    scanf("%d\n", &tam);  /* se requiere sacar el Return del buffer */
    while(tam > 0)
    {
       char pal[nom_size];
       int garbg;
       gets(pal);
       printf("\nEliminando %d: %s", tam, pal);
       garbg = deleteitem(tabla, pal);
       tam = tam - 1;
    }
    puts("\n\n Imprimir la tabla completa:\n");
    printtable(tabla, 0, 0);
}

/*  no ser� recursiva s�lo por motivos de eficiencia  */
void iniciaarreglo(celda * tabla)
{
   int cont = 0;
   while(cont < h_size)
   {
      tabla -> key = 0;
      tabla -> clash = NULL;
      tabla = tabla + 1;
      cont = cont + 1;
   }
}

void ingresavec(celda * tabla, int tam)
{
   char nom[nom_size];
   if(tam == 0)
      return;
   gets(nom);
   preinsercion(tabla, nom);
   ingresavec(tabla, tam - 1);
}

void preinsercion(celda * tabla, char * nom)
{
   int membresia;
/*    ismemberitem verifica si ya est� en la tabla:
      0 no es miembro, 1 s� es miembro, -1 est� borrado  */
   if((membresia = ismemberitem(tabla, nom)) == 1)
      printf(" %s ya es miembro de la tabla.\n", nom);
   else
   if(membresia == -1)
      getaddress(tabla, nom) -> deleted = 0;      
   else    /*   membresia cero   */
      insertitemintable(tabla, nom);
}

void insertitemintable(celda * tabla, char * nom)
{
   int itemkey = 0, tableindex, membresia;
   itemkey = hash(nom);
   tableindex = index(itemkey);
   printf("Ingresando: %d, %d, %s\n", tableindex, itemkey, nom);
   if((tabla + tableindex) -> key == 0)
      setitem(tabla + tableindex, itemkey, nom);
   else   /*  ojo: viene una ejecuci�n escrita en dos l�neas  */
      (tabla + tableindex) -> clash =
          insertinlist((tabla + tableindex) -> clash, itemkey, nom );
}

celda * insertinlist(celda * current, int itemkey, char * nom)
{
   if(current == NULL)
   {
      current = malloc(sizeof(celda));
 /*   if current == NULL then Error ... Lo dejar� pendiente */
      setitem(current, itemkey, nom); 
   }
   else
      current -> clash = insertinlist(current -> clash, itemkey, nom);
   return(current);
}

void setitem(celda * elem, int itemkey, char * nom)
{
   char * point;
   elem -> key = itemkey;
   point = elem -> item;
   while(*point++ = *nom++);    /*  el cl�sico copia string */
   elem -> deleted = 0;      /*  0: presente, 1: eliminado  */
   elem -> clash = NULL;
}

/*
   toma el segundo, tercero y cuarto car�cter del g�nero y
   construye un n�mero de base 26
   toma el primero y segundo car�cter de la etiqueta de
   especie y construye un n�mero con base 26
   ... y los suma
*/
int hash(char * nombre)
{
    int busca, localkey;
    localkey = (*(nombre + 1) - 96) * (26 * 26) + 
               (*(nombre + 2) - 96) * 26 +
               (*(nombre + 3) - 96);
    busca = 0;
    while(*(nombre + busca) > ' ')
       busca = busca + 1;
    localkey = localkey + (*(nombre + busca + 1) - 96) * 26 + 
                          *(nombre + busca + 2) - 96;
 /*
     si deseas verificar los caracteres y el valor
     que se toma para el c�lculo saca del comentario
     a la funci�n printf:   ( ... 96+1 es el ascii de 'a' )
    printf("\n %c: %d; %c: %d; %c: %d; \n blanco: %d      \
            \n %c: %d; %c: %d; \n",
             *(nombre + 1), (*(nombre + 1) - 96),
             *(nombre + 2), (*(nombre + 2) - 96),
             *(nombre + 3), (*(nombre + 3) - 96),
             busca,
             *(nombre + busca + 1), *(nombre + busca + 1) - 96,
             *(nombre + busca + 2), *(nombre + busca + 2) - 96
          );
 */
    return(localkey);
}

int index(int itemkey)
{
   /*  if itemkey < h_size then ;  ... lo dejar� pendiente */
   return(itemkey % h_size);
}

/*
   primero decide si deber� imprimir el elemento actual,
   despu�s decide si debe continuar con el siguiente
   elemento de la lista (key repetida) o ...
   seguir con el siguiente elemento del arreglo
*/
void printtable(celda * vec, int cont, int flag)
{
   celda * lateral;   /* para los que tienen id�ntica llave key */
   while(cont < h_size)  /*   Refactoring 1: reescribir recursiva */
   {
      if((vec -> key != 0) && (vec -> deleted == 0))
         printf("\n %d   %s", vec -> key, vec -> item);
      if(vec -> clash != NULL)
      {
         lateral = vec -> clash;
         while(lateral)   /*   Refactoring 2: sacar a una funci�n */
         {
            if((lateral -> key != 0) && (lateral -> deleted == 0))
               printf("\n %d   %s", lateral -> key, lateral -> item);
            lateral = lateral -> clash;
         }
         lateral = NULL;  /*  mejor no eliminar  */
      }
      vec = vec + 1;
      cont = cont + 1;
   }
   putchar('\n');
}

/*   1:  s� es miembro,
     0:  no es miembro,
    -1:  fue miembro pero ya est� eliminado */
int ismemberitem(celda * tabla, char * nombre)
{
   celda * itemaddress;
   if(itemaddress = getaddress(tabla, nombre))
   {
      if(itemaddress -> deleted == 0)
         return(1);
      else
         return(-1);    /*  Uops! fue eliminado */
   }
   else    /*    itemaddress == NULL    */
      return(0);
}

/*   1:  borrado exitoso, 
     0:  fracas� al borrar por que no es miembro,
    -1:  ya hab�a sido "eliminado"   */
int deleteitem(celda * tabla, char * nombre)
{
   celda * itemaddress;
   if(itemaddress = getaddress(tabla, nombre))
   {
      if(itemaddress -> deleted == 0)
      {
         itemaddress -> deleted = 1;   /*  b�rralo  */
         return(1);
      }
      else
         return(-1);    /*  Uops! ya hab�a sido borrado */
   }
   else    /*    itemaddress == NULL    */
   {
      puts("Error. FunciOn: deleteitem.\
 El elemento no estA en la colecci�n.");
      return(0);
   }
}

/*  regresa la direcci�n del registro que aloja el
    nombre � NULL si el nombre no est� en la colecci�n  */
celda * getaddress(celda * tabla, char * nombre)
{
   int tableindex;
   tableindex = index(hash(nombre));
   if((tabla + tableindex) -> key == 0)
      return(NULL);
   else
   if(comparapalab((tabla + tableindex) -> item, nombre) == 0)
      return(tabla + tableindex);
   else
      return(tracklist(tabla + tableindex, nombre));
}

/*    auxiliar de getaddress   */
celda * tracklist(celda * vec, char * nombre)
{
   if(vec == NULL)
      return(NULL);
   else
   if(comparapalab(vec -> item, nombre) == 0)
      return(vec);
   else
      return(tracklist(vec -> clash, nombre));
}

/*
      regresa 0 si las palabras son iguales,
      si son diferentes regresa la diferencia:
      positivo: la primera es mayor que la segunda
      negativo: la primera es menor que la segunda    */
int comparapalab(char * pal1, char * pal2)
{
   if((*pal1 == '\0') && (*pal2 == '\0'))
      return(0);
   else
   if(*pal1 == *pal2)
      return(comparapalab(pal1 + 1, pal2 + 1));   
   else
      return((int)*pal1 - (int)*pal2);
}
