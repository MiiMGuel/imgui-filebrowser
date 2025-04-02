#include "imgui/imgui.h"
#include "cimfilebrowser.h"
#include "imfilebrowser.h"

extern "C" {
    struct ImFileBrowser {
        ImGui::FileBrowser fbrowser;
        std::string selected;
        std::string directory;
    };

    ImFileBrowser* ImFileBrowser_Create(ImFileBrowserFlags_t flags) {
        ImFileBrowser* browser = new ImFileBrowser();
        browser->fbrowser = ImGui::FileBrowser((ImGuiFileBrowserFlags_)flags);
        return browser;
    }

    void ImFileBrowser_Destroy(ImFileBrowser* browser) {
        delete browser;
    }

    void ImFileBrowser_SetWindowPos(ImFileBrowser* browser, int x, int y) {
        browser->fbrowser.SetWindowPos(x, y);
    }

    void ImFileBrowser_SetWindowSize(ImFileBrowser* browser, int width, int height) {
        browser->fbrowser.SetWindowSize(width, height);
    }

    void ImFileBrowser_SetTitle(ImFileBrowser* browser, const char* title) {
        browser->fbrowser.SetTitle(std::string(title));
    }

    void ImFileBrowser_Open(ImFileBrowser* browser) {
        browser->fbrowser.Open();
    }
    
    void ImFileBrowser_Close(ImFileBrowser* browser) {
        browser->fbrowser.Close();
    }
    
    int ImFileBrowser_IsOpen(ImFileBrowser* browser) {
        return browser->fbrowser.IsOpened();
    }

    void ImFileBrowser_Display(ImFileBrowser* browser) {
        browser->fbrowser.Display();
    }

    int ImFileBrowser_HasSelected(ImFileBrowser* browser) {
        if (browser->fbrowser.HasSelected()) {
            browser->selected = browser->fbrowser.GetSelected().string();
            return 1;
        }
        return 0;
    }

    int ImFileBrowser_SetDirectory(ImFileBrowser* browser, const char* dir) {
        if (dir) return browser->fbrowser.SetDirectory(std::string(dir));
        else return 0;
    }
    
    const char* ImFileBrowser_GetDirectory(ImFileBrowser* browser) {
        std::string dir = browser->fbrowser.GetDirectory().string();
        if (dir.empty()) return NULL;

        browser->directory = dir; 
        return browser->directory.c_str();
    }

    const char* ImFileBrowser_GetSelected(ImFileBrowser* browser) {
        return browser->selected.c_str();
    }
    
    void ImFileBrowser_ClearSelected(ImFileBrowser* browser) {
        browser->fbrowser.ClearSelected();
        browser->selected.clear();
    }
    
    void ImFileBrowser_SetTypeFilters(ImFileBrowser* browser, const char** type_filters, int count) {
        if (!type_filters || count <= 0) return;
        
        std::vector<std::string> filters;
        for (int i = 0; i < count; i++) {
            if (type_filters[i]) {
                filters.emplace_back(type_filters[i]);
            }
        }

        browser->fbrowser.SetTypeFilters(filters);
    }

    void ImFileBrowser_SetTypeFilterIndex(ImFileBrowser* browser, int index) {
        browser->fbrowser.SetCurrentTypeFilterIndex(index);
    }
    
    void ImFileBrowser_SetInputName(ImFileBrowser* browser, const char* input) {
        browser->fbrowser.SetInputName(input);
    }
}
