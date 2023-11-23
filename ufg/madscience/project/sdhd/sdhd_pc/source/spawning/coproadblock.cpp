// File Line: 28
// RVA: 0x155D500
__int64 dynamic_initializer_for__UFG::CopRoadBlock::s_CopRoadBlockList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CopRoadBlock::s_CopRoadBlockList__);
}

// File Line: 29
// RVA: 0x5B4250
const char *__fastcall UFG::CopRoadBlock::GetTypeName(UFG::CopRoadBlock *this)
{
  return "CopRoadBlock";
}

// File Line: 42
// RVA: 0x5B1820
void __fastcall UFG::CopRoadBlock::CopRoadBlock(UFG::CopRoadBlock *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mObjects; // rbx
  __int64 v5; // rsi
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock>;
  this->mNext = &this->UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopRoadBlock::`vftable;
  mObjects = this->mObjects;
  v5 = 6i64;
  `eh vector constructor iterator(
    this->mObjects,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  this->mPositionToDefendObject.mPrev = &this->mPositionToDefendObject;
  this->mPositionToDefendObject.mNext = &this->mPositionToDefendObject;
  this->mPositionToDefendObject.m_pPointer = 0i64;
  *(_DWORD *)&this->mAutoFillLanes = 1;
  mPrev = UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev;
  UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&UFG::CopRoadBlock::s_CopRoadBlockList;
  UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev = &this->UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock>;
  UFG::SimComponent::AddType(this, UFG::CopRoadBlock::_CopRoadBlockTypeUID, "CopRoadBlock");
  do
  {
    if ( mObjects->m_pPointer )
    {
      v7 = mObjects->mPrev;
      mNext = mObjects->mNext;
      v7->mNext = mNext;
      mNext->mPrev = v7;
      mObjects->mPrev = mObjects;
      mObjects->mNext = mObjects;
    }
    mObjects->m_pPointer = 0i64;
    ++mObjects;
    --v5;
  }
  while ( v5 );
}

// File Line: 53
// RVA: 0x5B1DB0
void __fastcall UFG::CopRoadBlock::~CopRoadBlock(UFG::CopRoadBlock *this)
{
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v2; // rdi
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *mPrev; // rcx
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mPositionToDefendObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v10; // rcx
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopRoadBlock::`vftable;
  if ( this == UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator )
    UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator = (UFG::CopRoadBlock *)&this->mPrev[-7];
  v2 = &this->UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mPositionToDefendObject = &this->mPositionToDefendObject;
  if ( this->mPositionToDefendObject.m_pPointer )
  {
    v6 = p_mPositionToDefendObject->mPrev;
    v7 = this->mPositionToDefendObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mPositionToDefendObject->mPrev = p_mPositionToDefendObject;
    this->mPositionToDefendObject.mNext = &this->mPositionToDefendObject;
  }
  this->mPositionToDefendObject.m_pPointer = 0i64;
  v8 = p_mPositionToDefendObject->mPrev;
  v9 = this->mPositionToDefendObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mPositionToDefendObject->mPrev = p_mPositionToDefendObject;
  this->mPositionToDefendObject.mNext = &this->mPositionToDefendObject;
  `eh vector destructor iterator(
    this->mObjects,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 59
// RVA: 0x5B4330
bool __fastcall UFG::CopRoadBlock::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCopRoadBlock);
}

// File Line: 65
// RVA: 0x5B5260
UFG::CopRoadBlock *__fastcall UFG::CopRoadBlock::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v10; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x130ui64, "CopRoadBlock", 0i64, 1u);
  v10 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::CopRoadBlock::CopRoadBlock((UFG::CopRoadBlock *)v3, v5, m_pSimObject);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  *(_BYTE *)(v7 + 296) = *PropertyUtils::Get<bool>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_AutoFillLanes);
  return (UFG::CopRoadBlock *)v7;
}

// File Line: 79
// RVA: 0x5B75F0
void __fastcall UFG::CopRoadBlock::Update(UFG::CopRoadBlock *this, float deltaTime)
{
  bool mDesiredStatus; // al
  UFG::TransformNodeComponent *mpXformNode; // rbx

  mDesiredStatus = this->mDesiredStatus;
  if ( mDesiredStatus != this->mActiveStatus )
  {
    if ( mDesiredStatus )
    {
      UFG::CopRoadBlock::Spawn(this);
    }
    else
    {
      mpXformNode = this->mpXformNode;
      UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
      if ( !UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&mpXformNode->mWorldTransform.v3, 2.0, 0) )
        UFG::CopRoadBlock::Despawn(this);
    }
  }
}

// File Line: 99
// RVA: 0x5B5110
// attributes: thunk
void __fastcall UFG::CopRoadBlock::OnDetach(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock::Despawn(this);
}

// File Line: 106
// RVA: 0x5B26B0
char __fastcall UFG::CopRoadBlock::ActivateByDistance(
        UFG::CopRoadBlock *this,
        UFG::qVector3 *origin,
        float minRadiusSq,
        float maxRadiusSq,
        int *pBitfields)
{
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float x; // xmm8_4
  float y; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // eax
  UFG::TransformNodeComponent *v17; // rbx
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  char result; // al

  mpXformNode = this->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  x = mpXformNode->mWorldTransform.v3.x;
  y = mpXformNode->mWorldTransform.v3.y;
  v10 = (float)((float)(origin->y - y) * (float)(origin->y - y))
      + (float)((float)(origin->x - x) * (float)(origin->x - x));
  if ( v10 < minRadiusSq
    || v10 > maxRadiusSq
    || ((v11 = x - origin->x,
         v12 = y - origin->y,
         v13 = mpXformNode->mWorldTransform.v3.z - origin->z,
         v14 = atan2f(v12, v11),
         v14 >= 0.0)
      ? (v15 = 0.0)
      : (v15 = FLOAT_6_2831855),
        v16 = 1 << (int)(float)((float)((float)(v15 + v14) * 8.0) * 0.15915494),
        (*pBitfields & v16) != 0) )
  {
    result = 0;
    this->mDesiredStatus = 0;
  }
  else
  {
    *pBitfields |= v16;
    v17 = this->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v17);
    v18 = v12 * v17->mWorldTransform.v0.y;
    v19 = v11 * v17->mWorldTransform.v0.x;
    v20 = v13 * v17->mWorldTransform.v0.z;
    this->mDesiredStatus = 1;
    this->mFlipped = (float)((float)(v18 + v19) + v20) > 0.0;
    ((void (__fastcall *)(UFG::CopRoadBlock *))this->vfptr[18].__vecDelDtor)(this);
    return 1;
  }
  return result;
}

