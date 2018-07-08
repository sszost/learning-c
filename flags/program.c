#include <stdio.h>

#define SUNNY   01 // 001
#define RAINING 02 // 010
#define WINDY   04 // 100

struct flags {
	unsigned is_sunny: 1;
	unsigned is_raining: 1;
	unsigned is_windy: 1;
};

typedef struct flags flags_t;

void forecast_flags( flags_t f )
{
	// test if any of the fs are set
	// test if none of the f are set
	if( ( f.is_sunny | f.is_raining ) != 0 && ( f.is_windy ) == 0 )  {
		printf( "%s\n", "take umbrella" );
	} else {
		printf( "%s\n", "dont take umbrella" );
	}
}

void forecast( char f )
{
	// test if any of the fs are set
	// test if none of the f are set
	if( ( f & ( SUNNY | RAINING ) ) != 0 && ( f & WINDY ) == 0 )  {
		printf( "%s\n", "take umbrella" );
	} else {
		printf( "%s\n", "dont take umbrella" );
	}
}

int main( int argc, char *argv[] )
{
	// set flags
	forecast( RAINING | WINDY ); // 110
	forecast( RAINING | SUNNY ); // 011

	forecast_flags( ( flags_t ) {
		0, 1, 1
	} );

	forecast_flags( ( flags_t ) {
		1, 1, 0
	} );

	return 0;
}
