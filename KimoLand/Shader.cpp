#include "Shader.h"

namespace Aiko {
	Shader::Shader()
		: Shader("basicvertex.glsl", "basicfragment.glsl")
	{
	}

	Shader::Shader(const std::string vertex_file, const std::string fragment_file)
	{
		// 1. retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// open files
			vShaderFile.open(vertex_file);
			fShaderFile.open(fragment_file);
			std::stringstream vShaderStream, fShaderStream;
			// read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		// 2. compile shaders
		unsigned int vertex, fragment;
		int success;
		char infoLog[512];

		// vertex Shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		// print compile errors if any
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};

		// fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		// print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		};

		// shader Program
		program = glCreateProgram();
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		this->bindAttribute(0, "pos");
		this->bindAttribute(1, "col");
		this->bindAttribute(2, "nor");

		glLinkProgram(program);

		// print linking errors if any
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		// delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}


	Shader::~Shader()
	{
		this->end();
		glDeleteProgram( this->program );
	}

	void Shader::start()
	{
		glUseProgram( this->program	);
	}


	void Shader::end()
	{
		glUseProgram( 0 );
	}

	void Shader::prepare()
	{
		glEnable(GL_DEPTH_TEST);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (WIREFRAME)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	void Shader::setCamera(Aiko::Camera& cam)
	{
		setMat4( "view", cam.getView() );
		setMat4( "projection", cam.getProjection());
	}

	void Shader::setObject(Aiko::Object & obj)
	{
		setMat4("model", obj.getTranform().getModel() );
	}

	void Shader::setMat4(const std::string name, const glm::mat4 mat)
	{
		glUniformMatrix4fv( getLocation( name ), 1, GL_FALSE, &mat[0][0] );
	}

	void Shader::setVec3(const std::string name, const glm::vec3 vec)
	{
		glUniform3fv( getLocation( name ), 1, &vec[0] );
	}

	void Shader::bindAttribute(int attribute, std::string variablename)
	{
		glBindAttribLocation( this->program, attribute, variablename.c_str() );
	}

	GLuint Shader::getLocation(const std::string name)
	{
		return glGetUniformLocation( this->program, name.c_str() );
	}

	void Shader::setLight(Light & light)
	{
		this->setVec3("lightPos", light.transform.position);
		this->setVec3("lighColor", light.color);
	}

}