#version 130

in vec2 vertexPosition;
flat in uint vertexTID;
in vec2 vertexUV;
in vec4 vertexColor;

out vec2 fragmentPosition;
flat out uint fragmentTID;
out vec4 fragmentColor;
out vec2 fragmentUV;

uniform mat4 P;

void main() {
    //Set the x,y position on the screen
    gl_Position = (P * vec4(vertexPosition, 0.0, 1.0));
    
    fragmentPosition = vertexPosition;
    
    fragmentColor = vertexColor;
    
    fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
}
