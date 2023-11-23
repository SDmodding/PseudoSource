// File Line: 28
// RVA: 0x14AECB0
__int64 dynamic_initializer_for__UFG::StimulusManager::s_UpdateList1__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StimulusManager::s_UpdateList1__);
}

// File Line: 29
// RVA: 0x14AECD0
__int64 dynamic_initializer_for__UFG::StimulusManager::s_UpdateList2__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StimulusManager::s_UpdateList2__);
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
  unsigned int v2; // edi
  const char **v3; // rbx

  v2 = 0;
  v3 = UFG::g_StimulusName;
  while ( (unsigned int)UFG::qStringCompareInsensitive(type_name, *v3, -1) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)&OneShotCondition::sClassName )
      return 0i64;
  }
  return v2;
}

// File Line: 109
// RVA: 0x362850
__int64 __fastcall UFG::StimulusManager::GetStimulusType(_DWORD *type_name)
{
  unsigned int v2; // edi
  const char **v3; // rbx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  v3 = UFG::g_StimulusName;
  while ( *type_name != UFG::qSymbol::create_from_string(&result, *v3)->mUID )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)&OneShotCondition::sClassName )
      return 0i64;
  }
  return v2;
}

// File Line: 131
// RVA: 0x393060
void __fastcall UFG::StimulusManager::Update(UFG::StimulusManager *this, float timestep)
{
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *m_pCurrentUpdateList; // r8
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *mNext; // rdx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *m_pOtherUpdateList; // rdx
  UFG::StimulusEmitterComponent *v6; // rdx
  __int64 v7; // rcx
  __int64 *v8; // rax
  __int64 mPrev; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v10; // rdx
  __int64 v11; // rdx
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // rax
  int v15; // edi
  bool v16; // r8
  float mSimTime_Temp; // xmm6_4
  __int64 **v18; // rcx
  __int64 *v19; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v20; // r8
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v21; // rdx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v22; // rdx
  __int64 v23; // rdx
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
  __int64 v34; // rax
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v35; // rdx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v36; // rcx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v37; // rax
  __int64 *v38; // rcx
  __int64 **v39; // rax
  __int64 *v40; // rcx
  __int64 **v41; // rax
  __int64 *v42; // rcx
  __int64 **v43; // rax
  __int64 *v44; // rcx
  __int64 **v45; // rax
  __int64 *v46; // rcx
  __int64 **v47; // rax
  __int64 *v48; // rcx
  __int64 **v49; // rax
  __int64 v50; // rcx
  __int64 *v51; // rax
  __int64 v52; // rcx
  __int64 *v53; // rax
  __int64 **v54; // [rsp+18h] [rbp-39h] BYREF
  __int64 *p_m_SafePointerList; // [rsp+20h] [rbp-31h] BYREF
  UFG::StimulusEmitterComponent *v56; // [rsp+28h] [rbp-29h]
  __int64 *v57; // [rsp+30h] [rbp-21h] BYREF
  __int64 **v58; // [rsp+38h] [rbp-19h]
  UFG::StimulusEmitterComponent *v59; // [rsp+40h] [rbp-11h]
  __int64 *v60; // [rsp+48h] [rbp-9h] BYREF
  __int64 **v61; // [rsp+50h] [rbp-1h]
  UFG::StimulusEmitterComponent *v62; // [rsp+58h] [rbp+7h]
  __int64 *v63; // [rsp+60h] [rbp+Fh] BYREF
  __int64 **v64; // [rsp+68h] [rbp+17h]
  UFG::StimulusEmitterComponent *v65; // [rsp+70h] [rbp+1Fh]
  __int64 v66; // [rsp+78h] [rbp+27h]

  v66 = -2i64;
  v54 = &p_m_SafePointerList;
  p_m_SafePointerList = (__int64 *)&p_m_SafePointerList;
  v56 = 0i64;
  v60 = (__int64 *)&v60;
  v61 = &v60;
  v62 = 0i64;
  m_pCurrentUpdateList = this->m_pCurrentUpdateList;
  if ( &this->m_pCurrentUpdateList->mNode.mNext[-4] == &this->m_pCurrentUpdateList[-4].mNode )
  {
    m_pOtherUpdateList = this->m_pOtherUpdateList;
    this->m_pCurrentUpdateList = m_pOtherUpdateList;
    this->m_pOtherUpdateList = m_pCurrentUpdateList;
    if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&m_pOtherUpdateList->mNode.mNext[-4] == &m_pOtherUpdateList[-4] )
      goto LABEL_9;
    mNext = m_pOtherUpdateList->mNode.mNext;
  }
  else
  {
    mNext = m_pCurrentUpdateList->mNode.mNext;
  }
  v6 = (UFG::StimulusEmitterComponent *)&mNext[-4];
  if ( v56 )
  {
    v7 = (__int64)v54;
    v8 = p_m_SafePointerList;
    v54[1] = p_m_SafePointerList;
    *v8 = v7;
    v54 = (__int64 **)&v54;
    p_m_SafePointerList = (__int64 *)&v54;
  }
  v56 = v6;
  if ( v6 )
  {
    mPrev = (__int64)v6->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    *(_QWORD *)(mPrev + 8) = &v54;
    v54 = (__int64 **)mPrev;
    p_m_SafePointerList = (__int64 *)&v6->m_SafePointerList;
    v6->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v54;
  }
