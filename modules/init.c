#include "header.h"

void full_reveal_dev(int length, int height, Bloc map[length][height]){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      map[j][i].Revealed = 1;
    }
  }
}

void map_init(int length, int height, Bloc map[length][height], int mines, int abs, int ord){
  for(int i=0; i<mines; i++){
    int x=0;
    while(x==0){
      int abs_x = rand()%length;
      int ord_x = rand()%height;
      if(abs_x<abs-1 || abs_x>abs+1 || ord_x<ord-1 || ord_x>ord+1){ //not within 3x3 of first tile
        map[abs_x][ord_x].Value = -1;
        x = 1;
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
	do{
		scanf("%c", &txt);
	}while(txt<'A' || txt>'A'+length);
	abs = txt-'A';
	do{
		scanf("%d", &ord);
	}while(ord<1 || ord>height);
	ord--;
  printf("Square selected: %c%d\n\n", abs+'A', ord+1);
  map_init(length, height, map, mines, abs, ord);
  full_reveal_dev(length, height, map);
  printf("Flags left: %d\n", mines);
  map_print(length, height, map);
  return 0;
}
