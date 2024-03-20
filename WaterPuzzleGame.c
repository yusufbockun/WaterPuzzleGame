#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#define MAX_SIZE 4
void movetube(char arr1[MAX_SIZE],char arr2[MAX_SIZE]);
int main(){
char tube1[4]={'C','R','S','S'},tube2[4]={'R','C','S','S'},tube3[4]={'C','R','C','R'},tube4[4]={' ',' ',' ',' '},tube5[4]={' ',' ',' ',' '};
int temp1,temp2,count;
int move,select,operation,i;
int stop=1;
printf("****WELCOME TO THE WATER PUZZLE GAME***** \n \n");
printf("Your game will start soon Please wait...");
sleep(1);
system("cls");
printf("-Rules\n\n1-)The purpose of the game is to place all the colors in the same tube.\n\n2-)Select 2 tube to empty into the tube.\n\n3-)Water is taken from the first tube you will write, and it is poured into the second tube you will write.\n\nEX:'Enter move:1 3' is making drains the water from the first tube to the third tube \n\n\nCOLORS\n------\nRED=R\nGREEN=G\nBLUE=B\n\nYour game will start soon Please wait...");
sleep(7);
count=0;
while(stop>0) //oyun bitene kadar sonlandýr
{
system("cls");
printf("tube1== [");
for(i=0;i<4;i++)
	printf("%c,",tube1[i]);

printf("]\ntube2== [");
for(i=0;i<4;i++)
	printf("%c,",tube2[i]);

printf("]\ntube3== [");
for(i=0;i<4;i++)
	printf("%c,",tube3[i]);

printf("]\ntube4== [");
for(i=0;i<4;i++)
	printf("%c,",tube4[i]);

printf("]\ntube5== [");
for(i=0;i<4;i++)
	printf("%c,",tube5[i]);
printf("] \n \n the number of your attempts: %d",count);        //Tüpleri ekrana yazdýr
if(tube1[0]==tube1[1]&&tube1[1]==tube1[2]&&tube1[2]==tube1[3]&&tube2[0]==tube2[1]&&tube2[1]==tube2[2]&&tube2[2]==tube2[3]&&tube3[0]==tube3[1]&&tube3[1]==tube3[2]&&tube3[2]==tube3[3]&&tube4[0]==tube4[1]&&tube4[1]==tube4[2]&&tube4[2]==tube4[3]&&tube5[0]==tube5[1]&&tube5[1]==tube5[2]&&tube5[2]==tube5[3])
{
printf("\n \n******Congratulations you won******** \n\n");
break;
}
printf(" \n Enter a move: \n");
scanf("%d %d",&select,&move); //oyuncudan hangi tüpü ve nereye taþýyaðacýný al
int i,j; //i son eleman j ise ilk elemani
count++;
switch(select){
	case 1:
		switch(move){
			case 2:
				movetube(tube1,tube2);
				break;
			case 3:
				movetube(tube1,tube3);

				break;
			case 4:
				movetube(tube1,tube4);
				break;
			case 5:
				movetube(tube1,tube5);
				break;
			default:
				printf("You have selected the same tube or a tube that is not. Please try again...\n\n");
				system("pause");
				break;
		}
		break;
	case 2:
		switch(move){
			case 1:
				movetube(tube2,tube1);
				break;
			case 3:
				movetube(tube2,tube3);
				break;
			case 4:
				movetube(tube2,tube4);
				break;
			case 5:
				movetube(tube2,tube5);
				break;
			default:
				printf("You have selected the same tube or a tube that is not. Please try again...\n\n");
				system("pause");
				break;
		}
		break;
	case 3:
		switch(move){
		case 1:
			movetube(tube3,tube1);
			break;
		case 2:
			movetube(tube3,tube2);
			break;
		case 4:
			movetube(tube3,tube4);
			break;
		case 5:
			movetube(tube3,tube5);
			break;
		default:
			printf("You have selected the same tube or a tube that is not. Please try again...\n\n");
			system("pause");
			break;
		}
		break;
	case 4:
		switch(move){
		case 1:
			movetube(tube4,tube1);
			break;
		case 2:
			movetube(tube4,tube2);
			break;
		case 3:
			movetube(tube4,tube3);
			break;
		case 5:
			movetube(tube4,tube5);
			break;
		default:
			printf("You have selected the same tube or a tube that is not. Please try again...\n\n");
			system("pause");
			break;
		}
		break;
	case 5:
		switch(move){
		case 1:
			movetube(tube5,tube1);
			break;
		case 2:
			movetube(tube5,tube2);
			break;
		case 3:
			movetube(tube5,tube3);
			break;
		case 4:
			movetube(tube5,tube4);
			break;
		default:
			printf("You have selected the same tube or a tube that is not. Please try again...\n\n");
			system("pause");
			break;
		}
		break;

}
}
return 0;
}
void movetube(char arr1[MAX_SIZE],char arr2[MAX_SIZE])
{
int i,j;
for(i=3;i>=0;i--){
	if(arr1[i]!=' '){
		if(arr1[i]==arr1[i-1]&& arr1[i-1]!=arr1[i-2]){
			for(j=0;j<3;j++){
				if(arr2[j]==' ' && arr2[j+1]==' '){
				arr2[j]=arr1[i];
				arr2[j+1]=arr1[i-1];
				arr1[i]=' ';
				arr1[i-1]=' ';
				break;
											}	
			
							}
							}
		else if(arr1[i]==arr1[i-1] && arr1[i-1]==arr1[i-2]&& arr1[i]!=arr1[i-3]){
					for(j=0;j<3;j++){
				if(arr2[j]==' ' && arr2[j+1]==' ' && arr2[j+2]==' '){
				arr2[j]=arr1[i];
				arr2[j+1]=arr1[i-1];
				arr2[j+2]=arr2[i-2];
				arr1[i]=' ';
				arr1[i-1]=' ';
				arr1[i-2]=' ';
				break;
											}	
			
							}
						}
		else if(arr1[i]==arr1[i-1] && arr1[i-1]==arr1[i-2]&&arr1[i-2]==arr1[i-3]){
					for(j=0;j<3;j++){
				if(arr2[j]==' ' && arr2[j+1]==' ' && arr2[j+2]==' '&&arr2[j+3]==' '){
				arr2[j]=arr1[i];
				arr2[j+1]=arr1[i-1];
				arr2[j+2]=arr2[i-2];
				arr2[j+3]=arr2[i-3];
				arr1[i]=' ';
				arr1[i-1]=' ';
				arr1[i-2]=' ';
				arr1[i-3]=' '; 
				break;
											}	
			
							}
		
		}
		
		
		else{
		
		for(j=0;j<4;j++){
			if(arr2[j]==' '){
			arr2[j]=arr1[i];
			arr1[i]=' ';
			break;
			}
		}
		}
	break;
	}
}
}
