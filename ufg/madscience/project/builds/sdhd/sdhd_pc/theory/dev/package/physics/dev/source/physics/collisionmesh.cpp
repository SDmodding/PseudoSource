// File Line: 56
// RVA: 0x1458480
__int64 dynamic_initializer_for__UFG::CollisionMeshData::mDeferredBreakableList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CollisionMeshData::mDeferredBreakableList__);
}

// File Line: 70
// RVA: 0x97710
void __fastcall UFG::CollisionMeshBundle::CollisionMeshBundle(UFG::CollisionMeshBundle *this)
{
  UFG::CollisionMeshBundle *v1; // rsi
  __int64 v2; // rdx
  signed __int64 v3; // rax
  signed __int64 v4; // rdi
  signed __int64 v5; // rbx
  char v6; // dl
  __int64 v7; // rax
  char v8; // cl
  char *v9; // rdi
  UFG::NativePackfileUtils::Fixups *v10; // rax
  char v11; // al
  char *v12; // rdi
  unsigned int i; // ebx
  UFG::CollisionMeshData *v14; // rdi
  UFG::CollisionMeshData *v15; // rax
  UFG::CollisionMeshData *v16; // rcx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v1->mMeshIndices = (unsigned __int16 *)&v1[1];
  v2 = v1->mNumMeshes;
  v3 = (signed __int64)&v1[1] + 2 * v2;
  v1->mCollisionMeshData = (UFG::CollisionMeshData **)v3;
  v4 = v3 + 8 * v2;
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  v7 = v6;
  *(_DWORD *)(v5 + 4 * v7) = 3;
  *(_QWORD *)(v5 + 8 * v7 + 16) = "CollisionPackfile";
  *(_QWORD *)(v5 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v5 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v5 + 81) = v8;
  v9 = (char *)((v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v10 = (UFG::NativePackfileUtils::Fixups *)UFG::qMemoryPool::Allocate(
                                              &gPhysicsMemoryPool,
                                              0x20ui64,
                                              "NativePackfileUtils::Fixups",
                                              0i64,
                                              1u);
  if ( v10 )
  {
    v10->nonZeroFixups.m_data = 0i64;
    v10->nonZeroFixups.m_size = 0;
    v10->nonZeroFixups.m_capacityAndFlags = 2147483648;
    v10->zeroFixups.m_data = 0i64;
    v10->zeroFixups.m_size = 0;
    v10->zeroFixups.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v10 = 0i64;
  }
  v1->mHavokPackfile = (char *)v10;
  v1->mListShape = (hkpListShape *)UFG::NativePackfileUtils::loadInPlace(v9, v1->mHavokPackfileSize, v10);
  v11 = *(_BYTE *)(v5 + 80);
  if ( v11 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v11 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v12 = &v9[v1->mHavokPackfileSize];
  for ( i = 0; i < v1->mNumMeshes; ++i )
  {
    v14 = (UFG::CollisionMeshData *)((unsigned __int64)(v12 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
    if ( v14 )
    {
      UFG::CollisionMeshData::CollisionMeshData(v14, 0, v1->mListShape->m_childInfo.m_data[v1->mMeshIndices[i]].m_shape);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v1->mCollisionMeshData[i] = v16;
    v12 = (char *)v14 + v1->mCollisionMeshData[i]->mSize;
  }
}

// File Line: 107
// RVA: 0x9BC90
void __fastcall UFG::CollisionMeshBundle::~CollisionMeshBundle(UFG::CollisionMeshBundle *this)
{
  UFG::CollisionMeshBundle *v1; // rbp
  int v2; // edi
  unsigned int v3; // ebx
  UFG::CollisionMeshData *v4; // rsi
  hkReferencedObject *v5; // rcx
  unsigned __int64 v6; // rdx
  UFG::NativePackfileUtils::Fixups *v7; // rbx
  int v8; // er8
  __int64 v9; // rdx
  __int64 v10; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v11; // rdi
  UFG::qResourceHandle *v12; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v14; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v15; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax

  v1 = this;
  v2 = 0;
  v3 = 0;
  if ( this->mNumMeshes )
  {
    do
    {
      v4 = v1->mCollisionMeshData[v3];
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::BasePhysicsSystem::mInstance->mCollisionModels,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4);
      v5 = (hkReferencedObject *)&v4->mShape->vfptr;
      if ( v5 )
        hkReferencedObject::removeReference(v5);
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v4->mObjectProperties.mPrev);
      ++v3;
    }
    while ( v3 < v1->mNumMeshes );
  }
  v6 = ((unsigned __int64)&v1[1].mNode.mChild[v1->mNumMeshes] + 2 * v1->mNumMeshes + 7) & 0xFFFFFFFFFFFFFFF0ui64;
  v7 = (UFG::NativePackfileUtils::Fixups *)v1->mHavokPackfile;
  *(_DWORD *)(v6 + 0x38) &= 0xFFFFFFFE;
  v8 = 0;
  if ( v7->zeroFixups.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      *(_DWORD *)v7->zeroFixups.m_data[v9] = 0;
      ++v8;
      ++v9;
    }
    while ( v8 < v7->zeroFixups.m_size );
  }
  if ( v7->nonZeroFixups.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      *(_DWORD *)v7->nonZeroFixups.m_data[v10].addr = v7->nonZeroFixups.m_data[v10].val;
      ++v2;
      ++v10;
    }
    while ( v2 < v7->nonZeroFixups.m_size );
  }
  UFG::NativePackfileUtils::Fixups::~Fixups(v7);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v7);
  v11 = &v1->mResourceHandles;
  v12 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
  if ( v12 != (UFG::qResourceHandle *)&v1->mResourceHandles )
  {
    do
    {
      v13 = v12->mPrev;
      v14 = v12->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v12->mPrev;
      v12->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v12->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v12);
      operator delete[](v12);
      v12 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
    }
    while ( v12 != (UFG::qResourceHandle *)v11 );
  }
  v15 = v11->mNode.mPrev;
  v16 = v1->mResourceHandles.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v11->mNode.mPrev = &v11->mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

// File Line: 139
// RVA: 0x97AD0
void __fastcall UFG::CollisionMeshData::CollisionMeshData(UFG::CollisionMeshData *this)
{
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *v1; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  *(_QWORD *)&this->mSceneNodeName.mUID = -1i64;
  this->mFlags = 0;
  this->mName.mUID = -1;
  v1 = &this->mObjectProperties;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mObjectProperties.mPrev);
  v1->mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 150
// RVA: 0x978C0
void __fastcall UFG::CollisionMeshData::CollisionMeshData(UFG::CollisionMeshData *this, MemImageLoadFlag f, hkpShape *shape)
{
  UFG::CollisionMeshData *v3; // rbx
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *v4; // rdi
  unsigned __int64 v5; // rdi
  unsigned int v6; // er11
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // rax
  signed __int64 v10; // r9
  __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // r10
  __int64 v14; // rax
  signed __int64 v15; // r9
  __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rax
  char *v20; // rax
  UFG::FractureConnectivity *v21; // rdi

  v3 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mShape = shape;
  this->mRemoveTerminalsMoppModifierList = 0i64;
  v4 = &this->mObjectProperties;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mObjectProperties.mPrev);
  v4->mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v4->mPrev, v4->mTypeUID, v3->mPropertiesHandleGuid);
  if ( !v3->mObjectProperties.mData )
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties(v4);
  if ( !v3->mGeometryType )
  {
    v5 = v3->mShape[2].m_userData;
    v6 = 0;
    if ( v3->mNumParts > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = *(_QWORD *)(v5 + 240);
        v9 = v3->mVertexBuffer.mOffset;
        if ( v9 )
          v10 = (signed __int64)&v3->mVertexBuffer + v9;
        else
          v10 = 0i64;
        v11 = v3->mParts.mOffset;
        if ( v11 )
          v12 = (signed __int64)&v3->mParts + v11;
        else
          v12 = 0i64;
        v13 = 48i64 * v6;
        *(_QWORD *)(v7 + v8 + 40) = v10 + 12i64 * *(unsigned int *)(v13 + v12 + 32);
        v14 = v3->mIndexBuffer.mOffset;
        if ( v14 )
          v15 = (signed __int64)&v3->mIndexBuffer + v14;
        else
          v15 = 0i64;
        v16 = v3->mParts.mOffset;
        if ( v16 )
          v17 = (signed __int64)&v3->mParts + v16;
        else
          v17 = 0i64;
        *(_QWORD *)(v7 + v8 + 56) = v15 + 2i64 * *(unsigned int *)(v13 + v17 + 36);
        *(_WORD *)(v7 + v8) &= 7u;
        *(_WORD *)(v7 + v8) |= 8u;
        v18 = v3->mParts.mOffset;
        if ( v18 )
          v19 = (signed __int64)&v3->mParts + v18;
        else
          v19 = 0i64;
        *(_QWORD *)(v7 + v8 + 16) = v13 + v19;
        ++v6;
        v7 += 144i64;
      }
      while ( v6 < v3->mNumParts );
    }
  }
  if ( HIDWORD(v3->mObjectProperties.mData[2].mBaseNode.mNeighbours[1]) == 1 )
  {
    v20 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v21 = (UFG::FractureConnectivity *)v20;
    if ( v20 )
    {
      *((_QWORD *)v20 + 1) = 0i64;
      *(_QWORD *)v20 = 0i64;
      *((_DWORD *)v20 + 4) = 0;
      v20[20] = 0;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::FractureConnectivity::Build(v21, v3);
    v3->mFractureConnectivity = v21;
  }
  UFG::qBaseTreeRB::Add(&UFG::BasePhysicsSystem::mInstance->mCollisionModels.mTree, &v3->mNode);
}

