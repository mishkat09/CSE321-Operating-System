#include <stdio.h>

struct food{
    int quantity;
    int price ;
    
};


int main()
{
    
    int num_people;
    int total_price=0;
    
    struct food Paratha;
    struct food Vegetable;
    struct food M_water;
    
    
    printf("Quantity Of Paratha: ");
    scanf("%d",&Paratha.quantity);
 
    printf("Unit Price: ");
    scanf("%d",&Paratha.price);
  
    
    printf("Quantity Of Vegetable: ");
    scanf("%d",&Vegetable.quantity);
  
    printf("Unit Price: ");
    scanf("%d",&Vegetable.price);

    
    printf("Quantity Of Mineral Water: ");
    scanf("%d",&M_water.quantity);
  
    printf("Unit Price: ");
    scanf("%d",&M_water.price);
  
    
    printf("Number of People: ");
    scanf("%d",&num_people);
 
    total_price += Paratha.quantity*Paratha.price;
    total_price += Vegetable.quantity*Vegetable.price;
    total_price += M_water.quantity*M_water.price;
    
    float result=total_price/num_people;
    
    printf("Individual people will pay: %f",result);
    

    return 0;
}