LABEL_9:
  v10 = this->m_pOtherUpdateList;
  if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&v10->mNode.mNext[-4] != &v10[-4]
    || (v10 = this->m_pCurrentUpdateList,
        &this->m_pCurrentUpdateList->mNode.mNext[-4] != &this->m_pCurrentUpdateList[-4].mNode) )
  {
    v11 = (__int64)&v10->mNode.mPrev[-4];
    if ( v62 )
    {
      v12 = v60;
      v13 = v61;
      v60[1] = (__int64)v61;
      *v13 = v12;
      v60 = (__int64 *)&v60;
      v61 = &v60;
    }
    v62 = (UFG::StimulusEmitterComponent *)v11;
    if ( v11 )
    {
      v14 = *(__int64 **)(v11 + 8);
      v14[1] = (__int64)&v60;
      v60 = v14;
      v61 = (__int64 **)(v11 + 8);
      *(_QWORD *)(v11 + 8) = &v60;
    }
  }
  v15 = 0;
  v16 = 0;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v56 )
  {
    while ( 1 )
    {
      if ( v15 >= (int)(float)(timestep * 1000.0) || v16 )
        goto LABEL_41;
      v63 = (__int64 *)&v63;
      v64 = &v63;
      v65 = v56;
      v18 = (__int64 **)&v56->m_SafePointerList;
      v19 = (__int64 *)v56->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v19[1] = (__int64)&v63;
      v63 = v19;
      v64 = v18;
      *v18 = (__int64 *)&v63;
      v57 = (__int64 *)&v57;
      v58 = &v57;
      v59 = 0i64;
      v20 = this->m_pCurrentUpdateList;
      if ( &v65->mNext[-4] != &this->m_pCurrentUpdateList[-4].mNode )
        break;
      v22 = this->m_pOtherUpdateList;
      this->m_pCurrentUpdateList = v22;
      this->m_pOtherUpdateList = v20;
      if ( (UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *)&v22->mNode.mNext[-4] != &v22[-4] )
      {
        v21 = v22->mNode.mNext;
        goto LABEL_24;
      }
LABEL_28:
      v27 = &v65->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
      v28 = v65->mPrev;
      v29 = v65->mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = v27;
      v27->mNext = v27;
      v30 = v65;
      if ( mSimTime_Temp >= v65->m_NextUpdateTime )
      {
        UFG::StimulusEmitterComponent::Update(v65, timestep);
        ++v15;
        v30 = v65;
      }
      v16 = v62 == v30;
      v31 = v59;
      if ( v56 )
      {
        v32 = (__int64)v54;
        v33 = p_m_SafePointerList;
        v54[1] = p_m_SafePointerList;
        *v33 = v32;
        v54 = (__int64 **)&v54;
        p_m_SafePointerList = (__int64 *)&v54;
        v30 = v65;
      }
      v56 = v31;
      if ( v31 )
      {
        v34 = (__int64)v31->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        *(_QWORD *)(v34 + 8) = &v54;
        v54 = (__int64 **)v34;
        p_m_SafePointerList = (__int64 *)&v31->m_SafePointerList;
        v31->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v54;
        v30 = v65;
      }
      if ( v30 )
      {
        v35 = this->m_pOtherUpdateList;
        v36 = &v30->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
        v37 = v35->mNode.mPrev;
        v37->mNext = v36;
        v36->mPrev = v37;
        v36->mNext = &v35->mNode;
        v35->mNode.mPrev = v36;
      }
      if ( v59 )
      {
        v38 = v57;
        v39 = v58;
        v57[1] = (__int64)v58;
        *v39 = v38;
        v57 = (__int64 *)&v57;
        v58 = &v57;
      }
      v59 = 0i64;
      v40 = v57;
      v41 = v58;
      v57[1] = (__int64)v58;
      *v41 = v40;
      v57 = (__int64 *)&v57;
      v58 = &v57;
      if ( v65 )
      {
        v42 = v63;
        v43 = v64;
        v63[1] = (__int64)v64;
        *v43 = v42;
        v63 = (__int64 *)&v63;
        v64 = &v63;
      }
      v65 = 0i64;
      v44 = v63;
      v45 = v64;
      v63[1] = (__int64)v64;
      *v45 = v44;
      v63 = (__int64 *)&v63;
      v64 = &v63;
      if ( !v56 )
        goto LABEL_41;
    }
    v21 = v65->mNext;
LABEL_24:
    v23 = (__int64)&v21[-4];
    if ( v59 )
    {
      v24 = v57;
      v25 = v58;
      v57[1] = (__int64)v58;
      *v25 = v24;
      v57 = (__int64 *)&v57;
      v58 = &v57;
    }
    v59 = (UFG::StimulusEmitterComponent *)v23;
    if ( v23 )
    {
      v26 = *(__int64 **)(v23 + 8);
      v26[1] = (__int64)&v57;
      v57 = v26;
      v58 = (__int64 **)(v23 + 8);
      *(_QWORD *)(v23 + 8) = &v57;
    }
    goto LABEL_28;
  }
