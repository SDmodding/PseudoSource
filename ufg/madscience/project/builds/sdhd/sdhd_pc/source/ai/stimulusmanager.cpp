// File Line: 28
// RVA: 0x14AECB0
__int64 dynamic_initializer_for__UFG::StimulusManager::s_UpdateList1__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StimulusManager::s_UpdateList1__);
}

// File Line: 29
// RVA: 0x14AECD0
__int64 dynamic_initializer_for__UFG::StimulusManager::s_UpdateList2__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StimulusManager::s_UpdateList2__);
}

// File Line: 78
// RVA: 0x351000
void UFG::StimulusManager::CreateInstance(void)
{
  UFG::StimulusManager *v0; // rax

  if ( !UFG::StimulusManager::s_pInstance )
  {
    v0 = (UFG::StimulusManager *)UFG::qMalloc(0x10ui64, "StimulusManager", 0i64);
    if ( v0 )
    {
      v0->m_pCurrentUpdateList = &UFG::StimulusManager::s_UpdateList1;
      v0->m_pOtherUpdateList = &UFG::StimulusManager::s_UpdateList2;
    }
    UFG::StimulusManager::s_pInstance = v0;
  }
}

// File Line: 86
// RVA: 0x352220
void UFG::StimulusManager::DestroyInstance(void)
{
  if ( UFG::StimulusManager::s_pInstance )
  {
    operator delete[](UFG::StimulusManager::s_pInstance);
    UFG::StimulusManager::s_pInstance = 0i64;
  }
}

// File Line: 96
// RVA: 0x3627E0
__int64 __fastcall UFG::StimulusManager::GetStimulusType(const char *type_name)
{
  const char *v1; // rsi
  unsigned int v2; // edi
  const char **v3; // rbx

  v1 = type_name;
  v2 = 0;
  v3 = UFG::g_StimulusName;
  while ( (unsigned int)UFG::qStringCompareInsensitive(v1, *v3, -1) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&OneShotCondition::sClassName )
      return 0i64;
  }
  return v2;
}

// File Line: 109
// RVA: 0x362850
__int64 __fastcall UFG::StimulusManager::GetStimulusType(__int64 type_name)
{
  _DWORD *v1; // rsi
  unsigned int v2; // edi
  const char **v3; // rbx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = (_DWORD *)type_name;
  v2 = 0;
  v3 = UFG::g_StimulusName;
  while ( *v1 != UFG::qSymbol::create_from_string(&result, *v3)->mUID )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&OneShotCondition::sClassName )
      return 0i64;
  }
  return v2;
}

// File Line: 131
// RVA: 0x393060
void __fastcall UFG::StimulusManager::Update(UFG::StimulusManager *this, float timestep)
{
  UFG::StimulusManager *v2; // rbx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v3; // r8
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v4; // rdx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v5; // rdx
  UFG::StimulusEmitterComponent *v6; // rdx
  __int64 v7; // rcx
  __int64 *v8; // rax
  __int64 v9; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v10; // rdx
  signed __int64 v11; // rdx
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // rax
  signed int v15; // edi
  bool v16; // r8
  float v17; // xmm6_4
  __int64 **v18; // rcx
  __int64 *v19; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v20; // r8
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v21; // rdx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v22; // rdx
  signed __int64 v23; // rdx
  __int64 *v24; // rcx
  __int64 **v25; // rax
  __int64 *v26; // rax
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v27; // rdx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v28; // rcx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v29; // rax
  UFG::StimulusEmitterComponent *v30; // rcx
  UFG::StimulusEmitterComponent *v31; // rdx
  __int64 v32; // rcx
  __int64 *v33; // rax
  __int64 *v34; // rcx
  __int64 v35; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v36; // rdx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v37; // rcx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v38; // rax
  __int64 *v39; // rcx
  __int64 **v40; // rax
  __int64 *v41; // rcx
  __int64 **v42; // rax
  __int64 *v43; // rcx
  __int64 **v44; // rax
  __int64 *v45; // rcx
  __int64 **v46; // rax
  __int64 *v47; // rcx
  __int64 **v48; // rax
  __int64 *v49; // rcx
  __int64 **v50; // rax
  __int64 v51; // rcx
  __int64 *v52; // rax
  __int64 v53; // rcx
  __int64 *v54; // rax
  __int64 **v55; // [rsp+18h] [rbp-39h]
  __int64 *v56; // [rsp+20h] [rbp-31h]
  UFG::StimulusEmitterComponent *v57; // [rsp+28h] [rbp-29h]
  __int64 *v58; // [rsp+30h] [rbp-21h]
  __int64 **v59; // [rsp+38h] [rbp-19h]
  UFG::StimulusEmitterComponent *v60; // [rsp+40h] [rbp-11h]
  __int64 *v61; // [rsp+48h] [rbp-9h]
  __int64 **v62; // [rsp+50h] [rbp-1h]
  __int64 v63; // [rsp+58h] [rbp+7h]
  __int64 *v64; // [rsp+60h] [rbp+Fh]
  __int64 **v65; // [rsp+68h] [rbp+17h]
  UFG::StimulusEmitterComponent *v66; // [rsp+70h] [rbp+1Fh]
  __int64 v67; // [rsp+78h] [rbp+27h]

  v67 = -2i64;
  v2 = this;
  v55 = &v56;
  v56 = (__int64 *)&v56;
  v57 = 0i64;
  v61 = (__int64 *)&v61;
  v62 = &v61;
  v63 = 0i64;
  v3 = this->m_pCurrentUpdateList;
  if ( &this->m_pCurrentUpdateList->mNode.mNext[-4] == &this->m_pCurrentUpdateList[-4].mNode )
  {
    v5 = this->m_pOtherUpdateList;
    this->m_pCurrentUpdateList = v5;
    this->m_pOtherUpdateList = v3;
    if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&v5->mNode.mNext[-4] == &v5[-4] )
      goto LABEL_9;
    v4 = v5->mNode.mNext;
  }
  else
  {
    v4 = v3->mNode.mNext;
  }
  v6 = (UFG::StimulusEmitterComponent *)&v4[-4];
  if ( v57 )
  {
    v7 = (__int64)v55;
    v8 = v56;
    v55[1] = v56;
    *v8 = v7;
    v55 = (__int64 **)&v55;
    v56 = (__int64 *)&v55;
  }
  v57 = v6;
  if ( v6 )
  {
    v9 = (__int64)v6->m_SafePointerList.mNode.mPrev;
    *(_QWORD *)(v9 + 8) = &v55;
    v55 = (__int64 **)v9;
    v56 = (__int64 *)&v6->m_SafePointerList;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v55;
  }
