#include<stdio.h>                                          //Header Files
#include<stdlib.h>
#include<string.h>
int petcare();                                             //Function Prototyping
int petfood();
int pethostel();
int petgrooming();
int petessential();
struct pets                                                //STRUCTURE
{
    char need_products[25];
    char item_code[25];
    int quantity;
    float price;
};
int main()                                                 //Main function
{
    long long int mobile;
    int select,login,id;
    char name;
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t=                  WELCOME                  =");
    printf("\n\t\t\t\t\t=                    TO                     =");
    printf("\n\t\t\t\t\t=                 PET CLINIC                =");
    printf("\n\t\t\t\t\t=                 MANAGEMENT                =");
    printf("\n\t\t\t\t\t=                   SYSTEM                  =");
    printf("\n\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*------------ GOWTHAM PET SHOP ------------*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\n\n\n\n\t\t\t\t\tPress any key to continue.....");
    getchar();
    system("clear");
    start:
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*-------------- GOWTHAM PET SHOP --------------*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\n\n\n1.FOR NEW LOGIN\n2.FOE EXISTING LOGIN");
    printf("\n\nEnter your choice: ");
    scanf("%d",&login);
    FILE *ptr,*read;
    ptr=fopen("bill.txt","w");
    fprintf(ptr,"\n\tGOWTHAM PET SHOP");
    fclose(ptr);
    if(login == 1)
    {
        FILE *fp,*rd;
        char name[50];
        int id;
        long long int mobile;
        fp = fopen("records.txt", "a+");
        rd=fopen("bill.txt","a");
        if(fp == NULL)
        {
            printf("Error in opening file\n");
            exit(1);
        }
        printf("Enter the name of the customer : ");
        scanf(" %[^\n]s",&name);
        printf("Enter the customer ID : ");
        scanf(" %d", &id);
        printf("Enter the mobile number of the customer : ");
        scanf(" %lld", &mobile);
        fprintf(fp, "Name: %s\t\tID: %d\t\tMobile number: %lld\n",name,id,mobile);
        fprintf(rd,"\nName: \t\t%s\nID: \t\t%d\nMobile number:  %lld",name,id,mobile);
        fclose(fp);
        fclose(rd);
        printf("\n\n\n\n\t\t\t\t\tPress any key to continue.....");
        getchar();
        system("clear");
    }
    else
    {
        char n[50];
        int i_d;
        long long int m;
        FILE *fd,*rr;
        fd = fopen("records.txt","r");
        rr=fopen("bill.txt","a");
        printf("\nEnter your name: ");
        scanf(" %[^\n]s",&n);
        printf("Enter the ID: ");
        scanf(" %d", &i_d);
        printf("Enter your mobile number: ");
        scanf(" %lld",&m);
        while(fscanf(fd,"Name: %s\t\tID: %d\t\tMobile number: %lld\n",&name,&id,&mobile)!=EOF)
        {
            if(i_d == id && m == mobile)
            {
                fprintf(rr,"\nName: \t\t%s\nID: \t\t%d\nMobile number:  %lld",n,i_d,m);
                fclose(rr);
                break;
            }
            else
            {
                printf("\n\n\t\t\tPLEASE SIGN UP FIRST!");
                getchar();
                system("clear");
                goto start;
             }
        }
        printf("\n\n\n\n\t\t\t\t\tPress any key to continue.....");
        getchar();
        system("clear");
    }
    int select_choice;
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*-------------- GOWTHAM PET SHOP --------------*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\t\t\t\t\t*=========================================*\n");
    printf("\n\n\n1.CARE\n2.ESSENTIALS\n3.HOSTEL\n4.FOOD\n5.GROOMING\n6.EXIT");
    printf("\n\nSelect your choice : ");
    scanf(" %d",&select_choice);
    switch(select_choice)
    {
        case 1: petcare();
                  break;
        case 2: petessential();
                  break;
        case 3: pethostel();
                  break;
        case 4: petfood();
                  break;
        case 5: petgrooming();
                  break;
        case 6: exit;
                  break;
    }
    return 0;
}

                                            //PET CARE

