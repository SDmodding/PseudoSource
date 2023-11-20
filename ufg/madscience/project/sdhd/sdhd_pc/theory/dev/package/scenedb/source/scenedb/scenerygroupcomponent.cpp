// File Line: 37
// RVA: 0x14700B0
__int64 dynamic_initializer_for__UFG::SceneryGroupComponent::s_SceneryGroupComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SceneryGroupComponent::s_SceneryGroupComponentList__);
}

// File Line: 38
// RVA: 0x232E60
const char *__fastcall UFG::SceneryGroupComponent::GetTypeName(UFG::SceneryGroupComponent *this)
{
  return "SceneryGroupComponent";
}

// File Line: 87
// RVA: 0x22F660
void __fastcall UFG::SceneryGroupComponent::SceneryGroupComponent(UFG::SceneryGroupComponent *this, UFG::SceneryGroup *scenery_group)
{
  UFG::SceneryGroup *v2; // rdi
  UFG::SceneryGroupComponent *v3; // rsi
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v4; // rdx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v5; // rax
  signed int v6; // ecx
  UFG::qList<Render::Decal,Render::Decal,0,0> *v7; // [rsp+48h] [rbp+10h]

  v2 = scenery_group;
  v3 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  v7 = &this->mAttachedDecals;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0x1111u);
  v4 = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (Render::IDecalSceneryVtbl *)&UFG::SceneryGroupComponent::`vftable{for `Render::IDecalScenery};
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneryGroupComponent::`vftable{for `UFG::SimComponent};
  v5 = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev;
  UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList;
  UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::SceneryGroupComponent::_SceneryGroupComponentTypeUID,
    "SceneryGroupComponent");
  v3->mSceneryGroup = v2;
  v6 = Illusion::gEngine.mFrameCount;
  if ( Render::TransparencySystem::msEnabled )
    v3->mTransparencyState[0] = 0;
  else
    v3->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  v3->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  v3->mTransparencyState[2] = v6 + v6 / 255;
}

// File Line: 107
// RVA: 0x22FBB0
void __fastcall UFG::SceneryGroupComponent::~SceneryGroupComponent(UFG::SceneryGroupComponent *this)
{
  UFG::SceneryGroupComponent *v1; // rdi
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v2; // rbx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v3; // rcx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v4; // rax
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v5; // rdx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v6; // rax

  v1 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&UFG::SceneryGroupComponent::`vftable{for `Render::IDecalScenery};
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneryGroupComponent::`vftable{for `UFG::SimComponent};
  if ( this == UFG::SceneryGroupComponent::s_SceneryGroupComponentpCurrentIterator )
    UFG::SceneryGroupComponent::s_SceneryGroupComponentpCurrentIterator = (UFG::SceneryGroupComponent *)&this->mPrev[-6].mNext;
  v2 = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v1->vfptr, 0xFFFFFFFF);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
  Render::IDecalScenery::~IDecalScenery((Render::IDecalScenery *)&v1->vfptr);
}

