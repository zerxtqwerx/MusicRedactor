#pragma once
#ifndef GUARDIAN_SoundFileDialog
#define GUARDIAN_SoundFileDialog

#include <windows.h>
#include <shobjidl.h> 
#include <combaseapi.h>
#include "FileDialog.h"
#include "Sound.h"


void ShowFileDialog(PWSTR pszFilePath)
{

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileDialog* pFileOpen;

		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			hr = pFileOpen->Show(NULL);

			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					if (SUCCEEDED(hr))
					{
						MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();

				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
}

#endif

//#include "windows.h"
//#include "commdlg.h"
//
//
//OPENFILENAME ofn;       // common dialog box structure
//char szFile[260];       // buffer for file name
//HWND hwnd;              // owner window
//HANDLE hf;              // file handle
//
//// Initialize OPENFILENAME
//ZeroMemory(&ofn, sizeof(ofn));
//ofn.lStructSize = sizeof(ofn);
//ofn.hwndOwner = hwnd;
//ofn.lpstrFile = szFile;
//// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
//// use the contents of szFile to initialize itself.
//ofn.lpstrFile[0] = '\0';
//ofn.nMaxFile = sizeof(szFile);
//ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
//ofn.nFilterIndex = 1;
//ofn.lpstrFileTitle = NULL;
//ofn.nMaxFileTitle = 0;
//ofn.lpstrInitialDir = NULL;
//ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//
//// Display the Open dialog box. 
//
//if (GetOpenFileName(&ofn) == TRUE)
//hf = CreateFile(ofn.lpstrFile,
//    GENERIC_READ,
//    0,
//    (LPSECURITY_ATTRIBUTES)NULL,
//    OPEN_EXISTING,
//    FILE_ATTRIBUTE_NORMAL,
//    (HANDLE)NULL);