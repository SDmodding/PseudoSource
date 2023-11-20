// File Line: 28
// RVA: 0x155D500
__int64 dynamic_initializer_for__UFG::CopRoadBlock::s_CopRoadBlockList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CopRoadBlock::s_CopRoadBlockList__);
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
  UFG::CopRoadBlock *v3; // r14
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v4; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rbx
  signed __int64 v6; // rsi
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // [rsp+78h] [rbp+20h]

  v3 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  v4 = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopRoadBlock::`vftable;
  v5 = v3->mObjects;
  v6 = 6i64;
  `eh vector constructor iterator(
    v3->mObjects,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v10 = &v3->mPositionToDefendObject;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v3->mPositionToDefendObject.m_pPointer = 0i64;
  *(_DWORD *)&v3->mAutoFillLanes = 1;
  v7 = UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev;
  UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev->mNext = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&v3->mPrev;
  v4->mPrev = v7;
  v3->mNext = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&UFG::CopRoadBlock::s_CopRoadBlockList;
  UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mPrev = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&v3->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v3->vfptr, UFG::CopRoadBlock::_CopRoadBlockTypeUID, "CopRoadBlock");
  do
  {
    if ( v5->m_pPointer )
    {
      v8 = v5->mPrev;
      v9 = v5->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    }
    v5->m_pPointer = 0i64;
    ++v5;
    --v6;
  }
  while ( v6 );
}

// File Line: 53
// RVA: 0x5B1DB0
void __fastcall UFG::CopRoadBlock::~CopRoadBlock(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock *v1; // rbx
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v2; // rdi
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v3; // rcx
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v10; // rcx
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopRoadBlock::`vftable;
  if ( this == UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator )
    UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator = (UFG::CopRoadBlock *)&this->mPrev[-7];
  v2 = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mPositionToDefendObject;
  if ( v1->mPositionToDefendObject.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mPositionToDefendObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mPositionToDefendObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPositionToDefendObject.mPrev;
  }
  v1->mPositionToDefendObject.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mPositionToDefendObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mPositionToDefendObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPositionToDefendObject.mPrev;
  `eh vector destructor iterator(
    v1->mObjects,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 59
// RVA: 0x5B4330
bool __fastcall UFG::CopRoadBlock::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentCopRoadBlock.mUID);
}

// File Line: 65
// RVA: 0x5B5260
UFG::CopRoadBlock *__fastcall UFG::CopRoadBlock::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v10; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x130ui64, "CopRoadBlock", 0i64, 1u);
  v10 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::CopRoadBlock::CopRoadBlock((UFG::CopRoadBlock *)v3, v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  *(_BYTE *)(v7 + 296) = PropertyUtils::Get<bool>(v1, (UFG::qSymbol *)&qSymbol_AutoFillLanes.mUID)->mFlags;
  return (UFG::CopRoadBlock *)v7;
}

// File Line: 79
// RVA: 0x5B75F0
void __fastcall UFG::CopRoadBlock::Update(UFG::CopRoadBlock *this, float deltaTime)
{
  bool v2; // al
  UFG::CopRoadBlock *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  v2 = this->mDesiredStatus;
  v3 = this;
  if ( v2 != this->mActiveStatus )
  {
    if ( v2 )
    {
      UFG::CopRoadBlock::Spawn(this);
    }
    else
    {
      v4 = this->mpXformNode;
      UFG::TransformNodeComponent::UpdateWorldTransform(this->mpXformNode);
      if ( !UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v4->mWorldTransform.v3, 2.0, 0) )
        UFG::CopRoadBlock::Despawn(v3);
    }
  }
}

// File Line: 99
// RVA: 0x5B5110
void __fastcall UFG::CopRoadBlock::OnDetach(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock::Despawn(this);
}

// File Line: 106
// RVA: 0x5B26B0
char __fastcall UFG::CopRoadBlock::ActivateByDistance(UFG::CopRoadBlock *this, UFG::qVector3 *origin, float minRadiusSq, float maxRadiusSq, int *pBitfields)
{
  UFG::TransformNodeComponent *v5; // rbx
  UFG::CopRoadBlock *v6; // rdi
  UFG::qVector3 *v7; // rsi
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  signed int v16; // eax
  float *v17; // rbx
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  char result; // al

  v5 = this->mpXformNode;
  v6 = this;
  v7 = origin;
  UFG::TransformNodeComponent::UpdateWorldTransform(this->mpXformNode);
  v8 = v5->mWorldTransform.v3.x;
  v9 = v5->mWorldTransform.v3.y;
  v10 = (float)((float)(v7->y - v9) * (float)(v7->y - v9)) + (float)((float)(v7->x - v8) * (float)(v7->x - v8));
  if ( v10 < minRadiusSq
    || v10 > maxRadiusSq
    || ((v11 = v8 - v7->x, v12 = v9 - v7->y, v13 = v5->mWorldTransform.v3.z - v7->z, v14 = atan2f(v12, v11), v14 >= 0.0) ? (v15 = 0.0) : (v15 = FLOAT_6_2831855),
        v16 = 1 << (signed int)(float)((float)((float)(v15 + v14) * 8.0) * 0.15915494),
        *pBitfields & v16) )
  {
    result = 0;
    v6->mDesiredStatus = 0;
  }
  else
  {
    *pBitfields |= v16;
    v17 = (float *)v6->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v6->mpXformNode);
    v18 = v12 * v17[33];
    v19 = v11 * v17[32];
    v20 = v13 * v17[34];
    v6->mDesiredStatus = 1;
    v6->mFlipped = (float)((float)(v18 + v19) + v20) > 0.0;
    ((void (__fastcall *)(UFG::CopRoadBlock *))v6->vfptr[18].__vecDelDtor)(v6);
    result = 1;
  }
  return result;
}

// File Line: 142
// RVA: 0x5B31D0
void __fastcall UFG::CopRoadBlock::Deactivate(UFG::CopRoadBlock *this)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v1; // rax

  v1 = this->vfptr;
  this->mDesiredStatus = 0;
  ((void (*)(void))v1[18].__vecDelDtor)();
}

