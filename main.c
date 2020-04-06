/**
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : Au Yong Chun Sang
* Student ID : 1155143521
* Class/Section : ENGG1110A
* Date : 11/11/2019
*/
#include <stdio.h>
//global declaration
  int availability[5] = {5,1,2,1,9}; //number of product left
  int price[5] = {10,6,5,8,7}; //price of products
  char name[5][255] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
  char button[5] = {' ', ' ', ' ', ' ', ' '};
  int coin = 0, revenue = 0;
  char out = '=';
//print machine
void printmachine(){
  int i;
  for (i=0; i<=4; i++){
    if (availability[i]>0){
      if (coin >= price[i])
        button[i] = 'O';
      else
        button[i] = ' ';
    }
    if (availability[i] == 0)
      button[i] = 'X';
  }
  printf("*---------------------------*\n|      Vending Machine      |\n*---------------------------*\n|   A    B    C    D    E   |\n|  $%2d  $%2d  $%2d  $%2d  $%2d  |\n|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n*---------------------------*\n|                    [$%2d]  |\n|                           |\n|           [=%c=]           |\n*---------------------------*\n" ,price[0], price[1], price[2], price[3], price[4], button[0],button[1], button[2], button[3], button[4], coin, out);
  out = '=';
}
//print menu
int printmenu(){
  int input;
  do {
    printf("\nWhat would you like to do?\n1. Read product information\n2. Insert coin\n3. Press product button\n4. Press return button\n9. Open service menu (code required)\n0. Quit\nYour choice:");
    scanf("%d", &input);
    if ((input > 4 && input != 9)|| input < 0)
      printf("Invalid Choice!\n");
  } while ((input > 4 && input != 9)|| input < 0);
return input;
}
//Read product information
void ReadProduct(){
  int i;
  printf("\n(1) The displayed products are:\n");
  for (i = 0; i <= 4; i++){
    printf("%c. %s ($%d)\n", 'A'+i, name[i], price[i]);
  }
}
//Insert coin
void InsertCoin(){ //pass coin by reference
  int input;
  do {
    printf("\n(2) Which coin would you like to insert?\n1. $1\n2. $2\n3. $5\n4. $10\n0. Go back\nYour choice:");
    scanf("%d", &input);
    switch (input){
    case 1:
      printf("You have inserted $1.\n");
      coin = coin + 1;
      break;
    case 2:
      printf("You have inserted $2.\n");
      coin = coin + 2;
      break;
    case 3:
      printf("You have inserted $5.\n");
      coin = coin + 5;
      break;
    case 4:
      printf("You have inserted $10.\n");
      coin = coin + 10;
      break;
    case 0:
      printf("Going back!\n");
      break;
    default:
      printf("Invalid Choice!\n");
    }
  if (input <= 4 && input >= 0){
    printf("\n");
    printmachine();
  }
  } while (input != 0);
}
//Press product button
void PressProduct(){
  int input;
  do{
    printf("\n(3) Which product button would you like to press?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
    scanf("%d",&input);
    if (input > 5 || input < 0)
      printf("Invalid Choice!\n");
    } while(input > 5 || input < 0);
    switch (input){
      case 1:
        printf("You have pressed button A.\n");
        if (coin >= price[0] && availability[0] >= 1){
          coin = coin - price[0];
          availability[0] = availability[0] -1;
          revenue = revenue + price[0];
          out = 'A';
        }
        printf("\n");
        printmachine();
        break;
      case 2:
        printf("You have pressed button B.\n");
        if (coin >= price[1] && availability[1] >= 1){
          coin = coin - price[1];
          availability[1] = availability[1] -1;
          revenue = revenue + price[1];
          out = 'B';
        }
        printf("\n");
        printmachine();
        break;
      case 3:
        printf("You have pressed button C.\n");
        if (coin >= price[2] && availability[2] >= 1){
          coin = coin - price[2];
          availability[2] = availability[2] -1;
          revenue = revenue + price[2];
          out = 'C';
        }
        printf("\n");
        printmachine();
        break;
      case 4:
        printf("You have pressed button D.\n");
        if (coin >= price[3] && availability[3] >= 1){
          coin = coin - price[3];
          availability[3] = availability[3] -1;
          revenue = revenue + price[3];
          out = 'D';
        }
        printf("\n");
        printmachine();
        break;
      case 5:
        printf("You have pressed button E.\n");
        if (coin >= price[4] && availability[4] >= 1){
          coin = coin - price[4];
          availability[4] = availability[4] -1;
          revenue = revenue + price[4];
          out = 'E';
        }
        printf("\n");
        printmachine();
        break;
      case 0:
        printf("Going back!\n");
        printf("\n");
        printmachine();
        break;
      default:
        printf("Invalid Choice!\n");
    }
}
//Press return button
void PressReturn(){
  printf("\n(4) Return button is pressed.\n$%d has been returned.\n", coin);
  coin=0;
  printmachine();
}
//Open Service menu
void ServiceMenu(){
int code, choice, subchoice, i;
  printf("\n(9) Opening service menu. Access code is required.\n");
  printf("Enter access code: ");
  scanf("%d", &code);
  if (code == 1110)
    printf("Correct Code!\n");
  else {
    printf("Incorrect code!\n\n");
    printmachine();
  }
  if (code == 1110)
    do {
      do {
        printf("\n(9) What would you like to do?\n1. Inspect machine status\n2. Withdraw all money\n3. Refill product\n4. Change product\n0. Go back\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice<0 || choice>4)
          printf("Invalid choice!\n");
      }while (choice<0 || choice>4);
      switch (choice){
        case 1:
          printf("\n(9-1) Machine status\nAmount of revenue: $%d\nAmount of inserted coins: $%d\nProduct information:\n", revenue, coin);
          for (i=0; i<=4; i++){
            printf("%c. %s ($%d) ", 'A'+i, name[i], price[i]);
            if (availability[i] == 0)
              printf("(sold out)\n");
            else printf("(%d left)\n", availability[i]);
          }
          break;
        case 2:
          printf("\n(9-2) All money is being withdrawn.\n$%d is withdrawn.\n", coin + revenue);
          coin=0;
          revenue=0;
          break;
        case 3:
          do {
            printf("\n(9-3) Which product would you like to refill?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
            printf("Your choice:");
            scanf("%d", &subchoice);
            if (subchoice>5 || subchoice<0)
              printf("Invalid choice!\n");
          } while (subchoice>5 || subchoice<0);
          if (subchoice != 0){
            availability[subchoice-1]=10;
            printf("You have refilled product %c to full.\n", 'A'+subchoice-1);
          }
          break;
        case 4:
          do {
            printf("\n(9-4) Which product would you like to change?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
            printf("Your choice:");
            scanf("%d", &subchoice);
            if (subchoice>5 || subchoice<0)
              printf("Invalid choice!\n");
          } while (subchoice>5 || subchoice<0);
          if (subchoice != 0) {
            printf("You are changing product %c.\n", 'A'+subchoice-1);
            printf("\nEnter new product name: ");
            scanf("%s", name[subchoice-1]);
            printf("Enter new product price: ");
            scanf("%d", &price[subchoice-1]);
            availability[subchoice-1]=10;
            printf("The new product %c has been filled to full.\n", 'A'+subchoice-1);
          } else
              printf("Going back!\n");
            break;
        case 0:
          printf("Going back!\n\n");
          printmachine();
          break;
      }
    } while (choice!=0);
}

//main
int main(void) {
//declaration
  int choice = '0';
  printmachine();
//menu
  do{
    choice = printmenu();
    switch (choice){
      case 1:
        ReadProduct();
        break;
      case 2:
        InsertCoin();
        break;
      case 3:
        PressProduct();
        break;
      case 4:
        PressReturn();
        break;
      case 9:
        ServiceMenu();
        break;
   }
  } while (choice!=0);
  return 0;
}
