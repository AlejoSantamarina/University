CREATE SCHEMA IF NOT EXISTS tp3_p2_ej1;
SET search_path TO tp3_p2_ej1;

DROP TABLE IF EXISTS Alumno, Articulo, Contiene, Curso, Equipo, Grabacion, Grabacion_comercial, Grabacion_no_propia, Inscripto, Palabra CASCADE;

-- Created by Redgate Data Modeler (https://datamodeler.redgate-platform.com)
-- Last modification date: 2026-05-21 19:02:52.214

-- tables
-- Table: Alumno
CREATE TABLE Alumno (
    LU int  NOT NULL,
    nombre varchar(40)  NOT NULL,
    provincia varchar(30)  NOT NULL,
    CONSTRAINT Alumno_pk PRIMARY KEY (LU)
);

-- Table: Articulo
CREATE TABLE Articulo (
    id_articulo int  NOT NULL,
    titulo varchar(120)  NOT NULL,
    autor varchar(30)  NOT NULL,
    fecha_pub date  NOT NULL,
    CONSTRAINT Articulo_pk PRIMARY KEY (id_articulo)
);

-- Table: Contiene
CREATE TABLE Contiene (
    Articulo_id_articulo int  NOT NULL,
    Palabra_cod_p int  NOT NULL,
    Palabra_idioma varchar(2)  NOT NULL,
    CONSTRAINT Contiene_pk PRIMARY KEY (Articulo_id_articulo)
);

-- Table: Curso
CREATE TABLE Curso (
    cod char(4)  NOT NULL,
    descripcion varchar(40)  NOT NULL,
    tipo varchar(100)  NOT NULL,
    Curso_cod char(4)  NULL,
    CONSTRAINT Curso_pk PRIMARY KEY (cod)
);

-- Table: Equipo
CREATE TABLE Equipo (
    nro_equipo int  NOT NULL,
    descripcion varchar(50)  NOT NULL,
    CONSTRAINT Equipo_pk PRIMARY KEY (nro_equipo)
);

-- Table: Grabacion
CREATE TABLE Grabacion (
    nro_grabacion int  NOT NULL,
    casa_discografica varchar(50)  NOT NULL,
    fecha_grabacion date  NOT NULL,
    CONSTRAINT Grabacion_pk PRIMARY KEY (nro_grabacion)
);

-- Table: Grabacion_comercial
CREATE TABLE Grabacion_comercial (
    Equipo_nro_equipo int  NOT NULL,
    Grabacion_nro_grabacion int  NOT NULL,
    CONSTRAINT Grabacion_comercial_pk PRIMARY KEY (Grabacion_nro_grabacion)
);

-- Table: Grabacion_no_propia
CREATE TABLE Grabacion_no_propia (
    duracion time  NOT NULL,
    Grabacion_nro_grabacion int  NOT NULL,
    CONSTRAINT Grabacion_no_propia_pk PRIMARY KEY (Grabacion_nro_grabacion)
);

-- Table: Inscripto
CREATE TABLE Inscripto (
    Alumno_LU int  NOT NULL,
    Curso_cod char(4)  NOT NULL,
    CONSTRAINT Inscripto_pk PRIMARY KEY (Alumno_LU,Curso_cod)
);

-- Table: Palabra
CREATE TABLE Palabra (
    descripcion varchar(25)  NOT NULL,
    cod_p int  NOT NULL,
    idioma varchar(2)  NOT NULL,
    CONSTRAINT Palabra_pk PRIMARY KEY (cod_p,idioma)
);

-- foreign keys
-- Reference: Contiene_Articulo (table: Contiene)
ALTER TABLE Contiene ADD CONSTRAINT Contiene_Articulo
    FOREIGN KEY (Articulo_id_articulo)
    REFERENCES Articulo (id_articulo)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Contiene_Palabra (table: Contiene)
ALTER TABLE Contiene ADD CONSTRAINT Contiene_Palabra
    FOREIGN KEY (Palabra_cod_p, Palabra_idioma)
    REFERENCES Palabra (cod_p, idioma)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Es_referente (table: Curso)
ALTER TABLE Curso ADD CONSTRAINT Es_referente
    FOREIGN KEY (Curso_cod)
    REFERENCES Curso (cod)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Grabacion_comercial_Equipo (table: Grabacion_comercial)
ALTER TABLE Grabacion_comercial ADD CONSTRAINT Grabacion_comercial_Equipo
    FOREIGN KEY (Equipo_nro_equipo)
    REFERENCES Equipo (nro_equipo)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Grabacion_comercial_Grabacion (table: Grabacion_comercial)
ALTER TABLE Grabacion_comercial ADD CONSTRAINT Grabacion_comercial_Grabacion
    FOREIGN KEY (Grabacion_nro_grabacion)
    REFERENCES Grabacion (nro_grabacion)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Grabacion_no_propia_Grabacion (table: Grabacion_no_propia)
ALTER TABLE Grabacion_no_propia ADD CONSTRAINT Grabacion_no_propia_Grabacion
    FOREIGN KEY (Grabacion_nro_grabacion)
    REFERENCES Grabacion (nro_grabacion)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Inscripto_Alumno (table: Inscripto)
ALTER TABLE Inscripto ADD CONSTRAINT Inscripto_Alumno
    FOREIGN KEY (Alumno_LU)
    REFERENCES Alumno (LU)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: Inscripto_Curso (table: Inscripto)
ALTER TABLE Inscripto ADD CONSTRAINT Inscripto_Curso
    FOREIGN KEY (Curso_cod)
    REFERENCES Curso (cod)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- End of file.