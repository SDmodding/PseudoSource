// File Line: 14
// RVA: 0x1514370
__int64 dynamic_initializer_for__UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList__);
}

// File Line: 15
// RVA: 0x4680A0
const char *__fastcall UFG::PhysicsRenderHelper::GetTypeName(UFG::PhysicsRenderHelper *this)
{
  return "PhysicsRenderHelper";
}

// File Line: 24
// RVA: 0x44ABC0
void __fastcall UFG::PhysicsRenderHelper::PhysicsRenderHelper(
        UFG::PhysicsRenderHelper *this,
        UFG::CollisionInstanceData *instanceData,
        UFG::CollisionMeshData *mesh)
{
  UFG::DynamicSceneryInstance *v6; // rdi
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *mPrev; // rax
  unsigned int mNumParts; // eax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // kr00_8
  unsigned __int16 mNumSceneryInstances; // ax
  unsigned int m_NameUID; // esi
  unsigned int mRenderModelGuid; // ebp
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::DynamicSceneryInstance *v16; // rax
  unsigned __int16 v17; // si
  __int64 mOffset; // rax
  char *v19; // rcx
  char *v20; // rbp
  unsigned int mInstanceUid; // r12d
  UFG::qMemoryPool *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::DynamicSceneryInstance *v24; // rax
  UFG::DynamicSceneryInstance *v25; // rcx

  UFG::SimComponent::SimComponent(this, mesh->mName.mUID);
  this->mPrev = &this->UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper>;
  this->mNext = &this->UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsRenderHelper::`vftable;
  v6 = 0i64;
  this->mNumSceneryInstances = 0;
  this->mSceneryInstances = 0i64;
  this->mFlags = 0;
  mPrev = UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev;
  UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList;
  UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev = &this->UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper>;
  UFG::SimComponent::AddType(this, UFG::PhysicsRenderHelper::_PhysicsRenderHelperTypeUID, "PhysicsRenderHelper");
  LOWORD(mNumParts) = 1;
  if ( mesh->mGeometryType )
    mNumParts = mesh->mNumParts;
  this->mNumSceneryInstances = mNumParts;
  v10 = (unsigned __int16)mNumParts;
  v9 = 8i64 * (unsigned __int16)mNumParts;
  if ( !is_mul_ok(v10, 8ui64) )
    v9 = -1i64;
  this->mSceneryInstances = (UFG::DynamicSceneryInstance **)UFG::qMalloc(v9, "DynamicSceneryInstancePtr", 0i64);
  mNumSceneryInstances = this->mNumSceneryInstances;
  if ( mNumSceneryInstances == 1 )
  {
    m_NameUID = this->m_NameUID;
    mRenderModelGuid = mesh->mRenderModelGuid;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v15 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x100ui64, "DynamicSceneryInstance", 0i64, 1u);
    if ( v15 )
    {
      UFG::DynamicSceneryInstance::DynamicSceneryInstance(
        (UFG::DynamicSceneryInstance *)v15,
        m_NameUID,
        mRenderModelGuid,
        0);
      v6 = v16;
    }
    *this->mSceneryInstances = v6;
  }
  else
  {
    v17 = 0;
    if ( mNumSceneryInstances )
    {
      do
      {
        mOffset = mesh->mPartDetails.mOffset;
        if ( mOffset )
          v19 = (char *)&mesh->mPartDetails + mOffset;
        else
          v19 = 0i64;
        v20 = &v19[96 * v17];
        mInstanceUid = instanceData->mParts[v17].mInstanceUid;
        v22 = UFG::GetSimulationMemoryPool();
        v23 = UFG::qMemoryPool::Allocate(v22, 0x100ui64, "DynamicSceneryInstance", 0i64, 1u);
        if ( v23 )
        {
          UFG::DynamicSceneryInstance::DynamicSceneryInstance(
            (UFG::DynamicSceneryInstance *)v23,
            mInstanceUid,
            *((_DWORD *)v20 + 20),
            0);
          v25 = v24;
        }
        else
        {
          v25 = 0i64;
        }
        this->mSceneryInstances[v17++] = v25;
      }
      while ( v17 < this->mNumSceneryInstances );
    }
  }
}

// File Line: 54
// RVA: 0x450490
void __fastcall UFG::PhysicsRenderHelper::~PhysicsRenderHelper(UFG::PhysicsRenderHelper *this)
{
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v2; // rsi
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *mPrev; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *mNext; // rax
  unsigned __int16 i; // di
  UFG::DynamicSceneryInstance *v6; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v7; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsRenderHelper::`vftable;
  if ( this == UFG::PhysicsRenderHelper::s_PhysicsRenderHelperpCurrentIterator )
    UFG::PhysicsRenderHelper::s_PhysicsRenderHelperpCurrentIterator = (UFG::PhysicsRenderHelper *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( this->mSceneryInstances )
  {
    for ( i = 0; i < this->mNumSceneryInstances; ++i )
    {
      v6 = this->mSceneryInstances[i];
      if ( v6 )
        v6->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor(&v6->UFG::SimComponent, 1u);
    }
    operator delete[](this->mSceneryInstances);
  }
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 71
// RVA: 0x46DF70
void __fastcall UFG::PhysicsRenderHelper::OnAttach(UFG::PhysicsRenderHelper *this, UFG::SimObject *object)
{
  unsigned __int16 i; // bx
  __int64 v5; // rsi
  UFG::DynamicSceneryInstance *v6; // rdx
  UFG::SimComponent *v7; // rdx
  UFG::SimObjectModifier v8; // [rsp+28h] [rbp-40h] BYREF

  for ( i = 0; i < this->mNumSceneryInstances; ++i )
  {
    v5 = i;
    if ( this->mSceneryInstances[v5] )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v8, object, 1);
      v6 = this->mSceneryInstances[v5];
      if ( v6 )
        v7 = &v6->UFG::SimComponent;
      else
        v7 = 0i64;
      UFG::SimObjectModifier::AttachComponent(&v8, v7, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v8);
      UFG::SimObjectModifier::~SimObjectModifier(&v8);
    }
  }
}

