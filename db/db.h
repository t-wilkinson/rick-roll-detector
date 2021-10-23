#ifndef _db_h_
#define _db_h_

#define MAXELEMENTS 10
#define FILENAME_LENGTH 100

typedef enum SafetyRating { Empty='\0', Unknown='0', Danger='1', Warning='2', Safe='3' } rating_t;

typedef struct Item {
    rating_t rating;
} db_item_t;

typedef struct Database {
    int number_of_elements;
    db_item_t elements[MAXELEMENTS];
    char *filename;
} db_t;

// load database from file if exists, otherwise call create_db
db_t *init_db(char *);
db_t *create_db(char *);
int save_db(db_t *);
db_t *load_db(char *);

int key_hash(char []);
int set_item(db_t *, char [], db_item_t *);
db_item_t get_item(db_t *, char []);

#endif
