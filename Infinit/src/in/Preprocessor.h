#pragma once

#define INCLASS(className, inheritance)						\
private:													\
	INString m_ClassName = #className;						\
public:														\
	const INString& GetClassName() const { return m_ClassName; } \
public:	\
virtual void Render_() override {	\
	inheritance::Render_(); \
	if (typeid(&className::OnRender) != typeid(&inheritance::OnRender)) \
		className::OnRender(); \
	} \
virtual void Start_() override {	\
	__super::Start_(); \
	if (typeid(&className::OnStart) != typeid(&inheritance::OnStart)) \
	className::OnStart(); \
	} \
virtual void Update_() override {	\
	__super::Update_(); \
	if (typeid(&className::OnUpdate) != typeid(&inheritance::OnUpdate)) \
		className::OnUpdate(); \
	}

#define INCLASS_(className)						\
private:													\
	INString m_ClassName = #className;						\
public:														\
	const INString& GetClassName() const { return m_ClassName; } \
public:	\
virtual void Start_() {	\
	className::OnStart(); \
	} \
virtual void Render_() {	\
	className::OnRender(); \
	} \
virtual void Update_() {	\
	className::OnUpdate(); \
	} 