LABEL_9:
  v10 = v2->m_pOtherUpdateList;
  if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&v10->mNode.mNext[-4] != &v10[-4]
    || (v10 = v2->m_pCurrentUpdateList, &v2->m_pCurrentUpdateList->mNode.mNext[-4] != &v2->m_pCurrentUpdateList[-4].mNode) )
  {
    v11 = (signed __int64)&v10->mNode.mPrev[-4];
    if ( v63 )
    {
      v12 = v61;
      v13 = v62;
      v61[1] = (__int64)v62;
      *v13 = v12;
      v61 = (__int64 *)&v61;
      v62 = &v61;
    }
    v63 = v11;
    if ( v11 )
    {
      v14 = *(__int64 **)(v11 + 8);
      v14[1] = (__int64)&v61;
      v61 = v14;
      v62 = (__int64 **)(v11 + 8);
      *(_QWORD *)(v11 + 8) = &v61;
    }
  }
  v15 = 0;
  v16 = 0;
  v17 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v57 )
  {
    while ( 1 )
    {
      if ( v15 >= (signed int)(float)(timestep * 1000.0) || v16 )
        goto LABEL_41;
      v64 = (__int64 *)&v64;
      v65 = &v64;
      v66 = v57;
      if ( v57 )
      {
        v18 = (__int64 **)&v57->m_SafePointerList;
        v19 = (__int64 *)v57->m_SafePointerList.mNode.mPrev;
        v19[1] = (__int64)&v64;
        v64 = v19;
        v65 = v18;
        *v18 = (__int64 *)&v64;
      }
      v58 = (__int64 *)&v58;
      v59 = &v58;
      v60 = 0i64;
      v20 = v2->m_pCurrentUpdateList;
      if ( &v66->mNext[-4] != &v2->m_pCurrentUpdateList[-4].mNode )
        break;
      v22 = v2->m_pOtherUpdateList;
      v2->m_pCurrentUpdateList = v22;
      v2->m_pOtherUpdateList = v20;
      if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&v22->mNode.mNext[-4] != &v22[-4] )
      {
        v21 = v22->mNode.mNext;
        goto LABEL_24;
      }
LABEL_28:
      v27 = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v66->mPrev;
      v28 = v66->mPrev;
      v29 = v66->mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = v27;
      v27->mNext = v27;
      v30 = v66;
      if ( v17 >= v66->m_NextUpdateTime )
      {
        UFG::StimulusEmitterComponent::Update(v66, timestep, (hkgpIndexedMeshDefinitions::Edge *)v27);
        ++v15;
        v30 = v66;
      }
      v16 = v63 == (_QWORD)v30;
      v31 = v60;
      if ( v57 )
      {
        v32 = (__int64)v55;
        v33 = v56;
        v55[1] = v56;
        *v33 = v32;
        v55 = (__int64 **)&v55;
        v56 = (__int64 *)&v55;
        v30 = v66;
      }
      v57 = v31;
      if ( v31 )
      {
        v34 = (__int64 *)&v31->m_SafePointerList;
        v35 = (__int64)v31->m_SafePointerList.mNode.mPrev;
        *(_QWORD *)(v35 + 8) = &v55;
        v55 = (__int64 **)v35;
        v56 = v34;
        *v34 = (__int64)&v55;
        v30 = v66;
      }
      if ( v30 )
      {
        v36 = v2->m_pOtherUpdateList;
        v37 = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v30->mPrev;
        v38 = v36->mNode.mPrev;
        v38->mNext = v37;
        v37->mPrev = v38;
        v37->mNext = &v36->mNode;
        v36->mNode.mPrev = v37;
      }
      if ( v60 )
      {
        v39 = v58;
        v40 = v59;
        v58[1] = (__int64)v59;
        *v40 = v39;
        v58 = (__int64 *)&v58;
        v59 = &v58;
      }
      v60 = 0i64;
      v41 = v58;
      v42 = v59;
      v58[1] = (__int64)v59;
      *v42 = v41;
      v58 = (__int64 *)&v58;
      v59 = &v58;
      if ( v66 )
      {
        v43 = v64;
        v44 = v65;
        v64[1] = (__int64)v65;
        *v44 = v43;
        v64 = (__int64 *)&v64;
        v65 = &v64;
      }
      v66 = 0i64;
      v45 = v64;
      v46 = v65;
      v64[1] = (__int64)v65;
      *v46 = v45;
      v64 = (__int64 *)&v64;
      v65 = &v64;
      if ( !v57 )
        goto LABEL_41;
    }
    v21 = v66->mNext;
