#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <mysql.h>

void main() {
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta [80];
	conn = mysql_init(NULL);
	
	if (conn==NULL)
	{

		printf ("Error al crear la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	conn = mysql_real_connect (conn, "localhost","root", "mysql",
			"Juego",0, NULL, 0);
	if (conn==NULL)
	{

		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	/////
	char nombre[20];
	
	puts("Sobre que jugador quieres saber su estado:");
	scanf("%s", nombre);
	char str_query[512];
	
	sprintf(str_query, "SELECT Conectat FROM Jugadors WHERE Usuari= '%s'", nombre);

	err=mysql_query (conn, str_query);
	if (err!=0)
	{
		printf ("Error al consultar datos de la base %u %s \n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	int consulta1 = atoi(row[0]);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else{
		
		if (consulta1==1)
		printf ("%s esta conectado\n",nombre);
		if (consulta1==0)
		printf("%s no esta conectado \n",nombre);
		while (row != NULL)
		{
			if (consulta1==1)
				printf ("%s esta conectado\n",nombre);
			if (consulta1==0)
				printf("%s no esta conectado \n",nombre);
			
			row = mysql_fetch_row (resultado);
			int consulta1 = atoi(row[0]);
		}
	}
	mysql_close(conn);
		
}