LABEL_41:
  if ( v62 )
  {
    v46 = v60;
    v47 = v61;
    v60[1] = (__int64)v61;
    *v47 = v46;
    v60 = (__int64 *)&v60;
    v61 = &v60;
  }
  v62 = 0i64;
  v48 = v60;
  v49 = v61;
  v60[1] = (__int64)v61;
  *v49 = v48;
  v60 = (__int64 *)&v60;
  v61 = &v60;
  if ( v56 )
  {
    v50 = (__int64)v54;
    v51 = p_m_SafePointerList;
    v54[1] = p_m_SafePointerList;
    *v51 = v50;
    v54 = (__int64 **)&v54;
    p_m_SafePointerList = (__int64 *)&v54;
  }
  v52 = (__int64)v54;
  v53 = p_m_SafePointerList;
  v54[1] = p_m_SafePointerList;
  *v53 = v52;
}

// File Line: 239
// RVA: 0x381F40
void __fastcall UFG::StimulusManager::RenderDebug(UFG::StimulusManager *this, Render::View *pView)
{
  __int64 v4; // rbx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *emitter_list[3]; // [rsp+20h] [rbp-18h]

  if ( UFG::StimulusManager::s_EnableStimulusVisualization )
  {
    v4 = 0i64;
    emitter_list[0] = &UFG::StimulusManager::s_UpdateList1;
    emitter_list[1] = &UFG::StimulusManager::s_UpdateList2;
    do
      UFG::StimulusManager::RenderDebug(this, pView, 0i64, emitter_list[v4++]);
    while ( v4 < 2 );
  }
}

