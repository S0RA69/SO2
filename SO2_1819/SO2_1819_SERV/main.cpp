#include<Windows.h>
#include <stdio.h>
#include <time.h>
#include <tchar.h>
#include <thread>
#include <fcntl.h>
#include <tchar.h>
#include <stdlib.h>
#include "shared.h"

using namespace shared;

int _tmain(int argc, char* argv[])
{
	DWORD LobbyThreadID, RefreshThreadID;
	HANDLE LobbyThreadHandle, RefreshThreadHandle;
	char * input = (char*)malloc(100);

	if (!InitSharedMemory())
	{
		printf("Erro ao montar memoria partilhada, a sair...\n");
		return 1;
	}
	else
	{
		printf("Memoria partilhada ok...\n");
	}

	printf("A iniciar lobby...\n");

	/*
	LobbyThreadHandle = CreateThread(
	NULL,                   // default security attributes
	0,                      // use default stack size
	LobbyThread,       // thread function name
	NULL,          // argument to thread function
	0,                      // use default creation flags
	&LobbyThreadID);   // returns the thread identifier
	*/



	{
		//processar teclado
		fflush(stdin);
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = 0;

		if (strcmp(input, "comecar") == 0)
		{
			//comecarJogo(&RefreshThreadHandle, &RefreshThreadID);
		}
		else if (strcmp(input, "test") == 0)
		{
			if (test())
			{
				printf(" saves");
			}
			else
				printf(" dont save");
		}
	}while (strcmp(input, "sair"));

}