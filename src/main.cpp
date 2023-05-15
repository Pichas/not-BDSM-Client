#include <iostream>

#include "imgui.h"
#include "../include/imgui_impl_sdl2.h"
#include "../include/imgui_impl_sdlrenderer.h"
#include <stdio.h>
#include <SDL.h>

#include "../include/application.h"

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

using namespace BDSM;

class App final : public Application
{
public:
    App() : Application("BDSM")
    {

    }

    void Setup() override
    {

    }

    void Update() override
    {

    }

    void Draw() override
    {
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Left Panel", 0, ImGuiWindowFlags_NoTitleBar);
        ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
        ImGui::SetWindowSize({ ImGui::GetIO().DisplaySize.x * 0.2f, ImGui::GetIO().DisplaySize.y });
        ImGui::SetWindowCollapsed(false);
        ImGui::End();

    }

private:

};

int main(int argc, char** argv)
{
    App app;
    app.Run();
    return 0;
}