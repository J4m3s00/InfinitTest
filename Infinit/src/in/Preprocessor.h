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
	} \
virtual void RenderStatic2D_(graphics::Renderer2D& renderer) override { \
	__super::RenderStatic2D_(renderer); \
	if (typeid(&className::OnRenderStatic2D) != typeid(&inheritance::OnRenderStatic2D)) \
		className::OnRenderStatic2D(renderer); \
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
	}  \
virtual void RenderStatic2D_(graphics::Renderer2D& renderer) {\
	className::OnRenderStatic2D(renderer); \
}