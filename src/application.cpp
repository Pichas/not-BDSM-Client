#include "../include/application.h"

BDSM::Application::Application(std::string_view title, ImVec2 windowSize) : m_window(new Window(title, windowSize))
{}

BDSM::Window* BDSM::Application::GetWindow()
{
	return m_window;
}

void BDSM::Application::Run()
{
	Setup();
	bool done = false;
	while (!done)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			ImGui_ImplSDL2_ProcessEvent(&e);
			if (e.type == SDL_QUIT)
				done = true;
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE && e.window.windowID == SDL_GetWindowID(m_window->GetWindow()))
				done = true;
		}

		Update();
		Draw();

		m_window->Draw();

	}
}

BDSM::Application::~Application()
{
	delete m_window;
}
