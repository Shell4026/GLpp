#pragma once

namespace glpp
{
	template<typename T>
	class Singleton
	{
	private:
		static T* instance;
	protected:
		Singleton()
		{

		}
	public:
		Singleton(const Singleton& obj) = delete;
		void operator=(const Singleton& obj) = delete;
		static T* GetInstance()
		{
			if (instance == nullptr)
				instance = new T;
			return instance;
		}

		void DestroyInstance()
		{
			if (instance == nullptr)
				return;
			delete instance;
			instance = nullptr;
		}
	};

	template<typename T>
	T* Singleton<T>::instance = nullptr;
}