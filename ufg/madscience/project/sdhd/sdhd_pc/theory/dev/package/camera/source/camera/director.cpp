// File Line: 17
// RVA: 0x1459290
__int64 dynamic_initializer_for__UFG::Director::s_DirectorList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Director::s_DirectorList__);
}

// File Line: 18
// RVA: 0xB9A70
UFG::ComponentIDDesc *__fastcall UFG::Director::GetDesc(UFG::Director *this)
{
  return &UFG::Director::_TypeIDesc;
}

// File Line: 24
// RVA: 0xB95B0
void __fastcall UFG::Director::Director(UFG::Director *this, unsigned int nameUID)
{
  UFG::Director *v2; // rbx
  UFG::qNode<UFG::Director,UFG::Director> *v3; // rdx
  UFG::qNode<UFG::Director,UFG::Director> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUID);
  v3 = (UFG::qNode<UFG::Director,UFG::Director> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Director::`vftable;
  v2->mCurrentCamera = 0i64;
  v4 = UFG::Director::s_DirectorList.mNode.mPrev;
  UFG::Director::s_DirectorList.mNode.mPrev->mNext = (UFG::qNode<UFG::Director,UFG::Director> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::Director,UFG::Director> *)&UFG::Director::s_DirectorList;
  UFG::Director::s_DirectorList.mNode.mPrev = (UFG::qNode<UFG::Director,UFG::Director> *)&v2->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v2->vfptr, UFG::Director::_DirectorTypeUID, "Director");
  UFG::gpDirector = v2;
}

// File Line: 36
// RVA: 0xB9740
void __fastcall UFG::Director::~Director(UFG::Director *this)
{
  UFG::Director *v1; // r8
  UFG::qNode<UFG::Director,UFG::Director> *v2; // rdx
  UFG::qNode<UFG::Director,UFG::Director> *v3; // rcx
  UFG::qNode<UFG::Director,UFG::Director> *v4; // rax
  UFG::qNode<UFG::Director,UFG::Director> *v5; // rcx
  UFG::qNode<UFG::Director,UFG::Director> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Director::`vftable;
  UFG::gpDirector = 0i64;
  if ( this == UFG::Director::s_DirectorpCurrentIterator )
    UFG::Director::s_DirectorpCurrentIterator = (UFG::Director *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::Director,UFG::Director> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 43
// RVA: 0xB9F00
UFG::SimComponent *__fastcall UFG::Director::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x58ui64, "Director::PropertiesOnActivate", 0i64, 1u);
  if ( v3 )
  {
    UFG::Director::Director((UFG::Director *)v3, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 54
// RVA: 0xBA270
void __fastcall UFG::Director::SetCurrentCamera(UFG::Director *this, UFG::BaseCameraComponent *newCam)
{
  UFG::Director *v2; // rdi
  UFG::BaseCameraComponent *v3; // rcx
  UFG::BaseCameraComponent *v4; // rbx
  __int64 v5; // rdx

  v2 = this;
  v3 = this->mCurrentCamera;
  v4 = newCam;
  if ( newCam != v3 )
  {
    if ( v3 )
    {
      v3->vfptr[20].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, 0);
      v2->mCurrentCamera->vfptr[22].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)v2->mCurrentCamera, 0);
    }
    if ( v4 )
    {
      LOBYTE(newCam) = 1;
      v4->vfptr[20].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)newCam);
      LOBYTE(v5) = 1;
      v4->vfptr[22].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, v5);
    }
    v2->mCurrentCamera = v4;
  }
}

// File Line: 77
// RVA: 0xB9A40
UFG::Director *__fastcall UFG::Director::Get()
{
  return UFG::gpDirector;
}