// File Line: 260
// RVA: 0x381750
void __fastcall UFG::StimulusManager::RenderDebug(
        UFG::StimulusManager *this,
        Render::View *pView,
        UFG::SimObject *pFocusObject,
        UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *emitter_list)
{
  char v7; // bl
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v8; // rsi
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *v9; // r13
  float z; // xmm9_4
  float y; // xmm10_4
  float x; // xmm11_4
  float v13; // xmm7_4
  float m_Type; // xmm15_4
  float v15; // xmm8_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float m_MinPerceptionRadiusMetres; // xmm14_4
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
  float v35; // xmm3_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm2_4
  float m_EmitterHorizontalAngleCosine; // xmm0_4
  float v41; // xmm0_4
  unsigned int v42; // xmm15_4
  const char *v43; // rbx
  Render::DebugDrawContext *Context; // rdi
  char *v45; // rax
  UFG::ActiveAIEntityComponent *p_mNext; // r9
  UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *v47; // rbx
  UFG::SimObjectCVBase *mPrev; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 world_position; // [rsp+30h] [rbp-98h] BYREF
  float v52; // [rsp+40h] [rbp-88h]
  float v53; // [rsp+44h] [rbp-84h]
  float v54; // [rsp+48h] [rbp-80h]
  unsigned __int64 v55; // [rsp+4Ch] [rbp-7Ch]
  UFG::qVector3 v56; // [rsp+54h] [rbp-74h]
  UFG::qColour colour; // [rsp+60h] [rbp-68h] BYREF
  UFG::qMatrix44 xform; // [rsp+70h] [rbp-58h] BYREF
  __int16 v59; // [rsp+B0h] [rbp-18h]
  char v60; // [rsp+B2h] [rbp-16h]
  __int64 v61; // [rsp+B8h] [rbp-10h]
  UFG::DrawInfo info; // [rsp+C0h] [rbp-8h] BYREF
  __int64 v63; // [rsp+F8h] [rbp+30h]
  UFG::Stimulus v64; // [rsp+108h] [rbp+40h] BYREF
  bool v65; // [rsp+398h] [rbp+2D0h]
  float v66; // [rsp+3A0h] [rbp+2D8h]

  v63 = -2i64;
  v7 = pFocusObject != 0i64;
  v65 = pFocusObject != 0i64;
  v8 = emitter_list->mNode.mNext - 4;
  v9 = emitter_list - 4;
  if ( v8 != (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&emitter_list[-4] )
  {
    v56 = world_position;
    z = world_position.z;
    v52 = world_position.z;
    y = world_position.y;
    v53 = world_position.y;
    x = world_position.x;
    v55 = *(_QWORD *)&world_position.x;
    v13 = world_position.z;
    v54 = world_position.z;
    v66 = world_position.x;
    do
    {
      UFG::Stimulus::Stimulus(&v64, (UFG::StimulusEmitterComponent *)v8, 0i64);
      if ( UFG::StimulusManager::s_StimulusTypeToRender
        && LODWORD(v8[5].mPrev) != UFG::StimulusManager::s_StimulusTypeToRender
        || v7 && pFocusObject != v64.m_pStimulusProducer.m_pPointer )
      {
        goto LABEL_46;
      }
      m_Type = (float)v64.m_Description.m_Type;
      v15 = (float)((float)v64.m_Description.m_Type * 0.0049999999) + 0.5;
      if ( !BYTE4(v8[27].mPrev) )
      {
        if ( v64.m_StimulusProducerInfoValid )
        {
          v16 = v64.m_StimulusProducerPosition.x;
          v56.x = v64.m_StimulusProducerPosition.x;
          v17 = v64.m_StimulusProducerPosition.y;
          v18 = v64.m_StimulusProducerPosition.z;
          v56.z = v64.m_StimulusProducerPosition.z;
          x = v64.m_StimulusProducerVelocity.x;
          v55 = __PAIR64__(LODWORD(v64.m_StimulusProducerPosition.y), LODWORD(v64.m_StimulusProducerVelocity.x));
          y = v64.m_StimulusProducerVelocity.y;
          v53 = v64.m_StimulusProducerVelocity.y;
          z = v64.m_StimulusProducerVelocity.z;
          v52 = v64.m_StimulusProducerVelocity.z;
          v66 = v64.m_StimulusProducerFacing.x;
          v56.y = v64.m_StimulusProducerFacing.y;
          v13 = v64.m_StimulusProducerFacing.z;
          v54 = v64.m_StimulusProducerFacing.z;
        }
        else
        {
          v16 = v56.x;
          v17 = *((float *)&v55 + 1);
          v18 = v56.z;
        }
        v19 = fsqrt((float)((float)(y * y) + (float)(x * x)) + (float)(z * z));
        m_MinPerceptionRadiusMetres = v64.m_Description.m_MinPerceptionRadiusMetres;
        if ( v64.m_Description.m_MinPerceptionRadiusMetres <= (float)(v64.m_Description.m_PerceptionRadiusSeconds * v19) )
          m_MinPerceptionRadiusMetres = v64.m_Description.m_PerceptionRadiusSeconds * v19;
        v21 = v18 + v15;
        world_position.x = v16;
        world_position.y = v17;
        world_position.z = v18 + v15;
        if ( (float)((float)((float)(UFG::qVector3::msDirUp.x * UFG::qVector3::msDirUp.x)
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z)) == 0.0 )
          v22 = 0.0;
        else
          v22 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(UFG::qVector3::msDirUp.x)).m128_f32[0];
        v23 = v22 * UFG::qVector3::msDirUp.z;
        v24 = v22 * UFG::qVector3::msDirUp.y;
        v25 = v22 * UFG::qVector3::msDirUp.x;
        xform.v0.x = v25;
        xform.v0.y = v24;
        xform.v0.z = v23;
        xform.v0.w = 0.0;
        if ( (float)((float)((float)(v56.y * v56.y) + (float)(v66 * v66)) + (float)(v13 * v13)) == 0.0 )
          v26 = 0.0;
        else
          v26 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(v56.y)).m128_f32[0];
        v27 = v13 * v26;
        v28 = v56.y * v26;
        v29 = v66 * v26;
        v30 = (float)(v24 * (float)(v66 * v26)) - (float)(v25 * (float)(v56.y * v26));
        v31 = (float)(v25 * v27) - (float)(v23 * v29);
        v32 = (float)(v23 * v28) - (float)(v24 * v27);
        v33 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v30 * v30);
        if ( v33 == 0.0 )
          v34 = 0.0;
        else
          v34 = 1.0 / fsqrt(v33);
        v54 = v32 * v34;
        *(float *)&v55 = v31 * v34;
        *((float *)&v55 + 1) = v30 * v34;
        v56.x = 0.0;
        v35 = (float)((float)(v31 * v34) * v25) - (float)((float)(v32 * v34) * v24);
        v36 = (float)((float)(v32 * v34) * v23) - (float)((float)(v30 * v34) * v25);
        v37 = (float)((float)(v30 * v34) * v24) - (float)((float)(v31 * v34) * v23);
        v38 = (float)((float)(v36 * v36) + (float)(v37 * v37)) + (float)(v35 * v35);
        if ( v38 == 0.0 )
          v39 = 0.0;
        else
          v39 = 1.0 / fsqrt(v38);
        v56.y = v37 * v39;
        v56.z = v39 * v36;
        colour.r = v39 * v35;
        colour.g = 0.0;
        colour.b = v56.x;
        colour.a = *((float *)&v55 + 1);
        xform.v0.x = v21;
        xform.v0.y = 1.0;
        m_EmitterHorizontalAngleCosine = v64.m_Description.m_EmitterHorizontalAngleCosine;
        if ( v64.m_Description.m_EmitterHorizontalAngleCosine <= -1.0 )
        {
          m_EmitterHorizontalAngleCosine = FLOAT_N1_0;
        }
        else if ( v64.m_Description.m_EmitterHorizontalAngleCosine >= 1.0 )
        {
          m_EmitterHorizontalAngleCosine = *(float *)&FLOAT_1_0;
        }
        v41 = acosf(m_EmitterHorizontalAngleCosine);
        *(float *)&v42 = m_Type * 0.0086206896;
        *(_QWORD *)&colour.r = v42;
        colour.b = 1.0 - *(float *)&v42;
        colour.a = 1.0;
        *(UFG::qColour *)&xform.v0.z = colour;
        xform.v1.y = desiredAlpha;
        *(_QWORD *)&xform.v1.z = v42;
        *(_QWORD *)&xform.v2.x = _mm_srli_si128((__m128i)colour, 8).m128i_u64[0];
        *(_QWORD *)&xform.v2.z = v42;
        *(_QWORD *)&xform.v3.x = *(_QWORD *)&xform.v2.x;
        xform.v3.z = m_MinPerceptionRadiusMetres * 2.0;
        xform.v3.w = -1.4230097e-17;
        v59 = 256;
        v60 = 0;
        v61 = 0i64;
        *(_QWORD *)&info.mColour1.r = v42;
        *(_QWORD *)&info.mColour1.b = *(_QWORD *)&xform.v1.x;
        *(_QWORD *)&info.mColour2.r = v42;
        *(_QWORD *)&info.mColour2.b = *(_QWORD *)&xform.v1.x;
        info.mScale = m_MinPerceptionRadiusMetres * 2.0;
        info.mAlphaBlend = AlphaState_additive;
        *(_WORD *)&info.mDepthBuffer = 257;
        info.mDepthBias = 0;
        info.mPreDrawCallback = 0i64;
        Render::View::DrawArcSolid(pView, &xform, &info, 3.1415927 - v41, v41 + 3.1415927, 0x3Cu);
        Render::View::DrawArc(pView, &xform, (UFG::DrawInfo *)&xform.v1.z, 3.1415927 - v41, v41 + 3.1415927, 0x3Cu);
        colour.a = 1.0;
        v43 = (char *)&v8[5].mNext->mNext + 2;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                3u);
        v45 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v8[2].mNext[4].mNext);
        Render::DebugDrawContext::DrawText(Context, &world_position, &colour, "%s:%s", v45, v43);
        p_mNext = (UFG::ActiveAIEntityComponent *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
        if ( &UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext != (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> **)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList - 1336) )
        {
          do
          {
            v47 = (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)&p_mNext->mNext[-84].mNext;
            UFG::StimulusManager::RenderPerceivedLine(this, pView, (UFG::StimulusEmitterComponent *)v8, p_mNext);
            p_mNext = (UFG::ActiveAIEntityComponent *)v47;
          }
          while ( v47 != (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList - 1336) );
        }
        v7 = v65;
        x = *(float *)&v55;
        y = v53;
        z = v52;
        v13 = v54;
        goto LABEL_46;
      }
      if ( v8[29].mPrev )
      {
        mPrev = (UFG::SimObjectCVBase *)*((_QWORD *)&v8[29].mPrev[5].mNext[2].mNext
                                        + 7
                                        * *((unsigned __int8 *)&v8[29].mPrev[6].mPrev->mNext + LODWORD(v8[30].mNext)));
      }
      else
      {
        mPrev = (UFG::SimObjectCVBase *)v8[32].mPrev;
        if ( !mPrev )
          goto LABEL_43;
      }
      if ( mPrev )
      {
        m_Flags = mPrev->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(mPrev);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                mPrev,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                mPrev,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        goto LABEL_44;
      }
