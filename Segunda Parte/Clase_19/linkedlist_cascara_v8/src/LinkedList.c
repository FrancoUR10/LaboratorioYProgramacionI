#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* lista=(LinkedList*)malloc(sizeof(LinkedList));
    if(lista!=NULL)
    {
        lista->pFirstNode=NULL;
        lista->size=0;
    }
    return lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        returnAux=lista->size;
    }
    return returnAux;
}

/*
Retorna un puntero al nodo que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.
*/
/** \brief  Obtiene un nodo de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    Node* pNode=NULL;
    int i=0;
    int len=ll_len(lista);
    if(lista!=NULL && nodeIndex > -1 && nodeIndex < len)
    {
        pNode=lista->pFirstNode;
        while(pNode!=NULL && i != nodeIndex)
        {
            pNode=pNode->pNextNode;
            i++;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param lista LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* lista, int nodeIndex)
{
    return getNode(lista, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    Node* pNuevoNodo=NULL;
    Node* pAuxNodo=NULL;
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL && nodeIndex > -1 && nodeIndex <= len)
    {
        pNuevoNodo=(Node*)malloc(sizeof(Node));
        if(pNuevoNodo!=NULL)
        {
            pNuevoNodo->pElement=pElement;
            if(nodeIndex==0)
            {
                pNuevoNodo->pNextNode=lista->pFirstNode;
                lista->pFirstNode=pNuevoNodo;
                lista->size++;
                returnAux=0;
            }
            else
            {
                pAuxNodo=getNode(lista,nodeIndex-1);
                if(pAuxNodo!=NULL)
                {
                    pNuevoNodo->pNextNode=pAuxNodo->pNextNode;
                    pAuxNodo->pNextNode=pNuevoNodo;
                    lista->size++;
                    returnAux=0;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    return addNode(lista,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* lista, void* pElement)
{
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        returnAux=addNode(lista,len,pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* lista, int index)
{
    void* returnAux=NULL;
    Node* pNode=getNode(lista,index);
    if(pNode!=NULL)
    {
        returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* lista, int index,void* pElement)
{
    int returnAux=-1;
    Node* pNode;
    if(lista!=NULL)
    {
        pNode=getNode(lista,index);
        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* lista,int index)
{
    Node* pNode=NULL;
    Node* pAuxNode=NULL;
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL && index > -1 && index < len)
    {
        pNode=getNode(lista,index);
        if(pNode!=NULL)
        {
            if(index==0)
            {
                lista->pFirstNode=pNode->pNextNode;
                free(pNode);
                pNode=NULL;
                lista->size--;
                returnAux=0;
            }
            else
            {
                pAuxNode=getNode(lista,index-1);
                if(pAuxNode!=NULL)
                {
                    pAuxNode->pNextNode=pNode->pNextNode;
                    free(pNode);
                    pNode=NULL;
                    lista->size--;
                    returnAux=0;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* lista)
{
    int returnAux=-1;
    Node* pNode;
    int i=0;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        while(lista!=NULL && i > -1 && i < len)
        {
            pNode=getNode(lista,i);
            free(pNode);
            pNode=NULL;
            i++;
        }
        lista->pFirstNode=NULL;
        lista->size=0;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        ll_clear(lista);
        free(lista);
        lista=NULL;
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param lista LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* lista, void* pElement)
{
    int returnAux=-1;
    Node* pNode=NULL;
    int i=0;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pNode=getNode(lista,i);
            if(pNode!=NULL && pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        if(lista->size==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* lista)
{
    LinkedList* cloneArray=NULL;
    void* auxElement=NULL;
    int i;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(i=0;i<len;i++)
            {
                auxElement=ll_get(lista,i);
                if(auxElement!=NULL)
                {
                    ll_add(cloneArray,auxElement);
                }
            }
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param lista LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order)
{
    int returnAux=-1;
    /*
    int i;
    int j;
    void* auxElement;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {

            }
        }
    }
    */
    return returnAux;

}