// File Line: 120
// RVA: 0x2319F0
void __fastcall UFG::SceneryGroupComponent::GenerateCullInfo(UFG::SceneryGroupComponent *this, CullLayer *cull_layer, UFG::SceneryGroupComponent *matching_std_group)
{
  UFG::SceneryGroupComponent *v3; // rdi
  UFG::SceneryGroup *v4; // rcx
  CullLayer *v5; // r14
  unsigned __int16 v6; // ax
  CullInfo *v7; // rbp
  char v8; // r12
  unsigned int v9; // esi
  unsigned int v10; // eax
  UFG::SectionChooser::SectionInfo *v11; // rbx
  bool v12; // al
  UFG::SectionChooser::SectionInfo *v13; // rax
  UFG::SectionChooser::LOD_SUPRESSION v14; // er14
  unsigned int v15; // eax
  signed __int64 v16; // rcx
  int v17; // er11
  int v18; // er8
  int v19; // esi
  int v20; // ecx
  int v21; // er10
  int v22; // er9
  int v23; // er10
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  unsigned __int16 v27; // dx
  int v28; // esi
  int v29; // er9
  int v30; // er8
  int v31; // er10
  int v32; // eax
  int v33; // ecx
  char v34; // al
  unsigned int v35; // eax
  UFG::SectionChooser::SectionInfo *v36; // r14
  UFG::SectionChooser::LOD_SUPRESSION v37; // er13
  unsigned int v38; // er15
  bool v39; // bl
  UFG::SectionChooser::SectionInfo *v40; // rcx
  unsigned int v41; // eax
  char v42; // al
  signed __int64 v43; // rcx
  int v44; // er11
  int v45; // er9
  signed int v46; // ecx
  int v47; // er8
  int v48; // esi
  int v49; // er10
  int v50; // ebx
  int v51; // eax
  int v52; // eax
  unsigned int v53; // er13
  unsigned int v54; // eax
  UFG::SectionChooser::SectionInfo *v55; // r14
  unsigned int v56; // er15
  bool v57; // bl
  UFG::SectionChooser::SectionInfo *v58; // rcx
  unsigned int v59; // eax
  bool v60; // al
  signed __int64 v61; // rcx
  int v62; // er9
  int v63; // er10
  signed int v64; // ecx
  int v65; // er8
  int v66; // eax
  int v67; // ecx
  int v68; // er8
  int v69; // er11
  int v70; // eax
  int v71; // eax
  UFG::SceneryGroup *v72; // rax
  unsigned __int16 v73; // dx
  __int64 v74; // rcx
  CullInfoFull *v75; // rsi
  int v76; // ebx
  CullManager *v77; // rax
  UFG::SceneryGroup *v78; // rcx
  unsigned __int16 v79; // dx
  __int64 v80; // rax
  int v81; // ebx
  CullManager *v82; // rax
  unsigned int vis_index; // [rsp+70h] [rbp+8h]
  CullLayer *v84; // [rsp+78h] [rbp+10h]
  UFG::SceneryGroupComponent *v85; // [rsp+80h] [rbp+18h]

  v85 = matching_std_group;
  v84 = cull_layer;
  v3 = this;
  v4 = this->mSceneryGroup;
  v5 = cull_layer;
  if ( v4->mFlags & 1 )
    return;
  v6 = v4->mSceneryLayer;
  v7 = 0i64;
  v8 = 1;
  if ( v6 == 4 )
  {
    v9 = v4->mSectionVisIndex;
    v10 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v9, 1);
    v11 = UFG::SectionChooser::mSectionInfo;
    if ( v10 >= 1 )
    {
      if ( UFG::SectionChooser::mSectionInfo
        && (v13 = &UFG::SectionChooser::mSectionInfo[v10], v13->meLODLevelCurrent.mValue == 2) )
      {
        v12 = v13->meLoadStateSTD.mValue == 2;
      }
      else
      {
        v12 = 0;
      }
    }
    else
    {
      v12 = 1;
    }
    v14 = UFG::SectionChooser::meSuppressLOD;
    if ( !v12 )
    {
      v15 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v9, 1);
      if ( v15 >= 1 )
        v12 = v11
           && ((v16 = (signed __int64)&v11[v15], *(_BYTE *)(v16 + 4) != 2)
            || *(_BYTE *)(v16 + 1) != 2
            || *(_DWORD *)(v16 + 160) >= UFG::Metrics::msFrameCount - 2)
           && v14 != 1
           && *(_BYTE *)v16 == 2
           && *(_DWORD *)(v16 + 156) < UFG::Metrics::msFrameCount - 2;
      else
        v12 = 1;
    }
    v17 = Render::TransparencySystem::msOpaqueIndex;
    v18 = (unsigned __int8)v3->mTransparencyState[0];
    v20 = 0;
    v21 = 0;
    v8 = 1;
    v22 = Render::TransparencySystem::msOpaqueIndex;
    if ( v14 )
      v8 = 0;
    LOBYTE(v20) = v12 == 0;
    if ( v12 )
      v22 = 0;
    LOBYTE(v21) = v20 == 1;
    v23 = v21 + 1;
    v24 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v20 == 3 )
    {
      v18 = v22;
LABEL_37:
      v26 = 0;
      v3->mTransparencyState[1] = v22;
      if ( v18 > 0 )
        v26 = v18;
      v3->mTransparencyState[2] = v24;
      if ( v26 < v17 )
        LOBYTE(v17) = v26;
      v3->mTransparencyState[0] = v17;
LABEL_157:
      v5 = v84;
      goto LABEL_158;
    }
    if ( v20 == 2 )
    {
      if ( v24 & 1 )
        goto LABEL_37;
    }
    else
    {
      v19 = (unsigned __int8)v3->mTransparencyState[2];
      v25 = v24 - (v19 + 1) % 255;
      if ( v25 < 0 )
        v25 = (v19 + 1) % 255 - v24;
      if ( v25 > 0 )
      {
        v18 = v22;
        goto LABEL_37;
      }
    }
    if ( v18 >= v22 )
    {
      if ( v18 > v22 )
        v18 -= v23;
    }
    else
    {
      v18 += v23;
    }
    goto LABEL_37;
  }
  v27 = v4->mSectionVisIndex;
  if ( v27 != -1 )
  {
    v28 = v6;
    if ( v6 == 3 )
    {
      v29 = Render::TransparencySystem::msOpaqueIndex;
      v30 = (unsigned __int8)v3->mTransparencyState[0];
      v8 = 1;
      v31 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      v32 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255
          - ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255;
      if ( v32 < 0 )
        v32 = ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255
            - (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      if ( v32 <= 0 )
      {
        if ( v30 >= Render::TransparencySystem::msOpaqueIndex )
        {
          if ( v30 > Render::TransparencySystem::msOpaqueIndex )
            v30 -= 2;
        }
        else
        {
          v30 += 2;
        }
      }
      else
      {
        v30 = Render::TransparencySystem::msOpaqueIndex;
      }
      v33 = 0;
      v34 = Render::TransparencySystem::msOpaqueIndex;
      if ( v30 > 0 )
        v33 = v30;
      v3->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
      v3->mTransparencyState[2] = v31;
      if ( v33 < v29 )
        v34 = v33;
      v3->mTransparencyState[0] = v34;
      goto LABEL_158;
    }
    if ( v6 == 2 )
    {
      vis_index = v27;
      v35 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v27, 1);
      v36 = UFG::SectionChooser::mSectionInfo;
      v37 = UFG::SectionChooser::meSuppressLOD;
      v38 = UFG::Metrics::msFrameCount;
      if ( v35 < 1 )
      {
        v39 = 1;
        goto LABEL_71;
      }
      if ( UFG::SectionChooser::mSectionInfo )
      {
        v40 = &UFG::SectionChooser::mSectionInfo[v35];
        if ( v28 == 2 )
        {
          if ( v40->meLODLevelCurrent.mValue == 2 )
          {
            v39 = v40->meLoadStateSTD.mValue == 2;
            goto LABEL_71;
          }
        }
        else if ( v28 == 1
               && (v40->meLODLevelCurrent.mValue != 2
                || v40->meLoadStateSTD.mValue != 2
                || v40->mChangedStateFrameStamp[2] >= UFG::Metrics::msFrameCount - 2)
               && UFG::SectionChooser::meSuppressLOD != 1 )
        {
          v39 = v40->meLoadStateMID.mValue == 2;
          goto LABEL_71;
        }
      }
      v39 = 0;
LABEL_71:
      v8 = v39;
      v41 = UFG::SectionChooser::GetCellToLoadFromVisIndex(vis_index, 1);
      if ( v41 < 1 )
      {
        v42 = 1;
        goto LABEL_88;
      }
      if ( v36 )
      {
        v43 = (signed __int64)&v36[v41];
        if ( v28 == 2 )
        {
          if ( *(_BYTE *)(v43 + 4) == 2 && *(_BYTE *)(v43 + 1) == 2 && *(_DWORD *)(v43 + 160) < v38 - 2 )
          {
            v42 = 1;
            goto LABEL_88;
          }
        }
        else if ( v28 == 1
               && (*(_BYTE *)(v43 + 4) != 2 || *(_BYTE *)(v43 + 1) != 2 || *(_DWORD *)(v43 + 160) >= v38 - 2)
               && v37 != 1
               && *(_BYTE *)v43 == 2
               && *(_DWORD *)(v43 + 156) < v38 - 2 )
        {
          v42 = 1;
          goto LABEL_88;
        }
      }
      v42 = 0;
LABEL_88:
      v44 = Render::TransparencySystem::msOpaqueIndex;
      v45 = 0;
      if ( v39 )
        v45 = Render::TransparencySystem::msOpaqueIndex;
      if ( !v39 || v42 )
        v46 = 1;
      else
        v46 = 2;
      v47 = (unsigned __int8)v3->mTransparencyState[0];
      v49 = (v46 == 1) + 1;
      v50 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      if ( v46 == 3 )
      {
        v47 = v45;
LABEL_106:
        v52 = 0;
        v3->mTransparencyState[1] = v45;
        if ( v47 > 0 )
          v52 = v47;
        v3->mTransparencyState[2] = v50;
        if ( v52 < v44 )
          LOBYTE(v44) = v52;
        v3->mTransparencyState[0] = v44;
LABEL_154:
        if ( !v8 )
        {
          v8 = 0;
          if ( v3->mTransparencyState[0] > 0u )
            v8 = 1;
        }
        goto LABEL_157;
      }
      if ( v46 == 2 )
      {
        if ( v50 & 1 )
          goto LABEL_106;
      }
      else
      {
        v48 = (unsigned __int8)v3->mTransparencyState[2];
        v51 = v50 - (v48 + 1) % 255;
        if ( v51 < 0 )
          v51 = (v48 + 1) % 255 - v50;
        if ( v51 > 0 )
        {
          v47 = v45;
          goto LABEL_106;
        }
      }
      if ( v47 >= v45 )
      {
        if ( v47 > v45 )
          v47 -= v49;
      }
      else
      {
        v47 += v49;
      }
      goto LABEL_106;
    }
    v53 = v27;
    v54 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v27, 1);
    v55 = UFG::SectionChooser::mSectionInfo;
    v56 = UFG::Metrics::msFrameCount;
    if ( v54 < 1 )
    {
      v57 = 1;
LABEL_124:
      v8 = v57;
      v59 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v53, 1);
      if ( v59 >= 1 )
      {
        v60 = 0;
        if ( v55 )
        {
          v61 = v59;
          if ( v55[v61].meLODLevelCurrent.mValue == 2
            && v55[v61].meLoadStateSTD.mValue == 2
            && v55[v61].mChangedStateFrameStamp[2] < v56 - 2 )
          {
            v60 = 1;
          }
        }
      }
      else
      {
        v60 = 1;
      }
      v62 = Render::TransparencySystem::msOpaqueIndex;
      if ( v57 || (v63 = 0, !v60) )
        v63 = Render::TransparencySystem::msOpaqueIndex;
      if ( v85 )
      {
        v64 = Render::TransparencySystem::msTransparencyFrameCounter;
        v65 = Render::TransparencySystem::msOpaqueIndex - (unsigned __int8)v85->mTransparencyState[0];
        v3->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex - v85->mTransparencyState[0];
        v66 = 0;
        v67 = v64 % 255;
        if ( v65 > 0 )
          v66 = v65;
        v3->mTransparencyState[2] = v67;
        if ( v66 < v62 )
          LOBYTE(v62) = v66;
        v3->mTransparencyState[0] = v62;
        v3->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex - v85->mTransparencyState[1];
      }
      else
      {
        v68 = (unsigned __int8)v3->mTransparencyState[0];
        v69 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
        v70 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255
            - ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255;
        if ( v70 < 0 )
          v70 = ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255
              - (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
        if ( v70 <= 0 )
        {
          if ( v68 >= v63 )
          {
            if ( v68 > v63 )
              v68 -= 2;
          }
          else
          {
            v68 += 2;
          }
        }
        else
        {
          v68 = v63;
        }
        v71 = 0;
        v3->mTransparencyState[1] = v63;
        if ( v68 > 0 )
          v71 = v68;
        v3->mTransparencyState[2] = v69;
        if ( v71 < v62 )
          LOBYTE(v62) = v71;
        v3->mTransparencyState[0] = v62;
      }
      goto LABEL_154;
    }
    if ( UFG::SectionChooser::mSectionInfo )
    {
      v58 = &UFG::SectionChooser::mSectionInfo[v54];
      if ( v28 == 2 )
      {
        if ( v58->meLODLevelCurrent.mValue == 2 )
        {
          v57 = v58->meLoadStateSTD.mValue == 2;
          goto LABEL_124;
        }
      }
      else if ( v28 == 1
             && (v58->meLODLevelCurrent.mValue != 2
              || v58->meLoadStateSTD.mValue != 2
              || v58->mChangedStateFrameStamp[2] >= UFG::Metrics::msFrameCount - 2)
             && UFG::SectionChooser::meSuppressLOD != 1 )
      {
        v57 = v58->meLoadStateMID.mValue == 2;
        goto LABEL_124;
      }
    }
    v57 = 0;
    goto LABEL_124;
  }
