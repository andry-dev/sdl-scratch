#version 400

layout(location = 0) in vec2 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in float vertexTID;
layout(location = 3) in vec4 vertexColor;

out vec2 fragmentPosition;
out float fragmentTID;
out vec4 fragmentColor;
out vec2 fragmentUV;

uniform mat4 ml_matrix;
uniform mat4 vw_matrix;
uniform mat4 pr_matrix;

void main() {
    //Set the x,y position on the screen
    gl_Position = (pr_matrix * vw_matrix * ml_matrix * vec4(vertexPosition, 0.0, 1.0));

    fragmentPosition = vertexPosition;

    fragmentColor = vertexColor;

    fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
    fragmentTID = vertexTID;
}





