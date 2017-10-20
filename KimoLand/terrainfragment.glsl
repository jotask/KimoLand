#version 330 core

in vec3 _color;
in vec3 _surfaceNormal;
in vec3 _toLightVector;

uniform vec3 lightPos;
uniform vec3 lighColor;

out vec4 out_color;

void main()
{

    vec3 unitNormal = normalize( _surfaceNormal );
    vec3 unitLight = normalize( _toLightVector );

    float nDot1 = dot( unitNormal, unitLight );
    float brightness = max( nDot1, 1.0f );
    vec3 diffuse = brightness * lighColor;

    out_color = vec4( diffuse, 1.0f ) * vec4(_color, 1.0f);
    out_color = vec4(_color, 1.0f);

}