LABEL_24:
    v23 = (signed __int64)&v21[-4];
    if ( v60 )
    {
      v24 = v58;
      v25 = v59;
      v58[1] = (__int64)v59;
      *v25 = v24;
      v58 = (__int64 *)&v58;
      v59 = &v58;
    }
    v60 = (UFG::StimulusEmitterComponent *)v23;
    if ( v23 )
    {
      v26 = *(__int64 **)(v23 + 8);
      v26[1] = (__int64)&v58;
      v58 = v26;
      v59 = (__int64 **)(v23 + 8);
      *(_QWORD *)(v23 + 8) = &v58;
    }
    goto LABEL_28;
  }
LABEL_41:
  if ( v63 )
  {
    v47 = v61;
    v48 = v62;
    v61[1] = (__int64)v62;
    *v48 = v47;
    v61 = (__int64 *)&v61;
    v62 = &v61;
  }
  v63 = 0i64;
  v49 = v61;
  v50 = v62;
  v61[1] = (__int64)v62;
  *v50 = v49;
  v61 = (__int64 *)&v61;
  v62 = &v61;
  if ( v57 )
  {
    v51 = (__int64)v55;
    v52 = v56;
    v55[1] = v56;
    *v52 = v51;
    v55 = (__int64 **)&v55;
    v56 = (__int64 *)&v55;
  }
  v53 = (__int64)v55;
  v54 = v56;
  v55[1] = v56;
  *v54 = v53;
}

// File Line: 239
// RVA: 0x381F40
void __fastcall UFG::StimulusManager::RenderDebug(UFG::StimulusManager *this, Render::View *pView)
{
  Render::View *v2; // rdi
  UFG::StimulusManager *v3; // rsi
  signed __int64 v4; // rbx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *emitter_list; // [rsp+20h] [rbp-18h]
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v6; // [rsp+28h] [rbp-10h]

  v2 = pView;
  v3 = this;
  if ( UFG::StimulusManager::s_EnableStimulusVisualization )
  {
    v4 = 0i64;
    emitter_list = &UFG::StimulusManager::s_UpdateList1;
    v6 = &UFG::StimulusManager::s_UpdateList2;
    do
      UFG::StimulusManager::RenderDebug(v3, v2, 0i64, *(&emitter_list + v4++));
    while ( v4 < 2 );
  }
}

