#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>

char cur_dir[200];
char *get_cmd(char *c_cmd);
int main(int argc, char *argv[])
{
	DIR *d;
    struct dirent *dir;
    
	char cur_cmd[100];
	
	if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
      perror("getcwd() error");
    
	while(1)
	{
		printf("Bobby [%s] :>", cur_dir);
		gets(cur_cmd);
	
		if(strcmp(cur_cmd,"exit")==0)
		{
			return 0;
		}
		if(strcmp(cur_cmd, "dir")==0)
		{
			d = opendir(cur_dir);
			if (d)
    		{
        		while ((dir = readdir(d)) != NULL)
        		{
            		printf("%s\t\t\t%d\n", dir->d_name, dir->d_reclen);
        		}
        		closedir(d);
    		}
    		//return 0;
		}
		if(strcmp(get_cmd(cur_cmd),"cd")==0)
		{
			chdir("..");
			
			
			if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
      			perror("getcwd() error");
      	
		}
	}
}
char *get_cmd(char *c_cmd)
{
	char cmd[50];
	int i=0;
	cmd[0]='\0';
	printf("%s",c_cmd);
	while((c_cmd[i]!=' ')&&(c_cmd[i]!='\0'))
	{
		cmd[i]=c_cmd[i];
		i++;
	}
	cmd[i]='\0';
	return cmd;
}
