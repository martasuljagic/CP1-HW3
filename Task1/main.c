#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputCheck(char input, int current)
{
    int floor;
    char inputjunior;
    switch(input)
    {
        case 'B': //basement cases and converting
            scanf(" %c", &inputjunior);
            switch (inputjunior)
            {
            case '1':
                floor = -1;
                break;
            case '2':
                floor = -2;
                break;
            case '3':
                floor = -3;
                break;
            default:
                floor = -10;
                break;
            }
            break;
        case '1': //regular cases and converting
            floor = 1;
            break;
        case '2':
            floor = 2;
            break;
        case '3':
            floor = 3;
            break;
        case '4':
            floor = 4;
            break;
        case '5':
            floor = 5;
            break;
        case 'G':
            floor = 0;
            break;
        case 'y':
            floor=current;
            break;
        case 'p':
            floor=current;
            break;
        default:
            floor = -10;
        break;
    }
    return floor;
}
void ride(char input, int floor, int current, int peopleOnElevator, int peopleOnFloor[])
{
    int pass = 1; //no of passengers
    while(peopleOnElevator > 0) //riding
    {
        printf("Where do you want to go? [B1, B2, B3, G, 1, 2, 3, 4, 5].\nDo you want to leave, type 'y'? Did someone enter, type 'p'?\n");
        scanf(" %c", &input); // i hate c, because it won't take ony 1 char without space before %c
    if(input == 'p') //if someone entered
    {
        peopleOnElevator++;
    }
    else if(input == 'y') //if someone left
    {
        peopleOnElevator--;
        peopleOnFloor[current]++; //remembering how many people are there on a certain floor
    }
    floor = inputCheck(input, current); //checking
        if(floor == -10)
        {
            printf("You can't go there, type in an existing floor.\n");
        }
        else if(current == floor && (input !='p' && input !='y')) //so it won't bother us if we type p or y on a certain floor multiple times
        {
            printf("You are already there!\n");
        }
        else
        {
            current=floor;//we made it to the desired floor
        } 
            printf("You are currently on the %d. floor.\n", current);
    }
}
int main()
{
    char input = 'G'; //we start at ground floor
    int floor, current = 0; //current floor, wish to be on floor
    int peopleOnElevator = 1; //people on the elevator
    int peopleOnFloor[] = {0,0,0,0,0,0}; //passengers on a floor
    ride(input, floor, current, peopleOnElevator, peopleOnFloor); //riding proccess
    return 0;
}