// File Line: 260
// RVA: 0x381750
void __fastcall UFG::StimulusManager::RenderDebug(UFG::StimulusManager *this, Render::View *pView, UFG::SimObject *pFocusObject, UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *emitter_list)
{
  UFG::SimObject *v4; // r12
  Render::View *v5; // r14
  UFG::StimulusManager *v6; // r15
  char v7; // bl
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v8; // rsi
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v9; // r13
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm7_4
  float v14; // xmm15_4
  float v15; // xmm8_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm14_4
  float v21; // xmm11_4
  float v22; // xmm5_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm7_4
  float v32; // xmm6_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm3_4
  float v38; // xmm6_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  UFG::qColour v44; // xmm2
  signed __int64 v45; // rbx
  Render::DebugDrawContext *v46; // rdi
  char *v47; // rax
  UFG::ActiveAIEntityComponent *v48; // r9
  UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *v49; // rbx
  UFG::SimObjectCVBase *v50; // rcx
  unsigned __int16 v51; // dx
  UFG::ActiveAIEntityComponent *v52; // rax
  UFG::qVector3 world_position; // [rsp+30h] [rbp-98h]
  float v54; // [rsp+40h] [rbp-88h]
  float v55; // [rsp+44h] [rbp-84h]
  float v56; // [rsp+48h] [rbp-80h]
  unsigned __int64 v57; // [rsp+4Ch] [rbp-7Ch]
  char v58[12]; // [rsp+54h] [rbp-74h]
  UFG::qColour colour; // [rsp+60h] [rbp-68h]
  UFG::qMatrix44 xform; // [rsp+70h] [rbp-58h]
  __int16 v61; // [rsp+B0h] [rbp-18h]
  char v62; // [rsp+B2h] [rbp-16h]
  __int64 v63; // [rsp+B8h] [rbp-10h]
  UFG::DrawInfo info; // [rsp+C0h] [rbp-8h]
  __int64 v65; // [rsp+F8h] [rbp+30h]
  UFG::Stimulus v66; // [rsp+108h] [rbp+40h]
  bool v67; // [rsp+398h] [rbp+2D0h]
  float v68; // [rsp+3A0h] [rbp+2D8h]

  v65 = -2i64;
  v4 = pFocusObject;
  v5 = pView;
  v6 = this;
  v7 = pFocusObject != 0i64;
  v67 = pFocusObject != 0i64;
  v8 = emitter_list->mNode.mNext - 4;
  v9 = emitter_list - 4;
  if ( v8 != (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&emitter_list[-4] )
  {
    *(UFG::qVector3 *)v58 = world_position;
    v10 = world_position.z;
    v54 = world_position.z;
    v11 = world_position.y;
    v55 = world_position.y;
    v12 = world_position.x;
    v57 = *(_QWORD *)&world_position.x;
    v13 = world_position.z;
    v56 = world_position.z;
    v68 = world_position.x;
    do
    {
      UFG::Stimulus::Stimulus(&v66, (UFG::StimulusEmitterComponent *)v8, 0i64);
      if ( UFG::StimulusManager::s_StimulusTypeToRender
        && LODWORD(v8[5].mPrev) != UFG::StimulusManager::s_StimulusTypeToRender
        || v7 && v4 != v66.m_pStimulusProducer.m_pPointer )
      {
        goto LABEL_48;
      }
      v14 = (float)(signed int)v66.m_Description.m_Type;
      v15 = (float)((float)(signed int)v66.m_Description.m_Type * 0.0049999999) + 0.5;
      if ( !BYTE4(v8[27].mPrev) )
      {
        if ( v66.m_StimulusProducerInfoValid )
        {
          v16 = v66.m_StimulusProducerPosition.x;
          *(float *)v58 = v66.m_StimulusProducerPosition.x;
          v17 = v66.m_StimulusProducerPosition.y;
          v18 = v66.m_StimulusProducerPosition.z;
          *(float *)&v58[8] = v66.m_StimulusProducerPosition.z;
          v12 = v66.m_StimulusProducerVelocity.x;
          v57 = __PAIR__(LODWORD(v66.m_StimulusProducerPosition.y), LODWORD(v66.m_StimulusProducerVelocity.x));
          v11 = v66.m_StimulusProducerVelocity.y;
          v55 = v66.m_StimulusProducerVelocity.y;
          v10 = v66.m_StimulusProducerVelocity.z;
          v54 = v66.m_StimulusProducerVelocity.z;
          v68 = v66.m_StimulusProducerFacing.x;
          *(float *)&v58[4] = v66.m_StimulusProducerFacing.y;
          v13 = v66.m_StimulusProducerFacing.z;
          v56 = v66.m_StimulusProducerFacing.z;
        }
        else
        {
          v16 = *(float *)v58;
          v17 = *((float *)&v57 + 1);
          v18 = *(float *)&v58[8];
        }
        v19 = fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10));
        v20 = v66.m_Description.m_MinPerceptionRadiusMetres;
        if ( v66.m_Description.m_MinPerceptionRadiusMetres <= (float)(v66.m_Description.m_PerceptionRadiusSeconds * v19) )
          v20 = v66.m_Description.m_PerceptionRadiusSeconds * v19;
        v21 = v18 + v15;
        world_position.x = v16;
        world_position.y = v17;
        world_position.z = v18 + v15;
        if ( (float)((float)((float)(UFG::qVector3::msDirUp.x * UFG::qVector3::msDirUp.x)
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z)) == 0.0 )
          v22 = 0.0;
        else
          v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(UFG::qVector3::msDirUp.x)));
        v23 = v22 * UFG::qVector3::msDirUp.z;
        v24 = v22 * UFG::qVector3::msDirUp.y;
        v25 = v22 * UFG::qVector3::msDirUp.x;
        xform.v0.x = v25;
        xform.v0.y = v24;
        xform.v0.z = v23;
        xform.v0.w = 0.0;
        if ( (float)((float)((float)(*(float *)&v58[4] * *(float *)&v58[4]) + (float)(v68 * v68)) + (float)(v13 * v13)) == 0.0 )
          v26 = 0.0;
        else
          v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)*(unsigned int *)&v58[4]));
        v27 = v13 * v26;
        v28 = *(float *)&v58[4] * v26;
        v29 = v68 * v26;
        v30 = (float)(v24 * (float)(v68 * v26)) - (float)(v25 * (float)(*(float *)&v58[4] * v26));
        v31 = (float)(v25 * v27) - (float)(v23 * v29);
        v32 = (float)(v23 * v28) - (float)(v24 * v27);
        v33 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v30 * v30);
        if ( v33 == 0.0 )
          v34 = 0.0;
        else
          v34 = 1.0 / fsqrt(v33);
        v35 = v30 * v34;
        v36 = v32 * v34;
        v56 = v36;
        *(float *)&v57 = v31 * v34;
        *((float *)&v57 + 1) = v35;
        *(_DWORD *)v58 = 0;
        v37 = (float)((float)(v31 * v34) * v25) - (float)(v36 * v24);
        v38 = (float)(v36 * v23) - (float)(v35 * v25);
        v39 = (float)(v35 * v24) - (float)((float)(v31 * v34) * v23);
        v40 = (float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v37 * v37);
        if ( v40 == 0.0 )
          v41 = 0.0;
        else
          v41 = 1.0 / fsqrt(v40);
        *(float *)&v58[4] = v39 * v41;
        *(float *)&v58[8] = v41 * v38;
        colour.r = v41 * v37;
        colour.g = 0.0;
        colour.b = *(float *)v58;
        colour.a = *((float *)&v57 + 1);
        xform.v0.x = v21;
        xform.v0.y = 1.0;
        v42 = v66.m_Description.m_EmitterHorizontalAngleCosine;
        if ( v66.m_Description.m_EmitterHorizontalAngleCosine <= -1.0 )
        {
          v42 = FLOAT_N1_0;
        }
        else if ( v66.m_Description.m_EmitterHorizontalAngleCosine >= 1.0 )
        {
          v42 = *(float *)&FLOAT_1_0;
        }
        v43 = acosf(v42);
        colour.r = v14 * 0.0086206896;
        colour.g = 0.0;
        colour.b = 1.0 - (float)(v14 * 0.0086206896);
        colour.a = 1.0;
        v44 = colour;
        _mm_store_si128((__m128i *)&xform.v0.z, (__m128i)colour);
        xform.v1.y = desiredAlpha;
        *(_QWORD *)&xform.v1.z = *(_QWORD *)&v44.r;
        *(_QWORD *)&xform.v2.x = (unsigned __int128)_mm_srli_si128((__m128i)v44, 8);
        *(_QWORD *)&xform.v2.z = *(_QWORD *)&v44.r;
        *(_QWORD *)&xform.v3.x = *(_QWORD *)&xform.v2.x;
        xform.v3.z = v20 * 2.0;
        xform.v3.w = -1.4230097e-17;
        v61 = 256;
        v62 = 0;
        v63 = 0i64;
        *(_QWORD *)&info.mColour1.r = *(_QWORD *)&xform.v0.z;
        *(_QWORD *)&info.mColour1.b = *(_QWORD *)&xform.v1.x;
        *(_QWORD *)&info.mColour2.r = *(_QWORD *)&xform.v0.z;
        *(_QWORD *)&info.mColour2.b = *(_QWORD *)&xform.v1.x;
        info.mScale = v20 * 2.0;
        info.mAlphaBlend = 1775952593;
        *(_WORD *)&info.mDepthBuffer = 257;
        info.mDepthBias = 0;
        info.mPreDrawCallback = 0i64;
        Render::View::DrawArcSolid(v5, &xform, &info, 3.1415927 - v43, v43 + 3.1415927, 0x3Cu);
        Render::View::DrawArc(v5, &xform, (UFG::DrawInfo *)&xform.v1.z, 3.1415927 - v43, v43 + 3.1415927, 0x3Cu);
        colour.a = 1.0;
        v45 = (signed __int64)&v8[5].mNext->mNext + 2;
        v46 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
        v47 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v8[2].mNext[4].mNext);
        Render::DebugDrawContext::DrawText(v46, &world_position, &colour, "%s:%s", v47);
        v48 = (UFG::ActiveAIEntityComponent *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
        if ( &UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext != (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> **)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList - 1336) )
        {
          do
          {
            v49 = (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)&v48->mNext[-84].mNext;
            UFG::StimulusManager::RenderPerceivedLine(v6, v5, (UFG::StimulusEmitterComponent *)v8, v48);
            v48 = (UFG::ActiveAIEntityComponent *)v49;
          }
          while ( v49 != (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList - 1336) );
        }
        v7 = v67;
        v12 = *(float *)&v57;
        v11 = v55;
        v10 = v54;
        v13 = v56;
        goto LABEL_48;
      }
      if ( v8[29].mPrev )
      {
        v50 = (UFG::SimObjectCVBase *)*((_QWORD *)&v8[29].mPrev[5].mNext[2].mNext
                                      + 7 * *((unsigned __int8 *)&v8[29].mPrev[6].mPrev->mNext + LODWORD(v8[30].mNext)));
      }
      else
      {
        v50 = (UFG::SimObjectCVBase *)v8[32].mPrev;
        if ( !v50 )
          goto LABEL_45;
      }
      if ( v50 )
      {
        v51 = v50->m_Flags;
        if ( (v51 >> 14) & 1 )
        {
          v52 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v50);
        }
        else if ( (v51 & 0x8000u) == 0 )
        {
          if ( (v51 >> 13) & 1 )
          {
            v52 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v50->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else if ( (v51 >> 12) & 1 )
          {
            v52 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v50->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v52 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v50->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
        else
        {
          v52 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v50);
        }
        goto LABEL_46;
      }
LABEL_45:
      v52 = 0i64;
LABEL_46:
      UFG::StimulusManager::RenderPerceivedLine(v6, v5, (UFG::StimulusEmitterComponent *)v8, v52);
LABEL_48:
      UFG::Stimulus::~Stimulus(&v66);
      v8 = v8[4].mNext - 4;
    }
    while ( v8 != (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)v9 );
  }
}46:
      UFG::StimulusManager::RenderPerceivedLine(v6, v5, (UFG::StimulusEmitter

// File Line: 355
// RVA: 0x381FB0
void __fastcall UFG::StimulusManager::RenderPerceivedLine(UFG::StimulusManager *this, Render::View *pView, UFG::StimulusEmitterComponent *emitter, UFG::ActiveAIEntityComponent *target_ai_entity)
{
  UFG::ActiveAIEntityComponent *v4; // rbx
  UFG::StimulusEmitterComponent *v5; // rdi
  Render::View *v6; // rsi
  UFG::TransformNodeComponent *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm3_4
  unsigned int v10; // xmm3_4
  UFG::qVector3 position; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 p0; // [rsp+40h] [rbp-B8h]
  __int64 v13; // [rsp+50h] [rbp-A8h]
  __int64 v14; // [rsp+58h] [rbp-A0h]
  UFG::DrawInfo info; // [rsp+60h] [rbp-98h]
  UFG::Stimulus stimulus; // [rsp+98h] [rbp-60h]
  float v17; // [rsp+268h] [rbp+170h]

  if ( target_ai_entity )
  {
    info.mPreDrawCallback = (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))-2i64;
    v4 = target_ai_entity;
    v5 = emitter;
    v6 = pView;
    UFG::Stimulus::Stimulus((UFG::Stimulus *)((char *)&stimulus + 8), emitter, target_ai_entity->m_pSimObject);
    if ( UFG::StimulusReceiverComponent::CanPerceive(
           &stimulus,
           (UFG::TransformNodeComponent *)v4->m_pTransformNodeComponent.m_pSimComponent) )
    {
      if ( UFG::StimulusEmitterComponent::GetStimulusProducerPosition(v5, &position) )
      {
        p0 = position;
        v7 = (UFG::TransformNodeComponent *)v4->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v7);
        v8 = v7->mWorldTransform.v3.y;
        v9 = v7->mWorldTransform.v3.z;
        position.x = v7->mWorldTransform.v3.x;
        position.y = v8;
        p0.z = p0.z + v17;
        position.z = v9 + v17;
        *(float *)&v10 = (float)(signed int)stimulus.m_Description.m_Type * 0.0086206896;
        v13 = v10;
        *(float *)&v14 = 1.0 - *(float *)&v10;
        HIDWORD(v14) = 1065353216;
        *(_QWORD *)&info.mColour1.r = v10;
        *(_QWORD *)&info.mColour1.b = v14;
        info.mColour2.r = UFG::qColour::White.r;
        info.mColour2.g = UFG::qColour::White.g;
        info.mColour2.b = 1.0;
        LOWORD(info.mScale) = 257;
        BYTE2(info.mScale) = 0;
        *(_QWORD *)&info.mDepthBuffer = Render::gXRayDrawCallback;
        LODWORD(info.mColour2.a) = `UFG::XRayDrawInfo::XRayDrawInfo::`2::alpha;
        LODWORD(info.mColour1.a) = `UFG::XRayDrawInfo::XRayDrawInfo::`2::alpha;
        Render::View::DrawArrow(v6, &p0, &position, &info, &UFG::qMatrix44::msIdentity);
      }
    }
    UFG::Stimulus::~Stimulus(&stimulus);
  }
}

