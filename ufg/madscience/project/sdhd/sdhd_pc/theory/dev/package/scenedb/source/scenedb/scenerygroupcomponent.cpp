// File Line: 37
// RVA: 0x14700B0
__int64 dynamic_initializer_for__UFG::SceneryGroupComponent::s_SceneryGroupComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SceneryGroupComponent::s_SceneryGroupComponentList__);
}

// File Line: 38
// RVA: 0x232E60
const char *__fastcall UFG::SceneryGroupComponent::GetTypeName(UFG::SceneryGroupComponent *this)
{
  return "SceneryGroupComponent";
}

// File Line: 87
// RVA: 0x22F660
void __fastcall UFG::SceneryGroupComponent::SceneryGroupComponent(
        UFG::SceneryGroupComponent *this,
        UFG::SceneryGroup *scenery_group)
{
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mPrev; // rax
  signed int mFrameCount; // ecx

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  UFG::SimComponent::SimComponent(&this->UFG::SimComponent, 0x1111u);
  this->mPrev = &this->UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent>;
  this->mNext = &this->UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent>;
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::SceneryGroupComponent::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneryGroupComponent::`vftable{for `UFG::SimComponent};
  mPrev = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev;
  UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList;
  UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent>;
  UFG::SimComponent::AddType(
    &this->UFG::SimComponent,
    UFG::SceneryGroupComponent::_SceneryGroupComponentTypeUID,
    "SceneryGroupComponent");
  this->mSceneryGroup = scenery_group;
  mFrameCount = Illusion::gEngine.mFrameCount;
  if ( Render::TransparencySystem::msEnabled )
    this->mTransparencyState[0] = 0;
  else
    this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = mFrameCount + mFrameCount / 255;
}

// File Line: 107
// RVA: 0x22FBB0
void __fastcall UFG::SceneryGroupComponent::~SceneryGroupComponent(UFG::SceneryGroupComponent *this)
{
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v2; // rbx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mPrev; // rcx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mNext; // rax
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v5; // rdx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v6; // rax

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::SceneryGroupComponent::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneryGroupComponent::`vftable{for `UFG::SimComponent};
  if ( this == UFG::SceneryGroupComponent::s_SceneryGroupComponentpCurrentIterator )
    UFG::SceneryGroupComponent::s_SceneryGroupComponentpCurrentIterator = (UFG::SceneryGroupComponent *)&this->mPrev[-6].mNext;
  v2 = &this->UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  Render::IDecalScenery::RemoveAttachedDecals(this, 0xFFFFFFFF);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(&this->UFG::SimComponent);
  Render::IDecalScenery::~IDecalScenery(this);
}

