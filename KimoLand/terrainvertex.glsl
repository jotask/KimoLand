#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec3 norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform vec3 lighColor;

out vec3 _color;
out vec3 _surfaceNormal;
out vec3 _toLightVector;

void main()
{
    
    vec4 worldPosition = model * vec4( pos, 1.0f );

    _color = col;
    _surfaceNormal = (worldPosition * vec4( norm, 0.0f )).xyz;
    _toLightVector = lightPos - worldPosition.xyz ;

    gl_Position = projection * view * worldPosition;

}