LABEL_43:
      ComponentOfTypeHK = 0i64;
LABEL_44:
      UFG::StimulusManager::RenderPerceivedLine(this, pView, (UFG::StimulusEmitterComponent *)v8, ComponentOfTypeHK);
LABEL_46:
      UFG::Stimulus::~Stimulus(&v64);
      v8 = v8[4].mNext - 4;
    }
    while ( v8 != (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)v9 );
  }
}e<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)v9 );
  }
}

// File Line: 355
// RVA: 0x381FB0
void __fastcall UFG::StimulusManager::RenderPerceivedLine(
        UFG::StimulusManager *this,
        Render::View *pView,
        UFG::StimulusEmitterComponent *emitter,
        UFG::ActiveAIEntityComponent *target_ai_entity)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v8; // xmm1_4
  float v9; // xmm3_4
  unsigned int v10; // xmm3_4
  UFG::qVector3 position; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qVector3 p0; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v13; // [rsp+50h] [rbp-A8h]
  float v14; // [rsp+58h] [rbp-A0h]
  int v15; // [rsp+5Ch] [rbp-9Ch]
  UFG::DrawInfo info; // [rsp+60h] [rbp-98h] BYREF
  UFG::Stimulus stimulus; // [rsp+98h] [rbp-60h] BYREF
  float v18; // [rsp+268h] [rbp+170h]

  if ( target_ai_entity )
  {
    info.mPreDrawCallback = (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))-2i64;
    UFG::Stimulus::Stimulus(
      (UFG::Stimulus *)&stimulus.UFG::qNode<UFG::Event,UFG::Event>,
      emitter,
      target_ai_entity->m_pSimObject);
    if ( UFG::StimulusReceiverComponent::CanPerceive(
           &stimulus,
           (UFG::TransformNodeComponent *)target_ai_entity->m_pTransformNodeComponent.m_pSimComponent) )
    {
      if ( UFG::StimulusEmitterComponent::GetStimulusProducerPosition(emitter, &position) )
      {
        p0 = position;
        m_pSimComponent = target_ai_entity->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
        v8 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
        v9 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
        position.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
        position.y = v8;
        p0.z = p0.z + v18;
        position.z = v9 + v18;
        *(float *)&v10 = (float)stimulus.m_Description.m_Type * 0.0086206896;
        v13 = v10;
        v14 = 1.0 - *(float *)&v10;
        v15 = 1065353216;
        *(_QWORD *)&info.mColour1.r = v10;
        info.mColour1.b = 1.0 - *(float *)&v10;
        info.mColour2.r = UFG::qColour::White.r;
        info.mColour2.g = UFG::qColour::White.g;
        info.mColour2.b = 1.0;
        LOWORD(info.mScale) = 257;
        BYTE2(info.mScale) = 0;
        *(_QWORD *)&info.mDepthBuffer = Render::gXRayDrawCallback;
        LODWORD(info.mColour2.a) = `UFG::XRayDrawInfo::XRayDrawInfo::`2::alpha;
        LODWORD(info.mColour1.a) = `UFG::XRayDrawInfo::XRayDrawInfo::`2::alpha;
        Render::View::DrawArrow(pView, &p0, &position, &info, &UFG::qMatrix44::msIdentity);
      }
    }
    UFG::Stimulus::~Stimulus(&stimulus);
  }
}

