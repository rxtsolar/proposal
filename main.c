#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define WORDS_PATH "/home/guangyu/Documents/engagement/words"
#define HEART_PATH "/home/guangyu/Documents/engagement/heart"
#define USLEEP_TIME 60000
#define SCREEN_HEIGHT 44

void clear()
{
	int i;
	for (i = 0; i < SCREEN_HEIGHT; i++)
		printf("\n");
}

void show_pic(char *name)
{
	char buffer[BUFFER_SIZE];
	FILE *fp = fopen(name, "r");

	if (!fp) {
		perror("show_pic");
		exit(1);
	}

	while (!feof(fp)) {
		fgets(buffer, BUFFER_SIZE, fp);
		printf("%s", buffer);
		usleep(USLEEP_TIME);
	}

	fclose(fp);
}

void wait_for_answer()
{
	char *buffer = NULL;
	size_t len;
	printf("Ms. Ziyi Zhang, would you like to marry Mr. Guangyu Sun (yes/no)? ");
	for(;;) {
		getline(&buffer, &len, stdin);
		if (!strcmp(buffer, "yes\n")) {
			free(buffer);
			break;
		} else if (!strcmp(buffer, "no\n")) {
			printf("Bad answer, please try again.\n");
			printf("Ms. Ziyi Zhang, would you like to marry Mr. Guangyu Sun (yes/no)? ");
		} else {
			printf("Please type 'yes' or 'no': ");
		}
		free(buffer);
		buffer = NULL;
	}
}

void congrats()
{
	printf("Congratulations! You are engaged!\n");
}

int main(int argc, char *argv[])
{
	clear();
	show_pic(WORDS_PATH);
	wait_for_answer();
	show_pic(HEART_PATH);
	congrats();

	return 0;
}
