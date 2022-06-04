#include "header.h"

void map_init(int length, int height, Bloc map[length][height], int mines, int abs, int ord){
  for(int i=0; i<mines; i++){
    int x=0;
    while(x==0){
      int abs_x = rand()%length;
      int ord_x = rand()%height;
      if(abs_x<abs-1 || abs_x>abs+1 || ord_x<ord-1 || ord_x>ord+1){ //not within 3x3 of first tile
        if(map[abs_x][ord_x].Value != -1){
          map[abs_x][ord_x].Value = -1;
          x = 1;
        }
      }
    }
  }
}

int first_turn(int length, int height, Bloc map[length][height], int mines){
  printf("Flags left: %d\n", mines);
  map_print(length, height, map);
  while(getchar()!='\n'); //flush
  int abs;
	int ord;
	char txt;
	printf("What square do you target?\n");
	fflush(stdin);
	bool isValidInput = false;
	int type1,type2;
	while(isValidInput == false) {
		type1 = scanf("%c", &txt);
		type2 = scanf("%d", &ord);

		if((type1 == 1 && type2 == 1) && (ord >= 1 && ord <= height) && (txt>='A' && txt<='A'+length)){
			isValidInput = true;
		}
		else{
			printf("Invalid input, try again.\n");
			while(getchar()!='\n'); //flush
		}
	}
	abs = txt-'A';
	ord--;
	
  printf("Square selected: %c%d\n\n", abs+'A', ord+1);
  map_init(length, height, map, mines, abs, ord);
  reveal_bloc(length, height, map, abs, ord, true);
  printf("Flags left: %d\n", mines);
  map_print(length, height, map);
  return turn(length, height, map, mines);
}