// File Line: 390
// RVA: 0x351450
UFG::SimObject *__fastcall UFG::StimulusManager::CreateSimObjectAtLocation(UFG::StimulusManager *this, UFG::qVector3 *location)
{
  UFG::qVector3 *v2; // rbp
  UFG::qSymbol *v3; // rax
  UFG::SimObject *v4; // rsi
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // eax
  UFG::TransformNodeComponent *v9; // rax
  UFG::TransformNodeComponent *v10; // rdi
  UFG::qVector4 v11; // xmm3
  float v12; // xmm1_4
  float v13; // xmm2_4
  unsigned __int16 v14; // cx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-80h]
  UFG::qMatrix44 m; // [rsp+60h] [rbp-58h]
  UFG::qSymbol result; // [rsp+C8h] [rbp+10h]
  UFG::allocator::free_link *v19; // [rsp+D0h] [rbp+18h]

  v2 = location;
  v3 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v19, "StaticStimulusEmitterComponent");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, v3);
  v4 = UFG::Simulation::CreateSimObject(&UFG::gSim, &result);
  v5 = UFG::GetSimulationMemoryPool();
  v6 = UFG::qMemoryPool::Allocate(v5, 0x110ui64, "StimulusManager", 0i64, 1u);
  v19 = v6;
  v7 = -1;
  if ( v6 )
  {
    v8 = UFG::qStringHash32("TransformNode", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v6, v8, 0i64, 0);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 0i64;
  v11.x = (float)1;
  m.v0 = v11;
  m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 81);
  m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 69);
  m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 21);
  v12 = v2->y;
  v13 = v2->z;
  m.v3.x = v2->x;
  m.v3.y = v12;
  m.v3.z = v13;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(v10, &m);
  v14 = v4->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 || (v14 >> 13) & 1 )
  {
    v7 = 2;
  }
  else if ( (v14 >> 12) & 1 )
  {
    v7 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, v4, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, (UFG::SimComponent *)&v10->vfptr, v7);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v4;
}

