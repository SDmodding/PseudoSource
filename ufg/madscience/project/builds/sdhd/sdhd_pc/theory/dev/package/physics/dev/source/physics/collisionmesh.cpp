// File Line: 56
// RVA: 0x1458480
__int64 dynamic_initializer_for__UFG::CollisionMeshData::mDeferredBreakableList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CollisionMeshData::mDeferredBreakableList__);
}

// File Line: 70
// RVA: 0x97710
void __fastcall UFG::CollisionMeshBundle::CollisionMeshBundle(UFG::CollisionMeshBundle *this)
{
  __int64 mNumMeshes; // rdx
  UFG::CollisionMeshData **v3; // rax
  UFG::CollisionMeshData **v4; // rdi
  __int64 v5; // rbx
  char v6; // dl
  char v7; // cl
  char *v8; // rdi
  char *v9; // rax
  char v10; // al
  char *v11; // rdi
  unsigned int i; // ebx
  UFG::CollisionMeshData *v13; // rdi
  UFG::CollisionMeshData *v14; // rax
  UFG::CollisionMeshData *v15; // rcx

  UFG::qResourceData::qResourceData(this);
  this->mMeshIndices = (unsigned __int16 *)&this[1];
  mNumMeshes = this->mNumMeshes;
  v3 = (UFG::CollisionMeshData **)((char *)&this[1] + 2 * mNumMeshes);
  this->mCollisionMeshData = v3;
  v4 = &v3[mNumMeshes];
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v6) = 3;
  *(_QWORD *)(v5 + 8i64 * v6 + 16) = "CollisionPackfile";
  *(_QWORD *)(v5 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v5 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v5 + 81) = v7;
  v8 = (char *)(((unsigned __int64)v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::Fixups", 0i64, 1u);
  if ( v9 )
  {
    *(_QWORD *)v9 = 0i64;
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 3) = 0x80000000;
    *((_QWORD *)v9 + 2) = 0i64;
    *((_DWORD *)v9 + 6) = 0;
    *((_DWORD *)v9 + 7) = 0x80000000;
  }
  else
  {
    v9 = 0i64;
  }
  this->mHavokPackfile = v9;
  this->mListShape = (hkpListShape *)UFG::NativePackfileUtils::loadInPlace(
                                       v8,
                                       this->mHavokPackfileSize,
                                       (UFG::NativePackfileUtils::Fixups *)v9);
  v10 = *(_BYTE *)(v5 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v10 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v11 = &v8[this->mHavokPackfileSize];
  for ( i = 0; i < this->mNumMeshes; ++i )
  {
    v13 = (UFG::CollisionMeshData *)((unsigned __int64)(v11 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
    if ( v13 )
    {
      UFG::CollisionMeshData::CollisionMeshData(
        v13,
        0,
        this->mListShape->m_childInfo.m_data[this->mMeshIndices[i]].m_shape);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    this->mCollisionMeshData[i] = v15;
    v11 = (char *)v13 + this->mCollisionMeshData[i]->mSize;
  }
}

// File Line: 107
// RVA: 0x9BC90
void __fastcall UFG::CollisionMeshBundle::~CollisionMeshBundle(UFG::CollisionMeshBundle *this)
{
  int v2; // edi
  unsigned int i; // ebx
  UFG::CollisionMeshData *v4; // rsi
  hkReferencedObject *mShape; // rcx
  unsigned __int64 v6; // rdx
  UFG::NativePackfileUtils::Fixups *mHavokPackfile; // rbx
  int v8; // r8d
  __int64 v9; // rdx
  __int64 v10; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v14; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v15; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax

  v2 = 0;
  for ( i = 0; i < this->mNumMeshes; ++i )
  {
    v4 = this->mCollisionMeshData[i];
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::BasePhysicsSystem::mInstance->mCollisionModels,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4);
    mShape = v4->mShape;
    if ( mShape )
      hkReferencedObject::removeReference(mShape);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v4->mObjectProperties);
  }
  v6 = ((unsigned __int64)&this[1].mNode.mChild[this->mNumMeshes] + 2 * this->mNumMeshes + 7) & 0xFFFFFFFFFFFFFFF0ui64;
  mHavokPackfile = (UFG::NativePackfileUtils::Fixups *)this->mHavokPackfile;
  *(_DWORD *)(v6 + 0x38) &= ~1u;
  v8 = 0;
  if ( mHavokPackfile->zeroFixups.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      *(_DWORD *)mHavokPackfile->zeroFixups.m_data[v9] = 0;
      ++v8;
      ++v9;
    }
    while ( v8 < mHavokPackfile->zeroFixups.m_size );
  }
  if ( mHavokPackfile->nonZeroFixups.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      *(_DWORD *)mHavokPackfile->nonZeroFixups.m_data[v10].addr = mHavokPackfile->nonZeroFixups.m_data[v10].val;
      ++v2;
      ++v10;
    }
    while ( v2 < mHavokPackfile->nonZeroFixups.m_size );
  }
  UFG::NativePackfileUtils::Fixups::~Fixups(mHavokPackfile);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mHavokPackfile);
  p_mResourceHandles = &this->mResourceHandles;
  mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( mNext != (UFG::qResourceHandle *)&this->mResourceHandles )
  {
    do
    {
      mPrev = mNext->mPrev;
      v14 = mNext->mNext;
      mPrev->mNext = v14;
      v14->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qResourceHandle::~qResourceHandle(mNext);
      operator delete[](mNext);
      mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    while ( mNext != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v15 = p_mResourceHandles->mNode.mPrev;
  v16 = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 139
// RVA: 0x97AD0
void __fastcall UFG::CollisionMeshData::CollisionMeshData(UFG::CollisionMeshData *this)
{
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *p_mObjectProperties; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  *(_QWORD *)&this->mSceneNodeName.mUID = -1i64;
  this->mFlags = 0;
  this->mName.mUID = -1;
  p_mObjectProperties = &this->mObjectProperties;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mObjectProperties);
  p_mObjectProperties->mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 150
// RVA: 0x978C0
void __fastcall UFG::CollisionMeshData::CollisionMeshData(
        UFG::CollisionMeshData *this,
        MemImageLoadFlag f,
        hkpShape *shape)
{
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *p_mObjectProperties; // rdi
  unsigned __int64 m_userData; // rdi
  unsigned int v6; // r11d
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 mOffset; // rax
  char *v10; // r9
  __int64 v11; // rax
  char *v12; // rcx
  __int64 v13; // r10
  __int64 v14; // rax
  char *v15; // r9
  __int64 v16; // rax
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // rax
  char *v20; // rax
  UFG::FractureConnectivity *v21; // rdi

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mShape = shape;
  this->mRemoveTerminalsMoppModifierList = 0i64;
  p_mObjectProperties = &this->mObjectProperties;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mObjectProperties);
  p_mObjectProperties->mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(p_mObjectProperties, p_mObjectProperties->mTypeUID, this->mPropertiesHandleGuid);
  if ( !this->mObjectProperties.mData )
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties(p_mObjectProperties);
  if ( !this->mGeometryType )
  {
    m_userData = this->mShape[2].m_userData;
    v6 = 0;
    if ( this->mNumParts )
    {
      v7 = 0i64;
      do
      {
        v8 = *(_QWORD *)(m_userData + 240);
        mOffset = this->mVertexBuffer.mOffset;
        if ( mOffset )
          v10 = (char *)&this->mVertexBuffer + mOffset;
        else
          v10 = 0i64;
        v11 = this->mParts.mOffset;
        if ( v11 )
          v12 = (char *)&this->mParts + v11;
        else
          v12 = 0i64;
        v13 = 48i64 * v6;
        *(_QWORD *)(v7 + v8 + 40) = &v10[12 * *(unsigned int *)&v12[v13 + 32]];
        v14 = this->mIndexBuffer.mOffset;
        if ( v14 )
          v15 = (char *)&this->mIndexBuffer + v14;
        else
          v15 = 0i64;
        v16 = this->mParts.mOffset;
        if ( v16 )
          v17 = (char *)&this->mParts + v16;
        else
          v17 = 0i64;
        *(_QWORD *)(v7 + v8 + 56) = &v15[2 * *(unsigned int *)&v17[v13 + 36]];
        *(_WORD *)(v7 + v8) &= 7u;
        *(_WORD *)(v7 + v8) |= 8u;
        v18 = this->mParts.mOffset;
        if ( v18 )
          v19 = (char *)&this->mParts + v18;
        else
          v19 = 0i64;
        *(_QWORD *)(v7 + v8 + 16) = &v19[v13];
        ++v6;
        v7 += 144i64;
      }
      while ( v6 < this->mNumParts );
    }
  }
  if ( HIDWORD(this->mObjectProperties.mData[2].mBaseNode.mNeighbours[1]) == 1 )
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
    UFG::FractureConnectivity::Build(v21, this);
    this->mFractureConnectivity = v21;
  }
  UFG::qBaseTreeRB::Add(&UFG::BasePhysicsSystem::mInstance->mCollisionModels.mTree, &this->mNode);
}

// File Line: 242
// RVA: 0xAA240
void __fastcall UFG::CollisionMeshData::GetInertiaTensor(
        UFG::CollisionMeshData *this,
        hkMatrix3f *I,
        float massFudgeFactor)
{
  __m128 v3; // xmm10
  __m128 z_low; // xmm4
  __m128 v5; // xmm7
  __m128 x_low; // xmm6
  __m128 y_low; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  hkVector4f v14; // xmm2
  hkVector4f v15; // xmm0

  z_low = (__m128)LODWORD(this->mInertiaTensorRow1.z);
  v5 = (__m128)LODWORD(this->mInertiaTensorRow2.z);
  x_low = (__m128)LODWORD(this->mInertiaTensorRow1.x);
  y_low = (__m128)LODWORD(this->mInertiaTensorRow2.y);
  v8 = (__m128)LODWORD(this->mInertiaTensorRow2.x);
  v3.m128_f32[0] = massFudgeFactor;
  v9 = _mm_shuffle_ps(v3, v3, 0);
  v10 = _mm_unpacklo_ps((__m128)LODWORD(this->mInertiaTensorRow1.y), (__m128)0i64);
  I->m_col0.m_quad = _mm_mul_ps(
                       _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(this->mInertiaTensorRow0.x),
                           (__m128)LODWORD(this->mInertiaTensorRow0.z)),
                         _mm_unpacklo_ps((__m128)LODWORD(this->mInertiaTensorRow0.y), (__m128)0i64)),
                       v9);
  v11 = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), v10), v9);
  v12 = _mm_unpacklo_ps(I->m_col0.m_quad, v11);
  v13 = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v8, v5), _mm_unpacklo_ps(y_low, (__m128)0i64)), v9);
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
void __fastcall UFG::CollisionMeshData::MarkBreakableParts(
        UFG::CollisionMeshData *this,
        UFG::RigidBody *body,
        float timeDelay)
{
  __int64 mOffset; // rax
  UFG::Destruction *v6; // rbp
  unsigned int i; // ebx
  __int64 v8; // rax
  char *v9; // rcx
  __int64 v10; // rdx
  char *v11; // rax
  char *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v17; // rax

  mOffset = this->mPartDetails.mOffset;
  if ( mOffset && (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + mOffset) )
  {
    if ( timeDelay > 0.0 )
    {
      v11 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      v12 = v11;
      if ( v11 )
      {
        *(_QWORD *)v11 = v11;
        *((_QWORD *)v11 + 1) = v11;
        *((_QWORD *)v11 + 2) = v11 + 16;
        *((_QWORD *)v11 + 3) = v11 + 16;
        *((_QWORD *)v11 + 4) = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
      v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v12 + 16);
      if ( *((_QWORD *)v12 + 4) )
      {
        mPrev = v13->mPrev;
        v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)*((_QWORD *)v12 + 3);
        mPrev->mNext = v15;
        v15->mPrev = mPrev;
        v13->mPrev = v13;
        *((_QWORD *)v12 + 3) = v12 + 16;
      }
      *((_QWORD *)v12 + 4) = body;
      if ( body )
      {
        v16 = body->m_SafePointerList.mNode.mPrev;
        v16->mNext = v13;
        v13->mPrev = v16;
        *((_QWORD *)v12 + 3) = &body->m_SafePointerList;
        body->m_SafePointerList.mNode.mPrev = v13;
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
      for ( i = 0; i < this->mNumParts; ++i )
      {
        v8 = this->mPartDetails.mOffset;
        if ( v8 )
        {
          v9 = (char *)&this->mPartDetails + v8;
          if ( v9 )
          {
            v10 = 96i64 * i;
            if ( *(float *)&v9[v10 + 68] > 0.0 && *(_DWORD *)&v9[v10 + 76] != -1 )
              hkpBreakOffPartsUtil::markPieceBreakable(v6->mBreakOffPartsUtil, body->mBody, i, *(float *)&v9[v10 + 68]);
          }
        }
      }
    }
  }
}

