#include <stdio.h>

void sortArrayElement(int array[],int size){

    int i,j;

    int tmp;

    for (int i = 0; i < size; i++){

        if (array[i]%2!=0){

               array[i] *= -1;

        }
    }
    
    for(i=0; i<size-1; i++)

    {

       for(j=0; j<size-i-1; j++)

        {

           if(array[j]>array[j+1])

           {    

               // swap array element

                tmp=array[j];

                array[j]=array[j+1];

                array[j+1]=tmp;

           }

        }

    }   


   for (int i = 0; i < size; i++){

        if (array[i] %2!=0){

            array[i] *= -1;

        }

   }

}

int main()

{
    FILE *inputFile;

    char fName[60];

    int n,size;
    scanf("%s",fName);
    inputFile = fopen(fName, "r");
    if (inputFile == NULL)

    {

        printf("Invalid file format!\n");

    }else if((inputFile!=NULL)){


            fscanf(inputFile,"%d",&size);


            int arr[size];

            int k =0;


            while (!feof(inputFile))

            {

                fscanf(inputFile, "%d",&n);

                arr[k++] = n;

            }

            sortArrayElement(arr,size);



            for (int i =size-1; i >=0; i--){

                if(arr[i]%2!=0){

                    printf("%d ",arr[i]);

                }

            }


            for (int i =size-1; i >=0; i--){

                if(arr[i]%2==0){

                    printf("%d ",arr[i]);

                }

            }  

    }

    return 0;

}
