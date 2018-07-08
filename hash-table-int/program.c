#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101

//linked list
struct nlist_s
{
	int number;
	struct nlist_s *next; // next entry
};

typedef struct nlist_s nlist_t;

struct hashtable_s
{
	int size;
	struct nlist_s **table;
};

typedef struct hashtable_s hashtable_t;


hashtable_t *ht_create( int size )
{
	hashtable_t *hashtable = NULL;
	int i;

	hashtable = malloc( sizeof( hashtable_t ) );

	hashtable->table = malloc( sizeof( nlist_t * ) * size );

	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;
}

nlist_t *ht_newitem( int i )
{
	nlist_t *entry = NULL;
	entry = malloc( sizeof( nlist_t ) );
	entry->number = i;
	entry->next = NULL;
	return entry;
}

int ht_hash( hashtable_t *hashtable, int i )
{
	return i % hashtable->size;
}

int ht_insert( hashtable_t *hashtable, int i )
{
	int bin;
	nlist_t *next = NULL;
	nlist_t *last = NULL;
	nlist_t *newpair = NULL;

	bin = ht_hash( hashtable, i );
	next = hashtable->table[bin];

	while( next != NULL && next->number != i ) {
		last = next;
		next = next->next;
	}

	// this item exists
	if( next != NULL && next->number == i ) return 0;
	// add new item
	else {
		newpair = ht_newitem( i );
		// this is start
		if( next == hashtable->table[bin] )
			hashtable->table[bin] = newpair;
		// at the end
		else
			last->next = newpair;
	}
	return 1;
}

nlist_t *ht_get( hashtable_t *hashtable, int i ) {

}

void ht_print( hashtable_t *hashtable )
{
	nlist_t *entry = NULL;
	int i;

	for( i = 0 ; i < hashtable->size; i++ ) {
		entry = hashtable->table[i];
		if( entry != NULL ) {
			printf( "[%d] ", i );
			while( entry != NULL ) {
				printf( "%d ", entry->number );
				entry = entry->next;
			}
			printf( "\n" );
		}
	}

}

int main( int argc, char *argv[] )
{

	hashtable_t *hashtable = ht_create( HASHSIZE );
	ht_insert( hashtable, 20 );
	ht_insert( hashtable, 222 );
	ht_insert( hashtable, 20 );
	ht_insert( hashtable, 2 );

	ht_print( hashtable );

	return 0;
}