// File Line: 142
// RVA: 0x5B31D0
void __fastcall UFG::CopRoadBlock::Deactivate(UFG::CopRoadBlock *this)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax

  vfptr = this->vfptr;
  this->mDesiredStatus = 0;
  ((void (*)(void))vfptr[18].__vecDelDtor)();
}

// File Line: 148
// RVA: 0x5B58E0
void __fastcall UFG::CopRoadBlock::Spawn(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock *v1; // r13
  unsigned int v2; // r14d
  int v3; // r15d
  UFG::RoadNetworkSegment *ClosestRoadSegment; // rax
  UFG::RoadNetworkNode *v5; // r12
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float x; // xmm15_4
  float v8; // xmm10_4
  __m128 y_low; // xmm6
  float z; // xmm9_4
  float w; // xmm11_4
  float y; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm12_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mObjects; // rbx
  float v16; // xmm15_4
  float v17; // xmm8_4
  UFG::RoadNetworkLane *Lane; // rdi
  float v19; // xmm9_4
  float v20; // xmm6_4
  UFG::qSymbol *v21; // rax
  UFG::qPropertySet *PropertySet; // r15
  UFG::SceneObjectProperties *v23; // rdi
  UFG::SimObject *v24; // rsi
  UFG::qSymbolUC *v25; // rax
  char *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  float v30; // xmm3_4
  float v31; // xmm9_4
  float v32; // xmm11_4
  float v33; // xmm3_4
  __m128 x_low; // xmm2
  float v35; // xmm2_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm8_4
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm1_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleEffectsComponent *m_pComponent; // rax
  float v52; // xmm13_4
  float v53; // xmm14_4
  UFG::qPropertySet *v54; // rsi
  UFG::SceneObjectProperties *v55; // rbx
  __int64 v56; // r12
  UFG::SimObject *v57; // rdi
  UFG::qSymbolUC *v58; // rax
  char *v59; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v60; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v61; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v62; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v63; // rax
  UFG::qPropertySet *v64; // rsi
  UFG::SceneObjectProperties *v65; // rbx
  UFG::SimObject *v66; // rdi
  UFG::qSymbolUC *v67; // rax
  char *v68; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v69; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v70; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v71; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v72; // rax
  UFG::qPropertySet *v73; // rsi
  UFG::SceneObjectProperties *v74; // rbx
  UFG::SimObject *v75; // rdi
  UFG::qSymbolUC *v76; // rax
  char *v77; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v78; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v79; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v80; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v81; // rax
  __m128 v82; // xmm8
  float v83; // xmm1_4
  float v84; // xmm10_4
  float v85; // xmm11_4
  float v86; // xmm9_4
  __m128 v87; // xmm2
  __m128 v88; // xmm4
  float v89; // xmm1_4
  __m128 v90; // xmm2
  float v91; // xmm5_4
  __m128 v92; // xmm3
  __m128 v93; // xmm4
  float v94; // xmm1_4
  float v95; // xmm12_4
  float v96; // xmm3_4
  __m128 v97; // xmm4
  float v98; // xmm4_4
  UFG::SimObjectGame **p_m_pPointer; // rbx
  UFG::SimObjectGame *v100; // rcx
  __int16 v101; // dx
  UFG::VehicleEffectsComponent *ComponentOfTypeHK; // rax
  float v103; // xmm3_4
  float v104; // xmm10_4
  float v105; // xmm11_4
  float v106; // xmm3_4
  __m128 v107; // xmm2
  float v108; // xmm5_4
  float v109; // xmm1_4
  float v110; // xmm4_4
  float v111; // xmm5_4
  float v112; // xmm2_4
  float v113; // xmm8_4
  float v114; // xmm4_4
  float v115; // xmm5_4
  float v116; // xmm1_4
  float v117; // xmm5_4
  float v118; // xmm4_4
  float v119; // xmm2_4
  float v120; // xmm3_4
  float v121; // xmm3_4
  bool mFlipped; // al
  float v123; // xmm0_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  float v126; // xmm12_4
  float v127; // xmm13_4
  float v128; // xmm14_4
  float v129; // xmm10_4
  float v130; // xmm9_4
  __m128 v131; // xmm2
  float v132; // xmm1_4
  float v133; // xmm9_4
  float v134; // xmm10_4
  float v135; // xmm5_4
  __m128 v136; // xmm2
  float v137; // xmm4_4
  float v138; // xmm1_4
  float v139; // xmm3_4
  float v140; // xmm4_4
  float v141; // xmm2_4
  float v142; // xmm8_4
  float v143; // xmm3_4
  float v144; // xmm4_4
  float v145; // xmm1_4
  float v146; // xmm11_4
  float v147; // xmm3_4
  float v148; // xmm2_4
  float v149; // xmm4_4
  float v150; // xmm6_4
  UFG::SimObjectCVBase *v151; // rcx
  __int16 v152; // dx
  UFG::ActiveAIEntityComponent *v153; // rax
  UFG::ActiveAIEntityComponent *v154; // rbx
  UFG::SimObjectGame *v155; // rcx
  __int16 v156; // dx
  UFG::AIScriptInterfaceComponent *v157; // rdi
  UFG::SimComponent *v158; // rax
  UFG::SimObject *v159; // rdx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v161; // rbx
  UFG::qSymbol *v162; // rax
  UFG::SimComponent *v163; // rax
  UFG::qMemoryPool *v164; // rax
  UFG::allocator::free_link *v165; // rbx
  unsigned int v166; // eax
  UFG::TransformNodeComponent *v167; // rax
  UFG::TransformNodeComponent *v168; // rsi
  UFG::qVector4 v169; // xmm3
  UFG::SimObject *v170; // rdx
  __int16 v171; // cx
  unsigned int v172; // ebx
  UFG::SimObject *v173; // rcx
  __int16 v174; // dx
  UFG::TSActorComponent *v175; // rbx
  UFG::TSActor *Actor; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-90h] BYREF
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-80h] BYREF
  UFG::qMatrix44 v179; // [rsp+80h] [rbp-40h] BYREF
  UFG::qMatrix44 v180; // [rsp+C0h] [rbp+0h] BYREF
  UFG::qMatrix44 v181; // [rsp+100h] [rbp+40h] BYREF
  UFG::qMatrix44 m; // [rsp+140h] [rbp+80h] BYREF
  __int64 v183; // [rsp+180h] [rbp+C0h]
  UFG::qSymbol v184[2]; // [rsp+280h] [rbp+1C0h] BYREF
  UFG::qSymbol objName; // [rsp+288h] [rbp+1C8h] BYREF
  ASymbol v186[2]; // [rsp+290h] [rbp+1D0h] BYREF
  UFG::allocator::free_link *v187; // [rsp+298h] [rbp+1D8h] BYREF

  v183 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = 0;
  xform.v2.z = 0.0;
  this->mDesiredStatus = 1;
  if ( this->mActiveStatus )
    return;
  ClosestRoadSegment = UFG::CopRoadBlock::FindClosestRoadSegment(this);
  v5 = ClosestRoadSegment;
  if ( ClosestRoadSegment )
  {
    UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(
      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
      ClosestRoadSegment);
    UFG::WheeledVehicleManager::DestroyCarsOnRoad(UFG::WheeledVehicleManager::m_Instance, v5);
  }
  v1->mActiveStatus = 1;
  mpXformNode = v1->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  x = mpXformNode->mWorldTransform.v0.x;
  xform.v2.y = mpXformNode->mWorldTransform.v0.y;
  xform.v1.z = mpXformNode->mWorldTransform.v0.z;
  v8 = mpXformNode->mWorldTransform.v1.x;
  *(float *)&v187 = v8;
  y_low = (__m128)LODWORD(mpXformNode->mWorldTransform.v1.y);
  v186[0] = LODWORD(mpXformNode->mWorldTransform.v1.y);
  z = mpXformNode->mWorldTransform.v1.z;
  xform.v2.x = z;
  w = mpXformNode->mWorldTransform.v3.x;
  xform.v2.w = w;
  y = mpXformNode->mWorldTransform.v3.y;
  xform.v0.x = y;
  v13 = mpXformNode->mWorldTransform.v3.z;
  xform.v1.w = v13;
  if ( v1->mAutoFillLanes )
  {
    LODWORD(xform.v0.x) = (unsigned __int8)v5->mNumLanes;
    if ( !LODWORD(xform.v0.x) )
      goto LABEL_181;
    v14 = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(z * z);
    mObjects = v1->mObjects;
    v16 = z;
    while ( 1 )
    {
      v17 = FLOAT_3_4028235e38;
      UFG::RoadNetworkNode::GetPos(v5, &result, v2, 0.0);
      Lane = UFG::RoadNetworkNode::GetLane(v5, v2);
      v19 = 1.0 / UFG::RoadNetworkLane::GetLength(Lane);
      v20 = 0.0;
      do
      {
        UFG::RoadNetworkNode::GetPos(v5, (UFG::qVector3 *)&xform.v0.z, v2, v20);
        if ( (float)((float)((float)((float)(xform.v0.w - y) * (float)(xform.v0.w - y))
                           + (float)((float)(xform.v0.z - w) * (float)(xform.v0.z - w)))
                   + (float)((float)(xform.v1.x - v13) * (float)(xform.v1.x - v13))) < v17 )
        {
          v17 = (float)((float)((float)(xform.v0.w - y) * (float)(xform.v0.w - y))
                      + (float)((float)(xform.v0.z - w) * (float)(xform.v0.z - w)))
              + (float)((float)(xform.v1.x - v13) * (float)(xform.v1.x - v13));
          UFG::RoadNetworkLane::IsReversedInNode(Lane);
          result = *(UFG::qVector3 *)&xform.v0.z;
        }
        v20 = v20 + v19;
      }
      while ( v20 < 1.0 );
      v21 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&xform.v2.y, sRoadBlockItemPrefix);
      UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v21);
      PropertySet = UFG::PropertySetManager::GetPropertySet(&qSymbolX_propset_vehicle_police);
      v23 = UFG::SceneObjectProperties::Create(&objName, 0i64, PropertySet);
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v23,
        (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
        &qSymbol_Critical);
      v24 = UFG::SceneObjectProperties::Activate(v23, 3u, 0i64, 0i64);
      if ( v24 )
      {
        UFG::SpawnInfoInterface::ClearSpawnLocation(v23, UnReferenced);
        UFG::SpawnInfoInterface::ActivateObjectPost(v23, 0, 0i64, PropertySet, 0);
      }
      else
      {
        if ( v23 )
        {
          v25 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v1.z, v23->m_NameUID);
          v26 = UFG::qSymbol::as_cstr_dbg(v25);
        }
        else
        {
          v26 = "<NULL>";
        }
        UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v26);
      }
      if ( mObjects->m_pPointer )
      {
        mPrev = mObjects->mPrev;
        mNext = mObjects->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        mObjects->mPrev = mObjects;
        mObjects->mNext = mObjects;
      }
      mObjects->m_pPointer = v24;
      if ( v24 )
      {
        v29 = v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v29->mNext = mObjects;
        mObjects->mPrev = v29;
        mObjects->mNext = &v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = mObjects;
      }
      if ( v14 == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / fsqrt(v14);
      v31 = v30 * *(float *)&v187;
      v32 = v30 * *(float *)&v186[0].i_uid;
      v33 = v30 * v16;
      xform.v0.x = v31;
      xform.v0.y = v32;
      xform.v0.z = v33;
      xform.v0.w = 0.0;
      x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( x_low.m128_f32[0] == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
      v36 = v35 * UFG::qVector3::msDirUp.x;
      v37 = v35 * UFG::qVector3::msDirUp.y;
      v38 = v35 * UFG::qVector3::msDirUp.z;
      v39 = (float)(v37 * v33) - (float)(v38 * v32);
      v40 = (float)(v38 * v31) - (float)(v36 * v33);
      v41 = (float)(v36 * v32) - (float)(v37 * v31);
      v42 = (float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42 == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / fsqrt(v42);
      xform.v1.x = v39 * v43;
      xform.v1.y = v40 * v43;
      xform.v1.z = v41 * v43;
      xform.v1.w = 0.0;
      v44 = (float)((float)(v41 * v43) * v32) - (float)((float)(v40 * v43) * v33);
      v45 = (float)((float)(v39 * v43) * v33) - (float)((float)(v41 * v43) * v31);
      v46 = (float)((float)(v40 * v43) * v31) - (float)((float)(v39 * v43) * v32);
      v47 = (float)((float)(v45 * v45) + (float)(v44 * v44)) + (float)(v46 * v46);
      if ( v47 == 0.0 )
        v48 = 0.0;
      else
        v48 = 1.0 / fsqrt(v47);
      xform.v2.x = v44 * v48;
      xform.v2.y = v45 * v48;
      xform.v2.z = v46 * v48;
      xform.v2.w = 0.0;
      xform.v3.x = result.x;
      xform.v3.y = result.y;
      xform.v3.z = result.z;
      xform.v3.w = 1.0;
      UFG::SimObjectUtility::Teleport(mObjects->m_pPointer, &xform);
      m_pPointer = (UFG::SimObjectGame *)mObjects->m_pPointer;
      if ( !m_pPointer )
        goto LABEL_44;
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_40;
      if ( m_Flags < 0 )
      {
        m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
        goto LABEL_42;
      }
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_40:
        m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::VehicleEffectsComponent::_TypeUID);
      else
        m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::VehicleEffectsComponent::_TypeUID);
LABEL_42:
      if ( m_pComponent )
        UFG::VehicleEffectsComponent::TurnOnCopLights(m_pComponent);
LABEL_44:
      ++v2;
      ++mObjects;
      w = xform.v2.w;
      if ( v2 >= LODWORD(xform.v0.x) )
      {
        v1 = *(UFG::CopRoadBlock **)&v184[0].mUID;
        goto LABEL_181;
      }
    }
  }
  v52 = (float)(z * 3.0) + v13;
  v53 = (float)(y_low.m128_f32[0] * 3.0) + xform.v0.x;
  xform.v3.x = (float)(v8 * 3.0) + w;
  xform.v3.y = xform.v1.w - (float)(z * 3.0);
  xform.v3.w = xform.v0.x - (float)(y_low.m128_f32[0] * 3.0);
  xform.v3.z = w - (float)(v8 * 3.0);
  UFG::qSymbol::create_from_string(&objName, sRoadBlockItemPrefix_0);
  UFG::SimObjectUtility::GenerateUniqueActorName(v184, &objName);
  v54 = UFG::PropertySetManager::GetPropertySet(&qSymbolX_propset_vehicle_police);
  v55 = UFG::SceneObjectProperties::Create(v184, 0i64, v54);
  PropertyUtils::SetRuntime<UFG::qSymbol>(
    v55,
    (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
    &qSymbol_Critical);
  v56 = 3i64;
  v57 = UFG::SceneObjectProperties::Activate(v55, 3u, 0i64, 0i64);
  if ( v57 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v55, UnReferenced);
    UFG::SpawnInfoInterface::ActivateObjectPost(v55, 0, 0i64, v54, 0);
  }
  else
  {
    if ( v55 )
    {
      v58 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v55->m_NameUID);
      v59 = UFG::qSymbol::as_cstr_dbg(v58);
    }
    else
    {
      v59 = "<NULL>";
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v59);
  }
  v60 = v1->mObjects;
  if ( v1->mObjects[0].m_pPointer )
  {
    v61 = v60->mPrev;
    v62 = v1->mObjects[0].mNext;
    v61->mNext = v62;
    v62->mPrev = v61;
    v60->mPrev = v60;
    v1->mObjects[0].mNext = v1->mObjects;
  }
  v1->mObjects[0].m_pPointer = v57;
  if ( v57 )
  {
    v63 = v57->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v63->mNext = v60;
    v60->mPrev = v63;
    v1->mObjects[0].mNext = &v57->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v57->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v60;
  }
  v184[0] = (UFG::qSymbol)UFG::SimObjectUtility::GenerateUniqueActorName((UFG::qSymbol *)&xform.v0.y, &objName)->mUID;
  v64 = UFG::PropertySetManager::GetPropertySet(&qSymbolX_propset_vehicle_police);
  v65 = UFG::SceneObjectProperties::Create(v184, 0i64, v64);
  PropertyUtils::SetRuntime<UFG::qSymbol>(
    v65,
    (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
    &qSymbol_Critical);
  v66 = UFG::SceneObjectProperties::Activate(v65, 3u, 0i64, 0i64);
  if ( v66 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v65, UnReferenced);
    UFG::SpawnInfoInterface::ActivateObjectPost(v65, 0, 0i64, v64, 0);
  }
  else
  {
    if ( v65 )
    {
      v67 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v65->m_NameUID);
      v68 = UFG::qSymbol::as_cstr_dbg(v67);
    }
    else
    {
      v68 = "<NULL>";
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v68);
  }
  v69 = &v1->mObjects[1];
  if ( v1->mObjects[1].m_pPointer )
  {
    v70 = v69->mPrev;
    v71 = v1->mObjects[1].mNext;
    v70->mNext = v71;
    v71->mPrev = v70;
    v69->mPrev = v69;
    v1->mObjects[1].mNext = &v1->mObjects[1];
  }
  v1->mObjects[1].m_pPointer = v66;
  if ( v66 )
  {
    v72 = v66->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v72->mNext = v69;
    v69->mPrev = v72;
    v1->mObjects[1].mNext = &v66->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v66->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v69;
  }
  v184[0] = (UFG::qSymbol)UFG::SimObjectUtility::GenerateUniqueActorName((UFG::qSymbol *)&xform.v0.y, &objName)->mUID;
  v73 = UFG::PropertySetManager::GetPropertySet(&qSymbolX_propset_character_police);
  v74 = UFG::SceneObjectProperties::Create(v184, 0i64, v73);
  PropertyUtils::SetRuntime<UFG::qSymbol>(
    v74,
    (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
    &qSymbol_Critical);
  v75 = UFG::SceneObjectProperties::Activate(v74, 3u, 0i64, 0i64);
  if ( v75 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v74, UnReferenced);
    UFG::SpawnInfoInterface::ActivateObjectPost(v74, 0, 0i64, v73, 0);
  }
  else
  {
    if ( v74 )
    {
      v76 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v74->m_NameUID);
      v77 = UFG::qSymbol::as_cstr_dbg(v76);
    }
    else
    {
      v77 = "<NULL>";
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v77);
  }
  v78 = &v1->mObjects[2];
  if ( v1->mObjects[2].m_pPointer )
  {
    v79 = v78->mPrev;
    v80 = v1->mObjects[2].mNext;
    v79->mNext = v80;
    v80->mPrev = v79;
    v78->mPrev = v78;
    v1->mObjects[2].mNext = &v1->mObjects[2];
  }
  v1->mObjects[2].m_pPointer = v75;
  if ( v75 )
  {
    v81 = v75->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v81->mNext = v78;
    v78->mPrev = v81;
    v1->mObjects[2].mNext = &v75->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v75->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v78;
  }
  v82 = y_low;
  v82.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(z * z);
  if ( v82.m128_f32[0] == 0.0 )
    v83 = 0.0;
  else
    v83 = 1.0 / _mm_sqrt_ps(v82).m128_f32[0];
  v84 = z * v83;
  v85 = *(float *)&v186[0].i_uid * v83;
  v86 = *(float *)&v187 * v83;
  v179.v0.x = *(float *)&v187 * v83;
  v179.v0.y = *(float *)&v186[0].i_uid * v83;
  v179.v0.z = v84;
  v179.v0.w = 0.0;
  v87 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v87.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v87.m128_f32[0] == 0.0 )
  {
    v88 = 0i64;
  }
  else
  {
    v88 = (__m128)(unsigned int)FLOAT_1_0;
    v88.m128_f32[0] = 1.0 / _mm_sqrt_ps(v87).m128_f32[0];
  }
  v89 = v88.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v92 = v88;
  v92.m128_f32[0] = v88.m128_f32[0] * UFG::qVector3::msDirUp.y;
  v88.m128_f32[0] = v88.m128_f32[0] * UFG::qVector3::msDirUp.x;
  v90 = v88;
  v90.m128_f32[0] = (float)(v88.m128_f32[0] * v85) - (float)(v86 * v92.m128_f32[0]);
  v91 = (float)(v86 * v89) - (float)(v88.m128_f32[0] * v84);
  v92.m128_f32[0] = (float)(v92.m128_f32[0] * v84) - (float)(v89 * v85);
  v93 = v92;
  v93.m128_f32[0] = (float)((float)(v92.m128_f32[0] * v92.m128_f32[0]) + (float)(v91 * v91))
                  + (float)(v90.m128_f32[0] * v90.m128_f32[0]);
  if ( v93.m128_f32[0] == 0.0 )
    v94 = 0.0;
  else
    v94 = 1.0 / _mm_sqrt_ps(v93).m128_f32[0];
  v179.v1.x = v92.m128_f32[0] * v94;
  v179.v1.y = v91 * v94;
  v179.v1.z = v90.m128_f32[0] * v94;
  v179.v1.w = 0.0;
  v95 = (float)(v86 * (float)(v91 * v94)) - (float)((float)(v92.m128_f32[0] * v94) * v85);
  v96 = (float)((float)(v92.m128_f32[0] * v94) * v84) - (float)(v86 * (float)(v90.m128_f32[0] * v94));
  v90.m128_f32[0] = (float)((float)(v90.m128_f32[0] * v94) * v85) - (float)((float)(v91 * v94) * v84);
  v97 = v90;
  v97.m128_f32[0] = (float)((float)(v90.m128_f32[0] * v90.m128_f32[0]) + (float)(v96 * v96)) + (float)(v95 * v95);
  if ( v97.m128_f32[0] == 0.0 )
    v98 = 0.0;
  else
    v98 = 1.0 / _mm_sqrt_ps(v97).m128_f32[0];
  v179.v2.x = v90.m128_f32[0] * v98;
  v179.v2.y = v98 * v96;
  v179.v2.z = v98 * v95;
  v179.v2.w = 0.0;
  v179.v3.x = xform.v3.x;
  v179.v3.y = v53;
  v179.v3.z = v52;
  v179.v3.w = 1.0;
  p_m_pPointer = (UFG::SimObjectGame **)&v1->mObjects[0].m_pPointer;
  UFG::SimObjectUtility::Teleport(v1->mObjects[0].m_pPointer, &v179);
  do
  {
    v100 = *p_m_pPointer;
    if ( !*p_m_pPointer )
      goto LABEL_100;
    v101 = v100->m_Flags;
    if ( (v101 & 0x4000) != 0 )
      goto LABEL_96;
    if ( v101 < 0 )
    {
      ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)v100->m_Components.p[32].m_pComponent;
      goto LABEL_98;
    }
    if ( (v101 & 0x2000) != 0 || (v101 & 0x1000) != 0 )
