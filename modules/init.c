#include "header.h"

int reveal_bloc(int length, int height, Bloc map[length][height], int abs, int ord){
    if(map[abs][ord].Revealed){
      return 0;
    }
    else if(map[abs][ord].Value < 0){
      map[abs][ord].Revealed = 1;
      map[abs][ord].Value = -2;
      return -1;
    }
    else{
      map[abs][ord].Value = 0;
      map[abs][ord].Revealed = 1;

      //Update bloc according to mines nearby
	  int mines_nearby = 0;
	  for(int i = -1; i<2; i++){
		  for(int j = -1; j<2; j++){
			  if(abs+i >= 0 && abs+i < length && ord+j >= 0 && ord+j < height){
				  if(map[abs+i][ord+j].Value == -1 || map[abs+i][ord+j].Value == -2){
					  mines_nearby++;
				  }
			  }
		  }
	  }
	  /* if(mines_nearby == 0){
		  for(int i = -1; i<2; i++){
			  for(int j = -1; j<2; j++){
				  if(abs+i >= 0 && abs+i < length && ord+j >= 0 && ord+j < height){
					  reveal_bloc(length, height, map, abs+i, ord+j);
				  }
			  }
		  }
	  } */
	  //else{
		  map[abs][ord].Value = mines_nearby;
	  //}

      return 0;
    }
}

void full_reveal_dev(int length, int height, Bloc map[length][height]){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      reveal_bloc(length, height, map, j, i);
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


/*int turn(int length, int height, Bloc map[length][height], int mines, int flags){
  printf("Flags left: %d\n", flags);
  map_print(length, height, map);
  fflush(stdin);
  int abs;
	int ord;
	char txt;
  char act;
	int x=0;
	do{
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
		if(map[abs][ord].Revealed){
			printf("This case was already revealed, choose another spot.\n\n");
		}
		else{
			x=1;
		}
	}while(x==0);
  printf("Do you want to reveal (R) or flag (F)?\n");
  do{
    scanf("%c", &act);
  }while(act!='R' && act!='F');

  return 0;
}*/