// File Line: 411
// RVA: 0x349DD0
void __fastcall UFG::StimulusManager::BeginStimulus(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::StimulusParameters *stimulus_parameters, UFG::qVector3 *location)
{
  __int64 v4; // rbx
  UFG::StimulusParameters *v5; // rsi
  UFG::StimulusManager *v6; // rdi
  UFG::SimObject *v7; // rax

  v4 = stimulus_type;
  v5 = stimulus_parameters;
  v6 = this;
  v7 = UFG::StimulusManager::CreateSimObjectAtLocation(this, location);
  UFG::StimulusManager::AttachStimulusEmitterComponent(v6, &UFG::g_StimulusDescriptions[v4], v5, v7, 1);
}

// File Line: 439
// RVA: 0x351C90
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::SimObject *sim_object)
{
  UFG::eStimulusType v3; // esi
  UFG::SimComponent *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi

  if ( sim_object )
  {
    v3 = stimulus_type;
    v4 = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( v4 )
    {
      do
      {
        v5 = UFG::SimObject::GetComponentOfType(
               v4->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               v4);
        if ( LODWORD(v4[1].m_SafePointerList.mNode.mNext) == v3 )
          UFG::Simulation::DestroySimComponent(&UFG::gSim, v4);
        v4 = (UFG::SimComponent *)&v5->vfptr;
      }
      while ( v5 );
    }
  }
}