LABEL_158:
  v72 = v3->mSceneryGroup;
  v73 = v72->mNumOccluders;
  if ( v73 )
  {
    v74 = v72->mOccluderInfo.mOffset;
    if ( v74 )
      v75 = (CullInfoFull *)((char *)&v72->mOccluderInfo + v74);
    else
      v75 = 0i64;
    v76 = v73;
    v77 = CullManager::Instance();
    CullManager::AllocPrebuiltFrameOcclusionInfos(v77, v76, v75, 0i64);
  }
  v78 = v3->mSceneryGroup;
  v79 = v78->mNumInstances;
  if ( v79 && v8 )
  {
    v80 = v78->mCullInfo.mOffset;
    if ( v80 )
      v7 = (CullInfo *)((char *)&v78->mCullInfo + v80);
    v81 = v79;
    v82 = CullManager::Instance();
    CullManager::AllocPrebuiltFrameCullInfos(v82, 0i64, v81, v7, v5);
  }
}

// File Line: 209
// RVA: 0x231340
void __fastcall UFG::SceneryGroupComponent::Draw(UFG::SceneryGroupComponent *this, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::SceneryGroupComponent *v3; // rsi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rax
  float v6; // xmm0_4

  v2 = view;
  v3 = this;
  if ( gDrawScenery )
  {
    v4 = UFG::qGetTicks();
    UFG::SceneryGroup::DrawStatic(v3->mSceneryGroup, v2, v3->mTransparencyState);
    v5 = UFG::qGetTicks();
    v6 = UFG::qGetTickTime(v4, v5);
    Render::View::AddMetric_DrawScenery(v2, v6);
  }
}

