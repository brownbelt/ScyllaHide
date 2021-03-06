#pragma once

#include <ntdll/ntdll.h>

FORCEINLINE ULONG NTAPI RtlNtMajorVersion()
{
	return *(PULONG)(0x7FFE0000 + 0x26C);
}

FORCEINLINE ULONG NTAPI RtlGetTickCount()
{
	return (ULONG)(*(PULONG64)(0x7FFE0000 + 0x320) * *(PULONG)(0x7FFE0000 + 0x4) >> 24);
}

bool IsValidHandle(HANDLE hHandle);
bool IsValidThreadHandle(HANDLE hThread);
bool IsValidProcessHandle(HANDLE hProcess);
bool HasDebugPrivileges(HANDLE hProcess);
DWORD GetExplorerProcessId();
DWORD GetProcessIdByName(const WCHAR * processName);
bool IsProcessBad(PUNICODE_STRING process);

DWORD GetProcessIdByProcessHandle(HANDLE hProcess);
DWORD GetThreadIdByThreadHandle(HANDLE hThread);
DWORD GetProcessIdByThreadHandle(HANDLE hThread);

bool wcsistr(const wchar_t *s, const wchar_t *t);

bool IsWindowNameBad(PUNICODE_STRING lpszWindow);
bool IsWindowClassBad(PUNICODE_STRING lpszClass);
bool IsObjectTypeBad(USHORT objectTypeIndex);

size_t _wcslen(const wchar_t* sc);
size_t _strlen(const char* sc);
wchar_t * _wcscat(wchar_t *dest, const wchar_t *src);

int ThreadDebugContextFindFreeSlotIndex();
int ThreadDebugContextFindExistingSlotIndex();
void ThreadDebugContextRemoveEntry(const int index);
void ThreadDebugContextSaveContext(const int index, const PCONTEXT ThreadContext);

void IncreaseSystemTime(LPSYSTEMTIME lpTime);

void TerminateProcessByProcessId(DWORD dwProcess);
bool WriteMalwareToDisk(LPCVOID buffer, DWORD bufferSize, DWORD_PTR imagebase);
bool WriteMemoryToFile(const WCHAR * filename, LPCVOID buffer, DWORD bufferSize, DWORD_PTR imagebase);
void * GetPEBRemote(HANDLE hProcess);
void DumpMalware(DWORD dwProcessId);

void checkStructAlignment();