// File Line: 84
// RVA: 0x46E750
void __fastcall UFG::PhysicsRenderHelper::OnDetach(UFG::PhysicsRenderHelper *this)
{
  unsigned __int16 i; // bx
  ArrayOfTuplesImplementation v3; // [rsp+28h] [rbp-30h] BYREF

  for ( i = 0; i < this->mNumSceneryInstances; ++i )
  {
    if ( this->mSceneryInstances[i] )
    {
      UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v3, this->m_pSimObject, 1);
      ArrayOfTuplesImplementation::clear(&v3);
      UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v3);
      UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v3);
    }
  }
}

// File Line: 107
// RVA: 0x475670
void __fastcall UFG::PhysicsRenderHelper::SetToFadeOut(UFG::PhysicsRenderHelper *this)
{
  unsigned __int16 mNumSceneryInstances; // ax
  unsigned __int16 v3; // bx
  UFG::DynamicSceneryInstance *v4; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CompositeLookComponent *ComponentOfTypeHK; // rax

  mNumSceneryInstances = this->mNumSceneryInstances;
  this->mFlags |= 1u;
  if ( mNumSceneryInstances )
  {
    v3 = 0;
    do
    {
      v4 = this->mSceneryInstances[v3];
      if ( v4 )
        UFG::DynamicSceneryInstance::ForceFadeOut(v4);
      ++v3;
    }
    while ( v3 < this->mNumSceneryInstances );
  }
  else
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pSimObject,
                                                             UFG::CompositeLookComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pSimObject,
                                                             UFG::CompositeLookComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        UFG::CompositeLookComponent::ForceFadeOut(ComponentOfTypeHK);
    }
  }
}

// File Line: 133
// RVA: 0x468A00
char __fastcall UFG::PhysicsRenderHelper::HasFadedOut(UFG::PhysicsRenderHelper *this)
{
  unsigned __int16 v2; // bx
  UFG::DynamicSceneryInstance *v3; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CompositeLookComponent *ComponentOfTypeHK; // rax

  if ( (this->mFlags & 1) != 0 )
  {
    if ( this->mSceneryInstances )
    {
      v2 = 0;
      if ( this->mNumSceneryInstances )
      {
        while ( 1 )
        {
          v3 = this->mSceneryInstances[v2];
          if ( v3 )
          {
            if ( !UFG::DynamicSceneryInstance::HasFadedOut(v3) )
              break;
          }
          if ( ++v2 >= this->mNumSceneryInstances )
            return 1;
        }
        return 0;
      }
    }
    else
    {
      m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pSimObject,
                                                               UFG::CompositeLookComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pSimObject,
                                                               UFG::CompositeLookComponent::_TypeUID);
        if ( ComponentOfTypeHK && !UFG::CompositeLookComponent::HasFadedOut(ComponentOfTypeHK) )
          return 0;
      }
    }
    return 1;
  }
  return 0;
}

