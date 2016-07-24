#version 130

in vec2 fragPos;
in vec4 fragCol;
in vec2 fragUV;

out vec4 color;

uniform float time;
uniform sampler2D sampler;

void main()
{
	vec4 textureColor = texture(sampler, fragUV);

	color = textureColor * fragCol;
/*

	color = vec4(fragCol.r * (cos(fragPos.x + time) + 1.0) * 0.5,
				fragCol.g * (cos(fragPos.y + time) + 1.0) * 0.5,
				fragCol.b * (cos(fragPos.x + time) + 1.0) * 0.5,
				fragCol.a);
*/
}
