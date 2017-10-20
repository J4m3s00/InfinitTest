#pragma once

#define INCLASS(className, inheritance)						\
private:													\
	INString m_ClassName = #className;						\
public:														\
	const INString& GetClassName() const { return m_ClassName; } \
private:	\
void Render_() {	\
	inheritance::Render(); \
	OnRender(); \
	} \
void Start_() {	\
	inheritance::Start(); \
	OnStart(); \
	} \
void Update_() {	\
	inheritance::Update(); \
	OnUpdate(); \
	} 

#define INCLASS_(className)						\
private:													\
	INString m_ClassName = #className;						\
public:														\
	const INString& GetClassName() const { return m_ClassName; } \
private:	\
void Start_() {	\
	OnStart(); \
	} \
void Render_() {	\
	OnRender(); \
	} \
void Update_() {	\
	OnUpdate(); \
	} 