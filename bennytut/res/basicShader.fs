#version 120

uniform sampler2D diffuse;

void main () {
	gl_FragColor = texture2D (diffuse, vec2(0.8, 0.35));
}
