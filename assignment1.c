#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define length(a) ((int) (sizeof (a) / sizeof (a)[0])) 

int main(int argc, char *argv[])
{
	FILE *dpt, *ipt, *opt;
	int counter, row = 0, d, i, wlength, k, track = 1, wordlen, j, value, tracker=1;
	char ch[30], *pointer, substring, *pointer2, *suggestion, word[30];
	char dictionary[45426][30], suggestions[10][30];
	char substr[30];
	bool wordcheck[] = {true};
	
	if(argc != 3){
		printf("Incorrect number of arguments entered.\n");
		exit(0);
	}
	
	dpt = fopen("linux.words", "r");
	while ((d = fgetc(dpt)) != EOF){
		fscanf(dpt, "%[^\n]", ch);
		pointer = *(dictionary + row);
		strcpy(pointer, ch);
		++row; 
		//printf("Pointer: %s\n", pointer);
	}
	
	ipt = fopen(argv[1],"r");
	opt = fopen(argv[2],"w");
	
	
	while(fscanf(ipt,"%[a-zA-Z]%*[^a-zA-Z]",word)!=EOF){
		for (i=0; i<length(dictionary); i++)
		{
			pointer = *(dictionary + i);
			if (strcmp(pointer, word) == 0){
				printf("Match found for %s\n", word);
				fprintf(opt, "%s\n", word);
				wordcheck[0] = false;
			} 
		}
		if (wordcheck[0] == true){
			//printf("True");
			if(tracker==0){
				break;
			}
			printf("Suggestions for (%s) are: \n", word);
			wordlen = (strlen(word)-1);
			for(wordlen;wordlen>0;--wordlen){
				strncpy(substr, word, wordlen);
				substr[wordlen] = 0; 
				//printf("%s %s %d\n", substr, word, wordlen);
				for(j=0;j<length(dictionary);++j){
					pointer2 = *(dictionary+j);
					if(strcmp(substr,pointer2)==0){
						suggestion =*(suggestions + track);
						strcpy(suggestion,pointer2);
						//printf("Suggestions: %s\n", suggestion);
						++track; 
						if(track>10)
								continue;
					} 
				}
			}	
		}
		if (track<10){
			wordlen = (strlen(word)-1);
			for(wordlen;wordlen>0;--wordlen){
				strncpy(substr, word, wordlen);
				substr[wordlen] = 0; 
				//printf("%s %s %d\n", substr, word, wordlen);
				for(j=0;j<length(dictionary);++j){
					pointer2 = *(dictionary+j);
					if(strstr(pointer2,substr) != 0){
						for (i=0; i<10; i++){
							if (strcmp(pointer2, &suggestions[i][30]) == 0){
								continue;
							} 
						}
						if(track<=10){
							suggestion =*(suggestions + track);
							strcpy(suggestion,pointer2);
							printf("Suggestions: %s\n", suggestion);
							++track; 
						}
					}
				}
			}
		}
		while(tracker==1){
			printf("Enter 0 to exit, 1 to keep original word and 2 to change word.\n");
			scanf("%d", &value);
			if (value==0){
				tracker=0;
			}
			if (value==1){
				printf("The word (%s) will be sent to the output file. \n", word);
				fprintf(opt, "%s\n", word);
			}
			if (value==2){
				printf("The suggestions for (%s) are: \n", word);
				for(i=0;i<10;++i){
					printf("%d. %s\n", i+1, &suggestions[i][30]); 
				}
				printf("Which word would you like to replace (%s) with?\n", word);
				scanf("%d", &value);
				if (value>0 && value<11){
					printf("The word (%s) will be sent to the output file. \n", &suggestions[value-1][30]);
					fprintf(opt, "%s\n", &suggestions[value-1][30]);
				} else {
					printf("Number entered must be between 1 and 10");
				}
			}
		}
			
	}
	fclose(ipt);
	fclose(opt);
}
