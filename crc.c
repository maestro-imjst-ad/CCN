# include <stdio.h>
# include <conio.h>
# define DEGREE 16   

int result[30];
int getnext(int array[],int pos)
{
	int i=pos;
	while(array[i]==0)
		++i;
	return i;
}
int mod2add(int x,int y)    
{
	return (x==y ? 0 : 1);
}
void calc_CRC(int length)
{
	int ccitt[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};  /* Generator polynomial = x16 + x12 + x5 + 1 */
	int i=0,pos=0,newpos;
    while(pos<length-DEGREE)
	{
		/* Performing mod-2 division for DEGREE number of bits */
		for (i=pos;i<pos+DEGREE+1;++i)
			result[i]=mod2add(result[i],ccitt[i-pos]);
		newpos=getnext(result,pos);

		/* Skipping the mod-2 division if lesser than DEGREE bits are available for division */

		if (newpos>pos+1) pos=newpos-1;
		++pos;
	}
}

void main()
{
	int array[30],ch;
	int length,i=0;
	
	/* Inputting data */

	printf("Enter the data stream : ");
	while((ch=getche())!='\r'){
		array[i]=ch-'0';
		i++;
	}
	length=i;
	
	/* Appending zeros */

	for (i=0;i<DEGREE;++i)
		array[i+length]=0;
	length+=DEGREE;

	/* Duplicating the data input */

	for (i=0;i<length;i++)
		result[i]=array[i];
	calc_CRC(length); /* Calculation of CRC */
	printf("\nThe transmitted frame is : ");
	for (i=0;i<length-DEGREE;++i)             /* Printing the data */
		printf("%d ",array[i]);
	for (i=length-DEGREE;i<length;++i)   /* Printing the checksum */
		printf("%d ",result[i]);

	printf("\nEnter the stream for which CRC has to be checked : ");
	i=0;
	
	/* Inputting the stream to be checked */

	while((ch=getche())!='\r'){
		array[i]=ch-'0';
		i++;
	}
	length=i;

	/* Duplicating the array */

	for (i=0;i<length;i++)
		result[i]=array[i];
	calc_CRC(length); /* Calculation of CRC */
	printf("\nChecksum : ");
	for (i=length-DEGREE;i<length;++i)   /* Printing the checksum */
		printf("%d ",result[i]);
	getch();
}