// File Line: 234
// RVA: 0x232100
void __fastcall UFG::SceneryGroupComponent::GenerateCullInfoAll(CullLayer *cull_layer)
{
  CullLayer *v1; // r11
  UFG::allocator::free_link *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // er14
  char *v5; // r13
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v6; // r9
  UFG::SceneryGroupComponent *v7; // r15
  signed __int64 v8; // r12
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r14
  UFG::allocator::free_link *v15; // rdx
  __int64 v16; // rcx
  UFG::SceneryGroupComponent *v17; // r9
  signed __int64 v18; // rbx
  UFG::SceneryGroup *v19; // rcx
  UFG::SceneryGroupComponent *v20; // r10
  int v21; // eax
  CullLayer *v22; // [rsp+80h] [rbp+8h]

  v22 = cull_layer;
  v1 = cull_layer;
  if ( UFG::SectionChooser::mBSP && UFG::SectionChooser::mBSP->mSpaceCount )
  {
    v2 = 0i64;
    v3 = 0;
    v4 = 0;
    v5 = (char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88;
    v6 = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext;
    v7 = (UFG::SceneryGroupComponent *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
    if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
    {
      do
      {
        v8 = (signed __int64)&v7->mNext[-6].mNext;
        if ( v7->mSceneryGroup->mSceneryLayer == 2 )
        {
          v9 = v3;
          v10 = v3 + 1;
          if ( v3 + 1 > v4 )
          {
            v11 = 1;
            if ( v4 )
              v11 = 2 * v4;
            for ( ; v11 < v10; v11 *= 2 )
              ;
            if ( v11 <= 2 )
              v11 = 2;
            if ( v11 - v10 > 0x10000 )
              v11 = v3 + 65537;
            if ( v11 != v3 )
            {
              v12 = 8i64 * v11;
              if ( !is_mul_ok(v11, 8ui64) )
                v12 = -1i64;
              v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
              v14 = v13;
              if ( v2 )
              {
                if ( v3 )
                {
                  v15 = v13;
                  v16 = v3;
                  do
                  {
                    v15->mNext = *(UFG::allocator::free_link **)((char *)v15 + (char *)v2 - (char *)v13);
                    ++v15;
                    --v16;
                  }
                  while ( v16 );
                }
                operator delete[](v2);
              }
              v2 = v14;
              v4 = v11;
              v9 = v3;
              v1 = v22;
            }
          }
          ++v3;
          v2[v9].mNext = (UFG::allocator::free_link *)v7;
          UFG::SceneryGroupComponent::GenerateCullInfo(v7, v1, 0i64);
          v1 = v22;
        }
        v7 = (UFG::SceneryGroupComponent *)v8;
      }
      while ( (char *)v8 != v5 );
      v6 = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext;
    }
    v17 = (UFG::SceneryGroupComponent *)&v6[-6].mNext;
    if ( v17 != (UFG::SceneryGroupComponent *)v5 )
    {
      do
      {
        v18 = (signed __int64)&v17->mNext[-6].mNext;
        v19 = v17->mSceneryGroup;
        if ( v19->mSceneryLayer != 2 )
        {
          v20 = 0i64;
          v21 = 0;
          if ( v3 )
          {
            while ( LOWORD(v2[v21].mNext[13].mNext[21].mNext) != v19->mSectionCellIndex )
            {
              if ( ++v21 >= v3 )
                goto LABEL_33;
            }
            v20 = (UFG::SceneryGroupComponent *)v2[v21].mNext;
          }
LABEL_33:
          UFG::SceneryGroupComponent::GenerateCullInfo(v17, v1, v20);
        }
        v17 = (UFG::SceneryGroupComponent *)v18;
        v1 = v22;
      }
      while ( (char *)v18 != v5 );
    }
    if ( v2 )
      operator delete[](v2);
  }
};
        v1 = v22;
      }
      while ( (char *)v18 != v5 );
    }
    if ( v2 )
      operat

