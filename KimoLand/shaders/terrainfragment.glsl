#version 330 core

/*
struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float brightness;
};

struct Light{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
*/

in vec3 _color;
in vec3 _surfaceNormal;
in vec3 _toLightVector;

uniform vec3 lightPos;
uniform vec3 lightColor;

// uniform Material material;
// uniform Light light;

out vec4 out_color;

void main()
{

    vec3 unitNormal = normalize( _surfaceNormal );
    vec3 unitLight = normalize( _toLightVector );

    float nDot1 = dot( unitNormal, unitLight );
    float brightness = max( nDot1, 0.0f );
    vec3 diffuse = brightness * lightColor;

    out_color = vec4( diffuse, 1.0f ) * vec4(_color, 1.0f);
    //out_color = gl_FragCoord.z;

}