// File Line: 242
// RVA: 0xAA240
void __usercall UFG::CollisionMeshData::GetInertiaTensor(UFG::CollisionMeshData *this@<rcx>, hkMatrix3f *I@<rdx>, const float massFudgeFactor@<xmm2>, __m128 a4@<xmm10>)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  hkVector4f v14; // xmm2
  hkVector4f v15; // xmm0

  v4 = (__m128)LODWORD(this->mInertiaTensorRow1.z);
  v5 = (__m128)LODWORD(this->mInertiaTensorRow2.z);
  v6 = (__m128)LODWORD(this->mInertiaTensorRow1.x);
  v7 = (__m128)LODWORD(this->mInertiaTensorRow2.y);
  v8 = (__m128)LODWORD(this->mInertiaTensorRow2.x);
  a4.m128_f32[0] = massFudgeFactor;
  v9 = _mm_shuffle_ps(a4, a4, 0);
  v10 = _mm_unpacklo_ps((__m128)LODWORD(this->mInertiaTensorRow1.y), (__m128)0i64);
  I->m_col0.m_quad = _mm_mul_ps(
                       _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(this->mInertiaTensorRow0.x),
                           (__m128)LODWORD(this->mInertiaTensorRow0.z)),
                         _mm_unpacklo_ps((__m128)LODWORD(this->mInertiaTensorRow0.y), (__m128)0i64)),
                       v9);
  v11 = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v6, v4), v10), v9);
  v12 = _mm_unpacklo_ps(I->m_col0.m_quad, v11);
  v13 = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v8, v5), _mm_unpacklo_ps(v7, (__m128)0i64)), v9);
  v14.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(I->m_col0.m_quad, v11), v13, 228);
  v15.m_quad = _mm_movelh_ps(v12, v13);
  I->m_col0 = (hkVector4f)v15.m_quad;
  I->m_col2 = (hkVector4f)v14.m_quad;
  I->m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v15.m_quad, v12), v13, 212);
}

// File Line: 257
// RVA: 0xA9710
void __fastcall UFG::CollisionMeshData::GetCentreOfMass(UFG::CollisionMeshData *this, hkVector4f *cm)
{
  cm->m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(this->mCentreOfMass.x), (__m128)LODWORD(this->mCentreOfMass.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(this->mCentreOfMass.y), (__m128)0i64));
}

// File Line: 264
// RVA: 0xAD170
void __fastcall UFG::CollisionMeshData::MarkBreakableParts(UFG::CollisionMeshData *this, UFG::RigidBody *body, float timeDelay)
{
  UFG::RigidBody *v3; // rsi
  UFG::CollisionMeshData *v4; // rdi
  __int64 v5; // rax
  UFG::Destruction *v6; // rbp
  unsigned int v7; // ebx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  char *v11; // rax
  char *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v17; // rax
  _QWORD *v18; // [rsp+88h] [rbp+20h]

  v3 = body;
  v4 = this;
  v5 = this->mPartDetails.mOffset;
  if ( v5 && (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + v5) )
  {
    if ( timeDelay > 0.0 )
    {
      v11 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      v12 = v11;
      if ( v11 )
      {
        *(_QWORD *)v11 = v11;
        *((_QWORD *)v11 + 1) = v11;
        v18 = v11 + 16;
        *v18 = v18;
        v18[1] = v18;
        *((_QWORD *)v11 + 4) = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
      v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v12 + 16);
      if ( *((_QWORD *)v12 + 4) )
      {
        v14 = v13->mPrev;
        v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)*((_QWORD *)v12 + 3);
        v14->mNext = v15;
        v15->mPrev = v14;
        v13->mPrev = v13;
        *((_QWORD *)v12 + 3) = v12 + 16;
      }
      *((_QWORD *)v12 + 4) = v3;
      if ( v3 )
      {
        v16 = v3->m_SafePointerList.mNode.mPrev;
        v16->mNext = v13;
        v13->mPrev = v16;
        *((_QWORD *)v12 + 3) = (char *)v3 + 8;
        v3->m_SafePointerList.mNode.mPrev = v13;
      }
      *((float *)v12 + 10) = timeDelay;
      v17 = UFG::CollisionMeshData::mDeferredBreakableList.mNode.mPrev;
      UFG::CollisionMeshData::mDeferredBreakableList.mNode.mPrev->mNext = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)v12;
      *(_QWORD *)v12 = v17;
      *((_QWORD *)v12 + 1) = &UFG::CollisionMeshData::mDeferredBreakableList;
      UFG::CollisionMeshData::mDeferredBreakableList.mNode.mPrev = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)v12;
    }
    else
    {
      v6 = UFG::Destruction::mInstance;
      v7 = 0;
      if ( this->mNumParts )
      {
        do
        {
          v8 = v4->mPartDetails.mOffset;
          if ( v8 )
          {
            v9 = (signed __int64)&v4->mPartDetails + v8;
            if ( v9 )
            {
              v10 = 96i64 * v7;
              if ( *(float *)(v10 + v9 + 68) > 0.0 && *(_DWORD *)(v10 + v9 + 76) != -1 )
                hkpBreakOffPartsUtil::markPieceBreakable(
                  v6->mBreakOffPartsUtil,
                  (hkpEntity *)&v3->mBody->vfptr,
                  v7,
                  *(float *)(v10 + v9 + 68));
            }
          }
          ++v7;
        }
        while ( v7 < v4->mNumParts );
      }
    }
  }
}

// File Line: 327
// RVA: 0xB4400
void __fastcall UFG::CollisionMeshData::UnmarkBreakableParts(UFG::CollisionMeshData *this, hkpEntity *entity)
{
  __int64 v2; // rax
  hkpEntity *v3; // rbp
  UFG::CollisionMeshData *v4; // rdi
  __int64 v5; // rbx
  UFG::Destruction *v6; // rsi
  __int64 v7; // rax
  signed __int64 v8; // rdx

  v2 = this->mPartDetails.mOffset;
  v3 = entity;
  v4 = this;
  if ( v2 )
  {
    if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + v2) )
    {
      v5 = 0i64;
      v6 = UFG::Destruction::mInstance;
      if ( this->mNumParts )
      {
        do
        {
          v7 = v4->mPartDetails.mOffset;
          if ( v7 )
          {
            v8 = (signed __int64)&v4->mPartDetails + v7;
            if ( v8 )
            {
              if ( *(float *)(96 * v5 + v8 + 68) > 0.0 )
                hkpBreakOffPartsUtil::unmarkPieceBreakable(v6->mBreakOffPartsUtil, v3, v5);
            }
          }
          v5 = (unsigned int)(v5 + 1);
        }
        while ( (unsigned int)v5 < v4->mNumParts );
      }
    }
  }
}