// File Line: 271
// RVA: 0x1470110
void UFG::_dynamic_initializer_for__depth_colors__()
{
  UFG::depth_colors[0] = UFG::qColour::White;
  xmmword_1423A99A0 = (__int128)UFG::qColour::Yellow;
  xmmword_1423A99B0 = (__int128)UFG::qColour::Orange;
  xmmword_1423A99C0 = (__int128)UFG::qColour::Red;
  xmmword_1423A99D0 = (__int128)UFG::qColour::Green;
  xmmword_1423A99E0 = (__int128)UFG::qColour::Cyan;
  xmmword_1423A99F0 = (__int128)UFG::qColour::Blue;
  xmmword_1423A9A00 = (__int128)UFG::qColour::Purple;
}

// File Line: 412
// RVA: 0x232DF0
char __fastcall UFG::SceneryGroupComponent::GetTransform(UFG::SceneryGroupComponent *this, Render::Decal *decal, UFG::qMatrix44 *mat)
{
  Render::Decal *v3; // r9
  char result; // al
  UFG::SceneryGroup *v5; // rax
  __int64 v6; // rcx
  signed __int64 v7; // rax
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1

  v3 = decal;
  if ( *(_BYTE *)decal->mSceneryData2 > 1u )
    return 0;
  v5 = this->mSceneryGroup;
  v6 = v5->mInstances.mOffset;
  v7 = (signed __int64)&v5->mInstances;
  if ( v6 )
    v8 = v6 + v7;
  else
    v8 = 0i64;
  result = 1;
  v9 = 96i64 * v3->mBindIndex;
  v10 = *(UFG::qVector4 *)(v9 + v8 + 48);
  v11 = *(UFG::qVector4 *)(v9 + v8 + 64);
  v12 = *(UFG::qVector4 *)(v9 + v8 + 80);
  mat->v0 = *(UFG::qVector4 *)(v9 + v8 + 32);
  mat->v1 = v10;
  mat->v2 = v11;
  mat->v3 = v12;
  return result;
}

