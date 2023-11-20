// File Line: 14
// RVA: 0x1514370
__int64 dynamic_initializer_for__UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList__);
}

// File Line: 15
// RVA: 0x4680A0
const char *__fastcall UFG::PhysicsRenderHelper::GetTypeName(UFG::PhysicsRenderHelper *this)
{
  return "PhysicsRenderHelper";
}

// File Line: 24
// RVA: 0x44ABC0
void __fastcall UFG::PhysicsRenderHelper::PhysicsRenderHelper(UFG::PhysicsRenderHelper *this, UFG::CollisionInstanceData *instanceData, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionMeshData *v3; // r15
  UFG::CollisionInstanceData *v4; // r13
  UFG::PhysicsRenderHelper *v5; // rbx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v6; // r9
  UFG::DynamicSceneryInstance *v7; // rdi
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v8; // rax
  unsigned int v9; // eax
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr00_8
  unsigned __int16 v12; // ax
  unsigned int v13; // esi
  unsigned int v14; // ebp
  UFG::qMemoryPool *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::DynamicSceneryInstance *v17; // rax
  unsigned __int16 v18; // si
  __int64 v19; // rax
  signed __int64 v20; // rcx
  signed __int64 v21; // rbp
  unsigned int v22; // er12
  UFG::qMemoryPool *v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::DynamicSceneryInstance *v25; // rax
  UFG::DynamicSceneryInstance *v26; // rcx

  v3 = mesh;
  v4 = instanceData;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, mesh->mName.mUID);
  v6 = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsRenderHelper::`vftable';
  v7 = 0i64;
  v5->mNumSceneryInstances = 0;
  v5->mSceneryInstances = 0i64;
  v5->mFlags = 0;
  v8 = UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev;
  UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev->mNext = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&v5->mPrev;
  v6->mPrev = v8;
  v5->mNext = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList;
  UFG::PhysicsRenderHelper::s_PhysicsRenderHelperList.mNode.mPrev = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::PhysicsRenderHelper::_PhysicsRenderHelperTypeUID,
    "PhysicsRenderHelper");
  LOWORD(v9) = 1;
  if ( v3->mGeometryType )
    v9 = v3->mNumParts;
  v5->mNumSceneryInstances = v9;
  v11 = (unsigned __int16)v9;
  v10 = 8i64 * (unsigned __int16)v9;
  if ( !is_mul_ok(v11, 8ui64) )
    v10 = -1i64;
  v5->mSceneryInstances = (UFG::DynamicSceneryInstance **)UFG::qMalloc(v10, "DynamicSceneryInstancePtr", 0i64);
  v12 = v5->mNumSceneryInstances;
  if ( v12 == 1 )
  {
    v13 = v5->m_NameUID;
    v14 = v3->mRenderModelGuid;
    v15 = UFG::GetSimulationMemoryPool();
    v16 = UFG::qMemoryPool::Allocate(v15, 0x100ui64, "DynamicSceneryInstance", 0i64, 1u);
    if ( v16 )
    {
      UFG::DynamicSceneryInstance::DynamicSceneryInstance((UFG::DynamicSceneryInstance *)v16, v13, v14, 0);
      v7 = v17;
    }
    *v5->mSceneryInstances = v7;
  }
  else
  {
    v18 = 0;
    if ( v12 > 0u )
    {
      do
      {
        v19 = v3->mPartDetails.mOffset;
        if ( v19 )
          v20 = (signed __int64)&v3->mPartDetails + v19;
        else
          v20 = 0i64;
        v21 = v20 + 96i64 * v18;
        v22 = v4->mParts[v18].mInstanceUid;
        v23 = UFG::GetSimulationMemoryPool();
        v24 = UFG::qMemoryPool::Allocate(v23, 0x100ui64, "DynamicSceneryInstance", 0i64, 1u);
        if ( v24 )
        {
          UFG::DynamicSceneryInstance::DynamicSceneryInstance(
            (UFG::DynamicSceneryInstance *)v24,
            v22,
            *(_DWORD *)(v21 + 80),
            0);
          v26 = v25;
        }
        else
        {
          v26 = 0i64;
        }
        v5->mSceneryInstances[v18++] = v26;
      }
      while ( v18 < v5->mNumSceneryInstances );
    }
  }
}

// File Line: 54
// RVA: 0x450490
void __fastcall UFG::PhysicsRenderHelper::~PhysicsRenderHelper(UFG::PhysicsRenderHelper *this)
{
  UFG::PhysicsRenderHelper *v1; // rbx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v2; // rsi
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v3; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v4; // rax
  unsigned __int16 i; // di
  UFG::DynamicSceneryInstance *v6; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v7; // rcx
  UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PhysicsRenderHelper::`vftable';
  if ( this == UFG::PhysicsRenderHelper::s_PhysicsRenderHelperpCurrentIterator )
    UFG::PhysicsRenderHelper::s_PhysicsRenderHelperpCurrentIterator = (UFG::PhysicsRenderHelper *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::PhysicsRenderHelper,UFG::PhysicsRenderHelper> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( v1->mSceneryInstances )
  {
    for ( i = 0; i < v1->mNumSceneryInstances; ++i )
    {
      v6 = v1->mSceneryInstances[i];
      if ( v6 )
        v6->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v6->vfptr, 1u);
    }
    operator delete[](v1->mSceneryInstances);
  }
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 71
// RVA: 0x46DF70
void __fastcall UFG::PhysicsRenderHelper::OnAttach(UFG::PhysicsRenderHelper *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbp
  UFG::PhysicsRenderHelper *v3; // rdi
  unsigned __int16 i; // bx
  signed __int64 v5; // rsi
  UFG::DynamicSceneryInstance *v6; // rdx
  UFG::SimComponent *v7; // rdx
  UFG::SimObjectModifier v8; // [rsp+28h] [rbp-40h]

  v2 = object;
  v3 = this;
  for ( i = 0; i < v3->mNumSceneryInstances; ++i )
  {
    v5 = i;
    if ( v3->mSceneryInstances[v5] )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v8, v2, 1);
      v6 = v3->mSceneryInstances[v5];
      if ( v6 )
        v7 = (UFG::SimComponent *)&v6->vfptr;
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
  UFG::PhysicsRenderHelper *v1; // rdi
  unsigned __int16 i; // bx
  signed __int64 v3; // rsi
  UFG::SimObjectModifier v4; // [rsp+28h] [rbp-30h]

  v1 = this;
  for ( i = 0; i < v1->mNumSceneryInstances; ++i )
  {
    v3 = i;
    if ( v1->mSceneryInstances[v3] )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v4, v1->m_pSimObject, 1);
      v1->mSceneryInstances[v3];
      ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v4);
      UFG::SimObjectModifier::Close(&v4);
      UFG::SimObjectModifier::~SimObjectModifier(&v4);
    }
  }
}