int petcare()
{
    int rate_c,choice_c,care_rate,age;
    char bill,confirm;
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\t\t\t\t\t##################### CARE ###################");
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\n1.ALLERGY\n2.FEVER & COLD\n3.ACCIDENTS\n4.FOOD POISON\n5.VACCINATION");
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice_c);
    FILE *fcare,*care_bill;
    fcare = fopen("bill.txt","a");
    fprintf(fcare,"\nYou have chosen the care!!!");
    switch(choice_c)
    {
        case 1: care_rate = 189;
                printf("\nThe bill  has been created");
                printf("\nCOST - %d",care_rate);
                fprintf(fcare,"\n\n\t     ALLERGY\n\t   ~~~~~~~~~~");
                fprintf(fcare,"\n\tCleaning    - Rs.75\n\tDoctor fees - Rs.120\n\tMedicine    - Rs.50\n\n\tTOTAL - Rs.245\n\n");
                break;
        case 2: care_rate = 153;
                printf("\nThe bill  has been created");
                printf("\nCOST - %d",care_rate);
                fprintf(fcare,"\n\n\t  FEVER & COLD\n\t ~~~~~~~~~~~~~~");
                fprintf(fcare,"\n\tDoctor Fees - Rs.120\n\tMedicine    - Rs.79\n\n\tTOTAL - Rs.199\n\n");
                break;
        case 3: care_rate = 235;
                printf("\nThe bill  has been created");
                printf("\nCOST - %d",care_rate);
                fprintf(fcare,"\n\n\t    ACCIDENTS\n\t  ~~~~~~~~~~~~~");
                fprintf(fcare,"\n\tFirst Aid   - Rs.90\n\tDoctor Fees - Rs.120\n\tMedicine    - Rs.85\n\n\tTOTAL - Rs.395\n\n");
                break;
        case 4: care_rate = 150;
                printf("\nThe bill  has been created");
                printf("\nCOST - %d",care_rate);
                fprintf(fcare,"\n\n\t  FOOD POISON\n\t ~~~~~~~~~~~~");
                fprintf(fcare,"\n\tDoctor Fees - Rs.120\n\tMedicine    - Rs.75\n\n\tTOTAL - Rs.195\n\n");
                break;
        case 5:
            {   fprintf(fcare,"\n\n\t   VACCINATION\n\t ~~~~~~~~~~~~~~");
                printf("\n\nEnter the age of your dog(in weeks): ");
                scanf(" %d", &age);
                printf("\nThe bill  has been created");
                if(age>=6 && age<=8)
                {
                    care_rate = 700;
                    printf("\nCOST - %d",care_rate);
                    fprintf(fcare,"\nVaccination Name:  Distemper,Parvovirus\nVaccination Price: Rs.700\n\n");
                }
                if(age>=9 && age<=12)
                {
                    care_rate = 750;
                    printf("\nCOST - %d",care_rate);
                    fprintf(fcare,"\nVaccination Name:  DHPP\nVaccination Price: Rs.750\n\n");
                }
                if(age>=12 && age<=18)
                {
                    care_rate = 1500;
                    printf("\nCOST - %d",care_rate);
                    fprintf(fcare,"\nVaccination Name:  DHPP,Rabies\nVaccination Price: Rs.1500\n\n");
                }
                if(age>18)
                {
                    care_rate = 1200;
                    printf("\nCOST - %d",care_rate);
                    fprintf(fcare,"\nVaccination Name:  DHPP\nVaccination Price: Rs.1200\n\n");
                }
            }
                break;
    }

    fclose(fcare);                                                        //Validation for fcare
    cbill:
    printf("\n\nDisplay bill(y/n)? ");
    scanf(" %s",&confirm);
    if(confirm == 'y')
    {
        care_bill = fopen("bill.txt","r");
        do
        {
            bill = fgetc(care_bill);
            putchar(bill);
        }while(bill!=EOF);
        fclose(care_bill);
    }
    else
    {
        if(confirm == 'n')
        {
            exit (0);
        }
        else
        {
            printf("\nInvalid choice");
            goto cbill;
        }
    }
}

                                                     //ESSENTIALS

