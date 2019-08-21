#include "list.h"
using namespace std;
/**
 *Constructor
 */
template<typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}


template<typename T>
/**
 * @brief List<T>::add_head Añade el dato al inicio de la lista
 * @param data_: El dato
 */
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}


template<typename T>
/**
 * @brief List<T>::del_all Elimina todos los nodos
 */
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}


template<typename T>
/**
 * @brief List<T>::del Elimina el nodo al inicio de la lista
 */
void List<T>::del()
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;

    m_head = temp->next;

}


template<typename T>
/**
 * @brief List<T>::edit_pos Edita un nodo por posicion
 * @param pos: posicion ingresada
 * @param data_: dato ingresado
 */
void List<T>::edit_pos(int pos, T data_) {

    Node<T> *aux;
    Node<T> *new_node = new Node<T> (data_);
    int i=1;
    aux = m_head;
    while(i!=pos){
        aux=aux->next;
        i++;
    }
    aux->data = new_node->data;


}


template<typename T>
/**
 * @brief List<T>::obt_pos Obtiene un nodo por posicion
 * @param pos: posicion ingresada
 * @return
 */
int List<T>::obt_pos(int pos)
{
    Node<T> *aux;
    int i=1;
    aux=m_head;
    while(i!=pos){
        aux=aux->next;
        i++;
    }
    cout<<"El puntero en esa posiciòn de la lista es "<<aux->data<<endl;
    return aux->data;

}


template<typename T>
/**
 * @brief List<T>::add_end Inserta al final de la lista
 * @param data_
 */
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}


template<typename T>
/**
 * @brief List<T>::fill_by_user Llena la lista uno por uno
 * @param dim: dimension de la lista
 */
void List<T>::fill_by_user(int dim)
{
    T ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}

template<typename T>
/**
 * @brief List<T>::fill_random Lena la lista de manera aleatoria
 * @param dim
 */
void List<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}


/**
 *Imprime la lista
 */
template<typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

template<typename T>
List<T>::~List() {}