// File Line: 148
// RVA: 0x5B58E0
void __fastcall UFG::CopRoadBlock::Spawn(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock *v1; // r13
  unsigned int v2; // er14
  signed int v3; // er15
  UFG::RoadNetworkSegment *v4; // rax
  UFG::RoadNetworkNode *v5; // r12
  UFG::TransformNodeComponent *v6; // rbx
  float v7; // xmm15_4
  float v8; // xmm10_4
  __m128 v9; // xmm6
  float v10; // xmm9_4
  float v11; // xmm11_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm12_4
  signed __int64 v15; // rbx
  float v16; // xmm15_4
  float v17; // xmm8_4
  UFG::RoadNetworkLane *v18; // rdi
  float v19; // xmm9_4
  float v20; // xmm6_4
  UFG::qSymbol *v21; // rax
  UFG::qPropertySet *v22; // r15
  UFG::SceneObjectProperties *v23; // rdi
  UFG::SimObject *v24; // rsi
  UFG::qSymbolUC *v25; // rax
  char *v26; // rax
  __int64 v27; // rcx
  _QWORD *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  float v30; // xmm3_4
  float v31; // xmm9_4
  float v32; // xmm11_4
  float v33; // xmm3_4
  __m128 v34; // xmm5
  __m128 v35; // xmm2
  float v36; // xmm2_4
  float v37; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm6_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm6_4
  float v47; // xmm8_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm1_4
  UFG::SimObjectGame *v51; // rcx
  unsigned __int16 v52; // dx
  UFG::VehicleEffectsComponent *v53; // rax
  float v54; // xmm13_4
  float v55; // xmm14_4
  UFG::qPropertySet *v56; // rsi
  UFG::SceneObjectProperties *v57; // rbx
  signed __int64 v58; // r12
  UFG::SimObject *v59; // rdi
  UFG::qSymbolUC *v60; // rax
  char *v61; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v62; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v63; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v64; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v65; // rax
  UFG::qPropertySet *v66; // rsi
  UFG::SceneObjectProperties *v67; // rbx
  UFG::SimObject *v68; // rdi
  UFG::qSymbolUC *v69; // rax
  char *v70; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v71; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v72; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v73; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v74; // rax
  UFG::qPropertySet *v75; // rsi
  UFG::SceneObjectProperties *v76; // rbx
  UFG::SimObject *v77; // rdi
  UFG::qSymbolUC *v78; // rax
  char *v79; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v80; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v81; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v82; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v83; // rax
  __m128 v84; // xmm8
  float v85; // xmm1_4
  float v86; // xmm10_4
  float v87; // xmm11_4
  float v88; // xmm9_4
  __m128 v89; // xmm5
  __m128 v90; // xmm2
  __m128 v91; // xmm4
  float v92; // xmm1_4
  __m128 v93; // xmm2
  float v94; // xmm5_4
  __m128 v95; // xmm3
  __m128 v96; // xmm4
  float v97; // xmm1_4
  float v98; // xmm3_4
  float v99; // xmm12_4
  float v100; // xmm3_4
  __m128 v101; // xmm4
  float v102; // xmm4_4
  UFG::SimObjectGame **v103; // rbx
  UFG::SimObjectGame *v104; // rcx
  unsigned __int16 v105; // dx
  UFG::VehicleEffectsComponent *v106; // rax
  float v107; // xmm3_4
  float v108; // xmm10_4
  float v109; // xmm11_4
  float v110; // xmm3_4
  __m128 v111; // xmm8
  __m128 v112; // xmm2
  float v113; // xmm5_4
  float v114; // xmm1_4
  float v115; // xmm4_4
  float v116; // xmm5_4
  float v117; // xmm2_4
  float v118; // xmm8_4
  float v119; // xmm4_4
  float v120; // xmm5_4
  float v121; // xmm1_4
  float v122; // xmm2_4
  float v123; // xmm4_4
  float v124; // xmm5_4
  float v125; // xmm4_4
  float v126; // xmm2_4
  float v127; // xmm3_4
  float v128; // xmm3_4
  bool v129; // al
  float v130; // xmm0_4
  float v131; // xmm1_4
  float v132; // xmm2_4
  float v133; // xmm12_4
  float v134; // xmm13_4
  float v135; // xmm14_4
  float v136; // xmm10_4
  __m128 v137; // xmm5
  float v138; // xmm9_4
  __m128 v139; // xmm2
  float v140; // xmm1_4
  float v141; // xmm9_4
  float v142; // xmm10_4
  float v143; // xmm5_4
  __m128 v144; // xmm2
  float v145; // xmm4_4
  float v146; // xmm1_4
  float v147; // xmm3_4
  float v148; // xmm4_4
  float v149; // xmm2_4
  float v150; // xmm8_4
  float v151; // xmm3_4
  float v152; // xmm4_4
  float v153; // xmm1_4
  float v154; // xmm2_4
  float v155; // xmm3_4
  float v156; // xmm11_4
  float v157; // xmm3_4
  float v158; // xmm2_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  UFG::SimObjectCVBase *v161; // rcx
  unsigned __int16 v162; // dx
  UFG::ActiveAIEntityComponent *v163; // rax
  UFG::ActiveAIEntityComponent *v164; // rbx
  UFG::SimObjectGame *v165; // rcx
  unsigned __int16 v166; // dx
  UFG::AIScriptInterfaceComponent *v167; // rdi
  UFG::SimComponent *v168; // rax
  UFG::SimObject *v169; // rdx
  UFG::qMemoryPool *v170; // rax
  UFG::allocator::free_link *v171; // rbx
  UFG::qSymbol *v172; // rax
  UFG::SimComponent *v173; // rax
  UFG::qMemoryPool *v174; // rax
  UFG::allocator::free_link *v175; // rbx
  unsigned int v176; // eax
  UFG::TransformNodeComponent *v177; // rax
  UFG::TransformNodeComponent *v178; // rsi
  UFG::qVector4 v179; // xmm3
  UFG::SimObject *v180; // rdx
  unsigned __int16 v181; // cx
  unsigned int v182; // ebx
  UFG::SimObject *v183; // rcx
  unsigned __int16 v184; // dx
  UFG::TSActorComponent *v185; // rbx
  UFG::TSActor *v186; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-90h]
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-80h]
  UFG::qMatrix44 v189; // [rsp+80h] [rbp-40h]
  UFG::qMatrix44 v190; // [rsp+C0h] [rbp+0h]
  UFG::qMatrix44 v191; // [rsp+100h] [rbp+40h]
  UFG::qMatrix44 m; // [rsp+140h] [rbp+80h]
  __int64 v193; // [rsp+180h] [rbp+C0h]
  UFG::qSymbol v194[2]; // [rsp+280h] [rbp+1C0h]
  UFG::qSymbol objName; // [rsp+288h] [rbp+1C8h]
  ASymbol v196[2]; // [rsp+290h] [rbp+1D0h]
  UFG::allocator::free_link *v197; // [rsp+298h] [rbp+1D8h]

  v193 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = 0;
  xform.v2.z = 0.0;
  this->mDesiredStatus = 1;
  if ( !this->mActiveStatus )
  {
    v4 = UFG::CopRoadBlock::FindClosestRoadSegment(this);
    v5 = (UFG::RoadNetworkNode *)&v4->mType;
    if ( v4 )
    {
      UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(
        UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
        v4);
      UFG::WheeledVehicleManager::DestroyCarsOnRoad(UFG::WheeledVehicleManager::m_Instance, v5);
    }
    v1->mActiveStatus = 1;
    v6 = v1->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v1->mpXformNode);
    v7 = v6->mWorldTransform.v0.x;
    xform.v2.y = v6->mWorldTransform.v0.y;
    xform.v1.z = v6->mWorldTransform.v0.z;
    v8 = v6->mWorldTransform.v1.x;
    *(float *)&v197 = v6->mWorldTransform.v1.x;
    v9 = (__m128)LODWORD(v6->mWorldTransform.v1.y);
    v196[0] = LODWORD(v6->mWorldTransform.v1.y);
    v10 = v6->mWorldTransform.v1.z;
    xform.v2.x = v6->mWorldTransform.v1.z;
    v11 = v6->mWorldTransform.v3.x;
    xform.v2.w = v6->mWorldTransform.v3.x;
    v12 = v6->mWorldTransform.v3.y;
    xform.v0.x = v6->mWorldTransform.v3.y;
    v13 = v6->mWorldTransform.v3.z;
    xform.v1.w = v6->mWorldTransform.v3.z;
    if ( v1->mAutoFillLanes )
    {
      LODWORD(xform.v0.x) = (unsigned __int8)v5->mNumLanes;
      if ( LODWORD(xform.v0.x) )
      {
        v14 = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
        v15 = (signed __int64)v1->mObjects;
        v16 = v10;
        do
        {
          v17 = FLOAT_3_4028235e38;
          UFG::RoadNetworkNode::GetPos(v5, &result, v2, 0.0);
          v18 = UFG::RoadNetworkNode::GetLane(v5, v2);
          v19 = 1.0 / UFG::RoadNetworkLane::GetLength(v18);
          v20 = 0.0;
          do
          {
            UFG::RoadNetworkNode::GetPos(v5, (UFG::qVector3 *)&xform.v0.z, v2, v20);
            if ( (float)((float)((float)((float)(xform.v0.w - v12) * (float)(xform.v0.w - v12))
                               + (float)((float)(xform.v0.z - v11) * (float)(xform.v0.z - v11)))
                       + (float)((float)(xform.v1.x - v13) * (float)(xform.v1.x - v13))) < v17 )
            {
              v17 = (float)((float)((float)(xform.v0.w - v12) * (float)(xform.v0.w - v12))
                          + (float)((float)(xform.v0.z - v11) * (float)(xform.v0.z - v11)))
                  + (float)((float)(xform.v1.x - v13) * (float)(xform.v1.x - v13));
              UFG::RoadNetworkLane::IsReversedInNode(v18);
              result = *(UFG::qVector3 *)&xform.v0.z;
            }
            v20 = v20 + v19;
          }
          while ( v20 < 1.0 );
          v21 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&xform.v2.y, sRoadBlockItemPrefix);
          UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v21);
          v22 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&qSymbolX_propset_vehicle_police.mUID);
          v23 = UFG::SceneObjectProperties::Create(&objName, 0i64, v22);
          PropertyUtils::SetRuntime<UFG::qSymbol>(
            v23,
            (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
            (UFG::qSymbol *)&qSymbol_Critical.mUID);
          v24 = UFG::SceneObjectProperties::Activate(v23, 3u, 0i64, 0i64);
          if ( v24 )
          {
            UFG::SpawnInfoInterface::ClearSpawnLocation(v23, 0);
            UFG::SpawnInfoInterface::ActivateObjectPost(v23, 0, 0i64, v22, 0);
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
          if ( *(_QWORD *)(v15 + 16) )
          {
            v27 = *(_QWORD *)v15;
            v28 = *(_QWORD **)(v15 + 8);
            *(_QWORD *)(v27 + 8) = v28;
            *v28 = v27;
            *(_QWORD *)v15 = v15;
            *(_QWORD *)(v15 + 8) = v15;
          }
          *(_QWORD *)(v15 + 16) = v24;
          if ( v24 )
          {
            v29 = v24->m_SafePointerList.mNode.mPrev;
            v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v15;
            *(_QWORD *)v15 = v29;
            *(_QWORD *)(v15 + 8) = (char *)v24 + 8;
            v24->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v15;
          }
          if ( v14 == 0.0 )
            v30 = 0.0;
          else
            v30 = 1.0 / fsqrt(v14);
          v31 = v30 * *(float *)&v197;
          v32 = v30 * *(float *)&v196[0].i_uid;
          v33 = v30 * v16;
          xform.v0.x = v31;
          xform.v0.y = v32;
          xform.v0.z = v33;
          xform.v0.w = 0.0;
          v34 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          v35 = v34;
          v35.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v35.m128_f32[0] == 0.0 )
            v36 = 0.0;
          else
            v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
          v37 = v36 * UFG::qVector3::msDirUp.x;
          v38 = v36 * UFG::qVector3::msDirUp.y;
          v39 = v36 * UFG::qVector3::msDirUp.z;
          v40 = (float)(v38 * v33) - (float)(v39 * v32);
          v41 = (float)(v39 * v31) - (float)(v37 * v33);
          v42 = (float)(v37 * v32) - (float)(v38 * v31);
          v43 = (float)((float)(v41 * v41) + (float)(v40 * v40)) + (float)(v42 * v42);
          if ( v43 == 0.0 )
            v44 = 0.0;
          else
            v44 = 1.0 / fsqrt(v43);
          v45 = v41 * v44;
          xform.v1.x = v40 * v44;
          xform.v1.y = v45;
          xform.v1.z = v42 * v44;
          xform.v1.w = 0.0;
          v46 = (float)((float)(v42 * v44) * v32) - (float)(v45 * v33);
          v47 = (float)((float)(v40 * v44) * v33) - (float)((float)(v42 * v44) * v31);
          v48 = (float)(v45 * v31) - (float)((float)(v40 * v44) * v32);
          v49 = (float)((float)(v47 * v47) + (float)(v46 * v46)) + (float)(v48 * v48);
          if ( v49 == 0.0 )
            v50 = 0.0;
          else
            v50 = 1.0 / fsqrt(v49);
          xform.v2.x = v46 * v50;
          xform.v2.y = v47 * v50;
          xform.v2.z = v48 * v50;
          xform.v2.w = 0.0;
          *(UFG::qVector3 *)&xform.v3.x = result;
          xform.v3.w = 1.0;
          UFG::SimObjectUtility::Teleport(*(UFG::SimObject **)(v15 + 16), &xform);
          v51 = *(UFG::SimObjectGame **)(v15 + 16);
          if ( v51 )
          {
            v52 = v51->m_Flags;
            if ( (v52 >> 14) & 1 )
            {
              v53 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v51,
                                                      UFG::VehicleEffectsComponent::_TypeUID);
            }
            else if ( (v52 & 0x8000u) == 0 )
            {
              if ( (v52 >> 13) & 1 )
              {
                v53 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v51,
                                                        UFG::VehicleEffectsComponent::_TypeUID);
              }
              else if ( (v52 >> 12) & 1 )
              {
                v53 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v51,
                                                        UFG::VehicleEffectsComponent::_TypeUID);
              }
              else
              {
                v53 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                        (UFG::SimObject *)&v51->vfptr,
                                                        UFG::VehicleEffectsComponent::_TypeUID);
              }
            }
            else
            {
              v53 = (UFG::VehicleEffectsComponent *)v51->m_Components.p[32].m_pComponent;
            }
            if ( v53 )
              UFG::VehicleEffectsComponent::TurnOnCopLights(v53);
          }
          ++v2;
          v15 += 24i64;
          v11 = xform.v2.w;
        }
        while ( v2 < LODWORD(xform.v0.x) );
        v1 = *(UFG::CopRoadBlock **)&v194[0].mUID;
      }
    }
    else
    {
      v54 = (float)(v10 * 3.0) + v13;
      v55 = (float)(v9.m128_f32[0] * 3.0) + xform.v0.x;
      xform.v3.x = (float)(v8 * 3.0) + v11;
      xform.v3.y = xform.v1.w - (float)(v10 * 3.0);
      xform.v3.w = xform.v0.x - (float)(v9.m128_f32[0] * 3.0);
      xform.v3.z = v11 - (float)(v8 * 3.0);
      UFG::qSymbol::create_from_string(&objName, sRoadBlockItemPrefix_0);
      UFG::SimObjectUtility::GenerateUniqueActorName(v194, &objName);
      v56 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&qSymbolX_propset_vehicle_police.mUID);
      v57 = UFG::SceneObjectProperties::Create(v194, 0i64, v56);
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v57,
        (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
        (UFG::qSymbol *)&qSymbol_Critical.mUID);
      v58 = 3i64;
      v59 = UFG::SceneObjectProperties::Activate(v57, 3u, 0i64, 0i64);
      if ( v59 )
      {
        UFG::SpawnInfoInterface::ClearSpawnLocation(v57, 0);
        UFG::SpawnInfoInterface::ActivateObjectPost(v57, 0, 0i64, v56, 0);
      }
      else
      {
        if ( v57 )
        {
          v60 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v57->m_NameUID);
          v61 = UFG::qSymbol::as_cstr_dbg(v60);
        }
        else
        {
          v61 = "<NULL>";
        }
        UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v61);
      }
      v62 = v1->mObjects;
      if ( v1->mObjects[0].m_pPointer )
      {
        v63 = v62->mPrev;
        v64 = v1->mObjects[0].mNext;
        v63->mNext = v64;
        v64->mPrev = v63;
        v62->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v62->mPrev;
        v1->mObjects[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v1->mObjects;
      }
      v1->mObjects[0].m_pPointer = v59;
      if ( v59 )
      {
        v65 = v59->m_SafePointerList.mNode.mPrev;
        v65->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v62->mPrev;
        v62->mPrev = v65;
        v1->mObjects[0].mNext = &v59->m_SafePointerList.mNode;
        v59->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v62->mPrev;
      }
      v194[0] = (UFG::qSymbol)UFG::SimObjectUtility::GenerateUniqueActorName((UFG::qSymbol *)&xform.v0.y, &objName)->mUID;
      v66 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&qSymbolX_propset_vehicle_police.mUID);
      v67 = UFG::SceneObjectProperties::Create(v194, 0i64, v66);
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v67,
        (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
        (UFG::qSymbol *)&qSymbol_Critical.mUID);
      v68 = UFG::SceneObjectProperties::Activate(v67, 3u, 0i64, 0i64);
      if ( v68 )
      {
        UFG::SpawnInfoInterface::ClearSpawnLocation(v67, 0);
        UFG::SpawnInfoInterface::ActivateObjectPost(v67, 0, 0i64, v66, 0);
      }
      else
      {
        if ( v67 )
        {
          v69 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v67->m_NameUID);
          v70 = UFG::qSymbol::as_cstr_dbg(v69);
        }
        else
        {
          v70 = "<NULL>";
        }
        UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v70);
      }
      v71 = &v1->mObjects[1];
      if ( v1->mObjects[1].m_pPointer )
      {
        v72 = v71->mPrev;
        v73 = v1->mObjects[1].mNext;
        v72->mNext = v73;
        v73->mPrev = v72;
        v71->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v71->mPrev;
        v1->mObjects[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mObjects[1].mPrev;
      }
      v1->mObjects[1].m_pPointer = v68;
      if ( v68 )
      {
        v74 = v68->m_SafePointerList.mNode.mPrev;
        v74->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v71->mPrev;
        v71->mPrev = v74;
        v1->mObjects[1].mNext = &v68->m_SafePointerList.mNode;
        v68->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v71->mPrev;
      }
      v194[0] = (UFG::qSymbol)UFG::SimObjectUtility::GenerateUniqueActorName((UFG::qSymbol *)&xform.v0.y, &objName)->mUID;
      v75 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&qSymbolX_propset_character_police.mUID);
      v76 = UFG::SceneObjectProperties::Create(v194, 0i64, v75);
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v76,
        (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
        (UFG::qSymbol *)&qSymbol_Critical.mUID);
      v77 = UFG::SceneObjectProperties::Activate(v76, 3u, 0i64, 0i64);
      if ( v77 )
      {
        UFG::SpawnInfoInterface::ClearSpawnLocation(v76, 0);
        UFG::SpawnInfoInterface::ActivateObjectPost(v76, 0, 0i64, v75, 0);
      }
      else
      {
        if ( v76 )
        {
          v78 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&xform.v0.y, v76->m_NameUID);
          v79 = UFG::qSymbol::as_cstr_dbg(v78);
        }
        else
        {
          v79 = "<NULL>";
        }
        UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v79);
      }
      v80 = &v1->mObjects[2];
      if ( v1->mObjects[2].m_pPointer )
      {
        v81 = v80->mPrev;
        v82 = v1->mObjects[2].mNext;
        v81->mNext = v82;
        v82->mPrev = v81;
        v80->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v80->mPrev;
        v1->mObjects[2].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mObjects[2].mPrev;
      }
      v1->mObjects[2].m_pPointer = v77;
      if ( v77 )
      {
        v83 = v77->m_SafePointerList.mNode.mPrev;
        v83->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v80->mPrev;
        v80->mPrev = v83;
        v1->mObjects[2].mNext = &v77->m_SafePointerList.mNode;
        v77->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v80->mPrev;
      }
      v84 = v9;
      v84.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
      if ( v84.m128_f32[0] == 0.0 )
        v85 = 0.0;
      else
        v85 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v84));
      v86 = v10 * v85;
      v87 = *(float *)&v196[0].i_uid * v85;
      v88 = *(float *)&v197 * v85;
      v189.v0.x = *(float *)&v197 * v85;
      v189.v0.y = *(float *)&v196[0].i_uid * v85;
      v189.v0.z = v86;
      v189.v0.w = 0.0;
      v89 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v90 = v89;
      v90.m128_f32[0] = (float)((float)(v89.m128_f32[0] * v89.m128_f32[0])
                              + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                      + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v90.m128_f32[0] == 0.0 )
      {
        v91 = 0i64;
      }
      else
      {
        v91 = (__m128)(unsigned int)FLOAT_1_0;
        v91.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v90));
      }
      v92 = v91.m128_f32[0] * UFG::qVector3::msDirUp.z;
      v95 = v91;
      v95.m128_f32[0] = v91.m128_f32[0] * UFG::qVector3::msDirUp.y;
      v91.m128_f32[0] = v91.m128_f32[0] * UFG::qVector3::msDirUp.x;
      v93 = v91;
      v93.m128_f32[0] = (float)(v91.m128_f32[0] * v87) - (float)(v88 * v95.m128_f32[0]);
      v94 = (float)(v88 * v92) - (float)(v91.m128_f32[0] * v86);
      v95.m128_f32[0] = (float)(v95.m128_f32[0] * v86) - (float)(v92 * v87);
      v96 = v95;
      v96.m128_f32[0] = (float)((float)(v95.m128_f32[0] * v95.m128_f32[0]) + (float)(v94 * v94))
                      + (float)(v93.m128_f32[0] * v93.m128_f32[0]);
      if ( v96.m128_f32[0] == 0.0 )
        v97 = 0.0;
      else
        v97 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v96));
      v93.m128_f32[0] = v93.m128_f32[0] * v97;
      v98 = v95.m128_f32[0] * v97;
      v189.v1.x = v98;
      v189.v1.y = v94 * v97;
      LODWORD(v189.v1.z) = v93.m128_i32[0];
      v189.v1.w = 0.0;
      v99 = (float)(v88 * (float)(v94 * v97)) - (float)(v98 * v87);
      v100 = (float)(v98 * v86) - (float)(v88 * v93.m128_f32[0]);
      v93.m128_f32[0] = (float)(v93.m128_f32[0] * v87) - (float)((float)(v94 * v97) * v86);
      v101 = v93;
      v101.m128_f32[0] = (float)((float)(v93.m128_f32[0] * v93.m128_f32[0]) + (float)(v100 * v100)) + (float)(v99 * v99);
      if ( v101.m128_f32[0] == 0.0 )
        v102 = 0.0;
      else
        v102 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v101));
      v189.v2.x = v93.m128_f32[0] * v102;
      v189.v2.y = v102 * v100;
      v189.v2.z = v102 * v99;
      v189.v2.w = 0.0;
      v189.v3.x = xform.v3.x;
      v189.v3.y = v55;
      v189.v3.z = v54;
      v189.v3.w = 1.0;
      v103 = (UFG::SimObjectGame **)&v1->mObjects[0].m_pPointer;
      UFG::SimObjectUtility::Teleport(v1->mObjects[0].m_pPointer, &v189);
      do
      {
        v104 = *v103;
        if ( *v103 )
        {
          v105 = v104->m_Flags;
          if ( (v105 >> 14) & 1 )
          {
            v106 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v104,
                                                     UFG::VehicleEffectsComponent::_TypeUID);
          }
          else if ( (v105 & 0x8000u) == 0 )
          {
            if ( (v105 >> 13) & 1 )
              v106 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v104,
                                                       UFG::VehicleEffectsComponent::_TypeUID);
            else
              v106 = (UFG::VehicleEffectsComponent *)((v105 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v104,
                                                                           UFG::VehicleEffectsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v104->vfptr, UFG::VehicleEffectsComponent::_TypeUID));
          }
          else
          {
            v106 = (UFG::VehicleEffectsComponent *)v104->m_Components.p[32].m_pComponent;
          }
          if ( v106 )
            UFG::VehicleEffectsComponent::TurnOnCopLights(v106);
        }
        v103 += 3;
        --v58;
      }
      while ( v58 );
      if ( v84.m128_f32[0] == 0.0 )
        v107 = 0.0;
      else
        v107 = 1.0 / fsqrt(v84.m128_f32[0]);
      v108 = xform.v2.x * v107;
      v109 = *(float *)&v196[0].i_uid * v107;
      v110 = v107 * *(float *)&v197;
      v190.v0.x = v110;
      v190.v0.y = v109;
      v190.v0.z = v108;
      v190.v0.w = 0.0;
      v111 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v112 = v111;
      v112.m128_f32[0] = (float)((float)(v111.m128_f32[0] * v111.m128_f32[0])
                               + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                       + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v112.m128_f32[0] == 0.0 )
        v113 = 0.0;
      else
        v113 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v112));
      v114 = v113 * UFG::qVector3::msDirUp.z;
      v115 = v113 * UFG::qVector3::msDirUp.y;
      v116 = v113 * UFG::qVector3::msDirUp.x;
      v117 = (float)(v116 * v109) - (float)(v110 * v115);
      v118 = (float)(v110 * v114) - (float)(v116 * v108);
      v119 = (float)(v115 * v108) - (float)(v114 * v109);
      v120 = (float)((float)(v119 * v119) + (float)(v118 * v118)) + (float)(v117 * v117);
      if ( v120 == 0.0 )
        v121 = 0.0;
      else
        v121 = 1.0 / fsqrt(v120);
      v122 = v117 * v121;
      v123 = v119 * v121;
      v190.v1.x = v123;
      v190.v1.y = v118 * v121;
      v190.v1.z = v122;
      v190.v1.w = 0.0;
      v124 = (float)(v110 * (float)(v118 * v121)) - (float)(v123 * v109);
      v125 = (float)(v123 * v108) - (float)(v110 * v122);
      v126 = (float)(v122 * v109) - (float)((float)(v118 * v121) * v108);
      v127 = (float)((float)(v126 * v126) + (float)(v125 * v125)) + (float)(v124 * v124);
      if ( v127 == 0.0 )
        v128 = 0.0;
      else
        v128 = 1.0 / fsqrt(v127);
      v190.v2.x = v126 * v128;
      v190.v2.y = v128 * v125;
      v190.v2.z = v128 * v124;
      v190.v2.w = 0.0;
      v190.v3.x = xform.v3.z;
      v190.v3.y = xform.v3.w;
      v190.v3.z = xform.v3.y;
      v190.v3.w = 1.0;
      UFG::SimObjectUtility::Teleport(v1->mObjects[1].m_pPointer, &v190);
      v129 = v1->mFlipped;
      if ( v129 )
        v130 = FLOAT_N2_0;
      else
        v130 = FLOAT_2_0;
      v131 = xform.v1.z;
      v132 = xform.v2.y;
      v133 = (float)(xform.v1.z * v130) + xform.v1.w;
      v134 = (float)(xform.v2.y * v130) + xform.v0.x;
      v135 = (float)(v7 * v130) + xform.v2.w;
      if ( v129 )
      {
        LODWORD(v131) = LODWORD(xform.v1.z) ^ _xmm[0];
        LODWORD(v132) = LODWORD(xform.v2.y) ^ _xmm[0];
        LODWORD(v7) ^= _xmm[0];
      }
      result.z = v131;
      result.y = v132;
      result.x = v7;
      v136 = v132;
      v137 = (__m128)LODWORD(v7);
      v138 = v131;
      v139 = v137;
      v139.m128_f32[0] = (float)((float)(v137.m128_f32[0] * v137.m128_f32[0]) + (float)(v136 * v136))
                       + (float)(v138 * v138);
      if ( v139.m128_f32[0] == 0.0 )
        v140 = 0.0;
      else
        v140 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v139));
      v141 = v138 * v140;
      v142 = v136 * v140;
      v143 = v7 * v140;
      v191.v0.x = v7 * v140;
      v191.v0.y = v142;
      v191.v0.z = v141;
      v191.v0.w = 0.0;
      v144 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v144.m128_f32[0] = (float)((float)(v144.m128_f32[0] * v144.m128_f32[0])
                               + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                       + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v144.m128_f32[0] == 0.0 )
        v145 = 0.0;
      else
        v145 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v144));
      v146 = v145 * UFG::qVector3::msDirUp.z;
      v147 = v145 * UFG::qVector3::msDirUp.y;
      v148 = v145 * UFG::qVector3::msDirUp.x;
      v149 = (float)(v148 * v142) - (float)(v143 * v147);
      v150 = (float)(v143 * v146) - (float)(v148 * v141);
      v151 = (float)(v147 * v141) - (float)(v146 * v142);
      v152 = (float)((float)(v151 * v151) + (float)(v150 * v150)) + (float)(v149 * v149);
      if ( v152 == 0.0 )
        v153 = 0.0;
      else
        v153 = 1.0 / fsqrt(v152);
      v154 = v149 * v153;
      v155 = v151 * v153;
      v191.v1.x = v155;
      v191.v1.y = v150 * v153;
      v191.v1.z = v154;
      v191.v1.w = 0.0;
      v156 = (float)(v143 * (float)(v150 * v153)) - (float)(v155 * v142);
      v157 = (float)(v155 * v141) - (float)(v143 * v154);
      v158 = (float)(v154 * v142) - (float)((float)(v150 * v153) * v141);
      v159 = (float)((float)(v158 * v158) + (float)(v157 * v157)) + (float)(v156 * v156);
      if ( v159 == 0.0 )
        v160 = 0.0;
      else
        v160 = 1.0 / fsqrt(v159);
      v191.v2.x = v158 * v160;
      v191.v2.y = v160 * v157;
      v191.v2.z = v160 * v156;
      v191.v2.w = 0.0;
      v191.v3.x = v135;
      v191.v3.y = (float)(xform.v2.y * v130) + xform.v0.x;
      v191.v3.z = (float)(xform.v1.z * v130) + xform.v1.w;
      v191.v3.w = 1.0;
      UFG::SimObjectUtility::Teleport(v1->mObjects[2].m_pPointer, &v191);
      v161 = (UFG::SimObjectCVBase *)v1->mObjects[2].m_pPointer;
      if ( v161 )
      {
        v162 = v161->m_Flags;
        if ( (v162 >> 14) & 1 )
        {
          v163 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v161);
        }
        else if ( (v162 & 0x8000u) == 0 )
        {
          if ( (v162 >> 13) & 1 )
            v163 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v161->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
          else
            v163 = (UFG::ActiveAIEntityComponent *)((v162 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v161->vfptr,
                                                                         UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v161->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
        }
        else
        {
          v163 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v161);
        }
        v164 = v163;
        if ( v163 )
        {
          UFG::ActiveAIEntityComponent::SetCurrentObjective(v163, eAI_OBJECTIVE_PURSUIT_TARGET, "CopRoadBlock");
          v164->m_MaxEngagementDistanceXY = 50.0;
          v164->m_MaxEngagementDistanceZ = 50.0;
          v165 = (UFG::SimObjectGame *)v1->mObjects[2].m_pPointer;
          if ( v165 )
          {
            v166 = v165->m_Flags;
            if ( (v166 >> 14) & 1 )
            {
              v167 = (UFG::AIScriptInterfaceComponent *)v165->m_Components.p[5].m_pComponent;
            }
            else if ( (v166 & 0x8000u) == 0 )
            {
              if ( (v166 >> 13) & 1 )
                v168 = UFG::SimObjectGame::GetComponentOfTypeHK(v165, UFG::AIScriptInterfaceComponent::_TypeUID);
              else
                v168 = (v166 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v165,
                                            UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v165->vfptr,
                                                                                           UFG::AIScriptInterfaceComponent::_TypeUID);
              v167 = (UFG::AIScriptInterfaceComponent *)v168;
            }
            else
            {
              v167 = (UFG::AIScriptInterfaceComponent *)v165->m_Components.p[5].m_pComponent;
            }
            if ( v167 )
            {
              v169 = v1->mPositionToDefendObject.m_pPointer;
              if ( v169 )
                UFG::Simulation::DestroySimObject(&UFG::gSim, v169);
              v170 = UFG::GetSimulationMemoryPool();
              v171 = UFG::qMemoryPool::Allocate(v170, 0x80ui64, "CopRoadBlock::Spawn()", 0i64, 1u);
              v197 = v171;
              if ( v171 )
              {
                v3 = 1;
                LODWORD(xform.v2.z) = 1;
                v172 = UFG::qSymbol::create_from_string((UFG::qSymbol *)v196, "RoadblockPositionToDefend");
                UFG::SimObject::SimObject((UFG::SimObject *)v171, v172);
              }
              else
              {
                v173 = 0i64;
              }
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->mPositionToDefendObject,
                v173);
              if ( v3 & 1 )
                LODWORD(xform.v2.z) = v3 & 0xFFFFFFFE;
              v174 = UFG::GetSimulationMemoryPool();
              v175 = UFG::qMemoryPool::Allocate(v174, 0x110ui64, "CopRoadBlock::Spawn()", 0i64, 1u);
              *(_QWORD *)&v196[0].i_uid = v175;
              if ( v175 )
              {
                v176 = UFG::qStringHash32("RoadblockPositionToDefendTransformNode", 0xFFFFFFFF);
                UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v175, v176, 0i64, 0);
                v178 = v177;
              }
              else
              {
                v178 = 0i64;
              }
              v179 = 0i64;
              v179.x = (float)1;
              m.v0 = v179;
              m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v179, (__m128)v179, 81);
              m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v179, (__m128)v179, 69);
              m.v3.x = v135;
              m.v3.y = v134;
              m.v3.z = v133;
              m.v3.w = 1.0;
              UFG::TransformNodeComponent::SetWorldTransform(v178, &m);
              v180 = v1->mPositionToDefendObject.m_pPointer;
              v181 = v180->m_Flags;
              if ( (v181 >> 14) & 1 )
              {
                v182 = 2;
              }
              else if ( (v181 & 0x8000u) == 0 )
              {
                if ( (v181 >> 13) & 1 )
                {
                  v182 = 2;
                }
                else
                {
                  v182 = -1;
                  if ( (v181 >> 12) & 1 )
                    v182 = 1;
                }
              }
              else
              {
                v182 = 2;
              }
              UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&xform, v180, 1);
              UFG::SimObjectModifier::AttachComponent(
                (UFG::SimObjectModifier *)&xform,
                (UFG::SimComponent *)&v178->vfptr,
                v182);
              UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&xform);
              UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&xform);
              UFG::AIScriptInterfaceComponent::SetPositionToDefend(
                v167,
                v1->mPositionToDefendObject.m_pPointer,
                10.0,
                0,
                0,
                0);
            }
          }
          v183 = v1->mObjects[2].m_pPointer;
          if ( v183 )
          {
            v184 = v183->m_Flags;
            if ( (v184 >> 14) & 1 )
            {
              v185 = (UFG::TSActorComponent *)v183->m_Components.p[4].m_pComponent;
            }
            else if ( (v184 & 0x8000u) == 0 )
            {
              if ( (v184 >> 13) & 1 )
                v185 = (UFG::TSActorComponent *)v183->m_Components.p[3].m_pComponent;
              else
                v185 = (UFG::TSActorComponent *)((v184 >> 12) & 1 ? v183->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(v183, UFG::TSActorComponent::_TypeUID));
            }
            else
            {
              v185 = (UFG::TSActorComponent *)v183->m_Components.p[4].m_pComponent;
            }
            if ( v185 )
            {
              ASymbol::create(v196, "equip_firearm", 0xFFFFFFFF, ATerm_long);
              v197 = 0i64;
              v186 = UFG::TSActorComponent::GetActor(v185);
              ((void (__fastcall *)(UFG::TSActor *, ASymbol *, UFG::allocator::free_link **, bool, _QWORD, _QWORD, _QWORD, _QWORD))v186->vfptr[1].set_data_by_name)(
                v186,
                v196,
                &v197,
                v197 != 0i64,
                0i64,
                0i64,
                *(_QWORD *)&result.x,
                *(_QWORD *)&result.z);
            }
          }
        }
      }
    }
    UFG::SimObjectUtility::AttachHudSymbol(v1->m_pSimObject, "roadblock_symbol", 0, 0.0, &customWorldMapCaption);
  }
}

