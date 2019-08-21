#include <QCoreApplication>
#include <iostream>
#include "list.h"
#include "list.cpp"
#include "socketserver.h"
/**
 * @brief server inicializa la clase SocketServer
 *
 */
SocketServer *server;

void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

   pthread_exit(NULL);
}

/**
 * Còdigo de cliente- servidor con sockets basado en el tutorial https://www.youtube.com/watch?v=0DdCOwSsFLY
 * Còdigo de la lista basado de https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/
 */

int main(int argc, char *argv[])
{



    server = new SocketServer;
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);


    while (1) {
        string dimension;
        string numero_inicio;
        string msn;
        cin >> msn;
        dimension= "Ingrese la dimension de la lista";
        server->setMensaje(dimension.c_str());
        cin >> msn;
        numero_inicio= "Ingrese el numero que desea agregar al inicio de la lista";
        server->setMensaje(numero_inicio.c_str());



    }



}