// File Line: 327
// RVA: 0xB4400
void __fastcall UFG::CollisionMeshData::UnmarkBreakableParts(UFG::CollisionMeshData *this, hkpEntity *entity)
{
  __int64 mOffset; // rax
  __int64 v5; // rbx
  UFG::Destruction *i; // rsi
  __int64 v7; // rax
  char *v8; // rdx

  mOffset = this->mPartDetails.mOffset;
  if ( mOffset )
  {
    if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + mOffset) )
    {
      v5 = 0i64;
      for ( i = UFG::Destruction::mInstance; (unsigned int)v5 < this->mNumParts; v5 = (unsigned int)(v5 + 1) )
      {
        v7 = this->mPartDetails.mOffset;
        if ( v7 )
        {
          v8 = (char *)&this->mPartDetails + v7;
          if ( v8 )
          {
            if ( *(float *)&v8[96 * v5 + 68] > 0.0 )
              hkpBreakOffPartsUtil::unmarkPieceBreakable(i->mBreakOffPartsUtil, entity, v5);
          }
        }
      }
    }
  }
}

// File Line: 345
// RVA: 0xAFE30
void __fastcall UFG::CollisionMeshData::ResetFracture(UFG::CollisionMeshData *this)
{
  __int64 mOffset; // rax
  hkpListShape *mShape; // rdi
  unsigned int v4; // ecx
  unsigned int i; // ebx
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *mRemoveTerminalsMoppModifierList; // rdi
  hkpShape *v7; // rbp
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v9; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v13; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v14; // rax
  UFG::FractureConnectivity *mFractureConnectivity; // rbx
  UFG::FractureConnectivity::Node **p; // rcx
  UFG::FractureConnectivity *v17; // rax

  mOffset = this->mPartDetails.mOffset;
  if ( !mOffset || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&this->mPartDetails + mOffset) )
    goto LABEL_17;
  mShape = (hkpListShape *)this->mShape;
  v4 = this->mGeometryType - 3;
  if ( !v4 )
  {
    mShape = (hkpListShape *)mShape->m_aabbHalfExtents.m_quad.m128_u64[1];
LABEL_7:
    if ( mShape )
    {
      for ( i = 0; (signed int)i < mShape->m_childInfo.m_size; ++i )
      {
        if ( i < 0x100 && (mShape->m_enabledChildren[(unsigned __int64)i >> 5] & (1 << (i & 0x1F))) == 0 )
          hkpListShape::enableChild(mShape, i);
      }
    }
    goto LABEL_13;
  }
  if ( v4 == 1 )
    goto LABEL_7;