// File Line: 120
// RVA: 0x2319F0
void __fastcall UFG::SceneryGroupComponent::GenerateCullInfo(
        UFG::SceneryGroupComponent *this,
        CullLayer *cull_layer,
        UFG::SceneryGroupComponent *matching_std_group)
{
  UFG::SceneryGroup *mSceneryGroup; // rcx
  CullLayer *v5; // r14
  unsigned __int16 mSceneryLayer; // ax
  CullInfo *v7; // rbp
  bool v8; // r12
  unsigned int mSectionVisIndex; // esi
  int CellToLoadFromVisIndex; // eax
  UFG::SectionChooser::SectionInfo *v11; // rbx
  bool v12; // al
  UFG::SectionChooser::SectionInfo *v13; // rax
  UFG::SectionChooser::LOD_SUPRESSION v14; // r14d
  int v15; // eax
  UFG::SectionChooser::SectionInfo *v16; // rcx
  int v17; // r11d
  int v18; // r8d
  int v19; // esi
  int v20; // ecx
  int v21; // r10d
  int v22; // r9d
  int v23; // r10d
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  unsigned __int16 v27; // dx
  int v28; // esi
  int v29; // r9d
  int v30; // r8d
  int v31; // r10d
  int v32; // eax
  int v33; // ecx
  char v34; // al
  int v35; // eax
  UFG::SectionChooser::SectionInfo *v36; // r14
  UFG::SectionChooser::LOD_SUPRESSION v37; // r13d
  unsigned int v38; // r15d
  bool v39; // bl
  UFG::SectionChooser::SectionInfo *v40; // rcx
  int v41; // eax
  char v42; // al
  UFG::SectionChooser::SectionInfo *v43; // rcx
  int v44; // r11d
  int v45; // r9d
  int v46; // ecx
  int v47; // r8d
  int v48; // esi
  int v49; // r10d
  int v50; // ebx
  int v51; // eax
  int v52; // eax
  unsigned int v53; // r13d
  int v54; // eax
  UFG::SectionChooser::SectionInfo *v55; // r14
  unsigned int v56; // r15d
  bool v57; // bl
  UFG::SectionChooser::SectionInfo *v58; // rcx
  unsigned int v59; // eax
  bool v60; // al
  __int64 v61; // rcx
  int v62; // r9d
  int v63; // r10d
  signed int v64; // ecx
  int v65; // r8d
  int v66; // eax
  int v67; // ecx
  int v68; // r8d
  int v69; // r11d
  int v70; // eax
  int v71; // eax
  UFG::SceneryGroup *v72; // rax
  unsigned __int16 mNumOccluders; // dx
  __int64 mOffset; // rcx
  CullInfoFull *v75; // rsi
  int v76; // ebx
  CullManager *v77; // rax
  UFG::SceneryGroup *v78; // rcx
  unsigned __int16 mNumInstances; // dx
  __int64 v80; // rax
  int v81; // ebx
  CullManager *v82; // rax
  unsigned int vis_index; // [rsp+70h] [rbp+8h]

  mSceneryGroup = this->mSceneryGroup;
  v5 = cull_layer;
  if ( (mSceneryGroup->mFlags & 1) != 0 )
    return;
  mSceneryLayer = mSceneryGroup->mSceneryLayer;
  v7 = 0i64;
  v8 = 1;
  if ( mSceneryLayer == 4 )
  {
    mSectionVisIndex = mSceneryGroup->mSectionVisIndex;
    CellToLoadFromVisIndex = UFG::SectionChooser::GetCellToLoadFromVisIndex(mSectionVisIndex, 1);
    v11 = UFG::SectionChooser::mSectionInfo;
    if ( CellToLoadFromVisIndex )
      v12 = UFG::SectionChooser::mSectionInfo
         && (v13 = &UFG::SectionChooser::mSectionInfo[CellToLoadFromVisIndex], v13->meLODLevelCurrent.mValue == 2)
         && v13->meLoadStateSTD.mValue == 2;
    else
      v12 = 1;
    v14 = UFG::SectionChooser::meSuppressLOD;
    if ( !v12 )
    {
      v15 = UFG::SectionChooser::GetCellToLoadFromVisIndex(mSectionVisIndex, 1);
      if ( v15 )
        v12 = v11
           && ((v16 = &v11[v15], v16->meLODLevelCurrent.mValue != 2)
            || v16->meLoadStateSTD.mValue != 2
            || v16->mChangedStateFrameStamp[2] >= UFG::Metrics::msFrameCount - 2)
           && v14 != SUPRESS_ISLAND
           && v16->meLoadStateMID.mValue == 2
           && v16->mChangedStateFrameStamp[1] < UFG::Metrics::msFrameCount - 2;
      else
        v12 = 1;
    }
    v17 = Render::TransparencySystem::msOpaqueIndex;
    v18 = (unsigned __int8)this->mTransparencyState[0];
    v20 = 0;
    v21 = 0;
    v8 = 1;
    v22 = Render::TransparencySystem::msOpaqueIndex;
    if ( v14 )
      v8 = 0;
    LOBYTE(v20) = !v12;
    if ( v12 )
      v22 = 0;
    LOBYTE(v21) = v20 == 1;
    v23 = v21 + 1;
    v24 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v20 == 3 )
    {
      v18 = v22;
LABEL_37:
      v26 = 0;
      this->mTransparencyState[1] = v22;
      if ( v18 > 0 )
        v26 = v18;
      this->mTransparencyState[2] = v24;
      if ( v26 < v17 )
        LOBYTE(v17) = v26;
      this->mTransparencyState[0] = v17;
LABEL_154:
      v5 = cull_layer;
      goto LABEL_155;
    }
    if ( v20 == 2 )
    {
      if ( (v24 & 1) != 0 )
        goto LABEL_37;
    }
    else
    {
      v19 = (unsigned __int8)this->mTransparencyState[2];
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
  v27 = mSceneryGroup->mSectionVisIndex;
  if ( v27 != 0xFFFF )
  {
    v28 = mSceneryLayer;
    if ( mSceneryLayer == 3 )
    {
      v29 = Render::TransparencySystem::msOpaqueIndex;
      v30 = (unsigned __int8)this->mTransparencyState[0];
      v8 = 1;
      v31 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      v32 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255
          - ((unsigned __int8)this->mTransparencyState[2] + 1) % 255;
      if ( v32 < 0 )
        v32 = ((unsigned __int8)this->mTransparencyState[2] + 1) % 255
            - (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
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
      this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
      this->mTransparencyState[2] = v31;
      if ( v33 < v29 )
        v34 = v33;
      this->mTransparencyState[0] = v34;
      goto LABEL_155;
    }
    if ( mSceneryLayer == 2 )
    {
      vis_index = v27;
      v35 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v27, 1);
      v36 = UFG::SectionChooser::mSectionInfo;
      v37 = UFG::SectionChooser::meSuppressLOD;
      v38 = UFG::Metrics::msFrameCount;
      if ( !v35 )
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
               && UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND )
        {
          v39 = v40->meLoadStateMID.mValue == 2;
          goto LABEL_71;
        }
      }
      v39 = 0;
LABEL_71:
      v8 = v39;
      v41 = UFG::SectionChooser::GetCellToLoadFromVisIndex(vis_index, 1);
      if ( !v41 )
      {
        v42 = 1;
        goto LABEL_88;
      }
      if ( v36 )
      {
        v43 = &v36[v41];
        if ( v28 == 2 )
        {
          if ( v43->meLODLevelCurrent.mValue == 2
            && v43->meLoadStateSTD.mValue == 2
            && v43->mChangedStateFrameStamp[2] < v38 - 2 )
          {
            v42 = 1;
            goto LABEL_88;
          }
        }
        else if ( v28 == 1
               && (v43->meLODLevelCurrent.mValue != 2
                || v43->meLoadStateSTD.mValue != 2
                || v43->mChangedStateFrameStamp[2] >= v38 - 2)
               && v37 != SUPRESS_ISLAND
               && v43->meLoadStateMID.mValue == 2
               && v43->mChangedStateFrameStamp[1] < v38 - 2 )
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
      v47 = (unsigned __int8)this->mTransparencyState[0];
      v49 = (v46 == 1) + 1;
      v50 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      if ( v46 == 2 )
      {
        if ( (v50 & 1) == 0 )
        {
LABEL_96:
          if ( v47 >= v45 )
          {
            if ( v47 > v45 )
              v47 -= v49;
          }
          else
          {
            v47 += v49;
          }
        }
      }
      else
      {
        v48 = (unsigned __int8)this->mTransparencyState[2];
        v51 = v50 - (v48 + 1) % 255;
        if ( v51 < 0 )
          v51 = (v48 + 1) % 255 - v50;
        if ( v51 <= 0 )
          goto LABEL_96;
        v47 = v45;
      }
      v52 = 0;
      this->mTransparencyState[1] = v45;
      if ( v47 > 0 )
        v52 = v47;
      this->mTransparencyState[2] = v50;
      if ( v52 < v44 )
        LOBYTE(v44) = v52;
      this->mTransparencyState[0] = v44;
LABEL_152:
      if ( !v8 )
        v8 = this->mTransparencyState[0] != 0;
      goto LABEL_154;
    }
    v53 = v27;
    v54 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v27, 1);
    v55 = UFG::SectionChooser::mSectionInfo;
    v56 = UFG::Metrics::msFrameCount;
    if ( !v54 )
    {
      v57 = 1;
LABEL_122:
      v8 = v57;
      v59 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v53, 1);
      if ( v59 )
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
      if ( matching_std_group )
      {
        v64 = Render::TransparencySystem::msTransparencyFrameCounter;
        v65 = Render::TransparencySystem::msOpaqueIndex - (unsigned __int8)matching_std_group->mTransparencyState[0];
        this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex
                                    - matching_std_group->mTransparencyState[0];
        v66 = 0;
        v67 = v64 % 255;
        if ( v65 > 0 )
          v66 = v65;
        this->mTransparencyState[2] = v67;
        if ( v66 < v62 )
          LOBYTE(v62) = v66;
        this->mTransparencyState[0] = v62;
        this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex
                                    - matching_std_group->mTransparencyState[1];
      }
      else
      {
        v68 = (unsigned __int8)this->mTransparencyState[0];
        v69 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
        v70 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255
            - ((unsigned __int8)this->mTransparencyState[2] + 1) % 255;
        if ( v70 < 0 )
          v70 = ((unsigned __int8)this->mTransparencyState[2] + 1) % 255
              - (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
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
        this->mTransparencyState[1] = v63;
        if ( v68 > 0 )
          v71 = v68;
        this->mTransparencyState[2] = v69;
        if ( v71 < v62 )
          LOBYTE(v62) = v71;
        this->mTransparencyState[0] = v62;
      }
      goto LABEL_152;
    }
    if ( UFG::SectionChooser::mSectionInfo )
    {
      v58 = &UFG::SectionChooser::mSectionInfo[v54];
      if ( v28 == 2 )
      {
        if ( v58->meLODLevelCurrent.mValue == 2 )
        {
          v57 = v58->meLoadStateSTD.mValue == 2;
          goto LABEL_122;
        }
      }
      else if ( v28 == 1
             && (v58->meLODLevelCurrent.mValue != 2
              || v58->meLoadStateSTD.mValue != 2
              || v58->mChangedStateFrameStamp[2] >= UFG::Metrics::msFrameCount - 2)
             && UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND )
      {
        v57 = v58->meLoadStateMID.mValue == 2;
        goto LABEL_122;
      }
    }
    v57 = 0;
    goto LABEL_122;
  }
