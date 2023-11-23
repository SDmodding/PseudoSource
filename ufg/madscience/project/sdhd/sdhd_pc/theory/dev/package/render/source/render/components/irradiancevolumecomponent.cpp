// File Line: 26
// RVA: 0x1457320
__int64 dynamic_initializer_for__Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList__);
}

// File Line: 27
// RVA: 0x14572F0
__int64 dynamic_initializer_for__Render::IrradianceVolumeComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = Render::IrradianceVolumeComponent::AccessComponentDesc();
  *(_DWORD *)&Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  Render::IrradianceVolumeComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  Render::IrradianceVolumeComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 32
// RVA: 0x73B80
void __fastcall Render::IrradianceVolumeComponent::IrradianceVolumeComponent(
        Render::IrradianceVolumeComponent *this,
        unsigned int nameUID,
        UFG::SceneObjectProperties *sceneObj)
{
  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject> *v5; // rcx
  const char *StaticTypeName; // rax
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, nameUID);
  this->mPrev = &this->UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent>;
  this->mNext = &this->UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::IrradianceVolumeComponent::`vftable;
  this->mSceneObj = sceneObj;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mIrradianceHandle);
  StaticTypeName = UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::GetStaticTypeName(v5);
  this->mIrradianceHandle.mTypeUID = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  mPrev = Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev;
  Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev->mNext = &this->UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList;
  Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev = &this->UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent>;
  UFG::SimComponent::AddType(
    this,
    Render::IrradianceVolumeComponent::_IrradianceVolumeComponentTypeUID,
    "IrradianceVolumeComponent");
}

// File Line: 41
// RVA: 0x73C40
void __fastcall Render::IrradianceVolumeComponent::~IrradianceVolumeComponent(Render::IrradianceVolumeComponent *this)
{
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v2; // rbx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *mPrev; // rcx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *mNext; // rax
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v5; // rcx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::IrradianceVolumeComponent::`vftable;
  if ( this == Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentpCurrentIterator )
    Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentpCurrentIterator = (Render::IrradianceVolumeComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mIrradianceHandle);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 46
// RVA: 0x73DA0
Render::IrradianceVolumeComponent *__fastcall Render::IrradianceVolumeComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObj)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v4; // rax
  Render::IrradianceVolumeComponent *v5; // rax
  Render::IrradianceVolumeComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  m_pSimObject = sceneObj->m_pSimObject;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x270ui64, "IrradianceVolumeComponent", 0i64, 1u);
  if ( v4 )
  {
    Render::IrradianceVolumeComponent::IrradianceVolumeComponent(
      (Render::IrradianceVolumeComponent *)v4,
      sceneObj->m_NameUID,
      sceneObj);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  Render::IrradianceVolumeComponent::Update(v6);
  return v6;
}

// File Line: 66
// RVA: 0x73E50
// attributes: thunk
void __fastcall Render::IrradianceVolumeComponent::TeleportEventHandler(
        Render::IrradianceVolumeComponent *this,
        UFG::Event *this_event)
{
  Render::IrradianceVolumeComponent::Update(this);
}