LABEL_13:
  mRemoveTerminalsMoppModifierList = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this->mRemoveTerminalsMoppModifierList;
  if ( mRemoveTerminalsMoppModifierList )
  {
    v7 = this->mShape;
    while ( (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)mRemoveTerminalsMoppModifierList->mNode.mNext != mRemoveTerminalsMoppModifierList )
    {
      mPrev = mRemoveTerminalsMoppModifierList->mNode.mPrev;
      v9 = mRemoveTerminalsMoppModifierList->mNode.mPrev->mPrev;
      mNext = mRemoveTerminalsMoppModifierList->mNode.mPrev->mNext;
      v9->mNext = mNext;
      mNext->mPrev = v9;
      mPrev->mPrev = mPrev;
      mPrev->mNext = mPrev;
      hkpRemoveTerminalsMoppModifier::undoRemoveTerminals(
        (hkpRemoveTerminalsMoppModifier *)mPrev[1].mPrev,
        *(hkpMoppCode **)&v7[1].m_memSizeAndFlags);
      hkReferencedObject::removeReference((hkReferencedObject *)mPrev[1].mPrev);
      v11 = mPrev->mPrev;
      v12 = mPrev->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      mPrev->mPrev = mPrev;
      mPrev->mNext = mPrev;
      operator delete[](mPrev);
    }
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(mRemoveTerminalsMoppModifierList);
    v13 = mRemoveTerminalsMoppModifierList->mNode.mPrev;
    v14 = mRemoveTerminalsMoppModifierList->mNode.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    mRemoveTerminalsMoppModifierList->mNode.mPrev = &mRemoveTerminalsMoppModifierList->mNode;
    mRemoveTerminalsMoppModifierList->mNode.mNext = &mRemoveTerminalsMoppModifierList->mNode;
    operator delete[](mRemoveTerminalsMoppModifierList);
    this->mRemoveTerminalsMoppModifierList = 0i64;
  }
LABEL_17:
  if ( HIDWORD(this->mObjectProperties.mData[2].mBaseNode.mNeighbours[1]) == 1 )
  {
    mFractureConnectivity = this->mFractureConnectivity;
    if ( mFractureConnectivity )
    {
      p = mFractureConnectivity->mNodes.p;
      if ( p )
        operator delete[](p);
      mFractureConnectivity->mNodes.p = 0i64;
      *(_QWORD *)&mFractureConnectivity->mNodes.size = 0i64;
      operator delete[](mFractureConnectivity);
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
    this->mFractureConnectivity = v17;
    UFG::FractureConnectivity::Build(v17, this);
  }
}

// File Line: 422
// RVA: 0xA0940
void __fastcall UFG::CollisionMeshData::AddMoppTerminalModifier(
        UFG::CollisionMeshData *this,
        hkpRemoveTerminalsMoppModifier *modifier)
{
  char *v4; // rax
  __int64 *mRemoveTerminalsMoppModifierList; // rdi
  char *v6; // rax
  char *v7; // rbx
  __int64 v8; // rax

  if ( !this->mRemoveTerminalsMoppModifierList )
  {
    v4 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
    if ( v4 )
    {
      *(_QWORD *)v4 = v4;
      *((_QWORD *)v4 + 1) = v4;
    }
    this->mRemoveTerminalsMoppModifierList = v4;
  }
  mRemoveTerminalsMoppModifierList = (__int64 *)this->mRemoveTerminalsMoppModifierList;
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
  *((_QWORD *)v7 + 2) = modifier;
  hkReferencedObject::addReference(modifier);
  v8 = *mRemoveTerminalsMoppModifierList;
  *(_QWORD *)(v8 + 8) = v7;
  *(_QWORD *)v7 = v8;
  *((_QWORD *)v7 + 1) = mRemoveTerminalsMoppModifierList;
  *mRemoveTerminalsMoppModifierList = (__int64)v7;
}