// File Line: 456
// RVA: 0x351BF0
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::SimObject *sim_object, UFG::SimObject *stimulus_target_object)
{
  UFG::eStimulusType v4; // ebp
  UFG::SimObject *v5; // rsi
  UFG::SimComponent *v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi

  if ( sim_object )
  {
    v4 = stimulus_type;
    v5 = stimulus_target_object;
    v6 = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( v6 )
    {
      do
      {
        v7 = UFG::SimObject::GetComponentOfType(
               v6->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               v6);
        if ( LODWORD(v6[1].m_SafePointerList.mNode.mNext) == v4
          && BYTE4(v6[6].m_BoundComponentHandles.mNode.mPrev)
          && (UFG::SimObject *)v6[8].vfptr == v5 )
        {
          UFG::Simulation::DestroySimComponent(&UFG::gSim, v6);
        }
        v6 = (UFG::SimComponent *)&v7->vfptr;
      }
      while ( v7 );
    }
  }
}

// File Line: 475
// RVA: 0x351D10
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::SimObject *sim_object, UFG::eTargetTypeEnum target_type)
{
  UFG::eStimulusType v4; // ebp
  UFG::eTargetTypeEnum v5; // esi
  UFG::SimComponent *v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi

  if ( sim_object )
  {
    v4 = stimulus_type;
    v5 = target_type;
    v6 = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( v6 )
    {
      do
      {
        v7 = UFG::SimObject::GetComponentOfType(
               v6->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               v6);
        if ( LODWORD(v6[1].m_SafePointerList.mNode.mNext) == v4
          && BYTE4(v6[6].m_BoundComponentHandles.mNode.mPrev)
          && LODWORD(v6[7].m_pSimObject) == v5 )
        {
          UFG::Simulation::DestroySimComponent(&UFG::gSim, v6);
        }
        v6 = (UFG::SimComponent *)&v7->vfptr;
      }
      while ( v7 );
    }
  }
}

// File Line: 494
// RVA: 0x349EB0
void __fastcall UFG::StimulusManager::BeginStimulus(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::StimulusParameters *stimulus_parameters, UFG::SimObject *stimulus_emitter_object)
{
  __int64 v4; // rbx
  UFG::StimulusParameters *v5; // rbp
  UFG::SimObject *v6; // rsi
  UFG::StimulusManager *v7; // rdi

  v4 = stimulus_type;
  v5 = stimulus_parameters;
  v6 = stimulus_emitter_object;
  v7 = this;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(this, stimulus_type, stimulus_emitter_object);
  UFG::StimulusManager::AttachStimulusEmitterComponent(v7, &UFG::g_StimulusDescriptions[v4], v5, v6, 0);
}

