#ifndef CIMFILEBROWSER_H
#define CIMFILEBROWSER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ImFileBrowser ImFileBrowser;

ImFileBrowser* ImFileBrowser_Create();
void ImFileBrowser_Destroy(ImFileBrowser* browser);
void ImFileBrowser_SetWindowPos(ImFileBrowser* browser, int x, int y);
void ImFileBrowser_SetWindowSize(ImFileBrowser* browser, int width, int height);
void ImFileBrowser_SetTitle(ImFileBrowser* browser, const char* title);
void ImFileBrowser_Open(ImFileBrowser* browser);
void ImFileBrowser_Close(ImFileBrowser* browser);
int ImFileBrowser_IsOpen(ImFileBrowser* browser);
void ImFileBrowser_Display(ImFileBrowser* browser);
int ImFileBrowser_HasSelected(ImFileBrowser* browser);
int ImFileBrowser_SetDirectory(ImFileBrowser* browser, const char* dir);
const char* ImFileBrowser_GetDirectory(ImFileBrowser* browser);
const char* ImFileBrowser_GetSelected(ImFileBrowser* browser);
void ImFileBrowser_SetTypeFilters(ImFileBrowser* browser, const char** type_filters, int count);
void ImFileBrowser_SetTypeFilterIndex(ImFileBrowser* browser, int index);
void ImFileBrowser_SetInputName(ImFileBrowser* browser, const char* input);
void ImFileBrowser_ClearSelected(ImFileBrowser* browser);

#ifdef __cplusplus
}
#endif

#endif // CIMFILEBROWSER_H