LABEL_155:
  v72 = this->mSceneryGroup;
  mNumOccluders = v72->mNumOccluders;
  if ( mNumOccluders )
  {
    mOffset = v72->mOccluderInfo.mOffset;
    if ( mOffset )
      v75 = (CullInfoFull *)((char *)&v72->mOccluderInfo + mOffset);
    else
      v75 = 0i64;
    v76 = mNumOccluders;
    v77 = CullManager::Instance();
    CullManager::AllocPrebuiltFrameOcclusionInfos(v77, v76, v75, 0i64);
  }
  v78 = this->mSceneryGroup;
  mNumInstances = v78->mNumInstances;
  if ( mNumInstances && v8 )
  {
    v80 = v78->mCullInfo.mOffset;
    if ( v80 )
      v7 = (CullInfo *)((char *)&v78->mCullInfo + v80);
    v81 = mNumInstances;
    v82 = CullManager::Instance();
    CullManager::AllocPrebuiltFrameCullInfos(v82, 0i64, v81, v7, v5);
  }
}

// File Line: 209
// RVA: 0x231340
void __fastcall UFG::SceneryGroupComponent::Draw(UFG::SceneryGroupComponent *this, Render::View *view)
{
  unsigned __int64 Ticks; // rbx
  unsigned __int64 v5; // rax
  float TickTime; // xmm0_4

  if ( gDrawScenery )
  {
    Ticks = UFG::qGetTicks();
    UFG::SceneryGroup::DrawStatic(this->mSceneryGroup, view, this->mTransparencyState);
    v5 = UFG::qGetTicks();
    TickTime = UFG::qGetTickTime(Ticks, v5);
    Render::View::AddMetric_DrawScenery(view, TickTime);
  }
}

