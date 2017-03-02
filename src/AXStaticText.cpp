#include "headers/stb_truetype.hpp"
#include "headers/AXStaticText.hpp"

AXStaticText::AXStaticText(const std::string& text, AXFont* font) : text(text){
	setFont(font);
}

AXStaticText::AXStaticText(const std::string& text, int fontID) : text(text){
	setFont(fontID);
}

bool AXStaticText::bakeText(){
	//bake the string
	if(this->font){
		if(this->font->isLoaded()){
			if(this->isBaked && this->texture){
				SDL_DestroyTexture(this->texture);
			}
			SDL_Surface* temp = TTF_RenderUTF8_Blended(this->font->getFontData(), text.c_str(), this->colour);
			if(!temp){
				std::cout << "Font failed to bake! SDL Error: " << TTF_GetError() << std::endl;
				return false;
			}
			if(TTF_SizeText(this->font->getFontData(), text.c_str(), &this->width, &this->height) == -1){
				if(owner){
					//resize the entity to this text
					owner->resizeEntity(width, height);
				}
				std::cout << "Font failed to bake! SDL Error: " << TTF_GetError() << std::endl;
				return false;
			}
			this->texture = SDL_CreateTextureFromSurface(AXWindow::renderer, temp);
			if(!texture){
				std::cout << "Font failed to bake! SDL Error: " << SDL_GetError() << std::endl;
				return false;
			}
			SDL_FreeSurface(temp);
			return true;
		}
	}
	std::cout << "The font isn't loaded, this can't be baked." << std::endl;
	return false;
}

void AXStaticText::setText(const std::string& text){
	this->text = text;
	isBaked = bakeText();
}

void AXStaticText::setFont(AXFont* font){
	this->font = font;
}

void AXStaticText::setFont(int id){
	this->font = resourceManager->getFont(id);
}

void AXStaticText::draw(float x, float y){
	if(texture && isBaked){
		SDL_Rect dest = {.x = (int)x, .y = (int)y, .w = this->width, .h = this->height};
		SDL_RenderCopy(AXWindow::renderer, texture, NULL, &dest);
	}
}

AXText* AXStaticText::clone(){
	AXText* a = new AXStaticText(this->text, this->font);
	a->setOwner(this->owner);
	a->bakeText();
	return a;
}