// File Line: 345
// RVA: 0xAFE30
void __fastcall UFG::CollisionMeshData::ResetFracture(UFG::CollisionMeshData *this)
{
  UFG::CollisionMeshData *v1; // rsi
  __int64 v2; // rax
  hkpListShape *v3; // rdi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v6; // rdi
  hkpShape *v7; // rbp
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v8; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v9; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v10; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v13; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v14; // rax
  UFG::FractureConnectivity *v15; // rbx
  UFG::FractureConnectivity::Node **v16; // rcx
  UFG::FractureConnectivity *v17; // rax

  v1 = this;
  v2 = this->mPartDetails.mOffset;
  if ( !v2 || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + v2) )
    goto LABEL_17;
  v3 = (hkpListShape *)this->mShape;
  v4 = this->mGeometryType - 3;
  if ( !v4 )
  {
    v3 = (hkpListShape *)v3->m_aabbHalfExtents.m_quad.m128_u64[1];
LABEL_7:
    if ( v3 )
    {
      v5 = 0;
      if ( v3->m_childInfo.m_size > 0 )
      {
        do
        {
          if ( v5 < 0x100 && !(v3->m_enabledChildren[(unsigned __int64)v5 >> 5] & (1 << (v5 & 0x1F))) )
            hkpListShape::enableChild(v3, v5);
          ++v5;
        }
        while ( (signed int)v5 < v3->m_childInfo.m_size );
      }
    }
    goto LABEL_13;
  }
  if ( v4 == 1 )
    goto LABEL_7;
LABEL_13:
  v6 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v1->mRemoveTerminalsMoppModifierList;
  if ( v6 )
  {
    v7 = v1->mShape;
    while ( (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v6->mNode.mNext != v6 )
    {
      v8 = v6->mNode.mPrev;
      v9 = v6->mNode.mPrev->mPrev;
      v10 = v6->mNode.mPrev->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = v8;
      v8->mNext = v8;
      hkpRemoveTerminalsMoppModifier::undoRemoveTerminals(
        (hkpRemoveTerminalsMoppModifier *)v8[1].mPrev,
        *(hkpMoppCode **)&v7[1].m_memSizeAndFlags);
      hkReferencedObject::removeReference((hkReferencedObject *)v8[1].mPrev);
      v11 = v8->mPrev;
      v12 = v8->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v8->mPrev = v8;
      v8->mNext = v8;
      operator delete[](v8);
    }
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v6);
    v13 = v6->mNode.mPrev;
    v14 = v6->mNode.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v6->mNode.mPrev = &v6->mNode;
    v6->mNode.mNext = &v6->mNode;
    operator delete[](v6);
    v1->mRemoveTerminalsMoppModifierList = 0i64;
  }
LABEL_17:
  if ( HIDWORD(v1->mObjectProperties.mData[2].mBaseNode.mNeighbours[1]) == 1 )
  {
    v15 = v1->mFractureConnectivity;
    if ( v15 )
    {
      v16 = v15->mNodes.p;
      if ( v16 )
        operator delete[](v16);
      v15->mNodes.p = 0i64;
      *(_QWORD *)&v15->mNodes.size = 0i64;
      operator delete[](v15);
    }
    v17 = (UFG::FractureConnectivity *)UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    if ( v17 )
    {
      v17->mNodes.p = 0i64;
      *(_QWORD *)&v17->mNodes.size = 0i64;
      v17->mNumColors = 0;
      v17->mColorsDirty = 0;
    }
    else
    {
      v17 = 0i64;
    }
    v1->mFractureConnectivity = v17;
    UFG::FractureConnectivity::Build(v17, v1);
  }
}

// File Line: 422
// RVA: 0xA0940
void __fastcall UFG::CollisionMeshData::AddMoppTerminalModifier(UFG::CollisionMeshData *this, hkpRemoveTerminalsMoppModifier *modifier)
{
  hkpRemoveTerminalsMoppModifier *v2; // rsi
  UFG::CollisionMeshData *v3; // rdi
  char *v4; // rax
  __int64 *v5; // rdi
  char *v6; // rax
  char *v7; // rbx
  __int64 v8; // rax

  v2 = modifier;
  v3 = this;
  if ( !this->mRemoveTerminalsMoppModifierList )
  {
    v4 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
    if ( v4 )
    {
      *(_QWORD *)v4 = v4;
      *((_QWORD *)v4 + 1) = v4;
    }
    v3->mRemoveTerminalsMoppModifierList = v4;
  }
  v5 = (__int64 *)v3->mRemoveTerminalsMoppModifierList;
  v6 = UFG::qMalloc(0x18ui64, "CollisionMeshData", 0i64);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
  }
  else
  {
    v7 = 0i64;
  }
  *((_QWORD *)v7 + 2) = v2;
  hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v8 = *v5;
  *(_QWORD *)(v8 + 8) = v7;
  *(_QWORD *)v7 = v8;
  *((_QWORD *)v7 + 1) = v5;
  *v5 = (__int64)v7;
}

