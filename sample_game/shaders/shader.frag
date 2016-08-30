#version 330

in vec2 fragmentPosition;
in float fragmentTID;
in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D mySampler[32];

void main() {
    vec4 textureColor = texture(mySampler[int(fragmentTID - 0.5)], fragmentUV);
	color = fragmentColor * textureColor;
}