// File Line: 390
// RVA: 0x351450
UFG::SimObject *__fastcall UFG::StimulusManager::CreateSimObjectAtLocation(
        UFG::StimulusManager *this,
        UFG::qVector3 *location)
{
  UFG::qSymbol *v3; // rax
  UFG::SimObject *v4; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // eax
  UFG::TransformNodeComponent *v9; // rax
  UFG::TransformNodeComponent *v10; // rdi
  UFG::qVector4 v11; // xmm3
  float y; // xmm1_4
  float z; // xmm2_4
  __int16 m_Flags; // cx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-80h] BYREF
  UFG::qMatrix44 m; // [rsp+60h] [rbp-58h] BYREF
  UFG::qSymbol result; // [rsp+C8h] [rbp+10h] BYREF
  UFG::allocator::free_link *v19; // [rsp+D0h] [rbp+18h] BYREF

  v3 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v19, "StaticStimulusEmitterComponent");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, v3);
  v4 = UFG::Simulation::CreateSimObject(&UFG::gSim, &result);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "StimulusManager", 0i64, 1u);
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
  y = location->y;
  z = location->z;
  m.v3.x = location->x;
  m.v3.y = y;
  m.v3.z = z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(v10, &m);
  m_Flags = v4->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v7 = 2;
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    v7 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, v4, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v10, v7);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v4;
}