// File Line: 234
// RVA: 0x232100
void __fastcall UFG::SceneryGroupComponent::GenerateCullInfoAll(CullLayer *cull_layer)
{
  CullLayer *v1; // r11
  UFG::allocator::free_link *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // r14d
  char *v5; // r13
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mNext; // r9
  UFG::SceneryGroupComponent *p_mNext; // r15
  __int64 v8; // r12
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r14
  UFG::allocator::free_link *v15; // rdx
  __int64 v16; // rcx
  UFG::SceneryGroupComponent *v17; // r9
  __int64 v18; // rbx
  UFG::SceneryGroup *mSceneryGroup; // rcx
  UFG::SceneryGroupComponent *v20; // r10
  int v21; // eax

  v1 = cull_layer;
  if ( UFG::SectionChooser::mBSP && UFG::SectionChooser::mBSP->mSpaceCount )
  {
    v2 = 0i64;
    v3 = 0;
    v4 = 0;
    v5 = (char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88;
    mNext = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext;
    p_mNext = (UFG::SceneryGroupComponent *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
    if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
    {
      do
      {
        v8 = (__int64)&p_mNext->mNext[-6].mNext;
        if ( p_mNext->mSceneryGroup->mSceneryLayer == 2 )
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
              v1 = cull_layer;
            }
          }
          ++v3;
          v2[v9].mNext = (UFG::allocator::free_link *)p_mNext;
          UFG::SceneryGroupComponent::GenerateCullInfo(p_mNext, v1, 0i64);
          v1 = cull_layer;
        }
        p_mNext = (UFG::SceneryGroupComponent *)v8;
      }
      while ( (char *)v8 != v5 );
      mNext = UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext;
    }
    v17 = (UFG::SceneryGroupComponent *)&mNext[-6].mNext;
    if ( v17 != (UFG::SceneryGroupComponent *)v5 )
    {
      do
      {
        v18 = (__int64)&v17->mNext[-6].mNext;
        mSceneryGroup = v17->mSceneryGroup;
        if ( mSceneryGroup->mSceneryLayer != 2 )
        {
          v20 = 0i64;
          v21 = 0;
          if ( v3 )
          {
            while ( LOWORD(v2[v21].mNext[13].mNext[21].mNext) != mSceneryGroup->mSectionCellIndex )
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
        v1 = cull_layer;
      }
      while ( (char *)v18 != v5 );
    }
    if ( v2 )
      operator delete[](v2);
  }
}  v1 = cull_layer;
      }
      while ( (char *)v18 != v5 );
    }
    if ( 

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
bool __fastcall UFG::SceneryGroupComponent::GetTransform(
        UFG::SceneryGroupComponent *this,
        Render::Decal *decal,
        UFG::qMatrix44 *mat)
{
  bool result; // al
  UFG::SceneryGroup *mSceneryGroup; // rax
  __int64 mOffset; // rcx
  UFG::qOffset64<UFG::SceneryInstance *> *p_mInstances; // rax
  char *v8; // rdx
  __int64 v9; // rcx
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1

  if ( *(_BYTE *)decal->mSceneryData2 > 1u )
    return 0;
  mSceneryGroup = this->mSceneryGroup;
  mOffset = mSceneryGroup->mInstances.mOffset;
  p_mInstances = &mSceneryGroup->mInstances;
  if ( mOffset )
    v8 = (char *)p_mInstances + mOffset;
  else
    v8 = 0i64;
  result = 1;
  v9 = 96i64 * decal->mBindIndex;
  v10 = *(UFG::qVector4 *)&v8[v9 + 48];
  v11 = *(UFG::qVector4 *)&v8[v9 + 64];
  v12 = *(UFG::qVector4 *)&v8[v9 + 80];
  mat->v0 = *(UFG::qVector4 *)&v8[v9 + 32];
  mat->v1 = v10;
  mat->v2 = v11;
  mat->v3 = v12;
  return result;
}

// File Line: 422
// RVA: 0x234430
void __fastcall UFG::SceneryGroupComponent::OnResetDecal(UFG::SceneryGroupComponent *this, Render::Decal *decal)
{
  CullResults *mSceneryData2; // rbx
  CullInfo *mSceneryData1; // rdi
  CullManager *v4; // rax

  mSceneryData2 = (CullResults *)decal->mSceneryData2;
  mSceneryData1 = (CullInfo *)decal->mSceneryData1;
  if ( mSceneryData2 )
  {
    v4 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v4, mSceneryData2, mSceneryData1);
  }
}