// File Line: 452
// RVA: 0xB2D80
UFG::CollisionMeshData *__fastcall UFG::CollisionMeshData::SplitMeshUsingConnectivity(
        UFG::FractureConnectivity *graph,
        UFG::CollisionMeshData *parent,
        hkTransformf *transform)
{
  hkTransformf *v3; // r13
  unsigned int size; // ebx
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdi
  UFG::FractureConnectivity *v10; // rax
  hkpShape *mShape; // rax
  char m_storage; // cl
  hkpShape *m_userData; // r15
  hkLifoAllocator *Value; // r8
  int v15; // edx
  hkpShape **m_cur; // rax
  char *v17; // rcx
  unsigned int v18; // ebx
  int v19; // r8d
  hkpShape *v20; // r12
  int v21; // r15d
  __int64 v22; // rbx
  hkpShape *v23; // r13
  _QWORD **v24; // rax
  hkpConvexTransformShape *v25; // rax
  hkpShape *v26; // rax
  hkpShape *v27; // rcx
  _QWORD **v28; // rax
  hkpListShape *v29; // rax
  hkpShape *v30; // rax
  __int64 v31; // rbx
  __int64 *v32; // r9
  __int64 v33; // rax
  unsigned int i; // r8d
  __int64 mOffset; // rax
  char *v36; // rdx
  char *v37; // rcx
  __int64 v38; // rdx
  char *v39; // r8
  unsigned __int64 v40; // r8
  __int64 *v41; // rcx
  __int64 v42; // rax
  unsigned int j; // r8d
  __int64 v44; // rax
  char *v45; // rdx
  char *v46; // rcx
  __int64 v47; // rdx
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  float y; // xmm1_4
  float z; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  char *v60; // rsi
  int v61; // ecx
  int v62; // ebx
  hkLifoAllocator *v63; // rax
  signed int v64; // ebx
  int v65; // r8d
  hkpShape **array; // [rsp+30h] [rbp-D0h] BYREF
  int numShapes; // [rsp+38h] [rbp-C8h]
  int v69; // [rsp+3Ch] [rbp-C4h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v71; // [rsp+48h] [rbp-B8h]
  hkMassProperties massProperties; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v73; // [rsp+A0h] [rbp-60h]
  hkTransformf v74; // [rsp+B0h] [rbp-50h] BYREF
  hkTransformf bTc; // [rsp+F0h] [rbp-10h] BYREF
  hkTransformf transformOut; // [rsp+130h] [rbp+30h] BYREF
  hkTransformf aTb; // [rsp+170h] [rbp+70h] BYREF
  __int64 result; // [rsp+1F0h] [rbp+F0h] BYREF
  char *v79; // [rsp+1F8h] [rbp+F8h]
  hkTransformf *v80; // [rsp+200h] [rbp+100h]

  v80 = transform;
  v73 = -2i64;
  v3 = transform;
  size = graph->mNodes.size;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 144 * graph->mNodes.size + 272, "CollisionMeshData1", 0i64, 1u);
  result = (__int64)v7;
  v79 = v7;
  if ( v7 )
  {
    UFG::CollisionMeshData::CollisionMeshData((UFG::CollisionMeshData *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_DWORD *)(v9 + 40) = parent->mBundleGuid;
  *(_DWORD *)(v9 + 48) = parent->mNumVertices;
  *(_DWORD *)(v9 + 52) = parent->mNumIndices;
  *(_DWORD *)(v9 + 76) = parent->mRenderModelGuid;
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
  if ( size > 1 )
    v10 = graph;
  *(_QWORD *)(v9 + 208) = v10;
  *(_DWORD *)(v9 + 56) = size;
  *(_DWORD *)(v9 + 60) = 0;
  mShape = parent->mShape;
  m_storage = mShape->m_type.m_storage;
  if ( m_storage == 9 )
  {
    m_userData = (hkpShape *)mShape[2].m_userData;
  }
  else
  {
    m_userData = 0i64;
    if ( m_storage == 8 )
      m_userData = parent->mShape;
  }
  array = 0i64;
  numShapes = 0;
  v69 = 0x80000000;
  v71 = size;
  if ( size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (((8 * size + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    m_cur = (hkpShape **)Value->m_cur;
    v17 = (char *)m_cur + v15;
    if ( v15 > Value->m_slabSize || v17 > Value->m_end )
      m_cur = (hkpShape **)hkLifoAllocator::allocateFromNewSlab(Value, v15);
    else
      Value->m_cur = v17;
  }
  else
  {
    m_cur = 0i64;
  }
  array = m_cur;
  v69 = size | 0x80000000;
  p = m_cur;
  v18 = 0;
  if ( graph->mNodes.size )
  {
    v19 = numShapes;
    do
    {
      v20 = *(hkpShape **)(32i64 * graph->mNodes.p[v18]->partIdx + *(_QWORD *)&m_userData[1].m_type.m_storage);
      if ( v19 == (v69 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
        v19 = numShapes;
      }
      array[v19] = v20;
      v19 = ++numShapes;
      ++v18;
    }
    while ( v18 < graph->mNodes.size );
  }
  hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&(*array)[2], &transformOut);
  hkTransformf::setMul(&v74, v3, &transformOut);
  hkTransformf::setInverse(&aTb, &transformOut);
  v21 = 0;
  if ( numShapes > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = array[v22];
      hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&v23[2], &bTc);
      hkTransformf::setMul(&bTc, &aTb, &bTc);
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (hkpConvexTransformShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v24[11] + 8i64))(v24[11], 128i64);
      result = (__int64)v25;
      if ( v25 )
      {
        hkpConvexTransformShape::hkpConvexTransformShape(
          v25,
          *(hkpConvexShape **)&v23[1].m_type.m_storage,
          &bTc,
          REFERENCE_POLICY_INCREMENT);
        v27 = v26;
      }
      else
      {
        v27 = 0i64;
      }
      array[v22] = v27;
      ++v21;
      ++v22;
    }
    while ( v21 < numShapes );
    v3 = v80;
  }
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 144i64);
  v80 = (hkTransformf *)v29;
  if ( v29 )
    hkpListShape::hkpListShape(v29, array, numShapes, REFERENCE_POLICY_INCREMENT);
  else
    v30 = 0i64;
  *(_QWORD *)(v9 + 192) = v30;
  *(_DWORD *)(v9 + 64) = (unsigned __int8)hkpShapeDepthUtil::getShapeDepth(v30);
  v31 = v9 + 272;
  v80 = (hkTransformf *)(v9 + 272);
  v32 = (__int64 *)(v9 + 152);
  if ( v9 == -272 )
    v33 = 0i64;
  else
    v33 = v31 - (_QWORD)v32;
  *v32 = v33;
  for ( i = 0; i < graph->mNodes.size; ++i )
  {
    mOffset = parent->mParts.mOffset;
    if ( mOffset )
      v36 = (char *)&parent->mParts + mOffset;
    else
      v36 = 0i64;
    v37 = &v36[48 * graph->mNodes.p[i]->partIdx];
    result = v31;
    if ( v31 )
    {
      *(_DWORD *)v31 = 0;
      v38 = v31;
    }
    else
    {
      v38 = 0i64;
    }
    *(_DWORD *)v38 = *(_DWORD *)v37;
    *(_DWORD *)(v38 + 4) = *((_DWORD *)v37 + 1);
    *(_QWORD *)(v38 + 8) = *((_QWORD *)v37 + 1);
    *(_QWORD *)(v38 + 16) = *((_QWORD *)v37 + 2);
    *(_DWORD *)(v38 + 24) = *((_DWORD *)v37 + 6);
    *(_DWORD *)(v38 + 28) = *((_DWORD *)v37 + 7);
    *(_DWORD *)(v38 + 36) = *((_DWORD *)v37 + 9);
    *(_DWORD *)(v38 + 32) = *((_DWORD *)v37 + 8);
    v31 += 48i64;
    v80 = (hkTransformf *)v31;
  }
  v39 = (char *)v32 + *v32;
  if ( !*v32 )
    v39 = 0i64;
  v40 = *((_QWORD *)v39 + 2);
  *(_QWORD *)(v9 + 32) = v40;
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v9 + 224), *(_QWORD *)(v9 + 240), v40);
  v41 = (__int64 *)(v9 + 160);
  if ( v31 )
    v42 = v31 - (_QWORD)v41;
  else
    v42 = 0i64;
  *v41 = v42;
  for ( j = 0; j < graph->mNodes.size; ++j )
  {
    v44 = parent->mPartDetails.mOffset;
    if ( v44 )
      v45 = (char *)&parent->mPartDetails + v44;
    else
      v45 = 0i64;
    v46 = &v45[96 * graph->mNodes.p[j]->partIdx];
    result = v31;
    if ( v31 )
    {
      *(_DWORD *)(v31 + 72) = -1;
      *(_QWORD *)(v31 + 84) = -1i64;
      v47 = v31;
    }
    else
    {
      v47 = 0i64;
    }
    *(_DWORD *)(v47 + 84) = *((_DWORD *)v46 + 21);
    *(_DWORD *)(v47 + 88) = *((_DWORD *)v46 + 22);
    *(_DWORD *)(v47 + 76) = *((_DWORD *)v46 + 19);
    *(_DWORD *)(v47 + 72) = *((_DWORD *)v46 + 18);
    *(_DWORD *)(v47 + 80) = *((_DWORD *)v46 + 20);
    *(_DWORD *)(v47 + 68) = *((_DWORD *)v46 + 17);
    *(_OWORD *)v47 = *(_OWORD *)v46;
    *(_OWORD *)(v47 + 16) = *((_OWORD *)v46 + 1);
    *(_OWORD *)(v47 + 32) = *((_OWORD *)v46 + 2);
    *(_OWORD *)(v47 + 48) = *((_OWORD *)v46 + 3);
    *(_DWORD *)(v47 + 64) = *((_DWORD *)v46 + 16);
    v31 += 96i64;
    v80 = (hkTransformf *)v31;
  }
  *(_QWORD *)&massProperties.m_volume = 0i64;
  memset(&massProperties.m_centerOfMass, 0, 64);
  if ( UFG::CollisionMeshData::ComputeMassProperties((UFG::CollisionMeshData *)v9, &massProperties, 0i64) )
  {
    *(float *)(v9 + 144) = massProperties.m_mass;
    v48 = _mm_unpacklo_ps(massProperties.m_inertiaTensor.m_col0.m_quad, massProperties.m_inertiaTensor.m_col1.m_quad);
    v49 = _mm_shuffle_ps(
            _mm_unpackhi_ps(massProperties.m_inertiaTensor.m_col0.m_quad, massProperties.m_inertiaTensor.m_col1.m_quad),
            massProperties.m_inertiaTensor.m_col2.m_quad,
            228);
    v50 = _mm_movelh_ps(v48, massProperties.m_inertiaTensor.m_col2.m_quad);
    v51 = _mm_shuffle_ps(_mm_movehl_ps(v50, v48), massProperties.m_inertiaTensor.m_col2.m_quad, 212);
    *(_DWORD *)(v9 + 108) = v50.m128_i32[0];
    *(_DWORD *)(v9 + 112) = _mm_shuffle_ps(v50, v50, 85).m128_u32[0];
    *(_DWORD *)(v9 + 116) = _mm_shuffle_ps(v50, v50, 170).m128_u32[0];
    *(_DWORD *)(v9 + 120) = v51.m128_i32[0];
    *(_DWORD *)(v9 + 124) = _mm_shuffle_ps(v51, v51, 85).m128_u32[0];
    *(_DWORD *)(v9 + 128) = _mm_shuffle_ps(v51, v51, 170).m128_u32[0];
    *(_DWORD *)(v9 + 132) = v49.m128_i32[0];
    *(_DWORD *)(v9 + 136) = _mm_shuffle_ps(v49, v49, 85).m128_u32[0];
    *(_DWORD *)(v9 + 140) = _mm_shuffle_ps(v49, v49, 170).m128_u32[0];
    v48.m128_i32[0] = massProperties.m_centerOfMass.m_quad.m128_i32[1];
    v50.m128_i32[0] = massProperties.m_centerOfMass.m_quad.m128_i32[2];
    *(_DWORD *)(v9 + 96) = massProperties.m_centerOfMass.m_quad.m128_i32[0];
    *(_DWORD *)(v9 + 100) = v48.m128_i32[0];
    *(_DWORD *)(v9 + 104) = v50.m128_i32[0];
  }
  else
  {
    *(float *)(v9 + 144) = parent->mMass;
    y = parent->mCentreOfMass.y;
    z = parent->mCentreOfMass.z;
    *(float *)(v9 + 96) = parent->mCentreOfMass.x;
    *(float *)(v9 + 100) = y;
    *(float *)(v9 + 104) = z;
    v54 = parent->mInertiaTensorRow0.y;
    v55 = parent->mInertiaTensorRow0.z;
    *(float *)(v9 + 108) = parent->mInertiaTensorRow0.x;
    *(float *)(v9 + 112) = v54;
    *(float *)(v9 + 116) = v55;
    v56 = parent->mInertiaTensorRow1.y;
    v57 = parent->mInertiaTensorRow1.z;
    *(float *)(v9 + 120) = parent->mInertiaTensorRow1.x;
    *(float *)(v9 + 124) = v56;
    *(float *)(v9 + 128) = v57;
    v58 = parent->mInertiaTensorRow2.y;
    v59 = parent->mInertiaTensorRow2.z;
    *(float *)(v9 + 132) = parent->mInertiaTensorRow2.x;
    *(float *)(v9 + 136) = v58;
    *(float *)(v9 + 140) = v59;
  }
  *v3 = v74;
  v60 = (char *)p;
  v61 = numShapes;
  if ( p == array )
    v61 = 0;
  numShapes = v61;
  v62 = v71;
  v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v64 = (8 * v62 + 127) & 0xFFFFFF80;
  v65 = (v64 + 15) & 0xFFFFFFF0;
  if ( v64 > v63->m_slabSize || &v60[v65] != v63->m_cur || v63->m_firstNonLifoEnd == v60 )
    hkLifoAllocator::slowBlockFree(v63, v60, v65);
  else
    v63->m_cur = v60;
  numShapes = 0;
  if ( v69 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v69);
  return (UFG::CollisionMeshData *)v9;
}