// File Line: 422
// RVA: 0x234430
void __fastcall UFG::SceneryGroupComponent::OnResetDecal(UFG::SceneryGroupComponent *this, Render::Decal *decal)
{
  CullResults *v2; // rbx
  CullInfo *v3; // rdi
  CullManager *v4; // rax

  v2 = (CullResults *)decal->mSceneryData2;
  v3 = (CullInfo *)decal->mSceneryData1;
  if ( v2 )
  {
    v4 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v4, v2, v3);
  }
}

// File Line: 433
// RVA: 0x234000
void __fastcall UFG::SceneryGroupComponent::OnAttachDecal(UFG::SceneryGroupComponent *this, Render::Decal *decal, Render::DecalClipQuery *dcq)
{
  Render::DecalClipInfo *v3; // r9
  Render::DecalClipQuery *v4; // rsi
  UFG::SceneryGroupComponent *v5; // rbp
  UFG::SimComponent *v6; // rax
  CullInfo **v7; // rdi
  CullResults **v8; // rbx
  CullManager *v9; // rax
  UFG::SceneryGroup *v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  CullInfo *v13; // rcx
  signed __int64 v14; // rbx
  Render::DecalClipTaskResults *v15; // rdx
  float v16; // xmm0_4
  float v17; // xmm1_4
  CullInfo *v18; // rcx
  float v19; // xmm0_4
  float v20; // xmm1_4

  v3 = dcq->decal_info;
  v4 = dcq;
  v5 = this;
  v6 = v3->mStoredObjLink.mComponentPtr.m_pPointer;
  if ( v6 && v6 != (UFG::SimComponent *)24 )
  {
    v7 = (CullInfo **)&decal->mSceneryData1;
    v8 = (CullResults **)&decal->mSceneryData2;
    decal->mBindIndex = v3->mStoredObjLink.mIndex;
    v9 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v9, v8, v7, 0i64, 0i64, 0i64);
    v10 = v5->mSceneryGroup;
    v11 = v10->mInstances.mOffset;
    v12 = (signed __int64)&v10->mInstances + v11;
    if ( !v11 )
      v12 = 0i64;
    v13 = *v7;
    v14 = v12 + 96i64 * v4->decal_info->mStoredObjLink.mIndex;
    v15 = v4->task_results;
    v16 = v15->mAabbMin.y;
    v17 = v15->mAabbMin.z;
    v13->mAABBMin[0] = v15->mAabbMin.x;
    v13->mAABBMin[1] = v16;
    v13->mAABBMin[2] = v17;
    v18 = *v7;
    v19 = v15->mAabbMax.y;
    v20 = v15->mAabbMax.z;
    v18->mAABBMax[0] = v15->mAabbMax.x;
    v18->mAABBMax[1] = v19;
    v18->mAABBMax[2] = v20;
    (*v7)->mIsLocalWorldIdentity = 0;
    (*v7)->mViewsCulled = -2;
    (*v7)->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
    (*v7)->mpLocalWorld = (float *)(v14 + 32);
  }
}

