#version 130

in vec2 vertexPos;
in vec4 vertexCol;
in vec2 vertexUV;

out vec2 fragPos;
out vec4 fragCol;
out vec2 fragUV;

void main()
{
	gl_Position.xy = vertexPos;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;

	fragCol = vertexCol;
}
