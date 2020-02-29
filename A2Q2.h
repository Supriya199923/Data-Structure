void print_list()
{
    printf("******************MENU*************\n");
    printf("Enter 1 to insert new data\n");
    printf("Enter 2 to delete previous data\n");
    printf("Enter 3 to modify previous data\n");
    printf("Enter 4 to print_data\n");
    printf("Enter 5 to exit\nYour choice: ");
}
int get_dim()
{
    int temp;
    printf("Enter the dimension of your matrix: ");
    scanf("%d",&temp);
    return temp;
}
int get_bound()
{
    int temp;
    printf("Enter the bound to create sparse array for matrix: ");
    scanf("%d",&temp);
    return temp;
}
void get_data(int sparse[],int n,int &last_idx)
{
    int i=0,choice,a,b,data;
    printf("Enter 1 to add new element or 2 to exit: ");
    scanf("%d",&choice);
    while(choice==1)
    {
        printf("Enter the location and data(row,column,data): ");
        scanf("%d%d%d",&a,&b,&data);
        sparse[3*last_idx+0]=a;
        sparse[3*last_idx+1]=b;
        sparse[3*last_idx+2]=data;
        last_idx+=1;
        printf("Enter 1 to add new element or 2 to exit: ");
        scanf("%d",&choice);
    }
}
void insert_new_data(int sparse[],int n,int &last_idx)
{
    int i=0,choice,a,b,data;
    printf("Enter 1 to add new element or 2 to exit: ");
    scanf("%d",&choice);
    while(choice==1)
    {
        printf("Enter the location and data: ");
        scanf("%d%d%d",&a,&b,&data);
        int c=0,f=0;
        for(c=0;c<last_idx;i++)
        {
            if(sparse[3*c+0]==a&&sparse[3*c+1]==b)
            {
                printf("Do you want to modify(1-YES\t2-NO)!!!\n");
                scanf("%d",&f);
                if(f==1)
                    sparse[3*c+2]=data;
                f=1;
            }
        }
        if(f==0)
        {
            sparse[3*last_idx+0]=a;
            sparse[3*last_idx+1]=b;
            sparse[3*last_idx+2]=data;
        }
        last_idx+=1;
        printf("Enter 1 to add new element or 2 to exit: ");
        scanf("%d",&choice);
    }
}
void modify_data(int sparse[],int n,int last_idx)
{
    int i=0,choice,a,b,data;
    printf("Enter 1 to modify element or 2 to exit: ");
    scanf("%d",&choice);
    while(choice==1)
    {
        printf("Enter the location and new data: ");
        scanf("%d%d%d",&a,&b,&data);
        for(i=0;i<last_idx;i++)
        {
            if(sparse[i*3+0]=='a'&&sparse[i*3+1]=='b')
            {
                sparse[i*3+2]=data;
                break;
            }
        }
        if(i==n)
            printf("Data doesn't exist\n");
        printf("Enter 1 to modify element or 2 to exit: ");
        scanf("%d",&choice);
    }
}
void delete_data(int *sparse,int n,int last_idx)
{
    int i=0,choice,a,b,data;
    printf("Enter 1 to delete element or 2 to exit: ");
    scanf("%d",&choice);
    while(choice==1)
    {
        printf("Enter the location : ");
        scanf("%d%d%d",&a,&b,&data);
        for(i=0;i<last_idx;i++)
        {
            if(sparse[i*3+0]=='a'&&sparse[i*3+1]=='b')
                sparse[i*3+2]=-1;
        }
        printf("Enter 1 to delete element or 2 to exit: ");
        scanf("%d",&choice);
    }
}
void print_data(int sparse[],int last_idx)
{
    printf("*******************DATA**********************\n");
    printf("S No.         Row          Column        Data\n");
    int i=0;
    for(i=0;i<last_idx;i++)
        printf("%d           %d              %d             %d\n",i+1,sparse[i*3+0],sparse[i*3+1],sparse[i*3+2]);
}