// File Line: 71
// RVA: 0x73E60
void __fastcall Render::IrradianceVolumeComponent::Update(Render::IrradianceVolumeComponent *this)
{
  UFG::SceneObjectProperties *mSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v4; // rax
  char *MemImagePtr; // rdi
  UFG::SceneObjectProperties *v6; // rax
  unsigned int mPrevNameHash; // edx
  UFG::SimObject *m_pSimObject; // r14
  Render::IrradianceVolume *p_mIrradianceVolume; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v11; // xmm0_4
  float v12; // xmm12_4
  float v13; // xmm1_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm3_4
  unsigned int v26; // ecx
  unsigned int v27; // ecx
  float v28; // xmm0_4
  unsigned int v29; // ecx
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  float v32; // xmm0_4
  UFG::TransformNodeComponent *v33; // rbx
  UFG::qVector4 v34; // xmm3
  UFG::qVector4 v35; // xmm2
  UFG::qVector4 v36; // xmm1
  float x; // xmm0_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm11_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm11_4
  UFG::qVector3 scale; // [rsp+20h] [rbp-98h] BYREF

  mSceneObj = this->mSceneObj;
  mpWritableProperties = mSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = mSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         &component_IrradianceVolume::sPropertyName,
         DEPTH_RECURSE);
  if ( v4 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v4);
  else
    MemImagePtr = 0i64;
  v6 = this->mSceneObj;
  mPrevNameHash = v6->mPrevNameHash;
  m_pSimObject = v6->m_pSimObject;
  if ( mPrevNameHash )
    UFG::Simulation::GetSimObject(&UFG::gSim, mPrevNameHash);
  p_mIrradianceVolume = &this->mIrradianceVolume;
  this->mIrradianceVolume.mVolumeUID = m_pSimObject->mNode.mUID;
  this->mIrradianceVolume.mImageDimensions[0] = *(_WORD *)MemImagePtr;
  this->mIrradianceVolume.mImageDimensions[1] = *((_WORD *)MemImagePtr + 2);
  this->mIrradianceVolume.mImageDimensions[2] = *((_WORD *)MemImagePtr + 4);
  this->mIrradianceVolume.mType = MemImagePtr[12];
  this->mIrradianceVolume.mFlags = MemImagePtr[16];
  this->mIrradianceVolume.mSectionIndex = *((_DWORD *)MemImagePtr + 14);
  UFG::qMemSet(this->mIrradianceVolume.mName, 0, 0x60u);
  UFG::qMemSet(this->mIrradianceVolume.mZone, 0, 4u);
  if ( this->mIrradianceVolume.mType == 2 )
    this->mIrradianceVolume.mFlags |= 4u;
  UFG::qReflectHandleBase::Init(
    &this->mIrradianceHandle,
    this->mIrradianceHandle.mTypeUID,
    *((_QWORD *)MemImagePtr + 6));
  Render::IrradianceVolumeComponent::UpdateTextureUIDs(this);
  *(_QWORD *)this->mIrradianceVolume.mTexture2UID = 0i64;
  this->mIrradianceVolume.mTexture2UID[2] = 0;
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v11 = *((float *)MemImagePtr + 10);
  v12 = (float)(*((float *)MemImagePtr + 5) - *((float *)MemImagePtr + 8)) * 0.5;
  v13 = v12 + *((float *)MemImagePtr + 8);
  v14 = m_pTransformNodeComponent->mWorldTransform.v0.x * v13;
  v15 = m_pTransformNodeComponent->mWorldTransform.v0.y * v13;
  v16 = m_pTransformNodeComponent->mWorldTransform.v0.z * v13;
  v17 = (float)((float)(*((float *)MemImagePtr + 6) - *((float *)MemImagePtr + 9)) * 0.5) + *((float *)MemImagePtr + 9);
  v18 = m_pTransformNodeComponent->mWorldTransform.v1.z * v17;
  v19 = (float)(v14 + m_pTransformNodeComponent->mWorldTransform.v3.x)
      + (float)(m_pTransformNodeComponent->mWorldTransform.v1.x * v17);
  v20 = (float)(v15 + m_pTransformNodeComponent->mWorldTransform.v3.y)
      + (float)(m_pTransformNodeComponent->mWorldTransform.v1.y * v17);
  v21 = (float)(*((float *)MemImagePtr + 6) - *((float *)MemImagePtr + 9)) * 0.5;
  v22 = (float)((float)(*((float *)MemImagePtr + 7) - v11) * 0.5) + v11;
  v23 = v20 + (float)(m_pTransformNodeComponent->mWorldTransform.v2.y * v22);
  v24 = (float)((float)(v16 + m_pTransformNodeComponent->mWorldTransform.v3.z) + v18)
      + (float)(m_pTransformNodeComponent->mWorldTransform.v2.z * v22);
  v25 = (float)(*((float *)MemImagePtr + 7) - v11) * 0.5;
  p_mIrradianceVolume->mPos.x = v19 + (float)(m_pTransformNodeComponent->mWorldTransform.v2.x * v22);
  p_mIrradianceVolume->mPos.y = v23;
  p_mIrradianceVolume->mPos.z = v24;
  v26 = ((unsigned int)(p_mIrradianceVolume->mImageDimensions[0] - 1) >> 1) | (p_mIrradianceVolume->mImageDimensions[0]
                                                                             - 1);
  scale.x = v12;
  scale.y = v21;
  scale.z = v25;
  v27 = (((v26 >> 2) | v26) >> 4) | (v26 >> 2) | v26;
  v28 = (float)(int)(((v27 >> 8) | v27 | (((v27 >> 8) | v27) >> 16)) + 1);
  if ( v28 <= 16.0 )
    v28 = FLOAT_16_0;
  v29 = p_mIrradianceVolume->mImageDimensions[1] - 1;
  p_mIrradianceVolume->mImageDimensions[0] = (int)v28;
  v30 = (((v29 >> 1) | v29) >> 2) | (v29 >> 1) | v29;
  v31 = (((v30 >> 4) | v30) >> 8) | (v30 >> 4) | v30;
  v32 = (float)(int)((v31 | HIWORD(v31)) + 1);
  if ( v32 <= 16.0 )
    v32 = FLOAT_16_0;
  p_mIrradianceVolume->mImageDimensions[1] = (int)v32;
  p_mIrradianceVolume->mImageDimensions[2] = (p_mIrradianceVolume->mImageDimensions[2] + 3) & 0xFFFC;
  p_mIrradianceVolume->mScale.x = v12;
  p_mIrradianceVolume->mScale.y = v21;
  p_mIrradianceVolume->mScale.z = v25;
  *(_QWORD *)&p_mIrradianceVolume->mRot.x = 0i64;
  p_mIrradianceVolume->mRot.z = 0.0;
  v33 = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v33);
  v34 = v33->mWorldTransform.v1;
  v35 = v33->mWorldTransform.v2;
  v36 = v33->mWorldTransform.v3;
  p_mIrradianceVolume->mRotationMtx.v0 = v33->mWorldTransform.v0;
  p_mIrradianceVolume->mRotationMtx.v1 = v34;
  p_mIrradianceVolume->mRotationMtx.v2 = v35;
  p_mIrradianceVolume->mRotationMtx.v3 = v36;
  *(_QWORD *)&p_mIrradianceVolume->mRotationMtx.v3.x = 0i64;
  p_mIrradianceVolume->mRotationMtx.v3.z = 0.0;
  p_mIrradianceVolume->mRotationMtx.v3.w = 1.0;
  UFG::qInverseAffine(&p_mIrradianceVolume->mRotationMtxInv, &p_mIrradianceVolume->mRotationMtx);
  UFG::qScaleMatrix(&p_mIrradianceVolume->mTransform, &scale);
  UFG::qMatrix44::operator*=(&p_mIrradianceVolume->mTransform, &p_mIrradianceVolume->mRotationMtx);
  x = p_mIrradianceVolume->mPos.x;
  v36.x = p_mIrradianceVolume->mPos.y;
  v35.x = p_mIrradianceVolume->mPos.z;
  p_mIrradianceVolume->mTransform.v3.w = 1.0;
  p_mIrradianceVolume->mTransform.v3.x = x;
  p_mIrradianceVolume->mTransform.v3.y = v36.x;
  p_mIrradianceVolume->mTransform.v3.z = v35.x;
  UFG::qInverse(&p_mIrradianceVolume->mTransformInv, &p_mIrradianceVolume->mTransform);
  v38 = 0.5 / (float)p_mIrradianceVolume->mImageDimensions[0];
  v39 = 0.5 / (float)p_mIrradianceVolume->mImageDimensions[1];
  v40 = 0.5 / (float)p_mIrradianceVolume->mImageDimensions[2];
  UFG::qScaleMatrix(&p_mIrradianceVolume->mProbesTransform, &p_mIrradianceVolume->mScale);
  UFG::qMatrix44::operator*=(&p_mIrradianceVolume->mProbesTransform, &p_mIrradianceVolume->mRotationMtx);
  v41 = v38 + p_mIrradianceVolume->mPos.x;
  v42 = v39 + p_mIrradianceVolume->mPos.y;
  v43 = v40 + p_mIrradianceVolume->mPos.z;
  p_mIrradianceVolume->mProbesTransform.v3.w = 1.0;
  p_mIrradianceVolume->mProbesTransform.v3.x = v41;
  p_mIrradianceVolume->mProbesTransform.v3.y = v42;
  p_mIrradianceVolume->mProbesTransform.v3.z = v43;
}

// File Line: 200
// RVA: 0x74370
void __fastcall Render::IrradianceVolumeComponent::UpdateTextureUIDs(Render::IrradianceVolumeComponent *this)
{
  UFG::qReflectObject *mData; // rax

  mData = this->mIrradianceHandle.mData;
  if ( mData )
  {
    if ( this->mIrradianceVolume.mType == 2 )
    {
      *(_QWORD *)this->mIrradianceVolume.mTextureUID = 0i64;
    }
    else
    {
      this->mIrradianceVolume.mTextureUID[0] = (unsigned int)mData[1].mBaseNode.mChildren[1][4].mParent;
      this->mIrradianceVolume.mTextureUID[1] = (unsigned int)this->mIrradianceHandle.mData[1].mHandles.mNode.mNext[12].mNext;
    }
    this->mIrradianceVolume.mTextureUID[2] = (unsigned int)this->mIrradianceHandle.mData[2].mBaseNode.mChildren[1][4].mParent;
  }
}

