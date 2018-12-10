#include<stdio.h>
#include<string.h>

main()
{
	FILE *fpt, *pt;
	int charactercount=0, i, counter, value, j, k;
	fpt = fopen("words.txt", "w");
	fprintf(fpt, "This course is Systems Programming. \n");
	fclose(fpt);
	char text[80];
	pt = fopen("words.txt", "r");
	fread(text, 1, 80, pt);
	printf("%s\n", text);
	counter = strlen(text);
	text[counter] = 0;
	int lst[13] = {3,4,5,6,7,8,9,10,11,12,13,14,15};
	int numbytes[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (i=0; i<strlen(text); i++)
	{	
		if (text[i]>=33 && text[i]<=126){
			charactercount++;
		}
		if (text[i] == 32 && text[i-1]>=33 && text[i-1]<=126){
			if (charactercount>=3 && charactercount<=15){
				if (numbytes[charactercount-1] == 0){
					numbytes[charactercount-1] = 1;
				} else {
					value = numbytes[charactercount-1];
					numbytes[charactercount-1] = value + 1;
				}
			}
			charactercount = 0;
		}
	}
	for(k=0; k<13; k++)
	{
		if (numbytes[k] > 0){
			printf("Words with %d bytes = %d\n", k+1, numbytes[k]);
		}
	}
	fclose(pt);
}