int petessential()
{
    int s_e,s_e2,a_e[20]={0},cost_e[20]={0},totalcost_e=0;
    char products[20][20]=
    { "StainlessSteel dog bowl(large)",
      "StainlessSteel dog bowl(medium)",
      "Neck Collar",
      "Chew Toys",
      "Towel",
      "Miniature Groom Box",
      "Pet area refresher",
      "Pet Bed",
      "Pet wipes(60 counts)",
      "All purpose shampoo",
      "Cleanser",
      "Moisturizer",
      "Nourishing Lotion",
      "Perfume for dogs",
      "Cream",
      "Grooming Brush",
      "Muzzle",
      "Powder",
      "Goofy box(Gift box)"
    };
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\t\t\t\t\t################## ESSENTIALS ################");
    printf("\n\t\t\t\t\t##############################################");
    start_e:
    printf("\n\n(i)ACCESSORIES:\n\n\t1.StainlessSteel dog bowl(large) - Rs.589\n\t2.StainlessSteel dog bowl(medium) - Rs.385\n\t3.Neck Collar - Rs.195\n\t4.Chew Toys - Rs.174\n\t5.Towel - Rs.94\n\t6.Miniature Groom Box - Rs.460\n\t7.Pet area refresher - Rs.300\n\t8.Pet Bed - Rs.1,200\n\t9.Pet wipes(60 counts) - Rs.300");
    printf("\n\n(ii)SHAMPOOS & SOAPS:\n\n\t10.All purpose shampoo  - Rs.242  (100ml)\n\t11.Cleanser - Rs.90  (100 ml)\n\t12.Moisturizer - Rs.130  (100ml)\n\t13.Nourishing Lotion - Rs.150  (100ml)\n\t14.Perfume for dogs - Rs.110  (100ml)\n\t15.Cream - Rs.200  (100ml)\n\t16.Grooming Brush - Rs.89\n\t17.Muzzle - Rs.100\n\t18.Powder - Rs.190\n\t19.Goofy box(Gift box) - Rs.2,500");
    printf("\n\nEnter your choice(1 to 19): ");
    scanf("%d",&s_e);
    if(s_e == 1)
    {
        a_e[1]++;
        cost_e[1] = 589;
        totalcost_e+=589;
    }
    else if(s_e ==2 )
    {
        a_e[2]++;
        cost_e[2] = 385;
        totalcost_e+=385;
    }
    else if(s_e ==3 )
    {
        a_e[3]++;
        cost_e[3] = 195;
        totalcost_e+=195;
    }
    else if(s_e == 4)
    {
        a_e[4]++;
        cost_e[4] = 174;
        totalcost_e+=174;
    }
    else if(s_e == 5)
    {
        a_e[5]++;
        cost_e[5] = 94;
        totalcost_e+=94;
    }
    else if(s_e == 6)
    {
        a_e[6]++;
        cost_e[6] = 460;
        totalcost_e+=460;
    }
    else if(s_e == 7)
    {
        a_e[7]++;
        cost_e[7] = 300;
        totalcost_e+=300;
    }
    else if(s_e == 8)
    {
        a_e[8]++;
        cost_e[8] = 1200;
        totalcost_e+=1200;
    }
    else if(s_e == 9)
    {
        a_e[9]++;
        cost_e[9] = 300;
        totalcost_e+=300;
    }
    else if(s_e == 10)
    {
        a_e[10]++;
        cost_e[10] = 242;
        totalcost_e+=242;
    }
    else if(s_e == 11)
    {
        a_e[11]++;
        cost_e[11] = 90;
        totalcost_e+=90;
    }
    else if(s_e == 12)
    {
        a_e[12]++;
        cost_e[12] = 130;
        totalcost_e+=130;
    }
    else if(s_e == 13)
    {
        a_e[13]++;
        cost_e[13] = 150;
        totalcost_e+=150;
    }
    else if(s_e == 14)
    {
        a_e[14]++;
        cost_e[14] = 110;
        totalcost_e+=110;
    }
    else if(s_e == 15)
    {
        a_e[15]++;
        cost_e[15] = 200;
        totalcost_e+=200;
    }
    else if(s_e == 16)
    {
        a_e[16]++;
        cost_e[16] = 89;
        totalcost_e+=89;
    }
    else if(s_e == 17)
    {
        a_e[17]++;
        cost_e[17] = 100;
        totalcost_e+=100;
    }
    else if(s_e == 18)
    {
        a_e[18]++;
        cost_e[18] = 190;
        totalcost_e+=190;
    }
    else if(s_e == 19)
    {
        a_e[19]++;
        cost_e[19] = 2500;
        totalcost_e+=2500;
    }
    for(int i=0;i<20;i++)
    {
        if(a_e[i]!=0)
        {
           printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d",i,products[i-1],a_e[i],cost_e[i]);
        }
    }
    printf("\n\n\COST is %d",totalcost_e);
    start1:
    printf("\n\nWould you like to change your choice?\n\t1.Add product\n\t2.Delete product\n\t3.Change Quantity\n\t4.Exit\nEnter your choice: ");
    scanf(" %d",&s_e2);
    if(s_e2 == 1)
    {
       goto start_e;
    }
    if(s_e2 == 2)
    {
        int i,id;
        printf("\nEnter the ID of the product to delete item: ");
        scanf("%d",&id);
        if(id<=19 && id>=0)
        {
            totalcost_e = totalcost_e - (cost_e[id]*a_e[id]);
            a_e[id]=0;
        }
        else
        {
            printf("\nEnter valid ID of the product:");
        }
        printf("\n\n\t\tREVISED ITEMS");
        for(i=0;i<19;i++)
        {
            if(a_e[i]!=0)
            {
                printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d",i,products[i-1],a_e[i],(cost_e[i]*a_e[i]));
            }
        }
        printf("\nTOTAL COST - Rs.%d\n",totalcost_e);
        goto start1;
    }

    if(s_e2==3)
    {
        int id,quantity;
        printf("\nEnter ID of the product to change the quantity of an item: ");
        scanf(" %d",&id);
        printf("\nEnter quantity to be changed of an item: ");
        scanf(" %d",&quantity);
        if(id<=19 && id>=0)
        {
            if(quantity>0 && a_e[id]>0)
            {
                if(quantity<a_e[id])
                {
                    int dec = a_e[id] - quantity;
                    a_e[id] = quantity;
                    totalcost_e = totalcost_e - (cost_e[id]*dec);
                }
                if(quantity>a_e[id])
                {
                    int inc = quantity - a_e[id];
                    a_e[id] = quantity;
                    totalcost_e = totalcost_e+(cost_e[id]*inc);
                }
                if(quantity == a_e[id])
                {
                    a_e[id] = quantity;
                    totalcost_e = totalcost_e+0;
                }
            }
            else
            {
                printf("\nItem has no Quantity.Please Try again\n");
            }
        }
        else
        {
            printf("\nEnter valid ID: ");
        }
        printf("\n\n\t\tREVISED ITEMS");
        for(int i=0;i<19;i++)
        {
            if(a_e[i]!=0)
            {
                printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d",i,products[i-1],a_e[i],(cost_e[i]*a_e[i]));
            }
        }
        printf("\nTOTAL COST - Rs.%d\n",totalcost_e);
        goto start1;
    }
}

                                        //PET HOSTEL

