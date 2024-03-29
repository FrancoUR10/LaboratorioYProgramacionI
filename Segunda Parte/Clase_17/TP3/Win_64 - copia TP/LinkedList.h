/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
/** \brief Crea una lista en memoria
 *
 * \param void
 * \return LinkedList* La posicion de memoria de la lista
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief Devuelve la cantidad de elementos que estan dentro de la lista
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Agrega un elemento dentro de la lista
 *
 * \param this LinkedList*
 * \param pElement void* Un puntero a void
 * \return int
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Devuelve el objeto que esta en un indice de la lista
 *
 * \param this LinkedList*
 * \param index int
 * \return void*
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief Pone un elemento arriba de otro
 *
 * \param this LinkedList*
 * \param index int
 * \param pElement void*
 * \return int
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief Remueve un elemento de la lista
 *
 * \param this LinkedList*
 * \param index int
 * \return int
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief Borra todos los elementos de la lista en memoria
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_clear(LinkedList* this);

/** \brief Elimina todo el espacio en memoria con todos sus elementos
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_deleteLinkedList(LinkedList* this);

/** \brief Le paso una referencia y me dice donde esta
 *
 * \param this LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** \brief Me dice si hay algo en la lista o no
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_isEmpty(LinkedList* this);

/** \brief Agrega un elemento al indice indicado,
 * metiendo un espacio en el medio si se encuentra ocupado
 *
 * \param this LinkedList*
 * \param index int
 * \param pElement void*
 * \return int
 *
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** \brief Antes de borrar un elemento lo devuelve
 *
 * \param this LinkedList*
 * \param index int
 * \return void*
 *
 */
void* ll_pop(LinkedList* this,int index);

/** \brief Me pasa un elemento y me dice si esa lista lo contiene
 *
 * \param this LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int ll_contains(LinkedList* this, void* pElement);

/** \brief Me dice si los elementos del segundo parametro
 * estan en la primer lista
 *
 * \param this LinkedList*
 * \param this2 LinkedList*
 * \return int
 *
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** \brief Me devuelve una sub lista
 *
 * \param this LinkedList*
 * \param from int
 * \param to int
 * \return LinkedList*
 *
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief Crea una copia identica de la lista
 *
 * \param this LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* ll_clone(LinkedList* this);

/** \brief Ordena los elementos de la lista
 *
 * \param void*
 * \param void*
 * \return int ll_sort(LinkedList* this, int
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
