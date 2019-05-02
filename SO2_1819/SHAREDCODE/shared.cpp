#include "shared.h"
#include "info.h"

namespace shared {

	HANDLE Pagina = NULL;
	void* ponteiroNaPagina = NULL;

	bool test() {
		if (Pagina != NULL)
		{
			return true;
		}
		return false;
	}

	bool InitSharedMemory() {
		Pagina = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0,
			PAGESIZE,
			TEXT(PAGE_NAME)
		);

		if (Pagina == NULL)
			return FALSE;

		ponteiroNaPagina = MapViewOfFile(
			Pagina,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			PAGESIZE
		);

		if (ponteiroNaPagina == NULL)
			return FALSE;
		else
			return TRUE;
	}
}
