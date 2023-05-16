#include "../include/leftpanel.h"

namespace BDSM
{

void LeftPanel::Draw() 
{
    ImGui::Begin("Left Panel", 0, ImGuiWindowFlags_NoTitleBar);
    ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetWindowSize({ ImGui::GetIO().DisplaySize.x * 0.2f, ImGui::GetIO().DisplaySize.y });
    ImGui::SetWindowCollapsed(false);
    ImGui::End();
}

};
