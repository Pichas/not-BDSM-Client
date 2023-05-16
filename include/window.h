#pragma once

#include <SDL.h>
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer.h"
#include <imgui.h>

#include <string_view>
#include <iostream>

namespace BDSM
{
struct Window
{
	Window(std::string_view title, ImVec2 windowSize);
	~Window();

	void Draw();

	ImColor clearColor = ImColor(115, 140, 153);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};
}