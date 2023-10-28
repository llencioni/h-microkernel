
typedef void (*ptask_t)(void);

typedef struct {
    ptask_t task;
    int event; 
}
TCB_t;

