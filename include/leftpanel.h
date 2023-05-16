#include "imgui.h"
#include "../include/imgui_impl_sdl2.h"
#include "../include/imgui_impl_sdlrenderer.h"

#include "../include/panel.h"


namespace BDSM
{

struct LeftPanel final : Panel
{
    LeftPanel(/*some params*/){}
    void Draw() override;
};

};