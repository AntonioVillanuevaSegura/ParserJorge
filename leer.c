#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOMBRE_FICHERO "fichero.txt"
//---------------------------------------------------------------------- 
// FUNCIONES ESPECIFICAS PARA TRATAR CADA TIPO DE INFORMACION 
//---------------------------------------------------------------------- 

double caudal(double valor){
	//Funcion para tratar caudal	
	
	return valor*2;//Retorno de un valor ejemplo 
}
//----------------------------------------------------------------------
double presion(double valor){
	//Funcion para tratar presion	
	return valor*3;//Retorno de un valor ejemplo 
}
//----------------------------------------------------------------------
double temperatura(double valor){
	//Funcion para tratar temperatura	
	return valor*4;//Retorno de un valor ejemplo 
}
//----------------------------------------------------------------------
double altura(double valor){
	//Funcion para tratar altura
	return valor*5;//Retorno de un valor ejemplo 	
}

//----------------------------------------------------------------------
//FUNCIONES OBTENCION DE DATOS NUMERICOS Y TEST DE INFORMACION
//---------------------------------------------------------------------- 
double obtieneNumero(char linea[1024]){
	//Busca el caracter : devuelve numero asociado 
	char *num;
	double n;
	
	num=strrchr(linea,':');//Busca : en esta linea
	n=atof (++num);//Avanza : queda solo el numero
	return n;//Retorna un double 
}
//----------------------------------------------------------------------
int existePalabra(char linea [256],char  palabra [64]){
	//Existe la palabra clave en esta linea ? 1 Si 0 No
	//Buscamos CAUDAL PRESION TEMPERATURA ALTURA 
	return (int ) (strstr(linea,palabra)!=NULL ?  1:0) ;	 
}
//---------------------------------------------------------------------- 
// MAIN BUCLE DE LA FUNCION  
//---------------------------------------------------------------------- 
int main() {
	
    char linea[1024];//Buffer lectura de lineas
    FILE *fich;
 
    fich = fopen(NOMBRE_FICHERO, "r");

    //Lectura lineas del fichero texto  
    while(fgets(linea, 1024, (FILE*) fich)) {
		//Parser ,Busca palabras clave para tratar la informacion ...
      
      if (existePalabra(linea,"CAUDAL")==1){//Existe CAUDAL en esta linea ?		  
		  printf ("C A U D A L = %.2f\n",caudal(obtieneNumero(linea)));
	  }
	  	  
      if (existePalabra(linea,"PRESION")==1){//Existe PRESION en esta linea ?		  
		  printf ("P R E S I O N = %.2f\n",presion(obtieneNumero(linea)));
	  }
	  
      if (existePalabra(linea,"TEMPERATURA")==1){//Existe TEMPERATURA en esta linea ?		  
		  printf ("T E M P. = %.2f\n",temperatura(obtieneNumero(linea)));
	  }
	  
      if (existePalabra(linea,"ALTURA")==1){//Existe ALTURA en esta linea ?		  
		  printf ("A L T U R A= %.2f\n",altura(obtieneNumero(linea)));
	  }	  	  	    
      
    }
    
    fclose(fich);//Cierre del fichero abierto 
}
