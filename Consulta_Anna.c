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
	MYSQL *mysql_conn;
	char consulta [80];
	conn = mysql_init(NULL);
	err=mysql_query(mysql_conn,consulta);
	
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
	
	strcpy(consulta,"SELECT Partida.Id FROM Partida WHERE Partida.final = (SELECT MAX(Partida.final) FROM Partida)");
	// quieren saber si el nombre es bonito
	err=mysql_query(mysql_conn,consulta);
	
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(mysql_conn), mysql_error(mysql_conn));
		exit (1);
	}
	
	resultado = mysql_store_result (mysql_conn);
	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else		
		printf("La partida mas larga es Id_Partida %s\n",row[0]);
	mysql_close(conn);
}
