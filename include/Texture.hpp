#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

namespace GLitch
{
    class Texture
    {
    public:
        struct TextureData
        {
        public:
            int width;
            int height;
            int numberOfChannels;
            unsigned char* data;
        };

        enum class TextureType
        {
            Diffuse,
            Specular,
            Normal,
            Metallic,
            Roughness,
            AO,
            Emissive,
            Height,
            Glossiness,
            Opacity,
            Undefined
        };

        explicit Texture(const std::string& filePath);

        Texture();

        void load(const std::string& filePath);

        [[nodiscard]]const std::string& getName() const;

        [[nodiscard]]unsigned int getId() const;

        void bake();

        [[nodiscard]] bool isBaked() const;

        void bind(unsigned int slot = 0) const;

        ~Texture();
    private:
        bool m_isBaked;
        unsigned int m_id;
        TextureData m_textureData;
        std::string m_name;
    };
} //namespace GLitch

#endif //TEXTURE_HPP
