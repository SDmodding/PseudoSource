// File Line: 21
// RVA: 0x1514350
__int64 dynamic_initializer_for__UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList__);
}

// File Line: 22
// RVA: 0x466420
UFG::ComponentIDDesc *__fastcall UFG::PhantomVolumeComponent::GetDesc(UFG::PhantomVolumeComponent *this)
{
  return &UFG::PhantomVolumeComponent::_TypeIDesc;
}

// File Line: 28
// RVA: 0x44A440
void __fastcall UFG::PhantomVolumeComponent::PhantomVolumeComponent(
        UFG::PhantomVolumeComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent>;
  this->mNext = &this->UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhantomVolumeComponent::`vftable;
  *(_WORD *)&this->mActiveProperties = 0;
  mPrev = UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev;
  UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)&UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList;
  UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mPrev = &this->UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID,
    "PhantomVolumeComponent");
  this->mVolumeProperties.array[0] = 0i64;
  this->mPhantomCallbackShapes.array[0] = 0i64;
  this->mVolumeProperties.array[1] = 0i64;
  this->mPhantomCallbackShapes.array[1] = 0i64;
  this->mVolumeProperties.array[2] = 0i64;
  this->mPhantomCallbackShapes.array[2] = 0i64;
  this->mVolumeProperties.array[3] = 0i64;
  this->mPhantomCallbackShapes.array[3] = 0i64;
  this->mVolumeProperties.array[4] = 0i64;
  this->mPhantomCallbackShapes.array[4] = 0i64;
}

// File Line: 40
// RVA: 0x4502D0
void __fastcall UFG::PhantomVolumeComponent::~PhantomVolumeComponent(UFG::PhantomVolumeComponent *this)
{
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v2; // rdx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *mPrev; // rcx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *mNext; // rax
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v5; // rcx
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhantomVolumeComponent::`vftable;
  if ( this == UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator )
    UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator = (UFG::PhantomVolumeComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent>;
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

// File Line: 45
// RVA: 0x46E8D0
void __fastcall UFG::PhantomVolumeComponent::OnEnterVolume(
        UFG::PhantomVolumeComponent *this,
        UFG::PhantomCallbackShape *phantom)
{
  unsigned __int8 mActiveVolumes; // al
  UFG::PhysicsVolumeProperties *mVolumeProperties; // r9
  unsigned __int8 i; // al
  UFG::PhysicsVolumeProperties *v5; // rdx

  mActiveVolumes = this->mActiveVolumes;
  if ( mActiveVolumes < 5u )
  {
    this->mPhantomCallbackShapes.array[mActiveVolumes] = phantom;
    ++this->mActiveVolumes;
    mVolumeProperties = phantom->mVolumeProperties;
    for ( i = 0; i < 5u; ++i )
    {
      v5 = this->mVolumeProperties.array[i];
      if ( v5 == mVolumeProperties )
        break;
      if ( !v5 )
      {
        this->mVolumeProperties.array[(unsigned __int8)this->mActiveProperties++] = mVolumeProperties;
        return;
      }
    }
  }
}

// File Line: 71
// RVA: 0x46ECD0
void __fastcall UFG::PhantomVolumeComponent::OnLeaveVolume(
        UFG::PhantomVolumeComponent *this,
        UFG::PhantomCallbackShape *phantom)
{
  unsigned __int8 v3; // cl
  unsigned __int8 mActiveVolumes; // r9
  unsigned __int8 v6; // r9
  unsigned __int8 v7; // r9
  unsigned __int8 v8; // dl
  unsigned __int8 mActiveProperties; // dl
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // dl

  v3 = 0;
  mActiveVolumes = this->mActiveVolumes;
  if ( mActiveVolumes )
  {
    while ( this->mPhantomCallbackShapes.array[v3] != phantom )
    {
      if ( ++v3 >= mActiveVolumes )
        goto LABEL_6;
    }
    v6 = mActiveVolumes - 1;
    this->mActiveVolumes = v6;
    this->mPhantomCallbackShapes.array[v3] = this->mPhantomCallbackShapes.array[v6];
    this->mPhantomCallbackShapes.array[(unsigned __int8)this->mActiveVolumes] = 0i64;
  }
LABEL_6:
  v7 = this->mActiveVolumes;
  v8 = 0;
  if ( v7 )
  {
    while ( this->mPhantomCallbackShapes.array[v8]->mVolumeProperties != phantom->mVolumeProperties )
    {
      if ( ++v8 >= v7 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    mActiveProperties = this->mActiveProperties;
    v10 = 0;
    if ( mActiveProperties )
    {
      while ( this->mVolumeProperties.array[v10] != phantom->mVolumeProperties )
      {
        if ( ++v10 >= mActiveProperties )
          return;
      }
      v11 = mActiveProperties - 1;
      this->mActiveProperties = v11;
      this->mVolumeProperties.array[v10] = this->mVolumeProperties.array[v11];
      this->mVolumeProperties.array[(unsigned __int8)this->mActiveProperties] = 0i64;
    }
  }
}

// File Line: 121
// RVA: 0x4799E0
void __fastcall UFG::PhantomVolumeComponent::Update(UFG::PhantomVolumeComponent *this, float deltaTime)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *i; // r10
  unsigned __int8 j; // cl
  UFG::PhysicsVolumeProperties *v9; // rdx
  float mDamagePerSecond; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RigidBodyComponent::_TypeUID);
    for ( i = ComponentOfTypeHK;
          i;
          i = UFG::SimObject::GetComponentOfType(
                i->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                i) )
    {
      for ( j = 0; j < 5u; ++j )
      {
        v9 = this->mVolumeProperties.array[j];
        if ( v9 )
        {
          mDamagePerSecond = v9->mDamagePerSecond;
          if ( mDamagePerSecond > 0.0 )
          {
            vfptr = i[6].vfptr;
            if ( vfptr )
            {
              v12 = mDamagePerSecond * deltaTime;
              if ( v12 > 0.0 )
              {
                if ( vfptr[19].__vecDelDtor )
                {
                  v13 = *((float *)&vfptr[33].__vecDelDtor + 1) - v12;
                  *((float *)&vfptr[33].__vecDelDtor + 1) = v13;
                  if ( v13 < 0.0 )
                    HIDWORD(vfptr[33].__vecDelDtor) = 0;
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 142
// RVA: 0x466FF0
UFG::PhysicsVolumeProperties *__fastcall UFG::PhantomVolumeComponent::GetProperties(
        UFG::PhantomVolumeComponent *this,
        unsigned __int8 index)
{
  if ( index >= 5u )
    return 0i64;
  else
    return this->mVolumeProperties.array[index];
}

