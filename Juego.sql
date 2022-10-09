DROP DATABASE IF EXISTS Juego;
CREATE DATABASE Juego;
USE Juego;

CREATE TABLE Jugadors (
  Id INTEGER AUTO_INCREMENT,
  Usuari VARCHAR(30) NOT NULL,
  Contrasenya VARCHAR(80) NOT NULL,
  Email VARCHAR(255) NOT NULL,
  Conectat INTEGER,
  PRIMARY KEY (id)
)ENGINE = InnoDB;
 
CREATE TABLE Partida (
  Id INTEGER AUTO_INCREMENT,
  Inici DATETIME DEFAULT CURRENT_TIMESTAMP,
  Final DATETIME DEFAULT CURRENT_TIMESTAMP,
  Ganador VARCHAR(30),
  PRIMARY KEY (id)
)ENGINE = InnoDB;

CREATE TABLE Participacio (
  Id_Usuari INTEGER,
  Id_Partida INTEGER,
  Posicio INTEGER,
  FOREIGN KEY (Id_Usuari) REFERENCES Jugadors(Id),
  FOREIGN KEY (Id_Partida) REFERENCES Partida(Id) 
)ENGINE = InnoDB;

INSERT INTO Jugadors(Usuari, Contrasenya, Email,Conectat) VALUES ("Ana", sha2("1111", 256), "Ana@gmail.com",1);
INSERT INTO Jugadors(Usuari, Contrasenya, Email,Conectat) VALUES ("Taha", sha2("2222", 256), "Taha@gmail.com",1);
INSERT INTO Jugadors(Usuari, Contrasenya, Email,Conectat) VALUES ("Alex", sha2("3333", 256), "Alex@gmail.com",1);
INSERT INTO Jugadors(Usuari, Contrasenya, Email,Conectat) VALUES ("Juan", sha2("3333", 256), "Juan@gmail.com",1);


INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));
INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));
INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));
INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));
INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));
INSERT INTO Partida(Final) VALUES (DATE_ADD(CURRENT_TIMESTAMP, INTERVAL RAND()*15 MINUTE));


INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (1, 1, 1);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (2, 1, 2);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (3, 1, 3);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (4, 1, 4);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (1, 2, 4);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (2, 2, 3);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (3, 2, 2);
INSERT INTO Participacio(Id_Usuari, Id_Partida, Posicio) VALUES (4, 2, 1);

