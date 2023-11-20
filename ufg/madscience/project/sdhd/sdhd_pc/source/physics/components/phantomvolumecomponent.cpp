// File Line: 21
// RVA: 0x1514350
__int64 dynamic_initializer_for__UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList__);
}

// File Line: 22
// RVA: 0x466420
UFG::ComponentIDDesc *__fastcall UFG::PhantomVolumeComponent::GetDesc(UFG::PhantomVolumeComponent *this)
{
  return &UFG::PhantomVolumeComponent::_TypeIDesc;
}

// File Line: 28
// RVA: 0x44A440
void __fastcall UFG::PhantomVolumeComponent::PhantomVolumeComponent(UFG::PhantomVolumeComponent *this, unsigned int name_uid)
{
  UFG::PhantomVolumeComponent *v2; // rbx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v3; // rdx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhantomVolumeComponent::`vftable';
  *(_WORD *)&v2->mActiveProperties = 0;
  v4 = UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev;
  UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList;
  UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID,
    "PhantomVolumeComponent");
  v2->mVolumeProperties.array[0] = 0i64;
  v2->mPhantomCallbackShapes.array[0] = 0i64;
  v2->mVolumeProperties.array[1] = 0i64;
  v2->mPhantomCallbackShapes.array[1] = 0i64;
  v2->mVolumeProperties.array[2] = 0i64;
  v2->mPhantomCallbackShapes.array[2] = 0i64;
  v2->mVolumeProperties.array[3] = 0i64;
  v2->mPhantomCallbackShapes.array[3] = 0i64;
  v2->mVolumeProperties.array[4] = 0i64;
  v2->mPhantomCallbackShapes.array[4] = 0i64;
}

// File Line: 40
// RVA: 0x4502D0
void __fastcall UFG::PhantomVolumeComponent::~PhantomVolumeComponent(UFG::PhantomVolumeComponent *this)
{
  UFG::PhantomVolumeComponent *v1; // r8
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v2; // rdx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v3; // rcx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v4; // rax
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v5; // rcx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhantomVolumeComponent::`vftable';
  if ( this == UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator )
    UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator = (UFG::PhantomVolumeComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&this->mPrev;
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

// File Line: 45
// RVA: 0x46E8D0
void __fastcall UFG::PhantomVolumeComponent::OnEnterVolume(UFG::PhantomVolumeComponent *this, UFG::PhantomCallbackShape *phantom)
{
  unsigned __int8 v2; // al
  UFG::PhysicsVolumeProperties *v3; // r9
  unsigned __int8 v4; // al
  UFG::PhysicsVolumeProperties *v5; // rdx

  v2 = this->mActiveVolumes;
  if ( v2 < 5u )
  {
    this->mPhantomCallbackShapes.array[v2] = phantom;
    ++this->mActiveVolumes;
    v3 = phantom->mVolumeProperties;
    v4 = 0;
    do
    {
      v5 = this->mVolumeProperties.array[v4];
      if ( v5 == v3 )
        break;
      if ( !v5 )
      {
        this->mVolumeProperties.array[(unsigned __int8)this->mActiveProperties++] = v3;
        return;
      }
      ++v4;
    }
    while ( v4 < 5u );
  }
}

// File Line: 71
// RVA: 0x46ECD0
void __fastcall UFG::PhantomVolumeComponent::OnLeaveVolume(UFG::PhantomVolumeComponent *this, UFG::PhantomCallbackShape *phantom)
{
  UFG::PhantomVolumeComponent *v2; // r8
  unsigned __int8 v3; // cl
  UFG::PhantomCallbackShape *v4; // r10
  unsigned __int8 v5; // r9
  unsigned __int8 v6; // r9
  unsigned __int8 v7; // r9
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // dl
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // dl

  v2 = this;
  v3 = 0;
  v4 = phantom;
  v5 = v2->mActiveVolumes;
  if ( v5 )
  {
    while ( v2->mPhantomCallbackShapes.array[v3] != phantom )
    {
      if ( ++v3 >= v5 )
        goto LABEL_6;
    }
    v6 = v5 - 1;
    v2->mActiveVolumes = v6;
    v2->mPhantomCallbackShapes.array[v3] = v2->mPhantomCallbackShapes.array[v6];
    v2->mPhantomCallbackShapes.array[(unsigned __int8)v2->mActiveVolumes] = 0i64;
  }
LABEL_6:
  v7 = v2->mActiveVolumes;
  v8 = 0;
  if ( v7 )
  {
    while ( v2->mPhantomCallbackShapes.array[v8]->mVolumeProperties != v4->mVolumeProperties )
    {
      if ( ++v8 >= v7 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v9 = v2->mActiveProperties;
    v10 = 0;
    if ( v9 )
    {
      while ( v2->mVolumeProperties.array[v10] != v4->mVolumeProperties )
      {
        if ( ++v10 >= v9 )
          return;
      }
      v11 = v9 - 1;
      v2->mActiveProperties = v11;
      v2->mVolumeProperties.array[v10] = v2->mVolumeProperties.array[v11];
      v2->mVolumeProperties.array[(unsigned __int8)v2->mActiveProperties] = 0i64;
    }
  }
}

// File Line: 121
// RVA: 0x4799E0
void __fastcall UFG::PhantomVolumeComponent::Update(UFG::PhantomVolumeComponent *this, float deltaTime)
{
  UFG::PhantomVolumeComponent *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  float v4; // xmm7_4
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *i; // r10
  unsigned __int8 v8; // cl
  UFG::PhysicsVolumeProperties *v9; // rdx
  float v10; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  v4 = deltaTime;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    for ( i = v6;
          i;
          i = (UFG::SimComponent *)UFG::SimObject::GetComponentOfType(
                                     i->m_pSimObject,
                                     UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                     0,
                                     i) )
    {
      v8 = 0;
      do
      {
        v9 = v2->mVolumeProperties.array[v8];
        if ( v9 )
        {
          v10 = v9->mDamagePerSecond;
          if ( v10 > 0.0 )
          {
            v11 = i[6].vfptr;
            if ( v11 )
            {
              v12 = v10 * v4;
              if ( v12 > 0.0 )
              {
                if ( v11[19].__vecDelDtor )
                {
                  v13 = *((float *)&v11[33].__vecDelDtor + 1) - v12;
                  *((float *)&v11[33].__vecDelDtor + 1) = v13;
                  if ( v13 < 0.0 )
                    HIDWORD(v11[33].__vecDelDtor) = 0;
                }
              }
            }
          }
        }
        ++v8;
      }
      while ( v8 < 5u );
    }
  }
}

// File Line: 142
// RVA: 0x466FF0
UFG::PhysicsVolumeProperties *__fastcall UFG::PhantomVolumeComponent::GetProperties(UFG::PhantomVolumeComponent *this, char index)
{
  UFG::PhysicsVolumeProperties *result; // rax

  if ( (unsigned __int8)index >= 5u )
    result = 0i64;
  else
    result = this->mVolumeProperties.array[(unsigned __int8)index];
  return result;
}

