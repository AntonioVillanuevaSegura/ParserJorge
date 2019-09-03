# coding=utf-8
#Antonio Villanueva Segura 
#Un ensayo en python3 del programa en c anterior 

import math
#Nombre del fichero con los datos
FICHERO ='fichero.txt'

#*******************************************************************************
def caudal(valor):
	"""Calculo caudal fake funcion"""
	return str (valor*2)+' litros/min'
#*******************************************************************************	
def presion(valor):
	"""Calculo presion fake funcion"""
	return str(round (valor*3,3))+' psi'
#*******************************************************************************	
def temperatura(valor):
	"""Calculo temperatura fake funcion"""
	return str(valor*4)+' celsius'
#*******************************************************************************	
def altura(valor):
	"""Calculo altura fake funcion"""
	return str (valor*5)+' m'			
#*******************************************************************************	
def obtieneNumero(linea):
	"""Recupera numero float despues del caracter ':' en la linea"""
	if ':' in linea:#Verifica que incluye el caracter :
		return float ( linea.split(':')[1].rstrip())
#*******************************************************************************		
def obtieneNombre(linea,variables):
	"""Recupera el nombre en mayusculas en la linea CAUDAL,PRESION ..."""
	for nombre in variables:#Recorre las lineas
		if nombre in linea:#Si existe este nombre e
			return nombre
#*******************************************************************************					
def funcionVariable(nombre,valor):
	"""Imprime el nombre y  resultado para cada variable"""
	if nombre=='CAUDAL':
		print(nombre,' : ',caudal(valor))
	if nombre=='PRESION':
		print(nombre,' : ',presion(valor))
	if nombre=='TEMPERATURA':
		print(nombre,' : ',temperatura(valor))
	if nombre=='ALTURA':
		print(nombre,' : ',altura(valor))						
	

#*******************************************************************************
#                               MAIN   LOOP
#*******************************************************************************
format(math.pi, '.2f')   # give 2 digits after the point
variables=('CAUDAL','PRESION','TEMPERATURA','ALTURA')

with open(FICHERO, 'r') as fichero_texto:
	for linea in fichero_texto:#Lee linea a linea el fichero
		funcionVariable(obtieneNombre(linea,variables),obtieneNumero(linea))


