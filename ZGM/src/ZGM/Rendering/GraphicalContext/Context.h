#pragma once

namespace ZGM {
	class Context {
	public:
		virtual bool Init() = 0;
		virtual void SwapBuffers() = 0;
		virtual bool VSync(bool isEnable) = 0;
	};
}