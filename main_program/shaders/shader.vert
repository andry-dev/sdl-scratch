#version 130

in vec2 vertexPos;
in vec4 vertexCol;

out vec4 fragCol;

void main()
{
	gl_Position.xy = vertexPos;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;

	fragCol = vertexCol;
}
