#ifndef CIMFILEBROWSER_H
#define CIMFILEBROWSER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ImFileBrowserFlags {
    ImFileBrowserFlags_SelectDirectory       = 1 << 0,  // select directory instead of regular file
    ImFileBrowserFlags_EnterNewFilename      = 1 << 1,  // allow user to enter new filename when selecting regular file
    ImFileBrowserFlags_NoModal               = 1 << 2,  // file browsing window is modal by default. specify this to use a popup window
    ImFileBrowserFlags_NoTitleBar            = 1 << 3,  // hide window title bar
    ImFileBrowserFlags_NoStatusBar           = 1 << 4,  // hide status bar at the bottom of browsing window
    ImFileBrowserFlags_CloseOnEsc            = 1 << 5,  // close file browser when pressing 'ESC'
    ImFileBrowserFlags_CreateNewDir          = 1 << 6,  // allow user to create new directory
    ImFileBrowserFlags_MultipleSelection     = 1 << 7,  // allow user to select multiple files. this will hide ImFileBrowserFlags_EnterNewFilename
    ImFileBrowserFlags_HideRegularFiles      = 1 << 8,  // hide regular files when ImFileBrowserFlags_SelectDirectory is enabled
    ImFileBrowserFlags_ConfirmOnEnter        = 1 << 9,  // confirm selection when pressing 'ENTER'
    ImFileBrowserFlags_SkipItemsCausingError = 1 << 10, // when entering a new directory, any error will interrupt the process, causing the file browser to fall back to the working directory.
                                                           // with this flag, if an error is caused by a specific item in the directory, that item will be skipped, allowing the process to continue.
    ImFileBrowserFlags_EditPathString        = 1 << 11, // allow user to directly edit the whole path string
} ImFileBrowserFlags_t;

typedef struct ImFileBrowser ImFileBrowser;

ImFileBrowser* ImFileBrowser_Create(ImFileBrowserFlags_t flags);
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