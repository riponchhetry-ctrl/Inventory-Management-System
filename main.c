#include<stdio.h>
#include<string.h>


typedef struct {
    char name[20];
    int price;
    int quantity;
} Item;

Item items[50];
int count = 0;

void add_item()
{
    char name[20];
    int price, quantity;

    printf("\nEnter the name of the item: ");
    scanf("%s",&name);
    printf("\nEnter the price of the item: ");
    scanf("%d",&price);
    printf("\nEnter the quantity of the item: ");
    scanf("%d",&quantity);
    
    Item i1;
    strcpy(i1.name, name);
    i1.price = price;
    i1.quantity = quantity;
    
    items[count] = i1;
    
    count++;
}

void view_storage() {
    
    if(count == 0) {
        printf("Please enter some items in the storage\n");
        return ;
    }
    
    printf("Name \t\t Price \t\t Quantity\n");
    
    for (int i=0; i<count; i++){
        printf("%s \t\t %d \t\t %d\n",items[i].name, items[i].price, items[i].quantity);
    }
}

void change_price_quantity(Item *item){
    int choice = 0, price = 0, quantity = 0;

    printf("Enter 1 if you want to change the price \nEnter 2 if you want to change the quantity\nEnter 3 if you want to change both\n");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            printf("\nEnter the price of the item: ");
            scanf("%d",&price);
            item->price = price;
            break;
    
        case 2:
            printf("\nEnter the quantity of the item: ");
            scanf("%d",&quantity);
            item->quantity = quantity;
            break;
            
        case 3:
            printf("\nEnter the price of the item: ");
            scanf("%d",&price);
            item->price = price;
            printf("\nEnter the quantity of the item: ");
            scanf("%d",&quantity);
            item->quantity = quantity;
            break;
    
        default:
            break;
    }
}

void update_item() {
    char update_item_name[20];
    printf("\nEnter the name of the item to update: ");
    scanf("%s", &update_item_name);

    for (int i=0; i<count; i++){
        if (strcmp(update_item_name, items[i].name) == 0){
            change_price_quantity(&items[i]);
        }
    }
}

int main(){
    while(1){
        int choice;
        
        printf("\nEnter your choice \n 1. To add items \n 2. To view storage \n 3. To update an item \n 4. Exit \n");
        scanf("%d",&choice);

        if(choice == 1){
            add_item();
        }
        else if(choice == 2){
            view_storage();
        }
        else if(choice == 3) {
            update_item();
        }
        else{
            break; 
        }
    }    
    return 0;
}

