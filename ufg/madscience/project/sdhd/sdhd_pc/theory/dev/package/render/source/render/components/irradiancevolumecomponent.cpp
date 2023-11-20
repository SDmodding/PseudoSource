// File Line: 26
// RVA: 0x1457320
__int64 dynamic_initializer_for__Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList__);
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
void __fastcall Render::IrradianceVolumeComponent::IrradianceVolumeComponent(Render::IrradianceVolumeComponent *this, unsigned int nameUID, UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v3; // rbx
  Render::IrradianceVolumeComponent *v4; // rsi
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v5; // rdi
  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v8; // rax

  v3 = sceneObj;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUID);
  v5 = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::IrradianceVolumeComponent::`vftable;
  v4->mSceneObj = v3;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v4->mIrradianceHandle.mPrev);
  v7 = UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::GetStaticTypeName(v6);
  v4->mIrradianceHandle.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  v8 = Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev;
  Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev->mNext = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList;
  Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mPrev = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    Render::IrradianceVolumeComponent::_IrradianceVolumeComponentTypeUID,
    "IrradianceVolumeComponent");
}

// File Line: 41
// RVA: 0x73C40
void __fastcall Render::IrradianceVolumeComponent::~IrradianceVolumeComponent(Render::IrradianceVolumeComponent *this)
{
  Render::IrradianceVolumeComponent *v1; // rdi
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v2; // rbx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v3; // rcx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v4; // rax
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v5; // rcx
  UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::IrradianceVolumeComponent::`vftable;
  if ( this == Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentpCurrentIterator )
    Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentpCurrentIterator = (Render::IrradianceVolumeComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mIrradianceHandle.mPrev);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 46
// RVA: 0x73DA0
Render::IrradianceVolumeComponent *__fastcall Render::IrradianceVolumeComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::SimObject *v2; // rdi
  UFG::qMemoryPool *v3; // rax
  char *v4; // rax
  Render::IrradianceVolumeComponent *v5; // rax
  Render::IrradianceVolumeComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = sceneObj;
  v2 = sceneObj->m_pSimObject;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x270ui64, "IrradianceVolumeComponent", 0i64, 1u);
  if ( v4 )
  {
    Render::IrradianceVolumeComponent::IrradianceVolumeComponent(
      (Render::IrradianceVolumeComponent *)v4,
      v1->m_NameUID,
      v1);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v2, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  Render::IrradianceVolumeComponent::Update(v6);
  return v6;
}

// File Line: 66
// RVA: 0x73E50
void __fastcall Render::IrradianceVolumeComponent::TeleportEventHandler(Render::IrradianceVolumeComponent *this, UFG::Event *this_event)
{
  Render::IrradianceVolumeComponent::Update(this);
}

