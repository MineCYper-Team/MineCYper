#include "header.h"

bool winning(int length, int height, Bloc** map){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      if(map[j][i].Revealed == false && map[j][i].Value > -1){
        return false;
      }
    }
  }
  return true;
}

int reveal_bloc(int length, int height, Bloc** map, int abs, int ord, bool gameplay){
  int flag_removed = 0;
  if(map[abs][ord].Revealed){
    return 0;
  }
  if(map[abs][ord].Flag){
    map[abs][ord].Flag = false;
    flag_removed++;
  }
  if(map[abs][ord].Value < 0){
    map[abs][ord].Revealed = true;
    if(gameplay){
      map[abs][ord].Value = -2;
    }
    else{
      map[abs][ord].Value = -1;
    }
    return -1;
  }
  else{
    map[abs][ord].Value = 0;
    map[abs][ord].Revealed = 1;

    //Update bloc according to mines nearby
    map[abs][ord].Value = 0;
    for(int i = -1; i<2; i++){
  	  for(int j = -1; j<2; j++){
  		  if(abs+i >= 0 && abs+i < length && ord+j >= 0 && ord+j < height){
  			  if(map[abs+i][ord+j].Value < 0){
  				  map[abs][ord].Value++;
  			  }
  		  }
  	  }
    }
    if(map[abs][ord].Value == 0){
  	  for(int i = -1; i<2; i++){
  		  for(int j = -1; j<2; j++){
  			  if(abs+i >= 0 && abs+i < length && ord+j >= 0 && ord+j < height){
  				  flag_removed = flag_removed + reveal_bloc(length, height, map, abs+i, ord+j, gameplay);
  			  }
  		  }
  	  }
    }
    return flag_removed;
  }
}

void full_reveal(int length, int height, Bloc** map){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      reveal_bloc(length, height, map, j, i, false);
    }
  }
}

int turn(int length, int height, Bloc** map, int flags){
  printf("Flags left: %d\n", flags);
  map_print(length, height, map);
  while(getchar()!='\n'); //flush
  int abs;
	int ord;
	char txt;
  char act;
	printf("What square do you target?\n");

	fflush(stdin);
	bool isValidInput = false;
	int type1,type2;
	while(isValidInput == false) {
		type1 = scanf("%c", &txt);
		type2 = scanf("%d", &ord);

		if(type1 == 1 && type2 == 1 && (ord >= 1 && ord <= height) && (txt>='A' && txt<='A'+length)){
			if(map[txt-'A'][ord-1].Revealed){
				printf("This square is already revealed\n");
				while(getchar()!='\n'); //flush
			}
			else{
				isValidInput = true;
			}
		}
		else{
			printf("Invalid input, try again.\n");
			while(getchar()!='\n');
		}
	}
	abs = txt-'A';
	ord--;

  printf("Do you want to reveal (R) or flag (F)?\n");
  fflush(stdin);
  while(getchar()!='\n');
  isValidInput = false;
  while(isValidInput == false) {
  	type1 = scanf("%c", &act);
  	if(type1 == 1 && (act == 'R' || act == 'F')){
  	  isValidInput = true;
  	}
  	else{
  	  printf("Invalid input, try again.\n");
  	  while(getchar()!='\n'); //flush
  	}
  }

  if(act=='F' && !map[abs][ord].Flag){
    map[abs][ord].Flag = true;
    return turn(length, height, map, flags-1);
  }
  else if(act=='F' && map[abs][ord].Flag){
    map[abs][ord].Flag = false;
    return turn(length, height, map, flags+1);
  }
  else if(act=='R'){
    int reveal_value = reveal_bloc(length, height, map, abs, ord, true);
    if(reveal_value == -1){ // Game over
      full_reveal(length, height, map);
      map_print(length, height, map);
      colorPrintf("\nGAME OVER\n",RED);
      return 0;
    }
    else{
      flags = flags + reveal_value;
      if(winning(length, height, map)){
        full_reveal(length, height, map);
        map_print(length, height, map);
        colorPrintf("\nVICTORY\n",GREEN);
        return 1;
      }
      else{
        return turn(length, height, map, flags);
      }
    }
  }
  else{
    colorPrintf("Error : This shouldn't happen. Exiting gameplay.\n\n",RED);
    return -1;
  }
}
