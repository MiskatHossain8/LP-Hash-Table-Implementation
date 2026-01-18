#include<stdio.h>
/*Problem-6: Implementation of Linear probing hash tables
Group Number: 7
1) Name: Md. Miskat Hossain
ID: 2021-2-60-109

2) Name: Ifthekhar Iqbal Enan
ID: 2021-2-60-043
*/
int max,prime,size=0;
int *arrTable;
int hashFunction(int x)
{
    return x%prime;
}
void insert(int x)
{
    int index=hashFunction(x);
    while(arrTable[index]!=-1)
    {
        index=index+1;
        if(arrTable[index]==-2)
        {
            break;
        }
    }
    printf("Added successfully\n");
    arrTable[index]=x;
    size++;
}
void delete(int x)
{
    int index=hashFunction(x);
    int c=0;
    while(arrTable[index]!=-1)
    {
        if(arrTable[index]==x)
        {
            size--;
            arrTable[index]=-2;
            printf("Deleted successfully\n");
            c=1;
            break;
        }
        index=(index+1)%max;
        if(index==hashFunction(x))
        {
            break;
        }
    }
    if(c==0)
    {
        printf("ELEMENT NOT FOUND\n");
    }
}
void display()
{
    for (int i=0; i<max; i++)
    {
        if (arrTable[i]!=-1)
        {
            printf("Index %d: %d\n",i,arrTable[i]);
        }
    }
}
int search(int x)
{
    int index=hashFunction(x);
    int count=0;
    while (arrTable[index]!=-1)
    {
        if (arrTable[index]==x)
        {
            return index;
        }
        index=(index+1)%max;
        if (index==hashFunction(x) || count>=max)
        {
            break;
        }
        count++;
    }
    return -1;
}
int tableSize()
{
    return size;
}
int main()
{
    int k,i,j=0,n=1,x;
    printf("Enter the size of HASH TABLE: ");
    scanf("%d",&max);
    prime=max;
    while(j!=1)
    {
        k=0;
        prime=prime+1;
        for(i=2; i<prime; i++)
        {
            if(prime%i==0)
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
            j=1;
        }
    }
    printf("Next Prime Number: %d\n",prime);
    arrTable=(int*)malloc(max*sizeof(int));
    for (int i=0; i<max; i++)
    {
        arrTable[i]=-1;
    }
    while(n!=0)
    {
        printf("1) Insert an element\n");
        printf("2) Delete an element\n");
        printf("3) Display Hash\n");
        printf("4) Check the size of Hashtable\n");
        printf("5) Search an element\n");
        printf("0) Exit\n");
        printf("Enter any number between 0-5: ");
        scanf("%d",&n);
        if(n==1)
        {
            if(size<max)
            {
                scanf("%d",&x);
                insert(x);
            }
            else
            {
                printf("Hashtable Full\n");
            }
        }
        else if(n==2)
        {
            scanf("%d",&x);
            delete(x);
        }
        else if(n==3)
        {
            display();
        }
        else if(n==4)
        {
            int my;
            my=tableSize();
            printf("%d\n",my);
        }
        else if(n==5)
        {
            scanf("%d",&x);
            int my= search(x);
            if(my!=-1)
            {
                printf("Index: %d Found\n",my);
            }
            else
            {
                printf("NOT FOUND\n");
            }
        }
        else
        {
            n=0;
        }
    }

}
