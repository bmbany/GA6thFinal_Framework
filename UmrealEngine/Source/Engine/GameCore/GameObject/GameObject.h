﻿#pragma once
class Component;

template<typename T>
concept IS_BASE_COMPONENT_C = std::is_base_of_v<Component, T>;

//참고
//Unity GameObject https://docs.unity3d.com/kr/2021.1/Manual/class-GameObject.html
//Unity GameObject Script https://docs.unity3d.com/6000.0/Documentation/ScriptReference/GameObject.html

//함수는 일단 선언만. 구현은 나중에. 
class GameObject 
{
    friend class ComponentFactory;

    //public static 함수
public:
    /// <summary>
    /// <para> 구현 X </para>
    /// <para> 매개변수와 같은 이름을 가진 GameObject를 찾아 반환합니다. </para>
    /// <para> 같은 이름의 GameObject가 없으면 nullptr를 반환합니다.    </para>
    /// <para> 참고 : 같은 이름의 오브젝트가 여러개 있으면 특정 오브젝트 반환을 보장하지 못합니다.  </para>
    /// </summary>
    /// <param name="name :">검색할 오브젝트의 이름</param>
    /// <returns>찾은 오브젝트를 weak_ptr에 담아준다.</returns>
    static std::weak_ptr<GameObject> Find(std::wstring_view name) { return std::weak_ptr<GameObject>(); }

    /// <summary>
    /// <para> 구현 X                                                      </para>
    /// <para> 매개변수와 같은 태그가 설정된 GameObject들의 배열을 반환합니다. </para>
    /// <para> 태그가 있는 GameObject가 없으면 빈 배열을 반환합니다.          </para>
    /// </summary>
    /// <param name="tag :">검색할 태그</param>
    /// <returns>찾은 오브젝트들을 담은 weak_ptr배열</returns>
    static std::vector<std::weak_ptr<GameObject>> FindGameObjectsWithTag(std::wstring_view tag) { return std::vector<std::weak_ptr<GameObject>>(); }

    /// <summary>
    /// <para> 구현 X                                                                               </para>
    /// <para> 매개변수와 같은 태그가 설정된 GameObject를 찾아 반환합니다.                             </para>
    /// <para> 참고 : 같은 태그가 설정된 오브젝트가 여러개 있으면 특정 오브젝트 반환을 보장하지 못합니다. </para>
    /// </summary>
    /// <param name="tag :">검색할 태그</param>
    /// <returns>찾은 오브젝트를 weak_ptr에 담아준다.</returns>
    static std::weak_ptr<GameObject> FindWithTag(std::wstring_view tag) { return std::weak_ptr<GameObject>(); }

    /// <summary>
    /// <para> 구현 X                                                            </para>
    /// <para> 전달받은 인스턴스 ID를 가진 GameObject가 속해있는 Scene을 반환합니다. </para>
    /// </summary>
    /// <param name="instanceID :">대상 인스턴스 아이디</param>
    /// <returns>Scene 정보</returns>
    static Scene& GetScene(int instanceID) 
    { 
        static Scene empty;
        return empty;
    }

    /// <summary>
    /// <para>구현 X                                  </para>
    /// <para>전달받은 오브젝트 or 컴포넌트를 파괴합니다. </para>
    /// </summary>
    /// <param name="Object :">파괴할 오브젝트</param>
    /// <param name="t :">딜레이 시간</param>
    static void Destroy(Component& component, float t = 0.f);
    /// <summary>
    /// <para>구현 X                                  </para>
    /// <para>전달받은 오브젝트 or 컴포넌트를 파괴합니다. </para>
    /// </summary>
    /// <param name="Object :">파괴할 오브젝트</param>
    /// <param name="t :">딜레이 시간</param>
    static void Destroy(Component* component, float t = 0.f)
    {
        Destroy(*component, t);
    }
    /// <summary>
    /// <para>구현 X                                  </para>
    /// <para>전달받은 오브젝트 or 컴포넌트를 파괴합니다. </para>
    /// </summary>
    /// <param name="Object :">파괴할 오브젝트</param>
    /// <param name="t :">딜레이 시간</param>
    static void Destroy(GameObject& gameObject, float t = 0.f);
    /// <summary>
    /// <para>구현 X                                  </para>
    /// <para>전달받은 오브젝트 or 컴포넌트를 파괴합니다. </para>
    /// </summary>
    /// <param name="Object :">파괴할 오브젝트</param>
    /// <param name="t :">딜레이 시간</param>
    static void Destroy(GameObject* gameObject, float t = 0.f)
    {
        Destroy(*gameObject, t);
    }

    /// <summary>
    /// <para>구현 X                                                         </para>
    /// <para>전달받은 오브젝트가 다른 Scene을 로드 할 때 파괴되지 않도록 합니다.</para>
    /// </summary>
    /// <param name="Object :">대상 오브젝트</param>
    static void DontDestroyOnLoad(GameObject& gameObject);
    /// <summary>
    /// <para>구현 X                                                         </para>
    /// <para>전달받은 오브젝트가 다른 Scene을 로드 할 때 파괴하지 않도록 합니다.</para>
    /// </summary>
    /// <param name="Object :">대상 오브젝트</param>
    static void DontDestroyOnLoad(GameObject* gameObject)
    {
        DontDestroyOnLoad(*gameObject);
    }