int pethostel()
{
    int n,choice_h,hostel_rate;
    char confirm,bill_h;
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\t\t\t\t\t#################### HOSTEL ##################");
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\n1.Rate per hour - Rs.150\n2.Rate per hour with food - Rs.180");
    printf("\n\nEnter your choice: ");
    scanf(" %d",&choice_h);
    printf("\nEnter the number of hours: ");
    scanf("%d",&n);
    FILE *fhostel,*hostel_bill;
    fhostel = fopen("bill.txt","a");
    fprintf(fhostel,"\nYou have chosen hostel!!!");
    if(choice_h == 1)
    {
        hostel_rate = n*150;
        fprintf(fhostel,"\n\nPRICE(Without food): %d\n\n",hostel_rate);
    }
    else
    {
        hostel_rate = n*180;
        fprintf(fhostel,"\n\nPRICE(With food): %d\n\n",hostel_rate);
    }
    printf("\nThe bill has been created!\nTOTAL COST - %d",hostel_rate);
    fclose(fhostel);
    hbill:
    printf("\n\nDisplay bill(y/n)? ");                                               //Validation for pet hostel
    scanf(" %s",&confirm);
    if(confirm == 'y')
    {
        hostel_bill = fopen("bill.txt","r");
        do
        {
            bill_h = fgetc(hostel_bill);
            putchar(bill_h);
        }while(bill_h!=EOF);
        fclose(hostel_bill);
    }
    else
    {
        if(confirm == 'n')
        {
            exit (0);
        }
        else
        {
            printf("\nInvalid choice!");
            goto hbill;
        }
    }
}

                                       //PET FOOD

