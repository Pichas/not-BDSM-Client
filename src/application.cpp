#include "../include/application.h"

namespace BDSM
{

Application::Application(std::string_view title, ImVec2 windowSize) 
	: m_window(new Window(title, windowSize))
{
	//init all env
	m_panels.emplace_back(new LeftPanel());

	//m_panels.emplace_back(new rightPanel());
	//....
}

void Application::StartFrame()
{
	//tasks at start of the frame
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void Application::EndFrame()
{
	//tasks at end of the frame
	m_window->Draw(); //в нужное место переместить и вообще проверить содержимое метода
}

bool Application::ProcessEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_QUIT)
			return false;
		if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE && 
				e.window.windowID == SDL_GetWindowID(m_window->window))
			return false;
	}
	return true;
}

void Application::Run()
{
	do
	{
		StartFrame();

		for (auto p : m_panels){
			p->Draw();
		}
	
		EndFrame();
	}while (ProcessEvents());
}


}