    /// <summary>
    /// <para> 구현 X                                      </para>
    /// <para> 대상 오브젝트의 복사본을 현재 씬에 생성합니다.  </para>
    /// </summary>
    /// <param name="gameObject :">복사할 오브젝트</param>
    static void Instantiate(GameObject& original);
    /// <summary>
    /// <para> 구현 X                                      </para>
    /// <para> 대상 오브젝트의 복사본을 현재 씬에 생성합니다.  </para>
    /// </summary>
    /// <param name="gameObject :">복사할 오브젝트</param>
    static void Instantiate(GameObject* original)
    {
        Instantiate(*original);
    }
   
public:
    GameObject();
    ~GameObject();

public:
    /// <summary>
    /// <para>구현 X                                                                  </para>
    /// <para>이 GameObject의 InstanceID를 반환합니다.                                 </para>
    /// <para>참고 : InstanceID는 매 런타임마다 달라집니다. 즉 UUID로 사용할 수 없습니다. </para>
    /// </summary>
    /// <returns>int InstanceID</returns>
    int GetInstanceID() { return -1; }

    /// <summary>
    /// <para> 구현 X                            </para>
    /// <para> 이 GameObject의 이름을 반환합니다. </para>
    /// </summary>
    /// <returns>std::wstring_view 오브젝트의 이름</returns>
    std::wstring_view ToWString() { return L""; }

    /// <summary>
    /// 컴포넌트를 추가합니다.
    /// </summary>
    /// <typeparam name="TComponent :">추가할 컴포넌트 타입</typeparam>
    template<IS_BASE_COMPONENT_C TComponent>
    inline TComponent& AddComponent();

    /// <summary>
    /// <para> TComponent 타입의 컴포넌트를 찾아서 반환합니다. </para>
    /// <para> 실패시 empty를 반환합니다.                     </para>
    /// </summary>
    /// <typeparam name="TComponent :">검색할 컴포넌트 타입</typeparam>
    /// <returns>해당 타입 컴포넌트의 weak_ptr</returns>
    template<IS_BASE_COMPONENT_C TComponent>
    inline std::weak_ptr<TComponent> GetComponent();

    /// <summary>
    /// 전달받은 인덱스의 컴포넌트를 TComponent 타입으로 dynamic_cast를 시도해 반환합니다.
    /// </summary>
    /// <typeparam name="TComponent :">캐스팅할 컴포넌트 타입</typeparam>
    /// <param name="index :">컴포넌트 인덱스</param>
    /// <returns>해당 타입 컴포넌트의 weak_ptr</returns>
    template<IS_BASE_COMPONENT_C TComponent>
    inline std::weak_ptr<TComponent> GetComponentAtIndex(size_t index);

    inline size_t GetComponentCount() { return m_components.size(); }
//프로퍼티
public:
    USING_PROPERTY(GameObject)

    GETTER_ONLY(bool, activeInHierarchy)
    {
        return false;
    }
    // 미구현
    // get : 실제 활성화 여부 (부모가 false면 false)
    PROPERTY(activeInHierarchy);
    //실제 활성화 여부 (부모가 false면 false)
    
    GETTER_ONLY(bool, activeSelf)
    {
        return false;
    }
    //미구현
    // get : 자신의 local active 여부 (실제 활성화 여부)
    PROPERTY(activeSelf);
   
    GETTER(bool, isStatic)
    {
        return false;
    }
    SETTER(bool, isStatic)
    {
        return;
    }
    //미구현
    // get, set :
    //  게임 오브젝트에 대해 isStatic 플래그가 설정되어 있는지 여부.
    PROPERTY(isStatic);
    

    GETTER(std::wstring_view, name)
    {
        return this->ToWString();
    }
    SETTER(std::wstring_view, name)
    {

    }
    //미구현
    // get, set:
    //  게임 오브젝트의 이름
    PROPERTY(name)

    GETTER(float, testFloat)
    {
        return aaaa;
    }
    SETTER(float, testFloat)
    {
        aaaa = value;

    }
    PROPERTY(testFloat);

    struct MyStrusct
    {
        float x = 3.f;
        float y = 4.f;
    };
    GETTER(MyStrusct, TestStruct)
    {
        return myStruct;
    }
    SETTER(MyStrusct, TestStruct)
    {
        myStruct = value;
    }
    PROPERTY(TestStruct);

private:
    std::vector<std::shared_ptr<Component>>  m_components;
    float aaaa;
    MyStrusct myStruct;

public:
    //activeInHierarchy와 같음.
    operator bool() { return activeInHierarchy; }
    bool operator != (const GameObject& rhs)
    {
        return this != &rhs;
    }
    bool operator == (const GameObject& rhs)
    {
        return this == &rhs;
    }
};

#include "Engine/EngineCore/EngineCores.h"
template<IS_BASE_COMPONENT_C TComponent >
inline TComponent& GameObject::AddComponent()
{
#ifndef SCRIPTS_PROJECT
    ComponentFactory& factory = componentFactory;
#else
    ComponentFactory& factory = UmrealEngine->componentFactory;
#endif
    bool result = factory.AddComponentToObject(this, typeid(TComponent).name());
    if (result)
    {
        return *(this->m_components.back());
    }
    else
    {
        //존재하지 않는 컴포넌트.
        __debugbreak();
    } 
}

template<IS_BASE_COMPONENT_C TComponent>
inline std::weak_ptr<TComponent> GameObject::GetComponent()
{
    std::weak_ptr<TComponent> result;
    for (auto& component : m_components)
    {
        if (typeid(TComponent) == typeid(*component))
        {
            result = component;
            break;
        }
    }
    return result;
}

template<IS_BASE_COMPONENT_C TComponent>
inline std::weak_ptr<TComponent> GameObject::GetComponentAtIndex(size_t index)
{
    std::weak_ptr<TComponent> result;
    if (index >= m_components.size())
    {
        return result;
    }
    else
    {
        result = std::dynamic_pointer_cast<TComponent>(m_components[index]);
        return result;
    }
}