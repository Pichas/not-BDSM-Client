#pragma once

#include <SDL.h>
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer.h"
#include <imgui.h>

#include <string_view>

namespace BDSM
{
	class Window
	{
	public:
		Window(std::string_view title, ImVec2 windowSize);

		SDL_Window* GetWindow();
		SDL_Renderer* GetRenderer();

		const ImVec4& GetClearColor();
		void SetClearColor(ImVec4 clearColor);

		void Draw();

		~Window();
	private:

		ImVec4 m_clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	};
}