// File Line: 305
// RVA: 0x5B3360
void __fastcall UFG::CopRoadBlock::Despawn(UFG::CopRoadBlock *this)
{
  bool v1; // zf
  UFG::CopRoadBlock *v2; // r14
  UFG::SimObject *v3; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::WheeledVehicleManager *v7; // rsi
  UFG::RoadNetworkResource *v8; // rax
  UFG::TransformNodeComponent *v9; // rbx
  UFG::RoadNetworkResource *v10; // rdi
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::RoadNetworkSegment *v13; // rax
  UFG::RoadNetworkNode *v14; // rbx
  UFG::SimObject **v15; // rdi
  signed __int64 v16; // rbp
  UFG::SimObjectGame *v17; // rbx
  unsigned __int16 v18; // cx
  UFG::StreamedResourceComponent *v19; // rsi
  UFG::SimObjectGame *v20; // rcx
  UFG::SimComponent *v21; // rax
  unsigned __int16 v22; // cx
  UFG::SimComponent *v23; // rax
  __int64 v24; // rcx
  _QWORD *v25; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-28h]
  unsigned int p_segment_index; // [rsp+60h] [rbp+8h]

  v1 = this->mActiveStatus == 0;
  v2 = this;
  this->mDesiredStatus = 0;
  if ( !v1 )
  {
    v3 = this->mPositionToDefendObject.m_pPointer;
    this->mActiveStatus = 0;
    if ( v3 )
    {
      UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
      v4 = &v2->mPositionToDefendObject;
      if ( v2->mPositionToDefendObject.m_pPointer )
      {
        v5 = v4->mPrev;
        v6 = v2->mPositionToDefendObject.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v2->mPositionToDefendObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPositionToDefendObject.mPrev;
      }
      v2->mPositionToDefendObject.m_pPointer = 0i64;
    }
    v7 = UFG::WheeledVehicleManager::m_Instance;
    v8 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    v9 = v2->mpXformNode;
    v10 = v8;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2->mpXformNode);
    v11 = v9->mWorldTransform.v3.y;
    v12 = v9->mWorldTransform.v3.z;
    pos.x = v9->mWorldTransform.v3.x;
    pos.y = v11;
    pos.z = v12;
    p_segment_index = -1;
    v13 = UFG::RoadNetworkResource::GetClosestSegment(v10, &pos, &p_segment_index, 0);
    v14 = (UFG::RoadNetworkNode *)&v13->mType;
    if ( v13 )
    {
      UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(v7->m_NavigationData, v13);
      UFG::WheeledVehicleManager::DestroyCarsOnRoad(v7, v14);
    }
    v15 = &v2->mObjects[0].m_pPointer;
    v16 = 6i64;
    do
    {
      v17 = (UFG::SimObjectGame *)*v15;
      if ( *v15 )
      {
        v18 = v17->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v19 = (UFG::StreamedResourceComponent *)v17->m_Components.p[10].m_pComponent;
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
          {
            v19 = (UFG::StreamedResourceComponent *)v17->m_Components.p[7].m_pComponent;
          }
          else
          {
            v1 = ((v18 >> 12) & 1) == 0;
            v20 = (UFG::SimObjectGame *)*v15;
            if ( v1 )
              v21 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v20->vfptr,
                      UFG::StreamedResourceComponent::_TypeUID);
            else
              v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::StreamedResourceComponent::_TypeUID);
            v19 = (UFG::StreamedResourceComponent *)v21;
          }
        }
        else
        {
          v19 = (UFG::StreamedResourceComponent *)v17->m_Components.p[10].m_pComponent;
        }
        if ( v19 )
        {
          UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v19, (UFG::qSymbol *)&qSymbol_Low.mUID);
          UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v19, (UFG::qSymbol *)&qSymbol_Critical.mUID);
        }
        v22 = v17->m_Flags;
        if ( (v22 >> 14) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::VehicleOccupantComponent::_TypeUID);
        }
        else if ( (v22 & 0x8000u) == 0 )
        {
          if ( (v22 >> 13) & 1 )
          {
            v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::VehicleOccupantComponent::_TypeUID);
          }
          else if ( (v22 >> 12) & 1 )
          {
            v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::VehicleOccupantComponent::_TypeUID);
          }
          else
          {
            v23 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v17->vfptr,
                    UFG::VehicleOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v23 = v17->m_Components.p[30].m_pComponent;
        }
        if ( !v23 || !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v23) )
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, *v15);
        if ( *v15 )
        {
          v24 = (__int64)*(v15 - 2);
          v25 = *(v15 - 1);
          *(_QWORD *)(v24 + 8) = v25;
          *v25 = v24;
          *(v15 - 2) = (UFG::SimObject *)(v15 - 2);
          *(v15 - 1) = (UFG::SimObject *)(v15 - 2);
        }
        *v15 = 0i64;
      }
      v15 += 3;
      --v16;
    }
    while ( v16 );
    UFG::SimObjectUtility::DetachHudSymbol(v2->m_pSimObject);
  }
}

// File Line: 371
// RVA: 0x5B3600
UFG::RoadNetworkSegment *__fastcall UFG::CopRoadBlock::FindClosestRoadSegment(UFG::CopRoadBlock *this)
{
  UFG::CopRoadBlock *v1; // rbx
  UFG::RoadNetworkResource *v2; // rax
  UFG::TransformNodeComponent *v3; // rbx
  UFG::RoadNetworkResource *v4; // rdi
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h]
  unsigned int p_segment_index; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v3 = v1->mpXformNode;
  v4 = v2;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v5 = v3->mWorldTransform.v3.y;
  v6 = v3->mWorldTransform.v3.z;
  pos.x = v3->mWorldTransform.v3.x;
  pos.y = v5;
  pos.z = v6;
  p_segment_index = -1;
  return UFG::RoadNetworkResource::GetClosestSegment(v4, &pos, &p_segment_index, 0);
}