// File Line: 411
// RVA: 0x349DD0
void __fastcall UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::StimulusParameters *stimulus_parameters,
        UFG::qVector3 *location)
{
  __int64 v4; // rbx
  UFG::SimObject *SimObjectAtLocation; // rax

  v4 = stimulus_type;
  SimObjectAtLocation = UFG::StimulusManager::CreateSimObjectAtLocation(this, location);
  UFG::StimulusManager::AttachStimulusEmitterComponent(
    this,
    &UFG::g_StimulusDescriptions[v4],
    stimulus_parameters,
    SimObjectAtLocation,
    1);
}

// File Line: 439
// RVA: 0x351C90
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::SimObject *sim_object)
{
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v5; // rdi

  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( ComponentOfType )
    {
      do
      {
        v5 = UFG::SimObject::GetComponentOfType(
               ComponentOfType->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               ComponentOfType);
        if ( LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) == stimulus_type )
          UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
        ComponentOfType = v5;
      }
      while ( v5 );
    }
  }
}

// File Line: 456
// RVA: 0x351BF0
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::SimObject *sim_object,
        UFG::SimObject *stimulus_target_object)
{
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v7; // rdi

  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( ComponentOfType )
    {
      do
      {
        v7 = UFG::SimObject::GetComponentOfType(
               ComponentOfType->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               ComponentOfType);
        if ( LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) == stimulus_type
          && BYTE4(ComponentOfType[6].m_BoundComponentHandles.mNode.mPrev)
          && (UFG::SimObject *)ComponentOfType[8].vfptr == stimulus_target_object )
        {
          UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
        }
        ComponentOfType = v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 475
// RVA: 0x351D10
void __fastcall UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::SimObject *sim_object,
        UFG::eTargetTypeEnum target_type)
{
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v7; // rdi

  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::StimulusEmitterComponent::_TypeUID);
    if ( ComponentOfType )
    {
      do
      {
        v7 = UFG::SimObject::GetComponentOfType(
               ComponentOfType->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               ComponentOfType);
        if ( LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) == stimulus_type
          && BYTE4(ComponentOfType[6].m_BoundComponentHandles.mNode.mPrev)
          && LODWORD(ComponentOfType[7].m_pSimObject) == target_type )
        {
          UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
        }
        ComponentOfType = v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 494
// RVA: 0x349EB0
void __fastcall UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::StimulusParameters *stimulus_parameters,
        UFG::SimObject *stimulus_emitter_object)
{
  __int64 v4; // rbx

  v4 = stimulus_type;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(this, stimulus_type, stimulus_emitter_object);
  UFG::StimulusManager::AttachStimulusEmitterComponent(
    this,
    &UFG::g_StimulusDescriptions[v4],
    stimulus_parameters,
    stimulus_emitter_object,
    0);
}

// File Line: 510
// RVA: 0x349E30
void __fastcall UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::StimulusParameters *stimulus_parameters,
        UFG::SimObject *stimulus_emitter_object,
        UFG::SimObject *stimulus_target_object)
{
  __int64 v6; // rbx
  UFG::StimulusEmitterComponent *v9; // rax

  v6 = stimulus_type;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
    this,
    stimulus_type,
    stimulus_emitter_object,
    stimulus_target_object);
  v9 = UFG::StimulusManager::AttachStimulusEmitterComponent(
         this,
         &UFG::g_StimulusDescriptions[v6],
         stimulus_parameters,
         stimulus_emitter_object,
         0);
  if ( stimulus_target_object )
  {
    if ( v9 )
      UFG::StimulusEmitterComponent::SetIsTargeted(v9, stimulus_target_object);
  }
}