LABEL_96:
      ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v100,
                                                            UFG::VehicleEffectsComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                            v100,
                                                            UFG::VehicleEffectsComponent::_TypeUID);
LABEL_98:
    if ( ComponentOfTypeHK )
      UFG::VehicleEffectsComponent::TurnOnCopLights(ComponentOfTypeHK);
LABEL_100:
    p_m_pPointer += 3;
    --v56;
  }
  while ( v56 );
  if ( v82.m128_f32[0] == 0.0 )
    v103 = 0.0;
  else
    v103 = 1.0 / fsqrt(v82.m128_f32[0]);
  v104 = xform.v2.x * v103;
  v105 = *(float *)&v186[0].i_uid * v103;
  v106 = v103 * *(float *)&v187;
  v180.v0.x = v106;
  v180.v0.y = v105;
  v180.v0.z = v104;
  v180.v0.w = 0.0;
  v107 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v107.m128_f32[0] = (float)((float)(v107.m128_f32[0] * v107.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v107.m128_f32[0] == 0.0 )
    v108 = 0.0;
  else
    v108 = 1.0 / _mm_sqrt_ps(v107).m128_f32[0];
  v109 = v108 * UFG::qVector3::msDirUp.z;
  v110 = v108 * UFG::qVector3::msDirUp.y;
  v111 = v108 * UFG::qVector3::msDirUp.x;
  v112 = (float)(v111 * v105) - (float)(v106 * v110);
  v113 = (float)(v106 * v109) - (float)(v111 * v104);
  v114 = (float)(v110 * v104) - (float)(v109 * v105);
  v115 = (float)((float)(v114 * v114) + (float)(v113 * v113)) + (float)(v112 * v112);
  if ( v115 == 0.0 )
    v116 = 0.0;
  else
    v116 = 1.0 / fsqrt(v115);
  v180.v1.x = v114 * v116;
  v180.v1.y = v113 * v116;
  v180.v1.z = v112 * v116;
  v180.v1.w = 0.0;
  v117 = (float)(v106 * (float)(v113 * v116)) - (float)((float)(v114 * v116) * v105);
  v118 = (float)((float)(v114 * v116) * v104) - (float)(v106 * (float)(v112 * v116));
  v119 = (float)((float)(v112 * v116) * v105) - (float)((float)(v113 * v116) * v104);
  v120 = (float)((float)(v119 * v119) + (float)(v118 * v118)) + (float)(v117 * v117);
  if ( v120 == 0.0 )
    v121 = 0.0;
  else
    v121 = 1.0 / fsqrt(v120);
  v180.v2.x = v119 * v121;
  v180.v2.y = v121 * v118;
  v180.v2.z = v121 * v117;
  v180.v2.w = 0.0;
  v180.v3.x = xform.v3.z;
  v180.v3.y = xform.v3.w;
  v180.v3.z = xform.v3.y;
  v180.v3.w = 1.0;
  UFG::SimObjectUtility::Teleport(v1->mObjects[1].m_pPointer, &v180);
  mFlipped = v1->mFlipped;
  if ( mFlipped )
    v123 = FLOAT_N2_0;
  else
    v123 = FLOAT_2_0;
  v124 = xform.v1.z;
  v125 = xform.v2.y;
  v126 = (float)(xform.v1.z * v123) + xform.v1.w;
  v127 = (float)(xform.v2.y * v123) + xform.v0.x;
  v128 = (float)(x * v123) + xform.v2.w;
  if ( mFlipped )
  {
    LODWORD(v124) = LODWORD(xform.v1.z) ^ _xmm[0];
    LODWORD(v125) = LODWORD(xform.v2.y) ^ _xmm[0];
    LODWORD(x) ^= _xmm[0];
  }
  result.z = v124;
  result.y = v125;
  result.x = x;
  v129 = v125;
  v130 = v124;
  v131 = (__m128)LODWORD(x);
  v131.m128_f32[0] = (float)((float)(v131.m128_f32[0] * v131.m128_f32[0]) + (float)(v129 * v129)) + (float)(v130 * v130);
  if ( v131.m128_f32[0] == 0.0 )
    v132 = 0.0;
  else
    v132 = 1.0 / _mm_sqrt_ps(v131).m128_f32[0];
  v133 = v130 * v132;
  v134 = v129 * v132;
  v135 = x * v132;
  v181.v0.x = x * v132;
  v181.v0.y = v134;
  v181.v0.z = v133;
  v181.v0.w = 0.0;
  v136 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v136.m128_f32[0] = (float)((float)(v136.m128_f32[0] * v136.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v136.m128_f32[0] == 0.0 )
    v137 = 0.0;
  else
    v137 = 1.0 / _mm_sqrt_ps(v136).m128_f32[0];
  v138 = v137 * UFG::qVector3::msDirUp.z;
  v139 = v137 * UFG::qVector3::msDirUp.y;
  v140 = v137 * UFG::qVector3::msDirUp.x;
  v141 = (float)(v140 * v134) - (float)(v135 * v139);
  v142 = (float)(v135 * v138) - (float)(v140 * v133);
  v143 = (float)(v139 * v133) - (float)(v138 * v134);
  v144 = (float)((float)(v143 * v143) + (float)(v142 * v142)) + (float)(v141 * v141);
  if ( v144 == 0.0 )
    v145 = 0.0;
  else
    v145 = 1.0 / fsqrt(v144);
  v181.v1.x = v143 * v145;
  v181.v1.y = v142 * v145;
  v181.v1.z = v141 * v145;
  v181.v1.w = 0.0;
  v146 = (float)(v135 * (float)(v142 * v145)) - (float)((float)(v143 * v145) * v134);
  v147 = (float)((float)(v143 * v145) * v133) - (float)(v135 * (float)(v141 * v145));
  v148 = (float)((float)(v141 * v145) * v134) - (float)((float)(v142 * v145) * v133);
  v149 = (float)((float)(v148 * v148) + (float)(v147 * v147)) + (float)(v146 * v146);
  if ( v149 == 0.0 )
    v150 = 0.0;
  else
    v150 = 1.0 / fsqrt(v149);
  v181.v2.x = v148 * v150;
  v181.v2.y = v150 * v147;
  v181.v2.z = v150 * v146;
  v181.v2.w = 0.0;
  v181.v3.x = v128;
  v181.v3.y = (float)(xform.v2.y * v123) + xform.v0.x;
  v181.v3.z = (float)(xform.v1.z * v123) + xform.v1.w;
  v181.v3.w = 1.0;
  UFG::SimObjectUtility::Teleport(v1->mObjects[2].m_pPointer, &v181);
  v151 = (UFG::SimObjectCVBase *)v1->mObjects[2].m_pPointer;
  if ( v151 )
  {
    v152 = v151->m_Flags;
    if ( (v152 & 0x4000) != 0 || v152 < 0 )
      v153 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v151);
    else
      v153 = (UFG::ActiveAIEntityComponent *)((v152 & 0x2000) != 0 || (v152 & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v151,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                v151,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
    v154 = v153;
    if ( v153 )
    {
      UFG::ActiveAIEntityComponent::SetCurrentObjective(v153, eAI_OBJECTIVE_PURSUIT_TARGET, "CopRoadBlock");
      v154->m_MaxEngagementDistanceXY = 50.0;
      v154->m_MaxEngagementDistanceZ = 50.0;
      v155 = (UFG::SimObjectGame *)v1->mObjects[2].m_pPointer;
      if ( v155 )
      {
        v156 = v155->m_Flags;
        if ( (v156 & 0x4000) != 0 )
        {
          v157 = (UFG::AIScriptInterfaceComponent *)v155->m_Components.p[5].m_pComponent;
        }
        else if ( v156 >= 0 )
        {
          v158 = (v156 & 0x2000) != 0 || (v156 & 0x1000) != 0
               ? UFG::SimObjectGame::GetComponentOfTypeHK(v155, UFG::AIScriptInterfaceComponent::_TypeUID)
               : UFG::SimObject::GetComponentOfType(v155, UFG::AIScriptInterfaceComponent::_TypeUID);
          v157 = (UFG::AIScriptInterfaceComponent *)v158;
        }
        else
        {
          v157 = (UFG::AIScriptInterfaceComponent *)v155->m_Components.p[5].m_pComponent;
        }
        if ( v157 )
        {
          v159 = v1->mPositionToDefendObject.m_pPointer;
          if ( v159 )
            UFG::Simulation::DestroySimObject(&UFG::gSim, v159);
          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
          v161 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x80ui64, "CopRoadBlock::Spawn()", 0i64, 1u);
          v187 = v161;
          if ( v161 )
          {
            v3 = 1;
            LODWORD(xform.v2.z) = 1;
            v162 = UFG::qSymbol::create_from_string((UFG::qSymbol *)v186, "RoadblockPositionToDefend");
            UFG::SimObject::SimObject((UFG::SimObject *)v161, v162);
          }
          else
          {
            v163 = 0i64;
          }
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->mPositionToDefendObject,
            v163);
          if ( (v3 & 1) != 0 )
            LODWORD(xform.v2.z) = v3 & 0xFFFFFFFE;
          v164 = UFG::GetSimulationMemoryPool();
          v165 = UFG::qMemoryPool::Allocate(v164, 0x110ui64, "CopRoadBlock::Spawn()", 0i64, 1u);
          *(_QWORD *)&v186[0].i_uid = v165;
          if ( v165 )
          {
            v166 = UFG::qStringHash32("RoadblockPositionToDefendTransformNode", 0xFFFFFFFF);
            UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v165, v166, 0i64, 0);
            v168 = v167;
          }
          else
          {
            v168 = 0i64;
          }
          v169 = 0i64;
          v169.x = (float)1;
          m.v0 = v169;
          m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v169, (__m128)v169, 81);
          m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v169, (__m128)v169, 69);
          m.v3.x = v128;
          m.v3.y = v127;
          m.v3.z = v126;
          m.v3.w = 1.0;
          UFG::TransformNodeComponent::SetWorldTransform(v168, &m);
          v170 = v1->mPositionToDefendObject.m_pPointer;
          v171 = v170->m_Flags;
          if ( (v171 & 0x4000) != 0 )
          {
            v172 = 2;
          }
          else if ( v171 >= 0 )
          {
            if ( (v171 & 0x2000) != 0 )
            {
              v172 = 2;
            }
            else
            {
              v172 = -1;
              if ( (v171 & 0x1000) != 0 )
                v172 = 1;
            }
          }
          else
          {
            v172 = 2;
          }
          UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&xform, v170, 1);
          UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&xform, v168, v172);
          UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&xform);
          UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&xform);
          UFG::AIScriptInterfaceComponent::SetPositionToDefend(
            v157,
            v1->mPositionToDefendObject.m_pPointer,
            10.0,
            0,
            0,
            0);
        }
      }
      v173 = v1->mObjects[2].m_pPointer;
      if ( v173 )
      {
        v174 = v173->m_Flags;
        if ( (v174 & 0x4000) != 0 )
        {
          v175 = (UFG::TSActorComponent *)v173->m_Components.p[4].m_pComponent;
        }
        else if ( v174 >= 0 )
        {
          if ( (v174 & 0x2000) != 0 )
            v175 = (UFG::TSActorComponent *)v173->m_Components.p[3].m_pComponent;
          else
            v175 = (UFG::TSActorComponent *)((v174 & 0x1000) != 0
                                           ? v173->m_Components.p[2].m_pComponent
                                           : UFG::SimObject::GetComponentOfType(v173, UFG::TSActorComponent::_TypeUID));
        }
        else
        {
          v175 = (UFG::TSActorComponent *)v173->m_Components.p[4].m_pComponent;
        }
        if ( v175 )
        {
          ASymbol::create(v186, "equip_firearm", 0xFFFFFFFF, ATerm_long);
          v187 = 0i64;
          Actor = UFG::TSActorComponent::GetActor(v175);
          ((void (__fastcall *)(UFG::TSActor *, ASymbol *, UFG::allocator::free_link **, bool, _QWORD, _QWORD, _QWORD, _DWORD))Actor->vfptr[1].set_data_by_name)(
            Actor,
            v186,
            &v187,
            v187 != 0i64,
            0i64,
            0i64,
            *(_QWORD *)&result.x,
            LODWORD(result.z));
        }
      }
    }
  }