// File Line: 612
// RVA: 0xA2260
UFG::CollisionMeshData *__fastcall UFG::CollisionMeshData::Clone(UFG::CollisionMeshData *this)
{
  char *v2; // rax
  UFG::CollisionMeshData *v3; // rax
  UFG::CollisionMeshData *v4; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  char *p_mParts; // rcx
  __int64 mOffset; // rax
  char *v15; // rax
  __int64 v16; // rax
  char *p_mPartDetails; // rcx
  __int64 v18; // rax
  char *v19; // rax
  __int64 v20; // rax
  char *p_mIndexBuffer; // rcx
  __int64 v22; // rax
  char *v23; // rax
  __int64 v24; // rax
  char *p_mVertexBuffer; // rcx
  __int64 v26; // rax
  char *v27; // rax
  __int64 v28; // rax
  hkpShape *mShape; // r13
  __int64 m_userData_low; // r12
  hkLifoAllocator *Value; // rax
  int v32; // edx
  hkpShape **m_cur; // rcx
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
  int v47; // r8d
  char *p_mFractureConnections; // rcx
  __int64 v49; // rax
  char *v50; // rax
  __int64 v51; // rax
  UFG::FractureConnectivity *v52; // rax
  hkpShape **array; // [rsp+28h] [rbp-28h] BYREF
  int v55; // [rsp+30h] [rbp-20h]
  int v56; // [rsp+34h] [rbp-1Ch]
  void *p; // [rsp+38h] [rbp-18h]
  int v58; // [rsp+40h] [rbp-10h]

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
  v4->mPropertiesHandleGuid = this->mPropertiesHandleGuid;
  v4->mBundleGuid = this->mBundleGuid;
  v4->mGeometryType = this->mGeometryType;
  v4->mNumVertices = this->mNumVertices;
  v4->mNumIndices = this->mNumIndices;
  v4->mNumParts = this->mNumParts;
  v4->mShapeKeyDepth = this->mShapeKeyDepth;
  v4->mSceneNodeName.mUID = this->mSceneNodeName.mUID;
  v4->mSceneNodeNameUC.mUID = this->mSceneNodeNameUC.mUID;
  v4->mRenderModelGuid = this->mRenderModelGuid;
  v4->mParkourGuid = this->mParkourGuid;
  v4->mCoverGuid = this->mCoverGuid;
  v4->mFlags = this->mFlags | 2;
  v4->mCustomDataSlotIndex = this->mCustomDataSlotIndex;
  y = this->mCentreOfMass.y;
  z = this->mCentreOfMass.z;
  v4->mCentreOfMass.x = this->mCentreOfMass.x;
  v4->mCentreOfMass.y = y;
  v4->mCentreOfMass.z = z;
  v7 = this->mInertiaTensorRow0.y;
  v8 = this->mInertiaTensorRow0.z;
  v4->mInertiaTensorRow0.x = this->mInertiaTensorRow0.x;
  v4->mInertiaTensorRow0.y = v7;
  v4->mInertiaTensorRow0.z = v8;
  v9 = this->mInertiaTensorRow1.y;
  v10 = this->mInertiaTensorRow1.z;
  v4->mInertiaTensorRow1.x = this->mInertiaTensorRow1.x;
  v4->mInertiaTensorRow1.y = v9;
  v4->mInertiaTensorRow1.z = v10;
  v11 = this->mInertiaTensorRow2.y;
  v12 = this->mInertiaTensorRow2.z;
  v4->mInertiaTensorRow2.x = this->mInertiaTensorRow2.x;
  v4->mInertiaTensorRow2.y = v11;
  v4->mInertiaTensorRow2.z = v12;
  v4->mMass = this->mMass;
  p_mParts = (char *)&v4->mParts;
  mOffset = this->mParts.mOffset;
  if ( mOffset && (v15 = (char *)&this->mParts + mOffset) != 0i64 )
    v16 = v15 - p_mParts;
  else
    v16 = 0i64;
  *(_QWORD *)p_mParts = v16;
  p_mPartDetails = (char *)&v4->mPartDetails;
  v18 = this->mPartDetails.mOffset;
  if ( v18 && (v19 = (char *)&this->mPartDetails + v18) != 0i64 )
    v20 = v19 - p_mPartDetails;
  else
    v20 = 0i64;
  *(_QWORD *)p_mPartDetails = v20;
  p_mIndexBuffer = (char *)&v4->mIndexBuffer;
  v22 = this->mIndexBuffer.mOffset;
  if ( v22 && (v23 = (char *)&this->mIndexBuffer + v22) != 0i64 )
    v24 = v23 - p_mIndexBuffer;
  else
    v24 = 0i64;
  *(_QWORD *)p_mIndexBuffer = v24;
  p_mVertexBuffer = (char *)&v4->mVertexBuffer;
  v26 = this->mVertexBuffer.mOffset;
  if ( v26 && (v27 = (char *)&this->mVertexBuffer + v26) != 0i64 )
    v28 = v27 - p_mVertexBuffer;
  else
    v28 = 0i64;
  *(_QWORD *)p_mVertexBuffer = v28;
  v4->mRemoveTerminalsMoppModifierList = 0i64;
  v4->mFractureConnectivity = 0i64;
  v4->mName.mUID = this->mName.mUID;
  v4->mSize = this->mSize;
  UFG::qReflectHandleBase::operator=(&v4->mObjectProperties, &this->mObjectProperties);
  mShape = this->mShape;
  if ( mShape->m_type.m_storage == 8 )
  {
    m_userData_low = SLODWORD(mShape[1].m_userData);
    array = 0i64;
    v55 = 0;
    v56 = 0x80000000;
    v58 = m_userData_low;
    if ( (_DWORD)m_userData_low )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (((8 * m_userData_low + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
      m_cur = (hkpShape **)Value->m_cur;
      v34 = (char *)m_cur + v32;
      if ( v32 > Value->m_slabSize || v34 > Value->m_end )
        m_cur = (hkpShape **)hkLifoAllocator::allocateFromNewSlab(Value, v32);
      else
        Value->m_cur = v34;
    }
    else
    {
      m_cur = 0i64;
    }
    array = m_cur;
    v56 = m_userData_low | 0x80000000;
    p = m_cur;
    v35 = m_userData_low;
    if ( (int)m_userData_low > 0 )
    {
      v36 = 0i64;
      v37 = v55;
      do
      {
        v38 = *(hkpShape **)(v36 + *(_QWORD *)&mShape[1].m_type.m_storage);
        if ( v37 == (v56 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
          v37 = v55;
        }
        array[v37] = v38;
        v37 = ++v55;
        v36 += 32i64;
        --v35;
      }
      while ( v35 );
    }
    v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v40 = (hkpListShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v39[11] + 8i64))(v39[11], 144i64);
    if ( v40 )
      hkpListShape::hkpListShape(v40, array, m_userData_low, REFERENCE_POLICY_INCREMENT);
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v56);
    array = 0i64;
    v56 = 0x80000000;
  }
  else
  {
    this->mShape = 0i64;
  }
  v4->mNumFractureConnections = this->mNumFractureConnections;
  p_mFractureConnections = (char *)&v4->mFractureConnections;
  v49 = this->mFractureConnections.mOffset;
  if ( v49 && (v50 = (char *)&this->mFractureConnections + v49) != 0i64 )
    v51 = v50 - p_mFractureConnections;
  else
    v51 = 0i64;
  *(_QWORD *)p_mFractureConnections = v51;
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
bool __fastcall UFG::CollisionMeshData::ComputeMassProperties(
        UFG::CollisionMeshData *this,
        hkMassProperties *massProperties,
        BitArray256 *fractureState)
{
  hkResultEnum m_enum; // ebx
  unsigned int v5; // r12d
  int v6; // r14d
  __int64 v7; // r13
  __int64 v8; // r15
  hkpShape *mShape; // rbx
  __int64 mOffset; // rax
  char *v11; // rcx
  char *v12; // r8
  char *v13; // rdx
  char *v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  char *v18; // rcx
  int m_size; // ecx
  __int64 v20; // rcx
  bool v21; // zf
  hkMassElement *v22; // rcx
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm1
  hkVector4f v25; // xmm3
  hkArray<hkMassElement,hkContainerHeapAllocator> array; // [rsp+20h] [rbp-99h] BYREF
  __int64 v28; // [rsp+30h] [rbp-89h]
  hkVector4f v29; // [rsp+40h] [rbp-79h]
  __m128 v30; // [rsp+50h] [rbp-69h]
  __m128 v31; // [rsp+60h] [rbp-59h]
  __m128 v32; // [rsp+70h] [rbp-49h]
  hkTransformf transformOut; // [rsp+80h] [rbp-39h] BYREF
  __int64 v34; // [rsp+C0h] [rbp+7h]
  hkMassElement *result; // [rsp+120h] [rbp+67h] BYREF
  hkMassProperties *v36; // [rsp+128h] [rbp+6Fh]
  BitArray256 *v37; // [rsp+130h] [rbp+77h]
  hkMassElement *v38; // [rsp+138h] [rbp+7Fh]

  v37 = fractureState;
  v36 = massProperties;
  v34 = -2i64;
  m_enum = HK_FAILURE;
  if ( this->mShape->m_type.m_storage == 8 )
  {
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    v5 = 0;
    v6 = 1;
    if ( SLODWORD(this->mShape[1].m_userData) > 0 )
    {
      v7 = 0i64;
      v8 = 0i64;
      mShape = this->mShape;
      do
      {
        if ( !fractureState || (v6 & fractureState->mBits[v5 >> 5]) == 0 )
        {
          v28 = 0i64;
          v29.m_quad = 0i64;
          v30 = 0i64;
          v31 = 0i64;
          v32 = 0i64;
          transformOut.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
          transformOut.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
          transformOut.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          transformOut.m_translation = 0i64;
          mOffset = this->mPartDetails.mOffset;
          if ( mOffset )
            v11 = (char *)&this->mPartDetails + mOffset;
          else
            v11 = 0i64;
          HIDWORD(v28) = *(_DWORD *)&v11[v8 + 64];
          LODWORD(v28) = 1065353216;
          if ( mOffset )
            v12 = (char *)&this->mPartDetails + mOffset;
          else
            v12 = 0i64;
          if ( mOffset )
            v13 = (char *)&this->mPartDetails + mOffset;
          else
            v13 = 0i64;
          if ( mOffset )
            v14 = (char *)&this->mPartDetails + mOffset;
          else
            v14 = 0i64;
          v30 = *(__m128 *)&v14[v8 + 16];
          v31 = *(__m128 *)&v13[v8 + 32];
          v15 = *(__m128 *)&v12[v8 + 48];
          v16 = _mm_unpacklo_ps(v30, v31);
          v17 = _mm_shuffle_ps(_mm_unpackhi_ps(v30, v31), v15, 228);
          v30 = _mm_movelh_ps(v16, v15);
          v31 = _mm_shuffle_ps(_mm_movehl_ps(v30, v16), v15, 212);
          v32 = v17;
          if ( mOffset )
            v18 = (char *)&this->mPartDetails + mOffset;
          else
            v18 = 0i64;
          v29.m_quad = *(__m128 *)&v18[v8];
          hkQsTransformf::copyToTransformNoScale(
            (hkQsTransformf *)(*(_QWORD *)(v7 + *(_QWORD *)&mShape[1].m_type.m_storage) + 64i64),
            &transformOut);
          m_size = array.m_size;
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 144);
            m_size = array.m_size;
          }
          v20 = m_size;
          v21 = &array.m_data[v20] == 0;
          v22 = &array.m_data[v20];
          result = v22;
          v38 = v22;
          if ( !v21 )
          {
            *(_QWORD *)&v22->m_properties.m_volume = v28;
            v22->m_properties.m_centerOfMass = (hkVector4f)v29.m_quad;
            v22->m_properties.m_inertiaTensor.m_col0.m_quad = v30;
            v22->m_properties.m_inertiaTensor.m_col1.m_quad = v31;
            v22->m_properties.m_inertiaTensor.m_col2.m_quad = v32;
            v23.m_quad = (__m128)transformOut.m_rotation.m_col1;
            v24.m_quad = (__m128)transformOut.m_rotation.m_col2;
            v25.m_quad = (__m128)transformOut.m_translation;
            v22->m_transform.m_rotation.m_col0 = transformOut.m_rotation.m_col0;
            v22->m_transform.m_rotation.m_col1 = (hkVector4f)v23.m_quad;
            v22->m_transform.m_rotation.m_col2 = (hkVector4f)v24.m_quad;
            v22->m_transform.m_translation = (hkVector4f)v25.m_quad;
          }
          ++array.m_size;
          fractureState = v37;
        }
        ++v5;
        v6 = __ROL4__(v6, 1);
        v8 += 96i64;
        v7 += 32i64;
      }
      while ( (signed int)v5 < SLODWORD(mShape[1].m_userData) );
      m_enum = HK_FAILURE;
      massProperties = v36;
    }
    if ( array.m_size )
      m_enum = hkInertiaTensorComputer::combineMassProperties((hkResult *)&result, &array, massProperties)->m_enum;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        144 * (array.m_capacityAndFlags & 0x3FFFFFFF));
    array.m_data = 0i64;
    array.m_capacityAndFlags = 0x80000000;
  }
  return m_enum == HK_SUCCESS;
}

