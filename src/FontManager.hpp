#ifndef _FONT_MANAGER_HPP_
#define _FONT_MANAGER_HPP_
#include <iostream>
#include <vector>
#include <tuple>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Singleton.hpp"
using namespace sf;

class FontManager : public Singleton <FontManager> {
	friend class Singleton <FontManager>;
	public:
		~FontManager();
		Font* getFont(String name);
	protected:
		FontManager();
	private:
		std::vector<std::tuple<String,Font*>> _fonts;
};
#endif
