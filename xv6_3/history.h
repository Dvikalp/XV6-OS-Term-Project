#include "types.h"
#define UP_ARROW 226
#define DOWN_ARROW 227
#define MAX_HISTORY 16
#define INPUT_BUF 128

struct {
  char History_cmd_names_2d[MAX_HISTORY][INPUT_BUF]; 
  uint lengthsArr[MAX_HISTORY]; 
  uint lastCommandIndex;  
  int numOfCommmandsInMem; 
  int currentHistory;  
} history_record;

int history(char *buffer, int historyId);
