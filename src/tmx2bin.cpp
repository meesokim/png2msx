#include <locale.h>

#include "comun/funciones.h"
#include "comun/endian.h"
#include "comun/cadena.h"
#include "comun/archivo.h"
#include "comun/color.h"
// #include "comun/tiempo.h"
#include "comun/matematicas.h"
#include "comun/tabla.h"
#include "comun/matriz.h"
#include "comun/lista.h"
#include "comun/contenedor.h"
#include "comun/compresor.h"
#include "comun/mapaxml.h"
// #include "comun/formato_png.h"
#include "comun/pletter.h"

int main( int argc, char *argv[] ) {

	// Activamos el el idioma local:
    setlocale( LC_ALL, ".ACP" );
    // setlocale( LC_ALL, "C" );

	if( argc == 1 ) {
		printf( "ruta: %s\n", argv[0] );
	}
	printf( "Proyecto en construcci�n\n" );
	
	MapaXML xml;
	if( xml.inicia( "../mapas/", "untitled.tmx" ) ) {
		printf( "mapa cargado\n" );
	} else {
		printf( "error\n" );
		xml.quita();
		return 1;
	}

	printf( "Versi�n: %s\n", xml.map.version.dameCadena() );

	printf( "Orientaci�n: " );
	switch( xml.map.orientation ) {
		case no_orientation: printf( "sin orientaci�n\n" ); break;
		case orthogonal:	 printf( "ortogonal\n" ); break;
		case isometric:		 printf( "isom�trica\n" ); break;
		case staggered:		 printf( "isom�trica\n" ); break;
		default:			 printf( "sin determinar\n" );
	}
	
	printf( "Ancho: %u\n", xml.map.width  ); // unsigned int
	printf( "Alto:  %u\n", xml.map.height ); // unsigned int

	printf( "Ancho de la baldosa: %u\n", xml.map.tilewidth  );	// unsigned int
	printf( "Alto de la baldosa : %u\n", xml.map.tileheight );	// unsigned int

//	Color backgroundcolor;			// The background color of the map. (since 0.9, optional) 

//	RenderOrderType renderorder;	// The order in which tiles on tile layers are rendered.

//	Lista< XML_property > property;
	printf( "Propiedades: %u\n", xml.map.property.dameLongitud() ); // size_t 
	
//	Lista< XML_tileset > tileset;
	printf( "Baldosas: %u\n", xml.map.tileset.dameLongitud() ); // size_t 
	
//	Lista< XML_layer   > layer;	
	printf( "Capas: %u\n", xml.map.layer.dameLongitud() ); // size_t 

//	Lista< XML_objectgroup > objectgroup;
	printf( "Objetos: %u\n", xml.map.objectgroup.dameLongitud() ); // size_t 
	
	xml.quita();
	
	return 0;
}


