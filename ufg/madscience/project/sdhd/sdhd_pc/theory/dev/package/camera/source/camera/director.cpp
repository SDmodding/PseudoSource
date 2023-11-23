// File Line: 17
// RVA: 0x1459290
__int64 dynamic_initializer_for__UFG::Director::s_DirectorList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Director::s_DirectorList__);
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
  UFG::qNode<UFG::Director,UFG::Director> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, nameUID);
  this->mPrev = &this->UFG::qNode<UFG::Director,UFG::Director>;
  this->mNext = &this->UFG::qNode<UFG::Director,UFG::Director>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Director::`vftable;
  this->mCurrentCamera = 0i64;
  mPrev = UFG::Director::s_DirectorList.mNode.mPrev;
  UFG::Director::s_DirectorList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::Director,UFG::Director>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::Director,UFG::Director> *)&UFG::Director::s_DirectorList;
  UFG::Director::s_DirectorList.mNode.mPrev = &this->UFG::qNode<UFG::Director,UFG::Director>;
  UFG::SimComponent::AddType(this, UFG::Director::_DirectorTypeUID, "Director");
  UFG::gpDirector = this;
}

// File Line: 36
// RVA: 0xB9740
void __fastcall UFG::Director::~Director(UFG::Director *this)
{
  UFG::qNode<UFG::Director,UFG::Director> *v2; // rdx
  UFG::qNode<UFG::Director,UFG::Director> *mPrev; // rcx
  UFG::qNode<UFG::Director,UFG::Director> *mNext; // rax
  UFG::qNode<UFG::Director,UFG::Director> *v5; // rcx
  UFG::qNode<UFG::Director,UFG::Director> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Director::`vftable;
  UFG::gpDirector = 0i64;
  if ( this == UFG::Director::s_DirectorpCurrentIterator )
    UFG::Director::s_DirectorpCurrentIterator = (UFG::Director *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::Director,UFG::Director>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 43
// RVA: 0xB9F00
UFG::Director *__fastcall UFG::Director::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "Director::PropertiesOnActivate", 0i64, 1u);
  if ( v3 )
  {
    UFG::Director::Director((UFG::Director *)v3, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::Director *)v5;
}

// File Line: 54
// RVA: 0xBA270
void __fastcall UFG::Director::SetCurrentCamera(UFG::Director *this, UFG::BaseCameraComponent *newCam)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::BaseCameraComponent *v4; // rbx
  __int64 v5; // rdx

  mCurrentCamera = this->mCurrentCamera;
  v4 = newCam;
  if ( newCam != mCurrentCamera )
  {
    if ( mCurrentCamera )
    {
      mCurrentCamera->vfptr[20].__vecDelDtor(mCurrentCamera, 0);
      this->mCurrentCamera->vfptr[22].__vecDelDtor(this->mCurrentCamera, 0);
    }
    if ( v4 )
    {
      LOBYTE(newCam) = 1;
      v4->vfptr[20].__vecDelDtor(v4, (unsigned int)newCam);
      LOBYTE(v5) = 1;
      v4->vfptr[22].__vecDelDtor(v4, v5);
    }
    this->mCurrentCamera = v4;
  }
}

// File Line: 77
// RVA: 0xB9A40
UFG::Director *__fastcall UFG::Director::Get()
{
  return UFG::gpDirector;
}

