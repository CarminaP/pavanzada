typedef struct e {

int key;

char *value;

} Element;



typedef struct d {

Element *elements;

unsigned count;

unsigned length;

} HashElement;


typedef struct h {

HashElement *data;

unsigned size;

///

} HashInt;



void hashInit(HashInt *,unsigned);

void hashInsert(HashInt *,int ,char *);

int * hashGet(HashInt *, int);
