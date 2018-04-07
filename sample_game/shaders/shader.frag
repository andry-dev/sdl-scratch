#version 400

in vec2 fragmentPosition;
in vec2 fragmentUV;
in float fragmentTID;
in vec4 fragmentColor;

out vec4 color;

uniform sampler2D textures[16];

void main() {
    int tid = int(fragmentTID - 0.5);
    vec4 textureColor = texture(textures[tid], fragmentUV);
    color = fragmentColor * textureColor;
}