// File Line: 457
// RVA: 0x235410
void __fastcall UFG::TestSceneryGroupForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qBox *v2; // rsi
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *v3; // r15
  Render::DecalClipRequest *v4; // r14
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v5; // rdi
  __int16 v6; // ax
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *v7; // r12
  unsigned int v8; // ebp
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rbx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v12; // rcx
  signed __int64 v13; // rdx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qMatrix44 *v20; // rax
  UFG::qMatrix44 *v21; // rcx
  __int64 v22; // rax
  signed __int64 v23; // rcx
  __int64 v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v25; // rdx
  UFG::qVector4 v26; // xmm3
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-48h]
  UFG::qVector3 max; // [rsp+30h] [rbp-38h]

  v2 = projBox;
  v3 = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  v4 = request;
  if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
  {
    do
    {
      v5 = v3[6].mNode.mNext;
      v6 = WORD2(v5[10].mNext);
      v7 = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&v3[6].mNode.mPrev[-6].mNext;
      if ( v6 != 1
        && v6 != 4
        && *(float *)&v5[9].mPrev <= v2->mMax.x
        && *((float *)&v5[9].mNext + 1) >= v2->mMin.x
        && *((float *)&v5[9].mPrev + 1) <= v2->mMax.y
        && *(float *)&v5[10].mPrev >= v2->mMin.y
        && *(float *)&v5[9].mNext <= v2->mMax.z
        && *((float *)&v5[10].mPrev + 1) >= v2->mMin.z )
      {
        v8 = 0;
        if ( WORD1(v5[5].mNext) > 0u )
        {
          do
          {
            v9 = v5[6].mNext;
            if ( v9 )
              v10 = (signed __int64)&v5[6].mNext + (_QWORD)v9;
            else
              v10 = 0i64;
            v11 = v10 + 96i64 * v8;
            v12 = v5[7].mPrev;
            if ( v12 )
              v13 = (signed __int64)&v5[7] + (_QWORD)v12;
            else
              v13 = 0i64;
            v14 = (unsigned __int64)v8 << 6;
            if ( !(*(_WORD *)(v14 + v13 + 30) & 0x8000) )
            {
              if ( v12 )
                v15 = (signed __int64)&v12[7] + (_QWORD)v5;
              else
                v15 = 0i64;
              v16 = *(float *)(v14 + v15 + 4);
              v17 = *(float *)(v14 + v15 + 8);
              min.x = *(float *)(v14 + v15);
              min.y = v16;
              min.z = v17;
              v18 = *(float *)(v14 + v15 + 20);
              v19 = *(float *)(v14 + v15 + 24);
              max.x = *(float *)(v14 + v15 + 16);
              max.y = v18;
              max.z = v19;
              v20 = *(UFG::qMatrix44 **)(v14 + v15 + 56);
              v21 = &UFG::qMatrix44::msIdentity;
              if ( v20 )
                v21 = v20;
              TransformAABB(v21, &min, &max);
              if ( min.x > v2->mMax.x
                || max.x < v2->mMin.x
                || min.y > v2->mMax.y
                || max.y < v2->mMin.y
                || min.z > v2->mMax.z
                || max.z < v2->mMin.z )
              {
                v8 += *(unsigned __int16 *)(v11 + 6);
              }
              else
              {
                v22 = *(_QWORD *)(v11 + 16);
                if ( v22 )
                {
                  v23 = v11 + v22 + 16;
                  if ( v23 )
                  {
                    v24 = *(_QWORD *)(v23 + 32);
                    if ( v24 )
                    {
                      Illusion::ModelProxy::Init(&v4->mModelProxy, *(_DWORD *)(v24 + 24));
                      v25 = &v4->mComponentPtr;
                      v26 = *(UFG::qVector4 *)(v11 + 48);
                      v27 = *(UFG::qVector4 *)(v11 + 64);
                      v28 = *(UFG::qVector4 *)(v11 + 80);
                      v4->mLocalToWorld.v0 = *(UFG::qVector4 *)(v11 + 32);
                      v4->mLocalToWorld.v1 = v26;
                      v4->mLocalToWorld.v2 = v27;
                      v4->mLocalToWorld.v3 = v28;
                      if ( v4->mComponentPtr.m_pPointer )
                      {
                        v29 = v25->mPrev;
                        v30 = v4->mComponentPtr.mNext;
                        v29->mNext = v30;
                        v30->mPrev = v29;
                        v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
                        v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mComponentPtr.mPrev;
                      }
                      v4->mComponentPtr.m_pPointer = (UFG::SimComponent *)&v3[1].mNode.mNext;
                      if ( v3 != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)-24i64 )
                      {
                        v31 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3[2].mNode.mPrev;
                        v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
                        v25->mPrev = v31;
                        v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3[2];
                        v3[2].mNode.mPrev = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)v25;
                      }
                      v4->mScenery = (Render::IDecalScenery *)v3;
                      v4->mBindIndex = v8;
                      Render::DecalManager::AddClipQueue(&Render::gDecalManager, v4);
                    }
                  }
                }
              }
            }
            ++v8;
          }
          while ( v8 < WORD1(v5[5].mNext) );
        }
      }
      v3 = v7;
    }
    while ( v7 != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList
                                                                                          - 88) );
  }
}