// File Line: 811
// RVA: 0x97630
void __fastcall UFG::CollisionInstanceResource::CollisionInstanceResource(UFG::CollisionInstanceResource *this)
{
  UFG::CollisionInstanceData **v2; // rdx
  __int64 mNumInstances; // rax
  __int64 v4; // r9
  __int64 v5; // r10
  UFG::CollisionInstanceData *v6; // rcx
  UFG::CollisionInstanceData::Part *v7; // rax
  unsigned int i; // eax
  UFG::CollisionInstanceData::Part *v9; // rcx
  UFG::CollisionInstanceData *v10; // [rsp+50h] [rbp+18h]

  UFG::qResourceData::qResourceData(this);
  v2 = (UFG::CollisionInstanceData **)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  this->mData = v2;
  mNumInstances = this->mNumInstances;
  v4 = (__int64)&v2[mNumInstances];
  v5 = 0i64;
  if ( (_DWORD)mNumInstances )
  {
    do
    {
      v10 = (UFG::CollisionInstanceData *)((v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
      this->mData[v5] = v10;
      v6 = this->mData[v5];
      v7 = 0i64;
      if ( v6->mNumParts )
        v7 = (UFG::CollisionInstanceData::Part *)&v10[1];
      v6->mParts = v7;
      for ( i = 0; i < this->mData[v5]->mNumParts; ++i )
      {
        v9 = &this->mData[v5]->mParts[i];
        v9->mSimObject.mPrev = &v9->mSimObject;
        v9->mSimObject.mNext = &v9->mSimObject;
      }
      v4 = (__int64)&v10[1] + 32 * this->mData[v5]->mNumParts;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < this->mNumInstances );
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
void __fastcall UFG::CollisionInstanceData::Set(
        UFG::CollisionInstanceData *this,
        unsigned int guid,
        unsigned int flags,
        unsigned int *name,
        hkVector4f *pos,
        hkQuaternionf *orient,
        unsigned int collisionModelGuid)
{
  __m128 m_quad; // xmm0
  __m128 v8; // xmm1

  this->mPhysicsComponent = 0i64;
  this->mFlags = flags;
  this->mCollisionModelGuid = collisionModelGuid;
  this->mInstanceGuid = guid;
  this->mSimObjectName.mUID = *name;
  m_quad = pos->m_quad;
  this->mPosition = (hkVector4f)pos->m_quad;
  this->mInitialPosition.m_quad = m_quad;
  v8 = orient->m_vec.m_quad;
  this->mOrientation = (hkQuaternionf)orient->m_vec.m_quad;
  this->mInitialOrientation.m_vec.m_quad = v8;
}

// File Line: 904
// RVA: 0xB2B70
UFG::CollisionInstanceData *__fastcall UFG::CollisionInstanceData::SplitInstanceUsingConnectivity(
        UFG::FractureConnectivity *graph,
        UFG::CollisionInstanceData *parent,
        hkTransformf *transform)
{
  unsigned int size; // edi
  char *v7; // rax
  char *v8; // rbx
  hkVector4f v9; // xmm6
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r11
  UFG::CollisionInstanceData::Part *v13; // rcx
  UFG::SimObject *m_pPointer; // r9
  __int64 v15; // rdx
  _QWORD *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  hkQuaternionf v21; // [rsp+40h] [rbp-48h] BYREF
  char *result; // [rsp+98h] [rbp+10h] BYREF
  __int64 v23; // [rsp+A0h] [rbp+18h]
  __int64 v24; // [rsp+A8h] [rbp+20h]

  if ( parent->mNumParts )
    size = graph->mNodes.size;
  else
    size = 0;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 32 * size + 112, "CollisionInstanceData1", 0i64, 1u);
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
  v9.m_quad = (__m128)transform->m_translation;
  hkQuaternionf::set(&v21, &transform->m_rotation);
  *((hkVector4f *)v8 + 2) = (hkVector4f)v9.m_quad;
  *((hkVector4f *)v8 + 3) = (hkVector4f)v9.m_quad;
  *(hkQuaternionf *)v8 = (hkQuaternionf)v21.m_vec.m_quad;
  *((hkQuaternionf *)v8 + 1) = (hkQuaternionf)v21.m_vec.m_quad;
  *((_QWORD *)v8 + 8) = 0i64;
  *((UFG::qSymbol *)v8 + 18) = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                               (UFG::qSymbol *)&result,
                                               "SplitInstanceUsingConnectivity")->mUID;
  *((_DWORD *)v8 + 19) = size;
  *((_QWORD *)v8 + 11) = 0i64;
  *((_QWORD *)v8 + 12) = 0i64;
  v10 = (__int64)(v8 + 112);
  result = v8 + 112;
  *((_QWORD *)v8 + 10) = v8 + 112;
  if ( size )
  {
    v11 = 0i64;
    v12 = size;
    do
    {
      v13 = &parent->mParts[graph->mNodes.p[v11]->partIdx];
      v23 = v10;
      if ( v10 )
      {
        v24 = v10;
        *(_QWORD *)v10 = v10;
        *(_QWORD *)(v10 + 8) = v10;
        *(_QWORD *)(v10 + 16) = 0i64;
        *(_DWORD *)(v10 + 24) = -1;
      }
      *(_DWORD *)(v10 + 28) = v13->mInstanceUid;
      m_pPointer = v13->mSimObject.m_pPointer;
      if ( *(_QWORD *)(v10 + 16) )
      {
        v15 = *(_QWORD *)v10;
        v16 = *(_QWORD **)(v10 + 8);
        *(_QWORD *)(v15 + 8) = v16;
        *v16 = v15;
        *(_QWORD *)v10 = v10;
        *(_QWORD *)(v10 + 8) = v10;
      }
      *(_QWORD *)(v10 + 16) = m_pPointer;
      if ( m_pPointer )
      {
        mPrev = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v10;
        *(_QWORD *)v10 = mPrev;
        *(_QWORD *)(v10 + 8) = &m_pPointer->m_SafePointerList;
        m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v10;
      }
      if ( v13->mSimObject.m_pPointer )
      {
        v18 = v13->mSimObject.mPrev;
        mNext = v13->mSimObject.mNext;
        v18->mNext = mNext;
        mNext->mPrev = v18;
        v13->mSimObject.mPrev = &v13->mSimObject;
        v13->mSimObject.mNext = &v13->mSimObject;
      }
      v13->mSimObject.m_pPointer = 0i64;
      *(_DWORD *)(v10 + 24) = v13->mSimObjectGuid.mUID;
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
UFG::BaseProperty *__fastcall UFG::GetBaseProperty(hkpShape *shape, int key)
{
  unsigned __int64 m_userData; // r8
  signed int v4; // edx

  if ( key == -1 )
    return 0i64;
  if ( shape->m_type.m_storage != 9 )
    return 0i64;
  m_userData = shape[2].m_userData;
  if ( !m_userData || ((*(_BYTE *)(m_userData + 41) - 1) & 0xFD) != 0 )
    return 0i64;
  v4 = (key & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(m_userData + 232));
  if ( key < 0 )
    return *(UFG::BaseProperty **)(*(_QWORD *)(m_userData + 256) + 80i64 * v4 + 16);
  else
    return *(UFG::BaseProperty **)(*(_QWORD *)(m_userData + 240) + 144i64 * v4 + 16);
}

// File Line: 1022
// RVA: 0xAB6B0
void __fastcall UFG::GetTransformFromShapeKey(hkTransformf *transformOut, hkpShape *shape, int key)
{
  char m_storage; // al

  m_storage = shape->m_type.m_storage;
  if ( m_storage == 9 )
  {
    hkQsTransformf::copyToTransformNoScale(
      (hkQsTransformf *)(*(_QWORD *)(*(_QWORD *)(shape[2].m_userData + 48) + 32i64 * key) + 64i64),
      transformOut);
  }
  else if ( m_storage == 8 )
  {
    hkQsTransformf::copyToTransformNoScale(
      (hkQsTransformf *)(*(_QWORD *)(32i64 * key + *(_QWORD *)&shape[1].m_type.m_storage) + 64i64),
      transformOut);
  }
}

// File Line: 1046
// RVA: 0xA9500
void __fastcall UFG::GetAabbFromShapeKey(hkAabb *aabbOut, hkTransformf *localToWorld, hkpShape *shape, int key)
{
  char m_storage; // al

  m_storage = shape->m_type.m_storage;
  if ( m_storage == 9 )
  {
    (*(void (__fastcall **)(_QWORD, hkTransformf *, __int64, hkAabb *))(**(_QWORD **)(32i64 * key
                                                                                    + *(_QWORD *)(shape[2].m_userData
                                                                                                + 48))
                                                                      + 32i64))(
      *(_QWORD *)(32i64 * key + *(_QWORD *)(shape[2].m_userData + 48)),
      localToWorld,
      32i64 * key,
      aabbOut);
  }
  else if ( m_storage == 8 )
  {
    (*(void (__fastcall **)(_QWORD, hkTransformf *, hkpShape *, hkAabb *))(**(_QWORD **)(32i64 * key
                                                                                       + *(_QWORD *)&shape[1].m_type.m_storage)
                                                                         + 32i64))(
      *(_QWORD *)(32i64 * key + *(_QWORD *)&shape[1].m_type.m_storage),
      localToWorld,
      shape,
      aabbOut);
  }
}

