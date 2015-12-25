#include "FontManager.hpp"
using namespace sf;
using namespace std;

FontManager::~FontManager() {
	while (_fonts.size() > 0) {
		delete get<1>(_fonts.back());
		_fonts.pop_back();
	}
}
Font* FontManager::getFont(String name) {
	cout << "getFont(" << name.toAnsiString() << ") called." << endl;
	/*
	 * Check if font is already loaded:
	*/
	for (size_t i=0; i < _fonts.size(); ++i) {
		if (get<0>(_fonts[i]) == name) {
			cout << " -> Font #" << i << " is matching." << endl;
			return get<1>(_fonts[i]);
		};
	}
	cout << " -> Nothing found in " << _fonts.size() << " fonts, trying to load from file." << endl;
	/*
	 * Not loaded, try to load:
	*/
	Font* font = new Font();
	if (!font->loadFromFile(name)) {
		cout << " -> Failed loading from file." << endl;
		return NULL;
	};
	/*
	 * Loaded, add to vector:
	*/
	_fonts.push_back(make_tuple(name,font));
	/*
	 * Return pointer:
	*/
	return font;
}
