R"(#shader vertex

#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in float tid;
layout(location = 3) in vec4 color;

out DATA
{
	vec4 color;
	vec2 uv;
	float tid;
} vs_out;

uniform mat4 pr_matrix;

void main()
{
	vs_out.uv = uv;
	vs_out.tid = tid;
	vs_out.color = color;
	gl_Position = pr_matrix * vec4(position, 1.0);
}

#shader fragment

#version 330 core

uniform sampler2D textures[16];

in DATA
{
	vec4 color;
	vec2 uv;
	float tid;
} fs_in;

void main()
{
	vec4 texColor = fs_in.color;
	if (fs_in.tid > 0.0)
	{
		int id = int(fs_in.tid + 0.5) - 1;
		texColor = texture(textures[id], fs_in.uv) * fs_in.color;
	}
	gl_FragColor = texColor;
}
)"