// File Line: 433
// RVA: 0x234000
void __fastcall UFG::SceneryGroupComponent::OnAttachDecal(
        UFG::SceneryGroupComponent *this,
        Render::Decal *decal,
        Render::DecalClipQuery *dcq)
{
  Render::DecalClipInfo *decal_info; // r9
  UFG::SimComponent *m_pPointer; // rax
  void **p_mSceneryData1; // rdi
  void **p_mSceneryData2; // rbx
  CullManager *v9; // rax
  UFG::SceneryGroup *mSceneryGroup; // rax
  __int64 mOffset; // rcx
  char *v12; // rdx
  CullInfo *v13; // rcx
  char *v14; // rbx
  Render::DecalClipTaskResults *task_results; // rdx
  float y; // xmm0_4
  float z; // xmm1_4
  CullInfo *v18; // rcx
  float v19; // xmm0_4
  float v20; // xmm1_4

  decal_info = dcq->decal_info;
  m_pPointer = decal_info->mStoredObjLink.mComponentPtr.m_pPointer;
  if ( m_pPointer && m_pPointer != (UFG::SimComponent *)24 )
  {
    p_mSceneryData1 = &decal->mSceneryData1;
    p_mSceneryData2 = &decal->mSceneryData2;
    decal->mBindIndex = decal_info->mStoredObjLink.mIndex;
    v9 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(
      v9,
      (CullResults **)p_mSceneryData2,
      (CullInfo **)p_mSceneryData1,
      0i64,
      0i64,
      0i64);
    mSceneryGroup = this->mSceneryGroup;
    mOffset = mSceneryGroup->mInstances.mOffset;
    v12 = (char *)&mSceneryGroup->mInstances + mOffset;
    if ( !mOffset )
      v12 = 0i64;
    v13 = (CullInfo *)*p_mSceneryData1;
    v14 = &v12[96 * dcq->decal_info->mStoredObjLink.mIndex];
    task_results = dcq->task_results;
    y = task_results->mAabbMin.y;
    z = task_results->mAabbMin.z;
    v13->mAABBMin[0] = task_results->mAabbMin.x;
    v13->mAABBMin[1] = y;
    v13->mAABBMin[2] = z;
    v18 = (CullInfo *)*p_mSceneryData1;
    v19 = task_results->mAabbMax.y;
    v20 = task_results->mAabbMax.z;
    v18->mAABBMax[0] = task_results->mAabbMax.x;
    v18->mAABBMax[1] = v19;
    v18->mAABBMax[2] = v20;
    *((_WORD *)*p_mSceneryData1 + 6) = 0;
    *((_WORD *)*p_mSceneryData1 + 15) = -2;
    *((_WORD *)*p_mSceneryData1 + 14) = CullManager::Instance()->mPixelDensityDynamicBias;
    *((_QWORD *)*p_mSceneryData1 + 7) = v14 + 32;
  }
}