int petfood()
{
    int s_f,s_f2,a_f[30]={0},cost_f[30]={0},totalcost_f=0;
    char dishes[30][30]=
    { "Gravy-Chicken & Liver chunks flavor",
      "Gravy-Grilled liver chunks flavor",
      "Food-Chicken & Vegetables",
      "Food-Chicken rice & Egg",
      "Food-Meat rice",
      "Food-Meat & Vegetables",
      "Biscuits-Milk & Chicken flavored",
      "Biscuits-Chicken flavored",
      "Biscuits-Lamb flavored",
      "Mini-Chicken flavor",
      "Mini-Duck flavor",
      "Rodeo-Chicken flavored",
      "Rodeo-Duos with chicken & bacon flavor",
      "Meatstick-Bacon flavored",
      "Meatstick-Grilled liver flavor",
      "Meatstick-Smoked salmon flavored",
      "Meatstick-Barbeque Chicken flavored",
      "Dry-Meat &milk",
      "Dry-Chicken & meat",
      "Dry-Chicken, egg & rice",
      "Dry-Vegetarian"};
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\t\t\t\t\t##################### FOOD ###################");
    printf("\n\t\t\t\t\t##############################################");
    start2:
    printf("\n\n(i)GRAVY:\n\t1.Chicken & Liver chunks flavor - Rs.45  (100g)\n\t2.Grilled liver chunks flavor - Rs.50  (100g)");
    printf("\n(ii)FOOD:\n\t3.Chicken & Vegetables - Rs.135  (1kg)\n\t4.Chicken rice & Egg - Rs.139  (1kg)\n\t5.Meat rice - Rs.140  (1kg)\n\t6.Meat & Vegetables - Rs.145  (1kg)");
    printf("\n(iii)BISCUITS:\n\t7.Milk & Chicken flavored - Rs.30  (100g)\n\t8.Chicken flavored - Rs.35  (100g)\n\t9.Lamb flavored - Rs.40  (100g)");
    printf("\n(v)MINI'S:\n\t10.Chicken flavor - Rs.45  (100g)\n\t11.Duck flavor - Rs.50  (100g)");
    printf("\n(iv)RODEO:\n\t12.Chicken flavored - Rs.130  (100g)\n\t13.Duos with chicken & bacon flavor - Rs.140  (100g)");
    printf("\n(vi)MEAT STICKS:\n\t14.Bacon flavored - Rs.135  (100g)\n\t15.Grilled liver flavor - Rs.120  (100g)\n\t16.Smoked salmon flavored - Rs.156  (100g)\n\t17.Barbeque Chicken flavored - Rs.149  (100g)");
    printf("\n(vii)DRY FOODS:\n\t18.Dry meat &milk - Rs.160  (1kg)\n\t19.Dry chicken & meat - Rs.195  (1kg)\n\t20.Chicken, egg & rice - Rs.186  (1kg)\n\t21.Vegetarian - Rs.176 (1kg)");
    printf("\n\nEnter your choice(1 to 21): ")
    scanf("%d",&s_f);
    if(s_f==1)
    {
        a_f[1]++;
        cost_f[1]=45;
        totalcost_f+=45;
    }
    else if(s_f==2)
    {
        a_f[2]++;
        cost_f[2]=50;
        totalcost_f+=50;
    }
    else if(s_f==3)
    {
        a_f[3]++;
        cost_f[3]=135;
        totalcost_f+=135;
    }
    else if(s_f==4)
    {
        a_f[4]++;
        cost_f[4]=139;
        totalcost_f+=139;
    }
    else if(s_f==5)
    {
        a_f[5]++;
        cost_f[5]=140;
        totalcost_f+=140;
    }
    else if(s_f==6)
    {
        a_f[6]++;
        cost_f[6]=145;
        totalcost_f+=145;
    }
    else if(s_f==7)
    {
        a_f[7]++;
        cost_f[7]=30;
        totalcost_f+=30;
    }
    else if(s_f==8)
    {
        a_f[8]++;
        cost_f[8]=35;
        totalcost_f+=35;
    }
    else if(s_f==9)
    {
        a_f[9]++;
        cost_f[9]=40;
        totalcost_f+=40;
    }
    else if(s_f==10)
    {
        a_f[10]++;
        cost_f[10]=45;
        totalcost_f+=45;
    }
    else if(s_f==11)
    {
        a_f[11]++;
        cost_f[11]=50;
        totalcost_f+=50;
    }
    else if(s_f==12)
    {
        a_f[12]++;
        cost_f[12]=130;
        totalcost_f+=130;
    }
    else if(s_f==13)
    {
        a_f[13]++;
        cost_f[13]=140;
        totalcost_f+=140;
    }
    else if(s_f==14)
    {
        a_f[14]++;
        cost_f[14]=135;
        totalcost_f+=135;
    }
    else if(s_f==15)
    {
        a_f[15]++;
        cost_f[15]=120;
        totalcost_f+=120;
    }
    else if(s_f==16)
    {
        a_f[16]++;
        cost_f[16]=156;
        totalcost_f+=156;
    }
    else if(s_f==17)
    {
        a_f[17]++;
        cost_f[17]=149;
        totalcost_f+=149;
    }
    else if(s_f==18)
    {
        a_f[18]++;
        cost_f[18]=160;
        totalcost_f+=160;
    }
    else if(s_f==19)
    {
        a_f[19]++;
        cost_f[19]=195;
        totalcost_f+=195;
     else if(s_f==20)
    {
        a_f[20]++;
        cost_f[20]=186;
        totalcost_f+=186;
    }
    else if(s_f==21)
    {
        a_f[21]++;
        cost_f[21]=196;
        totalcost_f+=196;
    }
    for(int j=0;j<21;j++)
    {
        if(a_f[j]!=0)
        {
            printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d",j,dishes[j-1],a_f[j],cost_f[j]);
        }
    }
    printf("\n\n\tCOST is %d",totalcost_f);
    start3:
    printf("\n\nWould you like to modify your choice?\n\t1.Add product\n\t2.Delete product\n\t3.Change Quantity\n\t4.Exit\nEnter your choice: ");
    scanf(" %d",&s_f2);
    if(s_f2 == 1)
    {
        goto start2;
    }
    if(s_f2 == 2)
    {
        int i,id;
        printf("\nEnter the ID of the food product to delete item: ");
        scanf("%d",&id);
        if(id<=21 && id>=0)
        {
            totalcost_f = totalcost_f - (cost_f[id]*a_f[id]);
            a_f[id]=0;
        }
        else
        {
            printf("\nEnter valid ID of the food product: ");
        }
        printf("\n\n\t\tREVISED ITEMS\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d");
        for(i=0;i<21;i++)
        {
            if(a_f[i]!=0)
            {
                printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d\n",i,dishes[i-1],a_f[i],(cost_f[i]*a_f[i]));
            }
        }
        printf("\nTOTAL COST - %d\n",totalcost_f);
        goto start3;
    }
    if(s_f2 == 3)
    {
        int id,quantity;
        printf("\nEnter ID of the food product to change the quantity of an item : ");
        scanf(" %d",&id);
        printf("\nEnter the amount of quantity to be changed of an item : ");
        scanf(" %d",&quantity);
        if(id<=21 && id>=0)
        {
            if(quantity>0 && a_f[id]>0)
            {
                if(quantity<a_f[id])
                {
                    int dec = a_f[id] - quantity;
                    a_f[id] = quantity;
                    totalcost_f = totalcost_f - (cost_f[id]*dec);
                }
                if(quantity>a_f[id])
                {
                    int inc = quantity - a_f[id];
                    a_f[id] = quantity;
                    totalcost_f = totalcost_f + (cost_f[id]*inc);
                }
                if(quantity == a_f[id])
                {
                    a_f[id] = quantity;
                    totalcost_f = totalcost_f + 0;
                }
            }
            else
            {
                printf("Item has no Quantity.Please Try again!!!\n");
            }
        }
        else
        {
            printf("\nEnter the valid ID of the food product: ");
        }
        printf("\n\n\t\tREVISED ITEMS");
        for(int i=0;i<21;i++)
        {
            if(a_f[i]!=0)
            {
                printf("\nITEM CODE: %d\nPRODUCT NAME: %s\nQUANTITY: %d\nPRICE: %d",i,dishes[i-1],a_f[i],(cost_f[i]*a_f[i]));
            }
        }
        printf("\nTOTAL COST - %d\n",totalcost_f);
        goto start3;
    }
}

                                          //PET GROOMING

int petgrooming()
{
    system("clear");
    int rate_g,choice_g,grooming_rate;
    char confirm,bill_g;
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\t\t\t\t\t################### GROOMING #################");
    printf("\n\t\t\t\t\t##############################################");
    printf("\n\n1.BASIC BATH\n\t->Bath\n\t->Conditioning\n\t->Blow dry\n\t->Paw clean\n\t->Organic Perfume\n\t->Brushing/Combing\n\n");
    printf("2.PREMIUM BATH\n\t->Bath\n\t->Conditioning\n\t->Blow dry\n\t->Nail clipping\n\t->Ear cleaning\n\t->Anal cleaning\n\t->Eye cleaning\n\t->Paw balm\n\t->Organic Perfume\n\t->Brushing/Combing\n\n");
    printf("3.BASIC TRIM\n\t->Full body trim\n\t->Paw pads trim\n\t->Hair shaping\n\t->Paw balm\n\t->Brushing/Combing->Bath\n\t->Anal cleaning\n\n");
    printf("4.PREMIUM TRIM\n\t->Full body trim\n\t->Paw pads trim\n\t->Hair shaping\n\t->Shampoo bath\n\t->Conditioning\n\t->Ear cleaning\n\t->Anal cleaning\n\t->Eye cleaning\n\t->Paw balm\n\t->Organic Perfume\n\t->Brushing/Combing\n\n");
    printf("5.ANTI-TICK TREATMENT\n\t->Medical bath\n\t->Blow dry\n\t->Tick removal\n\t->Ear cleaning\n\t->Organic Perfume\n\t->Brushing/Combing\n\n");
    printf("\n\nEnter your choice: ");
    scanf(" %d",&choice_g);
    FILE *fgroom,*groom_bill;
    fgroom = fopen("bill.txt","a");
    fprintf(fgroom,"\n\nYou have chosen grooming!!!");
    if(choice_g == 1)
    {
        grooming_rate = 750;
        fprintf(fgroom,"\n\nTYPE:  Basic Bath\nCOST: Rs.750\n\n");
    }
    if(choice_g == 2)
    {
        grooming_rate = 1200;
        fprintf(fgroom,"\n\nTYPE:  Premium Bath\nPRICE: Rs.1,200\n\n");
    }
    if(choice_g == 3)
    {
        grooming_rate = 900;
        fprintf(fgroom,"\n\nTYPE:  Basic Trim\nPRICE: Rs.900\n\n");
    }
    if(choice_g == 4)
    {
        grooming_rate = 1600;
        fprintf(fgroom,"\n\nTYPE:  Premium Trim\nPRICE: Rs.1,600\n\n");
    }
    if(choice_g == 5)
    {
        grooming_rate = 700;
        fprintf(fgroom,"\n\nTYPE:  Anti-Tick Treatment\nPRICE: Rs.700\n\n");
    }
    rate_g = grooming_rate;
    printf("\nThe bill has been created!\nTOTAL COST - %d",rate_g);
    fclose(fgroom);
    gbill:
    printf("\n\nDisplay bill(y/n)? ");
    scanf(" %s",&confirm);
    if(confirm == 'y')
    {
        groom_bill = fopen("bill.txt","r");
        do
        {
            bill_g = fgetc(groom_bill);
            putchar(bill_g);
        }while(bill_g!=EOF);
        fclose(groom_bill);
    }
    else
    {
        if(confirm == 'n')
        {
            exit (0);
        }
        else
        {
            printf("\nInvalid choice");
            goto gbill;
        }
    }
}