// File Line: 107
// RVA: 0x475670
void __fastcall UFG::PhysicsRenderHelper::SetToFadeOut(UFG::PhysicsRenderHelper *this)
{
  unsigned __int16 v1; // ax
  UFG::PhysicsRenderHelper *v2; // rdi
  unsigned __int16 v3; // bx
  UFG::DynamicSceneryInstance *v4; // rcx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::CompositeLookComponent *v7; // rax

  v1 = this->mNumSceneryInstances;
  this->mFlags |= 1u;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    if ( v1 > 0u )
    {
      do
      {
        v4 = v2->mSceneryInstances[v3];
        if ( v4 )
          UFG::DynamicSceneryInstance::ForceFadeOut(v4);
        ++v3;
      }
      while ( v3 < v2->mNumSceneryInstances );
    }
  }
  else
  {
    v5 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v5,
                                              UFG::CompositeLookComponent::_TypeUID);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v5,
                                                UFG::CompositeLookComponent::_TypeUID);
        else
          v7 = (UFG::CompositeLookComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v5,
                                                                  UFG::CompositeLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CompositeLookComponent::_TypeUID));
      }
      else
      {
        v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v5,
                                              UFG::CompositeLookComponent::_TypeUID);
      }
      if ( v7 )
        UFG::CompositeLookComponent::ForceFadeOut(v7);
    }
  }
}

// File Line: 133
// RVA: 0x468A00
char __fastcall UFG::PhysicsRenderHelper::HasFadedOut(UFG::PhysicsRenderHelper *this)
{
  UFG::PhysicsRenderHelper *v1; // rdi
  unsigned __int16 v2; // bx
  UFG::DynamicSceneryInstance *v3; // rcx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::CompositeLookComponent *v7; // rax

  v1 = this;
  if ( this->mFlags & 1 )
  {
    if ( this->mSceneryInstances )
    {
      v2 = 0;
      if ( this->mNumSceneryInstances > 0u )
      {
        while ( 1 )
        {
          v3 = v1->mSceneryInstances[v2];
          if ( v3 )
          {
            if ( !(unsigned __int8)UFG::DynamicSceneryInstance::HasFadedOut(v3) )
              break;
          }
          if ( ++v2 >= v1->mNumSceneryInstances )
            return 1;
        }
        return 0;
      }
    }
    else
    {
      v5 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v5,
                                                UFG::CompositeLookComponent::_TypeUID);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v5,
                                                  UFG::CompositeLookComponent::_TypeUID);
          else
            v7 = (UFG::CompositeLookComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v5,
                                                                    UFG::CompositeLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CompositeLookComponent::_TypeUID));
        }
        else
        {
          v7 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v5,
                                                UFG::CompositeLookComponent::_TypeUID);
        }
        if ( v7 && !UFG::CompositeLookComponent::HasFadedOut(v7) )
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
  UFG::DynamicSceneryInstance **v1; // rax
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  v1 = this->mSceneryInstances;
  if ( v1 )
  {
    (*v1)->mSelfIlluminationOverride = 0.0;
  }
  else
  {
    v2 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CompositeLookComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
      }
      if ( v4 )
        HIDWORD(v4[1].m_BoundComponentHandles.mNode.mNext[1].mNext) = 0;
    }
  }
}