// File Line: 510
// RVA: 0x349E30
void __fastcall UFG::StimulusManager::BeginStimulus(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::StimulusParameters *stimulus_parameters, UFG::SimObject *stimulus_emitter_object, UFG::SimObject *stimulus_target_object)
{
  UFG::SimObject *v5; // rsi
  __int64 v6; // rbx
  UFG::StimulusParameters *v7; // rbp
  UFG::StimulusManager *v8; // rdi
  UFG::StimulusEmitterComponent *v9; // rax

  v5 = stimulus_emitter_object;
  v6 = stimulus_type;
  v7 = stimulus_parameters;
  v8 = this;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
    this,
    stimulus_type,
    stimulus_emitter_object,
    stimulus_target_object);
  v9 = (UFG::StimulusEmitterComponent *)UFG::StimulusManager::AttachStimulusEmitterComponent(
                                          v8,
                                          &UFG::g_StimulusDescriptions[v6],
                                          v7,
                                          v5,
                                          0);
  if ( stimulus_target_object )
  {
    if ( v9 )
      UFG::StimulusEmitterComponent::SetIsTargeted(v9, stimulus_target_object);
  }
}

// File Line: 531
// RVA: 0x349F20
void __fastcall UFG::StimulusManager::BeginStimulus(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::StimulusParameters *stimulus_parameters, UFG::SimObject *stimulus_emitter_object, UFG::eTargetTypeEnum target_type)
{
  UFG::SimObjectGame *v5; // rbp
  __int64 v6; // rbx
  UFG::StimulusParameters *v7; // rsi
  UFG::StimulusManager *v8; // rdi
  UFG::SimComponent *v9; // rax
  UFG::StimulusEmitterComponent *v10; // rbx
  unsigned __int16 v11; // dx
  UFG::TargetingSystemBaseComponent *v12; // rax

  v5 = (UFG::SimObjectGame *)stimulus_emitter_object;
  v6 = stimulus_type;
  v7 = stimulus_parameters;
  v8 = this;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(this, stimulus_type, stimulus_emitter_object, target_type);
  v9 = UFG::StimulusManager::AttachStimulusEmitterComponent(
         v8,
         &UFG::g_StimulusDescriptions[v6],
         v7,
         (UFG::SimObject *)&v5->vfptr,
         0);
  v10 = (UFG::StimulusEmitterComponent *)v9;
  if ( target_type && v9 && v5 )
  {
    v11 = v5->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v5->vfptr,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
    }
    else
    {
      v12 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    }
    if ( v12 )
      UFG::StimulusEmitterComponent::SetIsTargeted(v10, v12, target_type);
  }
}

// File Line: 556
// RVA: 0x355860
void __fastcall UFG::StimulusManager::EndStimulus(UFG::StimulusManager *this, UFG::eStimulusType stimulus_type, UFG::SimObject *stimulus_emitter_object)
{
  UFG::SimObject *v3; // rsi
  int v4; // ebp
  UFG::SimComponent *v5; // rbx
  UFG::TransformNodeComponent *v6; // rdi

  if ( stimulus_emitter_object )
  {
    v3 = stimulus_emitter_object;
    v4 = *((_DWORD *)&unk_1423BF9B0 + 18 * stimulus_type);
    v5 = UFG::SimObject::GetComponentOfType(stimulus_emitter_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( v5 )
    {
      do
      {
        v6 = UFG::SimObject::GetComponentOfType(
               v5->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               v5);
        if ( *(_DWORD *)&v5[1].m_Flags == v4 )
        {
          if ( LOBYTE(v5[2].m_BoundComponentHandles.mNode.mPrev) )
          {
            UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
            return;
          }
          UFG::Simulation::DestroySimComponent(&UFG::gSim, v5);
        }
        v5 = (UFG::SimComponent *)&v6->vfptr;
      }
      while ( v6 );
    }
  }
}

// File Line: 596
// RVA: 0x14B9480
__int64 dynamic_initializer_for__uid_StimulusEmitterComponent__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("StimulusEmitterComponent", 0xFFFFFFFF);
  uid_StimulusEmitterComponent = result;
  return result;
}

// File Line: 602
// RVA: 0x342670
UFG::SimComponent *__fastcall UFG::StimulusManager::AttachStimulusEmitterComponent(UFG::StimulusManager *this, UFG::StimulusDescription *stimulus_description, UFG::StimulusParameters *stimulus_parameters, UFG::SimObject *stimulus_emitter_object, bool delete_simobject_upon_expiry)
{
  UFG::SimObject *v5; // rdi
  UFG::StimulusParameters *v6; // rbx
  UFG::StimulusDescription *v7; // rsi
  UFG::StimulusManager *v8; // rbp
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v13; // rdx
  UFG::SimComponent *v14; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v15; // rax
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]

  v5 = stimulus_emitter_object;
  v6 = stimulus_parameters;
  v7 = stimulus_description;
  v8 = this;
  if ( !stimulus_emitter_object )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x208ui64, "StimulusEmitterComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::StimulusEmitterComponent::StimulusEmitterComponent(
      (UFG::StimulusEmitterComponent *)v10,
      uid_StimulusEmitterComponent,
      v7,
      v6,
      delete_simobject_upon_expiry);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, v5, 0);
  UFG::SimObjectModifier::AttachComponent(&v17, v12, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
  v13 = v8->m_pOtherUpdateList;
  v14 = v12 + 1;
  v15 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v13->mNode.mPrev;
  v15[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v12[1];
  v14->vfptr = v15;
  v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v13;
  v13->mNode.mPrev = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v12[1];
  return v12;
}

