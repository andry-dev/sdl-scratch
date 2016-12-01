#version 400 core

in vec2 vertexPosition;
in float vertexTID;
in vec2 vertexUV;
in vec4 vertexColor;

out vec2 fragmentPosition;
out float fragmentTID;
out vec4 fragmentColor;
out vec2 fragmentUV;

uniform mat4 P;

void main() {
    //Set the x,y position on the screen
    gl_Position = (P * vec4(vertexPosition, 0.0, 1.0));
    
    fragmentPosition = vertexPosition;
    
    fragmentColor = vertexColor;
    
    fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);

	fragmentTID = vertexTID;
}