// File Line: 452
// RVA: 0xB2D80
UFG::CollisionMeshData *__fastcall UFG::CollisionMeshData::SplitMeshUsingConnectivity(UFG::FractureConnectivity *graph, UFG::CollisionMeshData *parent, hkTransformf *transform)
{
  hkTransformf *v3; // r13
  UFG::CollisionMeshData *v4; // rsi
  UFG::FractureConnectivity *v5; // r14
  unsigned int v6; // ebx
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdi
  UFG::FractureConnectivity *v10; // rax
  hkpShape *v11; // rax
  char v12; // cl
  hkpShape *v13; // r15
  hkLifoAllocator *v14; // rax
  hkLifoAllocator *v15; // r8
  int v16; // edx
  hkpShape **v17; // rax
  char *v18; // rcx
  unsigned int v19; // ebx
  int v20; // er8
  hkpShape *v21; // r12
  int v22; // er15
  __int64 v23; // rbx
  hkpShape *v24; // r13
  _QWORD **v25; // rax
  hkpConvexTransformShape *v26; // rax
  hkpShape *v27; // rax
  hkpShape *v28; // rcx
  _QWORD **v29; // rax
  hkpListShape *v30; // rax
  hkpShape *v31; // rax
  signed __int64 v32; // rbx
  signed __int64 *v33; // r9
  signed __int64 v34; // rax
  unsigned int v35; // er8
  __int64 v36; // rax
  signed __int64 v37; // rdx
  signed __int64 v38; // rcx
  signed __int64 v39; // rdx
  char *v40; // r8
  unsigned __int64 v41; // r8
  signed __int64 *v42; // rcx
  signed __int64 v43; // rax
  unsigned int v44; // er8
  __int64 v45; // rax
  signed __int64 v46; // rdx
  signed __int64 v47; // rcx
  signed __int64 v48; // rdx
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __int64 v53; // kr00_8
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  char *v62; // rsi
  int v63; // ecx
  int v64; // ebx
  hkLifoAllocator *v65; // rax
  signed int v66; // ebx
  int v67; // er8
  hkpShape **array; // [rsp+30h] [rbp-D0h]
  int numShapes; // [rsp+38h] [rbp-C8h]
  int v71; // [rsp+3Ch] [rbp-C4h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v73; // [rsp+48h] [rbp-B8h]
  hkMassProperties massProperties; // [rsp+50h] [rbp-B0h]
  __int64 v75; // [rsp+A0h] [rbp-60h]
  hkTransformf v76; // [rsp+B0h] [rbp-50h]
  hkTransformf bTc; // [rsp+F0h] [rbp-10h]
  hkTransformf transformOut; // [rsp+130h] [rbp+30h]
  hkTransformf aTb; // [rsp+170h] [rbp+70h]
  __int64 result; // [rsp+1F0h] [rbp+F0h]
  char *v81; // [rsp+1F8h] [rbp+F8h]
  hkTransformf *v82; // [rsp+200h] [rbp+100h]

  v82 = transform;
  v75 = -2i64;
  v3 = transform;
  v4 = parent;
  v5 = graph;
  v6 = graph->mNodes.size;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 144 * graph->mNodes.size + 272, "CollisionMeshData1", 0i64, 1u);
  result = (__int64)v7;
  v81 = v7;
  if ( v7 )
  {
    UFG::CollisionMeshData::CollisionMeshData((UFG::CollisionMeshData *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_DWORD *)(v9 + 40) = v4->mBundleGuid;
  *(_DWORD *)(v9 + 48) = v4->mNumVertices;
  *(_DWORD *)(v9 + 52) = v4->mNumIndices;
  *(_DWORD *)(v9 + 76) = v4->mRenderModelGuid;
  *(_DWORD *)(v9 + 44) = 4;
  *(_QWORD *)(v9 + 80) = 0i64;
  *(_QWORD *)(v9 + 200) = 0i64;
  *(_DWORD *)(v9 + 220) = 0;
  *(_QWORD *)(v9 + 176) = 0i64;
  *(_QWORD *)(v9 + 184) = 0i64;
  *(UFG::qSymbol *)(v9 + 216) = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                (UFG::qSymbol *)&result,
                                                "SplitMeshUsingConnectivity")->mUID;
  v10 = 0i64;
  if ( v6 > 1 )
    v10 = v5;
  *(_QWORD *)(v9 + 208) = v10;
  *(_DWORD *)(v9 + 56) = v6;
  *(_DWORD *)(v9 + 60) = 0;
  v11 = v4->mShape;
  v12 = v11->m_type.m_storage;
  if ( v12 == 9 )
  {
    v13 = (hkpShape *)v11[2].m_userData;
  }
  else
  {
    v13 = 0i64;
    if ( v12 == 8 )
      v13 = v4->mShape;
  }
  array = 0i64;
  numShapes = 0;
  v71 = 2147483648;
  v73 = v6;
  if ( v6 )
  {
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = v14;
    v16 = (((8 * v6 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v17 = (hkpShape **)v14->m_cur;
    v18 = (char *)v17 + v16;
    if ( v16 > v15->m_slabSize || v18 > v15->m_end )
      v17 = (hkpShape **)hkLifoAllocator::allocateFromNewSlab(v15, v16);
    else
      v15->m_cur = v18;
  }
  else
  {
    v17 = 0i64;
  }
  array = v17;
  v71 = v6 | 0x80000000;
  p = v17;
  v19 = 0;
  if ( v5->mNodes.size > 0 )
  {
    v20 = numShapes;
    do
    {
      v21 = *(hkpShape **)(32i64 * v5->mNodes.p[v19]->partIdx + *(_QWORD *)&v13[1].m_type.m_storage);
      if ( v20 == (v71 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v20 = numShapes;
      }
      array[v20] = v21;
      v20 = numShapes++ + 1;
      ++v19;
    }
    while ( v19 < v5->mNodes.size );
  }
  hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&(*array)[2], &transformOut);
  hkTransformf::setMul(&v76, v3, &transformOut);
  hkTransformf::setInverse(&aTb, &transformOut);
  v22 = 0;
  if ( numShapes > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = array[v23];
      hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&v24[2], &bTc);
      hkTransformf::setMul(&bTc, &aTb, &bTc);
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (hkpConvexTransformShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                         v25[11],
                                         128i64);
      result = (__int64)v26;
      if ( v26 )
      {
        hkpConvexTransformShape::hkpConvexTransformShape(
          v26,
          *(hkpConvexShape **)&v24[1].m_type.m_storage,
          &bTc,
          REFERENCE_POLICY_INCREMENT);
        v28 = v27;
      }
      else
      {
        v28 = 0i64;
      }
      array[v23] = v28;
      ++v22;
      ++v23;
    }
    while ( v22 < numShapes );
    v3 = v82;
  }
  v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(v29[11], 144i64);
  v82 = (hkTransformf *)v30;
  if ( v30 )
    hkpListShape::hkpListShape(v30, array, numShapes, REFERENCE_POLICY_INCREMENT);
  else
    v31 = 0i64;
  *(_QWORD *)(v9 + 192) = v31;
  *(_DWORD *)(v9 + 64) = (unsigned __int8)hkpShapeDepthUtil::getShapeDepth(v31);
  v32 = v9 + 272;
  v82 = (hkTransformf *)(v9 + 272);
  v33 = (signed __int64 *)(v9 + 152);
  if ( v9 == -272 )
    v34 = 0i64;
  else
    v34 = v32 - (_QWORD)v33;
  *v33 = v34;
  v35 = 0;
  if ( v5->mNodes.size )
  {
    do
    {
      v36 = v4->mParts.mOffset;
      if ( v36 )
        v37 = (signed __int64)&v4->mParts + v36;
      else
        v37 = 0i64;
      v38 = v37 + 48i64 * v5->mNodes.p[v35]->partIdx;
      result = v32;
      if ( v32 )
      {
        *(_DWORD *)v32 = 0;
        v39 = v32;
      }
      else
      {
        v39 = 0i64;
      }
      *(_DWORD *)v39 = *(_DWORD *)v38;
      *(_DWORD *)(v39 + 4) = *(_DWORD *)(v38 + 4);
      *(_QWORD *)(v39 + 8) = *(_QWORD *)(v38 + 8);
      *(_QWORD *)(v39 + 16) = *(_QWORD *)(v38 + 16);
      *(_DWORD *)(v39 + 24) = *(_DWORD *)(v38 + 24);
      *(_DWORD *)(v39 + 28) = *(_DWORD *)(v38 + 28);
      *(_DWORD *)(v39 + 36) = *(_DWORD *)(v38 + 36);
      *(_DWORD *)(v39 + 32) = *(_DWORD *)(v38 + 32);
      v32 += 48i64;
      v82 = (hkTransformf *)v32;
      ++v35;
    }
    while ( v35 < v5->mNodes.size );
  }
  v40 = (char *)v33 + *v33;
  if ( !*v33 )
    v40 = 0i64;
  v41 = *((_QWORD *)v40 + 2);
  *(_QWORD *)(v9 + 32) = v41;
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v9 + 224), *(_QWORD *)(v9 + 240), v41);
  v42 = (signed __int64 *)(v9 + 160);
  if ( v32 )
    v43 = v32 - (_QWORD)v42;
  else
    v43 = 0i64;
  *v42 = v43;
  v44 = 0;
  if ( v5->mNodes.size )
  {
    do
    {
      v45 = v4->mPartDetails.mOffset;
      if ( v45 )
        v46 = (signed __int64)&v4->mPartDetails + v45;
      else
        v46 = 0i64;
      v47 = v46 + 96i64 * v5->mNodes.p[v44]->partIdx;
      result = v32;
      if ( v32 )
      {
        *(_DWORD *)(v32 + 72) = -1;
        *(_QWORD *)(v32 + 84) = -1i64;
        v48 = v32;
      }
      else
      {
        v48 = 0i64;
      }
      *(_DWORD *)(v48 + 84) = *(_DWORD *)(v47 + 84);
      *(_DWORD *)(v48 + 88) = *(_DWORD *)(v47 + 88);
      *(_DWORD *)(v48 + 76) = *(_DWORD *)(v47 + 76);
      *(_DWORD *)(v48 + 72) = *(_DWORD *)(v47 + 72);
      *(_DWORD *)(v48 + 80) = *(_DWORD *)(v47 + 80);
      *(_DWORD *)(v48 + 68) = *(_DWORD *)(v47 + 68);
      *(_OWORD *)v48 = *(_OWORD *)v47;
      *(_OWORD *)(v48 + 16) = *(_OWORD *)(v47 + 16);
      *(_OWORD *)(v48 + 32) = *(_OWORD *)(v47 + 32);
      *(_OWORD *)(v48 + 48) = *(_OWORD *)(v47 + 48);
      *(_DWORD *)(v48 + 64) = *(_DWORD *)(v47 + 64);
      v32 += 96i64;
      v82 = (hkTransformf *)v32;
      ++v44;
    }
    while ( v44 < v5->mNodes.size );
  }
  *(_QWORD *)&massProperties.m_volume = 0i64;
  massProperties.m_centerOfMass = 0i64;
  massProperties.m_inertiaTensor.m_col0 = 0i64;
  massProperties.m_inertiaTensor.m_col1 = 0i64;
  massProperties.m_inertiaTensor.m_col2 = 0i64;
  if ( UFG::CollisionMeshData::ComputeMassProperties((UFG::CollisionMeshData *)v9, &massProperties, 0i64) )
  {
    *(float *)(v9 + 144) = massProperties.m_mass;
    v49 = _mm_unpacklo_ps(massProperties.m_inertiaTensor.m_col0.m_quad, massProperties.m_inertiaTensor.m_col1.m_quad);
    v50 = _mm_shuffle_ps(
            _mm_unpackhi_ps(massProperties.m_inertiaTensor.m_col0.m_quad, massProperties.m_inertiaTensor.m_col1.m_quad),
            massProperties.m_inertiaTensor.m_col2.m_quad,
            228);
    v51 = _mm_movelh_ps(v49, massProperties.m_inertiaTensor.m_col2.m_quad);
    v52 = _mm_shuffle_ps(_mm_movehl_ps(v51, v49), massProperties.m_inertiaTensor.m_col2.m_quad, 212);
    *(_DWORD *)(v9 + 108) = v51.m128_i32[0];
    *(_DWORD *)(v9 + 112) = (unsigned __int128)_mm_shuffle_ps(v51, v51, 85);
    *(_DWORD *)(v9 + 116) = (unsigned __int128)_mm_shuffle_ps(v51, v51, 170);
    *(_DWORD *)(v9 + 120) = v52.m128_i32[0];
    *(_DWORD *)(v9 + 124) = (unsigned __int128)_mm_shuffle_ps(v52, v52, 85);
    *(_DWORD *)(v9 + 128) = (unsigned __int128)_mm_shuffle_ps(v52, v52, 170);
    *(_DWORD *)(v9 + 132) = v50.m128_i32[0];
    *(_DWORD *)(v9 + 136) = (unsigned __int128)_mm_shuffle_ps(v50, v50, 85);
    *(_DWORD *)(v9 + 140) = (unsigned __int128)_mm_shuffle_ps(v50, v50, 170);
    v53 = *(__int64 *)((char *)massProperties.m_centerOfMass.m_quad.m128_i64 + 4);
    *(float *)(v9 + 96) = massProperties.m_centerOfMass.m_quad.m128_f32[0];
    *(_QWORD *)(v9 + 100) = v53;
  }
  else
  {
    *(float *)(v9 + 144) = v4->mMass;
    v54 = v4->mCentreOfMass.y;
    v55 = v4->mCentreOfMass.z;
    *(float *)(v9 + 96) = v4->mCentreOfMass.x;
    *(float *)(v9 + 100) = v54;
    *(float *)(v9 + 104) = v55;
    v56 = v4->mInertiaTensorRow0.y;
    v57 = v4->mInertiaTensorRow0.z;
    *(float *)(v9 + 108) = v4->mInertiaTensorRow0.x;
    *(float *)(v9 + 112) = v56;
    *(float *)(v9 + 116) = v57;
    v58 = v4->mInertiaTensorRow1.y;
    v59 = v4->mInertiaTensorRow1.z;
    *(float *)(v9 + 120) = v4->mInertiaTensorRow1.x;
    *(float *)(v9 + 124) = v58;
    *(float *)(v9 + 128) = v59;
    v60 = v4->mInertiaTensorRow2.y;
    v61 = v4->mInertiaTensorRow2.z;
    *(float *)(v9 + 132) = v4->mInertiaTensorRow2.x;
    *(float *)(v9 + 136) = v60;
    *(float *)(v9 + 140) = v61;
  }
  v3->m_rotation.m_col0 = v76.m_rotation.m_col0;
  v3->m_rotation.m_col1 = v76.m_rotation.m_col1;
  v3->m_rotation.m_col2 = v76.m_rotation.m_col2;
  v3->m_translation = v76.m_translation;
  v62 = (char *)p;
  v63 = numShapes;
  if ( p == array )
    v63 = 0;
  numShapes = v63;
  v64 = v73;
  v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v66 = (8 * v64 + 127) & 0xFFFFFF80;
  v67 = (v66 + 15) & 0xFFFFFFF0;
  if ( v66 > v65->m_slabSize || &v62[v67] != v65->m_cur || v65->m_firstNonLifoEnd == v62 )
    hkLifoAllocator::slowBlockFree(v65, v62, v67);
  else
    v65->m_cur = v62;
  numShapes = 0;
  if ( v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v71);
  return (UFG::CollisionMeshData *)v9;
}5->m_slabSize || &v62[v67] != v65->m_cur || v65->m_firstNonLifoEnd == v62 )
    hkLifoAllocator