// File Line: 164
// RVA: 0x461DF0
void __fastcall UFG::PhysicsRenderHelper::DisableSelfIllumination(UFG::PhysicsRenderHelper *this)
{
  UFG::DynamicSceneryInstance **mSceneryInstances; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  mSceneryInstances = this->mSceneryInstances;
  if ( mSceneryInstances )
  {
    (*mSceneryInstances)->mSelfIlluminationOverride = 0.0;
  }
  else
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::CompositeLookComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CompositeLookComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        HIDWORD(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mNext[1].mNext) = 0;
    }
  }
}

// File Line: 182
// RVA: 0x4766E0
void __fastcall UFG::PhysicsRenderHelper::SwapRenderModel(UFG::PhysicsRenderHelper *this, unsigned int renderModelUID)
{
  UFG::DynamicSceneryInstance **mSceneryInstances; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::DynamicSceneryInstance *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax

  mSceneryInstances = this->mSceneryInstances;
  if ( mSceneryInstances )
  {
    Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    v5 = *mSceneryInstances;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v5->mModelHandle, 0xA2ADCD77, renderModelUID, Inventory);
  }
}

// File Line: 209
// RVA: 0x461D40
void __fastcall UFG::PhysicsRenderHelper::DisableDynamicScenery(
        UFG::PhysicsRenderHelper *this,
        unsigned int dynmaicSceneryInstanceGuid)
{
  int mNumSceneryInstances; // r9d
  unsigned __int16 v5; // r8
  UFG::DynamicSceneryInstance **mSceneryInstances; // rdx
  UFG::DynamicSceneryInstance *v7; // rcx
  UFG::DynamicSceneryInstance *v8; // rdx
  __int64 v9; // rbx
  UFG::SimComponent *v10; // rdx

  mNumSceneryInstances = this->mNumSceneryInstances;
  v5 = 0;
  if ( this->mNumSceneryInstances )
  {
    mSceneryInstances = this->mSceneryInstances;
    while ( 1 )
    {
      v7 = mSceneryInstances[v5];
      if ( v7 )
      {
        if ( v7->m_NameUID == dynmaicSceneryInstanceGuid )
          break;
      }
      if ( ++v5 >= mNumSceneryInstances )
        return;
    }
    v8 = mSceneryInstances[v5];
    v9 = v5;
    if ( v8 )
      v10 = &v8->UFG::SimComponent;
    else
      v10 = 0i64;
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v10);
    this->mSceneryInstances[v9] = 0i64;
  }
}

// File Line: 235
// RVA: 0x4802C0
void __fastcall UFG::PhysicsRenderHelper::UpdateTransforms(
        UFG::PhysicsRenderHelper *this,
        UFG::CollisionMeshData *mesh,
        hkTransformf *rigidBodyTransform)
{
  unsigned __int16 mNumSceneryInstances; // ax
  UFG::DynamicSceneryInstance *v7; // rdx
  unsigned __int16 v8; // bx
  __int64 v9; // rsi
  hkTransformf transformOut; // [rsp+20h] [rbp-88h] BYREF
  hkTransformf v11; // [rsp+60h] [rbp-48h] BYREF

  mNumSceneryInstances = this->mNumSceneryInstances;
  if ( mNumSceneryInstances == 1 )
  {
    v7 = *this->mSceneryInstances;
    if ( v7 )
    {
      hkTransformf::get4x4ColumnMajor(rigidBodyTransform, &v7->mLocalWorld.v0.x);
      UFG::DynamicSceneryInstance::UpdateCullInfo(*this->mSceneryInstances);
    }
  }
  else
  {
    v8 = 0;
    if ( mNumSceneryInstances )
    {
      do
      {
        v9 = v8;
        if ( this->mSceneryInstances[v9] )
        {
          UFG::GetTransformFromShapeKey(&transformOut, mesh->mShape, v8);
          hkTransformf::setMul(&v11, rigidBodyTransform, &transformOut);
          hkTransformf::get4x4ColumnMajor(&v11, &this->mSceneryInstances[v9]->mLocalWorld.v0.x);
          UFG::DynamicSceneryInstance::UpdateCullInfo(this->mSceneryInstances[v9]);
        }
        ++v8;
      }
      while ( v8 < this->mNumSceneryInstances );
    }
  }
}