// File Line: 457
// RVA: 0x235410
void __fastcall UFG::TestSceneryGroupForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *p_mNext; // r15
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mNext; // rdi
  __int16 v6; // ax
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *v7; // r12
  unsigned int i; // ebp
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rbx
  UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *mPrev; // rcx
  __int64 v13; // rdx
  unsigned __int64 v14; // rax
  __int64 v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qMatrix44 *v20; // rax
  UFG::qMatrix44 *v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rcx
  __int64 v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::qVector4 v26; // xmm3
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 max; // [rsp+30h] [rbp-38h] BYREF

  p_mNext = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
  {
    do
    {
      mNext = p_mNext[6].mNode.mNext;
      v6 = WORD2(mNext[10].mNext);
      v7 = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&p_mNext[6].mNode.mPrev[-6].mNext;
      if ( v6 != 1
        && v6 != 4
        && *(float *)&mNext[9].mPrev <= projBox->mMax.x
        && *((float *)&mNext[9].mNext + 1) >= projBox->mMin.x
        && *((float *)&mNext[9].mPrev + 1) <= projBox->mMax.y
        && *(float *)&mNext[10].mPrev >= projBox->mMin.y
        && *(float *)&mNext[9].mNext <= projBox->mMax.z
        && *((float *)&mNext[10].mPrev + 1) >= projBox->mMin.z )
      {
        for ( i = 0; i < WORD1(mNext[5].mNext); ++i )
        {
          v9 = mNext[6].mNext;
          if ( v9 )
            v10 = (__int64)&mNext[6].mNext + (_QWORD)v9;
          else
            v10 = 0i64;
          v11 = v10 + 96i64 * i;
          mPrev = mNext[7].mPrev;
          if ( mPrev )
            v13 = (__int64)&mNext[7] + (_QWORD)mPrev;
          else
            v13 = 0i64;
          v14 = (unsigned __int64)i << 6;
          if ( (*(_WORD *)(v14 + v13 + 30) & 0x8000) == 0 )
          {
            if ( mPrev )
              v15 = (__int64)&mPrev[7] + (_QWORD)mNext;
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
            if ( min.x > projBox->mMax.x
              || max.x < projBox->mMin.x
              || min.y > projBox->mMax.y
              || max.y < projBox->mMin.y
              || min.z > projBox->mMax.z
              || max.z < projBox->mMin.z )
            {
              i += *(unsigned __int16 *)(v11 + 6);
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
                    Illusion::ModelProxy::Init(&request->mModelProxy, *(_DWORD *)(v24 + 24));
                    p_mComponentPtr = &request->mComponentPtr;
                    v26 = *(UFG::qVector4 *)(v11 + 48);
                    v27 = *(UFG::qVector4 *)(v11 + 64);
                    v28 = *(UFG::qVector4 *)(v11 + 80);
                    request->mLocalToWorld.v0 = *(UFG::qVector4 *)(v11 + 32);
                    request->mLocalToWorld.v1 = v26;
                    request->mLocalToWorld.v2 = v27;
                    request->mLocalToWorld.v3 = v28;
                    if ( request->mComponentPtr.m_pPointer )
                    {
                      v29 = p_mComponentPtr->mPrev;
                      v30 = request->mComponentPtr.mNext;
                      v29->mNext = v30;
                      v30->mPrev = v29;
                      p_mComponentPtr->mPrev = p_mComponentPtr;
                      request->mComponentPtr.mNext = &request->mComponentPtr;
                    }
                    request->mComponentPtr.m_pPointer = (UFG::SimComponent *)&p_mNext[1].mNode.mNext;
                    if ( p_mNext != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)-24i64 )
                    {
                      v31 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext[2].mNode.mPrev;
                      v31->mNext = p_mComponentPtr;
                      p_mComponentPtr->mPrev = v31;
                      request->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&p_mNext[2];
                      p_mNext[2].mNode.mPrev = (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> *)p_mComponentPtr;
                    }
                    request->mScenery = (Render::IDecalScenery *)p_mNext;
                    request->mBindIndex = i;
                    Render::DecalManager::AddClipQueue(&Render::gDecalManager, request);
                  }
                }
              }
            }
          }
        }
      }
      p_mNext = v7;
    }
    while ( v7 != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList
                                                                                          - 88) );
  }
}