// File Line: 612
// RVA: 0xA2260
UFG::CollisionMeshData *__fastcall UFG::CollisionMeshData::Clone(UFG::CollisionMeshData *this)
{
  UFG::CollisionMeshData *v1; // rsi
  char *v2; // rax
  UFG::CollisionMeshData *v3; // rax
  UFG::CollisionMeshData *v4; // rdi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  signed __int64 *v13; // rcx
  __int64 v14; // rax
  signed __int64 v15; // rax
  signed __int64 v16; // rax
  signed __int64 *v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rax
  signed __int64 v20; // rax
  signed __int64 *v21; // rcx
  __int64 v22; // rax
  signed __int64 v23; // rax
  signed __int64 v24; // rax
  signed __int64 *v25; // rcx
  __int64 v26; // rax
  signed __int64 v27; // rax
  signed __int64 v28; // rax
  hkpShape *v29; // r13
  __int64 v30; // r12
  hkLifoAllocator *v31; // rax
  int v32; // edx
  hkpShape **v33; // rcx
  char *v34; // r8
  __int64 v35; // r14
  __int64 v36; // rbx
  int v37; // ecx
  hkpShape *v38; // r15
  _QWORD **v39; // rax
  hkpListShape *v40; // rax
  hkpShape *v41; // rax
  char *v42; // r14
  int v43; // ecx
  int v44; // ebx
  hkLifoAllocator *v45; // rax
  signed int v46; // ebx
  int v47; // er8
  signed __int64 *v48; // rcx
  __int64 v49; // rax
  signed __int64 v50; // rax
  signed __int64 v51; // rax
  UFG::FractureConnectivity *v52; // rax
  hkpShape **array; // [rsp+28h] [rbp-28h]
  int v55; // [rsp+30h] [rbp-20h]
  int v56; // [rsp+34h] [rbp-1Ch]
  void *p; // [rsp+38h] [rbp-18h]
  int v58; // [rsp+40h] [rbp-10h]

  v1 = this;
  v2 = UFG::qMalloc(0x110ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
  {
    UFG::CollisionMeshData::CollisionMeshData((UFG::CollisionMeshData *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v4->mPropertiesHandleGuid = v1->mPropertiesHandleGuid;
  v4->mBundleGuid = v1->mBundleGuid;
  v4->mGeometryType = v1->mGeometryType;
  v4->mNumVertices = v1->mNumVertices;
  v4->mNumIndices = v1->mNumIndices;
  v4->mNumParts = v1->mNumParts;
  v4->mShapeKeyDepth = v1->mShapeKeyDepth;
  v4->mSceneNodeName.mUID = v1->mSceneNodeName.mUID;
  v4->mSceneNodeNameUC.mUID = v1->mSceneNodeNameUC.mUID;
  v4->mRenderModelGuid = v1->mRenderModelGuid;
  v4->mParkourGuid = v1->mParkourGuid;
  v4->mCoverGuid = v1->mCoverGuid;
  v4->mFlags = v1->mFlags | 2;
  v4->mCustomDataSlotIndex = v1->mCustomDataSlotIndex;
  v5 = v1->mCentreOfMass.y;
  v6 = v1->mCentreOfMass.z;
  v4->mCentreOfMass.x = v1->mCentreOfMass.x;
  v4->mCentreOfMass.y = v5;
  v4->mCentreOfMass.z = v6;
  v7 = v1->mInertiaTensorRow0.y;
  v8 = v1->mInertiaTensorRow0.z;
  v4->mInertiaTensorRow0.x = v1->mInertiaTensorRow0.x;
  v4->mInertiaTensorRow0.y = v7;
  v4->mInertiaTensorRow0.z = v8;
  v9 = v1->mInertiaTensorRow1.y;
  v10 = v1->mInertiaTensorRow1.z;
  v4->mInertiaTensorRow1.x = v1->mInertiaTensorRow1.x;
  v4->mInertiaTensorRow1.y = v9;
  v4->mInertiaTensorRow1.z = v10;
  v11 = v1->mInertiaTensorRow2.y;
  v12 = v1->mInertiaTensorRow2.z;
  v4->mInertiaTensorRow2.x = v1->mInertiaTensorRow2.x;
  v4->mInertiaTensorRow2.y = v11;
  v4->mInertiaTensorRow2.z = v12;
  v4->mMass = v1->mMass;
  v13 = &v4->mParts.mOffset;
  v14 = v1->mParts.mOffset;
  if ( v14 && (v15 = (signed __int64)&v1->mParts + v14) != 0 )
    v16 = v15 - (_QWORD)v13;
  else
    v16 = 0i64;
  *v13 = v16;
  v17 = &v4->mPartDetails.mOffset;
  v18 = v1->mPartDetails.mOffset;
  if ( v18 && (v19 = (signed __int64)&v1->mPartDetails + v18) != 0 )
    v20 = v19 - (_QWORD)v17;
  else
    v20 = 0i64;
  *v17 = v20;
  v21 = &v4->mIndexBuffer.mOffset;
  v22 = v1->mIndexBuffer.mOffset;
  if ( v22 && (v23 = (signed __int64)&v1->mIndexBuffer + v22) != 0 )
    v24 = v23 - (_QWORD)v21;
  else
    v24 = 0i64;
  *v21 = v24;
  v25 = &v4->mVertexBuffer.mOffset;
  v26 = v1->mVertexBuffer.mOffset;
  if ( v26 && (v27 = (signed __int64)&v1->mVertexBuffer + v26) != 0 )
    v28 = v27 - (_QWORD)v25;
  else
    v28 = 0i64;
  *v25 = v28;
  v4->mRemoveTerminalsMoppModifierList = 0i64;
  v4->mFractureConnectivity = 0i64;
  v4->mName.mUID = v1->mName.mUID;
  v4->mSize = v1->mSize;
  UFG::qReflectHandleBase::operator=(
    (UFG::qReflectHandleBase *)&v4->mObjectProperties.mPrev,
    (UFG::qReflectHandleBase *)&v1->mObjectProperties.mPrev);
  v29 = v1->mShape;
  if ( v29->m_type.m_storage == 8 )
  {
    v30 = SLODWORD(v29[1].m_userData);
    array = 0i64;
    v55 = 0;
    v56 = 2147483648;
    v58 = v30;
    if ( (_DWORD)v30 )
    {
      v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (((8 * v30 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
      v33 = (hkpShape **)v31->m_cur;
      v34 = (char *)v33 + v32;
      if ( v32 > v31->m_slabSize || v34 > v31->m_end )
        v33 = (hkpShape **)hkLifoAllocator::allocateFromNewSlab(v31, v32);
      else
        v31->m_cur = v34;
    }
    else
    {
      v33 = 0i64;
    }
    array = v33;
    v56 = v30 | 0x80000000;
    p = v33;
    v35 = v30;
    if ( (signed int)v30 > 0 )
    {
      v36 = 0i64;
      v37 = v55;
      do
      {
        v38 = *(hkpShape **)(v36 + *(_QWORD *)&v29[1].m_type.m_storage);
        if ( v37 == (v56 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v37 = v55;
        }
        array[v37] = v38;
        v37 = v55++ + 1;
        v36 += 32i64;
        --v35;
      }
      while ( v35 );
    }
    v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v40 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v39[11] + 8i64))(v39[11], 144i64);
    if ( v40 )
      hkpListShape::hkpListShape(v40, array, v30, REFERENCE_POLICY_INCREMENT);
    else
      v41 = 0i64;
    v4->mShape = v41;
    v42 = (char *)p;
    v43 = v55;
    if ( p == array )
      v43 = 0;
    v55 = v43;
    v44 = v58;
    v45 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v46 = (8 * v44 + 127) & 0xFFFFFF80;
    v47 = (v46 + 15) & 0xFFFFFFF0;
    if ( v46 > v45->m_slabSize || &v42[v47] != v45->m_cur || v45->m_firstNonLifoEnd == v42 )
      hkLifoAllocator::slowBlockFree(v45, v42, v47);
    else
      v45->m_cur = v42;
    v55 = 0;
    if ( v56 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v56);
    array = 0i64;
    v56 = 2147483648;
  }
  else
  {
    v1->mShape = 0i64;
  }
  v4->mNumFractureConnections = v1->mNumFractureConnections;
  v48 = &v4->mFractureConnections.mOffset;
  v49 = v1->mFractureConnections.mOffset;
  if ( v49 && (v50 = (signed __int64)&v1->mFractureConnections + v49) != 0 )
    v51 = v50 - (_QWORD)v48;
  else
    v51 = 0i64;
  *v48 = v51;
  if ( HIDWORD(v4->mObjectProperties.mData[2].mBaseNode.mNeighbours[1]) == 1 )
  {
    v52 = (UFG::FractureConnectivity *)UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    if ( v52 )
    {
      v52->mNodes.p = 0i64;
      *(_QWORD *)&v52->mNodes.size = 0i64;
      v52->mNumColors = 0;
      v52->mColorsDirty = 0;
    }
    else
    {
      v52 = 0i64;
    }
    v4->mFractureConnectivity = v52;
    UFG::FractureConnectivity::Build(v52, v4);
  }
  return v4;
}

// File Line: 682
// RVA: 0xA3BF0
bool __fastcall UFG::CollisionMeshData::ComputeMassProperties(UFG::CollisionMeshData *this, hkMassProperties *massProperties, BitArray256 *fractureState)
{
  UFG::CollisionMeshData *v3; // rsi
  hkResultEnum v4; // ebx
  unsigned int v5; // er12
  signed int v6; // er14
  __int64 v7; // r13
  __int64 v8; // r15
  hkpShape *v9; // rbx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // r8
  signed __int64 v13; // rdx
  signed __int64 v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  signed __int64 v18; // rcx
  int v19; // ecx
  signed __int64 v20; // rcx
  bool v21; // zf
  __int64 v22; // rcx
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm1
  hkVector4f v25; // xmm3
  char *array; // [rsp+20h] [rbp-99h]
  int v28; // [rsp+28h] [rbp-91h]
  int v29; // [rsp+2Ch] [rbp-8Dh]
  __int64 v30; // [rsp+30h] [rbp-89h]
  __int128 v31; // [rsp+40h] [rbp-79h]
  __m128 v32; // [rsp+50h] [rbp-69h]
  __m128 v33; // [rsp+60h] [rbp-59h]
  __m128 v34; // [rsp+70h] [rbp-49h]
  hkTransformf transformOut; // [rsp+80h] [rbp-39h]
  __int64 v36; // [rsp+C0h] [rbp+7h]
  __int64 result; // [rsp+120h] [rbp+67h]
  hkMassProperties *v38; // [rsp+128h] [rbp+6Fh]
  BitArray256 *v39; // [rsp+130h] [rbp+77h]
  __int64 v40; // [rsp+138h] [rbp+7Fh]

  v39 = fractureState;
  v38 = massProperties;
  v36 = -2i64;
  v3 = this;
  v4 = 1;
  if ( this->mShape->m_type.m_storage == 8 )
  {
    array = 0i64;
    v28 = 0;
    v29 = 2147483648;
    v5 = 0;
    v6 = 1;
    if ( SLODWORD(this->mShape[1].m_userData) > 0 )
    {
      v7 = 0i64;
      v8 = 0i64;
      v9 = this->mShape;
      do
      {
        if ( !fractureState || !(v6 & fractureState->mBits[v5 >> 5]) )
        {
          v30 = 0i64;
          v31 = 0i64;
          v32 = 0i64;
          v33 = 0i64;
          v34 = 0i64;
          transformOut.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
          transformOut.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
          transformOut.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          transformOut.m_translation = 0i64;
          v10 = v3->mPartDetails.mOffset;
          if ( v10 )
            v11 = (signed __int64)&v3->mPartDetails + v10;
          else
            v11 = 0i64;
          HIDWORD(v30) = *(_DWORD *)(v11 + v8 + 64);
          LODWORD(v30) = 1065353216;
          if ( v10 )
            v12 = (signed __int64)&v3->mPartDetails + v10;
          else
            v12 = 0i64;
          if ( v10 )
            v13 = (signed __int64)&v3->mPartDetails + v10;
          else
            v13 = 0i64;
          if ( v10 )
            v14 = (signed __int64)&v3->mPartDetails + v10;
          else
            v14 = 0i64;
          v32 = *(__m128 *)(v14 + v8 + 16);
          v33 = *(__m128 *)(v13 + v8 + 32);
          v15 = *(__m128 *)(v12 + v8 + 48);
          v16 = _mm_unpacklo_ps(v32, v33);
          v17 = _mm_shuffle_ps(_mm_unpackhi_ps(v32, v33), v15, 228);
          v32 = _mm_movelh_ps(v16, v15);
          v33 = _mm_shuffle_ps(_mm_movehl_ps(v32, v16), v15, 212);
          v34 = v17;
          if ( v10 )
            v18 = (signed __int64)&v3->mPartDetails + v10;
          else
            v18 = 0i64;
          v31 = *(_OWORD *)(v18 + v8);
          hkQsTransformf::copyToTransformNoScale(
            (hkQsTransformf *)(*(_QWORD *)(v7 + *(_QWORD *)&v9[1].m_type.m_storage) + 64i64),
            &transformOut);
          v19 = v28;
          if ( v28 == (v29 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 144);
            v19 = v28;
          }
          v20 = 144i64 * v19;
          v21 = &array[v20] == 0i64;
          v22 = (__int64)&array[v20];
          result = v22;
          v40 = v22;
          if ( !v21 )
          {
            *(_QWORD *)v22 = v30;
            *(_OWORD *)(v22 + 16) = v31;
            *(__m128 *)(v22 + 32) = v32;
            *(__m128 *)(v22 + 48) = v33;
            *(__m128 *)(v22 + 64) = v34;
            v23.m_quad = (__m128)transformOut.m_rotation.m_col1;
            v24.m_quad = (__m128)transformOut.m_rotation.m_col2;
            v25.m_quad = (__m128)transformOut.m_translation;
            *(hkVector4f *)(v22 + 80) = transformOut.m_rotation.m_col0;
            *(hkVector4f *)(v22 + 96) = (hkVector4f)v23.m_quad;
            *(hkVector4f *)(v22 + 112) = (hkVector4f)v24.m_quad;
            *(hkVector4f *)(v22 + 128) = (hkVector4f)v25.m_quad;
          }
          ++v28;
          fractureState = v39;
        }
        ++v5;
        v6 = __ROL4__(v6, 1);
        v8 += 96i64;
        v7 += 32i64;
      }
      while ( (signed int)v5 < SLODWORD(v9[1].m_userData) );
      v4 = 1;
      massProperties = v38;
    }
    if ( v28 )
      v4 = hkInertiaTensorComputer::combineMassProperties(
             (hkResult *)&result,
             (hkArray<hkMassElement,hkContainerHeapAllocator> *)&array,
             massProperties)->m_enum;
    v28 = 0;
    if ( v29 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        144 * (v29 & 0x3FFFFFFF));
    array = 0i64;
    v29 = 2147483648;
  }
  return v4 == 0;
}

// File Line: 811
// RVA: 0x97630
void __fastcall UFG::CollisionInstanceResource::CollisionInstanceResource(UFG::CollisionInstanceResource *this)
{
  UFG::CollisionInstanceResource *v1; // rbx
  unsigned __int64 v2; // rdx
  __int64 v3; // rax
  signed __int64 v4; // r9
  signed __int64 v5; // r10
  unsigned __int64 v6; // r9
  signed __int64 v7; // r8
  signed __int64 v8; // r9
  UFG::CollisionInstanceData *v9; // rcx
  signed __int64 v10; // rax
  unsigned int v11; // eax
  UFG::CollisionInstanceData::Part *v12; // rcx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = ((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64;
  v1->mData = (UFG::CollisionInstanceData **)v2;
  v3 = v1->mNumInstances;
  v4 = v2 + 8 * v3;
  v5 = 0i64;
  if ( (_DWORD)v3 )
  {
    do
    {
      v6 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
      v7 = v5;
      v1->mData[v5] = (UFG::CollisionInstanceData *)v6;
      v8 = v6 + 112;
      v9 = v1->mData[v5];
      v10 = 0i64;
      if ( v9->mNumParts )
        v10 = v8;
      v9->mParts = (UFG::CollisionInstanceData::Part *)v10;
      v11 = 0;
      if ( v1->mData[v7]->mNumParts )
      {
        do
        {
          v12 = &v1->mData[v7]->mParts[v11];
          v12->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mSimObject.mPrev;
          v12->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mSimObject.mPrev;
          ++v11;
        }
        while ( v11 < v1->mData[v7]->mNumParts );
      }
      v4 = 32i64 * v1->mData[v7]->mNumParts + v8;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < v1->mNumInstances );
  }
}

// File Line: 855
// RVA: 0x975F0
void __fastcall UFG::CollisionInstanceData::CollisionInstanceData(UFG::CollisionInstanceData *this)
{
  this->mPhysicsComponent = 0i64;
  this->mSimObjectName.mUID = -1;
  this->mNumParts = 0;
  this->mParts = 0i64;
  *(_QWORD *)&this->mFlags = 0i64;
  *(_QWORD *)&this->mCollisionModelGuid = 0i64;
  this->mOrientation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mInitialOrientation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mPosition = 0i64;
  this->mInitialPosition = 0i64;
}

// File Line: 888
// RVA: 0xB0540
void __fastcall UFG::CollisionInstanceData::Set(UFG::CollisionInstanceData *this, unsigned int guid, unsigned int flags, __int64 name, hkVector4f *pos, hkQuaternionf *orient, unsigned int collisionModelGuid)
{
  __m128 v7; // xmm0
  __m128 v8; // xmm1

  this->mPhysicsComponent = 0i64;
  this->mFlags = flags;
  this->mCollisionModelGuid = collisionModelGuid;
  this->mInstanceGuid = guid;
  this->mSimObjectName.mUID = *(_DWORD *)name;
  v7 = pos->m_quad;
  this->mPosition = (hkVector4f)pos->m_quad;
  this->mInitialPosition.m_quad = v7;
  v8 = orient->m_vec.m_quad;
  this->mOrientation = (hkQuaternionf)orient->m_vec.m_quad;
  this->mInitialOrientation.m_vec.m_quad = v8;
}

// File Line: 904
// RVA: 0xB2B70
UFG::CollisionInstanceData *__fastcall UFG::CollisionInstanceData::SplitInstanceUsingConnectivity(UFG::FractureConnectivity *graph, UFG::CollisionInstanceData *parent, hkTransformf *transform)
{
  hkTransformf *v3; // rsi
  UFG::CollisionInstanceData *v4; // rbp
  UFG::FractureConnectivity *v5; // r14
  unsigned int v6; // edi
  char *v7; // rax
  char *v8; // rbx
  hkVector4f v9; // xmm6
  signed __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r11
  signed __int64 v13; // rcx
  __int64 v14; // r9
  __int64 v15; // rdx
  _QWORD *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdx
  _QWORD *v19; // rax
  hkQuaternionf v21; // [rsp+40h] [rbp-48h]
  char *result; // [rsp+98h] [rbp+10h]
  __int64 v23; // [rsp+A0h] [rbp+18h]
  __int64 v24; // [rsp+A8h] [rbp+20h]

  v3 = transform;
  v4 = parent;
  v5 = graph;
  if ( parent->mNumParts )
    v6 = graph->mNodes.size;
  else
    v6 = 0;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 32 * v6 + 112, "CollisionInstanceData1", 0i64, 1u);
  v8 = v7;
  result = v7;
  v23 = (__int64)v7;
  if ( v7 )
  {
    *((_QWORD *)v7 + 8) = 0i64;
    *((_DWORD *)v7 + 18) = -1;
    *((_DWORD *)v7 + 19) = 0;
    *((_QWORD *)v7 + 10) = 0i64;
    *((_QWORD *)v7 + 11) = 0i64;
    *((_QWORD *)v7 + 12) = 0i64;
    *(hkQuaternionf *)v7 = (hkQuaternionf)qi.m_vec.m_quad;
    *((hkQuaternionf *)v7 + 1) = (hkQuaternionf)qi.m_vec.m_quad;
    *((_OWORD *)v7 + 2) = 0i64;
    *((_OWORD *)v7 + 3) = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  v9.m_quad = (__m128)v3->m_translation;
  hkQuaternionf::set(&v21, &v3->m_rotation);
  *((hkVector4f *)v8 + 2) = (hkVector4f)v9.m_quad;
  *((hkVector4f *)v8 + 3) = (hkVector4f)v9.m_quad;
  *(hkQuaternionf *)v8 = (hkQuaternionf)v21.m_vec.m_quad;
  *((hkQuaternionf *)v8 + 1) = (hkQuaternionf)v21.m_vec.m_quad;
  *((_QWORD *)v8 + 8) = 0i64;
  *((UFG::qSymbol *)v8 + 18) = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                               (UFG::qSymbol *)&result,
                                               "SplitInstanceUsingConnectivity")->mUID;
  *((_DWORD *)v8 + 19) = v6;
  *((_QWORD *)v8 + 11) = 0i64;
  *((_QWORD *)v8 + 12) = 0i64;
  v10 = (signed __int64)(v8 + 112);
  result = v8 + 112;
  *((_QWORD *)v8 + 10) = v8 + 112;
  if ( v6 )
  {
    v11 = 0i64;
    v12 = v6;
    do
    {
      v13 = (signed __int64)&v4->mParts[v5->mNodes.p[v11]->partIdx];
      v23 = v10;
      if ( v10 )
      {
        v24 = v10;
        *(_QWORD *)v10 = v10;
        *(_QWORD *)(v10 + 8) = v10;
        *(_QWORD *)(v10 + 16) = 0i64;
        *(_DWORD *)(v10 + 24) = -1;
      }
      *(_DWORD *)(v10 + 28) = *(_DWORD *)(v13 + 28);
      v14 = *(_QWORD *)(v13 + 16);
      if ( *(_QWORD *)(v10 + 16) )
      {
        v15 = *(_QWORD *)v10;
        v16 = *(_QWORD **)(v10 + 8);
        *(_QWORD *)(v15 + 8) = v16;
        *v16 = v15;
        *(_QWORD *)v10 = v10;
        *(_QWORD *)(v10 + 8) = v10;
      }
      *(_QWORD *)(v10 + 16) = v14;
      if ( v14 )
      {
        v17 = *(_QWORD *)(v14 + 8);
        *(_QWORD *)(v17 + 8) = v10;
        *(_QWORD *)v10 = v17;
        *(_QWORD *)(v10 + 8) = v14 + 8;
        *(_QWORD *)(v14 + 8) = v10;
      }
      if ( *(_QWORD *)(v13 + 16) )
      {
        v18 = *(_QWORD *)v13;
        v19 = *(_QWORD **)(v13 + 8);
        *(_QWORD *)(v18 + 8) = v19;
        *v19 = v18;
        *(_QWORD *)v13 = v13;
        *(_QWORD *)(v13 + 8) = v13;
      }
      *(_QWORD *)(v13 + 16) = 0i64;
      *(_DWORD *)(v10 + 24) = *(_DWORD *)(v13 + 24);
      v10 += 32i64;
      result = (char *)v10;
      ++v11;
      --v12;
    }
    while ( v12 );
  }
  return (UFG::CollisionInstanceData *)v8;
}

// File Line: 987
// RVA: 0xA9680
UFG::BaseProperty *__fastcall UFG::GetBaseProperty(hkpShape *shape, unsigned int key)
{
  signed int v2; // er9
  unsigned __int64 v3; // r8
  signed int v4; // edx
  UFG::BaseProperty *result; // rax

  v2 = key;
  if ( key == -1 )
    return 0i64;
  if ( shape->m_type.m_storage != 9 )
    return 0i64;
  v3 = shape[2].m_userData;
  if ( !v3 || (*(_BYTE *)(v3 + 41) - 1) & 0xFD )
    return 0i64;
  v4 = (key & 0x7FFFFFFF) >> (32 - *(_BYTE *)(v3 + 232));
  if ( v2 < 0 )
    result = *(UFG::BaseProperty **)(*(_QWORD *)(v3 + 256) + 80i64 * v4 + 16);
  else
    result = *(UFG::BaseProperty **)(*(_QWORD *)(v3 + 240) + 144i64 * v4 + 16);
  return result;
}

// File Line: 1022
// RVA: 0xAB6B0
void __fastcall UFG::GetTransformFromShapeKey(hkTransformf *transformOut, hkpShape *shape, unsigned int key)
{
  char v3; // al

  v3 = shape->m_type.m_storage;
  if ( v3 == 9 )
  {
    hkQsTransformf::copyToTransformNoScale(
      (hkQsTransformf *)(*(_QWORD *)(*(_QWORD *)(shape[2].m_userData + 48) + 32i64 * (signed int)key) + 64i64),
      transformOut);
  }
  else if ( v3 == 8 )
  {
    hkQsTransformf::copyToTransformNoScale(
      (hkQsTransformf *)(*(_QWORD *)(32i64 * (signed int)key + *(_QWORD *)&shape[1].m_type.m_storage) + 64i64),
      transformOut);
  }
}

// File Line: 1046
// RVA: 0xA9500
void __fastcall UFG::GetAabbFromShapeKey(hkAabb *aabbOut, hkTransformf *localToWorld, hkpShape *shape, unsigned int key)
{
  char v4; // al

  v4 = shape->m_type.m_storage;
  if ( v4 == 9 )
  {
    (*(void (__fastcall **)(_QWORD, hkTransformf *, signed __int64, hkAabb *))(**(_QWORD **)(32i64 * (signed int)key
                                                                                           + *(_QWORD *)(shape[2].m_userData + 48))
                                                                             + 32i64))(
      *(_QWORD *)(32i64 * (signed int)key + *(_QWORD *)(shape[2].m_userData + 48)),
      localToWorld,
      32i64 * (signed int)key,
      aabbOut);
  }
  else if ( v4 == 8 )
  {
    (*(void (__fastcall **)(_QWORD, hkTransformf *, hkpShape *, hkAabb *))(**(_QWORD **)(32i64 * (signed int)key
                                                                                       + *(_QWORD *)&shape[1].m_type.m_storage)
                                                                         + 32i64))(
      *(_QWORD *)(32i64 * (signed int)key + *(_QWORD *)&shape[1].m_type.m_storage),
      localToWorld,
      shape,
      aabbOut);
  }
}