// File Line: 182
// RVA: 0x4766E0
void __fastcall UFG::PhysicsRenderHelper::SwapRenderModel(UFG::PhysicsRenderHelper *this, unsigned int renderModelUID)
{
  UFG::DynamicSceneryInstance **v2; // rbx
  unsigned int v3; // edi
  UFG::qResourceInventory *v4; // rax
  UFG::DynamicSceneryInstance *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax

  v2 = this->mSceneryInstances;
  v3 = renderModelUID;
  if ( v2 )
  {
    v4 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
    v5 = *v2;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mModelHandle.mPrev, 0xA2ADCD77, v3, v4);
  }
}

// File Line: 209
// RVA: 0x461D40
void __fastcall UFG::PhysicsRenderHelper::DisableDynamicScenery(UFG::PhysicsRenderHelper *this, unsigned int dynmaicSceneryInstanceGuid)
{
  signed int v2; // er9
  unsigned int v3; // er10
  UFG::PhysicsRenderHelper *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::DynamicSceneryInstance **v6; // rdx
  UFG::DynamicSceneryInstance *v7; // rcx
  UFG::DynamicSceneryInstance *v8; // rdx
  signed __int64 v9; // rbx
  UFG::SimComponent *v10; // rdx

  v2 = this->mNumSceneryInstances;
  v3 = dynmaicSceneryInstanceGuid;
  v4 = this;
  v5 = 0;
  if ( v2 > 0 )
  {
    v6 = this->mSceneryInstances;
    while ( 1 )
    {
      v7 = v6[v5];
      if ( v7 )
      {
        if ( v7->m_NameUID == v3 )
          break;
      }
      if ( ++v5 >= v2 )
        return;
    }
    v8 = v6[v5];
    v9 = v5;
    if ( v8 )
      v10 = (UFG::SimComponent *)&v8->vfptr;
    else
      v10 = 0i64;
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v10);
    v4->mSceneryInstances[v9] = 0i64;
  }
}

// File Line: 235
// RVA: 0x4802C0
void __fastcall UFG::PhysicsRenderHelper::UpdateTransforms(UFG::PhysicsRenderHelper *this, UFG::CollisionMeshData *mesh, hkTransformf *rigidBodyTransform)
{
  unsigned __int16 v3; // ax
  hkTransformf *v4; // rbp
  UFG::CollisionMeshData *v5; // r14
  UFG::PhysicsRenderHelper *v6; // rdi
  UFG::DynamicSceneryInstance *v7; // rdx
  unsigned __int16 v8; // bx
  signed __int64 v9; // rsi
  hkTransformf transformOut; // [rsp+20h] [rbp-88h]
  hkTransformf v11; // [rsp+60h] [rbp-48h]

  v3 = this->mNumSceneryInstances;
  v4 = rigidBodyTransform;
  v5 = mesh;
  v6 = this;
  if ( v3 == 1 )
  {
    v7 = *this->mSceneryInstances;
    if ( v7 )
    {
      hkTransformf::get4x4ColumnMajor(rigidBodyTransform, &v7->mLocalWorld.v0.x);
      UFG::DynamicSceneryInstance::UpdateCullInfo(*v6->mSceneryInstances);
    }
  }
  else
  {
    v8 = 0;
    if ( v3 > 0u )
    {
      do
      {
        v9 = v8;
        if ( v6->mSceneryInstances[v9] )
        {
          UFG::GetTransformFromShapeKey(&transformOut, v5->mShape, v8);
          hkTransformf::setMul(&v11, v4, &transformOut);
          hkTransformf::get4x4ColumnMajor(&v11, &v6->mSceneryInstances[v9]->mLocalWorld.v0.x);
          UFG::DynamicSceneryInstance::UpdateCullInfo(v6->mSceneryInstances[v9]);
        }
        ++v8;
      }
      while ( v8 < v6->mNumSceneryInstances );
    }
  }
}

