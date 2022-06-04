#include "header.h"

int * flag_pointer = NULL;

bool winning(int length, int height, Bloc map[length][height]){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      if(map[j][i].Revealed == false && map[j][i].Value > -1){
        return false;
      }
    }
  }
  return true;
}

int reveal_bloc(int length, int height, Bloc map[length][height], int abs, int ord, bool gameplay){
  if(map[abs][ord].Revealed){
    return 0;
  }
  else if(map[abs][ord].Value < 0){
    map[abs][ord].Revealed = 1;
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
  				  reveal_bloc(length, height, map, abs+i, ord+j, gameplay);
  			  }
  		  }
  	  }
    }

	if(map[abs][ord].Flag){
		map[abs][ord].Flag = false;
		*flag_pointer += 1;
	}

    return 0;
  }
}

void full_reveal(int length, int height, Bloc map[length][height]){
  for(int i=0; i<height; i++){
    for(int j=0; j<length; j++){
      reveal_bloc(length, height, map, j, i, false);
    }
  }
}

int turn(int length, int height, Bloc map[length][height], int flags){
	flag_pointer = &flags;

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

	if(flags == 0){
		colorPrintf("Warning : You're out of flags.\n",YELLOW);
		return turn(length, height, map, flags);
	}

    return turn(length, height, map, flags-1);
  }
  else if(act=='F' && map[abs][ord].Flag){
    map[abs][ord].Flag = false;
    return turn(length, height, map, flags+1);
  }
  else if(act=='R'){
	if(map[abs][ord].Flag){
		printf("You can't reveal a flagged square.\n");
		return turn(length, height, map, flags);
	}

    if(reveal_bloc(length, height, map, abs, ord, true) == -1){ // Game over
      full_reveal(length, height, map);
      map_print(length, height, map);
      colorPrintf("\nGAME OVER\n",RED);
      return 0;
    }
    else{
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
