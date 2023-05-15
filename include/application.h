#pragma once 

#include "window.h"

namespace BDSM
{
	class Application
	{
	public:

		Application() = delete;
		Application(Application&) = delete;
		Application(Application&&) = delete;
		Application(std::string_view title, ImVec2 windowSize = { 1280, 720 });

		Application& operator=(Application&) = delete;
		Application& operator=(Application&&) = delete;

		Window* GetWindow();

		void Run();

		~Application();

	private:
		Window* m_window = nullptr;
	protected:
		virtual void Setup() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	};
}