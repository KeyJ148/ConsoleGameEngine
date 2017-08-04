#include "texture.h"

Texture::Texture() {
    texture_h = 1;
    texture_w = 1;

    texture = new char*[texture_h];
    texture[0] = new char[texture_w];
    texture[0][0] = ' ';

}

Texture::Texture(char** texture, int texture_w, int texture_h) {
    this->texture = new char*[texture_h];
    for (int i=0; i<texture_h; i++){
        this->texture[i] = new char[texture_w];
        for (int j=0; j<texture_w; j++){
            this->texture[i][j] = texture[i][j];
        }
    }

    this->texture_h = texture_h;
    this->texture_w = texture_w;
}

Texture::Texture(const Texture& copy) {
    this->texture = copy.texture;
}

Texture::~Texture() {
    for (int i=0; i<texture_h; i++){
        delete texture[i];
    }

    delete texture;
}

Texture* Texture::copy() {
    return new Texture(*this);
}

inline void Texture::update(long delta) {}

string Texture::getType() {
    return "texture";
}