// File Line: 71
// RVA: 0x73E60
void __fastcall Render::IrradianceVolumeComponent::Update(Render::IrradianceVolumeComponent *this)
{
  Render::IrradianceVolumeComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rax
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  char *v5; // rdi
  UFG::SceneObjectProperties *v6; // rax
  unsigned int v7; // edx
  UFG::SimObject *v8; // r14
  signed __int64 v9; // rbp
  float *v10; // rbx
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
  unsigned int v27; // eax
  unsigned int v28; // ecx
  float v29; // xmm0_4
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  unsigned int v32; // ecx
  float v33; // xmm0_4
  UFG::TransformNodeComponent *v34; // rbx
  UFG::qVector4 v35; // xmm3
  UFG::qVector4 v36; // xmm2
  UFG::qVector4 *v37; // rdx
  UFG::qVector4 v38; // xmm1
  int v39; // xmm0_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm11_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm11_4
  UFG::qVector3 scale; // [rsp+20h] [rbp-98h]

  v1 = this;
  v2 = this->mSceneObj;
  v3 = v2->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v3,
         (UFG::qSymbol *)&component_IrradianceVolume::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v4 )
    v5 = UFG::qPropertySet::GetMemImagePtr(v4);
  else
    v5 = 0i64;
  v6 = v1->mSceneObj;
  v7 = v6->mPrevNameHash;
  v8 = v6->m_pSimObject;
  if ( v7 )
    UFG::Simulation::GetSimObject(&UFG::gSim, v7);
  v9 = (signed __int64)&v1->mIrradianceVolume;
  *(_DWORD *)(v9 + 364) = v8->mNode.mUID;
  *(_WORD *)(v9 + 356) = *(_WORD *)v5;
  *(_WORD *)(v9 + 358) = *((_WORD *)v5 + 2);
  *(_WORD *)(v9 + 360) = *((_WORD *)v5 + 4);
  *(_BYTE *)(v9 + 362) = v5[12];
  *(_BYTE *)(v9 + 363) = v5[16];
  *(_DWORD *)(v9 + 492) = *((_DWORD *)v5 + 14);
  UFG::qMemSet(v1->mIrradianceVolume.mName, 0, 0x60u);
  UFG::qMemSet(v1->mIrradianceVolume.mZone, 0, 4u);
  if ( v1->mIrradianceVolume.mType == 2 )
    v1->mIrradianceVolume.mFlags |= 4u;
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&v1->mIrradianceHandle.mPrev,
    v1->mIrradianceHandle.mTypeUID,
    *((_QWORD *)v5 + 6));
  Render::IrradianceVolumeComponent::UpdateTextureUIDs(v1);
  *(_QWORD *)v1->mIrradianceVolume.mTexture2UID = 0i64;
  v1->mIrradianceVolume.mTexture2UID[2] = 0;
  v10 = (float *)v8->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8->m_pTransformNodeComponent);
  v11 = *((float *)v5 + 10);
  v12 = (float)(*((float *)v5 + 5) - *((float *)v5 + 8)) * 0.5;
  v13 = v12 + *((float *)v5 + 8);
  v14 = v10[32] * v13;
  v15 = v10[33] * v13;
  v16 = v10[34] * v13;
  v17 = (float)((float)(*((float *)v5 + 6) - *((float *)v5 + 9)) * 0.5) + *((float *)v5 + 9);
  v18 = v10[38] * v17;
  v19 = (float)(v14 + v10[44]) + (float)(v10[36] * v17);
  v20 = (float)(v15 + v10[45]) + (float)(v10[37] * v17);
  v21 = (float)(*((float *)v5 + 6) - *((float *)v5 + 9)) * 0.5;
  v22 = (float)((float)(*((float *)v5 + 7) - v11) * 0.5) + v11;
  v23 = v20 + (float)(v10[41] * v22);
  v24 = (float)((float)(v16 + v10[46]) + v18) + (float)(v10[42] * v22);
  v25 = (float)(*((float *)v5 + 7) - v11) * 0.5;
  *(float *)(v9 + 320) = v19 + (float)(v10[40] * v22);
  *(float *)(v9 + 324) = v23;
  *(float *)(v9 + 328) = v24;
  v26 = ((unsigned int)(*(signed __int16 *)(v9 + 356) - 1) >> 1) | (*(signed __int16 *)(v9 + 356) - 1);
  v27 = ((unsigned int)(*(signed __int16 *)(v9 + 356) - 1) >> 1) | (*(signed __int16 *)(v9 + 356) - 1);
  scale.x = v12;
  scale.y = v21;
  scale.z = v25;
  v28 = (((v27 >> 2) | v26) >> 4) | (v27 >> 2) | v26;
  v29 = (float)(signed int)(((v28 >> 8) | v28 | (((v28 >> 8) | v28) >> 16)) + 1);
  if ( v29 <= 16.0 )
    v29 = FLOAT_16_0;
  v30 = *(signed __int16 *)(v9 + 358) - 1;
  *(_WORD *)(v9 + 356) = (signed int)v29;
  v31 = (((v30 >> 1) | v30) >> 2) | (v30 >> 1) | v30;
  v32 = (((v31 >> 4) | v31) >> 8) | (v31 >> 4) | v31;
  v33 = (float)(signed int)((v32 | (v32 >> 16)) + 1);
  if ( v33 <= 16.0 )
    v33 = FLOAT_16_0;
  *(_WORD *)(v9 + 358) = (signed int)v33;
  *(_WORD *)(v9 + 360) = (*(_WORD *)(v9 + 360) + 3) & 0xFFFC;
  *(float *)(v9 + 332) = v12;
  *(float *)(v9 + 336) = v21;
  *(float *)(v9 + 340) = v25;
  *(_QWORD *)(v9 + 344) = 0i64;
  *(_DWORD *)(v9 + 352) = 0;
  v34 = v8->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8->m_pTransformNodeComponent);
  v35 = v34->mWorldTransform.v1;
  v36 = v34->mWorldTransform.v2;
  v37 = (UFG::qVector4 *)(v9 + 192);
  v38 = v34->mWorldTransform.v3;
  *v37 = v34->mWorldTransform.v0;
  v37[1] = v35;
  v37[2] = v36;
  v37[3] = v38;
  *(_QWORD *)(v9 + 240) = 0i64;
  *(_DWORD *)(v9 + 248) = 0;
  *(_DWORD *)(v9 + 252) = 1065353216;
  UFG::qInverseAffine((UFG::qMatrix44 *)(v9 + 256), (UFG::qMatrix44 *)(v9 + 192));
  UFG::qScaleMatrix((UFG::qMatrix44 *)v9, &scale);
  UFG::qMatrix44::operator*=((UFG::qMatrix44 *)v9, (UFG::qMatrix44 *)(v9 + 192));
  v39 = *(_DWORD *)(v9 + 320);
  v38.x = *(float *)(v9 + 324);
  v36.x = *(float *)(v9 + 328);
  *(_DWORD *)(v9 + 60) = 1065353216;
  *(_DWORD *)(v9 + 48) = v39;
  *(float *)(v9 + 52) = v38.x;
  *(float *)(v9 + 56) = v36.x;
  UFG::qInverse((UFG::qMatrix44 *)(v9 + 64), (UFG::qMatrix44 *)v9);
  v40 = 0.5 / (float)*(signed __int16 *)(v9 + 356);
  v41 = 0.5 / (float)*(signed __int16 *)(v9 + 358);
  v42 = 0.5 / (float)*(signed __int16 *)(v9 + 360);
  UFG::qScaleMatrix((UFG::qMatrix44 *)(v9 + 128), (UFG::qVector3 *)(v9 + 332));
  UFG::qMatrix44::operator*=((UFG::qMatrix44 *)(v9 + 128), (UFG::qMatrix44 *)(v9 + 192));
  v43 = v40 + *(float *)(v9 + 320);
  v44 = v41 + *(float *)(v9 + 324);
  v45 = v42 + *(float *)(v9 + 328);
  *(_DWORD *)(v9 + 188) = 1065353216;
  *(float *)(v9 + 176) = v43;
  *(float *)(v9 + 180) = v44;
  *(float *)(v9 + 184) = v45;
}

// File Line: 200
// RVA: 0x74370
void __fastcall Render::IrradianceVolumeComponent::UpdateTextureUIDs(Render::IrradianceVolumeComponent *this)
{
  UFG::qReflectObject *v1; // rax

  v1 = this->mIrradianceHandle.mData;
  if ( v1 )
  {
    if ( this->mIrradianceVolume.mType == 2 )
    {
      *(_QWORD *)this->mIrradianceVolume.mTextureUID = 0i64;
    }
    else
    {
      this->mIrradianceVolume.mTextureUID[0] = (unsigned int)v1[1].mBaseNode.mChildren[1][4].mParent;
      this->mIrradianceVolume.mTextureUID[1] = (unsigned int)this->mIrradianceHandle.mData[1].mHandles.mNode.mNext[12].mNext;
    }
    this->mIrradianceVolume.mTextureUID[2] = (unsigned int)this->mIrradianceHandle.mData[2].mBaseNode.mChildren[1][4].mParent;
  }
}