// File Line: 531
// RVA: 0x349F20
void __fastcall UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::StimulusParameters *stimulus_parameters,
        UFG::SimObjectGame *stimulus_emitter_object,
        UFG::eTargetTypeEnum target_type)
{
  __int64 v6; // rbx
  UFG::StimulusEmitterComponent *v9; // rax
  UFG::StimulusEmitterComponent *v10; // rbx
  signed __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax

  v6 = stimulus_type;
  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(this, stimulus_type, stimulus_emitter_object, target_type);
  v9 = UFG::StimulusManager::AttachStimulusEmitterComponent(
         this,
         &UFG::g_StimulusDescriptions[v6],
         stimulus_parameters,
         stimulus_emitter_object,
         0);
  v10 = v9;
  if ( target_type && v9 && stimulus_emitter_object )
  {
    m_Flags = stimulus_emitter_object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)stimulus_emitter_object->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              stimulus_emitter_object,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              stimulus_emitter_object,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)stimulus_emitter_object->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StimulusEmitterComponent::SetIsTargeted(v10, m_pComponent, target_type);
  }
}

// File Line: 556
// RVA: 0x355860
void __fastcall UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager *this,
        UFG::eStimulusType stimulus_type,
        UFG::SimObject *stimulus_emitter_object)
{
  int v4; // ebp
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v6; // rdi

  if ( stimulus_emitter_object )
  {
    v4 = *((_DWORD *)&unk_1423BF9B0 + 18 * stimulus_type);
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        stimulus_emitter_object,
                        UFG::StimulusEmitterComponent::_TypeUID);
    if ( ComponentOfType )
    {
      do
      {
        v6 = UFG::SimObject::GetComponentOfType(
               ComponentOfType->m_pSimObject,
               UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
               0,
               ComponentOfType);
        if ( *(_DWORD *)&ComponentOfType[1].m_Flags == v4 )
        {
          if ( LOBYTE(ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev) )
          {
            UFG::Simulation::DestroySimObject(&UFG::gSim, stimulus_emitter_object);
            return;
          }
          UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
        }
        ComponentOfType = v6;
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
UFG::StimulusEmitterComponent *__fastcall UFG::StimulusManager::AttachStimulusEmitterComponent(
        UFG::StimulusManager *this,
        UFG::StimulusDescription *stimulus_description,
        UFG::StimulusParameters *stimulus_parameters,
        UFG::SimObject *stimulus_emitter_object,
        bool delete_simobject_upon_expiry)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  UFG::qList<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList,0,0> *m_pOtherUpdateList; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *mPrev; // rax
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  if ( !stimulus_emitter_object )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x208ui64, "StimulusEmitterComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::StimulusEmitterComponent::StimulusEmitterComponent(
      (UFG::StimulusEmitterComponent *)v10,
      uid_StimulusEmitterComponent,
      stimulus_description,
      stimulus_parameters,
      delete_simobject_upon_expiry);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, stimulus_emitter_object, 0);
  UFG::SimObjectModifier::AttachComponent(&v16, v12, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  m_pOtherUpdateList = this->m_pOtherUpdateList;
  mPrev = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)m_pOtherUpdateList->mNode.mPrev;
  mPrev[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v12[1];
  v12[1].vfptr = mPrev;
  v12[1].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)m_pOtherUpdateList;
  m_pOtherUpdateList->mNode.mPrev = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v12[1];
  return (UFG::StimulusEmitterComponent *)v12;
}

