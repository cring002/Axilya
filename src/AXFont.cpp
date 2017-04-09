#include "headers/AXFont.hpp"
#include "headers/AXWindow.hpp"
AXFont::AXFont(int id, const std::string& p, int size) : AXResource(id){
	loadFont(p, size);
}

AXFont::AXFont(const std::string& p, int size) : AXResource(-1){
	loadFont(p, size);
}

AXFont::~AXFont(){
	TTF_CloseFont(fontData);
}

bool AXFont::loadFont(const std::string& p, int size){
	if(loaded){
		//freeup the surface
		TTF_CloseFont(fontData);
	}
	std::string path = AXWindow::runPath+"data/" + p;

	fontData = TTF_OpenFont(path.c_str(), size);
	if(!fontData){
		AXLog::log("Font failed load.", TTF_GetError(), AX_LOG_ERROR);
		return false;
	}
	fontHeight = TTF_FontHeight(fontData);
	setPath(path);
	loaded = true;
	return true;
}

SDL_Texture* AXFont::bakeTexture(const std::string string, AXColour& colour){
	if(loaded){
		SDL_Surface* temp = TTF_RenderUTF8_Blended(fontData, string.c_str(), colour.toSDL());
		if(!temp){
			AXLog::log("Font failed to bake!", TTF_GetError(), AX_LOG_ERROR);
			return 0;
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(AXWindow::renderer, temp);
		if(!texture){
			AXLog::log("Font failed to bake!", TTF_GetError(), AX_LOG_ERROR);
			return 0;
		}
		SDL_FreeSurface(temp);
		return texture;
	}
	AXLog::log("Font failed to bake!", "Font file not loaded.", AX_LOG_ERROR);
	return 0;
}

AXVector2D AXFont::getStringSize(const std::string string){
	AXVector2D size;
	if(loaded){
		int width, height;
		TTF_SizeText(fontData, string.c_str(), &width, &height);
		size.x = width;
		size.y = height;
	}
	return size;
}

TTF_Font* AXFont::getFontData(){
	return fontData;
}