LABEL_181:
  UFG::SimObjectUtility::AttachHudSymbol(v1->m_pSimObject, "roadblock_symbol", 0, 0.0, &customCaption);
}

// File Line: 305
// RVA: 0x5B3360
void __fastcall UFG::CopRoadBlock::Despawn(UFG::CopRoadBlock *this)
{
  bool v1; // zf
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mPositionToDefendObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::WheeledVehicleManager *v7; // rsi
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::TransformNodeComponent *mpXformNode; // rbx
  UFG::RoadNetworkResource *v10; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  UFG::RoadNetworkNode *v14; // rbx
  UFG::SimObject **p_m_pPointer; // rdi
  __int64 v16; // rbp
  UFG::SimObjectGame *v17; // rbx
  __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rsi
  UFG::SimObjectGame *v20; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v22; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v24; // rcx
  _QWORD *v25; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-28h] BYREF
  unsigned int p_segment_index; // [rsp+60h] [rbp+8h] BYREF

  v1 = !this->mActiveStatus;
  this->mDesiredStatus = 0;
  if ( !v1 )
  {
    m_pPointer = this->mPositionToDefendObject.m_pPointer;
    this->mActiveStatus = 0;
    if ( m_pPointer )
    {
      UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
      p_mPositionToDefendObject = &this->mPositionToDefendObject;
      if ( this->mPositionToDefendObject.m_pPointer )
      {
        mPrev = p_mPositionToDefendObject->mPrev;
        mNext = this->mPositionToDefendObject.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mPositionToDefendObject->mPrev = p_mPositionToDefendObject;
        this->mPositionToDefendObject.mNext = &this->mPositionToDefendObject;
      }
      this->mPositionToDefendObject.m_pPointer = 0i64;
    }
    v7 = UFG::WheeledVehicleManager::m_Instance;
    RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    mpXformNode = this->mpXformNode;
    v10 = RoadNetwork;
    UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
    y = mpXformNode->mWorldTransform.v3.y;
    z = mpXformNode->mWorldTransform.v3.z;
    pos.x = mpXformNode->mWorldTransform.v3.x;
    pos.y = y;
    pos.z = z;
    p_segment_index = -1;
    ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(v10, &pos, &p_segment_index, 0);
    v14 = ClosestSegment;
    if ( ClosestSegment )
    {
      UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(v7->m_NavigationData, ClosestSegment);
      UFG::WheeledVehicleManager::DestroyCarsOnRoad(v7, v14);
    }
    p_m_pPointer = &this->mObjects[0].m_pPointer;
    v16 = 6i64;
    while ( 1 )
    {
      v17 = (UFG::SimObjectGame *)*p_m_pPointer;
      if ( *p_m_pPointer )
        break;
LABEL_36:
      p_m_pPointer += 3;
      if ( !--v16 )
      {
        UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
        return;
      }
    }
    m_Flags = v17->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)v17->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)v17->m_Components.p[7].m_pComponent;
      }
      else
      {
        v1 = (m_Flags & 0x1000) == 0;
        v20 = (UFG::SimObjectGame *)*p_m_pPointer;
        if ( v1 )
          ComponentOfType = UFG::SimObject::GetComponentOfType(v20, UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfType;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)v17->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(m_pComponent, &qSymbol_Low);
      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(m_pComponent, &qSymbol_Critical);
    }
    v22 = v17->m_Flags;
    if ( (v22 & 0x4000) != 0 )
      goto LABEL_28;
    if ( v22 < 0 )
    {
      ComponentOfTypeHK = v17->m_Components.p[30].m_pComponent;
      goto LABEL_30;
    }
    if ( (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
LABEL_28:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::VehicleOccupantComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v17, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_30:
    if ( !ComponentOfTypeHK
      || !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)ComponentOfTypeHK) )
    {
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, *p_m_pPointer);
    }
    if ( *p_m_pPointer )
    {
      v24 = (__int64)*(p_m_pPointer - 2);
      v25 = *(p_m_pPointer - 1);
      *(_QWORD *)(v24 + 8) = v25;
      *v25 = v24;
      *(p_m_pPointer - 2) = (UFG::SimObject *)(p_m_pPointer - 2);
      *(p_m_pPointer - 1) = (UFG::SimObject *)(p_m_pPointer - 2);
    }
    *p_m_pPointer = 0i64;
    goto LABEL_36;
  }
}

// File Line: 371
// RVA: 0x5B3600
UFG::RoadNetworkSegment *__fastcall UFG::CopRoadBlock::FindClosestRoadSegment(UFG::CopRoadBlock *this)
{
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::TransformNodeComponent *mpXformNode; // rbx
  UFG::RoadNetworkResource *v4; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h] BYREF
  unsigned int p_segment_index; // [rsp+50h] [rbp+8h] BYREF

  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  mpXformNode = this->mpXformNode;
  v4 = RoadNetwork;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  y = mpXformNode->mWorldTransform.v3.y;
  z = mpXformNode->mWorldTransform.v3.z;
  pos.x = mpXformNode->mWorldTransform.v3.x;
  pos.y = y;
  pos.z = z;
  p_segment_index = -1;
  return UFG::RoadNetworkResource::GetClosestSegment(v4, &pos, &p_segment_index, 0);
}

